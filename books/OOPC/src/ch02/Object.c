#include "Object.h"
#include "new.r"

#include <assert.h>

int differ(const void *self, const void *b) {
    const struct Class * const *cp = self;
    assert(self && *cp && (*cp)->differ);
    return (*cp)->differ(self, b);
}

size_t sizeOf(const void *self) {
    const struct Class *const *cp = self;
    assert(self && *cp);
    return (*cp)->size;
}

void *clone(const void *self) {
    const struct Class *const *cp = self;
    assert(self && *cp && (*cp)->clone);
    return (*cp)->clone(self);
}
