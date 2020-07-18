cmake_minimum_required(VERSION 3.8)
project(iptablescpp VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

include_directories(${PROJECT_SOURCE_DIR}/include)

###########################################
# Library
###########################################
add_library(${PROJECT_NAME}_obj OBJECT
    src/Address.cpp
    src/Chain.cpp
    src/ChainMap.cpp
    src/IpTablesWrapper.cpp
    src/Rule.cpp
    src/RuleMap.cpp
)

target_include_directories(${PROJECT_NAME}_obj
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_property(TARGET ${PROJECT_NAME}_obj PROPERTY POSITION_INDEPENDENT_CODE ON)

###########################################
# UNIT Test
###########################################
add_executable(run-tests
    $<TARGET_OBJECTS:${PROJECT_NAME}_obj>
    tests/AddressTest.cpp
    tests/ChainMapTest.cpp
    tests/ChainTest.cpp
    tests/IpTablesWrapperTest.cpp
    tests/MainTest.cpp
    tests/RuleMapTest.cpp
    tests/RuleTest.cpp
)

target_include_directories(run-tests
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)