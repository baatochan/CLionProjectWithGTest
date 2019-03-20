cmake_minimum_required(VERSION 3.10)

find_package(Threads REQUIRED)
enable_testing()
include_directories(${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR})

add_executable(runAllTests ../gtest.cpp ${TEST_SOURCES} ${SOURCES})

target_link_libraries(runAllTests gtest gtest_main)
add_test(AllTests runAllTests)
