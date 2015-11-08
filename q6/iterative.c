#include <stdio.h>
#include <stdlib.h>
#include <time.h>
static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

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
    struct timespec start, end;
    double cpu_time1;
    srand(time(NULL));


    struct node* head = NULL;
    for(int i = 100; i>0; i--)
        push(&head,i);

    clock_gettime(CLOCK_REALTIME, &start);
    reverseBetween(head,rand()%100+1,rand()%100+1);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);

    printf("execution time of reverseBetween() : %.9lf sec\n", cpu_time1);

    /*for(; head->next != NULL; head = head->next)
        printf("%d ",head->data);
        printf("%d",head->data);
    printf("\n");
    */
    return 0;
}
