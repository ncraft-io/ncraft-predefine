#ifndef NCRAFT_PREDEFINE_OS_LINUX_HPP
#define NCRAFT_PREDEFINE_OS_LINUX_HPP
/*
 * Copyright Rene Rivera 2008-2014
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */
#include <ncraft/predefine/version_number.hpp>

// clang-format off

#define NC_LINUX_NAME "Linux"
#define NC_LINUX NC_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(NC_OS_DETECTED) && (defined(linux) || defined(__linux))
#   undef NC_LINUX
#   define NC_LINUX NC_VERSION_NUMBER_AVAILABLE
#   define NC_UNIX        1
#   define NC_OS_DETECTED 1
#endif

// clang-format on

#endif  // NCRAFT_PREDEFINE_OS_LINUX_HPP
