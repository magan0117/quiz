/* FIXME: Implement! */
#include <assert.h>
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
    struct timespec start, end;
    double cpu_time1;
    int *array;
    int m = rand()%20+1;
    //len = m;
    array = (int*)malloc(m*sizeof(int));
    //printf("m = %d\n",m);
    for(int i = 0; i < m; i++) {
        array[i]=rand()%100+1;
        printf("%d,",array[i]);
    }
    clock_gettime(CLOCK_REALTIME, &start);
    printf("%d\n",maxSubArraySum(array,m));
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);

    printf("execution time of smallest_char() : %.9lf sec\n", cpu_time1);
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
