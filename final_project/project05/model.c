/* pomp C snippet file: model */
/* Time: 2022-04-19 21:06:15.900 -0400 */
/* Salt: 06D7B6D1624EF75567AA5FCC */

#include <pomp.h>
#include <R_ext/Rdynload.h>

 


/* C snippet: 'rinit' */
#define b1		(__p[__parindex[0]])
#define b2		(__p[__parindex[1]])
#define b3		(__p[__parindex[2]])
#define nu		(__p[__parindex[3]])
#define gamma		(__p[__parindex[4]])
#define mu_EI		(__p[__parindex[5]])
#define mu_IQ		(__p[__parindex[6]])
#define kappa		(__p[__parindex[7]])
#define mu_QR		(__p[__parindex[8]])
#define mu_QD		(__p[__parindex[9]])
#define rho		(__p[__parindex[10]])
#define N		(__p[__parindex[11]])
#define chi		(__p[__parindex[12]])
#define initial_V		(__p[__parindex[13]])
#define last_week_cases		(__p[__parindex[14]])
#define phi		(__p[__parindex[15]])
#define psi		(__p[__parindex[16]])
#define initial_Q		(__p[__parindex[17]])
#define initial_R		(__p[__parindex[18]])
#define initial_D		(__p[__parindex[19]])
#define intervention		(__covars[__covindex[0]])
#define S		(__x[__stateindex[0]])
#define V		(__x[__stateindex[1]])
#define E		(__x[__stateindex[2]])
#define I		(__x[__stateindex[3]])
#define Q		(__x[__stateindex[4]])
#define R		(__x[__stateindex[5]])
#define D		(__x[__stateindex[6]])
#define H		(__x[__stateindex[7]])

void __pomp_rinit (double *__x, const double *__p, double t, const int *__stateindex, const int *__parindex, const int *__covindex, const double *__covars)
{
 
  S = nearbyint(N - initial_V - nearbyint(last_week_cases *phi) - nearbyint(last_week_cases * psi) - initial_Q - initial_R - initial_D);
  V = nearbyint(initial_V);
  E = nearbyint(last_week_cases *phi);
  I = nearbyint(last_week_cases * psi);
  Q = nearbyint(initial_Q);
  R = nearbyint(initial_R);
  D = nearbyint(initial_D);
  H = nearbyint(0);
   
}

#undef b1
#undef b2
#undef b3
#undef nu
#undef gamma
#undef mu_EI
#undef mu_IQ
#undef kappa
#undef mu_QR
#undef mu_QD
#undef rho
#undef N
#undef chi
#undef initial_V
#undef last_week_cases
#undef phi
#undef psi
#undef initial_Q
#undef initial_R
#undef initial_D
#undef intervention
#undef S
#undef V
#undef E
#undef I
#undef Q
#undef R
#undef D
#undef H

/* C snippet: 'step.fn' */
#define b1		(__p[__parindex[0]])
#define b2		(__p[__parindex[1]])
#define b3		(__p[__parindex[2]])
#define nu		(__p[__parindex[3]])
#define gamma		(__p[__parindex[4]])
#define mu_EI		(__p[__parindex[5]])
#define mu_IQ		(__p[__parindex[6]])
#define kappa		(__p[__parindex[7]])
#define mu_QR		(__p[__parindex[8]])
#define mu_QD		(__p[__parindex[9]])
#define rho		(__p[__parindex[10]])
#define N		(__p[__parindex[11]])
#define chi		(__p[__parindex[12]])
#define initial_V		(__p[__parindex[13]])
#define last_week_cases		(__p[__parindex[14]])
#define phi		(__p[__parindex[15]])
#define psi		(__p[__parindex[16]])
#define initial_Q		(__p[__parindex[17]])
#define initial_R		(__p[__parindex[18]])
#define initial_D		(__p[__parindex[19]])
#define intervention		(__covars[__covindex[0]])
#define S		(__x[__stateindex[0]])
#define V		(__x[__stateindex[1]])
#define E		(__x[__stateindex[2]])
#define I		(__x[__stateindex[3]])
#define Q		(__x[__stateindex[4]])
#define R		(__x[__stateindex[5]])
#define D		(__x[__stateindex[6]])
#define H		(__x[__stateindex[7]])

