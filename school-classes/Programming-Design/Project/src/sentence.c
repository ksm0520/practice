#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sentence.h"

void loadSentence(char *buffer, int mode) {
    const char *fileName;

    switch (mode) {
        case 1: fileName = "data/easy.txt"; break;
        case 2: fileName = "data/normal.txt"; break;
        case 3: fileName = "data/hard.txt"; break;
        default: fileName = "data/normal.txt"; break;
    }

    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        strcpy(buffer, "기본 문장을 불러올 수 없습니다.");
        return;
    }

    fgets(buffer, 256, fp);
    fclose(fp);
}
