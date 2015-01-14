#ifndef __FORWARD_WFSINGLE_HPP__
#define __FORWARD_WFSINGLE_HPP__

#include <foRward/SinglePop.hpp>
#include <foRward/popgenmut.hpp>

//Single Wright-Fisher pop, mutations have an s and h associated with them
//This using declaration is an template alias/typedef
//and is NOT sufficient to define the type.  In order to provide a
//definition of the type, we must explicitly instantiate it,
//which we'll do in standard_model.cc
namespace foRward {
  using WFpop_std = SinglePop<popgenmut>;
}

#endif