void __pomp_stepfn (double *__x, const double *__p, const int *__stateindex, const int *__parindex, const int *__covindex, const double *__covars, double t, double dt)
{
 
  double Beta;
  if(intervention == 1) Beta = b1;
  else if(intervention == 2) Beta = b2;
  else if(intervention == 3) Beta = b3;

  double dN_SV = rbinom(S,1-exp(-nu*dt));
  double dN_SE = rbinom(S, 1-exp(-1*Beta*(I/N)*dt));
  double dN_VE = rbinom(V, 1-exp(-1*Beta*(1-gamma)*(I/N)*dt));
  double dN_EI = rbinom(E,1-exp(-mu_EI*dt));
  double dN_IQ = rbinom(I,1-exp(-mu_IQ*dt));
  double dN_QR = rbinom(Q,1-exp(-kappa*mu_QR*dt));
  double dN_QD = rbinom(Q,1-exp(-(1-kappa)*mu_QD*dt));
  
  
  S -= dN_SE +dN_SV; 
  V += dN_SV- dN_VE;
  E += dN_SE + dN_VE - dN_EI;
  I += dN_EI - dN_IQ;
  H += dN_IQ;
  Q += dN_IQ - dN_QR - dN_QD;
  R += dN_QR;
  D += dN_QD;
   
}

#undef b1
#undef b2
#undef b3
#undef nu
#undef gamma
#undef mu_EI
#undef mu_IQ
#undef kappa
#undef mu_QR
#undef mu_QD
#undef rho
#undef N
#undef chi
#undef initial_V
#undef last_week_cases
#undef phi
#undef psi
#undef initial_Q
#undef initial_R
#undef initial_D
#undef intervention
#undef S
#undef V
#undef E
#undef I
#undef Q
#undef R
#undef D
#undef H

/* C snippet: 'rmeasure' */
#define b1		(__p[__parindex[0]])
#define b2		(__p[__parindex[1]])
#define b3		(__p[__parindex[2]])
#define nu		(__p[__parindex[3]])
#define gamma		(__p[__parindex[4]])
#define mu_EI		(__p[__parindex[5]])
#define mu_IQ		(__p[__parindex[6]])
#define kappa		(__p[__parindex[7]])
#define mu_QR		(__p[__parindex[8]])
#define mu_QD		(__p[__parindex[9]])
#define rho		(__p[__parindex[10]])
#define N		(__p[__parindex[11]])
#define chi		(__p[__parindex[12]])
#define initial_V		(__p[__parindex[13]])
#define last_week_cases		(__p[__parindex[14]])
#define phi		(__p[__parindex[15]])
#define psi		(__p[__parindex[16]])
#define initial_Q		(__p[__parindex[17]])
#define initial_R		(__p[__parindex[18]])
#define initial_D		(__p[__parindex[19]])
#define intervention		(__covars[__covindex[0]])
#define S		(__x[__stateindex[0]])
#define V		(__x[__stateindex[1]])
#define E		(__x[__stateindex[2]])
#define I		(__x[__stateindex[3]])
#define Q		(__x[__stateindex[4]])
#define R		(__x[__stateindex[5]])
#define D		(__x[__stateindex[6]])
#define H		(__x[__stateindex[7]])
#define cases		(__y[__obsindex[0]])

void __pomp_rmeasure (double *__y, const double *__x, const double *__p, const int *__obsindex, const int *__stateindex, const int *__parindex, const int *__covindex, const double *__covars, double t)
{
 
  double tol= 1.0e-10;
  double mean =chi*H;
  double sd =sqrt(pow(rho*H,2)+chi*H+tol);


  cases = rnorm(mean, sd);
  if (sd <=0){
    cases = 0;
  }
  
  if(cases>0.0){
    cases = nearbyint(cases);
  } else {
    cases=0.0;
  }
 
}

