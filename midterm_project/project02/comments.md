---
title: "Review comments on Project 2"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: An interesting motivation and a nice idea to test the model in terms of evaluating trading strategies. A fairly comprehensive and well-presented investigation.

**Points for consideration**:

1. "Seasonality" should only usually be used to describe an inherent periodicity of the system (usually years, weeks, days,...). 

2. Inconsistent AIC values (not mathematically possible under accurate likelihood maximization and evaluation) should be noted.

3. ACF plot does not check for homoskedastic residuals - it looks at sample autocorrelation. Residuals can be uncorrelated while being homoskedastic or heterskedasic

4. The motivation for the decomposition into trend + noise + cycles is not clear. Why is this helpful for the current data analysis?

5. Periodograms estimate a spectral density which only exists for a stationary model. Spectral analysis of the returns (difference of log price) would make more sense.

6. Why is an estimated period of 2817 (units? days) "consistent with the ACF plot".

7. When R throws errors and warnings, it is good to investigate further.

8. Additional attention to figure captions, with numbering, would be helpful to readers. 








