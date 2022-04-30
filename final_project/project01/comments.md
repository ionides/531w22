---
title: "Review comments on Project 1"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

The authors carried out an analysis of a novel dataset. The questions are of general interest.

The project borrows techniques from previous projects, but implements them in an original way on this new dataset.

**Suggestions**:

1. Fig 1. "Blue line" in caption should read red line.

2. The return, $R_n=\log(y_n)-\log(y_{n-1})$ , is modeled by $Y_n$. It would be easier to read if notation is set up so that $Y_n$ was a model for data $y_n$. 

3. ARIMA models with different levels of integration ($D\neq 0$) do not have directly comparable likelihoods.

4. A key feature that the ARIMA models can explain here, which the GARCH and stochastic volatility cannot, is the strong weekly periodicity. People play more video games on weekends. You would have to put that into the volatility models to see if they can add value to ARMA. Or you could compare with 7-day differences. Or model weekly totals.

5. There is no particular rationale given for why a stochastic leverage model might be suitable for game play. Why would volatility be associated with increases or decreases in game play? It seemed more like an exercise in running code developed for a different situation.

6. A model (and/or exploratory analysis) explicitly linking the game growth to COVID incidence would have been nice. Since the introduction discusses an interaction between COVID levels, one may expect the work to move toward a model including such an interaction.

7. Readers might like to be told more details about the data on Steam platform.

8. The decomposition into trend + noise + cycles is unsuccessful here, for the "noise" is weekly periodicity. Frequencies for the bandpass filters should be relevant to the data being analyzed. The goal and purpose of the decomposition is not clear and not explained.

9. The choice $p=5$, $q=5$ in GARCH(p,q) is not explained.

10. The pairs plot for "Fitting the stochastic leverage model”"section seems a bit sparse, perhaps the team can try `logLik>max(logLik)-40` rather than `logLik>max(logLik)-20`

11. The conclusion on the divergence of $\mu_h$ and $\sigma_\eta$ is wrong. Maybe the authors focused on th broadness of the MIF2 convergence plot on the right end of filtering. However, the curves plotted include search traces of all starting points, including those not converging to global maxima. The convergence of these two parameters can be confirmed from the box plot. Both parameters converge well to a line ($\mu_h$ to around -7, and $\sigma_\eta$ to around 0) and the outliers require little attention since they don’t correspond to global maximum.

12. In Fig 1, there is a grey interval described as a "95% confidence interval" but what that means in the current context is unclear. Is there a sensible model for which it is a reasonable estimator in this context?




