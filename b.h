#include <stdint.h>
#include <stdbool.h>

struct boo {
    void (*foo)(uint32_t v);
    bool (*bar)(uint32_t v);
};

extern struct boo test;
