cmake_minimum_required(VERSION 3.10)

project(project_name)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(coffee-shop)

enable_testing() 

add_subdirectory(src)
add_subdirectory(tests)
