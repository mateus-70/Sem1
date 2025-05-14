#ifndef SET_H
#define SET_H
#include <stdarg.h>

extern const void * Set;

void * add (void * set, const void * element);
void * find (const void * set, const void * element);
void * drop (void * set, const void * element);
int contains (const void * set, const void * element);

int apply(const void * set, int (*action) (void * object, va_list ap), ...);

#endif
