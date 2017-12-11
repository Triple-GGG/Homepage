/**
 * An implementation -- Set
 *
 * In this implementation, an object stores no information, and belongs to at
 * most one set, so that we can represent each object and each set as small,
 * unique, positive integer values used as indices into an array. If an object
 * is a member of a set, its array element contains the integer value
 * representing the set.
 */
#include "new.h"
#include "Object.h"
#include "Set.h"

#include <assert.h>
#include <stdio.h>

const void *Set;
const void *Object;

#if !defined MANY || MANY < 1
#define MANY 10
#endif

/**
 * The object heap, if an element is zero, it's available; if an element is
 * MANY, it's an object not belongs to any set. So that the 'heap[0]' cannot
 * represent a set.
 */
static int heap[MANY];

void *new(const void *type, ...) {
    int *p;
    for (p = heap + 1; p < heap + MANY; ++p)
        if (*p == 0)
            break;

    assert(p < heap + MANY);

    *p = MANY;

    return p;
}

void delete(void *_item) {
    int *item = (int *)_item;
    if (item) {
        assert(item > heap && item < heap + MANY);
        *item = 0;
    }
}

void *add(void *_set, const void *_element) {
    int *set = (int *)_set;
    const int *element = (const int *)_element;

    assert(set > heap && set < heap + MANY);
    assert(*set == MANY); // a set can't belongs to other sets.
    assert(element > heap && element < heap + MANY);

    if (*element == MANY)
        *(int *)element = set - heap;
    else
        assert(*element == set - heap);

    return (void *)element;
}

void *find(const void *_set, const void *_element) {
    const int *set = (const int *)_set;
    const int *element = (const int *)_element;

    assert(set > heap && set < heap + MANY);
    assert(*set == MANY);
    assert(element > heap && element < heap + MANY);
    assert(*element);

    return *element == set - heap ? (void *)element : NULL;
}

int contains(const void *set, const void *element) {
    return find(set, element) != NULL;
}

void *drop(void *set, const void *_element) {
    int *element = find(set, _element);
    if (element) {
        *element = MANY;
    }
    return element;
}

int differ(const void *a, const void *b) {
    return a != b;
}
