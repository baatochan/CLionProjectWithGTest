cmake_minimum_required(VERSION 3.10)
project(CLionProjectWithGTest)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.hpp" "src/*.cpp")
file(GLOB TEST_SOURCES "tests/*.hpp" "tests/*.cpp")

add_subdirectory(googletest)
add_subdirectory(src)
add_subdirectory(tests)
