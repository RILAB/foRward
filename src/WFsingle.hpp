#ifndef __FORWARD_WFSINGLE_HPP__
#define __FORWARD_WFSINGLE_HPP__
/*
  A structure representing a single Wright-Fisher population.
  The user initizializes it with a population size, N
*/

#include <popgenmut.hpp> //this already includes fwdpp/forward_types.hpp, giving us access to KTfwd::gamete_base
#include <fwdpp/fwd_functional.hpp> //for KTfwd::equal_eps
//use boost containers
#include <boost/container/list.hpp>
#include <boost/container/vector.hpp>
#include <boost/pool/pool_alloc.hpp>
#include <boost/unordered_set.hpp>
#include <boost/functional/hash.hpp>
#include <RcppCommon.h>

class WFsingle
{
public:
  unsigned N;

  //Typedefs for various containers
  using mtype = popgenmut;
  using mut_allocator = boost::pool_allocator<mtype>;
  using mlist = boost::container::list<mtype,mut_allocator >;
  using gtype = KTfwd::gamete_base<mtype,mlist>;
  using gam_allocator = boost::pool_allocator<gtype>;
  using glist =  boost::container::list<gtype,gam_allocator >;
  using mvector = boost::container::vector<mtype>;
  using ftvector = boost::container::vector<unsigned>;
  using lookup_table_type = boost::unordered_set<double,boost::hash<double>,KTfwd::equal_eps >;
  using dipvector = std::vector< std::pair<glist::iterator,glist::iterator> >;

  //Data types -- the names should make the above typedefs a bit more clear
  mlist mutations;
  glist gametes;
  dipvector diploids;
  lookup_table_type mut_lookup;
  mvector fixations;
  ftvector fixation_times;

  //Constructors
  WFsingle( const unsigned & popsize );

  //Helper functions
  mlist::size_type nmuts() const;
};

RCPP_EXPOSED_CLASS(WFsingle);

#endif

#include <Rcpp.h>
