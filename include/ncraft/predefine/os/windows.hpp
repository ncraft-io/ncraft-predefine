#ifndef NCRAFT_PREDEFINE_OS_WINDOWS_HPP
#define NCRAFT_PREDEFINE_OS_WINDOWS_HPP
/*
 * Copyright Rene Rivera 2008-2014
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <ncraft/predefine/version_number.hpp>

// clang-format off

#define NC_WINDOWS_NAME "Microsoft Windows"
#define NC_WINDOWS NC_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(NC_OS_DETECTED) && ( \
    defined(_WIN32) || defined(_WIN64) || \
    defined(__WIN32__) || defined(__TOS_WIN__) || \
    defined(__WINDOWS__) \
    )
#   undef NC_WINDOWS
#   define NC_WINDOWS NC_VERSION_NUMBER_AVAILABLE

#   define NC_OS_DETECTED 1
#endif

// clang-format on

#endif  // NCRAFT_PREDEFINE_OS_WINDOWS_HPP
