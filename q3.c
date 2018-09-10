/*Question no-3
Program to create a self-referential structure.Read in values for four structure variables and print them. */

#include<stdio.h>
#include<stdlib.h>

typedef struct N {
                  int data;
                  struct N *ptr ;
                 }list ;
int main()
{
    list l1,l2,l3,l4;
    l1.ptr=l2.ptr=l3.ptr=l4.ptr=NULL ;
    int d,e,f,g;
    printf("Enter data value for l1,l2,l3,l4: ");
    scanf("%d%d%d%d",&d,&e,&f,&g);
    l1.data=d;
    l2.data=e;
    l3.data=f;
    l4.data=g;
    l1.ptr=&l2;
    l2.ptr=&l3;
    l3.ptr=&l4;
    printf("l1:\nData:%d\nLink:%u\nl2:\nData:%d\nLink:%u ",l1.data,l1.ptr,l2.data,l2.ptr);
    printf("\nl3:\nData:%d\nLink:%u\nl4:\nData:%d\nlink:%d\n",l3.data,l3.ptr,l4.data,l4.ptr);
    return 0;
}

