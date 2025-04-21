#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO_LINHA 150 

int atualizar_exercicios(void){  
  FILE * arquivo;
  char linha[TAMANHO_LINHA], nome_arquivo[100], observacao_questao[TAMANHO_LINHA-50], subitem_questao[6];
  short selecao_obra, num_questao, num_lista_capitulo=-1;
  char limpa_buffer_entrada, entrada[10];



  printf("Escolha o arquivo para carregar no modo a+: \n");
  printf("1 - CDI-II_lista1.txt\n");
  printf("2 - LMA_lista1.txt\n");
  printf("3 - CALCULO A\n");
  printf("4 - CALCULO B\n");
  // scanf("%d", &selecao_obra);
  fgets(entrada, 3, stdin);
  selecao_obra = atoi(entrada);

  // while((limpa_buffer_entrada = getchar()) != '\n' && limpa_buffer_entrada != EOF)
    /* discard */ ;

  printf("Numero da lista ou capitulo: ");
  // scanf("%d", &num_lista_capitulo);
  fgets(entrada, 4, stdin);
  num_lista_capitulo = atoi(entrada);


  switch (selecao_obra){
    case 1: 
      sprintf(nome_arquivo, "./LISTA/CDI-II/CDI-II_Lista%d.txt", num_lista_capitulo);
      break;
    case 2: 
      sprintf(nome_arquivo, "./LISTA/LMA/LMA_Lista%d.txt", num_lista_capitulo);
      break;
    case 3: 
      sprintf(nome_arquivo, "./CALCULO_A/Calculo_A_cap%d.txt", num_lista_capitulo);
      break;
    case 4: 
      sprintf(nome_arquivo, "./CALCULO_B/Calculo_B_cap%d.txt", num_lista_capitulo);
      break;
      default:
        fprintf(stderr, "Erro: Codigo invalido!\n");
        return 1;
  }
  arquivo = fopen(nome_arquivo, "a+");
  if(arquivo == NULL){
    fprintf(stderr, "Erro: Falha ao abrir arquivo.\n");
    return 1;
  }
  printf("\n\n \t\t EXERCICIOS FEITOS \n\n");
  while(fgets(linha, sizeof(linha), arquivo)){
    printf("%s\n", linha);
  }
  printf("\n\n");

  printf("Numero da questao: ");
  // while((limpa_buffer_entrada = getchar()) != '\n' && limpa_buffer_entrada != EOF)
	  /* discard */ ;
  // scanf("%d", &num_questao);
  fgets(entrada, 5, stdin);
  num_questao = atoi(entrada);

  printf("Subitem da questao: ");
  // while((limpa_buffer_entrada = getchar()) != '\n' && limpa_buffer_entrada != EOF)
	  /* discard */ ;
  fgets(subitem_questao, 5, stdin);
  subitem_questao[strlen(subitem_questao)-1] = '\0';
  // for(int i=0; i<5; i++) if(subitem_questao[i] == '\n') subitem_questao[i] = '\0';

  printf("Observacao: ");
  // while((limpa_buffer_entrada = getchar()) != '\n' && limpa_buffer_entrada != EOF)
	 /* discard */ ;
  fgets(observacao_questao, 100, stdin);
  if(observacao_questao[0] == '\n') strcpy(observacao_questao, "Nenhuma.\n");

  fprintf(arquivo, "%02d -- %s -- %s", num_questao, subitem_questao, observacao_questao);

  fclose(arquivo);
}

int main(){
  if (!atualizar_exercicios()){
    printf("Concluido!\n\n");
  }else{
    printf("Falha, tente novamente!\n\n");
  }
  return 0;
}
