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

int addAppointment(medical *m); // ���� ������ �߰��ϴ� �Լ�
void readAppointment(medical m); // �ϳ��� ����� ���� ������ ������ִ� �Լ� 
void listAppointment(medical *m[],int cnt); // ����� ���� ���� ����� �����ִ� �Լ�
int updateAppointment(medical *m); // ����� ���� ���� �� Ư�� ������ �������ִ� �Լ�
int deleteAppointment(medical *m); // ����� ���� ���� �� Ư�� ������ �������ִ� �Լ�
int selectAppointment(medical *m[],int cnt); // ����� ���� ���� �߿� ����,�����ϰ� ���� ������ �������ִ� �Լ�
void saveToFile(medical *m[],int cnt); // �����͸� ���Ͽ� �������ִ� �Լ�
int loadFile(medical *m[]); // ���Ͽ��� ����� �����͸� �о���� �Լ�
void searchPatient(medical *m[],int cnt); // ����� ȯ�� �̸����� ���� ������ ������ִ� �Լ� 
void searchByDate(medical *m[],int cnt); // Ư�� ���ڿ� ����� ���� ����� ������ִ� �Լ�
void searchByDepartment(medical *m[],int cnt); // Ư�� ������� ����� ���� ����� ������ִ� �Լ�
void searchByProf(medical *m[],int cnt); // Ư�� �������� ����� ���� ����� ������ִ� �Լ�

void proflist(char s[]){
    char deptList[7][20]={{"�ܰ�"},{"����"},{"�̺����İ�"},{"�Ű��"},{"����ΰ�"},{"�Ҿư�"},{"�Ȱ�"}};

    for(int i=0;i<7;i++){
        if(strstr(s,deptList[i])){
            printf("������ ������� %s�Դϴ�.\n",s);
            break;
        }
    }   
}

int addAppointment(medical *m){
    int check=0;

    printf("**************************************************\n");
    printf("ȯ�ڸ���? ");
    fflush(stdin);
    fgets(m->patientName,sizeof(m->patientName),stdin);
    m->patientName[strlen(m->patientName)-1]='\0';

    //�̹� �����ϴ� ������(searchByPatient�� ����)�� return -1; �� ���� main���� �ٷ� update�Լ� ȣ��� �� �ְ� ����

    do{
        if(check!=0) printf("�߸��Է��ϼ̽��ϴ�...���Ŀ� �°� ����� �Է��ϼ���!\n\n");
        
        printf("��� �������ڴ�(eg. 20230505(2023�� 5�� 5��))? ");
        fflush(stdin);
        fgets(m->date,sizeof(m->date),stdin);
        m->date[strlen(m->date)-1]='\0';
        check++;
        printf("date: %s\n",m->date);
    }while (strlen(m->date)!=8);
    
    check=0;
    do{
        if(check!=0) printf("�߸��Է��ϼ̽��ϴ�...���Ŀ� �°� ����� �Է��ϼ���!\n\n");
        
        printf("���������(eg. 20230505(2023�� 5�� 5��))? ");
        fflush(stdin);
        fgets(m->birth,sizeof(m->birth),stdin);
        m->birth[strlen(m->birth)-1]='\0';
        check++;
    }while (strlen(m->birth)!=8);

    check=0;
    do{
        if(check!=0) printf("�߸��Է��ϼ̽��ϴ�...���Ŀ� �°� ����� �Է��ϼ���!\n\n");

        fflush(stdin);
        printf("������(���� : F, ���� : M)? ");
        scanf("%c",&m->gender);
        check++;
    }while(m->gender!='M' && m->gender!='F');

    check=0;
    do{
        if(check!=0) printf("�ش� ���� �������� �ʽ��ϴ�...���� �����ϴ� ���� �����ϼ���!\n\n");

        printf("\n[����� �ܰ� ����� ���� ����� �̺����İ� ����� �Ű�� ����� ����ΰ� ����� �Ҿư� ����� �Ȱ� �����]\n");
        printf("����������? ");
        fflush(stdin);
        fgets(m->medicDept,sizeof(m->medicDept),stdin);
        m->medicDept[strlen(m->medicDept)-1]='\0';
        check++;
    }while(strstr(m->medicDept,"�ܰ�")==NULL && strstr(m->medicDept,"����")==NULL && strstr(m->medicDept,"�̺����İ�")==NULL && strstr(m->medicDept,"�Ű��")==NULL && strstr(m->medicDept,"����ΰ�")==NULL && strstr(m->medicDept,"�Ҿư�")==NULL && strstr(m->medicDept,"�Ȱ�")==NULL);

    printf("\n");
    proflist(m->medicDept);
    printf("��� ������? ");
    fflush(stdin);
    fgets(m->prof,sizeof(m->prof),stdin);
    m->prof[strlen(m->prof)-1]='\0';

    printf("Ư�̻�����(���� ����)? ");
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
            printf("�����!\n");
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
void saveToFile(medical *m[],int cnt){ //Ư�̻��� ������ 'x' ���Ͽ� �����ϵ��� �����ϱ�
    FILE *fp;
    fp=fopen("medical.txt","wt");
    for(int i=0;i<cnt;i++){
        if(m[i]==NULL) continue;
        fprintf(fp,"%s,%s,%s,%c %s,%s,%s\n",m[i]->patientName,m[i]->date,m[i]->birth,m[i]->gender,m[i]->medicDept,m[i]->prof,m[i]->memo);
    }
    fclose(fp);
    printf("�����!\n");
}
int loadFile(medical *m[]){
    FILE *fp;
    fp=fopen("medical.txt","rt");
    char trash;
    int i=0;
    if(fp==NULL){
        printf("=> ���� ����!\n");
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
    printf("=> �ε� ����!\n");

    return i;
}

void searchPatient(medical *m[],int cnt);
void searchByDate(medical *m[],int cnt);

void searchByDepartment(medical *m[],int cnt){
    char deptName[15];
    int check=0;
    do{
    if(check!=0) printf("�ش� ���� �������� �ʽ��ϴ�...���� �����ϴ� ���� �����ϼ���!\n\n");

    printf("\n[����� �ܰ� ����� ���� ����� �̺����İ� ����� �Ű�� ����� ����ΰ� ����� �Ҿư� ����� �Ȱ� �����]\n");
    printf("���� ������ �˻��ϰ� ���� �������? ");
    fflush(stdin);
    fgets(deptName,sizeof(deptName),stdin);
    deptName[strlen(deptName)-1]='\0';
    check++;
    }while(strstr(deptName,"�ܰ�")==NULL && strstr(deptName,"����")==NULL && strstr(deptName,"�̺����İ�")==NULL && strstr(deptName,"�Ű��")==NULL && strstr(deptName,"����ΰ�")==NULL && strstr(deptName,"�Ҿư�")==NULL && strstr(deptName,"�Ȱ�")==NULL);

    printf("\n\n�˻��� ��û�Ͻ� ������� '%s'�Դϴ�!\n\n",deptName);

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

int main(){
    medical *m1[100];
    int menu;
    int cnt=0,ind=0;
    cnt+=loadFile(m1);
    ind=cnt;
    if(cnt!=0)listAppointment(m1,cnt);
    while(1){
        printf("����(1) ����(0) ����(5) �˻�(8):");
        scanf("%d",&menu);
        if(menu==0){
            printf("=> ����\n");
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
