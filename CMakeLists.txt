cmake_minimum_required(VERSION 3.10)

project(app LANGUAGES C)

add_subdirectory(appio)
add_subdirectory(appui)

add_executable(myapp myapp.c)

target_link_libraries(myapp appio)
target_link_libraries(myapp appui)

target_include_directories(myapp PRIVATE appio appui)

install(TARGETS myapp DESTINATION bin)

