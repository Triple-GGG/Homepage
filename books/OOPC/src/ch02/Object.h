#ifndef OBJECT_H
#define OBJECT_H

#include <stddef.h>

extern const void *Object;

int differ(const void *a, const void *b);
size_t sizeOf(const void *self);

#endif
