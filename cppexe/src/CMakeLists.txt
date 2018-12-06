cmake_minimum_required(VERSION 3.8)
project(CppExe VERSION 0.0.1)

# dependencies
find_package(CppLib 0.0.1 REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

target_link_libraries(${CMAKE_PROJECT_NAME} Intrasonics::CppLib)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                           $<INSTALL_INTERFACE:include>
)

install(TARGETS ${CMAKE_PROJECT_NAME} EXPORT ${CMAKE_PROJECT_NAME}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)