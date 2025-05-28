#ifndef LOGIN_H
#define LOGIN_H

#define AUTHENTICATED 0
#define UNAUTHENTICATED 1



#define DEFAULT_USER_PERMISSION -1
#define SUPERUSER_PERMISSION 0
#define COORDINATION_PERMISSION 1
#define SECRETARY_PERMISSION 2
#define TECHNICIAN_PERMISSION 3

#define LOGIN "Login"
#define SAIR "Sair"
#define SIGNUP "Cadastre-se"

#define LOGIN_MAXSIZE 64
#define PASSWORD_MAXSIZE 128

extern short session;
extern struct User * current_user;
int login();

#endif
