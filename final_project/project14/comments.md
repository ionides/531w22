---
title: "Review comments on Project 14"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

This project makes a nice advance over previous STATS/DATASCI 531 finance final projects. The Heston stochastic volatility model is coded in a direct way, which is considerably simpler than the approach used for previous projects. Previous versions adapted the somewhat complex approach used in the notes for the model including leverage. The leverage model is delicate to handle as a POMP since the measurements play a role in the dynamics, but basic stochastic volatility models do not have that feature.

**Suggestions**:

1. One could use t-distributed returns within a stochastic volatility model, with or without leverage.

2. The ARMA models should have been fitted to the return (difference of log price) rather than the raw data. It is not immediately clear from the text what is intended, but the code reveals they are fitted to the raw data.

3. The AR-Garch model is undefined. Better to write out a model specification when doing applied statistics, but especially for a model that may be unfamiliar to the reader.

4. The convergence diagnostics for the Breto model are disappointing, showing decreasing likelihoods and substantial variation. This could indicate model misspecifcation of some kind.

5. The local search for the stochastic volatility model has nice consistent results, but also shows a steady decline in the likelihood as the random walk variance on parameters is reduced, indicative of model misspecification. Maybe t-distributed returns would help with this?

6. In the Heston model, the authors also illustrate the model formulas and useful notations. However, for the first plot, there is no proper interpretation or caption to describe which row is the simulated volatility or the actual volatility.

7. It would be helpful (and maybe interesting) to compare simulations from all the fitted models.

8. Typo: The Heston model notation for the Brownian motions is a bit unclear. Maybe, $W=(W^s,W^\nu)$ should be a bivariate Brownian motion?

9. Typo: Fixing $\mu=1$ looks like a typo; fixing $\mu=0$ is a more natural simplification and matches what happened in the code (or, rather, the returns are de-mened to make $\mu=0$ appropriate).




