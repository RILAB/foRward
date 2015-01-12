#ifndef __FORWARD_GSLUTILS_HPP__
#define __FORWARD_GSLUTILS_HPP__

#include <gsl/gsl_rng.h>

#include <memory>

struct gsl_rng_deleter
{
  void operator()( gsl_rng * r ) noexcept;
};

using gsl_rng_ptr_t = std::unique_ptr< gsl_rng,
				       gsl_rng_deleter >;


#endif
