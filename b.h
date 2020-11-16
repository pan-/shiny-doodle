#include <stdint.h>
#include <stdbool.h>

#ifndef B_H
#define B_H

struct boo {
    void (*foo)(uint32_t v);
    bool (*bar)(uint32_t v);
};

extern const struct boo b_test;

#endif
