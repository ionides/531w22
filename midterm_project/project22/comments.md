---
title: "Review comments on Project 22"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: 

**Points for consideration**:

1. If you don't want to explain what `auto.arima` does, and you don't want to discuss it or question it, that may not be a good thing to include in your data analysis. 

2. "The two models are significantly different" is not an appropriate way to explain rejecting the null hypothesis in a significance test.

3. Inconsistent values in the AIC table (not mathematically possible under accurate likelihood maximization and evaluation) should be noted and discussed. NA values in the table should be further disucssed and investigated. 

4. The project does not cite any previous STATS/DATASCI projects, yet it has strong similarities to some past ones, e.g., https://ionides.github.io/531w21/midterm_project/project02/project.html. This is inadequate scholarship which is a substantial weakness for the report.

5. The decomposition into trend + noise + cycles is unsuccessful here - the "noise" is seasonality. Frequencies for the bandpass filters should be relevant to the data being analyzed. The goal of this analysis is not clear in the context of this project. 




