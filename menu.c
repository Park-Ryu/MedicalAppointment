#include <stdio.h>

int selectMenu(){
    int menu;

    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("5. ���� ����\n");
    printf("6. �����ڸ� �˻�\n");
    printf("7. ����ȯ�� ��� ���ں� �˻�\n");
    printf("8. ����ȯ�� ��� ����� �˻�\n");
    printf("9. ����ȯ�� ��� ������ �˻�\n");
    printf("0. ����\n\n");

    printf("=> ���ϴ� �޴���? ");
    scanf("%d",&menu);

    return menu;
}