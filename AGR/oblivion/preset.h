#define ARGONIAN_MALE_ATTRIBUTES 0
#define ARGONIAN_FEMALE_ATTRIBUTES 1 
#define BRETON_MALE_ATTRIBUTES 2
#define BRETON_FEMALE_ATTRIBUTES 3 
#define DARK_ELF_MALE_ATTRIBUTES 4
#define DARK_ELF_FEMALE_ATTRIBUTES 5 
#define HIGH_ELF_MALE_ATTRIBUTES 6 
#define HIGH_ELF_FEMALE_ATTRIBUTES 7
#define IMPERIAL_MALE_ATTRIBUTES 8
#define IMPERIAL_FEMALE_ATTRIBUTES 9 
#define KHAJIIT_MALE_ATTRIBUTES 10
#define KHAJIIT_FEMALE_ATTRIBUTES 11
#define NORD_MALE_ATTRIBUTES 12
#define NORD_FEMALE_ATTRIBUTES 13
#define ORC_MALE_ATTRIBUTES 14
#define ORC_FEMALE_ATTRIBUTES 15
#define REDGUARD_MALE_ATTRIBUTES 16 
#define REDGUARD_FEMALE_ATTRIBUTES 17
#define WOOD_ELF_MALE_ATTRIBUTES 18
#define WOOD_ELF_FEMALE_ATTRIBUTES 19

#define COMBAT "Combat"
#define STEALTH "Stealth"
#define MAGIC "Magic"

#define BLADE "Blade"
#define BLUNT "Blunt"
#define HAND_TO_HAND "Hand to Hand"
#define ARMORER "Armorer"
#define BLOCK "Block"
#define HEAVY_ARMOR "Heavy Armor"
#define ATHLETICS "Athletics"
#define ACROBATICS "Acrobatics"
#define LIGHT_ARMOR "Light Armor"
#define SECURITY "Security"
#define SNEAK "Sneak"
#define MARKSMAN "Marksman"
#define MERCANTILE "Mercantile"
#define SPEECHCRAFT "Speechcraft"
#define ILLUSION "Illusion"
#define ALCHEMY "Alchemy"
#define CONJURATION "Conjuration"
#define MYSTICISM "Mysticism"
#define ALTERATION "Alteration"
#define DESTRUCTION "Destruction"
#define RESTORATION "Restoration"

#define ARGONIAN "Argonian"
#define BRETON "Breton"
#define DARK_ELF "Dark Elf"
#define HIGH_ELF "High Elf"
#define IMPERIAL "Imperial"
#define KHAJIIT "Khajiit"
#define NORD "Nord"
#define ORC "Orc"
#define REDGUARD "Redguard"
#define WOOD_ELF "Wood Elf"

#define MALE "Male"
#define FEMALE "Female"

#define STRENGTH "Strength"
#define ENDURANCE "Endurance"
#define SPEED "Speed"
#define AGILITY "Agility"
#define PERSONALITY "Personality"
#define INTELLIGENCE "Intelligence"
#define WILLPOWER "Willpower"
#define LUCK "Luck"

#define MINIMUM_LEVEL 5

// struct ATTRIBUTES {
//   int strength, intelligence, willpower,
//       agility, speed, endurance, personality,
//       luck;
// };

struct ATTRIBUTE {
  char * name;
  int level;
  struct SKILL * skills[3];
};

struct SKILL {
  char * name;
  int level;
  struct SPECIALIZATION * specialization;
  struct ATTRIBUTE * governing_attribute;
};

struct SPECIALIZATION {
  char * name;
  struct SKILL * spec_skills[7];
};

struct CLASS {
  struct SKILL * major_skills[7];
  struct ATTRIBUTE * favored_attributes[2];
  struct SPECIALIZATION * specialization;
};

struct RACE {
  char * name;
  char * gender;
  struct ATTRIBUTE attributes[8];
  struct SKILL skills[7];
};

struct BIRTH {
  void * effect;
};

struct CHARACTER {
  struct RACE race;
  struct CLASS class;
  struct BIRTH *birth;

  struct ATTRIBUTE attributes[8];
  struct SKILL skills[21];

  void *(* level_up_skill); // function level up the character
};



