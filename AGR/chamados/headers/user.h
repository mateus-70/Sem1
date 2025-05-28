#ifndef USER_H
#define USER_H

#define MAX_USERS 100
#define GIVEN_NAME_MAXSIZE 30
#define SURNAME_MAXSIZE 100
#define PASSWORD_MAXSIZE 128
#define DEFAULT_PERMISSION_ID -1
#define DEFAULT_ADMIN_PERMISSION 1

extern unsigned num_users;

//extern struct User_storage all_users[MAX_USERS];
extern struct User * all_users[MAX_USERS];
extern const void * User;

struct User{
  const void * class;
  unsigned id;
  char * login;
  char * password;
  int    permission;
  char * given_name;
  char * surname;
  struct Sector * in;

  void * (* add_user) ();
  void * (* del_user) ();
  void * (* edit_user) ();
  void * (* list_users) ();

  void * (* add_sector) ();
  void * (* del_sector) ();
  void * (* edit_sector) ();
  void * (* list_sectors) ();
};

struct User_storage{
  unsigned id;
  char login[PASSWORD_MAXSIZE];
  char password[PASSWORD_MAXSIZE];
  int  permission;
  char given_name[GIVEN_NAME_MAXSIZE];
  char surname[SURNAME_MAXSIZE];
  unsigned sector_id;
};
#endif
