/*******************************************************************************

Set, an example of abstract data type.

*******************************************************************************/

#ifndef SET_H
#define SET_H

/**
 * The descriptor of Set. We use the 'void*' to instead of a structure to
 * represent a Set, because it is generic enough, so that we can pass virtually
 * anything to 'add()' and the other functions.
 */
extern const void *Set;

void *add(void *set, const void *element);
void *find(const void *set, const void *element);
void *drop(void *set, const void *element);
int contains(const void *set, const void *element);

#endif
