#include <stdio.h>
#include "menu.h"

int selectMenu(){
    int menu;
    printf("===========================================\n");
    printf("====>>>>>  H-medic�� menu�Դϴ�.  <<<<<====\n");
    printf("===========================================\n");

    printf("|             1. ��ȸ                      |\n");
    printf("|             2. �߰�                      |\n");
    printf("|             3. ����                      |\n");
    printf("|             4. ����                      |\n");
    printf("|             5. ���� ����                 |\n");
    printf("|             6. �����ڸ� �˻�             |\n");
    printf("|             7. ����ȯ�� ��� ���ں� �˻� |\n");
    printf("|             8. ����ȯ�� ��� ����� �˻� |\n");
    printf("|             9. ����ȯ�� ��� ������ �˻� |\n");
    printf("|             0. ����                      |\n");
    printf("===========================================\n\n");

    printf("=> ????? ?????? ");
    scanf("%d",&menu);

    return menu;
}