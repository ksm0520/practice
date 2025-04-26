#include <stdio.h>

#define COUNT 5

int main()
{
    int i;
    int buffer[COUNT];
    FILE *fp = NULL;

    fp = fopen("sample.txt","rb");
    if(fp == NULL)
    {
        printf("파일 읽기 실패\n");
        return 1;
    }

    fread(buffer,sizeof(int),COUNT,fp);

    for(i=0;i<COUNT;i++)
        printf("%d",buffer[i]);
    fclose(fp);
    return 0;
}