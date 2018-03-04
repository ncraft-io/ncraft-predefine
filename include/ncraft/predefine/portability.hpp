#ifndef NCRAFT_PORTABILITY_HPP
#define NCRAFT_PORTABILITY_HPP
/*
 * Copyright 2014 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <ncraft/predefine/platform.hpp>

// clang-format off

/* Define a convenience macro to test when address sanitizer is being used
 * across the different compilers (e.g. clang, gcc) */
#if defined(__clang__)
#   if __has_feature(address_sanitizer)
#       define NC_SANITIZE_ADDRESS 1
#   endif
#elif defined(__GNUC__) &&                                             \
    (((__GNUC__ == 4) && (__GNUC_MINOR__ >= 8)) || (__GNUC__ >= 5)) && \
    __SANITIZE_ADDRESS__
#   define NC_SANITIZE_ADDRESS 1
#endif

/* Define attribute wrapper for function attribute used to disable
 * address sanitizer instrumentation. Unfortunately, this attribute
 * has issues when inlining is used, so disable that as well. */
#ifdef NC_SANITIZE_ADDRESS
#   if defined(__clang__)
#       if __has_attribute(__no_address_safety_analysis__)
#           define NC_DISABLE_ADDRESS_SANITIZER \
                __attribute__((__no_address_safety_analysis__, __noinline__))
#       elif __has_attribute(__no_sanitize_address__)
#           define NC_DISABLE_ADDRESS_SANITIZER \
                __attribute__((__no_sanitize_address__, __noinline__))
#       endif
#   elif defined(__GNUC__)
#       define NC_DISABLE_ADDRESS_SANITIZER \
            __attribute__((__no_address_safety_analysis__, __noinline__))
#   endif
#endif

#ifndef NC_DISABLE_ADDRESS_SANITIZER
#define NC_DISABLE_ADDRESS_SANITIZER
#endif

// MaxAlign: max_align_t isn't supported by gcc
#ifdef __GNUC__
struct MaxAlign {
    char c;
} __attribute__((__aligned__));
#else /* !__GNUC__ */
#error Cannot define MaxAlign on this platform
#endif

// compiler specific attribute translation
// msvc should come first, so if clang is in msvc mode it gets the right defines

// NOTE: this will only do checking in msvc with versions that support /analyze
#if _MSC_VER
#   ifdef _USE_ATTRIBUTES_FOR_SAL
#       undef _USE_ATTRIBUTES_FOR_SAL
#   endif
#   define _USE_ATTRIBUTES_FOR_SAL 1
#   include <sal.hpp>
#   define NC_PRINTF_FORMAT _Printf_format_string_
#   define NC_PRINTF_FORMAT_ATTR(format_param, dots_param) /**/
#else
#   define NC_PRINTF_FORMAT /**/
#   define NC_PRINTF_FORMAT_ATTR(format_param, dots_param) \
        __attribute__((__format__(__printf__, format_param, dots_param)))
#endif

// noreturn
#if defined(_MSC_VER)
#   define NC_NORETURN __declspec(noreturn)
#elif defined(__clang__) || defined(__GNUC__)
#   define NC_NORETURN __attribute__((__noreturn__))
#else
#   define NC_NORETURN
#endif

// noinline
#ifdef _MSC_VER
#   define NC_NOINLINE __declspec(noinline)
#elif defined(__clang__) || defined(__GNUC__)
#   define NC_NOINLINE __attribute__((__noinline__))
#else
#   define NC_NOINLINE
#endif

// always inline
#if NC_MSVC
#   define NC_ALWAYS_INLINE __forceinline
#elif NC_CLANG || NC_GCC
#   define NC_ALWAYS_INLINE inline __attribute__((__always_inline__))
#else
#   define NC_ALWAYS_INLINE
#endif

// packing is very ugly in msvc
#ifdef _MSC_VER
#   define NC_PACK_ATTR /**/
#   define NC_PACK_PUSH __pragma(pack(push, 1))
#   define NC_PACK_POP __pragma(pack(pop))
#elif defined(__clang__) || defined(__GNUC__)
#   define NC_PACK_ATTR __attribute__((__packed__))
#   define NC_PACK_PUSH /**/
#   define NC_PACK_POP  /**/
#else
#   define NC_PACK_ATTR /**/
#   define NC_PACK_PUSH /**/
#   define NC_PACK_POP  /**/
#endif

// portable version check
#ifndef __GNUC_PREREQ
#   if defined __GNUC__ && defined __GNUC_MINOR__
#       define __GNUC_PREREQ(maj, min) \
            ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))
#   else
#       define __GNUC_PREREQ(maj, min) 0
#   endif
#endif

/* Platform specific TLS support
 * gcc implements __thread
 * msvc implements __declspec(thread)
 * the semantics are the same (but remember __thread is broken on apple)
 */
#if defined(_MSC_VER)
#   define NC_TLS __declspec(thread)
#elif defined(__GNUC__) || defined(__clang__)
#   define NC_TLS __thread
#else
#   error cannot define platform specific thread local storage
#endif

// Define to 1 if you have the `preadv' and `pwritev' functions, respectively
#if !defined(NC_HAVE_PREADV) && !defined(NC_HAVE_PWRITEV)
#   if defined(__GLIBC_PREREQ)
#       if __GLIBC_PREREQ(2, 10)
#           define NC_HAVE_PREADV 1
#           define NC_HAVE_PWRITEV 1
#       endif
#   endif
#endif

// Some platforms lack clock_gettime(2) and clock_getres(2). Inject our own
// versions of these into the global namespace.
//#if NC_HAVE_CLOCK_GETTIME
//#include <time.hpp>
//#else
//#include <folly/detail/Clock.hpp>
//#endif

// Provide our own std::__throw_* wrappers for platforms that don't have them
//#if NC_HAVE_BITS_FUNCTEXCEPT_HPP
//#include <bits/functexcept.hpp>
//#else
//#include <folly/detail/FunctionalExcept.hpp>
//#endif

#if defined(__cplusplus)
// Unfortunately, boost::has_trivial_copy<T> is broken in libc++ due to its
// usage of __has_trivial_copy(), so we can't use it as a
// least-common-denominator for C++11 implementations that don't support
// std::is_trivially_copyable<T>.
//
//      http://stackoverflow.com/questions/12754886/has-trivial-copy-behaves-differently-in-clang-and-gcc-whos-right
//
// As a result, use std::is_trivially_copyable() where it exists, and fall back
// to Boost otherwise.
#if NC_HAVE_STD__IS_TRIVIALLY_COPYABLE
#include <type_traits>
#define NC_IS_TRIVIALLY_COPYABLE(T) (std::is_trivially_copyable<T>::value)
#else
#include <boost/type_traits.hpp>
#define NC_IS_TRIVIALLY_COPYABLE(T) \
    (boost::has_trivial_copy<T>::value && boost::has_trivial_destructor<T>::value)
#endif
#endif  // __cplusplus


// MSVC specific defines
// mainly for posix compat
#if NC_MSVC

// this definition is in a really silly place with a silly name
// and ifdefing it every time we want it is painful
#include <basetsd.hpp>
typedef SSIZE_T ssize_t;

// sprintf semantics are not exactly identical
// but current usage is not a problem
#define snprintf _snprintf

#define strtoll _strtoi64

#define strtoull _strtoui64

// semantics here are identical
#define strerror_r(errno, buf, len) strerror_s(buf, len, errno)

// compiler specific to compiler specific
#define __PRETTY_FUNCTION__ __FUNCSIG__

#endif

// clang-format on

#endif  // NCRAFT_PORTABILITY_HPP
