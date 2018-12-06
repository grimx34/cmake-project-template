cmake_minimum_required(VERSION 3.8)
project(CppLib VERSION 0.0.1)
# dependencies
#find_package(Foo 1.0 REQUIRED)
# library definition
add_library(${CMAKE_PROJECT_NAME} lib_source.cpp lib_source.h include/CppLib/lib_header.h)
target_compile_features(${CMAKE_PROJECT_NAME} PUBLIC cxx_std_17)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
 $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
 $<INSTALL_INTERFACE:include>
)
#target_link_libraries(CppLib PRIVATE Foo::Foo)



add_library(Company::${CMAKE_PROJECT_NAME} ALIAS ${CMAKE_PROJECT_NAME})

install(TARGETS ${CMAKE_PROJECT_NAME} EXPORT ${CMAKE_PROJECT_NAME}Targets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)
install(EXPORT ${CMAKE_PROJECT_NAME}Targets
        DESTINATION lib/cmake/${CMAKE_PROJECT_NAME}
        FILE ${CMAKE_PROJECT_NAME}Targets.cmake
        NAMESPACE Company::)
install(DIRECTORY include/${CMAKE_PROJECT_NAME}
        DESTINATION include)
include(CMakePackageConfigHelpers)

write_basic_package_version_file(${CMAKE_PROJECT_NAME}ConfigVersion.cmake
                                 COMPATIBILITY SameMajorVersion)
install(FILES CppLibConfig.cmake ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
        DESTINATION lib/cmake/${CMAKE_PROJECT_NAME})