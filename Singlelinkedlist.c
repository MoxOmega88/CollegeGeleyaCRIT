#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ int info; 
struct node *link; 
}; 
typedef struct node *NODE;  
NODE insert_front(int item,NODE first) 
{ 
} 
NODE temp; 
temp=(struct node*) malloc(sizeof(NODE)); 
temp->info=item; 
temp->link=first; 
return temp; 
NODE delete_front(NODE first) 
{ 
} 
NODE temp; 
if(first==NULL) 
{ 
} 
printf("empty list"); 
return first; 
temp=first; 
temp=temp->link; 
printf("item deleted is %d",first->info); 
free(first); 
return temp; 
void display(NODE first) 
{ 
NODE temp; 
temp=first; 
if(first==NULL) 
{ 
}  
printf("empty list"); 
return; 
printf("contents of linked list are"); 
while(temp!=NULL) 
{ 
} 
} 
printf("%d  ",temp->info); 
temp=temp->link; 
void main() 
{ 
NODE first; 
int x,item; 
first=NULL; 
printf("1. INSERT\n2. DISPLAY\n3.DELETE\n4.EXIT"); 
while(1) 
{ 
printf("\nenter operation number  "); 
scanf("%d",&x); 
switch(x) 
{ 
case 1: 
{ 
printf("enter item to be added to list"); 
   scanf("%d",&item); 
   first=insert_front(item,first); 
   break; 
  } 
  case 2: 
  { display(first); 
   break; 
  } 
  case 3: 
  { first=delete_front(first); 
   break; 
  } 
  case 4: 
  { exit(0); 
  } 
 } 
 } 
}