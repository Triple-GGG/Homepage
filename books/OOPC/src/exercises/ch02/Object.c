#include "new.h"
#include "new.r"

static unsigned obj_id;

struct Object {
    const void *class;
    unsigned id;
};

static void *Object_ctor(void *_self, va_list *app) {
    struct Object *self = _self;
    self->id = obj_id++;
    return self;
}

static void *Object_dtor(void *_self) {
    
}
