#include <stdio.h>
#include "storage.h"

void saveScore(int score) {
    FILE *fp = fopen("score.txt", "a");
    if (fp == NULL) return;
    fprintf(fp, "Score: %d\n", score);
    fclose(fp);
}
