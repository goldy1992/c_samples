cmake_minimum_required(VERSION 3.22.1...3.31.7 )


set(EXECUTABLE_NAME "app")

set(SOURCES)
list( APPEND SOURCES
    # headers
    main.c 
)

add_executable(${EXECUTABLE_NAME} ${SOURCES})



target_include_directories( ${EXECUTABLE_NAME} PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}  
    ${CMAKE_SOURCE_ROOT}/linked_list
    ${CMAKE_SOURCE_ROOT}/memory_arena
    ${CMAKE_SOURCE_ROOT}/hashmap
)

target_link_libraries(${EXECUTABLE_NAME}
    linked_list
    memory_arena
    hashmap
)


