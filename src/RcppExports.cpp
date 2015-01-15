// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// makeGSLrng
SEXP makeGSLrng(const unsigned& seed);
RcppExport SEXP foRward_makeGSLrng(SEXP seedSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< const unsigned& >::type seed(seedSEXP );
        SEXP __result = makeGSLrng(seed);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// sampleStd
Rcpp::List sampleStd(SEXP pop, SEXP rng, const unsigned& nsam, const bool& remove_fixed = false);
RcppExport SEXP foRward_sampleStd(SEXP popSEXP, SEXP rngSEXP, SEXP nsamSEXP, SEXP remove_fixedSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< SEXP >::type pop(popSEXP );
        Rcpp::traits::input_parameter< SEXP >::type rng(rngSEXP );
        Rcpp::traits::input_parameter< const unsigned& >::type nsam(nsamSEXP );
        Rcpp::traits::input_parameter< const bool& >::type remove_fixed(remove_fixedSEXP );
        Rcpp::List __result = sampleStd(pop, rng, nsam, remove_fixed);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// evolveStd
SEXP evolveStd(SEXP rng, const unsigned& N0, const double& mu_n, const double& mu_s, const double& s, const double& h, const double& littler, const Rcpp::IntegerVector& Ns, const bool& dist = true);
RcppExport SEXP foRward_evolveStd(SEXP rngSEXP, SEXP N0SEXP, SEXP mu_nSEXP, SEXP mu_sSEXP, SEXP sSEXP, SEXP hSEXP, SEXP littlerSEXP, SEXP NsSEXP, SEXP distSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< SEXP >::type rng(rngSEXP );
        Rcpp::traits::input_parameter< const unsigned& >::type N0(N0SEXP );
        Rcpp::traits::input_parameter< const double& >::type mu_n(mu_nSEXP );
        Rcpp::traits::input_parameter< const double& >::type mu_s(mu_sSEXP );
        Rcpp::traits::input_parameter< const double& >::type s(sSEXP );
        Rcpp::traits::input_parameter< const double& >::type h(hSEXP );
        Rcpp::traits::input_parameter< const double& >::type littler(littlerSEXP );
        Rcpp::traits::input_parameter< const Rcpp::IntegerVector& >::type Ns(NsSEXP );
        Rcpp::traits::input_parameter< const bool& >::type dist(distSEXP );
        SEXP __result = evolveStd(rng, N0, mu_n, mu_s, s, h, littler, Ns, dist);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
// writeStdToFile
unsigned long writeStdToFile(SEXP pop, const char * filename, const bool append = false, const bool lock = false);
RcppExport SEXP foRward_writeStdToFile(SEXP popSEXP, SEXP filenameSEXP, SEXP appendSEXP, SEXP lockSEXP) {
BEGIN_RCPP
    SEXP __sexp_result;
    {
        Rcpp::RNGScope __rngScope;
        Rcpp::traits::input_parameter< SEXP >::type pop(popSEXP );
        Rcpp::traits::input_parameter< const char * >::type filename(filenameSEXP );
        Rcpp::traits::input_parameter< const bool >::type append(appendSEXP );
        Rcpp::traits::input_parameter< const bool >::type lock(lockSEXP );
        unsigned long __result = writeStdToFile(pop, filename, append, lock);
        PROTECT(__sexp_result = Rcpp::wrap(__result));
    }
    UNPROTECT(1);
    return __sexp_result;
END_RCPP
}
