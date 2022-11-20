cmake_minimum_required(VERSION 3.22)
project(as-c-math LANGUAGES C)

include(FetchContent)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE as-ops.c)
target_include_directories(
  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_99)

option(AS_MATH_ENABLE_TEST "Enable testing" OFF)

if(AS_MATH_ENABLE_TEST)
  FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG 67ca5c57c9c50cc1580518cc6f822558c0009b1e)
  FetchContent_MakeAvailable(unity)
  add_executable(${PROJECT_NAME}-test)
  target_sources(${PROJECT_NAME}-test PRIVATE test.c)
  target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME} unity)
  target_compile_features(${PROJECT_NAME}-test PRIVATE c_std_99)
endif()
