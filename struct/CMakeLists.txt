cmake_minimum_required(VERSION 3.5)
project(struct LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "d:/Qt/5.15.2/mingw81_64")

aux_source_directory(./src SRCS)

add_executable(${PROJECT_NAME}
  ${SRCS}
)
