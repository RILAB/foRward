#ifndef __POPGENMUT_HPP__
#define __POPGENMUT_HPP__
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
#include <iosfwd>

namespace foRward {
  struct popgenmut : public KTfwd::mutation_base
  {
    double s,h;
    unsigned o;
    using base = KTfwd::mutation_base;
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

  /*
    The function objects below allow an object of type popgenmut to be serialized to/from binary
    ouptut/input streams.

    The function objects are non-template, and the definition of their operator()
    are found in popgenmut.cc
  */
  struct popgenMutWriter
  {
    typedef void result_type;
    result_type operator()( const popgenmut & m, std::ostream & buffer ) const;
  };

  struct popgenMutReader
  {
    typedef popgenmut result_type;
    result_type operator()( std::istream & buffer ) const;
  };
}
#endif
