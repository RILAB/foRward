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

struct WFsingle
{
  unsigned N;

  //Typedefs for various containers
  using mut_allocator = boost::pool_allocator<popgenmut>;
  using mlist = boost::container::list<popgenmut,mut_allocator >;
  using gtype = KTfwd::gamete_base<popgenmut,mlist>;
  using gam_allocator = boost::pool_allocator<gtype>;
  using glist =  boost::container::list<gtype,gam_allocator >;
  using mvector = boost::container::vector<popgenmut>;
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
};
