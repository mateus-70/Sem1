#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  /* VARIAVEIS DA OPCAO DE COMPRA DO CLIENTE */
  int categoria=0;

  /*  VARIAVEIS DO CLIENTE  */
  char nome_cliente[30]="Valor_inicial", eh_fora_estado_sao_paulo=0, nome_computador[30];
  char cep[30];
  char endereco[30];

  /*  VARIAVEIS GERAIS */
  float total_nota=0;
  float parcial_nota=0;
  float frete=0;

  /*  VARIAVEIS DO COMPUTADOR */
  int escolha_computador=0;
  float preco_apple=9599.00, preco_intel=1589.16, preco_amd=2748.00, valor_computador=0;
  float acrescimo_importacao=0, acrescimo_fora_sp=0;
  float total_computador=0;

  /* VARIAVEIS DOS ALIMENTOS */
  char cafe[]="Cafe", 
       pipoca[]="Pipoca", 
       creme_leite[]="Creme de Leite", 
       macarrao[]="macarrao", 
       laranja[]="Laranja";
  const int id_cafe=1, id_pipoca=2, id_creme_leite=3, id_macarrao=4, id_laranja=5;

//  int cafe_un, pipoca_un, creme_leite_un, macarrao_un;
//  float laranja_kg;

  int id_alimento1=0, id_alimento2=0, qtde_alimento_un1=0, qtde_alimento_un2=0;

  float preco_cafe=57.04, 
        preco_pipoca=1.88, 
        preco_creme_leite=6.57, 
        preco_macarrao=7.7, 
        preco_laranja=8.15;

  float qtde_alimento_kg1=0, qtde_alimento_kg2=0;
  float total_alimento1=0;
  float total_alimento2=0;
  float total_alimentos=0;

  

  printf("Digite seu nome: ");
  scanf("%s", nome_cliente);

  printf("Digite seu endereco: ");
  scanf("%s", endereco);

  printf("Digite seu CEP: ");
  scanf("%s", cep);

  printf("Digite categoria compra: \n");

  printf("1 - Somente computador\n");
  printf("2 - Somente alimentos\n");
  printf("3 - Ambos\n");
  scanf("%d", &categoria);

  printf("OBS: A entrega eh para fora do estado de Sao Paulo? (S/N)\n");
  scanf(" %c", &eh_fora_estado_sao_paulo);

  if(categoria == 1){
    printf("Escolha seu computador:\n");
    printf("1 - R$ 9599,00  Apple MacBook Pro\n");
    printf("2 - R$ 1589,16  PC CPU Intel Core I5\n");
    printf("3 - R$ 2748,00  PC Gamer Completo AMD 6-Core\n");
    scanf("%d", &escolha_computador);

    if(escolha_computador == 1){
      valor_computador = preco_apple;
      strcpy(nome_computador, "Apple MacBook Pro");
    }
    if(escolha_computador == 2){
      valor_computador = preco_intel;
      strcpy(nome_computador, "PC CPU Intel Core I5");
    }
    if(escolha_computador == 3){
      valor_computador = preco_amd;
      strcpy(nome_computador, "PC Gamer Completo AMD");
    }

    printf("\n\n%s\n", nome_cliente);
    printf("%s %-30s - %.2f.\n","Pedido:", nome_computador, valor_computador);

    if(escolha_computador == 1){
      acrescimo_importacao = preco_apple*0.10;
      printf("%-30s - %.2f\n", "Aliquota importacao", acrescimo_importacao);
    }
    if(eh_fora_estado_sao_paulo == 'S'){ // calculando sobre o bruto
      acrescimo_fora_sp=0.05*valor_computador;
      printf("%-30s - %.2f\n", "ICMS", acrescimo_fora_sp);
    }
    
    parcial_nota = valor_computador + acrescimo_importacao + acrescimo_fora_sp;
    if(parcial_nota < 1500.){
      printf("Frete: .......%.2f\n", 80.);
      frete = 80.;
    } else{
      printf("Frete gratis\n");
      frete=0;
    }
    total_nota = parcial_nota + frete;
    printf("%-30s - %.2f.\n", "Total da nota:", total_nota);

    printf("Entrega: %s - %s.\n\n", endereco, cep);
    // Would be good if there was no problem with \n on scanf!
  }else if(categoria == 2){
    printf("Bem-vindo(a) escolha das frutas!\n");
    printf("Para este programa, voce podera escolher 2 opcoes de alimentos!\n");
    printf("Escolha conforme abaixo: \n");
    printf("%d - %s.\n", id_cafe, cafe);
    printf("%d - %s.\n", id_pipoca, pipoca);
    printf("%d - %s.\n", id_creme_leite, creme_leite);
    printf("%d - %s.\n", id_macarrao, macarrao);
    printf("%d - %s.\n", id_laranja, laranja);

    printf("Digite o codigo do alimento: ");
    scanf("%d", &id_alimento1);
    if(id_alimento1 != 5){
      printf("Quantidade (unidades): ");
      scanf("%d", &qtde_alimento_un1);
    }else{
      printf("Quantidade (kg): ");
      scanf("%f", &qtde_alimento_kg1);
    }

    printf("Digite o codigo do alimento: ");
    scanf("%d", &id_alimento2);
    if(id_alimento2 != 5){
      printf("Quantidade (unidades): ");
      scanf("%d", &qtde_alimento_un2);
    }else{
      printf("Quantidade (kg): ");
      scanf("%f", &qtde_alimento_kg2);
    }

    printf("Nome: %s.\n", nome_cliente);

    printf("Pedido: \n");

    switch (id_alimento1){
      case 1: total_alimento1 = preco_cafe*qtde_alimento_un1;
        printf("%-30s - %.2f\n", cafe, preco_cafe*qtde_alimento_un1);
      break;
      case 2: total_alimento1 = preco_pipoca*qtde_alimento_un1;
        printf("%-30s - %.2f\n", pipoca, preco_pipoca*qtde_alimento_un1);
      break;
      case 3: total_alimento1 = preco_creme_leite*qtde_alimento_un1;
        printf("%-30s - %.2f\n", creme_leite, preco_creme_leite*qtde_alimento_un1);
      break;
      case 4: total_alimento1 = preco_macarrao*qtde_alimento_un1;
        printf("%-30s - %.2f\n", macarrao, preco_macarrao*qtde_alimento_un1);
      break;
      case 5: total_alimento1 = preco_laranja*qtde_alimento_kg1;
        printf("%-30s - %.2f\n", laranja, preco_laranja*qtde_alimento_kg1);
      break;
    }

    switch (id_alimento2){
      case 1: total_alimento2 = preco_cafe*qtde_alimento_un2;
        printf("%-30s - %.2f\n", cafe, preco_cafe*qtde_alimento_un2);
      break;
      case 2: total_alimento2 = preco_pipoca*qtde_alimento_un2;
        printf("%-30s - %.2f\n", pipoca, preco_pipoca*qtde_alimento_un2);
      break;
      case 3: total_alimento2 = preco_creme_leite*qtde_alimento_un2;
        printf("%-30s - %.2f\n", creme_leite, preco_creme_leite*qtde_alimento_un2);
      break;
      case 4: total_alimento2 = preco_macarrao*qtde_alimento_un2;
        printf("%-30s - %.2f\n", macarrao, preco_macarrao*qtde_alimento_un2);
      break;
      case 5: total_alimento2 = preco_laranja*qtde_alimento_kg2;
        printf("%-30s - %.2f\n", laranja, preco_laranja*qtde_alimento_kg2);
      break;
    }
    parcial_nota = total_alimento1 + total_alimento2;
    if(parcial_nota < 1500.){
      frete=80.;
    }else{
      frete=0;
    }
    if(eh_fora_estado_sao_paulo == 'S'){ // calculando sobre o bruto
      acrescimo_fora_sp=0.05*parcial_nota;
      printf("%-30s - %.2f\n", "ICMS", acrescimo_fora_sp);
    }
    total_nota = parcial_nota + frete;
    if(frete < 0.0001)
      printf("Frete gratis");
    else
      printf("%-30s - %.2f.\n","Frete", frete );
    printf("%-30s - %.2f.\n", "Total nota", total_nota);
    // printf("Would work fine if there was not a p\nr\no\nb\nl\ne\nm!");
    
  }else if(categoria == 3){

    printf("Escolha seu computador:\n");
    printf("1 - R$ 9599,00  Apple MacBook Pro\n");
    printf("2 - R$ 1589,16  PC CPU Intel Core I5\n");
    printf("3 - R$ 2748,00  PC Gamer Completo AMD 6-Core\n");
    scanf("%d", &escolha_computador);

    if(escolha_computador == 1){
      valor_computador = preco_apple;
      strcpy(nome_computador, "Apple MacBook Pro");
    }
    if(escolha_computador == 2){
      valor_computador = preco_intel;
      strcpy(nome_computador, "PC CPU Intel Core I5");
    }
    if(escolha_computador == 3){
      valor_computador = preco_amd;
      strcpy(nome_computador, "PC Gamer Completo AMD");
    }

    printf("%s\n", nome_cliente);

    if(escolha_computador == 1){
      acrescimo_importacao = preco_apple*0.10;
    }
    if(eh_fora_estado_sao_paulo == 'S'){ // calculando sobre o bruto
      acrescimo_fora_sp=0.05*valor_computador; 
    }
    total_computador = valor_computador + acrescimo_importacao+acrescimo_fora_sp;
    // Would be good if there was no problem with \n on scanf!
 
    printf("\nBem-vindo(a) escolha das frutas!\n");
    printf("Para este programa, voce podera escolher 2 opcoes de alimentos!\n");
    printf("Escolha conforme abaixo: \n");
    printf("%d - %s.\n", id_cafe, cafe);
    printf("%d - %s.\n", id_pipoca, pipoca);
    printf("%d - %s.\n", id_creme_leite, creme_leite);
    printf("%d - %s.\n", id_macarrao, macarrao);
    printf("%d - %s.\n", id_laranja, laranja);

    printf("Digite o codigo do alimento: ");
    scanf("%d", &id_alimento1);
    if(id_alimento1 != 5){
      printf("Quantidade (unidades): ");
      scanf("%d", &qtde_alimento_un1);
    }else{
      printf("Quantidade (kg): ");
      scanf("%f", &qtde_alimento_kg1);
    }

    printf("Digite o codigo do alimento: ");
    scanf("%d", &id_alimento2);
    if(id_alimento2 != 5){
      printf("Quantidade (unidades): ");
      scanf("%d", &qtde_alimento_un2);
    }else{
      printf("Quantidade (kg): ");
      scanf("%f", &qtde_alimento_kg2);
    }

    printf("%-30s - %s.\n", "Nome", nome_cliente);

    switch (id_alimento1){
      case 1: total_alimento1 = preco_cafe*qtde_alimento_un1;
        printf("%-30s - %.2f\n", cafe, preco_cafe*qtde_alimento_un1);
      break;
      case 2: total_alimento1 = preco_pipoca*qtde_alimento_un1;
        printf("%-30s - %.2f\n", pipoca, preco_pipoca*qtde_alimento_un1);
      break;
      case 3: total_alimento1 = preco_creme_leite*qtde_alimento_un1;
        printf("%-30s - %.2f\n", creme_leite, preco_creme_leite*qtde_alimento_un1);
      break;
      case 4: total_alimento1 = preco_macarrao*qtde_alimento_un1;
        printf("%-30s - %.2f\n", macarrao, preco_macarrao*qtde_alimento_un1);
      break;
      case 5: total_alimento1 = preco_laranja*qtde_alimento_kg1;
        printf("%-30s - %.2f\n", laranja, preco_laranja*qtde_alimento_kg1);
      break;
    }

    switch (id_alimento2){
      case 1: total_alimento2 = preco_cafe*qtde_alimento_un2;
        printf("%-30s - %.2f\n", cafe, preco_cafe*qtde_alimento_un2);
      break;
      case 2: total_alimento2 = preco_pipoca*qtde_alimento_un2;
        printf("%-30s - %.2f\n", pipoca, preco_pipoca*qtde_alimento_un2);
      break;
      case 3: total_alimento2 = preco_creme_leite*qtde_alimento_un2;
        printf("%-30s - %.2f\n", creme_leite, preco_creme_leite*qtde_alimento_un2);
      break;
      case 4: total_alimento2 = preco_macarrao*qtde_alimento_un2;
        printf("%-30s - %.2f\n", macarrao, preco_macarrao*qtde_alimento_un2);
      break;
      case 5: total_alimento2 = preco_laranja*qtde_alimento_kg2;
        printf("%-30s - %.2f\n", laranja, preco_laranja*qtde_alimento_kg2);
      break;
    }

    total_alimentos = total_alimento1 + total_alimento2;
    if(eh_fora_estado_sao_paulo == 'S'){ // calculando sobre o bruto
      acrescimo_fora_sp = total_alimentos*0.05;
      printf("%-30s - %.2f.\n", "ICMS", acrescimo_fora_sp);
      total_alimentos += acrescimo_fora_sp;
    }
    printf("%-30s - %.2f.\n", "Total alimentos:", total_alimentos);

    printf("%-30s - %.2f.\n", nome_computador, valor_computador);
    if(escolha_computador == 1){
      printf("%-30s - %.2f.\n", "Aliquota importacao", acrescimo_importacao);
    }
    if(eh_fora_estado_sao_paulo == 'S'){ // calculando sobre o bruto
      acrescimo_fora_sp=0.05*valor_computador; // recalcula...
      printf("%-30s - %.2f.\n", "ICMS", acrescimo_fora_sp);
    }
    total_computador = valor_computador + acrescimo_importacao+acrescimo_fora_sp;
    parcial_nota = total_alimentos + total_computador;
    printf("%-30s - %.2f.\n", "Total computador:", total_computador); // not sure i did print the taxes btw.
    if(parcial_nota < 1500.){
      printf("%-30s - %.2f.\n", "Frete", frete);
    }else{
      printf("Frete gratis.\n");  
    }
    total_nota = parcial_nota + frete;
    printf("%-30s - %.2f.\n", "Total nota", total_nota);
    printf("%-30s - %s - %s.\n", "Entrega:", endereco, cep);
    
   

  }

  return 0;   
}
