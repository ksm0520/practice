#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int i,j;
    for(i=1;i<=9;i++)
    {
        system("cls");
        for(j=1;j<=9;j++)
        printf("%d*%d=%d\n",i,j,i*j);
        printf("아무키나 누르시오\n");
        getch();
    }
    return 0;
}