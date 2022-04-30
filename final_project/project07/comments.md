---
title: "Review comments on Project 7"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

An engagingly written model-based comparison of two stocks, comparing new and established car companies.

**Suggestions**:

1. Model is missing a normal error in the term $Y_n = \exp\{H_n/2\} \epsilon_n$.

2. Based on the GARCH analysis, one might try $\epsilon_n$ having a $t$ distribution rather than normal. The effective sample size plot also suggests that - there are some jumps that are large outliers under a normal model.

3. A simpler stochastic volatility model might be worth trying before advancing to stochastic volatility with leverage. See Section 4 of https://ionides.github.io/531w22/final_project/project14/Blinded.html for an example.

4. Conclusion: "improvements of log likelihood were not significant" moving from normal to t GARCH seems wrong - make a likelihood ratio test.

5. Conclusion: "The POMP models perform much better than the GARCH for both Ford and Tesla" does not seem to be supported by the likelihoods. But, it looks like the Tesla POMP model was fitted to a reduced length time series (for practical reasons of finishing the analysis) which is not described in the report.

6. An AIC table for ARMA(p,q) is mentioned but not shown.

7. "Other models with competitive AIC values are not invertible or causal, with polynomial roots inside of the unit circle" seems implausible, since `arima()` will never fit roots inside the unit circle, though they may be on the boundary or close to it.

8. Plotting simulations from the mechanistic models would allow us to visually assess the fitted models.compare the performance of the local to the global search.

9. Typo: "(why we want to use log return instead of return?)" should be deleted. Also, in technical contexts, we usually say "return" to refer to the so-called log return.





