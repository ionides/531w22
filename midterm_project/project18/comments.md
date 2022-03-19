---
title: "Review comments on Project 18"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: A comprehensive time series analysis, using methods studied in class to address a topic of current interest.

**Points for consideration**:

1. You fit a satisfactory estimate of a trend and then give up trend estimation in favor of differencing.

2. The null hypothesis for ADF is a unit root model, which is one particular case of being non-stationary.

3. "data becomes more stationary" does not formally have meaning. A model is stationary or not, but we have no definition for "more stationary".

4. Likelihood ratio test statistics are wrong and/or wrongly interpreted. A negative difference is impossible for the nested models. The degrees of freedom for ARMA(3,2) vs ARMS(3,4) is 2. 

5. Table 2 presents a number called AIC which does not match the definition elsewhere. Also, AIC values cannot be compared across different levels of differencing.

6. No need to show all the convergence iteration information.

7. Roots: "This are within the unit circle" is incorrect.

8. Conclusions are limited - trend and seasonality of CO2 are immediately clear from the plot.

9. The code has `xreg=xreg` for a fitted ARMA model, but the model is written with a constant mean. It is unclear what is going on.

10. Figure 4 shows yearly data but labeled as weeks

11. Figure 6 shows a "decomposition" which includes seasonality as "noise"

12. Re-label axes instead of leaving as `CO2new$MonthAvg`, etc. 

13. SARIMA(3, 1, 3, 0, 0, 1) in the report should be written as SARIMA(3, 1, 3)$\times$(0, 0, 1) to avoid confusion and the period should be added as a subscript.




