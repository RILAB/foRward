#include <SinglePop.hpp>
#include <Rcpp.h>
#include <fwdpp/sampling_functions.hpp>

template<typename poptype>
Rcpp::List SinglePopSampler( SEXP pop, SEXP rng,
			     const unsigned & nsam )
{
  Rcpp::XPtr<poptype> ppop(pop);
  Rcpp::XPtr<GSLrng> r(rng);

  auto __sample = KTfwd::ms_sample_separate(r->r.get(),&ppop->diploids,nsam);

  Rcpp::IntegerMatrix n((!__sample.first.empty())?nsam:0,__sample.first.size()),
    s((!__sample.second.empty())?nsam:0,__sample.second.size());
  Rcpp::NumericVector npos,spos;

  for( unsigned i = 0 ; i < __sample.first.size() ; ++i )
    {
      npos.push_back(__sample.first[i].first);
      for(unsigned j=0;j<nsam;++j)
	n(j,i)= ((__sample.first[i].second[j] == '1') ? 1 : 0);
    }
  for( unsigned i = 0 ; i < __sample.second.size() ; ++i )
    {
      spos.push_back(__sample.second[i].first);
      for(unsigned j=0;j<nsam;++j)
	s(j,i)=((__sample.second[i].second[j] == '1') ? 1 : 0);
    }
  return Rcpp::List::create( Rcpp::Named("npos") = npos,
			     Rcpp::Named("spos") = spos,
			     Rcpp::Named("neutral") = n,
			     Rcpp::Named("selected") = s);
}
