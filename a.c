#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "b.h"
#include "c.h"

long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

void some_function(const void *d) {
    const struct boo *b = (const struct boo *)d;
    uint32_t v = (uint32_t)rand() % 100;
    b->foo(v);
    // XXX: If this is commented out, bar is never used
    /*if (b->bar != NULL) {
        printf("so ? %s\n", b->bar(12)?"true":"false");
    }*/
}

static const struct boo *array[] = {
    &b_test, &c_test
};

int main(void) {
    srand(current_timestamp());
    uint32_t idx = (uint32_t)rand() % (sizeof(array) / sizeof(struct boo *));

    /* lto works in that case
    some_function(&b_test);
    // */

    //* but not when using an array (const so known at compile time)
    some_function(array[idx]);
    // */
}

// vim: ts=4:sw=4
