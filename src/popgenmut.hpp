/*
  This file defines the type of mutation used in a typical popgen simulation.
  s = selection coefficient
  h = dominance
  o = generation when mutation first appeared in the population
*/

/*
  Typically, a user would include fwdpp/diploid.hh, which is the entire fwdpp library.
  Here, though, we just need to derive something from KTfwd::mutation_base,
  so we cheat a little and directly include the relevant header
 */
#include <fwdpp/forward_types.hpp>

struct popgenmut : public KTfwd::mutation_base
{
  double s,h;
  unsigned o;
  using base = KTfwd::mutation_base;
  //C++11: inherit constructors from the base class:
  using base::base;
  //Constructor -- the first three are the parameters for the base class
  popgenmut( const double & position, 
	     const unsigned & count,
	     const bool & isneutral,
	     const double & sel_coeff,
	     const double & dominance,
	     const unsigned & origin)
    //Initialize data (base class first), then the rest, in order declared above
    : KTfwd::mutation_base(position,count,isneutral),s(sel_coeff),h(dominance),o(origin)
  {
    //For efficiency, try not to initialize the data here!
  }
};