#undef b1
#undef b2
#undef b3
#undef nu
#undef gamma
#undef mu_EI
#undef mu_IQ
#undef kappa
#undef mu_QR
#undef mu_QD
#undef rho
#undef N
#undef chi
#undef initial_V
#undef last_week_cases
#undef phi
#undef psi
#undef initial_Q
#undef initial_R
#undef initial_D
#undef intervention
#undef S
#undef V
#undef E
#undef I
#undef Q
#undef R
#undef D
#undef H
#undef cases

/* C snippet: 'dmeasure' */
#define b1		(__p[__parindex[0]])
#define b2		(__p[__parindex[1]])
#define b3		(__p[__parindex[2]])
#define nu		(__p[__parindex[3]])
#define gamma		(__p[__parindex[4]])
#define mu_EI		(__p[__parindex[5]])
#define mu_IQ		(__p[__parindex[6]])
#define kappa		(__p[__parindex[7]])
#define mu_QR		(__p[__parindex[8]])
#define mu_QD		(__p[__parindex[9]])
#define rho		(__p[__parindex[10]])
#define N		(__p[__parindex[11]])
#define chi		(__p[__parindex[12]])
#define initial_V		(__p[__parindex[13]])
#define last_week_cases		(__p[__parindex[14]])
#define phi		(__p[__parindex[15]])
#define psi		(__p[__parindex[16]])
#define initial_Q		(__p[__parindex[17]])
#define initial_R		(__p[__parindex[18]])
#define initial_D		(__p[__parindex[19]])
#define intervention		(__covars[__covindex[0]])
#define S		(__x[__stateindex[0]])
#define V		(__x[__stateindex[1]])
#define E		(__x[__stateindex[2]])
#define I		(__x[__stateindex[3]])
#define Q		(__x[__stateindex[4]])
#define R		(__x[__stateindex[5]])
#define D		(__x[__stateindex[6]])
#define H		(__x[__stateindex[7]])
#define cases		(__y[__obsindex[0]])
#define lik		(__lik[0])

void __pomp_dmeasure (double *__lik, const double *__y, const double *__x, const double *__p, int give_log, const int *__obsindex, const int *__stateindex, const int *__parindex, const int *__covindex, const double *__covars, double t)
{
 
  double tol= 1.0e-10;
  double mean =chi*H;
  double sd =sqrt(pow(rho*H,2)+chi*H)+tol;
  if (cases <= 10*sd || cases >= -10*sd){
    if(sd <= 0){
      lik = tol;
    }
    else{
      lik = dnorm(cases, mean, sd, 0)+tol;
    }
  }
  else{
  lik = tol;
  }
  if(give_log) lik=log(lik);
 
}

#undef b1
#undef b2
#undef b3
#undef nu
#undef gamma
#undef mu_EI
#undef mu_IQ
#undef kappa
#undef mu_QR
#undef mu_QD
#undef rho
#undef N
#undef chi
#undef initial_V
#undef last_week_cases
#undef phi
#undef psi
#undef initial_Q
#undef initial_R
#undef initial_D
#undef intervention
#undef S
#undef V
#undef E
#undef I
#undef Q
#undef R
#undef D
#undef H
#undef cases
#undef lik

