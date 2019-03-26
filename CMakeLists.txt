cmake_minimum_required(VERSION 3.13)

project(codeforces LANGUAGES C CXX)

include(cmake/all.cmake)

option(BUILD_SOLVED "Build solved" OFF)
if(BUILD_SOLVED)
  add_subdirectory(problemset)
endif()

add_subdirectory(dev)
