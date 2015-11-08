#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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
    struct timespec start, end;
    double cpu_time1;
    srand(time(NULL));

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
