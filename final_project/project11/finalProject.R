library(pomp)
library(magrittr)
library(plyr)
library(dplyr)
library(ggplot2)
library(reshape2)
library(tidyverse)

run_level=2

## Setting up Parallelization Parameters
library(doParallel)
cores <- as.numeric(Sys.getenv('SLURM_NTASKS_PER_NODE',unset=NA))  
if(is.na(cores)) cores <- detectCores()  
registerDoParallel(cores)
# results_dir <- paste0("laptop_",run_level,"/")
results_dir <- paste0("greatlakes_",run_level,"/")
if(!dir.exists(results_dir)) dir.create(results_dir)
bake(file=paste0(results_dir,"cores.rds"),cores) -> cores

## Data Loading + Preprocessing -----------------------------------------------

# load the data
cpox_original = read.csv("hungary_chickenpox.csv")

# rowsum and create date object
cpox = cpox_original %>% mutate(cases = rowSums(.[-1]),date = as.Date(Date,format="%d/%m/%Y"))

# remove outliers
cpox = cpox %>% mutate(row_idx = 1:522)
cpox = cpox %>% filter(!row_idx %in% c(122,159,469,486,487,493)) %>% select(-row_idx)

# separate month/day/year
cpox = cpox %>% select(date,Date,cases) %>% separate(Date,c("day","month","year"),sep = "/")

cpox %>% mutate( time=  julian(date, origin = as.Date("2005-01-03"))/365.25 + 2005) %>%
  filter(time>=2005 & time<2015) %>%
  select(time,cases) -> cpox

# Plot the data
plot(cpox$time,cpox$case,type='l',xlab = "time",ylab="case", 
                       main="Hungarian chickenpox outbreak")


## Covariates -----------------------------------------------------------------
# data source (population): https://www.macrotrends.net/countries/HUN/hungary/population
# data source (birthrate): https://www.macrotrends.net/countries/HUN/hungary/birth-rate

pop = c(10085937,10055653,10024149,9991867,9959439,9927370,9895680,9864358,
                                                        9833923,9804991,9777923)

birthrate = c(9.437,9.470,9.502,9.534,9.443,9.353,9.262,9.172,9.081,9.163,9.245)
year = seq(2005,2015)

# convert birthrate to the number of newborns
hungary_demographic = data.frame(year,pop = pop, birthrate = birthrate,
                            num_newborn = ceiling(pop/1000 * birthrate))

# add smoothing line (Similar to the past project)
hungary_covar = hungary_demographic %>% summarise(time = seq(2005,2015,by=1/52),
            pop = predict(smooth.spline(x=year,y=pop),x=time)$y,
            birthrate = predict(smooth.spline(x=year,y=num_newborn),x=time)$y
            )

# population plot
plot(x=hungary_demographic$year,y=hungary_demographic$pop/1000000,type="b",
    col="red",xlab="year",ylab="population (million)",
    main = "Hungarian population from 2005 to 2014")

# birthrate plot
plot(x=hungary_demographic$year,y=hungary_demographic$num_newborn/1000,type="b",
    col="red",xlab="year",ylab="newborns (thousand)",
    main = "Hungarian number of newborns from 2005 to 2014")


## Process Model --------------------------------------------------------------
# c-snippets - modeled after project

