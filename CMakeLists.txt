cmake_minimum_required(VERSION 3.14)
project(TW)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(tests)

include(conanbuildinfo.cmake)
conan_basic_setup()


add_executable(TW main.cpp lib/Board.cpp lib/Board.h lib/Display.cpp lib/Display.h lib/Game.cpp lib/Game.h)
target_link_libraries(TW ${CONAN_LIBS})


