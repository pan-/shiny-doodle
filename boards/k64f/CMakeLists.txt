add_subdirectory(xpresso_k64f)

add_library(board_k64f)
target_sources(board_k64f PRIVATE board.cpp)
target_link_libraries(board_k64f PRIVATE mcu board freescale_xpresso_k64f)
