#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "b.h"
#include "c.h"
#include "d.h"

long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}

void other(struct boo *d) {
    d->foo(25);
}

void yet_another(void *d) {
    struct boo *b = (struct boo*)d;
    b->foo(44);
    // XXX: If this is commented out, bar is never used
    /*if (b->bar != NULL) {
        printf("so ? %s\n", b->bar(12)?"true":"false");
    }*/
}

struct boo *array[] = {
    &b_test, &c_test,
    /*
    &d_test
    // */
};

int main(void) {
    srand(current_timestamp());

    b_test.foo((uint32_t)rand() % 100);

    uint32_t idx = (uint32_t)rand() % (sizeof(array) / sizeof(struct boo *));

    other(array[idx]);
    yet_another(array[idx]);
}

