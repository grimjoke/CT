# boilerplate
cmake_minimum_required(VERSION 3.16.3)
project(cmake_test VERSION 0.1.0)



add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC Adder)

target_link_directories(${PROJECT_NAME} PRIVATE Adder)


add_subdirectory(Adder)

target_link_libraries(${PROJECT_NAME} adder)