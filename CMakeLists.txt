cmake_minimum_required(VERSION 3.14)
project(TW)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(tests)

include(conanbuildinfo.cmake)
conan_basic_setup()


add_executable(TW main.cpp lib/Math.cpp lib/Math.h lib/Circle.cpp lib/Circle.h)
target_link_libraries(TW ${CONAN_LIBS})


