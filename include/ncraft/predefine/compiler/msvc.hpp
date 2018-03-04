#ifndef NCRAFT_PREDEFINE_COMPILER_MSVC_HPP
#define NCRAFT_PREDEFINE_COMPILER_MSVC_HPP
/*
 * Copyright Rene Rivera 2008-2014
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <ncraft/predefine/compiler/clang.hpp>
#include <ncraft/predefine/version_number.hpp>

// clang-format off

#define BOOST_COMP_MSVC_NAME "Microsoft Visual C/C++"
#define NC_MSVC NC_VERSION_NUMBER_NOT_AVAILABLE

#if defined(_MSC_VER)
#   if !defined (_MSC_FULL_VER)
#       define NC_MSVC_BUILD 0
#   else
        /* how many digits does the build number have? */
#       if _MSC_FULL_VER / 10000 == _MSC_VER
            /* four digits */
#           define NC_MSVC_BUILD (_MSC_FULL_VER % 10000)
#       elif _MSC_FULL_VER / 100000 == _MSC_VER
            /* five digits */
#           define NC_MSVC_BUILD (_MSC_FULL_VER % 100000)
#       else
#           error "Cannot determine build number from _MSC_FULL_VER"
#       endif
#   endif
#   define NC_MSVC_DETECTION NC_VERSION_NUMBER(_MSC_VER/100-6, _MSC_VER%100, NC_MSVC_BUILD)
#endif

#ifdef NC_MSVC_DETECTION
#   if defined(NC_COMPILER_DETECTED)
#       define NC_MSVC_EMULATED NC_MSVC_DETECTION
#   else
#       undef NC_MSVC
#       undef NC_COMPILER_DETECTED
#       define NC_MSVC NC_MSVC_DETECTION
#       define NC_COMPILER_DETECTED 1
#   endif
#endif

// clang-format on

#endif  // NCRAFT_PREDEFINE_COMPILER_MSVC_HPP
