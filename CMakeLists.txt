cmake_minimum_required(VERSION 3.5)

project(
  CppNoteProj
  VERSION 1.0
  DESCRIPTION "cpp note project"
  LANGUAGES CXX)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)
install(TARGETS ${PROJECT_NAME})

# Specify MSVC UTF-8 encoding
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
