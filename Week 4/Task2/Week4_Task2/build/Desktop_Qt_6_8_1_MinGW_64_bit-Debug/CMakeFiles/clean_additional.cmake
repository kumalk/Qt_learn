# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Week4_Task2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Week4_Task2_autogen.dir\\ParseCache.txt"
  "Week4_Task2_autogen"
  )
endif()
