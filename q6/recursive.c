#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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
node *reverseList(node* subHead)
{
    if (subHead == NULL || subHead->next == NULL)
        return subHead;
    node* restStart = subHead->next;
    subHead->next = NULL;
    node* restEnd = reverseList(restStart);
    restStart->next = subHead;
    return restEnd;
}



node *reverseBetween(node *head,int m,int n)
{
    if(!head)
        return head;
    if(m==n)
        return head;
    struct node* start = (struct node*) malloc(sizeof(struct node));
    start->next = head;


    node *subHead = start;
    node *subTail = start;
    node *connect;
    //find subhead
    for (int i = 0; i < m-1; i++)
        subHead = subHead->next;
    //find subtail
    for (int i = 0; i < n; i++)
        subTail = subTail->next;

    //cut the subtail from orig
    //and save the rest part in connect
    connect = subTail->next;
    subTail->next = NULL;

    //recursive part
    subHead->next = reverseList(subHead->next);

    //connect subtail and rest part
    node *temp = head;
    for(; temp->next != NULL; temp = temp->next)
        printf("%d",temp->next->data);
    printf("\n");
    temp->next = connect;

    return head;

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
    printf("%d",head->data);
    printf("\n");

    return 0;
}
