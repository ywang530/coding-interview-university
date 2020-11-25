#include <stdlib.h>
#include <stdbool.h>

// Implement a linked list
typedef struct Node{
    int data;
    struct Node* next;
}linked_list;

int linked_list_size(linked_list *head);

bool linkked_list_empty(linked_list *head);

int linked_list_value_at(linked_list *head, int idx);

void linked_list_push_front(linked_list **head, int val);

int linked_list_pop_front(linked_list **head);

void linked_list_push_back(linked_list **head, int val);

int linked_list_pop_back(linked_list **head);

int linked_list_front(linked_list *head);

int linked_list_back(linked_list *head);

void linked_list_insert(linked_list **head, int idx, int val);

void linked_list_erase(linked_list **head, int idx);

int linked_list_value_n_from_end(linked_list *head, int n);

void linked_list_reverse(linked_list **head);

void linked_list_remove(linked_list **head, int val);

void print_list(linked_list *head);