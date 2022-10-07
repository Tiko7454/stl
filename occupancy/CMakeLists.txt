cmake_minimum_required(VERSION 3.10.0)


project(occupancy)

set(SOURCE_EXE main.cxx)

add_library(sentence_word_counter STATIC sentence_word_counter.cxx)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_EXE})
target_link_libraries(${CMAKE_PROJECT_NAME} sentence_word_counter)
