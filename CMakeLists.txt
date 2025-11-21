cmake_minimum_required(VERSION 3.22.1...3.31.7 )
project(hello_c_project LANGUAGES C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}}/bin/$<CONFIGURATION>")
set(UNITY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/unity")
set(BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build")
# this is a placeholder for when migrating the build system to ninja, currently MSVC does NOT support
# using compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()
