# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TestMsgBox_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TestMsgBox_autogen.dir\\ParseCache.txt"
  "TestMsgBox_autogen"
  )
endif()
