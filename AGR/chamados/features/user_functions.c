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

void list_user();
void list_user_admin();
void list_user_coordination();
void list_user_secretary();
void list_user_technician();
void list_user_default_user();

void edit_user(){}
void del_user(){}


void list_user_coordination(){}
void list_user_secretary(){}
void list_user_technician(){}
void list_user_default_user(){}

void list_user_admin(){
  char listed_user_role[ROLE_NAME_MAXSIZE];
  // list all users
  for(int i=0; i<num_users;i++){
    switch(all_users[i]->permission){
    case ADMIN_PERMISSION:
      strcpy(listed_user_role, ADMINISTRATOR);
    break;
    case COORDINATION_PERMISSION:
      strcpy(listed_user_role, COORDINATION);
    break;
    case SECRETARY_PERMISSION:
      strcpy(listed_user_role, SECRETARY);
    break;
    case TECHNICIAN_PERMISSION:
      strcpy(listed_user_role, TECHNICIAN);
    break;
    case DEFAULT_USER_PERMISSION:
      strcpy(listed_user_role, DEFAULT_USER_FUNCTION);
    break;
    default: throw_error(__func__);
    }

    printf("Nome: %*s - Setor: %*s - Funcao: %*s.\n", 
      GIVEN_NAME_MAXSIZE, all_users[i]->given_name, 
      SECTOR_NAME_MAXSIZE, all_users[i]->in->name,
      ROLE_NAME_MAXSIZE, listed_user_role);
  }
}

void list_user(){
  switch(current_user->permission){
  case ADMIN_PERMISSION: 
    list_user_admin();
  break;
  case COORDINATION_PERMISSION:
    list_user_coordination();
  break;
  case SECRETARY_PERMISSION:
    list_user_secretary();
  break;
  case TECHNICIAN_PERMISSION:
    list_user_technician();
  break;
  case DEFAULT_USER_PERMISSION:
    list_user_default_user();
  break;
  default:
    throw_error(__func__);
  }
}
