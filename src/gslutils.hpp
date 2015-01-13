#ifndef __FORWARD_GSLUTILS_HPP__
#define __FORWARD_GSLUTILS_HPP__

#include <RcppCommon.h>
#include <gsl/gsl_rng.h>

#include <memory>

struct gsl_rng_deleter
{
  void operator()( gsl_rng * r ) noexcept;
};

using gsl_rng_ptr_t = std::unique_ptr< gsl_rng,
				       gsl_rng_deleter >;

class GSLrng {
public:
  gsl_rng_ptr_t r;
  GSLrng(const unsigned & seed) : r(gsl_rng_alloc(gsl_rng_taus2)) {
    gsl_rng_set(r.get(),seed);
  }
};

RCPP_EXPOSED_CLASS(GSLrng);
#include <Rcpp.h>
//[[Rcpp::export]]
Rcpp::XPtr<GSLrng> makeGSLrng( const unsigned & seed );

#endif
