cmake_minimum_required(VERSION 3.13)
project(demo)

add_subdirectory(platform)
add_subdirectory(boards)
add_subdirectory(mcu)

add_library(app OBJECT main.cpp)
target_link_libraries(app PRIVATE platform board)

add_executable(app_k64f $<TARGET_OBJECTS:app>)
target_link_libraries(app_k64f PRIVATE app board_k64f)

add_executable(app_disco $<TARGET_OBJECTS:app>)
target_link_libraries(app_disco PRIVATE app board_disco_l475_iot01a)