rproc <- Csnippet("
                  double beta, br, seas, foi, dw, births, vac;
                  double rate[6], trans[6];

                  // cohort effect
                  if (fabs(t-floor(t)-251.0/365.0) < 0.5*dt) 
                    br = cohort*birthrate/dt + (1-cohort)*birthrate;
                  else 
                    br = (1.0-cohort)*birthrate;

                  // term-time seasonality
                  t = (t-floor(t))*365.25;
                  if ((t>=7&&t<=100) || 
                    (t>=115&&t<=199) || 
                    (t>=252&&t<=300) || 
                    (t>=308&&t<=356))
                    seas = 1.0+amplitude*0.2411/0.7589;
                  else
                     seas = 1.0-amplitude;

                  // transmission rate
                  beta = R0*(gamma+mu)*seas;

                  // expected force of infection
                  foi = beta*pow(I+iota,alpha)/pop;

                  // white noise (extrademographic stochasticity)
                  dw = rgammawn(sigmaSE,dt);

                  rate[0] = foi*dw/dt;  // stochastic force of infection
                  rate[1] = mu;			// natural S death
                  rate[2] = sigma;		// rate of ending of latent stage
                  rate[3] = mu;			// natural E death
                  rate[4] = gamma;		// recovery
                  rate[5] = mu;			// natural I death

                  // Poisson births
                  births = rpois(br*dt);

                  // Vaccination
                  vac = nearbyint(vr*br*.92*dt);

                  // transitions between classes
                  reulermultinom(2,S,&rate[0],dt,&trans[0]);
                  reulermultinom(2,E,&rate[2],dt,&trans[2]);
                  reulermultinom(2,I,&rate[4],dt,&trans[4]);

		          if (vac > S - trans[0] - trans[1]){
		          	vac = S - trans[0] - trans[1];
		          }

                  S += births   - trans[0] - trans[1] - vac;
                  E += trans[0] - trans[2] - trans[3];
                  I += trans[2] - trans[4] - trans[5];
                  R = pop - S - E - I + vac;
                  W += (dw - dt)/sigmaSE;  // standardized i.i.d. white noise
                  C += trans[4];           // true incidence
                  ")

rinit <- Csnippet("
  double m = pop/(S_0+E_0+I_0+R_0);
  S = nearbyint(m*S_0);
  E = nearbyint(m*E_0);
  I = nearbyint(m*I_0);
  R = nearbyint(m*R_0);
  W = 0;
  C = 0;
")

dmeas <- Csnippet("
  double m = rho*C;
  double v = m*(1.0-rho+psi*psi*m);
  double tol = 1.0e-18;
  if (cases > 0.0) {
    lik = pnorm(cases+0.5,m,sqrt(v)+tol,1,0)
            - pnorm(cases-0.5,m,sqrt(v)+tol,1,0)+tol;
  } else {
    lik = pnorm(cases+0.5,m,sqrt(v)+tol,1,0)+tol;
  }
  if (give_log) lik = log(lik);
  if (!R_FINITE(lik)) 
                 Rprintf(\"%lg %lg %lg %lg %lg %lg\\n\",rho,C,m,v,psi,lik);
")

rmeas <- Csnippet("
  double m = rho*C;
  double v = m*(1.0-rho+psi*psi*m);
  double tol = 1.0e-18;
  cases = rnorm(m,sqrt(v)+tol);
  if (cases > 0.0) {
    cases = nearbyint(cases);
  } else {
    cases = 0.0;
  }
")

## POMP Construction ----------------------------------------------------------
cpox %>% 
  pomp(t0=with(cpox, time[1]),
       time="time",
       rprocess=euler(rproc,delta.t=1/365.25),
       rinit=rinit,
       dmeasure=dmeas,
       rmeasure=rmeas,
       covar=covariate_table(hungary_covar,times="time"),
       accumvars=c("C","W"),
       statenames=c("S","E","I","R","C","W"),
       paramnames=c("R0","mu","sigma","gamma","alpha","iota",
                    "rho","sigmaSE","psi", "cohort", "amplitude", 
                    "S_0","E_0","I_0","R_0","vr")
  ) -> m1

## Initial Parameter Selection (MLEs) -----------------------------------------
# Some were selected based on feasible values, others taken from Measles/Polio 
# data in class
read_csv("
  town,loglik,loglik.sd,mu,delay,sigma,gamma,rho,R0,amplitude,alpha,iota,cohort,psi,S_0,E_0,I_0,R_0,sigmaSE
  Birmingham,-3239.3,1.55,0.02,4,45.6,32.9,0.544,43.4,0.428,1.01,0.343,0.331,0.178,0.0264,8.96e-05,0.000335,0.973,0.0611
  ") -> mles

paramnames <- c("R0","mu","sigma","gamma","alpha","iota",
                "rho","sigmaSE","psi","cohort","amplitude",
                "S_0","E_0","I_0","R_0", "vr")

mles$vr <- 0.2 # vaccination rate
mles$R0 <- 9 # we know this R_0
mles$delay <- 1
mles$mu <- 0.0001
mles$rho <- 0.43 # reporting rate
mles$cohort <- 0.5

mles[paramnames] %>% unlist() -> theta
mles %>% select(-S_0,-E_0,-I_0,-R_0)


library(doParallel); library(doRNG)

registerDoParallel()
registerDoRNG(998468235L)

foreach(i=1:4, .combine=c) %dopar% {
  library(pomp)
  pfilter(m1,Np=5000,params=theta)
} -> pfs

pfs %>% logLik() %>% logmeanexp(se=TRUE) -> L_pf

pfs[[1]] %>% coef() %>% bind_rows() %>%
  bind_cols(loglik=L_pf[1],loglik.se=L_pf[2]) %>%
  write_csv("cpox_params_2.csv")

## Estimating POMP parameters -------------------------------------------------

cpox_Np      <- c(1000, 5e3, 1e4)
cpox_Nmif    <- c(  10, 200, 400)
cpox_Neval   <- c(   2,  10,  20)
cpox_Nlocal  <- c(  10,  20,  40)
cpox_Nglobal <- c(  10,  20, 100)
cpox_Nsim    <- c(  50, 100, 500)


## Add initial parameters to POMP model
m1 <- pomp(m1, params=theta)


## LOCAL SEARCH ---------------------------------------------------------------

cpox_rw.sd <- 0.02
cpox_cooling.fraction.50 <- 0.1

pt <- parameter_trans(
  log=c("sigma","gamma","sigmaSE","psi","R0"),
  logit=c("cohort","amplitude", "vr", "rho"),
  barycentric=c("S_0","E_0","I_0","R_0")
)

m1 %>% pomp(partrans=pt,
      statenames=c("S","E","I","R","C","W"),
       paramnames=c("R0","mu","sigma","gamma","alpha","iota",
                    "rho","sigmaSE","psi", "cohort", "amplitude",
                    "S_0","E_0","I_0","R_0","vr")) -> m1

estpars <- setdiff(names(theta),c("sigmaSE","mu","alpha","rho","iota"))

theta["alpha"] <- 1

theta.t <- partrans(m1, theta, "toEst")

theta.t.hi <- theta.t.lo <- theta.t
theta.t.lo[estpars] <- theta.t[estpars] - log(2)
theta.t.hi[estpars] <- theta.t[estpars] + log(2)

profile_design(
  sigmaSE = seq(from=log(0.02), to=log(0.2), length=20),
  lower = theta.t.lo,
  upper = theta.t.hi,
  nprof = 40
) -> pd

pd <- as.data.frame(t(partrans(m1,t(pd),"fromEst")))

pairs(~sigmaSE+R0+mu+sigma+gamma+S_0+E_0, data=pd)

library(doRNG)

## METHOD 2 FOR LOCAL SEARCH

bake(file="local_search_2.rds",{
  registerDoRNG(482947940)
  foreach(i=1:20,.combine=c) %dopar% {
    library(pomp)
    library(tidyverse)
    m1 %>%
      mif2(
        Np=cpox_Np[run_level],
        Nmif=cpox_Nmif[run_level],
        cooling.type="geometric",
        cooling.fraction.50=cpox_cooling.fraction.50,
        rw.sd=rw.sd(
          R0=cpox_rw.sd,
          gamma=cpox_rw.sd,
          alpha=cpox_rw.sd,
          iota=cpox_rw.sd,
          rho=cpox_rw.sd,
          psi=cpox_rw.sd,
          sigma=cpox_rw.sd,
          sigmaSE=cpox_rw.sd,
          cohort=cpox_rw.sd,
          vr=cpox_rw.sd,
          amplitude=cpox_rw.sd,
          S_0=ivp(0.02),
          E_0=ivp(0.02),
          I_0=ivp(0.02),
          R_0=ivp(0.02)
          )
        )
  } -> mifs_local
  attr(mifs_local,"ncpu") <- getDoParWorkers()
  mifs_local
}) -> mifs_local

t_loc <- attr(mifs_local,"system.time")
ncpu_loc <- attr(mifs_local,"ncpu")

# mifs_local = readRDS("local_search_3.rds")
mifs_local %>%
  traces() %>%
  melt() %>%
  ggplot(aes(x=iteration,y=value,group=L1,color=factor(L1)))+
  geom_line()+
  guides(color="none")+
  facet_wrap(~variable,scales="free_y")

bake(file="lik_local_2.rds",{
  registerDoRNG(900242057)
  foreach(mf=mifs_local,.combine=rbind) %dopar% {
    library(pomp)
    library(tidyverse)
    evals <- replicate(10, logLik(pfilter(mf,Np=5000)))
    ll <- logmeanexp(evals,se=TRUE)
    mf %>% coef() %>% bind_rows() %>%
      bind_cols(loglik=ll[1],loglik.se=ll[2])
  } -> results
  attr(results,"ncpu") <- getDoParWorkers()
  results
}) -> results
t_local <- attr(results,"system.time")
ncpu_local <- attr(results,"ncpu")

# results=readRDS("lik_local_3.rds")
pairs(~loglik+gamma+alpha+iota+rho+psi+sigma+sigmaSE+cohort+vr+amplitude,data=results,pch=16)


results_local <- data.frame(logLik=liks_local[,1],logLik_se=liks_local[,2],t(sapply(mifs_local,coef)))
summary(results_local$logLik,digits=5)


## Global Search --------------------------------------------------------------

runif_design(
  lower=c(R0=6,gamma=60,alpha=0.7, cohort= 0.4, iota=0, rho=0.2, psi = 0.15, sigma=41, sigmaSE=0.03, vr=0.1,amplitude=0.1),
  upper=c(R0=14,gamma=170,alpha=1,cohort=1, iota=0.4, rho=0.9, psi=0.5, sigma=56, sigmaSE=0.09, vr=0.3, amplitude=0.5),
  nseq=200
) -> guesses

# mifs_local=readRDS("local_search_2.rds")

mf1 <- mifs_local[[1]]

fixed_params <- c(mu=0.0001, S_0=0.00477, E_0=2.66e-05, I_0=2.081e-05, R_0=.9522)
coef(m1,names(fixed_params)) <- fixed_params

bake(file="global_search_2_new.rds",
  dependson=guesses,{
    registerDoRNG(1270401374)
    foreach(guess=iter(guesses,"row"), .combine=rbind) %dopar% {
      library(pomp)
      library(tidyverse)
      mf1 %>%
        mif2(params=c(guess,fixed_params)) %>%
        mif2(Nmif=cpox_Nmif[run_level]) -> mf
      replicate(
        10,
        mf %>% pfilter(Np=cpox_Np[run_level]) %>% logLik()
      ) %>%
        logmeanexp(se=TRUE) -> ll
      mf %>% coef() %>% bind_rows() %>%
        bind_cols(loglik=ll[1],loglik.se=ll[2])
    } -> results
    attr(results,"ncpu") <- getDoParWorkers()
    results
  }) %>%
  filter(is.finite(loglik)) -> results
t_global <- attr(results,"system.time")
ncpu_global <- attr(results,"ncpu")

results = readRDS("global_search_1.rds")

read_csv("cpox_params_1.csv") %>%
  bind_rows(results) %>%
  filter(is.finite(loglik)) %>%
  arrange(-loglik) %>%
  write_csv("cpox_params_1.csv")

read_csv("cpox_params_1.csv") %>%
  filter(loglik>max(loglik)-50) %>%
  bind_rows(guesses) %>%
  mutate(type=if_else(is.na(loglik),"guess","result")) %>%
  arrange(type) -> all

pairs(~loglik+gamma+alpha+iota+rho+psi+sigma+sigmaSE+cohort+vr+amplitude, data=all, pch=16, cex=0.3,
  col=ifelse(all$type=="guess",grey(0.5),"red"))

all %>%
  filter(type=="result") %>%
  filter(loglik>max(loglik)-10) %>%
  ggplot(aes(x=vr,y=loglik))+
  geom_point()+
  labs(
    x=expression(vr),
    title="poor man's profile likelihood"
  )

read_csv("cpox_params_1.csv") %>%
  filter(loglik>max(loglik)-20,loglik.se<2) %>%
  sapply(range) -> box
box

results_global <- data.frame(logLik=liks_global[,1],logLik_se=liks_global[,2],t(sapply(mifs_global,coef)))
summary(results_global$logLik,digits=5)

# mifs_global = readRDS("global_search_1.rds")

bake(file="lik_global_1.rds",{
  registerDoRNG(900242057)
  foreach(mf=mifs_global,.combine=rbind) %dopar% {
    library(pomp)
    library(tidyverse)
    evals <- replicate(10, logLik(pfilter(mf,params=coef(mifs_global[[i]]),Np=cpox_Np[run_level])))
    ll <- logmeanexp(evals,se=TRUE)
    mf %>% coef() %>% bind_rows() %>%
      bind_cols(loglik=ll[1],loglik.se=ll[2])
  } -> results
  attr(results,"ncpu") <- getDoParWorkers()
  results
}) -> results
t_local <- attr(results,"system.time")
ncpu_local <- attr(results,"ncpu")