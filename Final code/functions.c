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
  if(input_value > max_value){
      printf("För högt värde, försök igen: \n");
  }
    return input_value;
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
