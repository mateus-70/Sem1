#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/login.h"
#include "../headers/mystrings.h"
#include "../headers/terminal.h"
#include "../headers/menus.h"
#include "../headers/sector.h"
#include "../headers/user.h"
#include "../headers/set.h"


extern short session;

//extern struct User_storage all_users[MAX_USERS];
extern struct User * all_users[MAX_USERS];

struct User * current_user = 0;

// return 0 if logged sucessfully, return 1 otherwise.
int login(){
  char login[128], password[128];

  printf(CLEAR_SCREEN);
  printf("Usuario: ");
  fgets(login, 128, stdin);
  remove_crlf(login);

  printf("Senha: ");
  fgets(password, 128, stdin);
  remove_crlf(password);

  for(int i=0; i<num_users; i++){

    if(!strcmp(login, all_users[i] -> login) && !strcmp(password, all_users[i] -> password)){
      session = AUTHENTICATED;
      current_user = all_users[i];
      return 0;
    }
  }
  printf("\nUsuario ou senha incorretos!\n\n");

  return 1;
}

