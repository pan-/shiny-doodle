#include <stdio.h>
#include "platform.h"
#include "mbed_overrides.h"

void platform_init() {
    mbed_sdk_init();
    printf("platform initialized !\n");
}
