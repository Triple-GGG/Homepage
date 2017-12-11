#ifndef LIST_H
#define LIST_H

#include "new.h"
#include "Object.h"
#include "Set.h"

struct Node {
    void *obj;
    int count;
    struct Node *next;
};

struct Set {
    struct Node *list;
};

void *new(const void *type, ...) {
    
}

#endif
