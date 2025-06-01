#include "../headers/menus.h"
#include "../headers/terminal.h"
#include "../headers/login.h"
#include "../headers/new_p.h"
#include "../headers/new.h"
#include "../headers/set.h"
#include "../headers/user.h"
#include "../headers/sector.h"
#include "../headers/mystrings.h"

void * add_user(){
  char login[LOGIN_MAXSIZE], password[PASSWORD_MAXSIZE], 
       given_name[GIVEN_NAME_MAXSIZE], surname[SURNAME_MAXSIZE];

  // struct Sector new_user_sector;

  printf(CLEAR_SCREEN);

  printf("Primeiro nome: ");
  fgets(given_name, GIVEN_NAME_MAXSIZE, stdin);
  remove_crlf(given_name);
  
  printf("Sobrenome: ");
  fgets(surname, SURNAME_MAXSIZE, stdin);
  remove_crlf(surname);

    // pode adicionar na propria sector usuario se coord.
  printf("Login: ");
  fgets(login, LOGIN_MAXSIZE, stdin);
  remove_crlf(login);

  printf("Senha: ");
  fgets(password, PASSWORD_MAXSIZE, stdin);
  remove_crlf(password);

  printf(CLEAR_SCREEN);
  if(session != AUTHENTICATED){
    // seleciona sector deestino se adm geral
    printf("Setor comum.\n");
    //remove_crlf();

  }else{
    printf("Ei ah! OOO");
    //implementar selecao de area
  }
  void * new_user = new(User, login, password, DEFAULT_USER_PERMISSION, given_name, surname, DEFAULT_SECTOR_ID);
  // printf("TTTHERE?");
  if (!new_user)
    store(new_user);
  return new_user;
}

void * signup(){
  return add_user();
}
