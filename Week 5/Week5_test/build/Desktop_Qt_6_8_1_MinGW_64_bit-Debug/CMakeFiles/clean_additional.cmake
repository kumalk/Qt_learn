# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Week5_test_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Week5_test_autogen.dir\\ParseCache.txt"
  "Week5_test_autogen"
  )
endif()
