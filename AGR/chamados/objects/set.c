#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

// #include "String.h"
#include "../headers/set.h"
#include "../headers/user.h"
#include "../headers/sector.h"
// #include "object.h"
#include "../headers/new.h"
#include "../headers/new_p.h"
#include "../headers/login.h"
#include "../headers/mystrings.h"


void retrieve_users();
void retrieve_sectors();

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

void * identify(const void * _class, ... ){
  const struct Class * class = _class;
  va_list ap;
  va_start(ap, _class);
  if(class == User){
    unsigned id = va_arg(ap, unsigned);
    for(int i=0; i<num_users; i++){
      if(all_users[i]->id == id){
        va_end(ap);
        return all_users[i];
      }
    }
  }else if(class == Sector){
    int id = va_arg(ap, int);
    // printf("Numsectors: %u.\n", num_sectors);
    for(int i=0; i<num_sectors; i++){
      if(all_sectors[i]->id == id){
        va_end(ap);
        return all_sectors[i];
      }
    }
    va_end(ap);
  }else{
    printf("Falha ao identificar. Abort() \n\n");
    getchar();
    abort();
    va_end(ap);
    return 0;
  }
    return 0;
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

void retrieve(const void * _class){
  const void * class = _class;

  if(class == User){
    retrieve_users();
  }else if(class == Sector){
    retrieve_sectors();
  }else{
    printf("Falha ao recuperar dados. Abort()");
    abort();
  }
}

void retrieve_users(){
  FILE * fp = fopen("./storage/users.data", "r");
  assert(fp);
  char user_login[LOGIN_MAXSIZE], user_password[PASSWORD_MAXSIZE];
  int user_permission, user_sector_id;
  unsigned user_id;
  char user_given_name[GIVEN_NAME_MAXSIZE], user_surname[SURNAME_MAXSIZE]; 
  // struct Sector * in;
  while( 
    fscanf(fp, "%u,%[a-zA-Z],%[a-zA-Z0-9],%d,%[a-zA-Z],%[a-zA-Z],%d", 
      &user_id,
      user_login, user_password, &user_permission, 
      user_given_name, user_surname, &user_sector_id) == 7){
       //printf("RETRIEVE USERS: %u, %s, %s, %d, %s, %s, %d.\n\n", user_id, user_login, user_password, user_permission, 
      // user_given_name, user_surname, user_sector_id);
      // in = identify(Sector, user_sector_id);
      // getchar();
    new(User, user_id, user_login, user_password, user_permission, 
      user_given_name, user_surname, user_sector_id);
  }
}

void retrieve_sectors(){
    FILE * fp = fopen("./storage/sectors.data", "r");
    char sector_name[SECTOR_NAME_MAXSIZE];
    int sector_id;
    unsigned user_id_in_charge;
    assert(fp);
    while(
      fscanf(fp, "%d,%[a-zA-Z ],%u", &sector_id, sector_name, &user_id_in_charge) == 3){
      new(Sector, sector_id, sector_name, user_id_in_charge);
    }
}

void throw_error(const char * function_name){
  printf("Erro na funcao %s.\n Abortando.\n", function_name);
  abort();
}
