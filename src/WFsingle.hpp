#ifndef __FORWARD_WFSINGLE_HPP__
#define __FORWARD_WFSINGLE_HPP__

#include <SinglePop.hpp>
#include <popgenmut.hpp>

extern template class SinglePop<popgenmut>;

using WFsingle = SinglePop<popgenmut>;
//template<> RCPP_EXPOSED_CLASS(SinglePop<popgenmut>);

#endif
