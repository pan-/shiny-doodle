#include <stdio.h>
#include <stdlib.h>
#include <sys/cdefs.h>
#include "d.h"

void d_foo(uint32_t v) {
    printf("d %u\n", v);
}

bool d_bar(uint32_t v) {
    uint32_t a =(uint32_t)rand() % 100;
    return v-7 > a;
}

struct boo d_test = {
    .foo = d_foo,
    .bar = d_bar
};

