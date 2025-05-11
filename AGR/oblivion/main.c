#include <stdio.h>
#include <stdlib.h>
#include "preset.h"

// struct ATTRIBUTES RACE_GENDER_ATTRIBUTES[20];
// struct SKILL RACE_SKILLS[20];
struct ATTRIBUTE base_attributes[8] = {
  {STRENGTH, 0, {NULL,NULL,NULL}},
  {ENDURANCE,0, {NULL,NULL,NULL}},
  {SPEED,0, {NULL,NULL,NULL}},
  {AGILITY,0, {NULL,NULL,NULL}},
  {PERSONALITY,0, {NULL,NULL,NULL}},
  {INTELLIGENCE,0, {NULL,NULL,NULL}},
  {WILLPOWER,0, {NULL,NULL,NULL}},
  {LUCK,0, {NULL,NULL,NULL}}
};


struct SKILL base_skills[21] ={ 
    {BLADE,0,NULL,&base_attributes[0] },
    {BLUNT,0,NULL,&base_attributes[1] },
    {HAND_TO_HAND,0,NULL,&base_attributes[2] },
    {ARMORER,0,NULL,&base_attributes[3] },
    {BLOCK,0,NULL,&base_attributes[4] },
    {HEAVY_ARMOR,0,NULL,&base_attributes[5] },
    {ATHLETICS,0,NULL,&base_attributes[6] },
    {ACROBATICS,0,NULL,&base_attributes[7] },
    {LIGHT_ARMOR,0,NULL,&base_attributes[8] },
    {SECURITY,0,NULL,&base_attributes[9] },
    {SNEAK,0,NULL,&base_attributes[10] },
    {MARKSMAN,0,NULL,&base_attributes[11] },
    {MERCANTILE,0,NULL,&base_attributes[12] },
    {SPEECHCRAFT,0,NULL,&base_attributes[13] },
    {ILLUSION,0,NULL,&base_attributes[14] },
    {ALCHEMY,0,NULL,&base_attributes[15] },
    {CONJURATION,0,NULL,&base_attributes[16] },
    {MYSTICISM,0,NULL,&base_attributes[17] },
    {ALTERATION,0,NULL,&base_attributes[18] },
    {DESTRUCTION,0,NULL,&base_attributes[19] },
    {RESTORATION,0,NULL,&base_attributes[20] }
};

struct SPECIALIZATION specializations[3] = {
  {COMBAT,NULL},
  {STEALTH,NULL},
  {MAGIC,NULL}
};
struct RACE base_races[20];

// struct CLASS {
//   struct SKILL * major_skills[7];
//   struct ATTRIBUTE * favored_attributes[2];
//   struct SPECIALIZATION * specialization;
// };

struct CLASS base_classes = {
  { &base_skills[1], &base_skills[3], &base_skills[8],
  &base_skills[11], &base_skills[14], &base_skills[16],
  &base_skills[20] },
  {&base_attributes[1], &base_attributes[7]},
  &specializations[2]
};

//struct BIRTH base_birth = NULL;

struct CHARACTER character;

