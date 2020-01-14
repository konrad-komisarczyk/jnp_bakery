cmake_minimum_required(VERSION 3.7)
project(jnp1zad4)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES bakery.h pie.h cake.h)
add_executable(testing test.cc ${SOURCE_FILES})