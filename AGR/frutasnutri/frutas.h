#define VITAMINA_A "vitamina A"
#define VITAMINA_B "vitamina B"
#define VITAMINA_C "vitamina C"
#define VITAMINA_B1 "vitamina B1"
#define VITAMINA_B2 "vitamina B2"
#define VITAMINA_B6 "vitamina B6"
#define CALCIO "calcio"
#define FERRO "ferro"
#define FIBRAS "fibras"
#define FOLATO "folato"
#define FOSFORO "fosforo"
#define LICOPENO "licopeno"
#define MAGNESIO "magnesio"
#define POTASSIO "potassio"
#define TIAMINA "tiamina"
#define ZINCO "zinco"
#define FIM_PROPRIEDADES 0

#define COR_BRANCA "BRANCA"
#define COR_LARANJA "LARANJA"
#define COR_VERMELHA "VERMELHA"

struct FRUTAS {
  char nome[40];
  int calorias;
  char cor_nutricional[40];
  char *propriedades[40];
};


