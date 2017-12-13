// Program to create a simple calculator
// Performs addition, subtraction, multiplication or division depending the input from user

#include <stdio.h>

int main() {
    char operator;
    double firstNumber,secondNumber, sum;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter two operands: ");
    scanf("%lf %lf",&firstNumber, &secondNumber);

    sum=calculate(operator,firstNumber,secondNumber);
    printf("\n%.1lf %c %.1lf = %.1lf",firstNumber, operator, secondNumber, sum);
    return 0;
}
