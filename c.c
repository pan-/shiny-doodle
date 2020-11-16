#include <stdio.h>
#include <stdlib.h>
#include <sys/cdefs.h>
#include "c.h"

void c_foo(uint32_t v) {
    printf("c %u\n", v);
}

bool c_bar(uint32_t v) {
    uint32_t a =(uint32_t)rand() % 100;
    return v > a;
}

struct boo c_test = {
    .foo = c_foo,
    .bar = c_bar
};

