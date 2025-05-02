CMAKE_MINIMUM_REQUIRED(VERSION 3.31)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(cpp_stuff CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(project_settings INTERFACE)

if(MSVC)
    target_compile_options(project_settings INTERFACE /W4 /WX)
else()
    target_compile_options(project_settings INTERFACE -Wall -Wextra -Wpedantic -Werror)
endif()

find_package(Catch2)

add_subdirectory(apps)
add_subdirectory(lib)
add_subdirectory(test)