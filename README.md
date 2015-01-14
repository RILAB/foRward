# foRward: forward simulation in R using fwdpp

This package is a testing ground for providing access to efficient forward-time population simulation machinery in R.

The specific goals are:

1.  Provide some useful routines that allow users to easily perform simulations under standard modeling scenarios.  This part of the package is a "regular" R package that provides functions that a user may find useful.
2.  Provide a mechanism by which a user may extend the package, and thereby simulate under other models within R.  This part of the package provides an interface for the development of additional Rcpp/fwdpp-based packages so that "power users".

The hope is that both aspects of the package evolve in tandem.

This package is implemented in terms of:

1. [Rcpp](http://cran.r-project.org/web/packages/Rcpp/index.html), which is an R package to streamline the exposure of methods implemented in C++ to R.
2. [fwdpp](http://molpopgen.github.io/fwdpp/), which is a C++11 template library for implementing efficient population genetic simulations
## What does the package do?

Now, as of version 0.0.1, the answer is "not much" in terms of meeting goal number 1.  So far, the library provides three functions:

1. evolveStd evolves a single Wright-Fisher population under the "standard" (or perhaps "default") model used in population genetics: fixed selection and dominance coefficients assigned to mutations, fitnesses are multiplicative across mutations, mutations arise according to an infinitely-many sites process and recombination occurs uniformly along a genomic region
2. sampleStd samples a sample of size n from a population of N diploids simulated by evolveStd, and returns a list of genotypes.

Based on the above, a user can actually do quite a bit, as evolveStd allows the simulation of arbitrary changes in N over time.

Progress on goal number two has resulted in:

1. A relatively simple method to generate new single-population simulations.  Some programmers may find this approach preferable to writing standalone C++ programs based on fwdpp.
2. Proof-of-principle that fwdpp functions can be made available to an Rcpp-based package based on further abstraction using C++ templates.

The package installs a bunch of headers that define a C++ namespace called foRward.  As with Rcpp, these headers are intalled into the bowels of an R installation.  Unlike Rcpp, I have done no testing to show that it is even possible to include those headers in a package derived from this one, but we're at version 0.0.1 here, right?

There is currently no documentation of namespace foRward, but you can look at the header files in inst/include/foRward in the source repository.

##Availability

This package is distributed at the following github repository: https://github.com/molpopgen/foRward.

This package is not (yet) available through CRAN, which does not allow the submission of C++11-based packages (yet).

##Dependencies

A lot of them:

* [Rcpp](http://cran.r-project.org/web/packages/Rcpp/index.html)
* [boost](http://www.boost.org)
* [gsl](http://www.gnu.org/software/gsl)
* [fwdpp](http://molpopgen.github.io/fwdpp/), preferably 0.2.5 or higher
* [libsequence](http://molpopgen.github.io/libsequence) 1.7.8 or newer is an installation dependency for fwdpp

You also need a C++11-compliant compiler.  For OS X users, that means Yosemite + current Xcode installation.  For linux users, GCC 4.8 or newer should suffice.

OS X users are recommended to use [brew](http://brew.sh) to install boost and gsl.

The following dependencies are only needed if you need to build the vignettes, etc.

* [knitr](http://cran.r-project.org/web/packages/knitr/index.html)

##Installation

First, install the dependencies.

Then, using R's devtools package:

~~~
library(devtools)
install_github("molpopgen/foRward",ref="dev")
~~~

On OS X, you may need to invoke R as follows:

~~~
R_LD_LIBRARY_PATH=/usr/local/lib R
~~~

Otherwise, the R build system may not be able to link to dependent libraries.

##Running the test example:

~~~
R_LD_LIBRARY_PATH=/usr/local/lib R --no-save < test.R
~~~

## Documentation

The main documentation is a series of vignettes:

~~~
library(foRward)
browseVignettes("foRward")
~~~

The vignettes are HTML, so you must be on a system where your browser can be accessed by R.

## Development pseudo-roadmap

1. Expose more fwdpp functionality to namespace foRward.
2. Expand the capabilities of simulation under the "standard" model to show what can be done in this environment.
