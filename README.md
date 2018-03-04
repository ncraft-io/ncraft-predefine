# The NCraft Project  - Network Application Library for modern C++

## Brief Introduce

The NCraft project is a network application framework for easy developmenting high performance and high scalability servers and clients.

It comes from [Netty](http://www.jboss.org/netty) project. The first version is almostly a translation of the Netty from java to c\+\+, this version is almost refactoried  using modern c\+\+.

## Dependence
1. [boost](www.boost.org)(required) 
   specially only need asio, context, coroutine
   crc and string_algo. And need compile file-path, context, coroutine
   libraries, others are headers only.
2. [google-perftools](code.google.com/p/google-perftools)(optional)
   using the tcmalloc to improve the memory operations.
3. [gtest](code.google.com/p/googletest)(optional)
   for unit test.
4. [protobuffer](http://code.google.com/p/protobuf)(optional)
   for protobuffer handle (currently have not integrated yet)


## Questions?
If you have any questions, please feel free to send mail to me 
(frankee.zhou at gmail).


## Acknowledgment
Thanks to [Trustin Lee](http://gleamynode.net/),
the Netty framework is like an art and so amazing.