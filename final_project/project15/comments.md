---
title: "Review comments on Project 15"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

 A coherent and well-referenced investigation.

Summing the cases over a week to eliminate day-of-week effects is a good decision. Some other COVID-19 analyses ran into difficulties by not doing this.

**Suggestions**:

1. The model is initialized with $I=1$, which may be inappropriate here. That may explain why the simulations start slower than the data. It could also seriously bias parameter estimates. Plotting the simulations and data on a log scale would help to make this evident.

2. For the delta wave, this problem is particularly acute (the omicron wave seems to start plausibly from $I=1$). Consequences of this can be diagnosed by the evidence of noisy likelihood maximization and high noise in the resulting simulations as they try to fit the data from an inappropriate initial condition.

3. Comparing to a benchmark likelihood, such as log-ARMA, might also have helped to identify model misspecification issues.

4. The description $k  = \mathrm{Initial infecteds}$ does not match the code, where $k$ is a measurement overdispersion parameter. Similarly, $N$ is the population size not the susceptible size.

5. Fixing $\rho=0.1$ is a strong assumption that should be relaxed later. 

6. The profile likelihood should be based on a smooth curve based on the Monte Carlo point estimates. Sometimes it is helpful to plot the points, but these cannot readily give a formal interval. 

7. All these issues together result in a model that gives unstable likelihood evaluation and is hard to filter and hence to obtain maximum likelihood estimates.

8. This project has apparently been carried out independently of all previous STATS/DATASCI 531 projects, but that is not entirely an advantage. There is plenty to learn from the more successful previous projects, such as https://ionides.github.io/531w21/final_project/project15/blinded.html

9. Typo in the title: "Comparsion". Many other typos may make readers wonder if the numerical work is similarly careless. Readers use easier-to-measure writing quality as a proxy for harder-to-see technical care.

10. There should be an explicit link to the data source.  In reference 4, they just gave us a website about the introduction of GISAID, but it is not clear how to obtain these data.

11. The data has some questionable features. As pointed out, the author did not give a specific link to the source of the data, but if this data is true, then from the plot, we can know in March 2022, there should be neither Delta variant nor Omicron variant in the United States because their numbers both become 0, which is inconsistent with what we know. The reason for this may be that the initiative stopped classifying COVID-19 cases from a certain day, but since there is no proper source given for the data, we have no way of checking.




