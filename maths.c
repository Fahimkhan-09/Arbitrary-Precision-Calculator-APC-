#include <stdio.h>
#include <stdlib.h>
#include "dll.h"
#include "maths.h"

int add(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    //starts from last digit
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int n1, n2;
    int sum, carry = 0;

    *headR = NULL;
    *tailR = NULL;
    //keeps adding until digits are present
    while (temp1 != NULL || temp2 != NULL || carry != 0)
    {
        if (temp1 != NULL)
            n1 = temp1->data - '0';
        else
            n1 = 0;

        if (temp2 != NULL)
            n2 = temp2->data - '0';
        else
            n2 = 0;

        sum = n1 + n2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        insert_at_first(headR, tailR, sum + '0');

        if (temp1)
        {
            //moves to previous node
            temp1 = temp1->prev;

        }
        
        if (temp2)
        {
            temp2 = temp2->prev;
        }
    }

    delete_zeroes_present_at_first(headR);

    return SUCCESS;
}

int sub(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    //from last

    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    //to store digit of each number

    int digit1 = 0, digit2 = 0;
    //result
    int diff = 0, borrow = 0;

    *headR = NULL;
    *tailR = NULL;
    //until both are empty
    while (temp1 != NULL || temp2 != NULL)
    {
        if (temp1 != NULL)
            digit1 = temp1->data - '0';
        else
            digit1 = 0;

        if (temp2 != NULL)
            digit2 = temp2->data - '0';
        else
            digit2 = 0;

        if (borrow == 1)
        {
            digit1 = digit1 - 1;
            borrow = 0;
        }

        if (digit1 < digit2)
        {
            digit1 = digit1 + 10;
            borrow = 1;
        }

        diff = digit1 - digit2;

        insert_at_first(headR, tailR, diff + '0');

        if (temp1)
        {
            temp1 = temp1->prev;
        }
        if (temp2)
        {
            temp2 = temp2->prev;
        }
    }

    delete_zeroes_present_at_first(headR);

    return SUCCESS;
}

int mul(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1, *temp2;

    Dlist *headR1 = NULL, *tailR1 = NULL; 
    Dlist *headR2 = NULL, *tailR2 = NULL; 

    // Initialize R2 = 0
    insert_at_first(&headR2, &tailR2, '0');

    int count = 0;

    temp2 = *tail2;

    while (temp2)
    {
        headR1 = NULL;
        tailR1 = NULL;

        
        for (int i = 0; i < count; i++)
            insert_end(&headR1, '0');   

        int digit2 = temp2->data - '0';
        int carry = 0;

        temp1 = *tail1;

        while (temp1)
        {
            int digit1 = temp1->data - '0';
            int res = (digit1 * digit2) + carry;

            carry = res / 10;
            res   = res % 10;

            insert_at_first(&headR1, &tailR1, res + '0');

            temp1 = temp1->prev;
        }

        if (carry > 0)
            insert_at_first(&headR1, &tailR1, carry + '0');

        // R2 = R1 + R2 → store into *headR,*tailR
        add(&headR1, &tailR1, &headR2, &tailR2, headR, tailR);

        // free old R1 and R2
        delete_list(&headR1, &tailR1);
        delete_list(&headR2, &tailR2);

        // move result into R2
        headR2 = *headR;
        tailR2 = *tailR;

        *headR = NULL;
        *tailR = NULL;

        temp2 = temp2->prev;
        count++;
    }

    *headR = headR2;
    *tailR = tailR2;

    delete_zeroes_present_at_first(headR);

    return SUCCESS;
}


int divide(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    // divisor == 0
    if ((*head2)->next == NULL && (*head2)->data == '0')
    {
        printf("Error : Division by zero is not allowed.\n");
        return FAILURE;
    }

    // result empty
    *headR = NULL;
    *tailR = NULL;

   
    Dlist *currH = NULL, *currT = NULL;

    //starts from first digit
    Dlist *temp = *head1;

    while (temp)
    {
        // Bring down next digit
        insert_end(&currH, temp->data);
        currT = get_tail(currH);

        // Remove extra leading zeros
        delete_zeroes_present_at_first(&currH);
        currT = get_tail(currH);

        // Count how many times divisor fits in currH
        int count = 0;

        while (currH && compare_list(currH, *head2) >= 0)
        {
            Dlist *resH = NULL, *resT = NULL;

            // currH = currH - divisor
            sub(&currH, &currT, head2, tail2, &resH, &resT);

            delete_list(&currH, &currT);

            currH = resH;
            currT = resT;

            count++;
        }

        // Store this quotient digit
        insert_end(headR, count + '0');

        temp = temp->next;
    }

    // Remove leading zeros in quotient
    delete_zeroes_present_at_first(headR);

    return SUCCESS;
}
