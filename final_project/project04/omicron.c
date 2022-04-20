/* pomp C snippet file: omicron */
/* Time: 2022-04-19 15:56:00.860 -0400 */
/* Salt: 43F8615F438492A685E8804F */

#include <E:/R-4.0.2/library/pomp/include/pomp.h>
#include <R_ext/Rdynload.h>

 


/* C snippet: 'rinit' */
#define Beta		(__p[__parindex[0]])
#define b1		(__p[__parindex[1]])
#define b2		(__p[__parindex[2]])
#define b3		(__p[__parindex[3]])
#define b4		(__p[__parindex[4]])
#define b5		(__p[__parindex[5]])
#define mu_EPI		(__p[__parindex[6]])
#define mu_PR		(__p[__parindex[7]])
#define mu_IR		(__p[__parindex[8]])
#define mu_RS		(__p[__parindex[9]])
#define eta		(__p[__parindex[10]])
#define rho		(__p[__parindex[11]])
#define N		(__p[__parindex[12]])
#define tau		(__p[__parindex[13]])
#define alpha		(__p[__parindex[14]])
#define intervention		(__covars[__covindex[0]])
#define S		(__x[__stateindex[0]])
#define E		(__x[__stateindex[1]])
#define P		(__x[__stateindex[2]])
#define I		(__x[__stateindex[3]])
#define R		(__x[__stateindex[4]])
#define H		(__x[__stateindex[5]])

void __pomp_rinit (double *__x, const double *__p, double t, const int *__stateindex, const int *__parindex, const int *__covindex, const double *__covars)
{
 
  S = nearbyint(eta*N);
  E = 100;
  I = 200;
  P = 50;
  R = nearbyint((1-eta)*N);
  H = 0;
 
}

#undef Beta
#undef b1
#undef b2
#undef b3
#undef b4
#undef b5
#undef mu_EPI
#undef mu_PR
#undef mu_IR
#undef mu_RS
#undef eta
#undef rho
#undef N
#undef tau
#undef alpha
#undef intervention
#undef S
#undef E
#undef P
#undef I
#undef R
#undef H

/* C snippet: 'step.fn' */
#define Beta		(__p[__parindex[0]])
#define b1		(__p[__parindex[1]])
#define b2		(__p[__parindex[2]])
#define b3		(__p[__parindex[3]])
#define b4		(__p[__parindex[4]])
#define b5		(__p[__parindex[5]])
#define mu_EPI		(__p[__parindex[6]])
#define mu_PR		(__p[__parindex[7]])
#define mu_IR		(__p[__parindex[8]])
#define mu_RS		(__p[__parindex[9]])
#define eta		(__p[__parindex[10]])
#define rho		(__p[__parindex[11]])
#define N		(__p[__parindex[12]])
#define tau		(__p[__parindex[13]])
#define alpha		(__p[__parindex[14]])
#define intervention		(__covars[__covindex[0]])
#define S		(__x[__stateindex[0]])
#define E		(__x[__stateindex[1]])
#define P		(__x[__stateindex[2]])
#define I		(__x[__stateindex[3]])
#define R		(__x[__stateindex[4]])
#define H		(__x[__stateindex[5]])

void __pomp_stepfn (double *__x, const double *__p, const int *__stateindex, const int *__parindex, const int *__covindex, const double *__covars, double t, double dt)
{
 
  double Beta_intervention;
  
  if (intervention==1){
    Beta_intervention = Beta*b1;
  }
  else if (intervention==2){
    Beta_intervention = Beta*b2;
  }
  else if (intervention==3){
    Beta_intervention = Beta*b3;
  }
  else if (intervention==4){
    Beta_intervention = Beta*b4;
  }
  else if (intervention==5){
    Beta_intervention = Beta*b5;
  }
  else {
    Beta_intervention = Beta;
  }
  
  double dN_SE = rbinom(S,1-exp(-Beta_intervention*(I+P)/N*dt));
  double dN_EPI = rbinom(E,1-exp(-mu_EPI*dt));
  double dN_PR = rbinom(P,1-exp(-mu_PR*dt));
  double dN_IR = rbinom(I,1-exp(-mu_IR*dt));
  double dN_RS = rbinom(I,1-exp(-mu_RS*dt));
  S -= dN_SE - dN_RS;
  E += dN_SE - dN_EPI;
  P += nearbyint(alpha*dN_EPI) - dN_PR;
  I += nearbyint((1-alpha)*dN_EPI) - dN_IR;
  R += dN_PR+dN_IR;
  H += dN_IR;
 
}

