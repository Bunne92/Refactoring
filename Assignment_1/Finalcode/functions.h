#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_RES   20000
#define MAX_AMP     440
#define MAX_VOLT    400
#define KW_PRIS      10
#define KW        50000

double value_1, value_2, value_3;

double multipli_two_values(double x, double y);
double res_tot(double r1, double r2, double r3);
double aktiv_eff(double u, double i, double cos);
double sken_3fas(double u, double i);
double aktiv_3fas(double u, double i, double cos);
double input_check(int max_value);
int menu();
void choice_one(void);
void choice_two(void);
void choice_three(void);
void choice_four(void);
void choice_five(void);
void choice_six(void);
void choice_seven(void);
void choice_eight(void);
void print_unit(char unit);
