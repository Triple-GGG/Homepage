/**
 * An implementation -- Bag
 *
 * In this implementation, an element could be added to a set many times.
 */
#ifndef BAG_H
#define BAG_H

#include "new.h"
#include "Object.h"
#include "Set.h"

#include <assert.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct Set { unsigned count; };
struct Object { unsigned count; struct Set *in; };

static const size_t _Set = sizeof(struct Set);
static const size_t _Object = sizeof(struct Object);

const void *Set = &_Set;
const void *Object = &_Object;

void *new(const void *type, ...) {
    const size_t size = *(const size_t *)type;
    void *p = calloc(1, size);

    assert(p);
    return p;
}

void delete(void *item) {
    free(item);
}

void *add(void *_set, const void *_element) {
    struct Set *set = _set;
    struct Object *element = (void *)_element;

    assert(set);
    assert(element);

    if (!element->in) {
        element->in = set;
    }
    else {
        assert(element->in == set);
    }

    ++element->count;
    ++set->count;

    return element;
}

void *find(const void *_set, const void *_element) {
    const struct Object *element = _element;
    assert(_set);
    assert(element);
    return element->in == _set ? (void *)element : NULL;
}

int contains(const void *set, const void *element) {
    return find(set, element) != NULL;
}

void *drop(void *_set, const void *_element) {
    struct Set *set = _set;
    struct Object *element = find(set, _element);

    if (element) {
        if (--element->count == 0)
            element->in = NULL;
        --set->count;
    }
    return element;
}

int differ(const void *a, const void *b) {
    return a != b;
}

#endif
