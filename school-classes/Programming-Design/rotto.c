#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,j,r,random[6];
    srand(time(NULL));

    for(i=0;i<=5;i++)
    {
        while(1)
        {
            r= rand()%45+1;
            for(j=0;j<i;j++)
            {
                if(r=random[j])
                break;
            }
            if(j==i)
            break;
        }
        random[i]=r;
    }
    for(i=0;i<=5;i++)
    printf("%d\n",random[i]);
    return 0;
}