#undef Beta
#undef b1
#undef b2
#undef b3
#undef b4
#undef b5
#undef mu_EPI
#undef mu_PR
#undef mu_IR
#undef mu_RS
#undef eta
#undef rho
#undef N
#undef tau
#undef alpha
#undef intervention
#undef S
#undef E
#undef P
#undef I
#undef R
#undef H

/* C snippet: 'rmeasure' */
#define Beta		(__p[__parindex[0]])
#define b1		(__p[__parindex[1]])
#define b2		(__p[__parindex[2]])
#define b3		(__p[__parindex[3]])
#define b4		(__p[__parindex[4]])
#define b5		(__p[__parindex[5]])
#define mu_EPI		(__p[__parindex[6]])
#define mu_PR		(__p[__parindex[7]])
#define mu_IR		(__p[__parindex[8]])
#define mu_RS		(__p[__parindex[9]])
#define eta		(__p[__parindex[10]])
#define rho		(__p[__parindex[11]])
#define N		(__p[__parindex[12]])
#define tau		(__p[__parindex[13]])
#define alpha		(__p[__parindex[14]])
#define intervention		(__covars[__covindex[0]])
#define S		(__x[__stateindex[0]])
#define E		(__x[__stateindex[1]])
#define P		(__x[__stateindex[2]])
#define I		(__x[__stateindex[3]])
#define R		(__x[__stateindex[4]])
#define H		(__x[__stateindex[5]])
#define Date		(__y[__obsindex[0]])
#define reports		(__y[__obsindex[1]])

void __pomp_rmeasure (double *__y, const double *__x, const double *__p, const int *__obsindex, const int *__stateindex, const int *__parindex, const int *__covindex, const double *__covars, double t)
{
 
  reports = rnorm(rho*H, sqrt(pow(tau*H,2)+rho*H));
  if(reports>0.0){
    reports=nearbyint(reports);
  } else {
    reports=0.0;
  }
 
}

#undef Beta
#undef b1
#undef b2
#undef b3
#undef b4
#undef b5
#undef mu_EPI
#undef mu_PR
#undef mu_IR
#undef mu_RS
#undef eta
#undef rho
#undef N
#undef tau
#undef alpha
#undef intervention
#undef S
#undef E
#undef P
#undef I
#undef R
#undef H
#undef Date
#undef reports

/* C snippet: 'dmeasure' */
#define Beta		(__p[__parindex[0]])
#define b1		(__p[__parindex[1]])
#define b2		(__p[__parindex[2]])
#define b3		(__p[__parindex[3]])
#define b4		(__p[__parindex[4]])
#define b5		(__p[__parindex[5]])
#define mu_EPI		(__p[__parindex[6]])
#define mu_PR		(__p[__parindex[7]])
#define mu_IR		(__p[__parindex[8]])
#define mu_RS		(__p[__parindex[9]])
#define eta		(__p[__parindex[10]])
#define rho		(__p[__parindex[11]])
#define N		(__p[__parindex[12]])
#define tau		(__p[__parindex[13]])
#define alpha		(__p[__parindex[14]])
#define intervention		(__covars[__covindex[0]])
#define S		(__x[__stateindex[0]])
#define E		(__x[__stateindex[1]])
#define P		(__x[__stateindex[2]])
#define I		(__x[__stateindex[3]])
#define R		(__x[__stateindex[4]])
#define H		(__x[__stateindex[5]])
#define Date		(__y[__obsindex[0]])
#define reports		(__y[__obsindex[1]])
#define lik		(__lik[0])

