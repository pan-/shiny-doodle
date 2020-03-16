#include <stdio.h>

void board_init(void) __attribute__((weak));
void board_init(void) {
    printf("B\n");
}
