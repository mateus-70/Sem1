#ifndef SECTOR_H
#define SECTOR_H

#define MAX_SECTORS 100
#define ROLE_NAME_MAXSIZE 50
#define SECTOR_NAME_MAXSIZE 100
#define DEFAULT_SECTOR {_class, -1, "Setor comum", 0}
#define DEFAULT_SECTOR_ID -1
#define DEFAULT_SECTOR_ADMIN 1

extern unsigned num_sectors; // INCREMENT ONLY // NEVER EVER REDUCES
extern struct Sector * all_sectors[MAX_SECTORS];
//extern struct Sector_storage all_sectors[MAX_SECTORS];

struct Sector { 
  const void * class;
  int id; // -1 para usuario comum, 0 para adm geral, 123... coord sec tec etc.
  char * name;
  struct User * user_id_in_charge;
};

struct Sector_storage { 
  int id; // -1 para usuario comum, 0 para adm geral, 123... coord sec tec etc.
  char name[SECTOR_NAME_MAXSIZE];
  struct User * user_id_in_charge;
};



#endif
