cmake_minimum_required(VERSION 3.13)
project(wave-table)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window audio network system)

file(GLOB_RECURSE sources "src/*")

add_executable(${PROJECT_NAME} ${sources})
target_compile_options(${PROJECT_NAME} PUBLIC -Wall)
target_include_directories(${PROJECT_NAME} PUBLIC "include/")
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)