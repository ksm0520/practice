#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "menu.h"
#include "typing.h"
#include "utils.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ENTER 13

// 콘솔 커서 이동
void gotoxy(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 좌표 범위 검사용 함수
BOOL isInRect(int x, int y, int left, int top, int right, int bottom) {
    return (x >= left && x <= right && y >= top && y <= bottom);
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

// GAME + KeyRush 로고 출력
void printLogo() {
    system("cls");
    int w = getConsoleWidth();
    int h = getConsoleHeight();

    const char* lines[] = {
        "                               ██████╗  █████╗ ███╗   ███╗███████╗",
        "                              ██╔════╝ ██╔══██╗████╗ ████║██╔════╝",
        "                              ██║  ███╗███████║██╔████╔██║█████╗  ",
        "                              ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ",
        "                              ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗",
        "                               ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝",
        "","","",
        "                                            - KeyRush -           ",
        "                                   Press any key to continue...    "
    };

    int totalLines = sizeof(lines) / sizeof(lines[0]);

    // 가장 긴 줄의 길이 계산
    int maxLen = 0;
    for (int i = 0; i < totalLines; i++) {
        int len = getDisplayWidth(lines[i]);
        if (len > maxLen) maxLen = len;
    }

    int startY = h / 2 - totalLines / 2;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);  // 연두색

    for (int i = 0; i < totalLines; i++) {
        int x = (w - maxLen) / 2;
        gotoxy(x, startY + i);
        printf("%s", lines[i]);
    }

    _getch();
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
    int leftPadding = (consoleWidth - boxWidth) / 2;
    int topPadding = (consoleHeight - boxHeight) / 2;

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

    // 사용자 이름 입력
    char username[50];
    int nameInputY = topPadding + 3;
    int nameInputX = leftPadding + 36;
    gotoxy(leftPadding + 4, nameInputY);
    printf("👤 사용자 이름을 입력하세요: ");
    gotoxy(nameInputX, nameInputY);
    scanf("%s", username);
    clearBuffer();

    // 텍스트 및 옵션 출력
    int baseX = leftPadding + (boxWidth / 2) - 30; // 오른쪽으로  이동
    int baseY = topPadding + 10;

    char* difficultyLabels[] = {
        "1.  🟢  쉬움",
        "2.  🟡  보통",
        "3.  🔴  어려움"
    };
    int selected = 0;
    int numOptions = 3;

    while (1) {
        gotoxy(leftPadding + 20, baseY - 2);
        printf("      🎮  타자 연습 게임 시작!  🎮");

        for (int i = 0; i < numOptions; i++) {  
            gotoxy(baseX, baseY + i * 3);
            if (i == selected) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A); // 초록
                printf("👉 %s", difficultyLabels[i]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); // 기본
            } else {
                printf("   %s", difficultyLabels[i]);
            }
        }

        int ch = _getch();
        if (ch == 224) {
            ch = _getch();
            if (ch == 72) selected = (selected - 1 + numOptions) % numOptions; // ↑
            else if (ch == 80) selected = (selected + 1) % numOptions;         // ↓
        } else if (ch == '\r') {
            break; // Enter 입력 시 종료
        }
    }

    // 선택 후 박스 내부 지우기
    for (int i = topPadding + 1; i < topPadding + boxHeight - 1; i++) {
        gotoxy(leftPadding + 1, i);
        for (int j = 0; j < boxWidth - 2; j++) printf(" ");
    }

    // 게임 시작 위치
    int typingX = leftPadding + (boxWidth - 40) / 2;
    int typingY = topPadding + boxHeight / 2;
    gotoxy(typingX, typingY);
    startTypingGame(selected + 1); // 1~3
}
