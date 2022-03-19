---
title: "Review comments on Project 7"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: Many techniques from the class are tried out in a clearly presented analysis.

**Points for consideration**:

1. The sample ACF is hard to interpret when the data are not well modeled by a stationary process. Maybe subtract off an estimated trend first?

2. Sec 3. Improperly described and conducted hypothesis test - the choice of 0.1 as a significance level is unusual, and if you reject the null then you reject ARIMA(0,1,1) rather than supporting it. 

3. Plotting data against fitted values can be a weak test of model specification. Even plots that look like a close fit may not actually support that. For example, just predicting time n by the value at time $n-1$ will often look like a good fit when plotted in thie way---your model should do better than a simple and obvious forecast if you want to show it is doing a good job.

4. What role does `auto.arima()` play in your logical reasoning? You don't say what it does, or how its output should be compared to your other lines of reasoning. 

5. Inconsistent values in the AIC table (not mathematically possible under accurate likelihood maximization and evaluation) should be noted and discussed.

6. References should be cited where used in the text, to make clear which parts correspond to which reference.

7. A linear trend is fitted, but maybe a nonlinear trend would be appropriate?

8. Having gone to the trouble of identifing a trend model, why do differencing rather than detrending?

9. Error: "the absolute value of root is less than 1 and within the circle, so the ARIMA(0,1,1) is invertable". You have plotted the inverse root, which is within the circle, so the root itself is outside, which is needed for invertibility.

10. Some unprocessed R output is presented in the report.

11. Saying "Autocorrelation by year" makes it seem that the unit of time is year, when it is months in your sample ACF plot.

12. The lowest AIC is ARMA(2,1). This is incorrectly reported as ARMA(1,2) and the analysis continues to investigate ARMA(1,2) instead.

13. Inconsistent use of $\Delta$ and $\triangledown$ to denote difference.






