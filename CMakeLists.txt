cmake_minimum_required(VERSION 3.26)

project(codeforces LANGUAGES C CXX)

include(cmake/all.cmake)

option(BUILD_SOLVED "Build solved" OFF)
if(BUILD_SOLVED)
  add_subdirectory(problemset)
endif()

add_subdirectory(dev)
add_custom_target(fix_comment
	#  COMMAND [=[ grep '"file":' ./compile_commands.json | gsed -e 's/"file"://' | xargs -I source_file bash -c 'gsed -e "/\* .file/s/file .*/file "$(basename source_file)"/" -i source_file ' ]=]
	COMMAND [=[ grep '"file":' ./compile_commands.json | gsed -e 's/"file"://' | xargs -I source_file bash -c 'gsed -e "/\* .brief/s#problem/.*#problem/"$(basename source_file ".cpp"  | gsed -e "s#[A-Z]#/&#" )"#" -i source_file ' ]=]
  DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  )
