#ifndef SECTOR_H
#define SECTOR_H

#define MAX_SECTORS 100
#define SECTOR_MAXNAME 100

extern unsigned num_sectors; // INCREMENT ONLY // NEVER EVER REDUCES

struct Sector { 
  const void * class;
  int id; // -1 para usuario comum, 0 para adm geral, 123... coord sec tec etc.
  char * name;
  struct User * user_id_in_charge;
};

struct Sector_storage { 
  int id; // -1 para usuario comum, 0 para adm geral, 123... coord sec tec etc.
  char name[SECTOR_MAXNAME];
  struct User * user_id_in_charge;
};

extern unsigned num_sectors; // INCREMENT ONLY // NEVER EVER REDUCES
extern struct Sector_storage all_sectors[MAX_SECTORS];

#endif
