cmake_minimum_required(VERSION 3.8) # can be lowered to 3.2 when c++14
project(CLionProjectWithGTest)

### Set default build type ###
if (NOT EXISTS ${CMAKE_BINARY_DIR}/CMakeCache.txt)
	if (NOT CMAKE_BUILD_TYPE)
		set(CMAKE_BUILD_TYPE "Release" CACHE STRING "" FORCE)
	endif()
endif()

### Basic settings ###
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES )
set(TESTS_SOURCE_FILES )

### Basic target - Terminal Snake ###
add_executable(CLionProjectWithGTest src/main.cpp ${SOURCE_FILES})

### Run target ###
add_custom_target(run
		COMMAND CLionProjectWithGTest
		DEPENDS CLionProjectWithGTest
		WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

if (CMAKE_BUILD_TYPE MATCHES "Debug" OR CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
	### Basic settings for Debug ###
	add_definitions(
			-Wall
			-Wextra
			-Wpedantic
			-Wfatal-errors
	)

	### Unit test target (only for Debug and RelWithDebInfo) ###
	find_package(Threads REQUIRED)

	add_subdirectory(googletest)
	include_directories(${GTEST_SOURCE_DIR}/include ${GTEST_SOURCE_DIR})

	add_executable(UnitTests ${TESTS_SOURCE_FILES} ${SOURCE_FILES})

	target_link_libraries(UnitTests gtest gmock gtest_main Threads::Threads ${CURSES_LIBRARIES})

	enable_testing()
	add_test(AllTests UnitTests)

	### Run unit test target (only for Debug and RelWithDebInfo) ###
	add_custom_target(runUnitTests
			COMMAND UnitTests
			DEPENDS UnitTests
			WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
	)
endif()

### Install target (only for Release and MinSizeRel) ###
install(TARGETS CLionProjectWithGTest
		DESTINATION bin
		CONFIGURATIONS Release MinSizeRel
)

### Change install location to './nope/' to prevent accidental installation of gtest (for Debug and RelWithDebInfo) ###
if (CMAKE_BUILD_TYPE MATCHES "Debug" OR CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
	set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/nope CACHE PATH "install here" FORCE)
endif()
