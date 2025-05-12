// TODO: 추후 사용자 이름, 날짜 등과 함께 저장 기능 확장 예정
#include <stdio.h>
#include "storage.h"

void saveScore(int score) {
    FILE *fp = fopen("score.txt", "a");
    if (fp == NULL) return;
    fprintf(fp, "Score: %d\n", score);
    fclose(fp);
}
