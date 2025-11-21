cmake_minimum_required(VERSION 3.22.1...3.31.7 )

add_subdirectory(${UNITY_DIR} ${BUILD_DIR})
set(EXECUTABLE_NAME "unit_tests")

set(SOURCES)
list( APPEND SOURCES
    main.c 
    test_queue.c 
)

add_executable(${EXECUTABLE_NAME} ${SOURCES})

target_include_directories( ${EXECUTABLE_NAME} PUBLIC 
    Unity/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_ROOT}/linked_list
    ${CMAKE_SOURCE_ROOT}/memory_arena
    ${CMAKE_SOURCE_ROOT}/hashmap
    ${CMAKE_SOURCE_ROOT}/queue
)

target_link_libraries(${EXECUTABLE_NAME}
    linked_list
    memory_arena
    hashmap
    queue
    unity
)

# enable testing functionality
enable_testing()

# define tests
add_test(
  NAME unit_tests 
  COMMAND $<TARGET_FILE:${EXECUTABLE_NAME}>
)
