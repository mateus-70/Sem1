#ifndef SET_H
#define SET_H
#include <stdarg.h>



extern const void * Sector;

void * new (const void * class, ...);
void * store(void * self);
void retrieve(const void * class);

void * add (void * sector, const void * user);
void * find (const void * sector, const void * user);
void * drop (void * sector, const void * user);
void * identify(const void * class, ...);
int contains (const void * sector, const void * user);
void throw_error(const char * function_name);

int apply(const void * area, int (*action) (void * object, va_list ap), ...);




#endif
