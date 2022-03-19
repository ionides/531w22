---
title: "Review comments on Project 8"
author: "STATS/DATASCI 531, Winter 2022"
output:
  html_document:
    toc: yes
---

**Strengths**: A dataset of broad interest to data scientists. Nicely presented work (only one example of unexplained raw R output).

**Points for consideration**:

1. The introduction is clear but could have more references to put the data, terminology and questions in a larger context. It is surprising that R and Python are called "libraries" rather than languages - is there a reason for this.

2. In Sec 2, a time plot would be more informative than a boxplot split by year.

3. Sec 3.1. "The highest peak occurs in the beginning of the period, with lower peaks appearing later on" is not clear. What is the "beggining of the period"? Do you mean January?  

4. Sec 4.1. The white noise assumption is wildly violated. Don't spend time carefully developing and explaining analysis which you have already found to be inappropriate. Don't present p-values you know to be inappopriate, unless it is part of an argument to explain why the p-value is inappropriate. Here, the main violation is the nonlinear trend more than the seasonality, but that has already been identified. 

5. Sec 4. It would be more relevant to check for a tend in the difference of log r rather than r itself. You have already explained why log and differencing make sense.

6. It is not always clear what data are being fitted. The raw data? Log data? Log differenced data? It is important to make sure this is clear from the writing, since otherwise the reader cannot readily interpret the results without going into the code.

7. Sec 4.2. The existence of trend in the data is not surprising here. It might be more interesting to see if there is evidence for nonlinearity of the trend. Has the stack overflow community for R stopped growing? If there is evidence for that, what might you conclude?

8. Interpretation needs care since stack overflow is also getting more popular - how can your conclusions properly conclude about the popularity of R? Should you normalize somehow? That would have its own issues.

9. In general, the report is missing a discussion of its own limitations.

10. The way the simulation study was conducted doesn't seem to be valid, obviously there will be a trend in the simulated data because the generating process had a linear trend. They should be checking whether the coefficient determined from the data fell within a reasonable range instead.

11. Typo: The dataset contains the number of questions with a specific tag, not the number of searches.




