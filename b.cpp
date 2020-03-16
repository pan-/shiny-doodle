#include <stdio.h>

void b(void) {
    printf("B\n");
}

void a(void);
void use_a(void) {
    printf("use_a\n");
    a();
}
