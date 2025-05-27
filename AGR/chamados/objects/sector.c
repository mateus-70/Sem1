#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <stdlib.h>

#include "../headers/sector.h"
#include "../headers/user.h"
#include "../headers/new.h"
#include "../headers/new_p.h"


static void * Sector_ctor(void * _self, va_list * app){
  struct Sector * self = _self;
  const int id = va_arg(*app, const int);
  const char * name = va_arg(*app, const char *);
  struct User * user_id_in_charge = va_arg(*app, struct User *);

  self -> id = id;

  self -> name = malloc(strlen(name)+1);
  assert(self -> name);
  strcpy(self -> name, name);

  self -> user_id_in_charge = user_id_in_charge;

  store(self);
  num_sectors++;
  return self;
}

static void * Sector_dtor(void * _self){
  return 0;
}

static void * Sector_clone(const void * _self){
  return 0;
}

int Sector_differ(const void * _self, const void * _b){
  return 0;
}

static void * Sector_store(void * _self){
  struct Sector * self = _self;
  assert(num_sectors < MAX_SECTORS);
  all_sectors[num_sectors] = self;
  return self;
}

static const struct Class _Sector = {
  sizeof(struct Sector),
  Sector_ctor,
  Sector_dtor,
  Sector_clone,
  Sector_differ,
  Sector_store
};

const void * Sector = & _Sector;
