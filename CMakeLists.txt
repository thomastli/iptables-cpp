cmake_minimum_required(VERSION 3.8)
project(iptablescpp VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

###########################################
# Executable
###########################################
add_library(${PROJECT_NAME}_obj OBJECT
    src/IpRule.cpp
    src/IpTablesMap.cpp
)

add_executable(${PROJECT_NAME}
    $<TARGET_OBJECTS:${PROJECT_NAME}_obj>
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)

###########################################
# UNIT Test
###########################################
add_executable(run-tests
    $<TARGET_OBJECTS:${PROJECT_NAME}_obj>
    tests/IpRuleTest.cpp
    tests/IpTablesMapTest.cpp
)

target_link_libraries(run-tests
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/tests
)