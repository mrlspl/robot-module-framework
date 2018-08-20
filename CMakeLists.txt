cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}-std=c++11")


project(robot-module-framework)
file(GLOB SOURCES ./src/Master.cpp)


include_directories(include)

add_library(robot-module-framework SHARED ${SOURCES})

install(TARGETS robot-module-framework DESTINATION src/robot-module-framework)

file(GLOB HEADERS ./src/Route.hpp ./include/Master.hpp ./include/Node.hpp)
install(FILES ${HEADERS} DESTINATION include/robot-module-framework)

find_package(PythonInterp)



find_package(CxxTest REQUIRED)

#if(CXXTEST_FOUND)
#	include_directories(${CXXTEST_INCLUDE_DIR})
#	enable_testing()
#	CXXTEST_ADD_TEST(testrunner unit-test/main.cpp
#			${CMAKE_SOURCE_DIR}/src/HelloWorld.cpp
#                       ${CMAKE_CURRENT_SOURCE_DIR}/unit-test/HelloWorldTestSuite.h)
#endif()


# add a target to generate API documentation with Doxygen
find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if(BUILD_DOCUMENTATION)
    if(NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${doxyfile_in} ${doxyfile} @ONLY)

    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION share/doc)
endif()
