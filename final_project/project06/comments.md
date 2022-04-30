---
title: "Review comments on Project 6"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

 A novel data analysis developed using an SEIR model for historical rubella data.

Files were hosted online and pulled when ran. This allows for the report to be recreated by anyone one the internet and every section’s code can be run individually.

**Suggestions**:

1. The analysis is quite similar to the referenced source, https://ionides.github.io/531w21/final_project/project14/blinded.html#. The data are different, but the model and analysis follow a similar trajectory. It would have been better to discuss explicitly the relationship to that previous work.

2. Signs in the "conservation of mass" flow equations are wrong. For example, we should have $S(t)=S(t_0)- N_{SE}(t)$.

3. The report does not describe the measurement model. From the code, one can see that the `dnbinom` specification is incorrect, since it uses a parameterization corresponding to a binomial distribution. Chapter 12 offers
```
sir_dmeas <- Csnippet("
lik = dnbinom_mu(reports,k,rho*H,give_log);
")
```
See also https://cran.r-project.org/doc/manuals/r-release/R-exts.html#Distribution-functions

4. The process model does not include overdispersion (as described in Chapter 17) which might cause problems matching the variability in the data.

5. A benchmark (perhaps log-ARMA) would help to establish the goodness of fit of the model, or identify misspecification issues.

6. Where possible, numbers should not be hard-coded in the Rmd document. Rather, they should be referenced using
```
`r my_variable`
```

7. In the code, the authors set $E(0) = 14$ and $I(0) = 7$ but did not explain this setting in the report. This may be done to match by eye, but it should be explained and the decision could have consequences for the conclusions. 



