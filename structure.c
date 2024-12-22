#include <stdio.h>

struct student
{
    char name[20];
    char USN[20];
    int age;
};

void main()
{
    int i,n;
    printf("Enter the number of students\n");
    scanf("%d",&n);
    struct student s[n];
    for(i=0;i<n;i++)
    {
        scanf("%s%s%d",&s[i].name,&s[i].USN,&s[i].age);
    }
    for(i=0;i<n;i++)
    {
        printf(" NAME - %s USN - %s AGE - %d \n",s[i].name,s[i].USN,s[i].age);
    } 
}