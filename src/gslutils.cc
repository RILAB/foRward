#include <foRward/gslutils.hpp>

namespace foRward {
  void gsl_rng_deleter::operator()( gsl_rng * r ) noexcept 
  {
    gsl_rng_free(r);
  }
}


GSLrng::GSLrng(const unsigned & seed) : r(gsl_rng_alloc(gsl_rng_taus2)) {
  gsl_rng_set(r.get(),seed);
  }

//' Make an external pointer to a GSL rng *
// [[Rcpp::export]]
SEXP makeGSLrng( const unsigned & seed )
{
  return Rcpp::XPtr<GSLrng>( new GSLrng(seed) );
}