/* C snippet: 'toEst' */
#define intervention		(__covars[__covindex[0]])
#define b1		(__p[__parindex[0]])
#define b2		(__p[__parindex[1]])
#define b3		(__p[__parindex[2]])
#define nu		(__p[__parindex[3]])
#define gamma		(__p[__parindex[4]])
#define mu_EI		(__p[__parindex[5]])
#define mu_IQ		(__p[__parindex[6]])
#define kappa		(__p[__parindex[7]])
#define mu_QR		(__p[__parindex[8]])
#define mu_QD		(__p[__parindex[9]])
#define rho		(__p[__parindex[10]])
#define N		(__p[__parindex[11]])
#define chi		(__p[__parindex[12]])
#define initial_V		(__p[__parindex[13]])
#define last_week_cases		(__p[__parindex[14]])
#define phi		(__p[__parindex[15]])
#define psi		(__p[__parindex[16]])
#define initial_Q		(__p[__parindex[17]])
#define initial_R		(__p[__parindex[18]])
#define initial_D		(__p[__parindex[19]])
#define T_b1		(__pt[__parindex[0]])
#define T_b2		(__pt[__parindex[1]])
#define T_b3		(__pt[__parindex[2]])
#define T_nu		(__pt[__parindex[3]])
#define T_gamma		(__pt[__parindex[4]])
#define T_mu_EI		(__pt[__parindex[5]])
#define T_mu_IQ		(__pt[__parindex[6]])
#define T_kappa		(__pt[__parindex[7]])
#define T_mu_QR		(__pt[__parindex[8]])
#define T_mu_QD		(__pt[__parindex[9]])
#define T_rho		(__pt[__parindex[10]])
#define T_N		(__pt[__parindex[11]])
#define T_chi		(__pt[__parindex[12]])
#define T_initial_V		(__pt[__parindex[13]])
#define T_last_week_cases		(__pt[__parindex[14]])
#define T_phi		(__pt[__parindex[15]])
#define T_psi		(__pt[__parindex[16]])
#define T_initial_Q		(__pt[__parindex[17]])
#define T_initial_R		(__pt[__parindex[18]])
#define T_initial_D		(__pt[__parindex[19]])

void __pomp_to_trans (double *__pt, const double *__p, const int *__parindex)
{
 	T_b1 = log(b1);
	T_b2 = log(b2);
	T_b3 = log(b3);
	T_mu_EI = log(mu_EI);
	T_mu_IQ = log(mu_IQ);
	T_mu_QR = log(mu_QR);
	T_mu_QD = log(mu_QD);
	T_nu = logit(nu);
	T_gamma = logit(gamma);
	T_kappa = logit(kappa);
	T_rho = logit(rho);
	T_chi = logit(chi);
	T_phi = logit(phi);
	T_psi = logit(psi); 
}

#undef intervention
#undef b1
#undef b2
#undef b3
#undef nu
#undef gamma
#undef mu_EI
#undef mu_IQ
#undef kappa
#undef mu_QR
#undef mu_QD
#undef rho
#undef N
#undef chi
#undef initial_V
#undef last_week_cases
#undef phi
#undef psi
#undef initial_Q
#undef initial_R
#undef initial_D
#undef T_b1
#undef T_b2
#undef T_b3
#undef T_nu
#undef T_gamma
#undef T_mu_EI
#undef T_mu_IQ
#undef T_kappa
#undef T_mu_QR
#undef T_mu_QD
#undef T_rho
#undef T_N
#undef T_chi
#undef T_initial_V
#undef T_last_week_cases
#undef T_phi
#undef T_psi
#undef T_initial_Q
#undef T_initial_R
#undef T_initial_D

