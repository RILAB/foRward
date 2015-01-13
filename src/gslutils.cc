#include <gslutils.hpp>

void gsl_rng_deleter::operator()( gsl_rng * r ) noexcept 
{
  gsl_rng_free(r);
}

Rcpp::XPtr<GSLrng> makeGSLrng( const unsigned & seed )
{
  return Rcpp::XPtr<GSLrng>( new GSLrng(seed) );
}
