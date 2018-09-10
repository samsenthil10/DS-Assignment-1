/*ASSIGNMENT-1
Name:SENTHIL KUMAR S A
USN:1PE17CS136
Class:B.E. 3rd SEMESTER,CSE
Section:'B'
Question no-1
Program to allocate memory dynamically to a 1D array.*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
     int n;
     printf("Enter no of elements in 1D array: ");
     scanf("%d",&n);
     int *p=(int *)malloc(n*sizeof(int)),i;
     printf("Enter array elements: ");
     for(i=0;i<n;i++)
         scanf("%d",p+i);
     printf("The array elements are: ");
     for(i=0;i<n;i++)
         printf("%d ",*(p+i));
     printf("\n");
     free(p);
     return 0;
}
