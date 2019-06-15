cmake_minimum_required(VERSION 3.14)
project(HelloTest)

set(CMAKE_CXX_STANDARD 14)
enable_testing()

add_test(test test_math.cpp)
include(../conanbuildinfo.cmake)
conan_basic_setup()

add_executable(HelloTest
        setup.cpp
        test_circle.cpp
        ../lib/Circle.cpp
        ../lib/Circle.h)
target_link_libraries(HelloTest ${CONAN_LIBS})
