#ifndef NCRAFT_PREDEFINE_OS_FREE_BSD_HPP
#define NCRAFT_PREDEFINE_OS_FREE_BSD_HPP
/*
 * Copyright Rene Rivera 2008-2014
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */
#include <ncraft/predefine/version_number.hpp>

// clang-format off

#define NC_FREE_BSD_NAME "Free BSD"
#define NC_FREE_BSD BOOST_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(NC_OS_DETECTED) && (defined(__FreeBSD__))
#   undef NC_FREE_BSD
#   if defined(__FreeBSD_version)
#       define V __FreeBSD_version
#       if V < 500000
#           define NC_FREE_BSD NC_VERSION_NUMBER(((V)/100000)%10,((V)/10000)%10,((V)/1000)%10)
#       else
#           define NC_FREE_BSD NC_VERSION_NUMBER(((V)/100000)%10,((V)/1000)%100,0)
#       endif
#   else
#       define NC_FREE_BSD NC_VERSION_NUMBER_AVAILABLE
#   endif

#   define NC_UNIX        1
#   define NC_BSD         1
#   define NC_OS_DETECTED 1
#endif

// clang-format on
#endif  // NCRAFT_PREDEFINE_OS_FREE_BSD_HPP
