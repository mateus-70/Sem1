#include <string.h>

char * remove_crlf(char * _str){
  char * str = _str;
  unsigned lenght;

  lenght = (unsigned) strlen(str);
  if(str[lenght-1] == '\n'){
    str[lenght-1] = 0;
  }
  return str;
}
