#ifndef NCRAFT_PREDEFINE_VERSION_NUMBER_HPP
#define NCRAFT_PREDEFINE_VERSION_NUMBER_HPP
/*
 * Copyright Rene Rivera 2005, 2008-2013
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

/*`
[heading `BOOST_VERSION_NUMBER`]

``
BOOST_VERSION_NUMBER(major,minor,patch)
``

Defines standard version numbers, with these properties:

* Decimal base whole numbers in the range \[0,1000000000).
  The number range is designed to allow for a (2,2,2) triplet.
  Which fits within a 32 bit value.
* The `major` number can be in the \[0,99\] range.
* The `minor` number can be in the \[0,99\] range.
* The `patch` number can be in the \[0,99\] range.
* Values can be specified in any base. As the defined value
  is an constant expression.
* Value can be directly used in both preprocessor and compiler
  expressions for comparison to other similarly defined values.
* The implementation enforces the individual ranges for the
  major, minor, and patch numbers. And values over the ranges
  are truncated (modulo).
*/

#define NC_VERSION_NUMBER(major, minor, patch) \
    ((((major) % 100) * 10000) + (((minor) % 100) * 100) + ((patch) % 100))

#define NC_VERSION_NUMBER_MAX NC_VERSION_NUMBER(99, 99, 99)

#define NC_VERSION_NUMBER_ZERO NC_VERSION_NUMBER(0, 0, 0)

#define NC_VERSION_NUMBER_MIN NC_VERSION_NUMBER(0, 0, 1)

#define NC_VERSION_NUMBER_AVAILABLE NC_VERSION_NUMBER_MIN

#define NC_VERSION_NUMBER_NOT_AVAILABLE NC_VERSION_NUMBER_ZERO

#endif  // NCRAFT_PREDEFINE_VERSION_NUMBER_HPP
