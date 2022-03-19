---
title: "Review comments on Project 6"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: An exciting modern topic, with a careful data analysis. A fairly comprehensive and well-presented investigation.

**Points for consideration**:

1. The ARMA(4,2) log likelihood reported of -1750.33 doesn't fit in with other numbers in the likelihood ratio test. Is it a typo?

2. The lower log likelihood reported for SARIMA is mathematically impossible, due to nesting.

3. The causal direction assumed by "increasing searching trend for NFT does facilitate sales" is not directly evidenced by the data.

4. The report incorrectly states that the AR roots of ARIMA(2,1,2) are within the unit circle. One reported MA root is within the unit circle, but this must be an error since `arima()` will always estimate roots with magnitued at least 1.

5. Typo: the regression with ARMA errors model is missing a term

6. Inconsistent values in the AIC table (not mathematically possible under accurate likelihood maximization and evaluation) should be noted and discussed.

7. References should be cited where relevant in the text. Also, the reference format is not sufficiently formal for a midterm project.

8. It would be better if the Rmd source did not hard-code data analysis numbers in the report. When the numbers are hard-coded, you cannot see where they came from so you cannot debug the issue above.

9. The data are not included in the submission.




