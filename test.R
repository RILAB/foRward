library(Rcpp)
library(foRward)

sfs = array(dim=9,data=0)

N=1e3
NGENS=10*N
NREPS=100
popsizes=rep(N,NGENS)
for(i in 1:100)
    {
        x=evolveStd(1000,0.01,0,0.1,0.5,0.0,popsizes,as.integer(runif(1,0,1e6)))
        x.sample = sampleStd(x,10,0);
        #for(j in 1:ncol(x.sample$neutral))
        #    {
        #        c = length(which(x.sample$neutral[,j]==1))
        #        sfs[c] = sfs[c]+1
        #    }
    }
print(sfs/NREPS)
#print(x.sample$npos)
#print(x.sample$spos)
#print(x.sample$neutral)
#print(x.sample$selected)


