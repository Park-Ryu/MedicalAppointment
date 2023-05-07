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

int addAppointment(medical *m); // 진료 예약을 추가하는 함수
void readAppointment(medical m); // 하나의 예약된 진료 예약을 출력해주는 함수 
void listAppointment(medical *m[],int cnt); // 예약된 진료 예약 목록을 보여주는 함수
int updateAppointment(medical *m); // 예약된 진료 예약 중 특정 예약을 수정해주는 함수
int deleteAppointment(medical *m); // 예약된 진료 예약 중 특정 예약을 삭제해주는 함수
int selectAppointment(medical *m[],int cnt); // 예약된 진료 예약 중에 수정,삭제하고 싶은 예약을 선택해주는 함수
void saveToFile(medical *m[],int cnt); // 데이터를 파일에 저장해주는 함수
int loadFile(medical *m[]); // 파일에서 저장된 데이터를 읽어오는 함수
void searchPatient(medical *m[],int cnt); // 예약된 환자 이름으로 예약 내역을 출력해주는 함수 
void searchByDate(medical *m[],int cnt); // 특정 일자에 예약된 예약 목록을 출력해주는 함수
void searchByDepartment(medical *m[],int cnt); // 특정 진료과에 예약된 예약 목록을 출력해주는 함수
void searchByProf(medical *m[],int cnt); // 특정 교수에게 예약된 예약 목록을 출력해주는 함수


int addAppointment(medical *m){
    printf("**************************************************\n");
    printf("환자명은? ");
    printf("희망 예약일자는(eg. 20230505(2023년 5월 5일))? ");
    printf("생년월일은(eg. 20230505(2023년 5월 5일))? ");
    printf("성별은? ");

    printf("\n [■■■■ 외과 ■■■■ 내과 ■■■■ 이비인후과 ■■■■ 신경과 ■■■■ 산부인과 ■■■■ 소아과 ■■■■ 안과 ■■■■]");
    printf("희망진료과는? ");
    printf("\n");
    proflist();
    printf("희망 교수는? ");
    printf("특이사항은(메모)? ");

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
void searchByDepartment(medical *m[],int cnt);
void searchByProf(medical *m[],int cnt);

int selectMenu(){
    int menu;

    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일 저장\n");
    printf("6. 예약자명 검색\n");
    printf("7. 예약환자 목록 일자별 검색\n");
    printf("8. 예약환자 목록 진료과 검색\n");
    printf("9. 예약환자 목록 교수별 검색\n");
    printf("0. 종료\n\n");

    printf("=> 원하는 메뉴는? ");
    scanf("%d",&menu);

    return menu;
}