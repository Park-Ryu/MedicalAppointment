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

int addAppointment(medical *m);                                           // 진료 예약을 추가하는 함수
void readAppointment(medical m);                                          // 하나의 예약된 진료 예약을 출력해주는 함수
void listAppointment(medical *m[], int cnt);                              // 예약된 진료 예약 목록을 보여주는 함수
int updateAppointment(medical *m);                                        // 예약된 진료 예약 중 특정 예약을 수정해주는 함수
int deleteAppointment(medical **m, int cnt, int no);                                       // 예약된 진료 예약 중 특정 예약을 삭제해주는 함수
int selectAppointment(medical *m[], int cnt);                             // 예약된 진료 예약 중에 수정,삭제하고 싶은 예약을 선택해주는 함수
void saveToFile(medical *m[], int cnt);                                   // 데이터를 파일에 저장해주는 함수
int loadFile(medical *m[]);                                               // 파일에서 저장된 데이터를 읽어오는 함수
int searchByPatient(medical *m[], int cnt, char Pname[], int menu_check); // 예약된 환자 이름으로 예약 내역을 출력해주는 함수
void searchByDate(medical *m[], int cnt);                                 // 특정 일자에 예약된 예약 목록을 출력해주는 함수
void searchByDepartment(medical *m[], int cnt);                           // 특정 진료과에 예약된 예약 목록을 출력해주는 함수
void searchByProf(medical *m[], int cnt);                                 // 특정 교수에게 예약된 예약 목록을 출력해주는 함수
const char *proflist(char s[]);                                           // 교수 목록을 출력해주는 함수