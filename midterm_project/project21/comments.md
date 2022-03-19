---
title: "Review comments on Project 21"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: A well-motivated and carefully conducted analysis, leading to reasonable conclusions.

**Points for consideration**:

1. It is interesting that high returns predict high trading volume over the coming weeks. 

2. The squared return has very long tails. Why not use the absolute return?

3. The return could be $\log(p_t)-\log(p_{t-1})$ rather than $p_t/p_{t-1} - 1$.

4. Sec 4.3. You say you are simulating return, but it looks more like price and is labeled as price. 

5. Maybe trade volume is more clearly related to volatility than to the return?

6. There could be more discussion of the goals that motivate fitting a model.

7. Data were not included in the submitted project - a reproducibility issue.

8. Typo: $\mu=E[Y_n]$ not $\mu=E[X_n]$.





