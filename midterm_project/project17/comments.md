---
title: "Review comments on Project 17"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: A well-motivated project trying a range of techniques. The conclusions noted previous projects addressing similar questions with different data, and discussed what new things were learned from their analysis.

**Points for consideration**:

1. "data after first difference show more stationary than before" does not formally have meaning - a model is stationary or not, but we have no definition for "more stationary".

2. The peaks in the estimated spectrum are reported wrongly. For example, 0.044 is reported as 4.044. In fact, the spectral analysis is consistent with the wavelets.

3. The conclusion "This leads us to conclude that there is no meaningful seasonality in our Detroit PM2.5 data" is incorrect. You find seasonal frequencies in the spectrum and wavelet analysis. ARIMA(2,1,3) can model seasonal fluctuations.

4. Typo: $\mu=E[Y_n]$ not $\mu=E[X_n]$.

5. Inconsistent values in the AIC table (not mathematically possible under accurate likelihood maximization and evaluation) should be noted and discussed. The discrepancy is large for the SARIMA table.

6. Looking at the SARIMA roots might help to understand numerical instability.

7. The degrees of freedom for the likelihood ratio test is incorrectly take to be 3 rather than 2. 





