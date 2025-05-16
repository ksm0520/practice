#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "menu.h"
#include "typing.h"
#include "utils.h"

// 콘솔 커서 이동
void gotoxy(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 콘솔 크기 설정
void setConsoleSize(int width, int height) {
    char command[100];
    sprintf(command, "mode con: cols=%d lines=%d", width, height);
    system(command);
}

// 콘솔 너비
int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

// 콘솔 높이
int getConsoleHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

// 문자열 출력 폭 계산
int getDisplayWidth(const char *str) {
    int width = 0;
    for (int i = 0; str[i];) {
        unsigned char c = str[i];
        if (c < 0x80) { width += 1; i += 1; }
        else if ((c & 0xE0) == 0xC0) { width += 2; i += 2; }
        else if ((c & 0xF0) == 0xE0) { width += 2; i += 3; }
        else i++;
    }
    return width;
}

// 매트릭스 효과
void startMatrixEffect(int durationMs) {
    srand((unsigned int)time(NULL));
    int width = getConsoleWidth();
    int height = getConsoleHeight();
    int *drops = (int *)malloc(sizeof(int) * width);

    for (int i = 0; i < width; i++) drops[i] = rand() % height;
    DWORD start = GetTickCount();

    while (GetTickCount() - start < (DWORD)durationMs) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
        for (int i = 0; i < width; i++) {
            gotoxy(i, drops[i]);
            printf("%c", 33 + rand() % 94);
            drops[i] = (drops[i] + 1) % height;
        }
        Sleep(50);
    }

    free(drops);
    system("cls");
}

// 배경 무늬
void drawBackgroundPattern(int width, int height) {
    char charset[] = { '/', '\\', '|', '-', ':' };
    int charsetSize = sizeof(charset) / sizeof(char);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            gotoxy(x, y);
            char c = charset[(x * y + x + y) % charsetSize];
            printf("%c", c);
        }
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A); // 다시 연두색
}

// 초기 로고 출력
void printLogo() {
    system("cls");
    int width = getConsoleWidth();

    const char *title = "   ██████  ▄▄▄▄    ████  ████  ▄▄▄▄   ████  ";
    const char *sub =    "   - KeyRush -";
    const char *prompt = "Press any key to continue...";

    int xTitle = (width - strlen(title)) / 2;
    int xSub = (width - strlen(sub)) / 2;
    int xPrompt = (width - strlen(prompt)) / 2;

    gotoxy(xTitle, 10); printf("%s", title);
    gotoxy(xSub, 12); printf("%s", sub);
    gotoxy(xPrompt, 14); printf("%s", prompt);

    _getch(); // 아무 키나
    system("cls");
}

// 메인 메뉴
void showMainMenu() {
    setConsoleSize(145, 40);
    printLogo();
    startMatrixEffect(2000);

    int consoleWidth = getConsoleWidth();
    int consoleHeight = getConsoleHeight();
    drawBackgroundPattern(consoleWidth, consoleHeight);

    const int boxWidth = 80;
    const int boxHeight = 30;
    const int contentLines = 5;
    int leftPadding = (consoleWidth - boxWidth) / 2;
    int topPadding = (consoleHeight - boxHeight) / 2;

    char *lines[] = {
        "🎮  타자 연습 게임 시작!  🎮",
        "1.  🟢  쉬움",
        "2.  🟡  보통",
        "3.  🔴  어려움",
        "👉 난이도를 선택하세요 (1~3):"
    };

    // 박스 그리기
    gotoxy(leftPadding, topPadding); printf("╔");
    for (int i = 0; i < boxWidth - 2; i++) printf("═");
    printf("╗");

    for (int i = 1; i < boxHeight - 1; i++) {
        gotoxy(leftPadding, topPadding + i); printf("║");
        for (int j = 0; j < boxWidth - 2; j++) printf(" ");
        printf("║");
    }

    gotoxy(leftPadding, topPadding + boxHeight - 1); printf("╚");
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
    int inputX = leftPadding + (boxWidth - promptWidth) / 2 + promptWidth + 1;
    int inputY = contentStartY + 4;
    gotoxy(inputX, inputY);
    scanf("%d", &mode);
    clearBuffer();

    // 게임 시작 위치
    int typingX = leftPadding + (boxWidth - 40) / 2;
    int typingY = topPadding + boxHeight / 2;
    gotoxy(typingX, typingY);
    startTypingGame(mode);
}
