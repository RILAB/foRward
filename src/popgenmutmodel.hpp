/*
  Generate popgenmuts under the infinitely-many sites mutation schemt
 */

#include <popgenmut.hpp>

struct popgen_mutation_model
{
  using result_type =  popgenmut;
  template<typename lookup_table_type>
  inline result_type operator()( gsl_rng * r, 
				 const unsigned int & ttl_generations,
				 const double & s, 
				 const double & h,
				 const double & ud, 
				 const double & un,
				 lookup_table_type * lookup,
				 const bool dist_effects = false) const
  {
    //Use hash to make sure that new mutation position does not currently exist in pop
    double pos = gsl_rng_uniform(r);
    while(lookup->find(pos) != lookup->end())
      {
	pos = gsl_rng_uniform(r);
      }
    lookup->insert(pos);

    //Check if new mutation is selected or neutral
    if( gsl_rng_uniform(r) <= ud/(ud+un) )
      {
	if( ! dist_effects )
	  {
	    return result_type(pos,1,false,s,h,ttl_generations);
	  }
	else
	  {
	    return result_type(pos,1,false,gsl_ran_exponential(r,s),h,ttl_generations);
	  }
      }
    //If not selected, return a neutral mutation
    return result_type(pos,1,true,0.,0.,ttl_generations);
  }
};
