#ifndef OBJECT_H
#define OBJECT_H 
#include <stdarg.h>
#include <stdio.h>

extern const void * Object; /* new(Object); */
int differ (const void * a, const void * b);

int store(const void * object, FILE * fp);
int storev(const void * object, va_list ap);

#endif
