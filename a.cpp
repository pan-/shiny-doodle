#include <stdio.h>

void a(void) {
    printf("A\n");
}

void b(void);
void use_b(void) {
    printf("use_b\n");
    b();
}
