/*Question no-4
Program to declare variables of structure type and print data using pointer-to-structure variable.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct n
{
    int data;
    struct n *link;
}list;
int main()
{
    list l1,l2,l3,*p ;
    printf("Enter three data values for three nodes: ");
    scanf("%d%d%d",&l1.data,&l2.data,&l3.data);
    l1.link=&l2;
    l2.link=&l3;
    l3.link=NULL;
    printf("The linked list is: ");
    p=&l1;
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->link;
    }
    printf("end\n");
    return 0;
}
