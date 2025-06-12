#include <stdio.h>
#include <string.h>
#include "storage.h"

// 사용자 이름과 글자수를 저장하고, 최고 글자수 파일도 갱신하는 함수
void saveScore(const char* username, double cpm) { // <<<<<< 여기를 double cpm으로 변경
    // score.txt에 현재 글자수 저장
    FILE* fp = fopen("score.txt", "a");
    if (fp == NULL) return;
    fprintf(fp, "%s %.2lf\n", username, cpm); // <<<<<< %.2lf로 변경, cpm 사용
    fclose(fp);

    // 최고 글자수 정보 읽기
    double highCPM; // <<<<<< highCPM으로 변경
    char topUser[100] = "";
    FILE* rfp = fopen("highscore.txt", "r");
    if (rfp && fscanf(rfp, "%s %lf", topUser, &highCPM) == 2) { // <<<<<< %lf로 변경
        fclose(rfp);
        if (cpm > highCPM) { // <<<<<< cpm과 highCPM 비교
            FILE* wfp = fopen("highscore.txt", "w");
            if (wfp) {
                fprintf(wfp, "%s %.2lf\n", username, cpm); // <<<<<< %.2lf로 변경, cpm 사용
                fclose(wfp);
            }
        }
    }
    else {
        // 최고 글자수 파일이 없거나 비어 있을 경우 새로 작성
        FILE* wfp = fopen("highscore.txt", "w");
        if (wfp) {
            fprintf(wfp, "%s %.2lf\n", username, cpm); // <<<<<< %.2lf로 변경, cpm 사용
            fclose(wfp);
        }
    }
}

// 최고 글자수 출력 함수
void showHighScore() {
    char name[100];
    double cpm; // <<<<<< cpm으로 변경
    FILE* fp = fopen("highscore.txt", "r");
    if (fp && fscanf(fp, "%s %lf", name, &cpm) == 2) { // <<<<<< %lf로 변경
        printf("🏆 최고 타수: %s - %.2lf", name, cpm); // <<<<<< %.2lf로 변경 및 메시지 수정
        fclose(fp);
    }
    else {
        printf("🏆 최고 타수:기록 없음");
    }
}