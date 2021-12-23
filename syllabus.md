---
title: "Syllabus for STATS/DATASCI 531 (Winter 2022) <br><it>Modeling and Analysis of Time Series Data</it>"
author: "Instructor: Edward L. Ionides"
output:
  html_document:
    toc: no
csl: ecology.csl
---


## Course information

Structure of the lectures and project groups is to be confirmed, depending on the Omicron situation. Course components will include:

* classes, in person according to current UM guidelines
* homework
* [Piazza discussion forum](https://piazza.com/umich/winter2022/statsdatasci531)
* group midterm project, with individual peer review
* group final project, with individual peer review


Instructor contact information:

* email: ionides@umich.edu 
* web: dept.stat.lsa.umich.edu/~ionides
* office hours: Tuesday/Thursday 11:30-12:30

GSI: Gang Qiao

* email: qiaogang@umich.edu
*  office hours: TBD

Computing support. If you have a coding problem you cannot debug, it is often helpful to develop a [minimal reproducible example](https://stackoverflow.com/help/minimal-reproducible-example) that others can run to help you. You can share this, and the error message you obtain, with your group and/or on Piazza, or by email if necessary.

Course notes and lectures are posted at https://ionides.github.io/531w22/ with source files available at https://github.com/ionides/531w22

Supplementary textbook: R. Shumway and D. Stoffer _Time Series Analysis and its Applications_, 4th edition (2017). 
A [pdf](https://link.springer.com/book/10.1007%2F978-3-319-52452-8) is available using the UM Library's Springer subscription.

Recommended pre-requisites:

* Theoretical and applied statistics. STATS 500 and prior or concurrent enrollment in STATS 511, or equivalent. STATS 413 and STATS 426 is sufficient in conjunction with a strong math and computing background. For review, see "Mathematical Statistics and Data Analysis" by J. A. Rice.

* Linear algebra. A certain amount of basic linear algebra will be required. For review, see 
[www.sosmath.com/matrix/matrix.html](http://www.sosmath.com/matrix/matrix.html).

Statistical computing background:

* We carry out data analysis using R. There is no formal R prerequisite, but we will be working with R extensively and so you should allow extra time for this course if you are new to R programming. Come to chat and we can make a plan for learning R in the context of your computational background.

-----------

## Course outline


1. Introduction to time series analysis.

2. Time series models: Estimating trend and autocovariance.

3. Stationarity, white noise, and some basic time series models.

4. Linear time series models and the algebra of autoregressive moving average (ARMA) models.

5. Parameter estimation and model identification for ARMA models.

6. Extending the ARMA model: Seasonality and trend.

7. Introduction to the frequency domain.

8. Smoothing in the time and frequency domains.

9. Case study: An association between unemployment and mortality?

10. Introduction to partially observed Markov process (POMP) models.

11. Introduction to simulation-based inference for epidemiological dynamics via the pomp R package.

12. Simulation of stochastic dynamic models.

13. Likelihood for POMP models: Theory and practice.

14. Likelihood maximization for POMP models.

15. A case study of polio including covariates, seasonality & over-dispersion.

16. A case study of financial volatility and a POMP model with observations driving latent dynamics.

--------------

## Groups

* The [2021](https://ionides.github.io/531w22/) online version of this course built in a new group structure. Watch the course website and Canvas notifications for how it will be adapted for 2022. Expect something like the following.

* Groups for the midterm project will be randomly assigned, around the third weak of classes.

* Groups for the final project will be re-randomized after the midterm project. 

<!--
* Groups are expected to meet up for at least 25 minutes a week, to discuss class notes or homework or projects, and for another 25 minutes a week together with an instructor. Active participation in your group will carry course credit.
-->

-------------

##  Grading

* Weekly homeworks (25\%).
* A group midterm project (20\%, due 11:59pm on Monday 2/21). In special situations, you can request to write an individual project for the midterm and/or the final project. This may be appropriate if you have a particular dataset or scientific question that has motivated your interest in learning time series analysis. You can also ask your group if it is willing to join collaboratively on your project to make it a group project.
* Two individual anonymous peer review evaluations of other group midterm projects (5\%, due 11:59pm on Monday 3/7). Each should be about 500 words, and should identify the main strengths and weaknesses of the project (from both technical and conceptual perspectives) as well as identifying points with room for improvement. The reviews should include discussion relating to reproducibility of the project's numerical results.
* A group final project (30%, due 11:59pm on Tuesday 4/19).
* Two individual anonymous peer review evaluations of other group final projects (10\%, due 11:59pm on Wednesday 4/27). Each should be about 1000 words, and should identify the main strengths and weaknesses of the project (from both technical and conceptual perspectives) as well as identifying points with room for improvement. The reviews should include discussion relating to reproducibility of the project's numerical results.
* Participation (10%). To build a learning community, attendance and contributions are valuable. Similarly, both raising and answering questions on a discussion forum is helpful. The instructor and GSI will keep track of student participation.
* Course letter grades are anticipated to be mostly in the A, A-, B+ range customary for courses at this level. In the past, this has corresponded to overall scores of approximately 95% for A+, 90% for A, 85% for A-, 80% for B+. However, the exact cutoff used will be determined in the context of the course for this specific semester.

### Grading credit for attribution of sources

Careful attribution of sources is fundamental to good scholarship. Also, **complete attribution facilitates meaningful grading given the reality of abundant online materials and online collaboration**. The grader will look for demonstrated effort in submitted homework, with contributions that go beyond the sources, following the <a href="rubric_homework.html">posted rubric</a>.

+ Each homework will have a question asking about sources. You will be asked to explain which parts of your responses above made use of a source, meaning anything or anyone you consulted (including classmates or office hours or any website you visited) to help you write or check your answers. **All sources are permitted. Every source must be documented. Full credit requires being explicit about which parts you did without any collaboration or other source, as well as being explicit about which parts used or did not use each listed source.**

+ Reference any web page you look at in connection with a homework or project, and to acknowledge any person you talk to in connection with a homework or project, including people in your own group or discussions in office hours.

+ If you look at a web page while working on your homework solutions, or while checking your homework solutions, add the URL to your source section.

+ The grader will look for an explicit statement saying that the listed sources and only those sources were consulted. 

+ Directly copied text must be in quotation marks. Directly copied equations must be explicitly referenced to the source. Adapted or paraphrased material take from a source should be referenced.

+ It is expected that you will consult the notes and the course Piazza site. However, putting explicit references (e.g., 531 class notes, slide 10 of chapter 3) is still appropriate as documentation of your sources.

+ The reader should not have to carry out detective work to figure out correctly which parts of the homework are attributable to a source.  Specific references to a page of the notes, or material on a previous course web page, or a page of the textbook, or a Stack Overflow page, can help with this. If the reader cannot readily tell what part of the homework is attributable to each source, that is a defect in the scholarship.

+ The midterm and final project will also have a substantial grading component allocated to clear and scholarly assignment of credit to sources.

+ In group work, you are responsible for checking that the sources of your collaborators are properly documented. The whole group must take responsibility for material that the group submits. 


----

## Student Mental Health and Wellbeing

University of Michigan is committed to advancing the mental health and wellbeing of its students. If you or someone you know is feeling overwhelmed, depressed, and/or in need of support, services are available. For help, contact Counseling and Psychological Services (CAPS) at 734.764.8312 and  https://caps.umich.edu during and after hours, on weekends and holidays. You may also consult University Health Service (UHS) at 734.764.8320 and https://www.uhs.umich.edu/mentalhealthsvcs.

----------

## Acknowledgements

Many people have contributed to the development of this course, including all former students and instructors. See the [acknowlegements page](acknowledge.html) for further details.

-----------
