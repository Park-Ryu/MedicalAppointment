#include <stdio.h>

typedef struct{
    char patientName[15];
    char date[10];
    char birth[10];
    char gender;
    char medicDept[15];
    char prof[15];
    char memo[50];
}medical;

int addAppointment(medical *m);
void readAppointment(medical m);
void listAppointment(medical *m[],int cnt);
int updateAppointment(medical *m);
int deleteAppointment(medical *m);
int selectAppointment(medical *m[],int cnt);
void saveToFile(medical *m[],int cnt);
int loadFile(medical *m[]);
void searchPatient(medical *m[],int cnt);
void searchByDate(medical *m[],int cnt);
void searchByProf(medical *m[],int cnt);
void proflist();


int addAppointment(medical *m){
    printf("**************************************************\n");
    printf("ȯ�ڸ���? ");
    printf("��� �������ڴ�(eg. 20230505(2023�� 5�� 5��))? ");
    printf("���������(eg. 20230505(2023�� 5�� 5��))? ");
    printf("������? ");

    printf("\n [����� �ܰ� ����� ���� ����� �̺����İ� ����� �Ű�� ����� ����ΰ� ����� �Ҿư� ����� �Ȱ� �����]");
    printf("����������? ");
    printf("\n");
    proflist();
    printf("��� ������? ");
    printf("Ư�̻�����(�޸�)? ");

    return 1;
}
void readAppointment(medical m);
void listAppointment(medical *m[],int cnt);
int updateAppointment(medical *m);
int deleteAppointment(medical *m);
int selectAppointment(medical *m[],int cnt);
void saveToFile(medical *m[],int cnt);
int loadFile(medical *m[]);
void searchPatient(medical *m[],int cnt);
void searchByDate(medical *m[],int cnt);
void searchByProf(medical *m[],int cnt);

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