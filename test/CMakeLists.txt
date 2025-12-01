cmake_minimum_required(VERSION 3.22.1...3.31.7 )

add_subdirectory(${UNITY_DIR} ${BUILD_DIR})

include(CTest)
set(TEST_QUEUE "test_queue")
add_executable(${TEST_QUEUE} 
    queue/test_queue.h 
    queue/test_queue.c 
)
target_include_directories( ${TEST_QUEUE} PUBLIC 
    ${UNITY_DIR}/src
    ${CMAKE_SOURCE_ROOT}/memory_arena
    ${CMAKE_SOURCE_ROOT}/queue
)
target_link_libraries(${TEST_QUEUE}
    memory_arena
    queue
    unity
)
add_test(
  NAME test_queue 
  COMMAND $<TARGET_FILE:${TEST_QUEUE}>
)


set(TEST_VECTOR "test_vector")
add_executable(${TEST_VECTOR} 
    vector/test_vector.h 
    vector/test_vector.c 
)
target_include_directories( ${TEST_QUEUE} PUBLIC 
    ${UNITY_DIR}/src
    ${CMAKE_SOURCE_ROOT}/memory_arena
    ${CMAKE_SOURCE_ROOT}/vector
)
target_link_libraries(${TEST_VECTOR}
    memory_arena
    vector
    unity
)
add_test(
  NAME test_vector
  COMMAND $<TARGET_FILE:${TEST_VECTOR}>
)