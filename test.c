#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char patientName[15];
    char date[11];
    char birth[11];
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

void proflist(char s[]){
    char deptList[7][20]={{"외과"},{"내과"},{"이비인후과"},{"신경과"},{"산부인과"},{"소아과"},{"안과"}};

    for(int i=0;i<7;i++){
        if(strstr(s,deptList[i])){
            printf("선택한 진료과는 %s입니다.\n",s);
            break;
        }
    }   
}

int addAppointment(medical *m){
    int check=0;

    printf("**************************************************\n");
    printf("환자명은? ");
    fflush(stdin);
    fgets(m->patientName,sizeof(m->patientName),stdin);
    m->patientName[strlen(m->patientName)-1]='\0';

    //이미 존재하는 예약자(searchByPatient로 구현)면 return -1; 한 다음 main에서 바로 update함수 호출될 수 있게 구현

    do{
        if(check!=0) printf("잘못입력하셨습니다...형식에 맞게 제대로 입력하세요!\n\n");
        
        printf("희망 예약일자는(eg. 20230505(2023년 5월 5일))? ");
        fflush(stdin);
        fgets(m->date,sizeof(m->date),stdin);
        m->date[strlen(m->date)-1]='\0';
        check++;
        printf("date: %s\n",m->date);
    }while (strlen(m->date)!=8);
    
    check=0;
    do{
        if(check!=0) printf("잘못입력하셨습니다...형식에 맞게 제대로 입력하세요!\n\n");
        
        printf("생년월일은(eg. 20230505(2023년 5월 5일))? ");
        fflush(stdin);
        fgets(m->birth,sizeof(m->birth),stdin);
        m->birth[strlen(m->birth)-1]='\0';
        check++;
    }while (strlen(m->birth)!=8);

    check=0;
    do{
        if(check!=0) printf("잘못입력하셨습니다...형식에 맞게 제대로 입력하세요!\n\n");

        fflush(stdin);
        printf("성별은(여자 : F, 남자 : M)? ");
        scanf("%c",&m->gender);
        check++;
    }while(m->gender!='M' && m->gender!='F');

    check=0;
    do{
        if(check!=0) printf("해당 과는 존재하지 않습니다...현재 존재하는 과를 선택하세요!\n\n");

        printf("\n[■■■■ 외과 ■■■■ 내과 ■■■■ 이비인후과 ■■■■ 신경과 ■■■■ 산부인과 ■■■■ 소아과 ■■■■ 안과 ■■■■]\n");
        printf("희망진료과는? ");
        fflush(stdin);
        fgets(m->medicDept,sizeof(m->medicDept),stdin);
        m->medicDept[strlen(m->medicDept)-1]='\0';
        check++;
    }while(strstr(m->medicDept,"외과")==NULL && strstr(m->medicDept,"내과")==NULL && strstr(m->medicDept,"이비인후과")==NULL && strstr(m->medicDept,"신경과")==NULL && strstr(m->medicDept,"산부인과")==NULL && strstr(m->medicDept,"소아과")==NULL && strstr(m->medicDept,"안과")==NULL);

    printf("\n");
    proflist(m->medicDept);
    printf("희망 교수는? ");
    fflush(stdin);
    fgets(m->prof,sizeof(m->prof),stdin);
    m->prof[strlen(m->prof)-1]='\0';

    printf("특이사항은(현재 증상)? ");
    fflush(stdin);
    fgets(m->memo,sizeof(m->memo),stdin);
    m->memo[strlen(m->memo)-1]='\0';

    return 1;
}
void readAppointment(medical m){
    printf("  %s      %s      %s       %c           %s           %s  %s\n",m.patientName,m.date,m.birth,m.gender,m.medicDept,m.prof,m.memo);
}
void listAppointment(medical *m[],int cnt){
    printf("========================Make an medical appointment with H-medic========================\n");
    printf("========================================================================================\n");
    printf("No PatientName    date           birth      gender   medicDepartment      prof     memo          \n");
    printf("----------------------------------------------------------------------------------------\n");
    for(int i=0;i<cnt;i++){
        if(m[i]==NULL){
            printf("실행됨!\n");
            continue;
        }

        printf("%2d ",i+1);
        readAppointment(*m[i]);
    }
    printf("\n");
}
int updateAppointment(medical *m);
int deleteAppointment(medical *m);
int selectAppointment(medical *m[],int cnt);
void saveToFile(medical *m[],int cnt){ //특이사항 없으면 'x' 파일에 저장하도록 수정하기
    FILE *fp;
    fp=fopen("medical.txt","wt");
    for(int i=0;i<cnt;i++){
        if(m[i]==NULL) continue;
        fprintf(fp,"%s,%s,%s,%c %s,%s,%s\n",m[i]->patientName,m[i]->date,m[i]->birth,m[i]->gender,m[i]->medicDept,m[i]->prof,m[i]->memo);
    }
    fclose(fp);
    printf("저장됨!\n");
}
int loadFile(medical *m[]){
    FILE *fp;
    fp=fopen("medical.txt","rt");
    char trash;
    int i=0;
    if(fp==NULL){
        printf("=> 파일 없음!\n");
        return 0;
    }
    for(i=0;i<100;i++){
        m[i]=(medical*)malloc(sizeof(medical));
        fscanf(fp,"%[^,]s",m[i]->patientName);
        if(feof(fp)){
            break;
        }

        fscanf(fp,"%c",&trash);
        fscanf(fp,"%[^,]s",m[i]->date);
        fscanf(fp,"%c",&trash);
        fscanf(fp,"%[^,]s",m[i]->birth);
        fscanf(fp,"%c",&trash);
        fscanf(fp,"%c",&m[i]->gender);
        fscanf(fp,"%c",&trash);
        fscanf(fp,"%[^,]s",m[i]->medicDept);
        fscanf(fp,"%c",&trash);
        fscanf(fp,"%[^,]s",m[i]->prof);
        fscanf(fp,"%c",&trash);
        fscanf(fp,"%[^\n]s",m[i]->memo);
    
        fscanf(fp,"%c",&trash);
    }
    fclose(fp);
    printf("=> 로딩 성공!\n");

    return i;
}

