---
title: "Review comments on Project 24"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: A fairly clearly written analysis investigating the relevance to a commercial application of time series methods developed in class.

**Points for consideration**:

1. "The ACF plot show the seasonally differenced data is non-stationary" is incorrect.

2. Simplicity is not a reason to choose ARMA(1,1) over ARMA(0,2), since both have the same number of parameters

3. The assertion that roots very close to the unit circle "is not unacceptable" may be unwise. You are fitting a big model.

4. Fitted value plots like this can be misleading - it assesses one-step prediction which is quite an easy task for this system.

5. The many MA roots on the boundary could be associated with numerical instability, and some roots seem close to canceling.

6. It might be clearer to plot the roots of the seasonal and local polynomials separately.

7. The explanation "AR roots are mostly inside the unit circle" is wrong. You have plotted the inverse roots. The roots are outside.

8. Inconsistent values in the AIC table (not mathematically possible under accurate likelihood maximization and evaluation) should be noted and discussed.

9. References should be cited in the text at relevant points.

10. It is not sufficient just to cite a whole directory of projects as sources. You should clarify which one (or ones) were used, and where.

11. The first sentence is copied verbatim from reference 1. However, that source is not referenced at this point. 

12. The research question is posed as just looking for patterns and building a model. It can be helpful to focus on a more specific goal, though providing an industrial forecast might count here.

13. Figures lack captions, which makes it harder to follow what is going on.




