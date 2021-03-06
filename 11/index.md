---
title: "Modeling and Analysis of Time Series Data<br>STATS/DATASCI 531, Winter 2022<br>Chapter 11: Introduction to simulation-based inference for epidemiological dynamics via the pomp R package"
author: "Edward L. Ionides"
output: html_document
---

We are borrowing material from a short course on [Simulation-Based Inference for Epidemiological Dynamics](https://kingaa.github.io/sbied/) (SBIED).
This short course uses the same notation as STATS/DATASCI 531 and shares an emphasis on likelihood methods for inference.
Indeed, SBIED can be viewed as a sub-course within STATS/DATASCI 531.
Although SBIED focuses on epidemiological examples, you can check from previous final projects for [2016](http://ionides.github.io/531w16/final_project/), [2018](http://ionides.github.io/531w18/final_project/), [2020](http://ionides.github.io/531w20/final_project/) and [2021](http://ionides.github.io/531w21/final_project/) that the ideas extend readily to a variety of other situations.
Later, in Chapter 16, we will consider models for financial markets, which is another major area of application for nonlinear time series techniques. 

Chapter 11 Part 2 has overlap with Chapter 10. It may be no bad thing to see the foundational material again, from a slightly different perspective. You are welcome to watch at 1.5 x speed if you are already comfortable with Chapter 10.


| | | | 
|:---|:---|:---|
| Slides  | |  [pdf](https://kingaa.github.io/sbied/intro/slides.pdf) |
| Notes   | | [pdf](https://kingaa.github.io/sbied/intro/notes.pdf) |
| Recording, Chapter 11, Part 1  | Time series analysis and mechanistic models in ecology and epidemiology | [(20 mins)](https://youtu.be/wn4bv3nz0kU) | 
| Recording, Chapter 11, Part 2  | Introduction to POMP models | [(22 mins)](https://youtu.be/-P4lwVDHxjQ) |
| Recording, Chapter 11, Part 3  | The pomp R package for POMP models | [(7 mins)](https://youtu.be/1MY8NuJ5fr4) |
----------------------

<iframe width="560" height="315" src="https://www.youtube.com/embed/wn4bv3nz0kU" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/-P4lwVDHxjQ" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/1MY8NuJ5fr4" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

----------------------

[Back to course homepage](../index.html)  
[Acknowledgements](../acknowledge.html)  
[Source code for these notes](http://github.com/kingaa/sbied/tree/master/intro)


----------------------