void __pomp_dmeasure (double *__lik, const double *__y, const double *__x, const double *__p, int give_log, const int *__obsindex, const int *__stateindex, const int *__parindex, const int *__covindex, const double *__covars, double t)
{
 
  double tol=1.0e-25;
  double mean =rho*H;
  double sd =sqrt(pow(tau*H,2)+rho*H);
  if(reports>0.0){
    lik=pnorm(reports+0.5,mean,sd,1,0)-pnorm(reports-0.5,mean,sd,1,0)+tol;
  } else {
    lik=pnorm(reports+0.5,mean,sd,1,0)+tol;
  }
  if(give_log) lik=log(lik);
 
}

#undef Beta
#undef b1
#undef b2
#undef b3
#undef b4
#undef b5
#undef mu_EPI
#undef mu_PR
#undef mu_IR
#undef mu_RS
#undef eta
#undef rho
#undef N
#undef tau
#undef alpha
#undef intervention
#undef S
#undef E
#undef P
#undef I
#undef R
#undef H
#undef Date
#undef reports
#undef lik

/* C snippet: 'toEst' */
#define intervention		(__covars[__covindex[0]])
#define Beta		(__p[__parindex[0]])
#define b1		(__p[__parindex[1]])
#define b2		(__p[__parindex[2]])
#define b3		(__p[__parindex[3]])
#define b4		(__p[__parindex[4]])
#define b5		(__p[__parindex[5]])
#define mu_EPI		(__p[__parindex[6]])
#define mu_PR		(__p[__parindex[7]])
#define mu_IR		(__p[__parindex[8]])
#define mu_RS		(__p[__parindex[9]])
#define eta		(__p[__parindex[10]])
#define rho		(__p[__parindex[11]])
#define N		(__p[__parindex[12]])
#define tau		(__p[__parindex[13]])
#define alpha		(__p[__parindex[14]])
#define T_Beta		(__pt[__parindex[0]])
#define T_b1		(__pt[__parindex[1]])
#define T_b2		(__pt[__parindex[2]])
#define T_b3		(__pt[__parindex[3]])
#define T_b4		(__pt[__parindex[4]])
#define T_b5		(__pt[__parindex[5]])
#define T_mu_EPI		(__pt[__parindex[6]])
#define T_mu_PR		(__pt[__parindex[7]])
#define T_mu_IR		(__pt[__parindex[8]])
#define T_mu_RS		(__pt[__parindex[9]])
#define T_eta		(__pt[__parindex[10]])
#define T_rho		(__pt[__parindex[11]])
#define T_N		(__pt[__parindex[12]])
#define T_tau		(__pt[__parindex[13]])
#define T_alpha		(__pt[__parindex[14]])

void __pomp_to_trans (double *__pt, const double *__p, const int *__parindex)
{
 	T_Beta = log(Beta);
	T_b1 = log(b1);
	T_b2 = log(b2);
	T_b3 = log(b3);
	T_b4 = log(b4);
	T_b5 = log(b5);
	T_mu_EPI = log(mu_EPI);
	T_mu_PR = log(mu_PR);
	T_mu_IR = log(mu_IR);
	T_mu_RS = log(mu_RS);
	T_tau = log(tau);
	T_rho = logit(rho);
	T_alpha = logit(alpha); 
}

#undef intervention
#undef Beta
#undef b1
#undef b2
#undef b3
#undef b4
#undef b5
#undef mu_EPI
#undef mu_PR
#undef mu_IR
#undef mu_RS
#undef eta
#undef rho
#undef N
#undef tau
#undef alpha
#undef T_Beta
#undef T_b1
#undef T_b2
#undef T_b3
#undef T_b4
#undef T_b5
#undef T_mu_EPI
#undef T_mu_PR
#undef T_mu_IR
#undef T_mu_RS
#undef T_eta
#undef T_rho
#undef T_N
#undef T_tau
#undef T_alpha

