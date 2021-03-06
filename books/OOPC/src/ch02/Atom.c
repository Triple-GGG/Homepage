#include "String.h"
#include "new.r"
#include "new.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>

/**
 * An atom is a unique string object; if two atoms contain the same strings,
 * they are identical. We maintain a circular list of all atoms and we count
 * the number of times an atom is cloned.
 *
 * Comparing with Strings, Atoms are more expensive to construct and destroy,
 * but cheaper to compare.
 */
struct String {
    const void *class;
    char *text;
    struct String *next;
    unsigned count;
};

static struct String *ring; // all strings

static void *String_clone(const void *_self) {
    struct String *self = (void *)_self;
    ++self->count;
    return self;
}

static void *String_ctor(void *_self, va_list *app) {
    struct String *self = _self;
    const char *text = va_arg(*app, const char *);

    if (ring) {
        struct String *p = ring;
        do {
            if (strcmp(p->text, text) == 0) {
                ++p->count;
                free(self);
                return p;
            }
        } while ((p = p->next) != ring);
    } else {
        ring = self;
    }

    self->next = ring->next;
    ring->next = self;
    self->count = 1;

    self->text = malloc(strlen(text) + 1);
    assert(self->text);
    strcpy(self->text, text);
    return self;
}

static void *String_dtor(void *_self) {
    struct String *self = _self;

    if (--self->count > 0)
        return NULL;

    assert(ring);

    if (ring == self)
        ring = self->next;
    if (ring == self)
        ring = NULL;
    else {
        struct String *p = ring;
        while (p->next != self) {
            p = p->next;
            assert(p != ring);
        }
        p->next = self->next;
    }

    free(self->text);
    self->text = NULL;
    return self;
}

static int String_differ(const void *_self, const void *_b) {
    return _self != _b;
}

// the type descriptor
static const struct Class _String = {
    sizeof(struct String),
    String_ctor, String_dtor,
    String_clone, String_differ
};

const void *String = &_String;
