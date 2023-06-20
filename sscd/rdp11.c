//Write a C program to implement recursive descent parsing for the given grammar.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int noofproduction,k,temp;
char productionset[20][20];
char str[20];
int reult;

void nonterminal(char p)
{
    int i,j,found=0;
    for(i=0; i<noofproduction; i++)
    {
        temp=k;
        if(productionset[i][0]==p)
            for(j=3; productionset[i][j]!='\0'; j++)
                if(isupper(productionset[i][j]))
                {
                    found=1;
                    nonterminal(productionset[i][j]);
                }
                else if (productionset[i][j]==str[k])
                {
                    k++;
                    found=1;
                }
                else if(productionset[i][j]=='#')
                {
                    found=1;
                    return;
                }
                else
                {
                    k=temp;
                    break;
                }
    }
    if(i>=noofproduction && found==0 && k!=strlen(str))
    {
        printf("input invalid");
        exit(0);
    }
}
int main()
{
    int i,ch;
    printf("\n Enter the no of productions:\n");
    scanf("%d",&noofproduction);
    printf("\n Enter the productions in form like E->E+T (Enter # for the epsilon)\n");
    for(i=0;i<noofproduction;i++)
    {
        printf("enter the production number %d:",i+1);
        scanf("%s",productionset[i]);
    }
    do
    {
        k=0;
        printf("\n Enter the string\n");
        scanf("%s",str);
        nonterminal(productionset[0][0]);
        if(k==strlen(str))
            printf("\n input string is valid \n");
        else
            printf("\n input string is invalid\n");
        printf("\n do you want to continue (0/1)\n");
        scanf("%d",&ch);
    }while(ch==1);
    return 0;
}
