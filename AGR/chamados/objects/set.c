#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

// #include "String.h"
#include "../headers/set.h"
#include "../headers/user.h"
// #include "object.h"
#include "../headers/new.h"
#include "../headers/new_p.h"
#include "../headers/login.h"
#include "../headers/mystrings.h"


// static const size_t _Sector = sizeof(struct Sector);
static const size_t _Class = sizeof(struct Class);

// const void * Sector = & _Sector;
const void * Class = & _Class;

void * new (const void * _class, ...){
  const struct Class * class = _class;
  void * p = calloc(1, class -> size);
  
  assert(p);
  * (const struct Class **) p = class;
  if (class -> ctor){
    va_list ap;

    va_start(ap, _class);
    p = class -> ctor(p, &ap);
    va_end(ap);
  }
  
  return p;
}

void * clone (const void * _self){
  const struct Class * const * cp = _self;
  void * p = calloc( 1, (*cp) -> size);

  assert(p);
  if ( (*cp) -> clone){
    p = (*cp) -> clone(_self);
  }
  return p;
}

void delete (void * self){
  const struct Class ** cp = self;
  
  if (self && * cp && (* cp) -> dtor)
    self = (* cp) -> dtor(self);
  free(self);
}

// void * add (void * _Sector, const void * _user){
//   struct Set * set = _Sector;
//   struct Object * element = (void *) _user;
//   assert(set);
//   assert(element);
//   
//   if (!element -> in)
//     element -> in = set;
//   else
//     assert(element -> in == set);
//   ++element->count, ++set -> count;
// 
//   return element;
// }
 

void * find (const void * _Sector, const void * _user){
  const struct User * user = _user;
  assert(_Sector);
  assert(user);
  return user -> in == _Sector ? (void *) user : 0;
}

int contains (const void * _Sector, const void * _user){
  return find(_Sector, _user) != 0 ;
}



// void * drop (void * _Sector, const void * _user){
//   struct Set * set = _Sector;
//   struct Object * element = find(set, _user);
// 
//   if(element){
//     if(--element -> count == 0)
//       element -> in = 0;
//     --set ->count;
//   }
//   return element;
// }

// unsigned count (const void * _Sector){
//   const struct Set * set = _Sector;
//   assert(set);
//   return set -> count;
// }

int differ (const void * self, const void * b){
  const struct Class * const * cp = self;

  assert(self && * cp && (* cp) -> differ);
  return (* cp) -> differ(self, b);
}

size_t sizeOf (const void * self){
  const struct Class * const * cp = self;
  assert(self && * cp);
  return (* cp) -> size;
}

void * store(void * _self){
  const struct Class * const * cp = _self;
  assert(_self && * cp);
  return (*cp) -> store(_self);
}
