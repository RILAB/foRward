AC_PREREQ(2.59)
AC_INIT([foRward], 0.1.0)
AC_CONFIG_MACRO_DIR([m4])

CC=`R CMD config CC`
CPP=`R CMD config CPP`
CFLAGS=`R CMD config CFLAGS`
CPPFLAGS=`R CMD config CPPFLAGS`
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_LANG(C++)
AC_CHECK_HEADER(boost/container/vector.hpp,, [AC_MSG_ERROR([boost/container/vector.hpp not found])])
AC_CHECK_HEADER(boost/container/list.hpp,, [AC_MSG_ERROR([boost/container/list.hpp not found])])
AC_CHECK_HEADER(boost/pool/pool_alloc.hpp>,,[AC_MSG_ERROR([boost/pool/pool_alloc.hpp>])])
AC_CHECK_HEADER(boost/unordered_set.hpp>,,[AC_MSG_ERROR([boost/unordered_set.hpp>])])
AC_CHECK_HEADER(boost/functional/hash.hpp>,,[AC_MSG_ERROR([boost/functional/hash.hpp>])])
AC_CHECK_HEADER(boost/interprocess/sync/file_lock.hpp,, [AC_MSG_ERROR([boost/interprocess/sync/file_lock.hpp not found])])
AC_CHECK_HEADER(gsl/gsl_rng.h,,[AC_MSG_ERROR([gsl/gsl_rng.h not found.  Please install the GNU Scientific Library])])
AC_CHECK_HEADER(gsl/gsl_randist.h,,[AC_MSG_ERROR([gsl/gsl_rng.h not found.  Please install the GNU Scientific Library])])
AC_CHECK_HEADER(zlib.h,,[AC_MSG_ERROR([zlib.h not found.  zlib >= 1.2.5 is requred])])
CXXFLAGS=-std=c++11
AC_CHECK_HEADER(fwdpp/diploid.hh,,[AC_MSG_ERROR(fwdpp/diploid.hh  not found -- please install fwdpp)])
dnl check that libraries are accessible
AC_CHECK_LIB([z],gzungetc,,[AC_MSG_ERROR([zlib run time library not found])])
AC_CHECK_LIB([gslcblas],[cblas_dgemm],,[AC_MSG_ERROR([gslcblas run-time library not found])])
AC_CHECK_LIB([gsl],[gsl_blas_dgemm],,[AC_MSG_ERROR([gsl run-time library not found])])

AC_LANG_SAVE
          AC_LANG_CPLUSPLUS
          AC_REQUIRE_CPP
          AC_CHECK_LIB(sequence, main,,[AC_MSG_ERROR([libsequence runtime library does not seem to be here])])
          AC_CHECK_LIB(boost_system, main,,[AC_MSG_ERROR([boost_system runtime library does not seem to be here])])
AC_LANG_RESTORE

AC_CONFIG_FILES([src/Makevars])
AC_OUTPUT
