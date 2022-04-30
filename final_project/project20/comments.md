---
title: "Review comments on Project 20"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

An innovative analysis of flu in the time of COVID-19, using social disruption caused by COVID as an experiment to study flu.

**Suggestions**:

1. For exploratory data analysis and/or ARMA and/or wavelets, it might be worth looking at the logarithm of the data since population dynamics are usually closer to linear on a log scale.

2. For whatever reason, the noise on your maximization is quite large (many log units) so the crude cutoff of 1.92 log units on the profile is primarily noise. One could use a smoothed estimate of the likelihood to improve this somewhat.

3. The use of Box-Cox transformations for ARMA models is not explained, and exactly what was done is unclear. Are ARMA likelihoods properly adjusted for a transformation?

4. What is the purpose of fitting the SARMA model to a different time interval from the mechanistic data - in that case, it no longer provides a benchmark likelihood.





