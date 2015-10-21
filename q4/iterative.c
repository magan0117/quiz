/* FIXME: Implement! */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxSubArraySum(int a[],int n)
{
    int max_temp = 0;
    int max_end = 0;

    assert((n>1) && "Array is empty!");


    for(int i = 0; i<n; i++) {
        max_end = max_end + a[i];
        if(max_end < 0)
            max_end = 0;
        if(max_temp < max_end)
            max_temp = max_end;
    }
    printf("ANS:");
    return max_temp;
}

void TestData()
{
    int *array;
    int m = rand()%20+1;
    //len = m;
    array = (int*)malloc(m*sizeof(int));
    //printf("m = %d\n",m);
    for(int i = 0; i < m; i++) {
        array[i]=rand()%100+1;
        printf("%d,",array[i]);
    }
    printf("%d\n",maxSubArraySum(array,m));
}


int main()
{

   srand(time(NULL));
//gen 10 test data
    for(int i = 0; i < 10; i++) {
        TestData();
    }
//int test[] = {-2,1,-3,4,-1,2,1,-5,4};
/*    int test[] = {-2,1,-3,4,-1,2,1,-5,4};

    int length = sizeof(test)/sizeof(int);
    //printf("%d\n",length);
    for(int i=0; i<length; i++)
        printf("%d ",test[i]);
    printf("\n");

    printf("%d\n",maxSubArraySum(test,length));
*/
    return 0;
}
