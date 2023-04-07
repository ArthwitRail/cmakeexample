cmake_minimum_required(VERSION 3.10)

project(app LANGUAGES C)


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
  message (STATUS "Defaulting build type to ${CMAKE_BUILD_TYPE}")
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_C_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O2")

enable_testing()

add_subdirectory(appio)
add_subdirectory(appui)

add_executable(myapp myapp.c)

target_link_libraries(myapp appio)
target_link_libraries(myapp appui)

target_include_directories(myapp PRIVATE appio appui)

install(TARGETS myapp DESTINATION dist/bin)

install(FILES myapp.c DESTINATION dist/bin)

install(DIRECTORY appio DESTINATION dist/bin/appiostuff)

add_test(apptest ${CMAKE_CTEST_COMMAND}
   --build-and-test "${CMAKE_SOURCE_DIR}/apptest"
                    "${CMAKE_BINARY_DIR}/apptest"
   --build-generator ${CMAKE_GENERATOR}
   --build-makeprogram ${CMAKE_MAKE_PROGRAM}
   --build-project apptest
   --debug
   --test-command apptest)
