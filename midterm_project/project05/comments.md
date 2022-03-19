---
title: "Review comments on Project 5"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: A fairly comprehensive and well-presented investigation, using methods from the class and some methods not covered.

**Points for consideration**:

1. The ADF alternative, $H_1$: "The time series does not have a unit root, meaning it is stationary" is incorrect. What if the data are appropriately modeled by a non-stationary process that does not have a unit root? In the statement of the ADF null hypothesis, $H_0$ "the time series has a unit root" is not quite right. Unit roots are a property of models, but the time series is the data.

2. The ADF analysis claims to show that a 2nd difference, $D=2$, is appropriate. Then the analysis proceeds to use $D=1$, without explaining the inconsistency.

3. Be careful about interpretation of statistical tests. If you fail to reject the null using a test, it does not mean that the null is true. It simply means that this particular test did not reveal the null to be false, which gives some justification for continuing to work under the assumption that the null is true.

4. Diagnostics: When looking at a fitted value plot, one should ask whether a simpler model (e.g., predict tomorrow using today) does any worse. Here, it would look about the same.

5. Inconsistent AIC values (not mathematically possible under accurate likelihood maximization and evaluation) should be noted.

6. Residuals have extremely long tails, in particular there is one large outlier. This shows that other tests based on normality are unreliable. Non-normality is noted, but its consequences are not discussed or investigated. 

7. Fig 10 shows there is a root essentially on the unit. To gain value from plotting the diagnostics, you have to interpret them and respond accordingly. 

8. The Box-Ljung test here is mostly wasted space. We can see from Fig 9 that the sample ACF is close to zero. Similarly, Shapiro-Wilk is uninformative since Fig 8 already shows massive deviation from normality. Better to focus on consequences of non-normality and a root close to the unit circle.

9. In what sense does `auto.arima` find an "optimal model"? Why is it better to use a pre-packaged algorithm that you do not explain, rather than explaining carefully how various lines of evidence lead you to a model? It is surprising here that an auto-arima analysis is discussed in the conclusion but not anywhere in the methods or results section. 

10. Many results are shown for fitting ARMA(p,q) models despite the arguments presented for differencing. Since `arima()` fits a stationary ARIMA(p,d,q) model when $d=0$, the time series should be detrended before fitting such a model. There is no point fitting a model that you have already explained is bad, and then repeating the exercise with ARIMA(p,1,q). Better to spend time and space on other things. 

11. Fitted value plots can give too much confidence in the model. Compare with plotting a simple prediction that the exchange rate tomorrow will be the same as today - if that looks just as good then what have you discovered?





