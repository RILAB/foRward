#ifndef __FORWARD_WFSINGLE_HPP__
#define __FORWARD_WFSINGLE_HPP__

#include <SinglePop.hpp>
#include <popgenmut.hpp>

 class WFsingle : public SinglePop<popgenmut>
 {
 public:
   using baseClass = SinglePop<popgenmut>;
   using baseClass::baseClass;
 };

RCPP_EXPOSED_CLASS(WFsingle);

#endif
