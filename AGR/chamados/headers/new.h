#ifndef NEW_H
#define NEW_H

#if ! defined MANY || MANY < 1
#define MANY 10
#endif

#define RECICLAR NULL 
#include <stddef.h>


void * new (const void * type, ...);
void * store(void * _self);
void delete (void * item);

void * clone (const void * self);
int differ (const void * self, const void * b);
size_t sizeOf (const void * self);

#endif
