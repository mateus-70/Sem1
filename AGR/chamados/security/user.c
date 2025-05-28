#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

#include "../headers/user.h"
#include "../headers/sector.h"
#include "../headers/set.h"
#include "../headers/new_p.h"
#include "../headers/new.h"




static void * User_ctor(void * _self, va_list * app){
  struct User * self = _self;
  const unsigned id = va_arg(*app, const unsigned);
  const char * login = va_arg(*app, const char *);
  const char * password = va_arg(*app, const char *);
  const char permission = va_arg(*app, const int);

  const char * given_name = va_arg(*app, const char *);
  const char * surname = va_arg(*app, const char *);
  const int sector_id = va_arg(*app, const int);

  self -> id = id;

  self -> login = malloc(strlen(login)+1);
  assert(self -> login);
  strcpy(self -> login, login);
//  printf("USER_CTOR self->login=%s.\n", self-> login);
//  getchar();

  self -> password = malloc(strlen(password)+1);
  assert(self -> password);
  strcpy(self -> password, password);

  self -> permission = permission;

  self -> given_name = malloc(strlen(given_name)+1);
  assert(self -> given_name);
  strcpy(self -> given_name, given_name);

  self -> surname = malloc(strlen(surname)+1);
  assert(self -> surname);
  strcpy(self -> surname, surname);
  //printf("Login: %s.\n permissino=%d.\n", login, permission);

//  printf("USER CTOR sector_id=%d.\n", sector_id );
  void * in = identify(Sector, sector_id);
  // printf("%d ->sectorid\n", sector_id);
  assert(in);
//  printf("user_ctor-> Setor ID=%d.\n, sectorADDR=%p.\n", sector_id,  in);
  self -> in = in;
  store(self);
  num_users++;

  return self;
}

static void * User_dtor(void * _self){
 return 0;
}

static void * User_clone(const void * _self){
 return 0;
}

int User_differ(const void * _self, const void * _b){
  return 0;
}

static void * User_store(void * _self){
  void * self = _self;

  assert(num_users < MAX_USERS);
  all_users[num_users] = self;
  return self;
}

static const struct Class _User = {
  sizeof(struct User),
  User_ctor,
  User_dtor,
  User_clone,
  User_differ,
  User_store
};

// static const size_t _User = sizeof(struct User);
const void * User = & _User;
