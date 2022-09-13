cmake_minimum_required(VERSION 3.16.3)


project(postfix_to_infix)

set(SOURCE_EXE main.cxx)

add_library(infix_to_postfix STATIC infix_to_postfix.cxx postfix_to_infix.cxx is_in.cxx)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_EXE})

target_link_libraries(${CMAKE_PROJECT_NAME} infix_to_postfix)

