//Calculator program

#include "calc_functions.h"

int main()
{
    int choice = menu();
    switch(choice) //switch statement for menu
    {
    case 1:
        choice_one();
        break;
    case 2:
        choice_two();
        break;
    case 3:
        choice_three();
        break;
    case 4:
        choice_four();
        break;
    default:
        printf("Enter correct number e.g 1 - 4\n"); //Outputted if the user enters a value other than 1 - 4
        break;
    }
    return 0;
}
//End of code
