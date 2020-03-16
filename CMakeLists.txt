cmake_minimum_required(VERSION 3.13)

# The interface shares only the symbol name without providing a dummy implementation 
add_library(mbed_overrides INTERFACE)
target_sources(mbed_overrides INTERFACE mbed_overrides.h)

# a vendor can still depend on this if they don't want to implement something specific
add_library(mbed_overrides_default)
target_sources(mbed_overrides_default PRIVATE mbed_overrides.cpp)

# platform requires mbed_overrides which is only an interface
add_library(platform)
target_link_libraries(platform PRIVATE mbed_overrides)
target_sources(platform PRIVATE platform.cpp)
target_sources(platform PRIVATE platform.h)

add_library(freescale_xpresso_k64f)
target_sources(freescale_xpresso_k64f PRIVATE mcu.cpp)
target_sources(freescale_xpresso_k64f PRIVATE mcu.h)

add_library(board_k64f)
target_link_libraries(board_k64f PRIVATE freescale_xpresso_k64f)
target_sources(board_k64f PRIVATE board.cpp)
target_sources(board_k64f PRIVATE board.h)

add_library(board_disco_l475_iot01a)
target_sources(board_disco_l475_iot01a PRIVATE disco.cpp)

add_executable(app_k64f main.cpp)
target_link_libraries(app_k64f PRIVATE platform board_k64f)

add_executable(app_disco main.cpp)
target_link_libraries(app_disco PRIVATE platform board_disco_l475_iot01a)
