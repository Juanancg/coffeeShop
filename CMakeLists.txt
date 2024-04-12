cmake_minimum_required(VERSION 3.9)


# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(coffee_shop)

# set complie warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function")

find_package(GTest REQUIRED)

include_directories(
        ${GTEST_INCLUDE_DIRS}
        include
)


SET(SOURCE_FILES
    src/OrderManager.cpp
    src/main.cpp
)

SET(HEADER_FILES
    src/OrderManager.h
)


add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME})

enable_testing()

add_subdirectory(test)


# install(DIRECTORY include/ DESTINATION include)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)