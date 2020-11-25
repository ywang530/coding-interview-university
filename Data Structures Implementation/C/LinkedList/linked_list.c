#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

int linked_list_size(linked_list *head){
    if(head == NULL){return 0;}
    int size = 1;
    linked_list* current;
    current = head;
    while(current->next != NULL){
        size++;
        current = current->next;
    }
    return size;
}   

bool linked_list_empty(linked_list *head){
    return head == NULL;
}

int linked_list_value_at(linked_list *head, int idx){
    if(head == NULL){exit(EXIT_FAILURE);}
    linked_list *current = head;
    int count = 0;
    while(current != NULL){
        if(count == idx){
            return current->data;
        }
        count++;
        current = current->next;
    }
    exit(EXIT_FAILURE);
    return 0;
}

void linked_list_push_front(linked_list **head, int val){
    if(*head == NULL){exit(EXIT_FAILURE);}

    linked_list *new_node = malloc(sizeof(linked_list));
    new_node->next = (*head)->next;
    new_node->data = val;
    *head = new_node;
}

int linked_list_pop_front(linked_list **head){
    if(*head == NULL){exit(EXIT_FAILURE);}
    int val = (*head)->data;
    linked_list *front = *head;
    *head = (*head)->next;

    free(front);
    return val;
}

void linked_list_push_back(linked_list **head, int val){
    linked_list *node = malloc(sizeof(linked_list));
    node->data = val;
    node->next = NULL;

    if(*head == NULL){
        *head = node;
        return;
    }

    linked_list *current = *head;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = node;
}

// double pointer because may need to modify head ptr
int linked_list_pop_back(linked_list **head){
    if(*head == NULL){exit(EXIT_FAILURE);}

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

int linked_list_front(linked_list *head){
    if(head == NULL){exit(EXIT_FAILURE);}

    return head->data;
}

int linked_list_back(linked_list *head){
    if(head == NULL){exit(EXIT_FAILURE);}
    linked_list *current = head;
    while(current->next != NULL){
        current = current->next;
    }
    return current->data;
}

void linked_list_insert(linked_list **head, int idx, int val){
    linked_list *current = *head;
    linked_list *previous = NULL;
    int i;
    for(i=0; i<idx && current != NULL; i++){
        previous = current;
        current = current->next;
    }

    if(i != idx){
        printf("Given index out of bounds.");
        exit(EXIT_FAILURE);
    }

    linked_list *node = malloc(sizeof(linked_list));
    if(previous != NULL){
        node->next = current;
        previous->next = node;
        node->data = val;
    }
    else{
        node->next = *head;
        node->data = val;
        *head = node;
    }
    
}

void linked_list_erase(linked_list **head, int idx){
    linked_list *current = *head;
    linked_list *previous = NULL;
    int i;
    for(i=0; i<idx && current != NULL; i++){
        previous = current;
        current = current->next;
    }

    if(i != idx){
        printf("Given index out of bounds.");
        exit(EXIT_FAILURE);
    }

    if(previous != NULL){
        previous->next = current->next;
        free(current);
    }
    else{
        *head = current->next;
        free(current);
    }
}

int linked_list_value_n_from_end(linked_list *head, int n){
    if (n < 1 || head == NULL) {
        printf("Cannot get nth item from end.");
        exit(EXIT_FAILURE);
    }

    linked_list *current = head;
    linked_list *match = head;
    
    int i = 0;
    for(i=0; i<n && current != NULL; i++){
        current = current->next;
    }

    if (i != n) {
        printf("List is too short to get nth item from end.");
        exit(EXIT_FAILURE);
    }
    // curent will lead match by n nodes
    while(current != NULL){
        current = current->next;
        match = match->next;
    }

    return match->data;

}

void linked_list_reverse(linked_list **head){
    linked_list *current = *head;
    linked_list *previous = NULL;
    linked_list *temp = NULL;
    while(current != NULL){
        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }
    *head = previous;
}

void linked_list_remove(linked_list **head, int val){
    if(head == NULL){exit(EXIT_FAILURE);}

    linked_list *current = *head;
    linked_list *previous = NULL;
    
    while(current != NULL){
        if(current->data == val){
            if(previous != NULL){
                previous->next = current->next;
            }
            else{
                *head = current->next;
            }
            free(current);
        }

        previous = current;
        current = current->next;
    }
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

void print_list(linked_list *head) {
  linked_list *current = head;

  while (current) {
    printf("%d -> ", current->data);
    current = current->next;
  }

  printf("\n");
}

int main(){
    linked_list* head = NULL;
    // linked_list* first = malloc(sizeof(linked_list));
    // linked_list* second = malloc(sizeof(linked_list));
    // first->data = 5;
    // first->next = second;
    // second->data = 10;
    // second->next = NULL;


    // head = first;
    linked_list_push_back(&head, 1);
    linked_list_push_back(&head, 2);
    linked_list_push_back(&head, 3);
    linked_list_push_back(&head, 4);
    linked_list_push_back(&head, 5);

    printf("size %d\n", linked_list_size(head));
    print_list(head); 

    linked_list_reverse(&head);
    print_list(head); 

    linked_list_remove(&head, 1);
    print_list(head); 
}