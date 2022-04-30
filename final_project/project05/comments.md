---
title: "Review comments on Project 5"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

 A novel twist on previous COVID investigations.

**Suggestions**:

1. Weekly periodicity cannot be described by GARCH.

2. Heteroskedasticity does not explain dependence. They are different things: heteroskedasticity is about variances, and dependence may be explained by covariances.

3. An ARMA-GARCH model is attempted to show how extended approaches to address heteroscedasticity are not sufficient to overcome the problem. This is an interesting idea, though it will not address the periodicity. It would be good to write out the model for an ARMA-GARCH model, so that readers do not have to track down the given reference.

4. Very few replications are carried out for the Monte Carlo inference. This may be due to time constraints, but such limitations need to be mentioned.

5. Avoid raw, unprocessed R outpt.

6. Why is the pairs plot so sparse? Is it because a likelihood cutoff was used which led to only one point being included? A referee noticed that, in the plots of local search, the reader can find that log likelihood doesn’t converge in the process of iteration. By looking into the code, we find that the iterating filter was done for 20 times, but only 8 of them are shown on the plot, which means the other 12 of them got problematic results. The common case is that the functions of `rmeasure` and `dmeasure` aren’t set properly so they return `NA` values, or the model design needs to be improved. In practice, some bad initial values of parameters can also cause this problem. The authors can try to solve this problem by tuning the parameters, debugging the measurement functions or redesigning the model.


7. It would be interesting to see a likelihood comparison between the different models.




