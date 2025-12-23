#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

void insert_end(Dlist **head, char digit)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(1);
    }
    new->data = digit;
    new->prev = NULL;
    new->next = NULL;
    //if it is empty
    if (*head == NULL)
    {
        *head = new;
        return;
    }
    //else
    Dlist *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new;
    new->prev  = temp;
}

void print_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Dlist *temp = head;
    while (temp != NULL)
    {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void clear_list(Dlist **head)
{
    Dlist *temp = *head;
    while (temp != NULL)
    {
        //store the next node and free the current node
        Dlist *next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}



int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL)
        return FAILURE;

    new->data = (char)data;  
    new->prev = NULL;
    new->next = *head;

    if (*head == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }

    (*head)->prev = new;
    *head = new;
    return SUCCESS;
}

int compare_list(Dlist *head1, Dlist *head2)
{
    if (head1 == NULL && head2 == NULL)
        return 0;
    if (head1 == NULL) 
        return -1;
    if (head2 == NULL) 
        return 1;

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;
    int list1_len = 0;
    int list2_len = 0;

    //counting digits of num1
    while (temp1 != NULL)
    {
        list1_len++;
        temp1 = temp1->next;
    }

    //counting digits of num2
    while (temp2 != NULL)
    {
        list2_len++;
        temp2 = temp2->next;
    }

    if (list1_len > list2_len)
        return 1;
    if (list1_len < list2_len)
        return -1;

    //if equal digits
    while (head1 != NULL && head2 != NULL)
    {
        int digit1 = head1->data;
        int digit2 = head2->data;

        if (digit1 > digit2)
            return 1;
        if (digit1 < digit2)
            return -1;

        head1 = head1->next;
        head2 = head2->next;
    }

    return 0;
}

void delete_zeroes_present_at_first(Dlist **headR)
{
    //check if list is present
    if (headR == NULL || *headR == NULL)
        return;

    Dlist *temp = *headR;

    // remove leading 0
    while (temp && temp->data == '0' && temp->next != NULL)
    {
        *headR = temp->next;
        (*headR)->prev = NULL;
        free(temp);
        temp = *headR;
    }
}

int delete_list(Dlist **head, Dlist **tail)
{
    if (*head == NULL)
        return FAILURE;

    Dlist *temp = *head;
    while (temp != NULL)
    {
        Dlist *next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;
    *tail = NULL;
    return SUCCESS;
}

Dlist *get_tail(Dlist *head)
{
    if (head == NULL)
        return NULL;
    Dlist *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    return temp;
}
