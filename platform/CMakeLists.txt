# The interface shares only the symbol name without providing a dummy implementation 
add_library(mbed_overrides INTERFACE)
target_sources(mbed_overrides INTERFACE mbed_overrides.h)

# platform requires mbed_overrides which is only an interface
add_library(platform)
target_sources(platform PRIVATE platform.cpp)
target_sources(platform PRIVATE platform.h)
target_include_directories(platform PUBLIC ./)
target_link_libraries(platform PRIVATE mbed_overrides)

# a vendor can still depend on this if they don't want to implement something specific
add_library(mbed_overrides_default)
target_sources(mbed_overrides_default PRIVATE mbed_overrides.cpp)
target_link_libraries(mbed_overrides_default PRIVATE mbed_overrides)

