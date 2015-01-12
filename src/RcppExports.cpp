// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// evolveWFsingle
void evolveWFsingle(SEXP pop, const double& mu_n, const double& mu_s, const double& s, const double& h, const double& littler, const Rcpp::IntegerVector& Ns, const unsigned long& seed, const bool& dist = true);
RcppExport SEXP foRward_evolveWFsingle(SEXP popSEXP, SEXP mu_nSEXP, SEXP mu_sSEXP, SEXP sSEXP, SEXP hSEXP, SEXP littlerSEXP, SEXP NsSEXP, SEXP seedSEXP, SEXP distSEXP) {
BEGIN_RCPP
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< SEXP >::type pop(popSEXP );
        Rcpp::traits::input_parameter< const double& >::type mu_n(mu_nSEXP );
        Rcpp::traits::input_parameter< const double& >::type mu_s(mu_sSEXP );
        Rcpp::traits::input_parameter< const double& >::type s(sSEXP );
        Rcpp::traits::input_parameter< const double& >::type h(hSEXP );
        Rcpp::traits::input_parameter< const double& >::type littler(littlerSEXP );
        Rcpp::traits::input_parameter< const Rcpp::IntegerVector& >::type Ns(NsSEXP );
        Rcpp::traits::input_parameter< const unsigned long& >::type seed(seedSEXP );
        Rcpp::traits::input_parameter< const bool& >::type dist(distSEXP );
        evolveWFsingle(pop, mu_n, mu_s, s, h, littler, Ns, seed, dist);
    }
    return R_NilValue;
END_RCPP
}
