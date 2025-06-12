#include <string.h>
#include "score.h"

int calculateScore(const char* original, const char* input) {
    int correct = 0;
    int lenOriginal = strlen(original);
    int lenInput = strlen(input);
    int total = (lenOriginal > lenInput) ? lenOriginal : lenInput;

    for (int i = 0; i < total; i++) {
        char a = (i < lenOriginal) ? original[i] : '\0';
        char b = (i < lenInput) ? input[i] : '\0';
        if (a == b) correct++;
    }

    return (correct * 100) / total;
}