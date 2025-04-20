#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str;
    str = (char *)malloc(20);
    printf("문자열 입력하고 엔터>");
    scanf("%s",str);
    printf("입력된 문자열:%s\n",str);
    free(str);
    return 0;
}