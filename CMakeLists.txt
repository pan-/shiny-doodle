cmake_minimum_required(VERSION 3.13)

add_library(A a.cpp)
add_library(B b.cpp)
target_link_libraries(A B)
target_link_libraries(B A)

add_executable(app_ab main.cpp)
target_link_libraries(app_ab A)
add_executable(app_ba main.cpp)
target_link_libraries(app_ba B)
