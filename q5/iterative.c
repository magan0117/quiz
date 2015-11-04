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



int DetectLoop(struct node* list)
{
    struct node *slow_p = list;
    struct node *fast_p = list;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if(slow_p == fast_p) {
            printf("loop!");
            return fast_p->data;
        }
    }

    return 0;
}


int main()
{
    struct node* head = NULL;

    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    //1->2->3->4->5->6------>2  and loop
    head->next->next->next->next->next = head->next;

    int ans =DetectLoop(head);
    printf("%d\n",ans);
    return 0;

}
