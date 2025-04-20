#include <stdio.h>
int main()
{
    char *name1="string";
    char *name2="shapter";
    printf("문자열 format\n");
    printf("\n1.name1=%10s",name1);
    printf("\n2.name2=%10s",name2);
    printf("\n4.name2=%-10s",name2);
    printf("\n5.name1=%.3s",name1);
    printf("\n6.name2=%.4s",name2);
    return 0;
}
