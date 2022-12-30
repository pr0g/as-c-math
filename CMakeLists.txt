cmake_minimum_required(VERSION 3.22)
project(as-c-math LANGUAGES C)

include(FetchContent)

option(AS_MATH_ENABLE_TEST "Enable testing" OFF)
option(AS_MATH_ENABLE_COVERAGE "Enable coverage" OFF)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE as-ops.c)
target_include_directories(
  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_99)

if(AS_MATH_ENABLE_COVERAGE)
  target_compile_options(${PROJECT_NAME} PRIVATE -fprofile-arcs -ftest-coverage)
  target_link_options(${PROJECT_NAME} PRIVATE -coverage)
endif()

if(AS_MATH_ENABLE_TEST)
  FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG 5a36b197fb34c0a77ac891c355596cb5c25aaf5b)
  FetchContent_MakeAvailable(unity)
  add_executable(${PROJECT_NAME}-test)
  target_sources(${PROJECT_NAME}-test PRIVATE test.c)
  target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME} unity)
  target_compile_features(${PROJECT_NAME}-test PRIVATE c_std_99)
  if(AS_MATH_ENABLE_COVERAGE)
    target_compile_options(${PROJECT_NAME}-test PRIVATE -fprofile-arcs
                                                        -ftest-coverage)
    target_link_options(${PROJECT_NAME}-test PRIVATE -coverage)
  endif()
endif()
