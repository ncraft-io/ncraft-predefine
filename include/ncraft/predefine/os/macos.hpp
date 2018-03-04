#ifndef NCRAFT_PREDEFINE_OS_MACOS_HPP
#define NCRAFT_PREDEFINE_OS_MACOS_HPP
/*
 * Copyright Rene Rivera 2008-2014
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <ncraft/predefine/os/macos.hpp>
#include <ncraft/predefine/version_number.hpp>

// clang-format off

#define NC_MACOS_NAME "Mac OS"
#define NC_MACOS NC_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(NC_OS_DETECTED) && (defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__)))
#   undef NC_MACOS
#   if !defined(NC_MACOS) && defined(__APPLE__) && defined(__MACH__)
#       define NC_MACOS NC_VERSION_NUMBER(10, 0, 0)
#   endif
#   if !defined(NC_MACOS)
#       define NC_MACOS NC_VERSION_NUMBER(9, 0, 0)
#   endif

#   define NC_UNIX        1
#   define NC_BSD         1
#   define NC_OS_DETECTED 1
#endif

// clang-format on

#endif  // NCRAFT_PREDEFINE_OS_MACOS_HPP