/* C snippet: 'fromEst' */
#define intervention		(__covars[__covindex[0]])
#define b1		(__p[__parindex[0]])
#define b2		(__p[__parindex[1]])
#define b3		(__p[__parindex[2]])
#define nu		(__p[__parindex[3]])
#define gamma		(__p[__parindex[4]])
#define mu_EI		(__p[__parindex[5]])
#define mu_IQ		(__p[__parindex[6]])
#define kappa		(__p[__parindex[7]])
#define mu_QR		(__p[__parindex[8]])
#define mu_QD		(__p[__parindex[9]])
#define rho		(__p[__parindex[10]])
#define N		(__p[__parindex[11]])
#define chi		(__p[__parindex[12]])
#define initial_V		(__p[__parindex[13]])
#define last_week_cases		(__p[__parindex[14]])
#define phi		(__p[__parindex[15]])
#define psi		(__p[__parindex[16]])
#define initial_Q		(__p[__parindex[17]])
#define initial_R		(__p[__parindex[18]])
#define initial_D		(__p[__parindex[19]])
#define T_b1		(__pt[__parindex[0]])
#define T_b2		(__pt[__parindex[1]])
#define T_b3		(__pt[__parindex[2]])
#define T_nu		(__pt[__parindex[3]])
#define T_gamma		(__pt[__parindex[4]])
#define T_mu_EI		(__pt[__parindex[5]])
#define T_mu_IQ		(__pt[__parindex[6]])
#define T_kappa		(__pt[__parindex[7]])
#define T_mu_QR		(__pt[__parindex[8]])
#define T_mu_QD		(__pt[__parindex[9]])
#define T_rho		(__pt[__parindex[10]])
#define T_N		(__pt[__parindex[11]])
#define T_chi		(__pt[__parindex[12]])
#define T_initial_V		(__pt[__parindex[13]])
#define T_last_week_cases		(__pt[__parindex[14]])
#define T_phi		(__pt[__parindex[15]])
#define T_psi		(__pt[__parindex[16]])
#define T_initial_Q		(__pt[__parindex[17]])
#define T_initial_R		(__pt[__parindex[18]])
#define T_initial_D		(__pt[__parindex[19]])

void __pomp_from_trans (double *__p, const double *__pt, const int *__parindex)
{
 	b1 = exp(T_b1);
	b2 = exp(T_b2);
	b3 = exp(T_b3);
	mu_EI = exp(T_mu_EI);
	mu_IQ = exp(T_mu_IQ);
	mu_QR = exp(T_mu_QR);
	mu_QD = exp(T_mu_QD);
	nu = expit(T_nu);
	gamma = expit(T_gamma);
	kappa = expit(T_kappa);
	rho = expit(T_rho);
	chi = expit(T_chi);
	phi = expit(T_phi);
	psi = expit(T_psi); 
}

#undef intervention
#undef b1
#undef b2
#undef b3
#undef nu
#undef gamma
#undef mu_EI
#undef mu_IQ
#undef kappa
#undef mu_QR
#undef mu_QD
#undef rho
#undef N
#undef chi
#undef initial_V
#undef last_week_cases
#undef phi
#undef psi
#undef initial_Q
#undef initial_R
#undef initial_D
#undef T_b1
#undef T_b2
#undef T_b3
#undef T_nu
#undef T_gamma
#undef T_mu_EI
#undef T_mu_IQ
#undef T_kappa
#undef T_mu_QR
#undef T_mu_QD
#undef T_rho
#undef T_N
#undef T_chi
#undef T_initial_V
#undef T_last_week_cases
#undef T_phi
#undef T_psi
#undef T_initial_Q
#undef T_initial_R
#undef T_initial_D

static int __pomp_load_stack = 0;

void __pomp_load_stack_incr (void) {++__pomp_load_stack;}

void __pomp_load_stack_decr (int *val) {*val = --__pomp_load_stack;}

void R_init_model (DllInfo *info)
{
R_RegisterCCallable("model", "__pomp_load_stack_incr", (DL_FUNC) __pomp_load_stack_incr);
R_RegisterCCallable("model", "__pomp_load_stack_decr", (DL_FUNC) __pomp_load_stack_decr);
R_RegisterCCallable("model", "__pomp_rinit", (DL_FUNC) __pomp_rinit);
R_RegisterCCallable("model", "__pomp_stepfn", (DL_FUNC) __pomp_stepfn);
R_RegisterCCallable("model", "__pomp_rmeasure", (DL_FUNC) __pomp_rmeasure);
R_RegisterCCallable("model", "__pomp_dmeasure", (DL_FUNC) __pomp_dmeasure);
R_RegisterCCallable("model", "__pomp_to_trans", (DL_FUNC) __pomp_to_trans);
R_RegisterCCallable("model", "__pomp_from_trans", (DL_FUNC) __pomp_from_trans);
}
