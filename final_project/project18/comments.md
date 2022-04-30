---
title: "Review comments on Project 18"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

An innovative investigation, exploring the use of financial models for oil price.

**Suggestions**:

1. Annual data for only 40 years is somewhat limited for fitting models. Would it be possible to get higher-frequency data? Or, once log-transformed, it might be meaningful to fit a longer time series to get a longer historical perspective.

2. The rationale for using ARMA(0,1) rather than ARMA(0,0) is weak. It seems like there is essentially no likelihood improvement for adding the one extra parameter. Likely, the estimated MA(1) coefficient is very close to zero.

3. This is too little data to fit a fairly complex model like stochastic volatility with leverage. Maybe start with a simpler POMP model, or test whether a model with no leverage is sufficient.

4. Figure captions and numbers would be appreciated by referees.

5. Where possible, numbers should not be hard-coded in the Rmd document. Rather, they should be referenced using
```
`r my_variable`
```



