#include <string.h>
#include "score.h"

int calculateScore(const char *original, const char *input) {
    int correct = 0;
    for (int i = 0; original[i] != '\0' && input[i] != '\0'; i++) {
        if (original[i] == input[i]) correct++;
    }
    return (correct * 100) / strlen(original);
}
