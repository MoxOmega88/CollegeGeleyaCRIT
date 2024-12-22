#include<stdio.h>
#include<stdlib.h>
int n;
int *queue;
int rear = -1;
int front = 0;

void enqueue()
{
    if(rear == n-1)
      printf("the queue is full\n");
    else
    {
      int m;
      printf("enter the elment to be inserted in the queue\n");
      scanf("%d",&m);
      queue[++rear]=m;
    }  
}

void dequeue()
{
    if(rear == -1|| front>rear)
      {
       printf("the queue is empty\n");
       front =0;
       rear =-1;
      }
    else
      {
        int del=queue[front++];
        printf("the element removed from the queue is %d\n",del);
      }
}

void display()
{
    if(rear ==-1||front>rear)
    printf("the queue is empty\n");
    else
    {
        for(int i=front;i<=rear;i++)
           {
             printf("the element of the  at index %d is ",i);
             printf("%d\n",queue[i]);
           }
    }
}

int main()
{
printf("enter the length of the queue\n");
scanf("%d",&n);
queue=(int*)malloc(n*sizeof(int));
int item ,ch;
while(1)
{
    printf("1 for enqueue\n");
    printf("2 for dequeue\n");
    printf("3 for display\n");
    printf("4 for exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1 : enqueue();
             break;
    case 2 : dequeue();
             break;
    case 3 : display();
             break;
    case 4 : exit(1);        
    }
}
return 0;
}
