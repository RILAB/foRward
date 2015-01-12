library(Rcpp)
library(foRward)

x=evolveWFsingle(100,0.01,0.001,0.1,0.5,0.001,c(rep(1000,100),rep(100,100),rep(100,100)),as.integer(runif(1,0,1e6)))
print(WFsingleNmuts(x))


