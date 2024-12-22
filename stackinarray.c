#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE];
int top = -1;

void push()
{
    int item;
    if(top==SIZE-1)
    printf("stack overflow\n");
    else
    {
        printf("enter the valve\n");
        scanf("%d",&item);
        top = top+1;
        stack[top]=item;
    }
}

void pop()
{
    int item;
    if(top == -1)
        printf("stack underflow\n");
    else
    {
        item=stack[top];
        printf("Element poped is %d in stack\n",item);
        stack[top]=0;
        top= top-1;
    }
}

void display()
{
    if(top==-1)
    printf("stack is empty\n");
    else
    {
        for(int i=top;i>-1;i--)
           {
             printf("the element of the stack at index %d is ",i);
             printf("%d\n",stack[i]);
           }
    }
}

int main()
{
int item;
int ch;
while(1)
{
    printf("1 for push\n");
    printf("2 for pop\n");
    printf("3 for display\n");
    printf("4 for exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1 : push();
              break;
    case 2 : pop();
              break;
    case 3 : display();
              break;
    case 4 : exit(1);        
    }
}
return 0;
}
