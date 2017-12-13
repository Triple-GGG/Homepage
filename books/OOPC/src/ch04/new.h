/**
 * Memory management
 */
#ifndef NEW_H
#define NEW_H

void *new(const void *type, ...);
void delete(void *item);

// The selector 'draw()'. Why put it here?
void draw(const void *self);

#endif
