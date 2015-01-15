#ifndef __FORWARD_SINGLEPOP_SERIALIZATION_HPP__
#define __FORWARD_SINGLEPOP_SERIALIZATION_HPP__

#include <foRward/SinglePop.hpp>
#include <fwdpp/IO.hpp>
#include <Rcpp.h>
#include <iosfwd>
namespace foRward {

  template<typename mutation_type>
  struct SerializeSinglePop {
    template<typename writer_type>
    inline void operator()(SEXP pop,
			   const writer_type & wt,
			   std::ostream & o ) const
    {
      using poptype = SinglePop<mutation_type>;
      Rcpp::XPtr< poptype > ppop(pop);
      //Step 1: write the mutations, diploids, gametes to the stream
      KTfwd::write_binary_pop( &ppop->gametes,&ppop->mutations,&ppop->diploids,wt,o );
    }
  };
}

#endif
