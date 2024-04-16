cmake_minimum_required(VERSION 3.9)

include_directories(${PROJECT_SOURCE_DIR}/include)


SET(SOURCE_FILES
    main_uts.cpp
    # tests_OrderManager.cpp
    menu_parsers/tests_CSVParser.cpp
    utils/tests_StringUtils.cpp
    rules/tests_CannotHaveBoth.cpp

    # includes from main program
    ../src/menu_parsers/CSVParser.cpp 
    ../src/utils/StringUtils.cpp
)

SET(HEADER_FILES
    # tests_OrderManager.h 
    menu_parsers/tests_CSVParser.h
    utils/tests_StringUtils.h
    rules/tests_CannotHaveBoth.h

    # includes from main program
    ../src/utils/StringUtils.h
    ../src/rules/CannotHaveBoth.h
)

add_executable(
    ${PROJECT_NAME}_test
    ${HEADER_FILES}
    ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}_test PUBLIC   
    gtest
    pthread
)