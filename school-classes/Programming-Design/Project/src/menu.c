#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "menu.h"
#include "typing.h"
#include "utils.h"
#include <time.h>
#include <wchar.h>
#include <locale.h>


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

void startMatrixEffect(int durationMs) {
    srand((unsigned int)time(NULL));
    int width = getConsoleWidth();
    int height = getConsoleHeight();

    int *drops = (int *)malloc(width * sizeof(int));
    for (int i = 0; i < width; i++)
        drops[i] = rand() % height;

    DWORD startTime = GetTickCount();

    while (GetTickCount() - startTime < (DWORD)durationMs) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A); // 연두색

        for (int i = 0; i < width; i++) {
            int dropY = drops[i];
            gotoxy(i, dropY);
            char c = 33 + rand() % 94; // ASCII 범위
            printf("%c", c);

            drops[i] = (dropY + 1) % height;
        }

        Sleep(50); // 애니메이션 속도
    }

    free(drops);
    system("cls");
}

// 현재 콘솔 너비
int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

// 현재 콘솔 높이
int getConsoleHeight() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

// 문자열 출력 길이 계산 (한글 등 멀티바이트 대응)
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

void drawBackgroundPattern(int width, int height) {
    char charset[] = {'.', ':', '-', '|', '/', '\\'};

    int charsetSize = sizeof(charset) / sizeof(char);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08); // 어두운 회색

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            gotoxy(x, y);
            char c = charset[(x * y + x + y) % charsetSize];
            printf("%c", c);
        }
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A); // 연두 복원
}


void showMainMenu() {
    setConsoleSize(145, 40); // 충분히 넓은 콘솔로 설정
    startMatrixEffect(2000);  // 2초간 매트릭스 효과

    int consoleWidth = getConsoleWidth();
    int consoleHeight = getConsoleHeight();

    drawBackgroundPattern(consoleWidth, consoleHeight); // 배경 출력

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

    // 박스 상단
    gotoxy(leftPadding, topPadding);
    printf("╔");
    for (int i = 0; i < boxWidth - 2; i++) printf("═");
    printf("╗");

    // 박스 측면
    for (int i = 1; i < boxHeight - 1; i++) {
        gotoxy(leftPadding, topPadding + i);
        printf("║");
        for (int j = 0; j < boxWidth - 2; j++) printf(" ");
        printf("║");
    }

    // 박스 하단
    gotoxy(leftPadding, topPadding + boxHeight - 1);
    printf("╚");
    for (int i = 0; i < boxWidth - 2; i++) printf("═");
    printf("╝");

    // 중앙 콘텐츠 출력
    int contentStartY = topPadding + 2 + (boxHeight - 2 - contentLines) / 2;
    for (int i = 0; i < contentLines; i++) {
        int w = getDisplayWidth(lines[i]);
        int x = leftPadding + (boxWidth - w) / 2;
        gotoxy(x, contentStartY + i);
        printf("%s", lines[i]);
    }

    // 사용자 입력
    int mode;
    int promptWidth = getDisplayWidth(lines[4]);
    int inputX = leftPadding + (boxWidth - promptWidth) / 2 + promptWidth + 1;
    int inputY = contentStartY + 4;
    gotoxy(inputX, inputY);
    scanf("%d", &mode);
    clearBuffer();

    // 콘텐츠 지우기
    for (int i = contentStartY; i < contentStartY + contentLines; i++) {
        gotoxy(leftPadding + 1, i);
        for (int j = 0; j < boxWidth - 2; j++) printf(" ");
    }

    // 중앙 위치에서 게임 시작
    int typingX = leftPadding + (boxWidth - 40) / 2;
    int typingY = topPadding + boxHeight / 2;
    gotoxy(typingX, typingY);
    startTypingGame(mode);
}
