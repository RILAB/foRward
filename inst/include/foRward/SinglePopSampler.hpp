//#include <SinglePop.hpp>
#include <Rcpp.h>
#include <fwdpp/sampling_functions.hpp>

/*
  This file provides a templated abstraction
  of the operation of taking a sample of size n 
  from a larter population of N diploids.

  The implementation is via a call to the fwdpp function,
  and then we convert the data to Rcpp types, which is a wee 
  bit inefficient, but it it what we have to do.

  For a use example, see samplStd in standard_model.cc
*/
//TODO: use fixations list to add in all of them!  BUG

namespace foRward {
  template<typename poptype>
  Rcpp::List SinglePopSampler( SEXP pop, SEXP rng,
			       const unsigned & nsam,
			       const bool & remove_fixed = false)
  {
    Rcpp::XPtr<poptype> ppop(pop);
    Rcpp::XPtr<GSLrng> r(rng);

    auto __sample = KTfwd::ms_sample_separate(r->r.get(),&ppop->diploids,nsam,remove_fixed);

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
}
