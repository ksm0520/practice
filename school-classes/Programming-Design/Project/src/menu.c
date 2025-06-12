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

// char username[50];  // 여기서 정의하는 대신 main.c에서 정의합니다.
extern char username[50]; // main.c에 정의된 username을 사용하겠다고 선언합니다.


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
int getDisplayWidth(const char* str) {
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
    int* drops = (int*)malloc(sizeof(int) * width);

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

// GAME + KeyRush 로고출력
void printLogo() {
    setConsoleSize(145, 40);
    system("cls");

    int w = getConsoleWidth();
    int h = getConsoleHeight();

    const char* logoLines[] = {
        "                                   ██╗  ██╗███████╗██╗   ██╗    ██████╗ ██╗   ██╗███████╗██╗  ██╗",
        "                                   ██║ ██╔╝██╔════╝╚██╗ ██╔╝    ██╔══██╗██║   ██║██╔════╝██║  ██║",
        "                                   █████╔╝ █████╗   ╚████╔╝     ██████╔╝██║   ██║███████╗███████║",
        "                                   ██╔═██╗ ██╔══╝    ╚██╔╝      ██╔══██╗██║   ██║╚════██║██╔══██║",
        "                                   ██║  ██╗███████╗   ██║       ██║  ██║╚██████╔╝███████║██║  ██║",
        "                                   ╚═╝  ╚═╝╚══════╝   ╚═╝       ╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝"
    };
    int totalLogoLines = sizeof(logoLines) / sizeof(logoLines[0]);
    int baseY = h / 2 - totalLogoLines / 2;
    int offsetY = 0;
    int direction = 1;

    const char* msg1 = "- English typing program -";
    const char* msg2 = "Press any key to continue...";

    while (!_kbhit()) {  // 키 누를 때까지 계속 흔들기
        system("cls");

        // 로고 흔들리는 위치
        for (int i = 0; i < totalLogoLines; i++) {
            gotoxy(0, baseY + offsetY + i);
            printf("%s", logoLines[i]);
        }

        // 고정 위치 텍스트 (중앙 정렬)
        int x1 = (w - getDisplayWidth(msg1)) / 2;
        int x2 = (w - getDisplayWidth(msg2)) / 2;
        gotoxy(x1, baseY + totalLogoLines + 11);
        printf("%s", msg1);
        gotoxy(x2, baseY + totalLogoLines + 14);
        printf("%s", msg2);

        Sleep(300);  // 흔들림 속도

        offsetY += direction;
        if (offsetY > 1 || offsetY < 0)  // 0 ↔ 1만 반복
            direction *= -1;
    }

    _getch();  // 입력 소비하고 빠져나가기
}



void showMainMenu(int isRestart) {
    setConsoleSize(145, 40);


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


    // 5. 사용자 이름 및 최고 타수 표시
    else {
        gotoxy(leftPadding + 4, nameInputY);
        printf("👤 사용자 이름: %s", username);
    }
    gotoxy(leftPadding + 4, nameInputY + 1); // 최고 타수 표시 위치
    showHighScore(); // 최고 타수 출력 함수 호출

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

        gotoxy(leftPadding + (boxWidth - 28) / 2 -2, baseY + numRows * 2 + 6);
        printf("↑↓←→ 이동, Enter로 선택 q로 종료");

        int key = _getch();
        // 방향키 입력 처리
        if (key == 224 || key == 0) {
            key = _getch();
            if (key == KEY_UP && selected - numCols >= 0) selected -= numCols;
            else if (key == KEY_DOWN && selected + numCols < numOptions) selected += numCols;
            else if (key == KEY_LEFT && selected % numCols > 0) selected -= 1;
            else if (key == KEY_RIGHT && selected % numCols < numCols - 1) selected += 1;
        }
        else if (key == KEY_ENTER) {
            break;  // 게임 시작
        }
        else if (key == 'q' || key == 'Q') {
            system("cls");
            printf("\n프로그램을 종료합니다...\n");
            exit(0);  // 즉시 종료
        }
    }

    // 선택 후 박스 내부 지우기
    for (int i = topPadding + 1; i < topPadding + boxHeight - 1; i++) {
        gotoxy(leftPadding + 1, i);
        for (int j = 0; j < boxWidth - 2; j++) printf(" ");
    }

    // 게임 시작 (선택된 인덱스는 1~15로 전달)
    startTypingGame(selected + 1);
}