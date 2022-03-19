---
title: "Review comments on Project 19"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: A well-presented analysis investigating the relevance to a commercial application of time series methods developed in class.

**Points for consideration**:

1. The introduction is brief. It does not explain the data, or put the data analysis question into a context.

2. Explain the assertion: "The store 39 is also the best one regarding the completeness of showing the behaviors and characteristics for the transactions in stores."

3. You propose a large fitted ARMA model. Is its size justified?

4. QQ-plot shows residuals are substantially non-Gaussian; the report incorrectly concluded this supports a normal assumption.

5. Inconsistent values in the AIC table (not mathematically possible under accurate likelihood maximization and evaluation) should be noted and discussed.

6. Typo: hyperlink for reference [1] did not work.

7. The likelihood ratio test has two problems: (1) the degrees of freedom difference is not calculated correctly, but more importantly (2) likelihoods at different levels of differencing are not comparable - we can only properly use likelihood to compare different models for the same data.




