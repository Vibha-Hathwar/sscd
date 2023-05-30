//Write a C program to recognize strings under ‘a*’, ‘a*b+’, ‘abb’.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char ch[100];
    int i,state;
    printf("ENTER THE STRING\t");
    gets(ch);
    i=0;
    state=0;
    while(ch[i]!='\0')
    {
        switch(state)
        {
            case 0:if(ch[i]==' ') state=0;
                    else if(ch[i]=='a') state=1;
                    else if(ch[i]=='b')state=2;
                    else state=6;
                    break;
            case 1:if(ch[i]=='a') state=3;
                    else if(ch[i]=='b') state=4;
                    else state=6;
                    break;
            case 2:if(ch[i]=='a') state=6;
                    else if(ch[i]=='b') state=2;
                    else state=6;
                    break;
            case 3:if(ch[i]=='a') state=3;
                    else if(ch[i]=='b') state=2;
                    else state=6;
                    break;
            case 4:if(ch[i]=='a') state=6;
                    else if(ch[i]=='b') state=5;
                    else state=6;
                    break;
            case 5:if(ch[i]=='a') state=6;
                    else if(ch[i]=='b') state=2;
                    else state=6;
                    break;
            case 6:printf("NOT RECOGNISED\n");
                    return(main());
        }
        i++;
    }
    if(state==0 || state ==1 || state==3)
        printf("BELONG TO PATTERN a*\n");
    else if(state==2 || state==4)
        printf("BELONG TO PATTERN a*b+\n");
    else if(state==5)
        printf("BELONG TO PATTERN abb\n");
    else
        printf("NOT RECOGNISED\n");
    return (main());
}
