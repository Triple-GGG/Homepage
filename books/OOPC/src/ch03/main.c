#include <setjmp.h>

static enum tokens token;

static jmp_buf onError;

int main() {
    volatile int errors = 0;
    char buf[BUFSIZ];

    if (setjmp(onError))
        ++errors;

    while (gets(buf))
        if (scan(buf)) {
            void *e = sum();
            if (token)
                error("trash after sum");
            process(e);
            delete(e);
        }

    return errors > 0;
}
