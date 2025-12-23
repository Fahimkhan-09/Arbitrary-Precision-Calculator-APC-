#ifndef DLL_H
#define DLL_H

typedef struct node
{
    char data;              
    struct node *prev;
    struct node *next;
} Dlist;

#define SUCCESS 0
#define FAILURE 1

void insert_end(Dlist **head, char digit);
void print_list(Dlist *head);
void clear_list(Dlist **head);
int insert_at_first(Dlist **head, Dlist **tail, int data);
int compare_list(Dlist *head1, Dlist *head2);
void delete_zeroes_present_at_first(Dlist **headR);
int delete_list(Dlist **head, Dlist **tail);

Dlist *get_tail(Dlist *head);

#endif
