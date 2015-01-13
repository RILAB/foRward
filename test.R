library(Rcpp)
library(foRward)

x=evolveWFsingle(100,0.01,0.001,0.1,0.5,0.001,c(rep(1000,100)),as.integer(runif(1,0,1e6)))
x.sample = sampleSingle(x,10,0);

print(x.sample$npos)
print(x.sample$spos)
print(x.sample$neutral)
print(x.sample$selected)
!

