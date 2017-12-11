#include "kmp.h"
#include <stdio.h>

void failure(const char *b, int *f, int len) {
    int s, t = -1;
    f[0] = 0;

    for (s = 0; s < len - 1; s++) {
        while (t >= 0 && b[s+1] != b[t+1]) {
            t = f[t];
        }
        if (b[s+1] == b[t+1]) {
            t += 1;
            f[s+1] = t;
        }
        else {
            f[s+1] = 0;
        }
    }
}