void searchPatient(medical *m[],int cnt);
void searchByDate(medical *m[],int cnt);

void searchByDepartment(medical *m[],int cnt){
    char deptName[15];
    int check=0;
    do{
    if(check!=0) printf("해당 과는 존재하지 않습니다...현재 존재하는 과를 선택하세요!\n\n");

    printf("\n[■■■■ 외과 ■■■■ 내과 ■■■■ 이비인후과 ■■■■ 신경과 ■■■■ 산부인과 ■■■■ 소아과 ■■■■ 안과 ■■■■]\n");
    printf("예약 내역을 검색하고 싶은 진료과는? ");
    fflush(stdin);
    fgets(deptName,sizeof(deptName),stdin);
    deptName[strlen(deptName)-1]='\0';
    check++;
    }while(strstr(deptName,"외과")==NULL && strstr(deptName,"내과")==NULL && strstr(deptName,"이비인후과")==NULL && strstr(deptName,"신경과")==NULL && strstr(deptName,"산부인과")==NULL && strstr(deptName,"소아과")==NULL && strstr(deptName,"안과")==NULL);

    printf("\n\n검색을 요청하신 진료과는 '%s'입니다!\n\n",deptName);

    printf("========================Make an medical appointment with H-medic========================\n");
    printf("========================================================================================\n");
    printf("No PatientName    date           birth      gender   medicDepartment      prof     memo          \n");
    printf("----------------------------------------------------------------------------------------\n");
    for(int i=0;i<cnt;i++){
        if(strstr(m[i]->medicDept,deptName)){
            if(m[i]==NULL) continue;

            printf("%d",i+1);
            readAppointment(*m[i]);
        }
    }

}
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

int main(){
    medical *m1[100];
    int menu;
    int cnt=0,ind=0;
    cnt+=loadFile(m1);
    ind=cnt;
    if(cnt!=0)listAppointment(m1,cnt);
    while(1){
        printf("실행(1) 종료(0) 저장(5) 검색(8):");
        scanf("%d",&menu);
        if(menu==0){
            printf("=> 종료\n");
            break;
        }

        if(menu==5){
            saveToFile(m1,cnt);
            break;
        }
        
        if(menu==8){
            searchByDepartment(m1,cnt);
            continue;
        }

        m1[ind]=(medical*)malloc(sizeof(medical));
        cnt+=addAppointment(m1[ind++]);
        listAppointment(m1,cnt);

        
        printf("\n");
    }
}
