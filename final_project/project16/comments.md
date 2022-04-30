---
title: "Review comments on Project 16"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

An ambitous development of a complex mechanistic model to describe COVID-19 dynamics.

**Suggestions**:

1. The rationale for choosing Moscow (Russia) is unclear. The assertion that "we chose this data because it has recorded and updated the number of confirmed cases, number of deaths, and number of recovered cases daily" seems surprising since many locations have reported regularly. Russian data was notoriously problematic, with reporting likely influenced by political considerations that might conflict with public health.

2. The model has no measurement or process over-dispersion which might cause problems fitting to data. This could explain the observed difficulties with convergence of the optimization.

3. A benchmark (e.g., ARMA or iid negative binomial) would help see whether the mechanistic model has reasonable statistical fit.

4. The model is complex (which is technically impressive) but maybe a more problematic assumption is the static structure. A referee pointed out that various difficulties of modelling covid-19 lie in the fact that people getting exposed to the virus, being infected, and recovering from the disease is a dynamic process, and most factors influencing the transmission process change along with time, such as policy and variants. It might be helpful to have a time-varying part in the model when fitting the Covid-19 data. Even when fitting to just one wave of the pandemic, lockdowns and other social factors changed rapidly.

5. According to the figure of the confirmed cases, we could see there is a small peak before the 50 days. After being fluctuated around small values for a short time, the data increase to be stable for about 150 days. At the last 50 days, there is no obvious tread of decreasing cases. All these characteristics demonstrate that the time-invariant model could not depict the data quite well. Other results from local and global search also verify this inference.

6. The authors propose a complex model, and to make progress they fix many of the parameters. That could be problematic if one or more parameters are accidentally fixed in a way that disagrees with the data.

7. Math punctuation is erratic. Best to punctuate math as text. A period goes at the end of the last line of math, not on a blank line.

8. The arrow from A to Sy is surprising, and could be considered for deletion. Generally, the definition of asymptomatics is that they go down a route that does not lead to symptoms.



