#include <stdio.h>

int main()
{
    int i,sum=0;
    for(i=1;i<=10;i++)
    {
        if(i%3==0) continue;
        sum = sum + i;
    }
    printf("합의 결과:%d\n",sum);
    return 0;

}