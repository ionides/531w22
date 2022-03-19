---
title: "Review comments on Project 4"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: An exciting modern topic, with a careful data analysis. A fairly comprehensive and well-presented investigation. It is a good solution to the outlier to study the before and after time intervals.

**Points for consideration**:

1. Usually, a data analysis writes out the model (here, an ARMA model) to make explicit what is being done. This report writes the model only in the backshift polynomial form, which is compact but harder to understand.

2. The conclusions don't address the question of what is learned from comparing the two time intervals.

3. The introduction is short, and could spend extra time explaining the concepts briefly for a general statistical audience (in addition to the extensive references that are provided for those who want to follow them). In particular, the conclusions about the efficient market hypothesis suggest that the report should say what this is. For this audience, you should appreciate that not all readers will know this; you should not expect them to follow references; you should give a 1 sentence explanation with a reference link for those who want more.

4. The figure comparing two detrending methods does not say which is which.

5. Sec 2.3.2. The null and alternative hypotheses are not well worded. For example, the null hypothesis is not the property that the two different models are "the same".

6. Please inspect to see if the residuals are close to normally distributed, e.g. a normal quantile plot.





