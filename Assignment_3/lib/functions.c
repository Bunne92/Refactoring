#include "functions.h"

float calculate(char operatorr, float first, float second){
  if(operatorr == '+') return first + second;
  else if(operatorr == '-') return first - second;
  else if(operatorr == '*') return first * second;
  else if(operatorr == '/') return first / second;
  else printf("Error! operator is not correct");
}
