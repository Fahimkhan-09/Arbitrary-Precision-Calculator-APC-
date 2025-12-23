#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
#include "maths.h"

void store_digits(Dlist **head, char num[])
{
    for (int i = 0; num[i] != '\0'; i++)
    {
        if (num[i] >= '0' && num[i] <= '9')
            insert_end(head, num[i]);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Give appropriate inputs! Usage: %s num1 operator num2\n", argv[0]);
        return 0;
    }

    Dlist *node1 = NULL;
    Dlist *node2 = NULL;

    char *num1_str = argv[1];
    char *num2_str = argv[3];
    char op = argv[2][0];

    // build DLLs
    printf("Digits of num1: ");
    store_digits(&node1, num1_str);
    print_list(node1);

    printf("Digits of num2: ");
    store_digits(&node2, num2_str);
    print_list(node2);

    Dlist *tail1 = get_tail(node1);
    Dlist *tail2 = get_tail(node2);

    Dlist *headR = NULL, *tailR = NULL;

    switch (op)
    {
        case '+':
            add(&node1, &tail1, &node2, &tail2, &headR, &tailR);
            break;

        case '-':
            // check first number >= second for sub
            if (compare_list(node1, node2) >= 0)
            {
                sub(&node1, &tail1, &node2, &tail2, &headR, &tailR);
            }
            else
            {
                //node2 - node1 then insert -
                sub(&node2, &tail2, &node1, &tail1, &headR, &tailR);
                insert_at_first(&headR, &tailR, '-');
            }
            break;

        case '*':
            mul(&node1, &tail1, &node2, &tail2, &headR, &tailR);
            break;

        case '/':
            if (divide(&node1, &tail1, &node2, &tail2, &headR, &tailR) == FAILURE)
            {
                // division by zero
                clear_list(&node1);
                clear_list(&node2);
                clear_list(&headR);
                return 0;
            }
            break;

        default:
            printf("Invalid Operation!\n");
            clear_list(&node1);
            clear_list(&node2);
            return 0;
    }

    printf("Result: ");
    print_list(headR);

    clear_list(&node1);
    clear_list(&node2);
    clear_list(&headR);

    return 0;
}
