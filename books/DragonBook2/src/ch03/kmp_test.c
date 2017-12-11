#include "kmp.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    char b[] = "ababaa";
    int f[6];

    failure(b, f, 6);

    int i;
    for (i = 0; i < 6; i++)
        printf("%d ", f[i]);
    printf("\n");

    return 0;
}
