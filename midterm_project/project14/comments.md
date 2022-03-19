---
title: "Review comments on Project 14"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: Natural gas emissions of CO$_2$ are a current climate concern, and amenable to time series analysis. The report introduces the analysis clearly. 


**Points for consideration**:

1. ADF is a reasonable way to test for a unit root model (that is what it does) but not as evidence for or against other types of non-stationarity.

2. The differenced analysis is an example of this: ADF does not know or care that the the residuals are heteroskedastic (therefore, not well modeled as stationary).

3. Typo? "The value of the t-statistic is greater than the critical value of t at any of the significant levels" is written without any explanation of what t-statistics is being considered or what its value is. 

4. The decomposition plot includes seasonality in the noise, perhaps due to heteroskedasticity. This should be noticed and/or fixed.

5. Using a black box method like 'auto.arima()' is not better than exploring different models, their residuals, and their numerical issues. It chooses a model for you, but how?

6. Too much unprocessed R output is displayed. Better to show specific numbers and make sure they are explained and discussed.

7. Additional attention to figure titles, labels and captions would improve readability (some are better than others)

8. If you use a test (e.g., Ljung-Box) you should describe it and say what it tests. Here, you conclude  it shows "the residual sequence is white noise" which missess patterns such as heteroskedasticity evident from a time plot.

9. A major conclusion is "the increasing trend is statistically significant" but that is not tested. The final model does not include an explicit trend.

10. What does it mean when you say in the conclusions "the prediction result of the model in 2020 is less different from the actual data". Less different than what?

11. The normal quantile plot shows somewhat heavy tails (relative to normal) and one outlier. This should be noted, and its possible consquences discusses and/or investigated. 

12. Prediction just based on past gas emissions may not be so useful as estimating how gas emissions co-vary with coal emissions and/or amount of non-carbon power generation.

13. References are not all cited where used in the text. In particular, two lists of past midterm projects are cited, but it is not explained which particular projects were studied, and what was learned from them.




