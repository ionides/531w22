---
title: "Review comments on Project 12"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

A nicely presented analysis updating COVID modeling to account for recent data.

**Suggestions**:

1. For the mechanistic model, one either has to analyze cases summed over weeks or to explicitly model the weekly periodicity.

2. Compare the mechanistic fit likelihoods to the ARMA benchmark.

3. For the ADF test, it is best not to present unprocessed R output. Better still, one could avoid the test entirely. ADF is only a test against a unit root hypothesis. Simply plotting the data would be better to detect a wider range of phenomena that might suggest a nonstationary model.

4. In the ARIMA model for the full data, the formula of the ARIMA is wrong. It should be $\phi(B)(\nabla^d Y_n - \mu)= \psi(B)\epsilon_n$.

5. Fig 14 shows clearly how the initial values are inappropriately specified for the model. Also, how the model fails to capture the week day effect in the data. The model has to compensate for these shortcomings by having a large amount of noise in order to do its best to fit the data.

6. The fixed choiced $E_0=30000$ and $I_0=15000$ are not discussed - one must go to the code to find them. However, these unsuccessful choices critically affect all the other model-based analysis. Better to estimate them from data.

7. The model has measurement overdispersion, but no process noise (see Chapter 17).




