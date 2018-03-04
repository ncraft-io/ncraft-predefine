cmake_minimum_required(VERSION 3.2)
project(ncraft-predefine)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/cmake)
#include(NcSourceDirectory)
#include(NcOSX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

# Where ncraft's .hpp files can be found.
INCLUDE_DIRECTORIES(
    ${PROJECT_SOURCE_DIR}/include
)

if(OSX)
set(CXX_FLAGS "-std=c++14 -stdlib=libc++ -DLEVELDB_PLATFORM_POSIX -DOS_MACOSX -g -DDEBUG -DNC_USE_ASIO -fno-limit-debug-info")
else(OSX)
set(CXX_FLAGS "-std=c++14 -DLEVELDB_PLATFORM_POSIX -g -DDEBUG -DNC_USE_ASIO")
endif(OSX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  ${CXX_FLAGS}")