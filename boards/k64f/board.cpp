#include "mcu.h"
#include "board.h"
#include <stdio.h>

void board_init() {
    mcu_init();
    printf("k64f board initialized !\n");
}

