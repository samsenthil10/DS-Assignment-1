/*Question-5
Multiplying two polynomials */

#include<stdio.h>
#define MAX 100

typedef struct
           {
               int expo ;
               float coef;
           }poly ;

int pmult(poly a[],int m,poly b[],int n,poly c[]);//polynomial multiplication

void display(poly a[],int m);//display polynomial

void input(poly a[],int m);//input polynomial

void sort(poly a[],int m);//sort the polynomial in decreasing order of exponents

int main()
{
    int m,n ;
    poly a[MAX],b[MAX],c[MAX] ;
    printf("Enter no of terms in 1st polynomial: ");
    scanf("%d",&m);
    printf("Enter terms of polynomial A: ");
    input(a,m);
    printf("Enter no of terms in 2nd polynomial: ");
    scanf("%d",&n);
    printf("Enter terms of polynomial B: ");
    input(b,n);
    printf("POLYNOMIAL A: ");
    display(a,m);
    printf("\nPOLYNOMIAL B: ");
    display(b,n);
    int size=pmult(a,m,b,n,c);
    printf("\nThe product is: ");
    display(c,size);
    printf("\n");
    return 0;
}

int pmult(poly a[],int m,poly b[],int n,poly c[])
{
    poly temp[MAX];
    int i,j,tIndex=0 ;

    //multiplication

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            temp[tIndex].coef=a[i].coef * b[j].coef;
            temp[tIndex].expo=a[i].expo + b[j].expo;
            tIndex++;
        }
    }
    temp[tIndex].expo=-1;

    //processing to reduce redundant terms

    int cIndex=0;
    for(i=temp[0].expo;i>=temp[tIndex-1].expo;i--)
    {
        c[cIndex].coef=0;
        for(j=0;j<tIndex;j++)
        {
             if(temp[j].expo==i)
             {
                 c[cIndex].coef+=temp[j].coef;
                 c[cIndex].expo=temp[j].expo ;
             }
        }
        cIndex++;
    }
    return cIndex;
}

void input(poly a[],int m)
{
    int i;
    printf("\n");
    for(i=0;i<m;i++)
    {
        printf("Enter exponent and coefficient of term no %d: ",i+1);
        scanf("%d%f",&a[i].expo,&a[i].coef);
    }
    sort(a,m);
}

void display(poly a[],int m)
{
    int i;
    printf("\n");
    for(i=0;i<m;i++)
    {
        printf("%0.2fx^(%d)",a[i].coef,a[i].expo);
        if(i!=m-1)
             printf("+");
    }
}

void sort(poly a[],int m)
{
    int i,j ;
    int large,pos,temp;
    float tmp;
    for(i=0;i<m-1;i++)
    {
        large=a[i].expo;
        pos=i;
        for(j=i+1;j<m;j++)
        {
            if(a[j].expo>large)
            {
                 large=a[j].expo;
                 pos=j;
            }
        }
        temp=a[pos].expo;
        a[pos].expo=a[i].expo;
        a[i].expo=temp;
        tmp=a[pos].coef;
        a[pos].coef=a[i].coef;
        a[i].coef=tmp ;
    }
}
