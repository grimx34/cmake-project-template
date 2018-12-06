cmake_minimum_required(VERSION 3.8)
project(CppLibTests)

enable_testing()
find_package(GTest MODULE REQUIRED)
if(NOT TARGET Company::CppLib)
    find_package(CppLib CONFIG REQUIRED)
endif()

add_executable(${CMAKE_PROJECT_NAME} tests_source.cpp)
target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_17)
target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE
        Company::CppLib
        GTest::Main
)
add_test(NAME CppLib.UnitTests
    COMMAND ${CMAKE_PROJECT_NAME}
)
