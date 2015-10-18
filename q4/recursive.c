/* FIXME: Implement! */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int FindMaxSumSubArray(int array[], int low, int high){
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
     return fmax(leftMax + rightMax, fmax(FindMaxSumSubArray(array, low, middle), FindMaxSumSubArray(array, middle+1, high)));}



int main()
{

    //int test[] = {-2,1,-3,4,-1,2,1,-5,4};
    int test[] = {-2,1,-3,4,-1,2,1,-5,4};

    int length = sizeof(test)/sizeof(int);
    //printf("%d\n",length);
    for(int i=0; i<length; i++)
        printf("%d ",test[i]);
    printf("\n");

    printf("Ans: %d\n",FindMaxSumSubArray(test,0,length-1));

    return 0;
}
