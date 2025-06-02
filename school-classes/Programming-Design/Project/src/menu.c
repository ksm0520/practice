#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include "menu.h"
#include "typing.h"
#include "utils.h"
#include "storage.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

char username[50];  // 전역 변수로 이동

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

     // 추가로 창 크기도 설정
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rect = { 0, 0, width - 1, height - 1 };
    SetConsoleWindowInfo(hOut, TRUE, &rect);
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);  // 회색

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            gotoxy(x, y);
            char c = charset[(x * y + x + y) % charsetSize];
            printf("%c", c);
        }
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);  // 연두색 
}



// GAME + KeyRush 로고 출력
void printLogo() {
    system("cls");
    int w = getConsoleWidth();
    int h = getConsoleHeight();

    const char* lines[] = {
        "                                    ██████╗  █████╗ ███╗   ███╗███████╗",
        "                                   ██╔════╝ ██╔══██╗████╗ ████║██╔════╝",
        "                                   ██║  ███╗███████║██╔████╔██║█████╗  ",
        "                                   ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ",
        "                                   ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗",
        "                                    ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝",
        "","","",
        "                                                 - KeyRush -           ",
        "                                        Press any key to continue...    "
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



void showMainMenu(int isRestart) {
    setConsoleSize(146, 41);

    if (!isRestart) {
        printLogo();               // 1. 로고
        startMatrixEffect(2000);   // 2. 매트릭스 효과
    }

    int consoleWidth = getConsoleWidth();
    int consoleHeight = getConsoleHeight();
    drawBackgroundPattern(consoleWidth, consoleHeight);

    const int boxWidth = 80;
    const int boxHeight = 30;
    int leftPadding = (consoleWidth - boxWidth) / 2;
    int topPadding = (consoleHeight - boxHeight) / 2;

    // 3. 박스 그리기
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

    // 4. 사용자 이름 입력 (처음 실행 시에만)
    int nameInputY = topPadding + 3;
    int nameInputX = leftPadding + 36;
    if (!isRestart) {
        gotoxy(leftPadding + 4, nameInputY);
        printf("👤 사용자 이름: ");
        gotoxy(nameInputX, nameInputY);
        scanf("%s", username);
        clearBuffer();
    }
    

    // 5. 사용자 이름 및 최고 점수 표시
    else {
    gotoxy(leftPadding + 4, nameInputY);
    printf("👤 사용자 이름: %s", username);
    }
    gotoxy(leftPadding + 4, nameInputY + 1);
    printf("🎯 최고 타율: ");
    // showHighAccuracy();  // 구현되면 주석 해제

    // 6. 모드 선택 메뉴 출력
    char* difficultyLabels[] = {
        "easy", "normal", "hard",
        "song1", "song2", "song3",
        "song4", "song5", "song6",
        "code1", "code2", "code3",
        "code4", "code5", "code6"
    };
    int selected = 0;
    int numOptions = 15;
    int numCols = 3;
    int numRows = 5;

    int baseX = leftPadding + 13;
    int baseY = topPadding + 10;

    while (1) {
        gotoxy(leftPadding + (boxWidth - 28) / 2, baseY - 2);
        printf("🎮  영타자 연습 시작!!!  🎮");

        for (int i = 0; i < numOptions; i++) {
            int row = i / numCols;
            int col = i % numCols;
            int x = baseX + col * 20;
            int y = baseY + row * 3;

            gotoxy(x, y);
            if (i == selected)
                printf("👉 %s", difficultyLabels[i]);
            else
                printf("   %s", difficultyLabels[i]);
        }

        gotoxy(leftPadding + (boxWidth - 28) / 2, baseY + numRows * 2 + 6);
        printf("↑↓←→ 이동, Enter로 선택");

        int key = getch();
        if (key == 224 || key == 0) {
            key = getch();
            if (key == KEY_UP && selected - numCols >= 0) selected -= numCols;
            else if (key == KEY_DOWN && selected + numCols < numOptions) selected += numCols;
            else if (key == KEY_LEFT && selected % numCols > 0) selected -= 1;
            else if (key == KEY_RIGHT && selected % numCols < numCols - 1) selected += 1;
        } else if (key == KEY_ENTER) {
            break;
        }
    }

    // 선택 후 박스 내부 지우기
    for (int i = topPadding + 1; i < topPadding + boxHeight - 1; i++) {
        gotoxy(leftPadding + 1, i);
        for (int j = 0; j < boxWidth - 2; j++) printf(" ");
    }

    // 게임 시작 (선택된 인덱스는 1~15로 전달)
    startTypingGame(username, selected + 1);
}
