#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#include "../headers/terminal.h"
#include "../headers/menus.h"
#include "../headers/login.h"
#include "../headers/signup.h"
#include "../headers/sector.h"
#include "../headers/user.h"
#include "../headers/set.h"
#include "../headers/add_user.h"
#include "../headers/user_functions.h"


#define EDIT_PROFILE "Editar perfil"
#define ADD_USER "Adicionar novo usuario"
#define DEL_USER "Remover usuario"
#define EDIT_USER "Editar usuario"
#define LIST_USER "Listar usuarios"

#define MANAGE_USERS "Alterar usuarios"
#define MANAGE_SECTORS "Alterar setores"
#define MANAGE_TICKETS "Alterar chamados"

void user_function_selector();

// the home() function is the same for every user that calls it, but the options shown will differ
void home(){
  char title[] = "Bem-vindo ao DS!";
  char *options[5];

  int num_options;
  options[0] = EDIT_PROFILE;
  //char *options_technician[] = { EDIT_PROFILE, MANAGE_TICKETS, EXIT };
  
  
  if(current_user->permission == ADMIN_PERMISSION){ 
    options[1] = MANAGE_USERS, 
    options[2] = MANAGE_SECTORS, 
    options[3] = MANAGE_TICKETS, 
    options[4] = EXIT;
    num_options = 5;
  }else if(current_user->permission == COORDINATION_PERMISSION){
    options[1] = MANAGE_USERS, 
    options[2] = MANAGE_TICKETS, 
    options[3] = EXIT;
    num_options = 4;
  }else if(current_user->permission == SECRETARY_PERMISSION){
    options[1] = MANAGE_USERS, 
    options[2] = MANAGE_TICKETS, 
    options[3] = EXIT;
    num_options = 4;
  }else if(current_user->permission == TECHNICIAN_PERMISSION){
    options[1] = MANAGE_TICKETS, 
    options[2] = EXIT;
    num_options = 3;
  }else if(current_user->permission == DEFAULT_USER_PERMISSION){
    options[1] = MANAGE_TICKETS, 
    options[2] = EXIT;
    num_options = 3;
  }else{
    printf("\n\nErro na permissao de usuario\n\n"); 
    getchar(); 
    abort();
  }

  Dropdown *dropdown = create_dropdown(title, options, num_options);

  int selected = run_dropdown(dropdown);
  

  // Clear screen and show result
  printf(CLEAR_SCREEN);
  //if (selected >= 0) printf("You selected: %s\n", options[selected]);
  //else printf("Selection cancelled\n");

  free_dropdown(dropdown);

  if(!strcmp(MANAGE_USERS, options[selected])){
    user_function_selector();
  }else if(!strcmp(MANAGE_SECTORS, options[selected])){
    printf("Quero "MANAGE_SECTORS);
  }else if(!strcmp(MANAGE_TICKETS, options[selected])){
    printf("Quero "MANAGE_TICKETS);
  }else if(!strcmp(EXIT, options[selected])){
    printf("Quero "EXIT);
  }
}

void user_function_selector(){
  char title[] = "Alteracoes em usuarios";
  char *options[] = {
    LIST_USER,
    ADD_USER,
    EDIT_USER,
    DEL_USER,
    EXIT
  };
  int num_options = sizeof(options) / sizeof(options[0]);
  Dropdown *dropdown = create_dropdown(title, options, num_options);

  int selected = run_dropdown(dropdown);
  printf(CLEAR_SCREEN);
  free_dropdown(dropdown);

  if(!strcmp(options[selected], LIST_USER)){
    list_user();
  }else if(!strcmp(options[selected], ADD_USER)){
    add_user();
  }else if(!strcmp(options[selected], EDIT_USER)){
    edit_user();
  }else if(!strcmp(options[selected], DEL_USER)){
    del_user();
  }else{
    printf("Erro na selecao do menu de usuario. Abort()\n");
    getchar();
    abort();
  }
}
