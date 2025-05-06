#include <stdio.h>
#include "typing.h"
#include "sentence.h"
#include "score.h"
#include "storage.h"
#include "utils.h"

void startTypingGame(int mode) {
    char sentence[256];
    loadSentence(sentence, mode);

    printf("\n문장: %s\n", sentence);
    printf("입력: ");
    char input[256];
    fgets(input, sizeof(input), stdin);

    int score = calculateScore(sentence, input);
    printf("점수: %d\n", score);

    saveScore(score);
}
    