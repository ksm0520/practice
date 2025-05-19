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
        case 4: fileName = "data/song1.txt"; break;
        case 5: fileName = "data/song2.txt"; break;
        case 6: fileName = "data/song3.txt"; break;
        case 7: fileName = "data/song4.txt"; break;
        case 8: fileName = "data/song5.txt"; break;
        case 9: fileName = "data/song6.txt"; break;
        case 10: fileName = "data/code1.txt"; break;
        case 11: fileName = "data/code2.txt"; break;
        case 12: fileName = "data/code3.txt"; break;
        case 13: fileName = "data/code4.txt"; break;
        case 14: fileName = "data/code5.txt"; break;
        case 15: fileName = "data/code6.txt"; break;
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
