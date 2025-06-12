#ifndef MENU_H
#define MENU_H

void showMainMenu(int isRestart);
void startMatrixEffect(int durationMs);
void setConsoleSize(int width, int height);
void printLogo();

extern char username[50];  // 사용자 이름 전역
#endif
