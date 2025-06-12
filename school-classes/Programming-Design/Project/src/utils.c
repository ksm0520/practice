#include <windows.h>
#include <stdio.h>
#include "utils.h"

void clearBuffer() {
    while (getchar() != '\n');
}

void enforceExactConsoleSize() {
    system("mode con: cols=146 lines=41");

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // 콘솔 창 크기 조절
    SMALL_RECT rect = { 0, 0, 145, 40 }; // width-1, height-1
    SetConsoleWindowInfo(hOut, TRUE, &rect);
}

void gotoxy(int x, int y) {
    COORD pos = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
