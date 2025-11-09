cmake_minimum_required(VERSION 3.22.1...3.31.7 )


set(LIBRARY_NAME "hashmap")

set(SOURCES)
list( APPEND SOURCES
    hashmap.h
    hashmap.c
    # main.c 
)

add_library(${LIBRARY_NAME} ${SOURCES})



target_include_directories( ${LIBRARY_NAME} PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}  
)



