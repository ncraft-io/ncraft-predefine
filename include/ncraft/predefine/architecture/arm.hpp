#ifndef NCRAFT_PREDEFINE_ARCHITECTURE_ARM_HPP
#define NCRAFT_PREDEFINE_ARCHITECTURE_ARM_HPP
/*
 * Copyright Rene Rivera 2008-2014
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <ncraft/predefine/version_number.hpp>

// clang-format off

#define NC_ARM_NAME "ARM"
#define NC_ARM NC_VERSION_NUMBER_NOT_AVAILABLE

#if defined(__arm__) || defined(__arm64) || defined(__thumb__) || \
    defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_M_ARM)
#   undef NC_ARM
#   if !defined(NC_ARM) && defined(__arm64)
#       define NC_ARM NC_VERSION_NUMBER(8, 0, 0)
#   endif
#   if !defined(NC_ARM) && defined(__TARGET_ARCH_ARM)
#       define NC_ARM NC_VERSION_NUMBER(__TARGET_ARCH_ARM, 0, 0)
#   endif
#   if !defined(NC_ARM) && defined(__TARGET_ARCH_THUMB)
#       define NC_ARM NC_VERSION_NUMBER(__TARGET_ARCH_THUMB, 0, 0)
#   endif
#   if !defined(NC_ARM) && defined(_M_ARM)
#       define NC_ARM NC_VERSION_NUMBER(_M_ARM, 0, 0)
#   endif
#   if !defined(NC_ARM)
#       define NC_ARM NC_VERSION_NUMBER_AVAILABLE
#   endif
#endif

#if NC_ARM
#   if defined(__ARMEB__)
#       define NC_BIG_ENDIAN 1
#   else
#       define NC_LITTLE_ENDIAN 1
#endif

// clang-format on

#endif  // NCRAFT_PREDEFINE_ARCHITECTURE_ARM_HPP
