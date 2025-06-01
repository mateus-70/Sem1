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

  printf("Num_users=%u.\n", num_users);
  for(int i=0; i<num_users; i++){

//    printf("Login: %s - %s.\n", login, all_users[i] -> login);
//    printf("Senha: %s - %s.\n", password, all_users[i] -> password);
    if(!strcmp(login, all_users[i] -> login) && !strcmp(password, all_users[i] -> password)){
      session = AUTHENTICATED;
      current_user = all_users[i];
       //printf("LOGIN: %u, %s, %s, %d, %s, %s, %d.\n\n", current_user -> id,current_user -> login, current_user -> password, current_user -> permission, current_user -> given_name, current_user -> surname, current_user -> in->id); 
       return 0;
    }
  }
  printf("Falha na autenticacao.\n");

  return 1;
}