void start_variables(){
 // This section is from STRENGHT ... to WILLPOWER
 base_attributes[0].skills[0] = &base_skills[0];
 base_attributes[0].skills[1] = &base_skills[1];
 base_attributes[0].skills[2] = &base_skills[2];

 base_attributes[1].skills[0] = &base_skills[3];
 base_attributes[1].skills[1] = &base_skills[4];
 base_attributes[1].skills[2] = &base_skills[5];

 base_attributes[2].skills[0] = &base_skills[6];
 base_attributes[2].skills[1] = &base_skills[7];
 base_attributes[2].skills[2] = &base_skills[8];

 base_attributes[3].skills[0] = &base_skills[9];
 base_attributes[3].skills[1] = &base_skills[10];
 base_attributes[3].skills[2] = &base_skills[11];

 base_attributes[4].skills[0] = &base_skills[12];
 base_attributes[4].skills[1] = &base_skills[13];
 base_attributes[4].skills[2] = &base_skills[14];

 base_attributes[5].skills[0] = &base_skills[15];
 base_attributes[5].skills[1] = &base_skills[16];
 base_attributes[5].skills[2] = &base_skills[17];

 base_attributes[6].skills[0] = &base_skills[18];
 base_attributes[6].skills[1] = &base_skills[19];
 base_attributes[6].skills[2] = &base_skills[20];

 for(int i=0; i<7; i++)
   base_skills[i].specialization = &specializations[0];
 for(int i=7; i<14; i++)
   base_skills[i].specialization = &specializations[1];
 for(int i=14; i<21; i++)
   base_skills[i].specialization = &specializations[2];

 specializations[0].spec_skills[0] = &base_skills[0];
 specializations[0].spec_skills[1] = &base_skills[1];
 specializations[0].spec_skills[2] = &base_skills[2];
 specializations[0].spec_skills[3] = &base_skills[3];
 specializations[0].spec_skills[4] = &base_skills[4];
 specializations[0].spec_skills[5] = &base_skills[5];
 specializations[0].spec_skills[6] = &base_skills[6];

 specializations[1].spec_skills[0] = &base_skills[7];
 specializations[1].spec_skills[1] = &base_skills[8];
 specializations[1].spec_skills[2] = &base_skills[9];
 specializations[1].spec_skills[3] = &base_skills[10];
 specializations[1].spec_skills[4] = &base_skills[11];
 specializations[1].spec_skills[5] = &base_skills[12];
 specializations[1].spec_skills[6] = &base_skills[13];

 specializations[2].spec_skills[0] = &base_skills[14];
 specializations[2].spec_skills[1] = &base_skills[15];
 specializations[2].spec_skills[2] = &base_skills[16];
 specializations[2].spec_skills[3] = &base_skills[17];
 specializations[2].spec_skills[4] = &base_skills[18];
 specializations[2].spec_skills[5] = &base_skills[19];
 specializations[2].spec_skills[6] = &base_skills[20];

 base_races[0].name = ARGONIAN;
 base_races[1].name = ARGONIAN;
 base_races[2].name = BRETON;
 base_races[3].name = BRETON;
 base_races[4].name = DARK_ELF;
 base_races[5].name = DARK_ELF;
 base_races[6].name = HIGH_ELF;
 base_races[7].name = HIGH_ELF;
 base_races[8].name = IMPERIAL;
 base_races[9].name = IMPERIAL;
 base_races[10].name = KHAJIIT;
 base_races[11].name = KHAJIIT;
 base_races[12].name = NORD;
 base_races[13].name = NORD;
 base_races[14].name = ORC;
 base_races[15].name = ORC;
 base_races[16].name = REDGUARD;
 base_races[17].name = REDGUARD;
 base_races[18].name = WOOD_ELF;
 base_races[19].name = WOOD_ELF;

 for(int i = 0; i<20; i++){
   if(i%2 ==0)
     base_races[i].gender = MALE;
   else
     base_races[i].gender = FEMALE;

 }

 for(int i=0; i<20; i++){
   for(int j=0; j<8; j++){
     base_races[i].attributes[j].name = base_attributes[j].name;
     // printf("base_attributes[%d] = %s.\n",j,base_attributes[j].name );
   }
 }
 {
   int preset[20][8] = { // https://en.uesp.net/wiki/Oblivion:Races
     {40,40,30,50,50,30,30,50},
     {40,50,40,40,40,30,30,50},
     {40,50,50,30,30,30,40,50},
     {30,50,50,30,40,30,40,50},
     {40,40,30,40,50,40,30,50},
     {40,40,30,40,50,30,40,50},
     {30,50,40,40,30,40,40,50},
     {30,50,40,40,40,30,40,50},
     {40,40,30,30,40,40,50,50},
     {40,40,40,30,30,40,50,50},
     {40,40,30,50,40,30,40,50},
     {30,40,30,50,40,40,40,50},
     {50,30,30,40,40,50,30,50},
     {50,30,40,40,40,40,30,50},
     {45,30,50,35,30,50,30,50},
     {45,40,45,35,30,50,25,50},
     {50,30,30,40,40,50,30,50},
     {40,30,30,40,40,50,40,50},
     {30,40,30,50,50,40,30,50},
     {30,40,30,50,50,30,40,50}
   };

   int setpre[20][8]; // https://en.uesp.net/wiki/Oblivion:Skills
     
   for(int i=0; i<20; i++){
     for(int j=0; j<8; j++){
       switch (j){
         case 0: setpre[i][0] = preset[i][j]; break;
         case 1: setpre[i][5] = preset[i][j]; break;
         case 2: setpre[i][6] = preset[i][j]; break;
         case 3: setpre[i][3] = preset[i][j]; break;
         case 4: setpre[i][2] = preset[i][j]; break;
         case 5: setpre[i][1] = preset[i][j]; break;
         case 6: setpre[i][4] = preset[i][j]; break;
         case 7: setpre[i][7] = preset[i][j]; break;
       };
     }
   }

   for(int i=0; i<20; i++){
     for(int j=0; j<8; j++){
       base_races[i].attributes[j].level = setpre[i][j];
     }
   }
 }

  // INICIAR CHARACTER
  character.race = base_races[8];
  character.class = base_classes;
  character.birth = NULL;


  for (int i=0; i<21; i++){
    character.skills[i].name = base_skills[i].name;
    character.skills[i].level = base_skills[i].level + MINIMUM_LEVEL;
    character.skills[i].specialization = base_skills[i].specialization;
    character.skills[i].governing_attribute = base_skills[i].governing_attribute;
  }
  printf("SKILLS sem adicionais\n");
  for(int i=0; i<21; i++){
    printf("%-12s - %2d.\n", character.skills[i].name, character.skills[i].level);
  }
  for (int i=0; i<21; i++){
    if(character.skills[i].specialization == character.class.specialization){
      character.skills[i].level += 5;
    }
  }
  printf("SKILLS com +5 da escola da classe/skill.\n");
  for(int i=0; i<21; i++){
    printf("%-12s - %2d.\n", character.skills[i].name, character.skills[i].level);
  }
  for (int i=0; i<21; i++){
    for(int j=0; j<7; j++){
      if(&(character.skills[i]) == character.class.major_skills[j]){
        character.skills[i].level += 20;
        break;
      }
    }
  }
  printf("SKILLS com +5 da escola da classe/skill e major_skills\n");
  for(int i=0; i<21; i++){
    printf("%-12s - %2d.\n", character.skills[i].name, character.skills[i].level);
  }
}




int main(){
  int i=0, j=0;
  int soma_atributos=0;

  start_variables();
  return 0;
}
