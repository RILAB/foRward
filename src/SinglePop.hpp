#ifndef __FORWARD_SINGLEPOP_HPP__
#define __FORWARD_SINGLEPOP_HPP__
/*
  A structure representing a single Wright-Fisher population.
  The user initizializes it with a population size, N
*/

#include <fwdpp/forward_types.hpp>
#include <fwdpp/fwd_functional.hpp> //for KTfwd::equal_eps
//use boost containers
#include <boost/container/list.hpp>
#include <boost/container/vector.hpp>
#include <boost/pool/pool_alloc.hpp>
#include <boost/unordered_set.hpp>
#include <boost/functional/hash.hpp>

/*
  Abstraction of what is needed to simulate a single population
  using an individual-based sampler from fwdpp

  All that is missing is the mutation_type.

  This uses boost containers so that the rapid boost::pool_allocator
  may be used.
 */
template<typename mutation_type>
class SinglePop
{
public:
  unsigned N;

  //Typedefs for various container
  using mtype = mutation_type;
  using mut_allocator = boost::pool_allocator<mtype>;
  using mlist = boost::container::list<mtype,mut_allocator >;
  using gtype = KTfwd::gamete_base<mtype,mlist>;
  using gam_allocator = boost::pool_allocator<gtype>;
  using glist =  boost::container::list<gtype,gam_allocator >;
  using mvector = boost::container::vector<mtype>;
  using ftvector = boost::container::vector<unsigned>;
  using lookup_table_type = boost::unordered_set<double,boost::hash<double>,KTfwd::equal_eps >;
  using dipvector = std::vector< std::pair<typename glist::iterator,typename glist::iterator> >;

  //Data types -- the names should make the above typedefs a bit more clear
  mlist mutations;
  glist gametes;
  dipvector diploids;
  lookup_table_type mut_lookup;
  mvector fixations;
  ftvector fixation_times;

  //Constructors
  SinglePop( const unsigned & popsize ) : N(popsize),
					  mutations(mlist()),                //No muts in the population
					  gametes(glist(1,gtype(2*popsize))), //The population contains a single gamete in 2N copies
					  diploids(dipvector(popsize,std::make_pair(gametes.begin(),gametes.begin()))), //All N diploids contain the only gamete in the pop
					  mut_lookup(lookup_table_type()),
					  fixations(mvector()),
					  fixation_times(ftvector())
  {
  }
};

#endif

