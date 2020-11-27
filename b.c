#include <stdio.h>
#include "b.h"

void b_foo(uint32_t v) {
    printf("b %u\n", v);
}

void b_baz(uint32_t v) {
    printf("b baz %u\n", v);
}

const struct boo b_test = {
    .foo = b_foo,
    .bar = NULL,
    .baz = b_baz
};
