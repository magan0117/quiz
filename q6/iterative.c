#include <stdio.h>
#include <stdlib.h>

//type define
typedef struct node {
    int data;
    struct node* next;
} node;

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

node *reverseBetween(node *head,int m,int n)
{
    if(!head)
        return head;
    if(m==n)
        return head;
    struct node* dummy = (struct node*) malloc(sizeof(struct node));
    dummy->next = head;

    node *prev = dummy;
    node *curr = dummy;
    node *temp;

    for (int i = 0; i < m - 1; i++)
        prev = prev->next;
    curr = prev->next;

    for (int i = 0; i < n - m; i++) {
        temp = curr->next->next;
        curr->next->next = prev->next;
        prev->next = curr->next;
        curr->next = temp;
    }
    return dummy->next;

}

int main()
{
    struct node* head = NULL;

    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);

    reverseBetween(head,2,4);
    for(; head->next != NULL; head = head->next)
        printf("%d",head->data);

    printf("\n");

    return 0;
}
