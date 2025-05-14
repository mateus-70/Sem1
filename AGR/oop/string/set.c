#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#include "String.h"
#include "set.h"
#include "object.h"
#include "new.h"
#include "new_p.h"

// static int heap [MANY];

struct Set { 
  const void * class;
};

struct Object { 
  unsigned count; 
struct Set * in;
};

static const size_t _Set = sizeof(struct Set);
static const size_t _Object = sizeof(struct Object);
static const size_t _Class = sizeof(struct Class);

const void * Set = & _Set;
const void * Object = & _Object;
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
  printf("self size=%zu\n", (*cp) -> size);
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

// void * add (void * _set, const void * _element){
//   struct Set * set = _set;
//   struct Object * element = (void *) _element;
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
 

void * find (const void * _set, const void * _element){
  const struct Object * element = _element;
  assert(_set);
  assert(element);
  return element -> in == _set ? (void *) element : 0;
}

int contains (const void * _set, const void * _element){
  return find(_set, _element) != 0 ;
}

// void * drop (void * _set, const void * _element){
//   struct Set * set = _set;
//   struct Object * element = find(set, _element);
// 
//   if(element){
//     if(--element -> count == 0)
//       element -> in = 0;
//     --set ->count;
//   }
//   return element;
// }

// unsigned count (const void * _set){
//   const struct Set * set = _set;
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

