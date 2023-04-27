cmake_minimum_required(VERSION 3.5)

project(06_homework LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(06_homework main.cpp base_container.h sequence_container.cpp list_container.cpp list_container_oneDir.cpp iterator.cpp)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(06_homework PRIVATE -Wall -Wextra -Werror -pedantic)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(06_homework PRIVATE /EHsc /W4 /WX)

 endif()



