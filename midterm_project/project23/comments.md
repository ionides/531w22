---
title: "Review comments on Project 23"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:  The overall conclusion is that gas prices behave similar to a random walk, but the analysis is carried out carefully and nicely presented.


**Points for consideration**:

1. Fig 2. Once you have argued that the data should be modeled with a trend, what do you learn from plotting a sample ACF? What is it estimating?

2. Inconsistent values in the AIC table (not mathematically possible under accurate likelihood maximization and evaluation) should be noted and discussed.

3. Throughout the analysis, the usage of "normal data" seems to refers to the original untransformed data. This can be confusing since "normal" has an very specific and already widely adopted meaning in the statistical context.

4. The authors point out correctly that it would be interesting to study the relationship between gasoline price and other variables, but a start on doing this could be within the scope of a midterm project. 

5. A spell checker could have been used to remove some distracting typos.

6. The assertion "ARMA(1,1) has smallest AIC among small models" is unclear. ARMA(3,0) and ARMA(1,2) have much lower AIC.

7. The ARMA(1,1) has an AR root on the unit circle. Since arima() will always estimate a causal, invertible model, the worst case is when the root is on the unit circle, which is the case here. 

8. It would be useful to add a normal quantile plot to assess normality of residuals.





