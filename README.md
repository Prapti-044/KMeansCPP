
<!-- README.md is generated from README.Rmd. Please edit that file -->

# KMeansCPP

<!-- badges: start -->

[![License: GPL
v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
![GitHub repo
size](https://img.shields.io/github/repo-size/Prapti-044/KmeansCPP)
![GitHub code size in
bytes](https://img.shields.io/github/languages/code-size/Prapti-044/KmeansCPP)
![GitHub language
count](https://img.shields.io/github/languages/count/Prapti-044/KmeansCPP)
![GitHub top
language](https://img.shields.io/github/languages/top/Prapti-044/KmeansCPP)
<!-- badges: end -->

The goal of KMeansCPP is to learn how to create an R-package by
implementing [KMeans clustering
algorithm](https://en.wikipedia.org/wiki/K-means_clustering) efficiently
using C++ for clustering a dataset.

*Note*: This RMarkdown is created following the guidelines of [this
R-package example](https://github.com/mvuorre/exampleRPackage).

## Installation

You can only install the development version from [this
repository](https://github.com/Prapti-044/KMeansCPP) with:

``` r
# install.packages("devtools")
devtools::install_github("Prapti-044/KMeansCPP")
```

## Example

This is a basic example which shows you how to cluster the iris dataset:

``` r
library(KMeansCPP)
result <- applyKMeans(as.matrix(iris[,-5]), 3, 300)
str(result)
#> List of 3
#>  $ : num [1:4] 5.006 3.428 1.462 0.246
#>  $ : num [1:4] 6.85 3.08 5.72 2.05
#>  $ : num [1:4] 5.88 2.74 4.39 1.43
```
