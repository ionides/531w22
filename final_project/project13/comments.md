---
title: "Review comments on Project 13"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

Strengths: A competent model-based investigation of COVID-19 in California and Texas. The conclusions accurately place the contributions of the work in the context of possibilities for continuations.

**Suggestions**:

1. Why are initial values treated as known, rather than estimated?

2. The fixed initial value of H does not make sense, but perhaps this does not matter since it gets reset to zero at each observation time.

3. Don't display log likelihood evaluations to 7 decimal places. One is usually enough.

4. The fixed value $\phi=14$ is not explained.

5. For the introduction, it is better to include the background (epidemic situation) in the researched regions, California and Texas.

6. It could be interesting to compare the results for California and Texas, but the report does not make progress on that. Indeed, the report does not put the analysis into the context of the characteristics of the two states analyzed.

7. The visual simulation of local search in California seems to give the wrong value of original daily new cases report in the plot, because the line is the same as the one in Texas. This may be a result of a coding problem where some variable names are re-used for the California and Texas cases.

8. This project builds on previous projects, which is a good thing to do. However, given this helpful start it might have been possible to get further.

9. There is a sign mistake in $\mathrm{Binomial}(S,1-\exp\{\beta \frac{1}{N} \Delta t \})$ which may have been inherited from https://ionides.github.io/531w21/final_project/project15/blinded.html. It is okay to borrow from cited past projects, but one should borrow critically.

10. The results are shown at low computational intensity, for example, only 5 iterations are used to look for the MLE in the local search. Evidently, the group did not learn to take advantage of greatlakes.






