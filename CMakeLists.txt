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
    src/main.cpp

    src/ui/ShellUI.cpp
    src/OrderManager.cpp

    src/storage/DiskStorage.cpp

    src/types/Order.cpp
    src/types/Beverage.cpp

    src/menu_parsers/CSVParser.cpp
)
    
SET(HEADER_FILES
    src/ui/ShellUI.h
    src/ui/UIiface.h

    src/OrderManager.h

    src/storage/DiskStorage.h
    src/storage/IOrderStorage.h


    src/types/Order.h
    src/types/Beverage.h

    src/menu_parsers/MenuParserFactory.h
    src/menu_parsers/CSVParser.h
    src/menu_parsers/IMenuParser.h
)


add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME})

enable_testing()

add_subdirectory(test)


# install(DIRECTORY include/ DESTINATION include)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)