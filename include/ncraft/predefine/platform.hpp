#ifndef NCRAFT_PREDEFINE_PLATFORM_HPP
#define NCRAFT_PREDEFINE_PLATFORM_HPP

#include <ncraft/predefine/architecture.hpp>
#include <ncraft/predefine/compiler.hpp>
#include <ncraft/predefine/os.hpp>

// clang-format off

#if NC_WINDOWS

// Verify that we're built with the multithreaded
// versions of the runtime libraries
#   if NC_MSVC && !defined(_MT)
#       error Must compile with /MD, /MDd, /MT or /MTd
#   endif

#   if defined(_WIN32)
#       ifndef _WIN32_WINNT
#           define _WIN32_WINNT 0x0501
#       endif
#       ifndef WIN32_LEAN_AND_MEAN
#           define WIN32_LEAN_AND_MEAN
#       endif
#   endif

// Turn off some annoying warnings
#   if NC_MSVC
#       pragma warning(disable : 4018)  // signed/unsigned comparison
#       pragma warning(disable : 4251)  // ... needs to have dll-interface warning
#       pragma warning(disable : 4355)  // 'this' : used in base member initializer list
#       pragma warning(disable : 4996)  // VC++ 8.0 deprecation warnings
#       pragma warning(disable : 4351)  // new behavior: elements of array '...' will be default initialized
#       pragma warning(disable : 4675)  // resolved overload was found by argument-dependent lookup
#       pragma warning(disable : 4275)  // non dll-interface class 'std::exception' used as base for dll-interface class 'Poco::Exception'
#   endif
#endif

// Check debug/release settings consistency
#if defined(NDEBUG) && defined(_DEBUG)
#   error Inconsistent build settings (check for /MD[d])
#endif

#if defined(DEBUG) || defined(_DEBUG) || !defined(NDEBUG) || !defined(_NDEBUG)
#   define NC_DEBUG 1
#endif

// clang-format on

#endif  // NCRAFT_PREDEFINE_PLATFORM_HPP
