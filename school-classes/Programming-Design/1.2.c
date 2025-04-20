#include <stdio.h>
int main()
{
    int a=32,b=512;
    long c=4874;
    printf("진법 및 주소 format\n");
    printf("\n1.base 16 of a =%5x",a);
    printf("\n2.base 16 of a =%-5x",a);
    printf("\n3.base 8 of b =%5o",b);
    printf("\n4.base 8 of b =%-5o",b);
    printf("\n7.address of a =%p",&c);
    printf("\n8.address of a =-%u\n",&c);
    return 0;
}
