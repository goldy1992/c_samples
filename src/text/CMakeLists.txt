cmake_minimum_required(VERSION 3.22.1...3.31.7 )


set(EXECUTABLE_NAME "text")

set(SOURCES)
list( APPEND SOURCES
    main.c 
)

add_executable(${EXECUTABLE_NAME} ${SOURCES})



target_include_directories( ${EXECUTABLE_NAME} PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}  
)



