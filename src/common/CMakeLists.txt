cmake_minimum_required(VERSION 3.22.1...3.31.7 )


set(LIBRARY_NAME "common")
set(SOURCES)
list( APPEND SOURCES
    common.h
)

add_library(${LIBRARY_NAME} INTERFACE ${SOURCES})

target_compile_features(${LIBRARY_NAME} INTERFACE c_std_90)


target_include_directories( ${LIBRARY_NAME} INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}#/common.h 
)




