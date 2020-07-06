add_subdirectory(disco_l475)
add_subdirectory(k64f)

# the muc interface
add_library(board INTERFACE)
target_include_directories(board INTERFACE .)
target_sources(board INTERFACE board.h)

