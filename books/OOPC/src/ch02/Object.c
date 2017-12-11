#include "Object.h"
#include "Class.h"

#include <assert.h>

int differ(const void *self, const void *b) {
    const struct Class * const *cp = self;
    assert(self && *cp && (*cp)->differ);
    return (*cp)->differ(self, b);
}

size_t sizeOf(const void *self) {
    cosnt struct Class *const *cp = self;
    assert(self && *cp);
    return (*cp)->size;
}
