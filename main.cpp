#include "platform.h"
#include "board.h"
#include "mcu.h"

int main(void) {
    board_init();
    platform_init();
}
