/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

// converts an operand in words to numerics and returns it
// operand is not valid, returns -1
double convert(char *operand)
{
        
        if(strcmp(operand, "one") == 0)
        {
            return 1;
        }
        else if(strcmp(operand, "two")== 0)
        {
            return 2;
        }
        else if(strcmp(operand , "three")== 0)
        {
            return 3;
        }
        else if(strcmp(operand , "four")== 0)
        {
            return 4;
        }
        else if(strcmp(operand , "five")== 0)
        {
            return 5;
        } 
        else if(strcmp(operand , "six")== 0)
        {
            return 6;
        }
        else if(strcmp(operand , "seven")== 0)
        {
            return 7;
        }
        else if(strcmp(operand ,"eight")== 0)
        {
            return 8;
        }
        else if(strcmp(operand , "nine")== 0)
        {
            return 9;
        }
        else if(strcmp(operand , "zero")== 0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
}

// checks whether the operator is valid or not
// returns 1 if valid operator
// returns 0 if invalid operator
int compare(char *operator)
{
        if(strcmp(operator, "plus") == 0)
        {
            return 1;
        }
        else if(strcmp(operator, "minus")== 0)
        {
            return 1;
        }
        else if(strcmp(operator , "multiply")== 0)
        {
            return 1;
        }
        else if(strcmp(operator , "divide")== 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

int main(int argc, char *argv[])
{
        double result;
        double operand1, operand2;
        char *temp = argv[1];
        if(argc < 4 && argc != 1)
        {
                printf("Error: not enough operands");
                return -1;
        }
        else if(argc > 4 )
        {
                printf("Error: too many elements");
                return -1;
        }
        else if(argc == 1)
        {
            printf("Error: not an operator:");
            return -1;
        }
        else
        {
                if(compare(argv[1]) == 0 )
                {
                        printf("Error: not an operator: %s", argv[1]);
                        return -1;
                }
                operand1 = convert(argv[2]);
                if(operand1 == -1)
                {
                        printf("Error: not an operand: %s", argv[2]);
                        return -1;
                }
                operand2 = convert(argv[3]);
                if(operand2 == -1)
                {
                        printf("Error: not an operand: %s", argv[3]);
                        return -1;
                }
                if(strcmp(argv[1], "plus" ) == 0)
                        result = operand1 + operand2;
                else if(strcmp(argv[1], "minus" ) == 0)
                        result = operand1 - operand2;
                else if(strcmp(argv[1], "multiply" ) == 0)
                        result = operand1 * operand2;
                else if(strcmp(argv[1], "divide" ) == 0)
                {
                        if(operand2 == 0)
                        {
                                printf("Error: divide by zero");
                                return -1;
                        }
                        else
                                result = operand1 / operand2;
                }
                printf("%2.2lf", result);
                return 1;
        }
        
}
