cmake_minimum_required(VERSION 3.22)
project(as-c-math LANGUAGES C)

include(FetchContent)
include(GNUInstallDirs)

option(AS_MATH_ENABLE_TEST "Enable testing" ON)
option(AS_MATH_ENABLE_COVERAGE "Enable coverage" OFF)

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE as-ops.c)
target_include_directories(
  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>
                         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/>)
target_compile_features(${PROJECT_NAME} PRIVATE c_std_99)
target_link_libraries(${PROJECT_NAME} PRIVATE $<$<C_COMPILER_ID:GNU>:-lm>)

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

install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}-config
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(EXPORT ${PROJECT_NAME}-config
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})
install(FILES ${CMAKE_CURRENT_LIST_DIR}/as-types.h
              ${CMAKE_CURRENT_LIST_DIR}/as-ops.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
