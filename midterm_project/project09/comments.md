---
title: "Review comments on Project 9"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: Many techniques from the class are tried out in a motivated data analysis.

**Points for consideration**:

1. Sec 3.1. the "strong tendency to fluctuate in the same pattern" is not so clear, especially in the first half of the time series.

2. Sec 4.1 The likelihood ratio tests both have errors. The first has the wrong sign - if you print the test statistic you have evaluated it would be negative. The second one presented is not nested.

3. Sec 4.2. "residuals change mainly around 0" is not a strong endorsement of the model - it happens due to the definition of residuals. Here, the residuals show fairly serious heteroskedasticity.

4. Sec 4.3 residuals are long-tailed, a fairly substantial violation of normality. It is not appropriate to say this indicates the normality assumption is mostly being met.

5. Sec 5.1 you find a negative relationship (the estimated coefficient of gold_cycles) though insignificant. This does not support your claim. The sign and significance of this coefficient (not discussed) is more relevant to your goals than the significance of the ARMA coefficients.

6. Sec 5.1. Some of the roots are very close to the unit circle. Is this a problem? It should be discussed.

7. Sec 6. It is unclear where the model in this section comes from.

8. It would be better if the Rmd source did not hard-code data analysis numbers in the fitted model. I'm not sure if all projects were assessed on this, but a referee pointed it out and it is a fair point.

9. References are listed at the end but not cited in the text. This becomes more problematic given point 11 below.

10. It would be interesting to see the outcome of flipping the independent and dependent variables, as there is no reason to suggest that the two entities are not co-dependent.

11. The report follows closely a previous project (https://ionides.github.io/531w22/midterm_project/project09/blinded.html). This project is in the reference list, but the amount borrowed is not clearly acknowledged. The report should clarify how it builds on the previous project and what new things have been learned.




