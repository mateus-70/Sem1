#ifndef NEW_R
#define NEW_R

struct Class{
  size_t size;            // size of an object
  void * (* ctor) (void * self, va_list * app); // constructor
  void * (* dtor) (void * self); // destructor
  void * (* clone) (const void * self); 
  int (* differ) (const void * self, const void * b);  
  void * (* store) (void * self); 
};
#endif
