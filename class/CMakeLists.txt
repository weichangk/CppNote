cmake_minimum_required(VERSION 3.5)
project(class LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "d:/Qt/5.15.2/msvc2019_64")

aux_source_directory(./src src)
aux_source_directory(./src/01 01)
aux_source_directory(./src/02 02)
# Specify MSVC UTF-8 encoding
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(${PROJECT_NAME}
  ${src}
  ${01}
  ${02}
)
