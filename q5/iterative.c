#include <stdio.h>
#include <stdlib.h>

//type define
typedef struct node {
    int data;
    struct node* next;
};

//push data
void push(struct node** head, int data)
{
//allocate
    struct node* new = (struct node*) malloc(sizeof(struct node));
//put data
    new->data = data;
//orig to next
    new->next = (*head);
//new one to head
    (*head) = new;

}


int main()
{
    return 0;
}
