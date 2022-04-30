---
title: "Review comments on Project 9"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

A careful time series analysis of the omicron wave here in Michigan.

**Suggestions**:

1. Further diagnostic analysis could investigate which data points are problematic for the mechanistic model to explain (e.g., using effective sample size) which might lead to insights on ways to get improved understanding in future.

2. A bug has led to a collection of idential points reported for the global search.

3. The conclusion $b_2>b_1$ may not be statistically significiant. One could make a suitable profile likelihood, or equivalently a likelihood ratio test.

4. The initial values for the state variables $E_0 = 30$, $I_0 = 30$ may be questionable. As an alternative, the initial states for $E$ and $I$ could be parameterized similarly to $S$, as in lecture notes Ch 17.

5. The local search shows issues. The log likelihood diverges with iterations. Possibly, the authors could plot particle filters diagnostic and look at ESS, which might give clues what is going wrong. Problematic model assumptions could be state initializations and/or process overdispersion. It is also possible that reducing the random walk size would change the local search trends.

6. The report does not specify the measurement model.

7. The report closely follows https://ionides.github.io/531w21/final_project/project15/blinded.html. This project is cited, so it is not a major problem. The updated data leads to new considerations. However, when so much of the groundwork is already prepared, one may hope the project will go further. If anything, less is done here, since the previous project also calculated a profile. Also, the conclusions are less carefully drawn and the model is less fully described - it is identical when it appears in both, but this article omits to describe the measurement model. If the authors had explained better the close relationship to this previous project, they might have realized that they should make their own contribution larger.

8. The style of references is informal. 



