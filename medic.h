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

int addAppointment(medical *m);                                           // ���� ������ �߰��ϴ� �Լ�
void readAppointment(medical m);                                          // �ϳ��� ����� ���� ������ ������ִ� �Լ�
void listAppointment(medical *m[], int cnt);                              // ����� ���� ���� ����� �����ִ� �Լ�
int updateAppointment(medical *m);                                        // ����� ���� ���� �� Ư�� ������ �������ִ� �Լ�
int deleteAppointment(medical **m);                                       // ����� ���� ���� �� Ư�� ������ �������ִ� �Լ�
int selectAppointment(medical *m[], int cnt);                             // ����� ���� ���� �߿� ����,�����ϰ� ���� ������ �������ִ� �Լ�
void saveToFile(medical *m[], int cnt);                                   // �����͸� ���Ͽ� �������ִ� �Լ�
int loadFile(medical *m[]);                                               // ���Ͽ��� ����� �����͸� �о���� �Լ�
int searchByPatient(medical *m[], int cnt, char Pname[], int menu_check); // ����� ȯ�� �̸����� ���� ������ ������ִ� �Լ�
void searchByDate(medical *m[], int cnt);                                 // Ư�� ���ڿ� ����� ���� ����� ������ִ� �Լ�
void searchByDepartment(medical *m[], int cnt);                           // Ư�� ������� ����� ���� ����� ������ִ� �Լ�
void searchByProf(medical *m[], int cnt);                                 // Ư�� �������� ����� ���� ����� ������ִ� �Լ�
const char *proflist(char s[]);                                           // ���� ����� ������ִ� �Լ