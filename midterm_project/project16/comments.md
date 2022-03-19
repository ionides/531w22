---
title: "Review comments on Project 16"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: Many techniques from the class are tried out in a clearly presented analysis of a topic with high relevance to the West Coast.

**Points for consideration**:

1. There should be a $+$ instead of $-$ in the MA polynomial of order $q$. 

2. In the frequency domain, the main peak at 1 cycle per year is just seasonality, and the smaller peak at 2 cycles is a slightly non-sinusoisal seasonality.

3. It is unsurprising to find no "seasonality" in annual data.  Do you mean that there was no detectable spectral peak?

4. Conclusions relate to looking for a model to fit, but not what was learned from the fitted model.

5. The QQ plot shows a skewed left pattern, worth some mention.

6. The project correctly concludes that it would be nice to know something about the relationship between the fire data and other relevant time series - this could be within the scope of a midterm project.

7. ACF plots cannot show evidence for heteroskedasticity, only autocorrelation.

8. Some extra attention to titles, labels and captions on figures would make it easier for the reader.

9. There are 5364 NA’s of the "ALARM DATE" column, which accounts for about 25.16% of all observations. This is not a small proportion, and merits mention.




