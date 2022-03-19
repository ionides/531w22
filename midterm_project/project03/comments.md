---
title: "Review comments on Project 3"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: The authors put ARIMA modeling in the context of economic theory, and demonstrate a range of time series techniques to study the price of gold. A fairly comprehensive and well-presented investigation.

**Points for consideration**:

1. Sec 2.2. What is the sample ACF estimating here? For a stationary model, it estimates the theoretical ACF, but a stationary model does not seem appropriate from the time plot.

2. Sec 2.3. Some numbers are shown but not explained. One should not conclude that there is a characteristic frequency unless it is evident through the noise - here, you could conclude that the estimated spectrum looks flat.

3. 0.0002953435 is not "basically zero". It is 0.0002953435 * 365 = 0.108 per year, corresponding to a 10% per year increase which is a reasonable rate of return.

4. Sec 3. "Similar in magnitude" is not enough for cancellation of roots - they should be similar as complex values (which they are).

5. Your model implies gold is statistically predictable - could you make a fortune out of that?

6. The Fisher CI presented may be good here. In other situations in class, a profile or bootstrap were more accurate. Why do you just present Fisher here?

7. For a formal report, references should be properly formatted, not just links.

8. The claim that the behavior of the time series is changed by COVID is a testable hypothesis. For example, one could do a likelihood ratio test (or normal approximation for parameter estimates) to assess the evidence for this assertion.






