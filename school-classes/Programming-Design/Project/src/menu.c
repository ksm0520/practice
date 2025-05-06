#include <stdio.h>
#include <windows.h>
#include <string.h>
#include "menu.h"
#include "typing.h"
#include "utils.h"

// 콘솔 창 너비 가져오기
int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return 80;
}

// 콘솔 창 높이 가져오기
int getConsoleHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
    return 25;
}

// 중앙 정렬 출력
void showMainMenu() {
    int mode;
    system("cls");

    int width = getConsoleWidth();
    int height = getConsoleHeight();
    int boxWidth = 60; // 박스 폭 고정

    int leftPadding = (width - boxWidth) / 2;
    int topPadding = (height - 11) / 2;

    char *lines[] = {
        "\xF0\x9F\x8E\xAE  타자 연습 게임 시작!  \xF0\x9F\x8E\xAE",
        "1.  \xF0\x9F\x9F\xA2  쉬움",
        "2.  \xF0\x9F\x9F\xA1  보통",
        "3.  \xF0\x9F\x94\xB4  어려움",
        "\xF0\x9F\x91\x89 난이도를 선택하세요 (1~3):"
    };

    // 상단 테두리
    for (int i = 0; i < leftPadding; i++) printf(" ");
    printf("╔");
    for (int i = 0; i < boxWidth - 2; i++) printf("═");
    printf("╗\n");

    // 위쪽 빈 줄
    for (int i = 0; i < topPadding; i++) {
        for (int j = 0; j < leftPadding; j++) printf(" ");
        printf("║");
        for (int j = 0; j < boxWidth - 2; j++) printf(" ");
        printf("║\n");
    }

    // 중앙 내용 출력
    for (int l = 0; l < 5; l++) {
        int padding = (boxWidth - 2 - 36) / 2; // 내용 너비 감안 (이모지 포함 예상 폭)
        for (int j = 0; j < leftPadding; j++) printf(" ");
        printf("║");
        for (int k = 0; k < padding; k++) printf(" ");
        printf("%s", lines[l]);
        for (int k = 0; k < (boxWidth - 2 - padding - strlen(lines[l])); k++) printf(" ");
        printf("║\n");
    }

    // 아래쪽 빈 줄
    for (int i = 0; i < topPadding; i++) {
        for (int j = 0; j < leftPadding; j++) printf(" ");
        printf("║");
        for (int j = 0; j < boxWidth - 2; j++) printf(" ");
        printf("║\n");
    }

    // 하단 테두리
    for (int i = 0; i < leftPadding; i++) printf(" ");
    printf("╚");
    for (int i = 0; i < boxWidth - 2; i++) printf("═");
    printf("╝\n");

    printf("\n> 입력: ");
    scanf("%d", &mode);
    
    clearBuffer();
    startTypingGame(mode); 
}
