#ifndef NCRAFT_PREDEFINE_COMPILER_GCC_HPP
#define NCRAFT_PREDEFINE_COMPILER_GCC_HPP
/*
 * Copyright Rene Rivera 2008-2014
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <ncraft/predefine/version_number.hpp>
#include <ncraft/predefine/compiler/clang.hpp>

// clang-format off

#define NC_GCC_NAME "Gnu GCC C/C++"
#define NC_GCC NC_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__GNUC__)
#   if defined(__GNUC_PATCHLEVEL__)
#       define NC_GCC_DETECTION NC_VERSION_NUMBER(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#   else
#       define NC_GCC_DETECTION NC_VERSION_NUMBER(__GNUC__, __GNUC_MINOR__, 0)
#   endif
#endif

#ifdef NC_GCC_DETECTION
#   if defined(NC_COMPILER_DETECTED)
#       define NC_GCC_EMULATED NC_GCC_DETECTION
#   else
#       undef NC_GCC
#       undef NC_COMPILER_DETECTED
#       define NC_GCC NC_GCC_DETECTION
#       define NC_COMPILER_DETECTED 1
#   endif
#endif

// clang-format on

#endif  // NCRAFT_PREDEFINE_COMPILER_GCC_HPP
