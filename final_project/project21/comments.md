---
title: "Review comments on Project 21"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

An interesting approach to COVID analysis, splitting up the investigation by dominant variant.

**Suggestions**:

1. ARMA(4,4) is on the limit of the range of considered ARMA models, so if it seems the best then should one look further? In practice, ARMA(4,4) is already a complicated model.

2. It appears the fitted ARMA(4,4) is not doing a good job of explaining weekly periodicity. Perhaps sum cases over weeks to avoid this issue.

3. Raw R output can be hard to read and should be avoided. For example, `avg_7` is undefined in the EDA section. Labels and captions for figures would help the reader.

4. Population models are typically close to log-linear, so ARMA modeling is preferred on the log scale.

5. Setting $I_0=1$ is wildly implausible here, as you can see from the simulations struggling at the start of the pandemic. Perhaps one has to start a bit later (say, April) with higher $I_0$. Perhaps there were reporting rate issues right at the start, with a higher rate of undiagnosed cases.

6. Looking into the code, we find that the authors fixed the parameters $\mu_{IR}$, $\mu_{EI}$ and $\tau$. This needs more explanation and justification.

7. The delta wave model also has problems with its initial conditions.

8. The ARMA analysis is disconntected to the mechanistic modeling. ARMA is fitted with the complete data while pomp model is fitted partially so it is inappropriate to compare the partial model with a full model if the authors plan to make comparison based on the log likelihood as a benchmark.

9. The iterated filtering searches can get lost - especially evident for the delta variant. This can be due to model misspecification or a choice of random walk intensity which is much too large.





