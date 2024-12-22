#include<stdio.h>
#include<ctype.h>
#include<math.h>
int top=-1;
char s[30];

void push(char opr)
{
     s[++top]=opr;
}

char pop()
{ 
    return(s[top--]);
}

int priority(char opr)
{ 
    if(opr=='('||opr=='#')
       return 1;
    if(opr=='+'||opr=='-')
       return 2;
    if(opr=='*'||opr=='/')
       return 3;
    if(opr=='^'||opr=='%')
       return 4;
}

void intopo(char infix[],char postfix[])
{
   int i,j=0;
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
}

int evalpo(char postfix[])
{ 
    int a,b;
    for(int i=0;postfix[i]!='\0';i++)
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        switch (postfix[i])
        { 
            case '+': push(pop()+pop());
                      break;
            case '-': a=pop();
                      b=pop();
                      push(b-a);
                      break;
            case '*': push(pop() * pop());
                      break;
            case '/': a=pop();
                      b=pop();
                      push(b/a);
                      break;
            case '^': a=pop();
                      b=pop();
                      push(pow(b,a));
                      break;
        }
    }
    int x=pop();
    return x;
}

void main()
{ 
    char infix[30],postfix[30];
    
    printf("enter valid infix expression \n");
    gets(infix);
    intopo(infix,postfix);
    printf("postfix expression is ");
    puts(postfix);
    int ans=evalpo(postfix);
    printf("solution to infix expression is %d\n",ans);
    }

