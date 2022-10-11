cmake_minimum_required(VERSION 3.10.0)


project(postfix_to_infix)

set(SOURCE_EXE main.cxx)

add_library(convertors STATIC convertor.cxx infix_to_postfix_convertor.cxx postfix_to_infix_convertor.cxx)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_EXE})
target_link_libraries(${CMAKE_PROJECT_NAME} convertors)

