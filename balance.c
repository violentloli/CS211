#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
#include<stdbool.h>
void push(char stack[], char elem, int *stack_top) 
{
    stack[*stack_top] = elem;
    *stack_top = *stack_top + 1;
}
char peek_stack(char stack[], int *stack_top) 
{
    return stack[*stack_top - 1];
}
char pop(char stack[], int *stack_top) 
{
    if (*stack_top == 0)
    {
        return '\0';
         
    }
    *stack_top = *stack_top - 1;
    char popped_char = stack[*stack_top];
    return popped_char;
}

int check_counter_brace(char curr_elem, char popped_elem) {
    if ((curr_elem == ')' && popped_elem == '(') || (curr_elem == '}' && popped_elem == '{') || (curr_elem == ']' && popped_elem == '[') || (curr_elem == '>' && popped_elem == '<'))
    {
        return 1;
        return 0;
    }
}

char get_counter_brace(char brace) {
    if (brace == '(') 
    {
        return ')';
    }
    if (brace == '{')
    {
        return '}';
    }
    if (brace == '[') 
    {
        return ']';
    }
    if (brace == '<') 
    {
        return '>';
    }
    printf("\nError in input string");
    exit(0);
}

int check_balance(const char *str) {
    int size = strlen(str);
    char stack[size];
    int stack_top = 0;
    int *stack_top_ptr = &stack_top;
    
    int idx = 0;
    
    while(str[idx] != '\0') 
    {
        char curr_elem = str[idx];
        if (curr_elem == '(' || curr_elem == '{' || curr_elem == '[' || curr_elem == '<')
        {
            push(stack, curr_elem, stack_top_ptr);
        }
        else if (curr_elem == ')' || curr_elem == '}' || curr_elem == ']' || curr_elem == '>') 
        {
            char popped_brace = peek_stack(stack, stack_top_ptr);
            if (!check_counter_brace(curr_elem, popped_brace)) 
            {
                printf("%d: %c", idx, curr_elem);
                return -1;
            }
        
            pop(stack, stack_top_ptr);
        }
        
        idx++;
    }
    if (stack_top == 0) 
    {
        return 1;
    }
    if(stack_top != 0)
    {
        printf("%s","open: ");
        while (stack_top != 0) 
        {
            char stack_top_brace = pop(stack, stack_top_ptr);
            
            printf("%c", get_counter_brace(stack_top_brace));
        }
    }
    return -1;
}

int main(int argc, char **argv) 
{
    char *str_to_be_checked = argv[1];
    int status = check_balance(str_to_be_checked);
    return status;
}