#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
}linked_list;

int pop_back(linked_list** head){
    if(*head == NULL){return 0;}

    linked_list* current = *head;
    linked_list* previous = NULL;

    while(current->next != NULL){
        previous = current;
        current = current->next;
    }

    int value = current->data;
    if(previous != NULL){
        previous->next = NULL;
    }
    else{
        *head = NULL;
    }

    free(current);

    return value;
}
linked_list* find(linked_list *head, int n){
    if(head == NULL){return NULL;}
    if(head->data == n){return head;}
    linked_list* current = head;
    linked_list* previous = head;
    
    while(current->next != NULL){
        if(current->data == n){return current;}
        previous = current;
        current = current->next;
    }
    return NULL;
}


int main(){
    linked_list* head = NULL;
    linked_list* first = malloc(sizeof(linked_list));
    first->data = 5;
    first->next = NULL;

    head = first;

    printf("%d\n", head->data);
    linked_list* node = find(head, 5);
    printf("%d\n", node->data);
    free(head);
}