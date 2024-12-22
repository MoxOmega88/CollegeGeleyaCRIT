#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,k,n,j;
    int *ptr=NULL;
    printf("Enter the4 number of bytes should be allocated\n");
    scanf("%d%d",&n,&j);
    ptr = (int*)calloc(j,n*sizeof(int));
    if(ptr==NULL)
    {
        printf("memory exit not allocted\n");
        exit(1);
    }
    else
    {
       /* for(i=0;i<n;i++)
        {
            scanf("%d",(ptr+i));
        }*/
       for(k=0;k<j;k++)
       {
        for(i=0;i<n;i++)
        {
            printf("%d",*(ptr+i));
        }
        printf("\n");
       }
    }
    free(ptr);
}
 
