#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medic.h"

const char* proflist(char s[]){
    int check=0,i,j;
    char select_prof[15];
    char *deptList[7]={"외과","내과","이비인후과","신경과","산부인과","소아과","안과"};
    char *prof[7][5]={
        {"외과A","외과B","외과C","외과D","외과E"},
        {"내과A","내과B","내과C","내과D","내과E"},
        {"이비인후과A","이비인후과B","이비인후과C","이비인후과D","이비인후과E"},
        {"신경과A","신경과B","신경과C","신경과D","신경과E"},
        {"산부인과A","산부인과B","산부인과C","산부인과D","산부인과E"},
        {"소아과A","소아과B","소아과C","소아과D","소아과E"},
        {"안과A","안과B","안과C","안과D","안과E"}
    };

    if(strcmp(s,"find")==0){
        printf("\n");
        for(i=0;i<7;i++){
            printf("| %s :",deptList[i]);
            for(j=0;j<5;j++){
                printf(" %s | ",prof[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }else{
        for(i=0;i<7;i++){
            if(strstr(s,deptList[i])){
                printf("************************************************\n");
                printf("선택하신 진료과: %s\n",s);
                printf("************************************************\n");
                printf(">>>>>>>>>>>>>해당 진료과 교수 리스트<<<<<<<<<<<<<\n");
                for(j=0;j<5;j++){
                    printf("=> %s\n",prof[i][j]);
                }
                break;
            }
        }
    }

    while(1){
        if(check!=0) printf("잘못입력하셨습니다...형식에 맞게 제대로 입력하세요!\n\n");
        if(strcmp(s,"find")==0) printf("찾으시는 교수님은? ");
        else printf("예약 희망 교수님은? ");
        fflush(stdin);
        fgets(select_prof,sizeof(select_prof),stdin);
        select_prof[strlen(select_prof)-1]='\0';
        check++;

        if(strcmp(s,"find")==0){
            for(i=0;i<7;i++){
                for(j=0;j<5;j++){
                    if(strcmp(prof[i][j],select_prof)==0) return prof[i][j];
                }
            }
        }
        else{
            for(int k=0;k<5;k++){
                if(strcmp(prof[i][k],select_prof)==0) return prof[i][k];
            }
        }

        
    }
}

int addAppointment(medical *m){
    int check=0;
    char prof_name[15];

    do{
        if(check!=0){
            printf("잘못입력하셨습니다...형식에 맞게 제대로 입력하세요!\n\n");
        }
        
        printf("희망 예약일자는(eg. 20230505(2023년 5월 5일))? ");
        fflush(stdin);
        fgets(m->date,sizeof(m->date),stdin);
        m->date[strlen(m->date)-1]='\0';
        check++;
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
    
    strcpy(m->prof,proflist(m->medicDept));

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
    int no = 0;
    printf("========================Make an medical appointment with H-medic========================\n");
    printf("========================================================================================\n");
    printf("No PatientName    date           birth      gender   medicDepartment      prof     memo          \n");
    printf("----------------------------------------------------------------------------------------\n");
    for(int i=0;i<cnt;i++){
        if(m[i]==NULL){
            continue;
        }
        no++;
        printf("%2d ",no);
        readAppointment(*m[i]);
    }
    printf("\n");
}
int updateAppointment(medical *m) {
    int check=0;

    printf("**************************************************\n");
    printf("환자명은? ");
    fflush(stdin);
    fgets(m->patientName,sizeof(m->patientName),stdin);
    m->patientName[strlen(m->patientName)-1]='\0';

    do{
        if(check!=0) printf("잘못입력하셨습니다...형식에 맞게 제대로 입력하세요!\n\n");
        
        printf("희망 예약일자는(eg. 20230505(2023년 5월 5일))? ");
        fflush(stdin);
        fgets(m->date,sizeof(m->date),stdin);
        m->date[strlen(m->date)-1]='\0';
        check++;
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

    strcpy(m->prof,proflist(m->medicDept));

    printf("특이사항은(현재 증상)? ");
    fflush(stdin);
    fgets(m->memo,sizeof(m->memo),stdin);
    m->memo[strlen(m->memo)-1]='\0';

    return 1;
}
int deleteAppointment(medical **m) {
    int dlt_ok;
    printf("정말로 삭제하시겠습니까(삭제:1 취소:0)? ");
    scanf("%d",&dlt_ok);
    if(dlt_ok!=1) return 0;

    if((*m)==NULL) free((*m));
    (*m)=NULL;

    return 1;
}
int selectAppointment(medical *m[],int cnt){
    int select;
    listAppointment(m,cnt);
    
    printf("번호는(취소:0)? ");
    scanf("%d",&select);
    
    return select;
}
void saveToFile(medical *m[],int cnt){ 
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

int searchByPatient(medical *m[],int cnt,char Pname[],int menu_check){
    int scnt=0;
    if(menu_check!=2){
        printf("========================Make an medical appointment with H-medic========================\n");
        printf("========================================================================================\n");
        printf("No PatientName    date           birth      gender   medicDepartment      prof     memo          \n");
        printf("----------------------------------------------------------------------------------------\n");
    }
    for(int i=0;i<cnt;i++){
        if(m[i]==NULL) continue;
        if(menu_check==2){
            if(strcmp(m[i]->patientName,Pname)==0) return -1;
        }else{
            if(strstr(m[i]->patientName,Pname)){
            printf("%2d",i+1);
            readAppointment(*m[i]);
            scnt++;
        }
        }
    }

    if(scnt==0){
        if(menu_check!=2) printf("찾으시는 예약 환자가 없습니다...\n");
        return 0;
    }
    return 1;
}
void searchByDate(medical *m[],int cnt) {
    char date[10];
    int no = 0;
    while(1) {
        printf("찾아볼 예약 날짜는? (eg. 20230505(2023년 5월 5일)) : ");
        scanf("%s", date);
        if(strlen(date) == 8) break;
        printf("잘못입력하셨습니다...형식에 맞게 제대로 입력하세요!\n\n");
    }
    printf("========================================================================================\n");
    printf("No PatientName    date           birth      gender   medicDepartment      prof     memo          \n");
    printf("----------------------------------------------------------------------------------------\n");
    
    for(int i = 0; i < cnt; i++) {
        if (m[i] == NULL) continue;
        if(strstr(m[i]->date, date)) {
            no++;
            printf("%2d", i+1);
            readAppointment(*m[i]);
            
            
        }
    }
    if(no == 0) printf("찾으시는 날짜에 예정된 예약이 없습니다.\n");
}

void searchByDepartment(medical *m[],int cnt){
    char deptName[15];
    int i=0,check=0,print_count=0;
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
    for(i=0;i<cnt;i++){
        if(m[i]==NULL) continue;
        if(strstr(m[i]->medicDept,deptName)){

            printf("%d",i+1);
            readAppointment(*m[i]);
            print_count++;
        }
    }
    if(print_count==0){
        printf(">>>>>> 현재 '%s'의 예약 내역이 없습니다!\n",deptName);
    }

}
void searchByProf(medical *m[],int cnt) {
    char prof[15]="find";
    int no = 0;
    
    strcpy(prof,proflist(prof));

    
    printf("========================================================================================\n");
    printf("No PatientName    date           birth      gender   medicDepartment      prof     memo          \n");
    printf("----------------------------------------------------------------------------------------\n");
    
    for(int i = 0; i < cnt; i++) {
        if (m[i] == NULL) continue;
        if(strstr(m[i]->prof, prof)) {
            no++;
            printf("%2d", i+1);
            readAppointment(*m[i]);
        }
    }
    if(no == 0) printf(">>>>>> 해당 교수님의 예약 내역은 없습니다.\n");
}