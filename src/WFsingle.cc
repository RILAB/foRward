#include <WFsingle.hpp>

// [[Rcpp::plugins(cpp11)]]

WFsingle::WFsingle ( const unsigned & popsize ) : N(popsize),
						  mutations(mlist()),                //No muts in the population
						  gametes(glist(1,gtype(2*popsize))), //The population contains a single gamete in 2N copies
						  diploids(dipvector(popsize,std::make_pair(gametes.begin(),gametes.begin()))), //All N diploids contain the only gamete in the pop
						  mut_lookup(lookup_table_type()),
						  fixations(mvector()),
						  fixation_times(ftvector())
{
}

WFsingle::mlist::size_type WFsingle::nmuts() const { return mutations.size(); }

Rcpp::XPtr<WFsingle> makeWFsingle(const unsigned & N) { return Rcpp::XPtr<WFsingle>(new WFsingle(N)); }
//RcppExport SEXP makeWFsingle(const unsigned & N) { return Rcpp::XPtr<WFsingle>(new WFsingle(N)); }
//WFsingle makeWFsingle(const unsigned & N) { return WFsingle(N); }

//WFsingle makeWFsingle(const unsigned & N) { return WFsingle(N); }

// [[Rcpp::export]]
unsigned WFsingleNmuts(SEXP pop) {
  Rcpp::XPtr<WFsingle> ppop(pop);
  return ppop->nmuts();
}

RCPP_MODULE(WFsingle)
{
  Rcpp::class_<WFsingle>( "WFsingle" )
    .constructor<unsigned>("Initialize a monomorphic population of N diploids")
    .method("nmuts",&WFsingle::nmuts,"Return number of mutations")
    ;
  Rcpp::function("make_WFsingle", &makeWFsingle,"Make a WFsingle object");
}

