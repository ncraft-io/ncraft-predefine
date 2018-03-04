#ifndef NCRAFT_PREDEFINE_COMPILER_CLANG_HPP
#define NCRAFT_PREDEFINE_COMPILER_CLANG_HPP
/*
 * Copyright Rene Rivera 2008-2014
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

// clang-format off

#define NC_CLANG NC_VERSION_NUMBER_NOT_AVAILABLE
#define NC_CLANG_NAME "Clang"

#if defined(__clang__)
#   define NC_CLANG_DETECTION NC_VERSION_NUMBER(__clang_major__, __clang_minor__, __clang_patchlevel__)
#endif

#ifdef NC_CLANG_DETECTION
#   if defined(NC_COMPILER_DETECTED)
#       define NC_CLANG_EMULATED NC_CLANG_DETECTION
#   else
#       undef NC_CLANG
#       undef NC_COMPILER_DETECTED
#       define NC_CLANG NC_CLANG_DETECTION
#       define NC_COMPILER_DETECTED 1
#   endif
#endif

// clang-format on

#endif  // NCRAFT_PREDEFINE_COMPILER_CLANG_HPP
