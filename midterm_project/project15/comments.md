---
title: "Review comments on Project 15"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: A well-motivated analysis reaching a meaningful conclusion. The report looks clean, tidy and professional.


**Points for consideration**:

1. The normal quantile plot shows considerable long-tailed deviation from normality. This should be noted, with discussion or investigation of possible consequences.

2. Inconsistent values in the AIC table (not mathematically possible under accurate likelihood maximization and evaluation) should be noted and discussed.

3. Don't present p-values you don't believe, such as the least squares trend p-value. In some special cases, you can present such a p-value if it is needed for the data analysis conclusion.

4. The regression with SARMA errors looks appropriate, and it may be interesting to try the cubic trend as written, but the SARMA results presented do not have a trend (e.g., no xreg component in Table 6). 

5. The coding is not done cleanly. The data are read in many times. In one case, this has a consequence that you accidentally analyze data from the Baltic rather than the Bering Sea (notice that Baltic Sea is in col. 15 and Bering Sea is in col.14).

6. It is interesting to try to predict an ice-free date, but this is a distant extrapolation so you should be cautious about your conclusions.

7. Typo: in the likelihood ratio test, $\beta_0$ should read $\beta_1$.





