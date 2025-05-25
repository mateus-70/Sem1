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



extern struct User_storage all_users[MAX_USERS];

static void * User_ctor(void * _self, va_list * app){
  struct User * self = _self;
  const char * login = va_arg(*app, const char *);
  const char * password = va_arg(*app, const char *);
  const char permission = va_arg(*app, const int);

  const char * given_name = va_arg(*app, const char *);
  const char * surname = va_arg(*app, const char *);
  const int sector_id = va_arg(*app, const int);

  self -> login = malloc(strlen(login)+1);
  assert(self -> login);
  strcpy(self -> login, login);

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

  // sector id?

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
  struct User* self = _self;
  printf("Dentro user_store\n\n...");
  if(num_users < MAX_USERS){
  printf("1\n");
    all_users[num_users].id = self->id;
  printf("2\n");
    strcpy(all_users[num_users].login, self->login);
  printf("3\n");
    strcpy(all_users[num_users].password, self->password);
  printf("4\n");
    all_users[num_users].permission = self->permission;
  printf("5\n");
    strcpy(all_users[num_users].given_name, self->given_name);
  printf("6\n");
    strcpy(all_users[num_users].surname, self->surname);
  printf("7\n");
    all_users[num_users].sector_id = (*self).in->id;
  printf("8\n");
    num_users++;
  printf("9\n");
  }
  printf("\nid=%u.\tlogin=%s\tpass=%s\tperm=%d\tgiv=%s\tsurn=%s\tsecID=%u.\n\n",
    all_users[num_users].id,
    all_users[num_users].login, 
    all_users[num_users].password,
    all_users[num_users].permission,
    all_users[num_users].given_name,
    all_users[num_users].surname,
    all_users[num_users].sector_id );
  return _self;
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
