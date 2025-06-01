#ifndef MYSTRINGS_H
#define STRINGS_H
#define _STRINGIFY(s) #s
#define STRINGIFY(s) _STRINGIFY(s)


char * remove_crlf(char * _str);

#endif
