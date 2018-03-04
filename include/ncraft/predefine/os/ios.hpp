#ifndef NCRAFT_PREDEFINE_OS_IOS_HPP
#define NCRAFT_PREDEFINE_OS_IOS_HPP
/*
 * Copyright Rene Rivera 2008-2014
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */
#include <ncraft/predefine/version_number.hpp>

// clang-format off

#define NC_IOS_NAME "iOS"
#define NC_IOS NC_VERSION_NUMBER_NOT_AVAILABLE

#if !defined(NC_OS_DETECTED) && ( \
    defined(__APPLE__) && defined(__MACH__) && \
    defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) \
    )
#   undef NC_IOS
#   define NC_IOS (__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__*1000)

#   define NC_UNIX        1
#   define NC_BSD         1
#   define NC_OS_DETECTED 1
#endif

// clang-format on
#endif  // NCRAFT_PREDEFINE_OS_IOS_HPP
