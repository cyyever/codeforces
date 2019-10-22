cmake_minimum_required(VERSION 3.13)

project(codeforces LANGUAGES C CXX)

include(cmake/all.cmake)

option(BUILD_SOLVED "Build solved" OFF)
if(BUILD_SOLVED)
  add_subdirectory(problemset)
endif()

add_subdirectory(dev)
#add_custom_target(fix_comment
#  COMMAND [=[ grep '"file":' ./compile_commands.json | sed -e 's/"file"://' | xargs -I source_file bash -c 'sed -e "/\* \\file/s/file .*/file "$(basename source_file)"/" -i source_file ' ]=]
#  DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
#  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
#  )
