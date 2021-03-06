library(Rcpp)
library(foRward)

#The sfs has n-1 bins
sfs = array(dim=9,data=0)

N=1000
NGENS=10*N
NREPS=100
popsizes=rep(N,NGENS)

#' You need to provide a random number generator to
#' functions in foRward. Since fwdpp works via the GSL
#' type gsl_rng *, we need a wrapper to one of those.
#' The functions foRward::makeGLSrng returns an external
#' pointer to one
GSL = makeGSLrng(100);  #RNG seed object via GSL routines
for(i in 1:NREPS)
    {
        #'x will be an Rcpp wrapper around an SEXP, which
        #'is a pointer to external data used by the current R session
        #'that pointer points to an object of type WFpop_std,
        #'which is defined in standard_model.hpp
        x=evolveStd(GSL,1000,0.01,0,0.0,0.0,0.0,popsizes)
	#' We pass TRUE to the function to remove fixed mutations
        x.sample = sampleStd(x,GSL,10,TRUE);
        for(j in 1:ncol(x.sample$neutral))
            {
                c = length(which(x.sample$neutral[,j]==1))
                sfs[c] = sfs[c]+1
            }
    }
print(sfs/NREPS)
