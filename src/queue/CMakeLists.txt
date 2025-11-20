cmake_minimum_required(VERSION 3.22.1...3.31.7 )


set(LIBRARY_NAME "queue")

set(SOURCES)
list( APPEND SOURCES
    # headers
	queue.h
    # source files
	queue.c
)

add_library(${LIBRARY_NAME} ${SOURCES})



target_include_directories( ${LIBRARY_NAME} PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}  
)
target_link_libraries( ${LIBRARY_NAME} 
   memory_arena 
)


