#include <stdio.h>
#include "menu.h"

int selectMenu(){
    int menu;
    printf("===========================================\n");
    printf("====>>>>>  H-medic의 menu입니다.  <<<<<====\n");
    printf("===========================================\n");

    printf("|             1. 조회                      |\n");
    printf("|             2. 추가                      |\n");
    printf("|             3. 수정                      |\n");
    printf("|             4. 삭제                      |\n");
    printf("|             5. 파일 저장                 |\n");
    printf("|             6. 예약자명 검색             |\n");
    printf("|             7. 예약환자 목록 일자별 검색 |\n");
    printf("|             8. 예약환자 목록 진료과 검색 |\n");
    printf("|             9. 예약환자 목록 교수별 검색 |\n");
    printf("|             0. 종료                      |\n");
    printf("===========================================\n\n");

    printf("=> ????? ?????? ");
    scanf("%d",&menu);

    return menu;
}