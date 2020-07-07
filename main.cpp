#include "platform.h"
#include "board.h"
//#include "mcu.h" // not available form here it is not a dependency

int main(void) {
    board_init();
    platform_init();
}
