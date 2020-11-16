#include <stdio.h>
#include "b.h"

void b_foo(uint32_t v) {
    printf("b %u\n", v);
}

struct boo b_test = {
    .foo = b_foo,
    .bar = NULL
};
