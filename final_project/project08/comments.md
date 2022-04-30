---
title: "Review comments on Project 8"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**:

A novel model and data analysis for COVID in Turkey.

**Suggestions**:

1. Can the authors explain the particular motivation for studying Turkey? Is there some unusual and favorable feature of data collection, for example? Could the authors add some cultural context to help the reader compare the Turkey pandemic experience to USA. What time of year do Turks typically spend more time inside - summer or winter?

2. The report raises the question of why the SEIREIR model fits worse than ARIMA. Perhaps plotting on a log scale might help. One might see that the fixed initial conditions (especially $I_0=100$) are problematic.

3. The authors also tried to learn the periodicity in data using smoothed periodogram. However, the related plot (smoothed periodogram) is missing in the report.

4. The author stated that “The result shows that ARIMA(2,1,0) is better for the data.”. However, the rejection of alternative hypotheses (I assume that is what happened) does not really mean one is better than another but more like choosing alternative over null is not statistically supported.

5. The iterated filtering convergence plots show incomplete convergence: the likelihood continues to go up. This suggests more iterations, and/or a larger random walk standard deviation.

6. More discussion of the parameters corresponding to the MLE (or parameter values with likelihood close to the identified maximum) would be nice to see.

7. Captions for graphs would help the reader.

8. The report does not describe the measurement model, apart from presenting code.

9. Typo: "We fix $N=843400$" should be $84.34 \times 10^6$

10. Typo: "$1/1\mathrm{month}$" should read $1/3\mathrm{month}$ for consistency with the text and code.

11. Proof-reading: grammatical mistakes were distracting for some readers.