/* C snippet: 'fromEst' */
#define intervention		(__covars[__covindex[0]])
#define Beta		(__p[__parindex[0]])
#define b1		(__p[__parindex[1]])
#define b2		(__p[__parindex[2]])
#define b3		(__p[__parindex[3]])
#define b4		(__p[__parindex[4]])
#define b5		(__p[__parindex[5]])
#define mu_EPI		(__p[__parindex[6]])
#define mu_PR		(__p[__parindex[7]])
#define mu_IR		(__p[__parindex[8]])
#define mu_RS		(__p[__parindex[9]])
#define eta		(__p[__parindex[10]])
#define rho		(__p[__parindex[11]])
#define N		(__p[__parindex[12]])
#define tau		(__p[__parindex[13]])
#define alpha		(__p[__parindex[14]])
#define T_Beta		(__pt[__parindex[0]])
#define T_b1		(__pt[__parindex[1]])
#define T_b2		(__pt[__parindex[2]])
#define T_b3		(__pt[__parindex[3]])
#define T_b4		(__pt[__parindex[4]])
#define T_b5		(__pt[__parindex[5]])
#define T_mu_EPI		(__pt[__parindex[6]])
#define T_mu_PR		(__pt[__parindex[7]])
#define T_mu_IR		(__pt[__parindex[8]])
#define T_mu_RS		(__pt[__parindex[9]])
#define T_eta		(__pt[__parindex[10]])
#define T_rho		(__pt[__parindex[11]])
#define T_N		(__pt[__parindex[12]])
#define T_tau		(__pt[__parindex[13]])
#define T_alpha		(__pt[__parindex[14]])

void __pomp_from_trans (double *__p, const double *__pt, const int *__parindex)
{
 	Beta = exp(T_Beta);
	b1 = exp(T_b1);
	b2 = exp(T_b2);
	b3 = exp(T_b3);
	b4 = exp(T_b4);
	b5 = exp(T_b5);
	mu_EPI = exp(T_mu_EPI);
	mu_PR = exp(T_mu_PR);
	mu_IR = exp(T_mu_IR);
	mu_RS = exp(T_mu_RS);
	tau = exp(T_tau);
	rho = expit(T_rho);
	alpha = expit(T_alpha); 
}

#undef intervention
#undef Beta
#undef b1
#undef b2
#undef b3
#undef b4
#undef b5
#undef mu_EPI
#undef mu_PR
#undef mu_IR
#undef mu_RS
#undef eta
#undef rho
#undef N
#undef tau
#undef alpha
#undef T_Beta
#undef T_b1
#undef T_b2
#undef T_b3
#undef T_b4
#undef T_b5
#undef T_mu_EPI
#undef T_mu_PR
#undef T_mu_IR
#undef T_mu_RS
#undef T_eta
#undef T_rho
#undef T_N
#undef T_tau
#undef T_alpha

static int __pomp_load_stack = 0;

void __pomp_load_stack_incr (void) {++__pomp_load_stack;}

void __pomp_load_stack_decr (int *val) {*val = --__pomp_load_stack;}

void R_init_omicron (DllInfo *info)
{
R_RegisterCCallable("omicron", "__pomp_load_stack_incr", (DL_FUNC) __pomp_load_stack_incr);
R_RegisterCCallable("omicron", "__pomp_load_stack_decr", (DL_FUNC) __pomp_load_stack_decr);
R_RegisterCCallable("omicron", "__pomp_rinit", (DL_FUNC) __pomp_rinit);
R_RegisterCCallable("omicron", "__pomp_stepfn", (DL_FUNC) __pomp_stepfn);
R_RegisterCCallable("omicron", "__pomp_rmeasure", (DL_FUNC) __pomp_rmeasure);
R_RegisterCCallable("omicron", "__pomp_dmeasure", (DL_FUNC) __pomp_dmeasure);
R_RegisterCCallable("omicron", "__pomp_to_trans", (DL_FUNC) __pomp_to_trans);
R_RegisterCCallable("omicron", "__pomp_from_trans", (DL_FUNC) __pomp_from_trans);
}
