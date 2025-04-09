// Mateus
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


// int raiz_quadrada(void){
// 
//     float a, b, c;
//     float discriminante;
//     printf("Digite valores de a b c para ax^2 + bx + c\n");
//     scanf("%f", &a);
// 
//     scanf("%f", &b);
// 
//     scanf("%f", &c);
// 
//     discriminante = b*b - 4*a*c;
//     if(discriminante < 0) printf("Raizes imaginarias.\n");
//     else if (discriminante - 0 < 0.00001) printf("Apenas uma raiz real: %f.\n", -b/(2*a) );
//     else printf("Duas raizes reais: %f e %f.\n", (-b+ sqrt(discriminante))/ (2*a), (-b-sqrt(discriminante))/(2*a) );
// 
//     return 0;
// }
// 
// struct PONTO{
// float x,y;
// };
// 
// int distancia_pontos(void){
//   struct PONTO P, Q;
//   // struct PONTO Q;
// 
//   printf("Digite x de P: ");
//   scanf("%f", &(P.x));
//   printf("Digite y de P: ");
//   scanf("%f", &(P.y));
//   printf("Digite x de Q: ");
//   scanf("%f", &(Q.x));
//   printf("Digite y de Q: ");
//   scanf("%f", &(Q.y));
//   printf("A distancia entre os pontos eh: %f.\n", sqrt(pow((P.x-Q.x),2) + pow((P.y-Q.y),2)));
//   return 0;
// }
// 
// 
// float volume(const float raio){
//   return (4/3.) * M_PI * pow(raio, 3);
// }
// 
// int ui(void){
//   float raio;
//   printf("Digite o raio: ");
//   scanf("%f", &raio);
//   printf("O volume eh: %f.\n", volume(raio));
//   return 0;
// }

// int ordenar(int *x, int *y, int *z){
//   int maior, menor, meio;
//   int a = *x, b = *y, c = *z;
//   if (a >= b && a >= c){
//     maior = a;
//     if(b >= c){
//       meio = b;
//       menor = c;
//     }else{
//       meio = c;
//       menor = b;
//     }
//   }else{
//     if(b >= c){
//       maior = b;
//       if(a >= c){
//         meio = a;
//         menor = c;
//       }else{
//         meio = c;
//         menor = a;
//       }
//     }else{
//       maior = c;
//       if(a >= b){
//         meio = a;
//         menor = b;
//       }else{
//         meio = b;
//         menor = a;
//       }
//     }
//   }
//   *x = maior;
//   *y = meio;
//   *z = menor;
//   return 0;
// }
// 
// int ui_ordenar(){
//   int num[3];
//   printf("Digite 3 inteiros separados por espaco: ");
//   scanf("%d %d %d", &num[0], &num[1], &num[2]);
//   ordenar(&num[0], &num[1], &num[2]);
//   printf("Os valores inseridos em ordem descrescente eh: %d %d %d.", num[0], num[1], num[2]);
//   return 0;
// }

// int ui_peso(){
//   char sexo;
//   int altura;
// 
//   printf("Wellcome\n ");
//   printf("Sexo (M/F): ");
//   scanf("%c", &sexo);
// 
//   printf("Altura (em cm): ");
//   scanf("%d", &altura);
// 
//   if(toupper(sexo) == 'M'){
//     printf("Seu peso ideal eh: %f.\n", (72.7 * altura / 100) -58);
//   }else if(toupper(sexo) == 'F'){
//           printf("Seu peso ideal eh: %f.\n", (62.1 * altura / 100) - 44.7 );
//         }else printf("rm -rf /");
//   return 0;
// }


// int ui_idade(void){
//   unsigned int dia, mes, ano;
//   printf("Qual sua data de nascimento (dd/mm/aaaa)? ");
//   scanf("%d/%d/%d", &dia, &mes, &ano);
//   
//   return 0;
//   // how to get current time?
// }



// int ui_classifica_produto(){
//   char const alimento_nao_perecivel[] = "alimento nao-perecivel";
//   char const alimento_perecivel[] = "alimento perecivel";
//   char const vestuario[] = "vestuario";
//   char const higiene[] = "higiene";
//   char const limpeza_e_utensilios[] = "limpeza e utensilios domesticos";
//   char const invalido[] = "invalido";
// 
//   struct PRODUTO {
//     unsigned int codigo;
//     char * classificacao;
//   };
// 
//   struct PRODUTO prod1;
// 
//   printf("Codigo do produto: ");
//   scanf("%d", &(prod1.codigo));
// 
//   switch (prod1.codigo){
//     case 1: prod1.classificacao = alimento_nao_perecivel; break;
//     case 2: 
//     case 3: 
//     case 4: 
//             prod1.classificacao = alimento_perecivel; break;
//     case 5: 
//     case 6: 
//             prod1.classificacao = vestuario; break;
//     case 7: 
//             prod1.classificacao = higiene; break;
//     case 8: 
//     case 9: 
//     case 10: 
//     case 11: 
//     case 12: 
//     case 13: 
//     case 14: 
//     case 15: 
//             prod1.classificacao = limpeza_e_utensilios; break;
//     default:
//         prod1.classificacao = invalido;
//   }
//   
//   printf("O produto eh classificado como %s.\n", prod1.classificacao);
// 
//   return 0;
// }

