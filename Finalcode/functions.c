
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include "functions.h"

double multipli_two_values(double x, double y){
    return x * y;
}

double res_tot(double r1, double r2, double r3){
    return 1/((1/r1) + (1/r2) + (1/r3));
}
double aktiv_eff(double u, double i, double cos){
    return u*i*cos;
}

double sken_3fas(double u, double i){
    return u*i*sqrt(3);
}
double aktiv_3fas(double u, double i, double cos){
    return u * i * sqrt(3) * cos;
}

double input_check(int max_value){
  double input_value;
  scanf("%lf", &input_value);
  while(input_value > max_value){
      printf("För högt värde, försök igen: \n");
      return menu();
  }
    return input_value;
}
void print_unit(char unit){
  if(unit == 'I') printf("Skriv ström Ampere I < 440A: \n");
  if(unit == 'U') printf("Skriv spännngen U i volt(V): \n ");
  if(unit == 'R') printf("Skriv resistans R < 20 000ohm: \n ");

}

int menu(){
  int val;
  printf("\nVälj vilka storheter du vill beräkna:\n"
         "Välj 1 för: OHMS LAG\n"
         "Välj 2 för: Rtot\n"
         "Välj 3 för: EFFEKTLAGEN ENKEL\n"
         "Välj 4 för: SKENBAR EFFEKT ENFAS\n"
         "Välj 5 för: AKTIV EFFEKT/MEDELEFFEKT ENFAS\n"
         "Välj 6 för: SKENBAR EFFEKT 3-FAS\n"
         "Välj 7 för: AKTIV EFFEKT 3-FAS\n"
         "Välj 8 för: Räkna ut elpris:\n"
         "Välj 0 för: FÖR ATT AVSLUTA\n");
  scanf("%d", &val);
  return val;
}
void choice_one(void){
  printf("Ohms lag spänningen(volt/V) betäckning U lika med Resistansen(Ohm) betäckning R \n"
         "gånger Strömmen(Ampere) med betäckningen I. Kort U=R*I. \n\n");
  print_unit('R');
  value_1 = input_check(MAX_RES);
  print_unit('I');
  value_2 = input_check(MAX_AMP);
  printf("%f V\n", multipli_two_values(value_1, value_2));
}

void choice_two(void){
  printf("Resistans sammankopplade i parallella kretsar är lika med 1 delat Resistans R total är lika med\n"
         "Resistans 1/R1 + 1/R2 + 1/R3 då vi högst använder tre resistanser.\n\n"
         "Skriv resistans R1 < 20 000ohm: \n ");
  value_1 = input_check(MAX_RES);
  printf("Skriv resistans R2 < 20 000ohm: \n ");
  value_2 = input_check(MAX_RES);
  printf("Skriv resistans R3 < 20 000ohm: \n ");
  value_3 = input_check(MAX_RES);

  printf("%f Ohm\n", res_tot(value_1, value_2, value_3));
}

void choice_three(void){
  printf("Effektlagen enkel för likström är effekten P i Watt (W) lika med spänningen U i volt(V)\n"
         "gånger strömmen I i Ampere(A): \n\n");
  print_unit('U');
  value_1 = input_check(MAX_VOLT);
  print_unit('I');
  value_2 = input_check(MAX_AMP);
  printf("%f W\n", multipli_two_values(value_1, value_2));
}

void choice_four(void){
  printf("Skenbar effekt enfas räknas med storheten VA(VoltAmpere) som är lika med spänningen U i volt(V)\n"
         "gånger strömmen I i ampere(A)\n\n");
  print_unit('U');
  value_1 = input_check(MAX_VOLT);
  print_unit('I');
  value_2 = input_check(MAX_AMP);
  printf("%f VA\n", multipli_two_values(value_1, value_2));
}

void choice_five(void){
  printf("Aktiv medelefdekt enfas är lika med effekt P i watt(W) lika med spänningen U i volt(V) gånger strömmen I \n"
         "i Ampere gånger cosinus fi/efkektfaktor < 1:\n\n");
  print_unit('U');
  value_1 = input_check(MAX_VOLT);
  print_unit('I');
  value_2 = input_check(MAX_AMP);
  printf("Skriv in effektfaktorn cos > 0 && cos < 1:\n");
  scanf("%lf", &value_3);
  if (value_3 < 0 && value_3 > 1){
      printf("Fel värde, försök igen\n");
  }
  printf("%f W\n", aktiv_eff(value_1, value_2, value_3));
}

void choice_six(void){
  printf("3-fas skenbar effekt är växelspänning är skenbar effekt S i voltampere(VA) lika med spänningen U i volt(V) \n"
         "gånger strömmen I i ampere(A) gånger roten ur 3 SQRT(3).\n\n");
  print_unit('U');
  value_1 = input_check(MAX_VOLT);
  print_unit('I');
  value_2 = input_check(MAX_AMP);
  printf("%f VA\n", sken_3fas(value_1, value_2));
}

void choice_seven(void){
  printf("3-fas aktiv effekt är effekten P i Watt(W) lika med spänningen U i volt(V) gånger strömmen I i ampere(A)\n"
         "gånger cos < 1 && cos > 0 gånger roten ur 3 SQRT(3).\n\n");
  print_unit('U');
  value_1 = input_check(MAX_VOLT);
  print_unit('I');
  value_2 = input_check(MAX_AMP);
  printf("Skriv in effektfaktorn cos > 0 && cos < 1: \n");
  scanf("%lf", &value_3);
  if (value_3 < 0 && value_3 > 1){
      printf("För högt värde, försök igen: \n");

  }
  printf("%f W\n", aktiv_3fas(value_1 ,value_2, value_3));
}

void choice_eight(void){
  printf("Pris för förbrukad el\n\n"
         "Ange pris i kw:\n");
  value_1 = input_check(KW_PRIS);
  printf("Ange förbrukad el i kilowatt (kw)\n");
  value_2 = input_check(KW);
  printf("Total summa %lf ", multipli_two_values(value_1, value_2));
}
