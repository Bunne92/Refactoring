#include "calc_functions.h"

float Addition(float a, float b){
  return a+b;
}
float Subtraction(float a, float b){
  return a-b;
}
float Multiplication(float a, float b){
  return a*b;
}
float Division(float a, float b){
  return a/b;
}

float scan_numbers(int number){
  float a, b;
  if(number == 1){
    printf("Enter first number: ");
    scanf("%f", &a);                                //User input for first number
    return a;
  }
  if(number == 2){
    printf("Enter second number: ");
    scanf("%f", &b);                                //User input for second number
    printf("\n");
    return b;
  }
}
//Calculator menu, user must enter a value from 1 - 4 for the program to work
int menu(){
  int choice;
  printf("Enter a number from the list below\n\n");

  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n\n");

  printf("Enter number: ");
  scanf("%d", &choice);                              //User input for the calculator menu

  printf("\n");
  return choice;
}

void choice_one(){
  printf("You entered Addition\n\n");
  num1=scan_numbers(1);
  num2=scan_numbers(2);
  printf("%.2f + %.2f = %.2f\n",num1,num2,Addition(num1,num2));
}

void choice_two(){
  printf("You entered Subtraction\n\n");
  num1=scan_numbers(1);
  num2=scan_numbers(2);
  printf("%.2f - %.2f = %.2f\n", num1, num2, Subtraction(num1,num2)); //Subtraction output
}

void choice_three(){
  printf("You entered Multiplication\n\n");
  num1=scan_numbers(1);
  num2=scan_numbers(2);
  printf("%.2f * %.2f = %.2f\n", num1, num2, Multiplication(num1,num2)); //Multiplication Output
}

void choice_four(){
  printf("You entered Division\n\n");
  num1=scan_numbers(1);
  num2=scan_numbers(2);
  printf("%.2f / %.2f = %.2f\n", num1, num2, Division(num1,num2));
}
