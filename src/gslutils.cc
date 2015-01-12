#include <gslutils.hpp>

void gsl_rng_deleter::operator()( gsl_rng * r ) noexcept 
{
  gsl_rng_free(r);
}
