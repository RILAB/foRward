#include <WFsingle.hpp>
#include <Rcpp.h>
#include <algorithm>
#include <fwdpp/diploid.hh>
#include <gslutils.hpp>
#include <popgenmutmodel.hpp>

// [[Rcpp::plugins(cpp11)]]

//' Evolve a single population under multiplicative fitness and arbitrary changes in N
//' @param pop An object of type WFsingle
//' @param mu_n The neutral mutation rate (per gamete per generation)
//' @param mu_n The mutation rate to selected mutations (per gamete per generation)
//' @param s The selection coefficient (for fixed-s models), or the mean of an exponential (for models with a distribution)
//' @param h The dominance of a selected mutation
//' @param littler The recombination rate (per diploid, per generation). 
//' @param Ns A list of populaton sizes.  The length of the list is the number of generations to simulate
//' @param seed Random number seed for the simulation
//' @param dist If true, simulate a distribution of fitness effects, otherwise treat s as fixed
//[[Rcpp::export]]
SEXP evolveWFsingle(const unsigned & N0,
		    const double & mu_n,
		    const double & mu_s,
		    const double & s,
		    const double & h,
		    const double & littler,
		    const Rcpp::IntegerVector & Ns,
		    const unsigned long & seed,
		    const bool & dist = true)
{
  Rcpp::XPtr<WFsingle> ppop(new WFsingle(N0));
  gsl_rng_ptr_t r( gsl_rng_alloc(gsl_rng_taus2) );
  gsl_rng_set(r.get(),seed);

  //define the genetic map
  std::function<double(void)> recmap = std::bind(gsl_rng_uniform,r.get());

  unsigned generation =  0;
  for( const auto & nextN : Ns )
    {
      double wbar = KTfwd::sample_diploid(r.get(),
					  &ppop->gametes,  //non-const pointer to gametes
					  &ppop->diploids, //non-const pointer to diploids
					  &ppop->mutations, //non-const pointer to mutations
					  ppop->N,     //current pop size
					  nextN,       //pop size in next gen
					  mu_n+mu_s,    //mutation rate per gamete
					  /*
					    The mutation model (defined above) will pass each gamete
					    to be mutated to the mutation model function.  Again, _1
					    is used as a placeholder for that gamete.
					  */
					  //std::bind(neutral_mutations_inf_sites,r,generation,std::placeholders::_1,&lookup),
					  std::bind(popgen_mutation_model(),r.get(),generation,s,h,mu_s,mu_n,&ppop->mut_lookup,dist),
					  //The recombination policy includes the uniform crossover rate
					  std::bind(KTfwd::genetics101(),std::placeholders::_1,std::placeholders::_2,
						    &ppop->gametes,
						    littler,
						    r.get(),
						    recmap),
					  /*
					    Policy to insert new mutations at the end of the mutations list
					  */
					  std::bind(KTfwd::insert_at_end<WFsingle::mtype,WFsingle::mlist>,std::placeholders::_1,std::placeholders::_2),
					  /*
					    Policy telling KTfwd::mutate how to add mutated gametes into the gamete pool.
					    If mutation results in a new gamete, add that gamete to the 
					    end of gametes. This is always the case under infinitely-many sites,
					    but for other mutation models, mutation may result in a new
					    copy identical to an existing gamete.  If so,
					    that gamete's frequency increases by 1.
					  */
					  std::bind(KTfwd::insert_at_end<WFsingle::gtype,WFsingle::glist>,std::placeholders::_1,std::placeholders::_2),
					  /*
					    Fitness is multiplicative over sites.
					    
					    The fitness model takes two gametes as arguments.  
					    The gametes are passed to this function by 
					    KTfwd::sample_diploid, and the _1 and _2 are placeholders for
					    those gametes (see documentation for boost/bind.hpp for details).
					    The 2. means that fitnesses are 1, 1+sh, and 1+2s for genotypes
					    AA, Aa, and aa, respectively, where a is a mutation with
					    selection coefficient s and dominance h, and the fitness of 
					    the diploid is the product of fitness over sites

					    There is no selection in this simulation, but this
					    function is called anyways to illustrate it as multiplicative
					    models are very common in population genetics
					  */
					  std::bind(KTfwd::multiplicative_diploid(),std::placeholders::_1,std::placeholders::_2,2.),
					  /*
					    For each gamete still extant after sampling,
					    remove the pointers to any mutations that have 
					    been fixed or lost from the population.
					 
					    For more complex models such as quantitative
					    traits evolving towards an optimum, one may not
					    with to remove fixations.  In that case,
					    replace the line below with
					    std::bind(KTfwd::mutation_remover(),std::placeholders::_1,twoN));

					    Under multiplicative fitness and Wright-Fisher sampling
					    proportional to relative fitness, fixed mutations
					    are just a constant applied to everyone's fitness, so we 
					    can remove them, making the simulation faster, etc.
					  */
					  std::bind(KTfwd::mutation_remover(),std::placeholders::_1,0,2*nextN));
      KTfwd::remove_fixed_lost(&ppop->mutations,&ppop->fixations,&ppop->fixation_times,&ppop->mut_lookup,generation,2*nextN);

      //update current pop size
      ppop->N = nextN;
    }
  return ppop;
}

