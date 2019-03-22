cmake_minimum_required(VERSION 3.13)

project(codeforces LANGUAGES C CXX)

include(cmake/all.cmake)

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/problemset/*/*.cpp  ${CMAKE_CURRENT_SOURCE_DIR}/problemset/*/*.c)
foreach(source ${sources})
  get_filename_component(prog ${source} NAME_WE)
  add_executable(${prog} ${source})
endforeach()
