#include <stdio.h>

#define COUNT 5
int main()
{
    int buffer[COUNT] = {10,20,30,40,50};
    FILE *fp = NULL;

    fp = fopen("sample.txt","wb");
    if(fp==NULL)
    {
        printf("파일 생성 실패\n");
        return 1;
    }

    fwrite(buffer,sizeof(int),COUNT,fp);

    fclose(fp);
    return 0;
}