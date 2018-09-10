/*Question no-7
Program to perform binary search on a sorted array recursively*/

#include<stdio.h>
#define MAX 100
void bsort(int a[],int n);
int bsearch(int a[],int n,int ele,int,int);

int main()
{
   int arr[MAX],n,i,item ;
   printf("Enter no of elements in array: ");
   scanf("%d",&n);
   printf("Enter array elements: ");
   for(i=0;i<n;i++)
      scanf("%d",arr+i);
   bsort(arr,n);
   int beg=0,end=n-1;
   printf("Enter element to be searched in array: ");
   scanf("%d",&item);
   int res=bsearch(arr,n,item,beg,end);
   if(res==-1)
      printf("Element not found\n");
   else
      printf("Found at position:%d\n",res);
   return 0;
}

void bsort(int a[],int n)
{
   int i,j,temp;
   for(i=0;i<n-1;i++)
   {
       for(j=0;j<n-i-1;j++)
       {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
       }
   }
}

int bsearch(int a[],int n,int ele,int beg,int end)
{
    int mid=(beg+end)/2;
    if(beg<=end)
    {
         mid=(beg+end)/2;
         if(ele==a[mid])
             return mid;
         else if(ele>a[mid])
             return bsearch(a,n,ele,mid+1,end);
         else
             return bsearch(a,n,ele,beg,mid-1);
    }
    return -1;
}
