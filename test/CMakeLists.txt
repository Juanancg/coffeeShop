cmake_minimum_required(VERSION 3.9)

include_directories(${PROJECT_SOURCE_DIR}/include)


SET(SOURCE_FILES
    main_uts.cpp
    tests_OrderManager.cpp
    tests_CSVParser.cpp

    ../src/OrderManager.cpp  
    ../src/menu_parsers/CSVParser.cpp 
)

SET(HEADER_FILES
    tests_OrderManager.h 
    tests_CSVParser.h

)

add_executable(
    ${PROJECT_NAME}_test
    ${HEADER_FILES}
    ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}_test PUBLIC   
    gtest
    pthread
)