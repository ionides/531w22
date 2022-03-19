---
title: "Review comments on Project 13"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: Many techniques from the class are tried out in a clearly presented and well written analysis. 


**Points for consideration**:

1. The estimated sign of $\beta$ is worth discussion.

2. Be careful about causal interpretations - the lag relationship could reflect seasonality of supply.

3. 1-step predicted values plot can be confusing. Perhaps a basic model that predicts using the current value would do almost as well.

4. $\beta$ should be $\beta_1$ in the hypothesis test.

5. The multi-line plot for price is helpful, but not a substitute for a time plot.

6. Typo: The formula for cross-covariance is mis-explained as cross-correlation

7. For the coherency plot,  it would be easier to read if frequency units are specified and/or changed to match the units of time (inverse).

8. Fitted value plots like this can be misleading - it assesses one-step prediction which is quite an easy task for this system.

9. Normal quantile plot shows distinctly long tails. I agree this is probably not enough to be a problem for the analysis, but how could you show this?

10. Inconsistent values in the AIC table (not mathematically possible under accurate likelihood maximization and evaluation) should be noted and discussed.

11. It would be better if the Rmd source did not hard-code data analysis numbers in the report. 




