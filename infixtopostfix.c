
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int top=-1;
char s[30];

void push(char opr)
   {
     s[++top]=opr;
   }

char pop()
   {
     return s[top--];
   }

int priority(char opr)
   { 
    if(opr=='('||opr=='#')
       return 1;
    if(opr=='+'||opr=='-')
       return 2;
    if(opr=='*'||opr=='/')
       return 3;
    if (opr=='^'||opr=='%')
       return 4;
   }

void main()
   {
    char infix[30],postfix[30];
    int i,j=0;
    printf("enter the valid expression ");
    gets(infix);
    push('#');
    for(i=0;infix[i]!='\0';i++)
    { 
        if(isalnum(infix[i]))
           postfix[j++]=infix[i];
        else if(infix[i]=='(')
           push(infix[i]);
        else if(infix[i]==')')
           { 
            while(s[top]!='(')
               {
                 postfix[j++]=pop();
               }
            pop();  
           }
        else
           {
            while(priority(s[top])>priority(infix[i]))
                {
                 postfix[j++]=pop();
                }
            push(infix[i]);
           }
    }
    while(s[top]!='#')
    {
        postfix[j++]=pop();
    }
    postfix[j++]='\0';
    printf("postfix expression is ");
    puts(postfix);
}
