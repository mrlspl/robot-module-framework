cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++11")


project(robot-module-framework)


include_directories(include)

add_library(robot_module_frameworkSHARED ${SOURCES} include/Node.hpp include/Master.hpp src/Route.hpp)

install(TARGETS robot_module_framework DESTINATION robot-module-framework)

file(GLOB HEADERS ./include/Master.hpp ./include/Node.hpp)
install(FILES ${HEADERS} DESTINATION include/robot-module-framework)

find_package(PythonInterp)
find_package(CxxTest REQUIRED)

if(CXXTEST_FOUND)
	include_directories(${CXXTEST_INCLUDE_DIR})
	enable_testing()
	CXXTEST_ADD_TEST(testrunner unit-test/main.cpp
                        ${CMAKE_CURRENT_SOURCE_DIR}/unit-test/HelloWorldTestSuite.h)
endif()





