#ifndef STORAGE_H
#define STORAGE_H

// 사용자 이름과 글자수(CPM)를 받아 score.txt에 저장하고
// 최고 글자수(highscore.txt)가 갱신되는 경우 업데이트
void saveScore(const char* username, double cpm); // <<<<<< 여기에 double cpm

// highscore.txt 파일에 저장된 최고 글자수 정보를 출력
void showHighScore();

#endif