#include "String.h"
#include "new.h"
#include "Object.h"

#include <stdio.h>

int main() {
    void *a = new(String, "a"), *aa = clone(a);
    void *b = new(String, "b");

    printf("sizeOf(a) == %I64u\n", sizeOf(a));

    if (differ(a, b))
        printf("ok\n");

    if (differ(a, aa))
        printf("differ?\n");

    if (a == aa)
        printf("clone?\n");

    delete(a);
    delete(aa);
    delete(b);

    return 0;
}
