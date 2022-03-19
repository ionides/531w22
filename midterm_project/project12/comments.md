---
title: "Review comments on Project 12"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: Understanding climate change is a topic that affects all of us and involves time series. This is an extensive analysis of two temperature time series.

**Points for consideration**:

1. Using frequency domain analysis to discover seasonality in temperature is anticlimactic. However, the frequency analysis of the yearly average data is quite interesting.

2. OLS confidence interval for trend is inappropriate if there is evidence for autocorrelation. Usually, a report should avoid reporting a p-values that you know to be inappropriate.

3. If you do OLS at all for correlated time series data, it should be a step toward regression with ARMA errors or something similar.

4. The trend here may be nonlinear, but only a linear trend is considered.

5. The choice of ARMA(3,2) is not justified.

6. The report contains too much unformatted R output. 

7. The 3.7 year spectral peak could be El Nino. The 10-11 year peak matches the sunspots in HW 4.

8. The time series stops at 2013, which is a bit dated. Newer data would aid the analysis and increase its relevance.




