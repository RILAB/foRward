#include <Rcpp.h>
#include <singlepop.hpp>

WFsingle::WFsingle ( const unsigned & popsize ) : N(popsize),
						  mutations(mlist()),                //No muts in the population
						  gametes(glist(1,gtype(2*popsize))), //The population contains a single gamete in 2N copies
						  diploids(dipvector(popsize,std::make_pair(gametes.begin(),gametes.begin()))), //All N diploids contain the only gamete in the pop
						  mut_lookup(lookup_table_type()),
						  fixations(mvector()),
						  fixation_times(ftvector())
{
}
