---
title: "Review comments on Project 10"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

A well motivated investigation, integrating scientific understanding with time series analysis.

**Suggestions**:

1. Analyzing weekly total might be superior to a weekly moving average. The latter induces dependence between observations.

2. The authors did a good job of getting the SEAPIRD model to work. Perhaps SIR could have done much better if initial conditions (especially, I) were estimated rather than fixed. There is a big mismatch with the data for the first 20 timepoints.

3. The paper used a Negative Binomial measurement model for the SIR model and a normal approximation to the Binomial for the SEAPIRD model. This difference, and its potential consequences, should be discussed.

4. Figure captions and numbers would be appreciated by the readers.

5. The omicron SIR model is fitted with $N=5\times 10^5$ whereas in the text and elsewhere the authors report $N=5\times 10^7$. This is a major problem, only detectable via careful reading by someone with access to the code. It could be avoided by not hard-coding numbers in the report.

6. The introduction could have been documented with more supporting references

7. The authors apparently did not use caching (e.g., bake and stew) for their results. This may have made it harder to develop the code. It also makes it harder for those who re-run the code during review. 

8. The SEAPIRD model comes from https://ionides.github.io/531w21/final_project/project13/blinded.html. The authors do not give credit to this (which is their reference [5]) and instead acknowledge incorrectly [6]. Hopefully this is a typo. However, the relationship to [5] could have been better explained beyond this favorable interpretation.



