#ifndef MENU_H
#define MENU_H

void showMainMenu();
void gotoxy(int x, int y);         // 커서 위치 이동 함수
extern char username[50];          // 사용자 이름 (전역 공유용)

#endif
