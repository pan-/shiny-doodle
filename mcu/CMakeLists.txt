# the mcu interface
add_library(mcu INTERFACE)
target_include_directories(mcu INTERFACE ./)
target_sources(mcu INTERFACE mcu.h)
