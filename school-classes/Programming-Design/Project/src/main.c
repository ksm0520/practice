#include <stdio.h>
#include "menu.h"
#include "utils.h"

char username[50]; // 여기서 username을 정의합니다.

int main() {
    setConsoleSize(145, 40); // 초기 콘솔 설정

    // 첫 실행: 로고 + 사용자 이름 입력 + 모드 선택
    showMainMenu(0);

    // 이후 반복: 사용자 이름 유지 + 모드 선택만
    while (1) {
        showMainMenu(1);
    }

    return 0;
}