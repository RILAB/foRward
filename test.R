library(Rcpp)
library(foRward)

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
        x=evolveStd(GSL,1000,0.01,0,0.1,0.5,0.0,popsizes)
        x.sample = sampleStd(x,10,0);
        for(j in 1:ncol(x.sample$neutral))
            {
                c = length(which(x.sample$neutral[,j]==1))
                sfs[c] = sfs[c]+1
            }
    }
print(sfs/NREPS)
#print(x.sample$npos)
#print(x.sample$spos)
#print(x.sample$neutral)
#print(x.sample$selected)


