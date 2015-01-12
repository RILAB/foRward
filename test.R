library(Rcpp)
library(foRward)

WFM = Rcpp::Module("WFsingle",inline::getDynLib("foRward"))
x = WFM$make_WFsingle(1000)
evolveWFsingle(x,0.01,0.001,0.1,0.5,0.001,c(rep(10000,1000),rep(100,100),rep(1000,1000)),101)
print(WFsingleNmuts(x))
