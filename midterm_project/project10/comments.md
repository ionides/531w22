---
title: "Review comments on Project 10"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:  An extensive range of appropriate methods considered. The authors limit to looking at linear associations. They are properly cautious about causal interpretations of these results. The report was written carefully: referees found relatively few technical errors.

**Points for consideration**:

1. "However, the ma1 and ma2 roots for the SARIMA(1,1,3) are inside the unit cycle, which may suggest a problem with causality and invertibility." This is incorrect - the plot shows the inverse of the roots. Note, the report interprets this correctly at a later point.

2. The simulation study for the estimated ma1 coefficient looks wrong; one typically expects values within [-1,1].

3. References could be formatted formally.

4. One could look for a lagged or nonlinear relationship between cases and vaccinations.

5. Typo: Parentheses are missing in the SARIMA specification. They should go around $(1-B)^d (1-B^7)^D Y_n - \mu$.

6. Various chunks of unprocessed R output are shown. It is better to incorporate the needed results into the report. 





