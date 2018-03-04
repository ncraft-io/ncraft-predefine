#ifndef NCRAFT_PREPROCESSOR_HPP
#define NCRAFT_PREPROCESSOR_HPP
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
// @author: Andrei Alexandrescu

#include <ncraft/predefine/platform.hpp>

/**
 * Necessarily evil preprocessor-related amenities.
 */

/**
 * NCRAFT_ONE_OR_NONE(hello, world) expands to hello and
 * NCRAFT_ONE_OR_NONE(hello) expands to nothing. This macro is used to
 * insert or eliminate text based on the presence of another argument.
 */
#if NC_MSVC

#define VA_NARGS_IMPL(_1, _2, _3, _4, _5, N, ...) N
#define VA_NARGS(...) VA_NARGS_IMPL(X, ##__VA_ARGS__, 4, 3, 2, 1, 0)
#define VARARG_IMPL2(base, count, ...) base##count(__VA_ARGS__)
#define VARARG_IMPL(base, count, ...) VARARG_IMPL2(base, count, __VA_ARGS__)
#define VARARG(base, ...) VARARG_IMPL(base, VA_NARGS(__VA_ARGS__), __VA_ARGS__)

#define NC_ONE_OR_NONE0()  /* */
#define NC_ONE_OR_NONE1(x) /* */
#define NC_ONE_OR_NONE2(x, y) x
#define NC_ONE_OR_NONE3(x, y, z) x
#define NC_ONE_OR_NONE(...) VARARG(NC_ONE_OR_NONE, __VA_ARGS__)

#else

#define NC_ONE_OR_NONE(a, ...) NC_THIRD(a, ##__VA_ARGS__, a)
#define NC_THIRD(a, b, ...) __VA_ARGS__

#endif

/**
 * Helper macro that extracts the first argument out of a list of any
 * number of arguments.
 */
#define NC_ARG_1(a, ...) a

/**
 * Helper macro that extracts the second argument out of a list of any
 * number of arguments. If only one argument is given, it returns
 * that.
 */
#define NC_ARG_2_OR_1(...) NC_ARG_2_OR_1_IMPL(__VA_ARGS__, __VA_ARGS__)
// Support macro for the above
#define NC_ARG_2_OR_1_IMPL(a, b, ...) b

/**
 * Helper macro that provides a way to pass argument with commas in it to
 * some other macro whose syntax doesn't allow using extra parentheses.
 * Example:
 *
 *   #define MACRO(type, name) type name
 *   MACRO(NC_SINGLE_ARG(std::pair<size_t, size_t>), x);
 *
 */
#define NC_SINGLE_ARG(...) __VA_ARGS__

/**
 * NC_ANONYMOUS_VARIABLE(str) introduces an identifier starting with
 * str and ending with a number that varies with the line.
 */
#ifndef NC_ANONYMOUS_VARIABLE
#define NC_CONCATENATE_IMPL(s1, s2) s1##s2
#define NC_CONCATENATE(s1, s2) NC_CONCATENATE_IMPL(s1, s2)
#ifdef __COUNTER__
#define NC_ANONYMOUS_VARIABLE(str) NC_CONCATENATE(str, __COUNTER__)
#else
#define NC_ANONYMOUS_VARIABLE(str) NC_CONCATENATE(str, __LINE__)
#endif
#endif

/**
 * Use NC_STRINGIZE(x) when you'd want to do what #x does inside
 * another macro expansion.
 */
#define NC_STRINGIZE(x) #x

#endif  // NCRAFT_PREPROCESSOR_HPP
