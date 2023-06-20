// Write a C program to test whether a given identifier is valid or not.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    int i;
    char id[100];
    printf("enter the string\n");
    gets(id);
    if(id[0]!='_'&&!isalpha(id[0]))
    {
        printf("it is not a valid c identifier1\n");
        return 0;
    }
    for(i=1;id[i]!='\0';i++)
        if(isalpha(id[i])||isdigit(id[i])||id[i]=='_')
            continue;
        else
        {
            printf("It is not a valid c identifier\n");
            return 0;
        }
    printf("It is a valid c identifier\n");
    return 0;
}
