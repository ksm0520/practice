#include <stdio.h>
#include <time.h>
#include "typing.h"
#include "sentence.h"
#include "score.h"
#include "storage.h"
#include "utils.h"
#include <string.h>

/// 문장 불러오기
void startTypingGame(const char* username,int mode) {
    char sentence[256];
    loadSentence(sentence, mode);

    ///문장 출력 + 사용자 입력받기
    printf("\n문장: %s\n", sentence);
    printf("입력: ");
    char input[256];
    

    /// 사용자 입력 및 걸린시간 측정 
    clock_t start, end;
    double pst;
    start = clock();
    fgets(input, sizeof(input), stdin);
    end = clock();
    pst = (double)(end - start) / CLK_TCK;

    /// 개행 문자 제거(fget함수는 입력끝에 개행을 포함하기 때문이다)
    input[strcspn(input, "\n")] = '\0';

    /// 점수계산
    int score = calculateScore(sentence, input);
    printf("점수: %d점\n", score);
    printf("걸린 시간 : %.2f초\n", pst);

    /// 정확도, 오타율, 맞은 글자 & 틀린 글자
    int lenOriginal = strlen(sentence); /// 출력된 문장의 길이
    int lenInput = strlen(input); /// 사용자 입력 문장의 길이
    int total = (lenOriginal > lenInput) ? lenOriginal : lenInput; /// 전체길이(total)는 위의 두 문장 중 길이가 긴 문장으로 설정
    int correct = 0, wrong = 0; /// 맞은글자수(correct), 틀린글자수(wrong) 초기화


    for (int i = 0; i < total; i++) /// total 문장 하나하나씩 비교
    {
        char origChar = (i < lenOriginal) ? sentence[i] : /// 현재 인덱스(i)가 원본 문장길이 보다 작을 때는 글자 작성
            '\0'; /// 현재 인덱스(i)가 원본 문장길이 보다 길 때 \0(빈문자) 채움
        char inputChar = (i < lenInput) ? input[i] : /// 현재 인덱스(i)가 원본 문장길이 보다 작을 때는 글자 작성
            '\0'; /// 현재 인덱스(i)가 원본 문장길이 보다 길 때 \0(빈문자) 채움

        if (origChar == inputChar) correct++; /// 두개가 같은면 옳은 경우 (correct에 1 더해주기)
        else wrong++; /// 다를경우는 틀린 경우 (wrong에 1 더해주기)
    }

    double accuracy = ((double)correct / total) * 100.0; /// 정확도 = (맞은 글자수 / 전체 글자수)100
    double errorRate = ((double)wrong / total) * 100.0; /// 오타율 = (틀린 글자수 / 전체 글자수)100

    printf("정확도: %.2f%%\n", accuracy);
    printf("오타율: %.2f%%\n", errorRate);
    printf("맞은 글자: %d, 틀린 글자: %d\n", correct, wrong);

    /// 타수계산
    int typedLength = strlen(input);  // 입력한 글자 수
    double charsPerMinute = (typedLength / pst) * 60.0;  /// 분당 타자수 = (입력한 글자 수 / 걸린시간)60
    printf("타수: %.2f 타/분\n", charsPerMinute);

    saveScore(username, score);
}
