#include <foRward/gslutils.hpp>

void gsl_rng_deleter::operator()( gsl_rng * r ) noexcept 
{
  gsl_rng_free(r);
}

//' Make an external pointer to a GSL rng *
// [[Rcpp::export]]
SEXP makeGSLrng( const unsigned & seed )
{
  return Rcpp::XPtr<GSLrng>( new GSLrng(seed) );
}
