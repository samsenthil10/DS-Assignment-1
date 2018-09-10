/*Question no -2
Program to allocate memory dynamically to 2D Arrays.*/

#include<stdio.h>
#include<stdlib.h>//for exit(),malloc() and free()

int main()
{
   int **a,row,col,i,j ;
   printf("Enter no of rows and columns: ");
   scanf("%d%d",&row,&col);
   a=(int**)malloc(row*sizeof(int *));
   if(a==NULL)
   {
      printf("No memory\n");
      exit(0);
   }
   for(i=0;i<row;i++)
      a[i]=(int*)malloc(col*sizeof(int));
   printf("Enter the elements: ");
   for(i=0;i<row;i++)
       for(j=0;j<col;j++)
           scanf("%d",(*(a+i)+j));
   printf("The array is: ");
   for(i=0;i<row;i++)
   {
        printf("\n");
        for(j=0;j<col;j++)
            printf("%d ",*(*(a+i)+j));
   }
   printf("\n");
   free(a);
   return 0;
}
