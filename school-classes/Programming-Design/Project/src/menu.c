// menu.c
#include <stdio.h>
#include <windows.h>
#include "menu.h"
#include "typing.h"
#include "utils.h"

void setConsoleSize(int width, int height) {
    char command[100];
    sprintf(command, "mode con: cols=%d lines=%d", width, height);
    system(command);
}

void gotoxy(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int getConsoleHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int getDisplayWidth(const char *str) {
    int width = 0;
    for (int i = 0; str[i];) {
        unsigned char c = str[i];
        if (c < 0x80) { width += 1; i += 1; }
        else if ((c & 0xE0) == 0xC0) { width += 2; i += 2; }
        else if ((c & 0xF0) == 0xE0) { width += 2; i += 3; }
        else if ((c & 0xF8) == 0xF0) { width += 2; i += 4; }
        else i++;
    }
    return width;
}

void showMainMenu() {
    setConsoleSize(100, 40);

    const int boxWidth = 60;
    const int boxHeight = 30;
    const int contentLines = 5;

    int consoleWidth = getConsoleWidth();
    int consoleHeight = getConsoleHeight();
    int leftPadding = (consoleWidth - boxWidth) / 2;
    int topPadding = (consoleHeight - boxHeight) / 2;

    char *lines[] = {
        "\xF0\x9F\x8E\xAE  \xED\x83\x80\xEC\x9E\x90 \xEC\x97\xAC\xEC\x8A\xB5 \xEA\xB2\x8C\xEC\x9E\x84 \xEC\x8B\x9C\xEC\x9E\x91!  \xF0\x9F\x8E\xAE",
        "1.  \xF0\x9F\x9F\xA2  \xEC\x89\xAC\xEC\x9B\x80",
        "2.  \xF0\x9F\x9F\xA1  \xEB\xB3\xB4\xED\x86\xB5",
        "3.  \xF0\x9F\x94\xB4  \xEC\x96\xB4\xEB\xA0\xA4\xEC\x9B\x80",
        "\xF0\x9F\x91\x89 \xEB\x82\x9C\xEC\x9D\xB4\xEB\x8F\x84\xEB\xA5\xBC \xEC\x84\xA0\xED\x83\x9D\xED\x95\x98\xEC\x84\xB8\xEC\x9A\x94 (1~3):"
    };

    // 테두리 그리기
    gotoxy(leftPadding, topPadding);
    printf("╔");
    for (int i = 0; i < boxWidth - 2; i++) printf("═");
    printf("╗");

    for (int i = 1; i < boxHeight - 1; i++) {
        gotoxy(leftPadding, topPadding + i);
        printf("║");
        for (int j = 0; j < boxWidth - 2; j++) printf(" ");
        printf("║");
    }

    gotoxy(leftPadding, topPadding + boxHeight - 1);
    printf("╚");
    for (int i = 0; i < boxWidth - 2; i++) printf("═");
    printf("╝");

    // 내용 출력
    int contentStartY = topPadding + 2 + (boxHeight - 2 - contentLines) / 2;
    for (int i = 0; i < contentLines; i++) {
        int w = getDisplayWidth(lines[i]);
        int x = leftPadding + (boxWidth - w) / 2;
        gotoxy(x, contentStartY + i);
        printf("%s", lines[i]);
    }

    // 입력 받기
    int mode;
    int promptWidth = getDisplayWidth(lines[4]);
    gotoxy(leftPadding + (boxWidth - promptWidth) / 2 + promptWidth + 1, contentStartY + 4);
    scanf("%d", &mode);
    clearBuffer();

    // 박스 안 메뉴 내용 지우기
    for (int i = contentStartY; i < contentStartY + contentLines; i++) {
        gotoxy(leftPadding + 1, i);
        for (int j = 0; j < boxWidth - 2; j++) printf(" ");
    }

    // 타자 게임 시작
    startTypingGame(mode);
}