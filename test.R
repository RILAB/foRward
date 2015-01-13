library(Rcpp)
library(foRward)

x=evolveStd(1000,0.01,0.0,0.1,0.5,0.01,c(rep(1000,10000)),as.integer(runif(1,0,1e6)))
x.sample = sampleStd(x,10,0);

print(x.sample$npos)
print(x.sample$spos)
print(x.sample$neutral)
print(x.sample$selected)


