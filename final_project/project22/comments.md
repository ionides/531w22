---
title: "Review comments on Project 22"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

It is nice that you discovered a simplified model (with no leverage) did better. The maximiziation probably works a bit better for a simpler model, explaining the slightly higher likelihood obtained. https://ionides.github.io/531w22/final_project/project14/Blinded.html used a similar model and found a simpler pomp representation for it.

**Suggestions**:

1. It would be interesting to see if a longer-tailed distribution for $\epsilon_n$, such as t, fits better. 

2. The global search suggests a bimodality: a collection of searches seem to reach a different and inferior region of parameter space. This is not scientifically critical - the second mode has much lower likelihood - but may help to understand numerical issues.




