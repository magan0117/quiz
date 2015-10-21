/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void bubble_sort(char number[],int n){
char a = '\0';
         for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (number[i] > number[j])
                {
                    a =  number[i];
                    number[i] = number[j];
                    number[j] = a;
                }
            }
        }

}




void make_string(char test_data[])
{
    srand(time(NULL));

//test data length < 50
    int data_num = (rand()%10);
//rand char
    int data_unit;

    printf("test string length = %d\n",data_num+1);

    printf("string = ");

    for(int i = 0; i<data_num+1; i++) {
        //small char's ASCII is from 97 - 122
        data_unit = (rand()%26+97) ;
        test_data[i]=(char)data_unit;
    }

	bubble_sort(test_data,data_num+1);

	 for(int i = 0; i<data_num+1; i++)
printf("%c,",test_data[i]);



    printf("\n");
}

char smallest_character(char str[],char c,int index)
{

    if(str[index]>c)
        return str[index];
    else if(str[index]!='\0')
        smallest_character(str,c,++index);
    else
        return str[0];

}


int main()
{

    char test[] = "\0";
    char find = 'a';
    char ans = '\0';

    make_string(test);
    ans = smallest_character(test,find,0);
    printf("ANS: %c\n",ans);
    return 0;



}
