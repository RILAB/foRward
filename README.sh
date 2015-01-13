# foRward: forward simulation in R using fwdpp

##Dependencies

A lot of them:

* Rcpp
* boost
* gsl
* [fwdpp](https://github.com/molpopgen/fwdpp), preferably 0.2.5 or higher
* [libsequence](https://github.com/molpopgen/libsequence) 1.7.8 or newer is an installation dependency for fwdpp

You also need a C++11-compliant compiler.  For OS X users, that means Yosemite + current Xcode installation.  For linux users, GCC 4.8 or newer should suffice.

OS X users are recommended to use [brew](http://brew.sh) to install boost and gsl.

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
