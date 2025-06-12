#include <stdio.h>
#include <time.h>
#include <string.h>
#include "typing.h"
#include "sentence.h"
#include "score.h"
#include "storage.h" // saveScore 함수 사용을 위해 포함
#include "utils.h"
#include <windows.h> // for COORD, SetConsoleCursorPosition, GetStdHandle
#include <conio.h>


extern char username[];  // main.c의 전역 username 참조

// 박스 내부만 클리어하는 함수
void clearBoxContent(int left, int top, int width, int height) {
    for (int y = top + 1; y < top + height - 1; y++) {
        gotoxy(left + 1, y);
        for (int x = 0; x < width - 2; x++) {
            printf(" ");
        }
    }
}

// 왼쪽 정렬된 텍스트 출력 함수 (위치 고정)
void printAlignedText(int x, int y, const char* text) {
    gotoxy(x, y);
    printf("%s", text);
}
// 문장불러오기
void startTypingGame(int mode) {
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    int sentenceCount = 0;
    loadSentences(sentences, &sentenceCount, mode);

    int boxLeft = 38, boxTop = 8;
    int boxWidth = 70, boxHeight = 27;

    int centerX = boxLeft + boxWidth / 2;
    int contentStartX = boxLeft + 5;
    double highestCPM_in_game = 0.0;

    for (int i = 0; i < sentenceCount; i++) {
        clearBoxContent(boxLeft, boxTop, boxWidth, boxHeight);

        char buf[256];

        // 상단 중앙: 문장 진행 표시
        snprintf(buf, sizeof(buf), "문장 %d / %d", i + 1, sentenceCount);
        gotoxy(centerX - (int)strlen(buf) / 2, boxTop + 1);
        printf("%s", buf);

        // 중앙: 문장 및 입력 위치
        int midY = boxTop + boxHeight / 2 - 2;
        gotoxy(contentStartX, midY);
        printf("문장: %s", sentences[i]);

        gotoxy(contentStartX, midY + 2);
        printf("입력: ");
        char input[256];
        gotoxy(contentStartX + strlen("입력:")-1, midY + 2);  // 정확히 정렬
        clock_t start = clock();
        fgets(input, sizeof(input), stdin);
        clock_t end = clock();
        input[strcspn(input, "\n")] = '\0';
        double duration = (double)(end - start) / CLOCKS_PER_SEC;

        // 점수 계산
        int score = calculateScore(sentences[i], input);
        int lenOriginal = strlen(sentences[i]);
        int lenInput = strlen(input);

        int correct = 0;
        int minLen = (lenOriginal < lenInput) ? lenOriginal : lenInput;
        for (int j = 0; j < minLen; j++) {
            if (sentences[i][j] == input[j]) correct++;
        }

        int wrong = 0;
        for (int j = 0; j < lenOriginal; j++) {
            if (j >= lenInput || sentences[i][j] != input[j]) wrong++;
        }
        if (lenInput > lenOriginal) wrong += (lenInput - lenOriginal);

        double accuracy = (double)correct / lenOriginal * 100.0;
        double errorRate = (lenInput > 0) ? ((double)wrong / lenInput * 100.0) : 0.0;
        double cpm_current = (duration > 0) ? (correct / duration) * 60 : 0;
        if (cpm_current > highestCPM_in_game) highestCPM_in_game = cpm_current;

        // 하단 출력
        int statsY = boxTop + boxHeight - 6;
        gotoxy(contentStartX, statsY);
        printf("점수: %d점", score);
        gotoxy(contentStartX + 22, statsY);
        printf("정확도: %.2f%%", accuracy);
        gotoxy(contentStartX + 45, statsY);
        printf("오타율: %.2f%%", errorRate);

        gotoxy(contentStartX, statsY + 1);
        printf("타수: %.2f타", cpm_current);
        gotoxy(contentStartX + 22, statsY + 1);
        printf("맞은 글자: %d, 틀린 글자: %d", correct, wrong);

        gotoxy(contentStartX, statsY + 3);
        printf("계속하려면 Enter, 메뉴로 가려면 q 입력: ");

        int ch = _getch();

        if (ch == 'q' || ch == 'Q') break; // 프로그램 종료
        else if (ch == 13) continue;  // 다음문장 이동
    
    }

    saveScore(username, highestCPM_in_game);
}
