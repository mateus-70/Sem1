// Autor: Mateus Schroeder da Silva
// It is what it is.
// It is not much but
// It is honest work
//
//

#include <stdio.h>
#include <stdlib.h>
#include "frutas.h"
#include <string.h>
#include <ctype.h>

#define FRUTAS_CONSUMIDAS_DIA 3
#define MAX_FRUTAS 4
//
//  It is true that we cannot be free from bugs, but at least let our bugs not always the same...
//  tamanegi


struct FRUTAS frutas[10];

struct CONSUMO {
  char nome_fruta[40];
  int qtde_por_fruta; 
};

void iniciar_frutas(){
  // banana
  sprintf(frutas[0].nome, "BANANA");
  sprintf(frutas[0].cor_nutricional, COR_BRANCA);
  frutas[0].calorias = 89;
  frutas[0].propriedades[0] = VITAMINA_C;
  frutas[0].propriedades[1] = VITAMINA_B6;
  frutas[0].propriedades[2] = VITAMINA_A;
  frutas[0].propriedades[3] = POTASSIO;
  frutas[0].propriedades[4] = FOSFORO;
  frutas[0].propriedades[5] = MAGNESIO;
  frutas[0].propriedades[6] = ZINCO;
  frutas[0].propriedades[7] = FIM_PROPRIEDADES;

  // printf("%s", frutas[0].nome);
  
  // maca
  sprintf(frutas[1].nome, "MACA");
  sprintf(frutas[1].cor_nutricional, COR_VERMELHA);
  frutas[1].calorias = 55;
  frutas[1].propriedades[0] = VITAMINA_B1;
  frutas[1].propriedades[1] = VITAMINA_B2;
  frutas[1].propriedades[2] = FOSFORO;
  frutas[1].propriedades[3] = FERRO;
  frutas[1].propriedades[4] = FIM_PROPRIEDADES;

  // mamao
  sprintf(frutas[2].nome, "MAMAO");
  sprintf(frutas[2].cor_nutricional, COR_LARANJA);
  frutas[2].calorias = 108;
  frutas[2].propriedades[0] = VITAMINA_A;
  frutas[2].propriedades[1] = VITAMINA_C;
  frutas[2].propriedades[2] = CALCIO;
  frutas[2].propriedades[3] = FERRO;
  frutas[2].propriedades[4] = POTASSIO;
  frutas[2].propriedades[5] = LICOPENO;
  frutas[2].propriedades[6] = FIBRAS;
  frutas[2].propriedades[7] = FIM_PROPRIEDADES;

  // tangerina
  sprintf(frutas[3].nome, "TANGERINA");
  sprintf(frutas[3].cor_nutricional, COR_LARANJA);
  frutas[3].calorias = 40;
  frutas[3].propriedades[0] = VITAMINA_C;
  frutas[3].propriedades[1] = VITAMINA_A;
  frutas[3].propriedades[2] = VITAMINA_B6;
  frutas[3].propriedades[3] = TIAMINA;
  frutas[3].propriedades[4] = FOLATO;
  frutas[3].propriedades[5] = POTASSIO;
  frutas[3].propriedades[6] = CALCIO;
  frutas[3].propriedades[7] = FERRO;
  frutas[3].propriedades[8] = MAGNESIO;
}

void imprimir_informacoes_frutas(int index){
  fprintf(stdout,"Nome da fruta: %s.\n", frutas[index].nome);
  fprintf(stdout,"Calorias: %d.\n", frutas[index].calorias);
  fprintf(stdout,"Cor nutricional: %s.\n", frutas[index].cor_nutricional);
  for(int i=0; frutas[index].propriedades[i] != 0; i++)
    fprintf(stdout,"%s\n", frutas[index].propriedades[i]);
  putchar('\n');
}

void removerFimDeLinha(char * str){
  int i=0;
  while(str[i] != 0 && str[i] != '\n')
    i++;
  if (str[i] == '\n')
    str[i] = 0;
}

void strToUpper(char *str){
  int i=0;
  char a;
  do{
    a = toupper(str[i]);
    str[i++]=a;
    // printf("ROCKS!%s\n",str);
  }while(a != 0);
  
}

void obterConsumo(struct CONSUMO *cons){
//char *nome[], int *qtde
  char str_qtde[4][5];
  char ordenacao[3][40] = {"primeira", "segunda", "terceira"};
  int k=0;

  printf("Informe as frutas que consumiu hoje.\n");
  for (int i=0; i<FRUTAS_CONSUMIDAS_DIA; i++){
    //int j=0;
    printf("Digite a %s fruta: ", ordenacao[k++]);
    fgets(cons[i].nome_fruta, 40, stdin);
    removerFimDeLinha(cons[i].nome_fruta);
    strToUpper(cons[i].nome_fruta);
    printf("Quantas unidades? ");
    fgets(str_qtde[i], 4, stdin);
    removerFimDeLinha(str_qtde[i]);
    cons[i].qtde_por_fruta = atoi(str_qtde[i]);
  }
}

void obterInformacao(void){
  char nome_fruta[40];
  printf("Digite alguma das frutas para obter informacao: ");
  for(int i=0; i<MAX_FRUTAS; i++)
    printf("%s, ", frutas[i].nome);
  printf(".\nFruta: ");
  fgets(nome_fruta, 40, stdin);
  removerFimDeLinha(nome_fruta);
  strToUpper(nome_fruta);

  for(int i=0; i<MAX_FRUTAS; i++){
    if(!strcmp(nome_fruta, frutas[i].nome)){
      imprimir_informacoes_frutas(i);
    }
  }
}

int main(void){
//  char frutas_consumidas_str_qtde[4][5];
  struct CONSUMO consumo[FRUTAS_CONSUMIDAS_DIA];
  short vermelhas=0, brancas=0, laranjas=0;


  iniciar_frutas();
  // for(int i=0; i<4; i++)
  //  imprimir_informacoes_frutas(i);
  printf("Programa de auxilio nutricional.\n");

  obterInformacao();

  obterConsumo(consumo);

  for(int i=0; i < FRUTAS_CONSUMIDAS_DIA; i++){
    for(int j=0; j < MAX_FRUTAS; j++)
      if(!strcmp(consumo[i].nome_fruta, frutas[j].nome)){
        //printf("i=%d,j=%d.",i,j);
        if(!strcmp(frutas[j].cor_nutricional, COR_BRANCA))
          brancas++;
          // Premature Optimization is the Root of All Evil!
        if(!strcmp(frutas[j].cor_nutricional, COR_LARANJA))
          laranjas++;
          // TRASH CODE IKR! 4 aninhamento pai do seo!
        if(!strcmp(frutas[j].cor_nutricional, COR_VERMELHA))
          vermelhas++;
      }
  } 
  if(vermelhas > 1 || brancas > 1 || laranjas > 1)
    printf("Consumir frutas de cores diferentes eh mais saudavel!\n");
    // printf("Consumir frutas de cores diferentes eh mais saudavel!%d-%d-%d\n", vermelhas,brancas,laranjas);
  else
    printf("Procure consumir 3 frutas ao dia, de cores diferentes.\n");
    // printf("Procure consumir 3 frutas ao dia, de cores diferentes.%d-%d-%d.\n", vermelhas,brancas,laranjas);

  return 0;
}
