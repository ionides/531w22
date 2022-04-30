---
title: "Review comments on Project 19"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

A well-presented analysis on a topic of general interest.

**Suggestions**:

1. If you want to difference the data, 7-day differencing would remove the weekly periodicity. One could sum up cases over each week as another way to avoid dealign with day-of-week effects. This is simpler than the idea proposed in the conclusion of explicitly modeling day of week as a covariate.

2. Shapiro-Wilk test does not add much to the QQ plot here. The QQ plot tells you the nature of the non-normality (long tails both ends) which Shapiro-Wilk does not.

3. You reject the null hypothesis that the postulated model is reasonable, and then say "therefore, the model can be represented by ..." which is not a clear conclusion.

4. It could be worth estimating $E(t_0)$ and/or $I(t_0)$ rather than fixing them. The model seems to struggle at the start of the wave.




