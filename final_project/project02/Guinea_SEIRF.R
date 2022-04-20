library(tidyverse)
df1 = read.csv(file = 'Gu.csv')

library(pomp)
library(doParallel)
cores <-  as.numeric(Sys.getenv('SLURM_NTASKS_PER_NODE', unset=NA))
if(is.na(cores)) cores <- detectCores()  
registerDoParallel(cores)

seir_step <- Csnippet("
  double dN_SE = rbinom(S,1-exp(-Beta*I/N*dt)) + rbinom(F_size*F,1-exp(-Beta2/F_size*dt));
  double dN_EI = rbinom(E,1-exp(-mu_EI*dt));
  double dN_IR = rbinom(I,1-exp(-mu_IR*dt));
  double dN_DF = rbinom(round(dN_IR/2),1-exp(-mu_DF*dt));
  
  S -= dN_SE;
  E += dN_SE - dN_EI;
  I += dN_EI - dN_IR;
  R += round(dN_IR/2);
  D += round(dN_IR/2);
  F = round(dN_DF);
  H += dN_IR;
")

seir_rinit <- Csnippet("
  S = nearbyint(eta*N)-482;
  E = 0;
  I = 482;
  R = nearbyint((1-eta)*N);
  F = 0;
  H = 0;
  ")

dmeas <- Csnippet("
double tol = 1.0e-25;

if(reports > 0.0 && H > 0.0)
{
lik = dbinom(reports,H,rho,FALSE) + tol;
} 
else
{
lik = tol;
}
if (give_log) lik = log(lik);

")

rmeas <- Csnippet("

reports = rbinom(H,rho);
if (reports > 0.0) 
{
reports = nearbyint(reports);
} 
else 
{
reports = 0.0;
}
")

ebola = df1 %>%
    select(Date,reports=New_Report) %>%
    pomp(
        times="Date",t0=0,
        rprocess=euler(seir_step,delta.t=1),
        rinit=seir_rinit,
        rmeasure=rmeas,
        dmeasure=dmeas,
        accumvars="H",
        partrans=parameter_trans(
            log=c("Beta","Beta2","mu_EI","mu_IR","mu_DF","F_size"),
            logit=c("rho","eta")
        ),
        paramnames=c("N","Beta","Beta2","mu_EI","mu_IR","mu_DF","F_size","rho","eta"),
        statenames=c("S","E","I","R","D","F","H")
    )

set.seed(531)

params <- c(Beta=17, Beta2=0.8, mu_EI=15,mu_IR=1.5,mu_DF=0.9,F_size=50,rho=0.33,eta=0.025,N=10628972)

foreach(i=1:10,.combine=c) %dopar% {
    library(pomp)
    ebola %>% pfilter(params=params,Np=100)
} -> pf
pf %>% logLik() %>% logmeanexp(se=TRUE) -> L_pf

# pf[[1]] %>% coef() %>% bind_rows() %>%
#     bind_cols(loglik=L_pf[1],loglik.se=L_pf[2]) %>%
#     write_csv("Guinea_params.csv")


### local
# set the random walk parameters
ebola_cooling.fraction.50 <- 0.5
ebola_rw.sd <- rw.sd(
    Beta=0.002,Beta2=0.002,mu_EI=0.002,mu_IR=0.002,mu_DF=0.002,rho=0.002,eta=ivp(0.002)
)

params <- c(Beta=17, Beta2=0.8, mu_EI=15,mu_IR=1.5,mu_DF=0.9,F_size=50,rho=0.33,eta=0.025,N=10628972)

bake(file="local_GU.rds",{
    foreach(i=1:20,.combine=c) %dopar% {
        library(pomp)
        library(tidyverse)
        mif2(ebola,
             params = params,
             Np=2000,
             Nmif=100,
             cooling.fraction.50=ebola_cooling.fraction.50,
             rw.sd=ebola_rw.sd) 
    } -> mifs_local 
}) -> mifs_local

bake(file="lik_local_GU.rds",{
    foreach(mf=mifs_local,.combine=rbind) %dopar% {
        library(pomp)
        library(tidyverse)
        evals <- replicate(10, logLik(pfilter(mf,Np=5000)))
        ll <- logmeanexp(evals,se=TRUE)
        mf %>% coef() %>% bind_rows() %>% bind_cols(loglik=ll[1],loglik.se=ll[2])
    } -> local_logliks
}) -> local_logliks

# read_csv("Guinea_params.csv") %>%
#     bind_rows(results) %>%
#     arrange(-loglik) %>%
#     write_csv("Guinea_params.csv")

### Global
#Beta=0.02, Beta2=3, mu_EI=23,mu_IR=0.94,mu_DF=6.16,F_size=50,rho=0.43,eta=0.003,N=10628972
set.seed(1234567)
fixed_params = c(F_size=50, N=10628972)
runif_design(
    lower=c(Beta=3, Beta2=0.5, mu_EI=10, mu_IR=0.7, mu_DF=0.5, rho=0.35,eta=0),
    upper=c(Beta=7, Beta2=1.5, mu_EI=20, mu_IR=1.2, mu_DF=1.2, rho=0.45,eta=0.1),
    nseq=500
) -> guesses
mf1 <- mifs_local[[1]]


bake(file="global_GU.rds",{
    foreach(guess=iter(guesses,"row"), .combine=rbind) %dopar% {
        library(pomp)
        library(tidyverse)
        mf1 %>%
            mif2(params=c(guess,fixed_params)) %>%
            mif2(Nmif=200) -> mf
        replicate(
            10,
            mf %>% pfilter(Np=10000) %>% logLik()
        ) %>%
            logmeanexp(se=TRUE) -> ll
        mf %>% coef() %>% bind_rows() %>%
            bind_cols(loglik=ll[1],loglik.se=ll[2])
    } -> results
}) %>%
  filter(is.finite(loglik)) -> results

# read_csv("Guinea_params.csv") %>%
#     filter(loglik>max(loglik)-50) %>%
#     bind_rows(guesses) %>%
#     mutate(type=if_else(is.na(loglik),"guess","result")) %>%
#     arrange(type) -> all

# read_csv("Guinea_params.csv") %>%
#     group_by(cut=round(Beta,2)) %>%
#     filter(rank(-loglik)<=10) %>%
#     ungroup() %>%
#     arrange(-loglik) %>%
#     select(-cut,-loglik,-loglik.se) -> guesses

bake(file="beta_GU.rds",dependson=guesses,{
    foreach(guess=iter(guesses,"row"), .combine=rbind) %dopar% {
        library(pomp)
        library(tidyverse)
        mf1 %>%
            mif2(params=c(guess,fixed_params),Nmif=100,
                 rw.sd=rw.sd(Beta2=0.002,mu_EI=0.002,mu_IR=0.002,mu_DF=0.002,rho=0.002,eta=ivp(0.002))) %>%
            mif2(Nmif=100,cooling.fraction.50=0.2) -> mf
        replicate(
            10,
            mf %>% pfilter(Np=5000) %>% logLik()) %>%
            logmeanexp(se=TRUE) -> ll
        mf %>% coef() %>% bind_rows() %>%
            bind_cols(loglik=ll[1],loglik.se=ll[2])
    } -> prof_results
}) -> prof_results
prof_results %>%
  filter(is.finite(loglik)) -> profile_results
# read_csv("Guinea_params.csv") %>%
#     bind_rows(results) %>%
#     filter(is.finite(loglik)) %>%
#     arrange(-loglik) %>%
#     write_csv("Guinea_params.csv")

profile_results %>%
  filter(loglik>max(loglik)-0.5*qchisq(df=1,p=0.95)) %>%
  summarize(min=min(Beta),max=max(Beta)) -> beta_GU_ci

save(beta_GU_ci, file = "./Guinea_Beta_CI.RData")
