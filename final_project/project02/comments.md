---
title: "Review comments on Project 2"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

The authors developed their own extension of an SIR POMP model and carried out some initial analysis. The model is suitable to address questions of interest about the epidemiology of ebola. 

**Suggestions**:

1. The profile for $\beta$ is flat over this interval. You have not justified a confidence interval of around 3-7.

2. Evidence of a strong nonlinear relationship between $\beta$ and $\eta$.

3. The conclusion "the confidence intervals of the two transmission rates are sill the same" is wrong. The obtained intervals are determined only by the interval over which the profile has been calculated. It would be more correct to say that in both cases beta is unidentifiable over this interval.

4. The weak identifiability might suggest exploring the possibility of fixing one ore more parameter at scientifically plausible values.

5. References at the end are not all cited when relevant during the main text. This makes it harder to see what is attributable to each reference.

6. At least some members in the group were aware of https://kingaa.github.io/sbied/ebola/ and the project would have been stronger had this connection been made explicit.

7. Figure captions, figure numbers and section numbers would make it easier for referees.

8. It would be good to have a benchmark likelihood, e.g. from log ARMA. The project references a previous project https://ionides.github.io/531w21/final_project/project15/blinded.html which does carry out a benchmark analysis, and one could follow their approach.



