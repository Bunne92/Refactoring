// Program to create a simple calculator
// Performs addition, subtraction, multiplication or division depending the input from user
#include "lib/functions.h"

int main() {
    char operator;
    float firstNumber,secondNumber, sum;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter two operands: ");
    scanf("%f %f",&firstNumber, &secondNumber);

    sum=calculate(operator,firstNumber,secondNumber);
    printf("\n%.1f %c %.1f = %.1f",firstNumber, operator, secondNumber, sum);
    return 0;
}
