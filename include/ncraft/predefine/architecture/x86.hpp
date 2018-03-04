#ifndef NCRAFT_PREDEFINE_ARCHITECTURE_X86_HPP
#define NCRAFT_PREDEFINE_ARCHITECTURE_X86_HPP
/*
 * Copyright Rene Rivera 2008-2014
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */
#include <ncraft/predefine/version_number.hpp>

// clang-format off

#define NC_X86_32_NAME "Intel x86-32"
#define NC_X86_64_NAME "Intel x86-64"

#define NC_X86_32 NC_VERSION_NUMBER_NOT_AVAILABLE
#define NC_X86_64 NC_VERSION_NUMBER_NOT_AVAILABLE

#define NC_X86 NC_VERSION_NUMBER_NOT_AVAILABLE
#define NC_X64 NC_VERSION_NUMBER_NOT_AVAILABLE

#if defined(i386) || defined(__i386__) || \
    defined(__i486__) || defined(__i586__) || \
    defined(__i686__) || defined(__i386) || \
    defined(_M_IX86) || defined(_X86_) || \
    defined(__THW_INTEL__) || defined(__I86__) || \
    defined(__INTEL__)
#   undef NC_X86_32
#   if !defined(NC_X86_32) && defined(__I86__)
#       define NC_X86_32 NC_VERSION_NUMBER(__I86__,0,0)
#   endif
#   if !defined(NC_X86_32) && defined(_M_IX86)
#       define NC_X86_32 BOOST_PREDEF_MAKE_10_VV00(_M_IX86)
#   endif
#   if !defined(NC_X86_32) && defined(__i686__)
#       define NC_X86_32 NC_VERSION_NUMBER(6,0,0)
#   endif
#   if !defined(NC_X86_32) && defined(__i586__)
#       define NC_X86_32 NC_VERSION_NUMBER(5,0,0)
#   endif
#   if !defined(NC_X86_32) && defined(__i486__)
#       define NC_X86_32 NC_VERSION_NUMBER(4,0,0)
#   endif
#   if !defined(NC_X86_32) && defined(__i386__)
#       define NC_X86_32 NC_VERSION_NUMBER(3,0,0)
#   endif
#   if !defined(NC_X86_32)
#       define NC_X86_32 NC_VERSION_NUMBER_AVAILABLE
#   endif
#   define NC_X86 NC_X86_32
#elif defined(__x86_64) || defined(__x86_64__) || \
      defined(__amd64__) || defined(__amd64) || \
      defined(_M_X64)
#   undef NC_X86_64
#   define NC_X86_64 NC_VERSION_NUMBER_AVAILABLE
#   define NC_X64 NC_X86_64
#endif

#if NC_X86_32 && NC_X86_64
#   define NC_LITTLE_ENDIAN 1
#endif

// clang-format on

#endif  // NCRAFT_PREDEFINE_ARCHITECTURE_X86_HPP
