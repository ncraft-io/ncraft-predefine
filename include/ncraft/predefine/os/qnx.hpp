#ifndef NCRAFT_PREDEFINE_OS_QNX_HPP
#define NCRAFT_PREDEFINE_OS_QNX_HPP
/*
 * Copyright Rene Rivera 2008-2014
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */
#include <ncraft/predefine/version_number.hpp>

// clang-format off

#define NC_QNX_NAME "QNX"
#define NC_QNX NC_VERSION_NUMBER_NOT_AVAILABLE


#if !defined(NC_OS_DETECTED) && (defined(__QNX__) || defined(__QNXNTO__))
#   undef NC_QNX
#   if !defined(NC_QNX) && defined(_NTO_VERSION)
#       define NC_QNX NC_VERSION_NUMBER(((_NTO_VERSION)/100)%100, (_NTO_VERSION)%100, 0)
#   endif
#   if !defined(NC_QNX) && defined(__QNX__)
#       define NC_QNX NC_VERSION_NUMBER(4,0,0)
#   endif
#   if !defined(NC_QNX)
#       define NC_QNX NC_VERSION_NUMBER_AVAILABLE
#   endif

#   define NC_UNIX_FAMILY 1
#   define NC_OS_DETECTED 1
#endif

// clang-format on

#endif  // NCRAFT_PREDEFINE_OS_QNX_HPP
