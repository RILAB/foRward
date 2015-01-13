#include <SinglePop.hpp>
#include <popgenmut.hpp>
//using WFsingle = SinglePop<popgenmut>;
//template<> RCPP_EXPOSED_CLASS(SinglePop<popgenmut>);
template class SinglePop<popgenmut>;
using WFsingle = SinglePop<popgenmut>;
#include <Rcpp.h>
#include <gslutils.hpp>
#include <fwdpp/diploid.hh>
// [[Rcpp::plugins(cpp11)]]




//' Sample nsam chromosomes from population
//' @param pop A population returned from evolveWFsingle
//' @param nsam The sample size
//' @param seed RNG seed
// [[Rcpp::export]]
Rcpp::List sampleSingle( SEXP pop, const unsigned & nsam,
			 const unsigned long & seed)
{
  Rcpp::XPtr<WFsingle> ppop(pop);
  gsl_rng_ptr_t r(gsl_rng_alloc(gsl_rng_taus2) );
  gsl_rng_set(r.get(),seed);

  auto __sample = KTfwd::ms_sample_separate(r.get(),&ppop->diploids,nsam);

  Rcpp::IntegerMatrix n(nsam,__sample.first.size()),s(nsam,__sample.second.size());
  Rcpp::NumericVector npos,spos;

  Rcpp::Rcerr << __sample.first.size() << ' ' << __sample.second.size() << ' ' << n.nrow() << ' ' << n.ncol() << '\n';
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


RCPP_MODULE(WFsingle)
{
  Rcpp::class_<WFsingle>( "WFsingle" )
    .constructor<unsigned>("Initialize a monomorphic population of N diploids")
    ;
}

