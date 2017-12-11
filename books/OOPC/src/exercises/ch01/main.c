#include <stdio.h>

#include "new.h"
#include "Object.h"
#include "Set.h"

int main() {
    void *s = new (Set);
    void *a = add(s, new(Object));
    void *b = add(s, new(Object));
    void *c = new(Object);

    if (contains(s, a) && contains(s, b))
        printf("ok\n");

    if (contains(s, c))
        printf("contains?\n");

    if (differ(a, add(s, a)))
        printf("differ?\n");

    if (contains(s, drop(s, a)))
        printf("drop?\n");

    delete(drop(s, b));
    delete(drop(s, c));

    return 0;
}
