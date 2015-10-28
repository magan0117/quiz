/* FIXME: Implement! */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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


int FindMaxSumSubArray(int array[], int low, int high)
{
    int i;
    int sum = 0;
    int leftMax = 0;
    int rightMax = 0;
    /* No element in the array */
    if (low > high)
        return 0;
    /* One element in the array */
    if (low == high)
        return fmax(0, array[low]);

    /* Middle element of the array */
    int middle = (low + high) / 2;

    /* find maximum sum crossing to left */
    leftMax = sum = 0;
    for (i = middle; i >= low; i--) {
        sum += array[i];
        if (sum > leftMax)
            leftMax = sum;
    }

    /* find maximum sum crossing to right */
    rightMax = sum = 0;
    for (i = middle+1; i <= high; i++) {
        sum += array[i];
        if (sum > rightMax)
            rightMax = sum;
    }

    /* Return the maximum of leftMax, rightMax and their sum */
    return fmax(leftMax + rightMax, fmax(FindMaxSumSubArray(array, low, middle), FindMaxSumSubArray(array, middle+1, high)));
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
    printf("Ans: %d\n",FindMaxSumSubArray(array,0,m-1));
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time1 = diff_in_second(start, end);
    printf("execution time of find max sub arr() : %.9lf sec\n", cpu_time1);
}


int main()
{
    srand(time(NULL));
//gen 10 test data
    for(int i = 0; i < 10; i++) {
        TestData();
    }


    return 0;
}