// int ui_classifica_nadador(){
//   char const infantilA[] = "infantil A";
//   char const infantilB[] = "infantil B";
//   char const juvenilA[] = "juvenil A";
//   char const juvenilB[] = "juvenil B";
//   char const adulto[] = "adulto";
// 
//   struct NADADOR {
//     unsigned int idade;
//     char* categoria;
//   };
// 
//   struct NADADOR nadador1;
// 
//   printf("Idade (em anos): ");
//   scanf("%d", &(nadador1.idade));
// 
//   if(nadador1.idade < 5 || nadador1.idade > 100){
//     printf("Erro, idade muito baixa ou muito alta. Verifique.\n\n");
//     return 1;
//   }
// 
//   switch(nadador1.idade){
//     case 5:
//     case 6:
//     case 7:
//       nadador1.categoria= infantilA;
//       break;
//     case 8:
//     case 9:
//     case 10:
//       nadador1.categoria= infantilB;
//       break;
//     case 11:
//     case 12:
//     case 13:
//       nadador1.categoria= juvenilA;
//       break;
//     case 14:
//     case 15:
//     case 16:
//     case 17:
//       nadador1.categoria= juvenilB;
//       break;
//     default:
//       nadador1.categoria = adulto;
//       break;
//   }
// 
//   printf("O nadador eh da categoria %s.\n", nadador1.categoria);
//   return 0;
// }


// int ui_pagamento_produto(){
//   struct PAGAMENTO_PRODUTO {
//     unsigned int forma;
//     unsigned int vezes;
//     float valor_base, desconto, acrescimo, total_cobrado;
//     char descricao_produto[400];
//     
//   };
// 
//   struct PAGAMENTO_PRODUTO pagamento;
// 
//   printf("Valor base do produto: ");
//   scanf("%f", &(pagamento.valor_base));
//   
//   printf("Codigo | Condicao de pagamento\n");
//   printf("     1 | A vista em dinheiro ou cheque (10%% de desconto)\n");
//   printf("     2 | A vista no cartao de credito (5%% de desconto)\n");
//   printf("     3 | Em 2 vezes (preco normal)\n");
//   printf("     4 | Em 3 vezes (10%% a mais em relacao ao preco normal)\n");
// 
//   printf("Escolha a forma de pagamento: ");
//   scanf("%d", &(pagamento.forma));
// 
//   switch (pagamento.forma) {
//     case 1:
//       pagamento.desconto = pagamento.valor_base * 0.1;  
//       break;
//     case 2:
//       pagamento.desconto = pagamento.valor_base * 0.05;  
//       break;
//     case 3:
//       break;
//     case 4:
//       pagamento.acrescimo = pagamento.valor_base * 0.1;  
//       break;
//     default: printf("BREAK!\n"); return 1; 
//   }
//   
//   pagamento.total_cobrado = pagamento.valor_base + pagamento.acrescimo - pagamento.desconto;
// 
//   printf("\n\nOs valores sao: \n");
//   printf("Valor base: %.2f.\n", pagamento.valor_base);
//   printf("Desconto: %.2f.\n", pagamento.desconto);
//   printf("Acrescimo: %.2f.\n", pagamento.acrescimo);
//   printf("Total cobrado: %.2f.\n", pagamento.total_cobrado);
//   return 0;
// }

// int ui_calculadora(){
//   
//   int num1, num2;
//   char op;
// 
//   printf("Digite como no padrao abaixo: \n");
//   printf("3 + 5\n");
//   printf("3 - 5\n");
//   printf("3 * 5\n");
//   printf("3 / 5\n");
//   printf("Sua vez:  ");
// 
//   scanf("%d %c %d", &num1, &op, &num2);
// 
//   switch(op){
//     case '+': printf("= %d.\n", num1 + num2);
//     break;
//     case '-': printf("= %d.\n", num1 - num2);
//     break;
//     case '*': printf("= %d.\n", num1 * num2);
//     break;
//     case '/': printf("= %.2f.\n", num1 / (float) num2);
//     break;
//     default: printf("BREAK!\n\n"); return 1;
//   }
//   return 0;
// }

// int ui_calcula_imc(){
//   float peso, altura, imc;
// 
//   printf("Peso: ");
//   scanf("%f", &peso);
//   printf("Altura (em metros): ");
//   scanf("%f", &altura);
// 
//   if(peso < 0 || altura < 0 || altura > 3){
//     printf("BREAK!!\n\n");
//     return 1;
//   }
// 
//   imc = peso / (altura*altura);
//   printf("IMC = %.2f.\n\n", imc);
// 
//   if(imc < 18.5){
//     printf("Abaixo do peso.\n");
//   }else if(imc < 25){
//     printf("Peso normal.\n");
//   }else if(imc < 30){
//     printf("Acima do peso.\n");
//   }else printf("Obeso.\n");
// 
//   return 0;
// }

int main(void){
  // ui_ordenar();
  // raiz_quadrada();
  // ui_peso();
  // ui_idade();
  // ui_classifica_produto();
  // ui_classifica_nadador();
  // ui_pagamento_produto();
  // ui_calculadora();
  // ui_calcula_imc(); 
  return 0;
}
