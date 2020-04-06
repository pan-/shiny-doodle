cmake_minimum_required(VERSION 3.13)

add_library(A STATIC a.cpp)
add_library(B STATIC b.cpp)

add_executable(app_ab main.cpp)
target_link_libraries(app_ab PRIVATE A B)
add_executable(app_ba main.cpp)
target_link_libraries(app_ba PRIVATE B A)
