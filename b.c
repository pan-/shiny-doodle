#include <stdio.h>
#include "b.h"

void b_foo(uint32_t v) {
    printf("%u\n", v);
}

struct boo test = {
    .foo = b_foo,
    .bar = NULL
};
