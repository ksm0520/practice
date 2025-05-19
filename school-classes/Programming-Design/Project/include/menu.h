#ifndef MENU_H
#define MENU_H

void showMainMenu();
void startMatrixEffect(int durationMs);
extern char username[50];// 사용자 이름 (전역 공유용)
void gotoxy(int x, int y);// 콘솔 커서 이동

#endif
