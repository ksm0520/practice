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
    setConsoleSize(145, 40);

    const int boxWidth = 80;
    const int boxHeight = 30;
    const int contentLines = 5;

    int consoleWidth = getConsoleWidth();
    int consoleHeight = getConsoleHeight();
    int leftPadding = (consoleWidth - boxWidth) / 2;
    int topPadding = (consoleHeight - boxHeight) / 2;

    char *lines[] = {
        "🎮  타자 연습 게임 시작!  🎮",
        "1.  🟢  쉬움",
        "2.  🟡  보통",
        "3.  🔴  어려움",
        "👉 난이도를 선택하세요 (1~3):"
    };

    // Draw box
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

    // Content display
    int contentStartY = topPadding + 2 + (boxHeight - 2 - contentLines) / 2;
    for (int i = 0; i < contentLines; i++) {
        int w = getDisplayWidth(lines[i]);
        int x = leftPadding + (boxWidth - w) / 2;
        gotoxy(x, contentStartY + i);
        printf("%s", lines[i]);
    }

    // User input prompt
    int mode;
    int promptWidth = getDisplayWidth(lines[4]);
    int inputX = leftPadding + (boxWidth - promptWidth) / 2 + promptWidth + 1;
    int inputY = contentStartY + 4;
    gotoxy(inputX, inputY);
    scanf("%d", &mode);
    clearBuffer();

    // Clear content area
    for (int i = contentStartY; i < contentStartY + contentLines; i++) {
        gotoxy(leftPadding + 1, i);
        for (int j = 0; j < boxWidth - 2; j++) printf(" ");
    }

    // Call typing game from same centered box
    int typingX = leftPadding + (boxWidth - 40) / 2;
    int typingY = topPadding + boxHeight / 2;
    gotoxy(typingX, typingY);
    startTypingGame(mode);
}
