#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

#include "headers/terminal.h"
#include "headers/menus.h"
#include "headers/login.h"
#include "headers/signup.h"
#include "headers/sector.h"
#include "headers/user.h"
#include "headers/set.h"

unsigned num_sectors = 0;
unsigned num_users = 0;
short session = UNAUTHENTICATED;
//struct User_storage all_users[MAX_USERS] = {0};
//struct Sector_storage all_sectors[MAX_SECTORS]={0};

struct User * all_users[MAX_USERS] = {0};
struct Sector * all_sectors[MAX_SECTORS] = {0};

void start_variables(){
  //const void * default_sector = new(Sector, DEFAULT_SECTOR_ID, "Setor comum", 0);
  retrieve(Sector);
  retrieve(User);
}

int main() {
  start_variables();

  char title[] = "Voce nao esta logado.";
  char *options[] = {
      LOGIN,
      SIGNUP,
      SAIR
  };
  int num_options = sizeof(options) / sizeof(options[0]);
  Dropdown *dropdown = create_dropdown(title, options, num_options);

  int selected = run_dropdown(dropdown);
  

  // Clear screen and show result
  printf(CLEAR_SCREEN);
  //if (selected >= 0) printf("You selected: %s\n", options[selected]);
  //else printf("Selection cancelled\n");

  free_dropdown(dropdown);


  if(!strcmp(options[selected], LOGIN)){
    if(!login()){
      printf("Voce esta autenticado.\n");
    }else{
      printf("Falha autenticacao\n");
    }

  }else if(!strcmp(options[selected], SIGNUP)){
    signup();
    if(!login()){
      printf("Voce esta autenticado.\n");
    }else{
      printf("Falha autenticacao\n");
    }
  }
  return 0;
}


