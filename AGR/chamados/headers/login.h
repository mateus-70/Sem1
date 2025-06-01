#ifndef LOGIN_H
#define LOGIN_H

#define AUTHENTICATED 0
#define UNAUTHENTICATED 1




#define LOGIN "Login"
#define EXIT "Sair"
#define SIGNUP "Cadastre-se"

#define LOGIN_MAXSIZE 64
#define PASSWORD_MAXSIZE 128

extern short session;
extern struct User * current_user;
int login();

#endif
