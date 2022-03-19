---
title: "Review comments on Project 20"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: A range of methods is used, and the data analysis is well motivated.


**Points for consideration**:

1. AIC is not comparable across different levels of differencing. Likelihoods are comparable across different models for the same data, but differencing leads to a modified dataset.

2. Inconsistent values in the AIC table (not mathematically possible under accurate likelihood maximization and evaluation) should be noted and discussed.

3. The assertion that the collapse of the Soviet Union was so important to US demography is not supported by references. In general, the introduction is short of references to support the background. 

4. "The result in Box-Ljung test does not the reject the null hypothesis, demonstrating the residuals are independently distributed as well." This test is basically the same as looking at the sample ACF, carrying out a test that adjusts for multiple comparisons. It cannot demonstrate independence, but it can be consistent with independence.

5. In Sec 3.2, confidence intervals are reported which we know to be unreliable, especially in situations (such as here) where there is a fairly large ARMA model (See Chapter 5 of the notes). Profile or bootstrap methods would identify this.

6. Sec 2.4. The periodogram is described as "smoothed" but is titled as a "raw periodogram".

7. Some figure headings and labels have not been thoughtfully edited. Captions and numbers for figures and tables can be helpful.

8. Sec 3.1. In the SARIMA equation, $(Y_n-\mu)$ should be $Y_n-\mu$, without parentheses, since the modeling assumption is that the differenced data are modeled as ARMA with mean $\mu$.




