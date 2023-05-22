#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "medic.h"

const char *proflist(char s[])
{
    int check = 0, i, j;
    char select_prof[15];
    char *deptList[7] = {"�ܰ�", "����", "�̺����İ�", "�Ű��", "����ΰ�", "�Ҿư�", "�Ȱ�"};
    char *prof[7][5] = {
        {"�ܰ�A", "�ܰ�B", "�ܰ�C", "�ܰ�D", "�ܰ�E"},
        {"����A", "����B", "����C", "����D", "����E"},
        {"�̺����İ�A", "�̺����İ�B", "�̺����İ�C", "�̺����İ�D", "�̺����İ�E"},
        {"�Ű��A", "�Ű��B", "�Ű��C", "�Ű��D", "�Ű��E"},
        {"����ΰ�A", "����ΰ�B", "����ΰ�C", "����ΰ�D", "����ΰ�E"},
        {"�Ҿư�A", "�Ҿư�B", "�Ҿư�C", "�Ҿư�D", "�Ҿư�E"},
        {"�Ȱ�A", "�Ȱ�B", "�Ȱ�C", "�Ȱ�D", "�Ȱ�E"}};

    if (strcmp(s, "find") == 0)
    {
        printf("\n");
        for (i = 0; i < 7; i++)
        {
            printf("| %s :", deptList[i]);
            for (j = 0; j < 5; j++)
            {
                printf(" %s | ", prof[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        for (i = 0; i < 7; i++)
        {
            if (strstr(s, deptList[i]))
            {
                printf("************************************************\n");
                printf("�����Ͻ� �����: %s\n", s);
                printf("************************************************\n");
                printf(">>>>>>>>>>>>>�ش� ����� ���� ����Ʈ<<<<<<<<<<<<<\n");
                for (j = 0; j < 5; j++)
                {
                    printf("=> %s\n", prof[i][j]);
                }
                break;
            }
        }
    }

    while (1)
    {
        if (check != 0)
            printf("�߸��Է��ϼ̽��ϴ�...���Ŀ� �°� ����� �Է��ϼ���!\n\n");
        if (strcmp(s, "find") == 0)
            printf("ã���ô� ��������? ");
        else
            printf("���� ��� ��������? ");
        fflush(stdin);
        fgets(select_prof, sizeof(select_prof), stdin);
        select_prof[strlen(select_prof) - 1] = '\0';
        check++;

        if (strcmp(s, "find") == 0)
        {
            for (i = 0; i < 7; i++)
            {
                for (j = 0; j < 5; j++)
                {
                    if (strcmp(prof[i][j], select_prof) == 0)
                        return prof[i][j];
                }
            }
        }
        else
        {
            for (int k = 0; k < 5; k++)
            {
                if (strcmp(prof[i][k], select_prof) == 0)
                    return prof[i][k];
            }
        }
    }
}

int addAppointment(medical *m)
{
    int check = 0;
    char prof_name[15];

    do
    {
        if (check != 0)
        {
            printf("�߸��Է��ϼ̽��ϴ�...���Ŀ� �°� ����� �Է��ϼ���!\n\n");
        }

        printf("��� �������ڴ�(eg. 20230505(2023�� 5�� 5��))? ");
        fflush(stdin);
        fgets(m->date, sizeof(m->date), stdin);
        m->date[strlen(m->date) - 1] = '\0';
        check++;
    } while (strlen(m->date) != 8);

    check = 0;
    do
    {
        if (check != 0)
            printf("�߸��Է��ϼ̽��ϴ�...���Ŀ� �°� ����� �Է��ϼ���!\n\n");

        printf("���������(eg. 20230505(2023�� 5�� 5��))? ");
        fflush(stdin);
        fgets(m->birth, sizeof(m->birth), stdin);
        m->birth[strlen(m->birth) - 1] = '\0';
        check++;
    } while (strlen(m->birth) != 8);

    check = 0;
    do
    {
        if (check != 0)
            printf("�߸��Է��ϼ̽��ϴ�...���Ŀ� �°� ����� �Է��ϼ���!\n\n");

        fflush(stdin);
        printf("������(���� : F, ���� : M)? ");
        scanf("%c", &m->gender);
        check++;
    } while (m->gender != 'M' && m->gender != 'F');

    check = 0;
    do
    {
        if (check != 0)
            printf("�ش� ���� �������� �ʽ��ϴ�...���� �����ϴ� ���� �����ϼ���!\n\n");

        printf("\n[����� �ܰ� ����� ���� ����� �̺����İ� ����� �Ű�� ����� ����ΰ� ����� �Ҿư� ����� �Ȱ� �����]\n");
        printf("����������? ");
        fflush(stdin);
        fgets(m->medicDept, sizeof(m->medicDept), stdin);
        m->medicDept[strlen(m->medicDept) - 1] = '\0';
        check++;
    } while (strstr(m->medicDept, "�ܰ�") == NULL && strstr(m->medicDept, "����") == NULL && strstr(m->medicDept, "�̺����İ�") == NULL && strstr(m->medicDept, "�Ű��") == NULL && strstr(m->medicDept, "����ΰ�") == NULL && strstr(m->medicDept, "�Ҿư�") == NULL && strstr(m->medicDept, "�Ȱ�") == NULL);

    strcpy(m->prof, proflist(m->medicDept));

    printf("Ư�̻�����(���� ����)? ");
    fflush(stdin);
    fgets(m->memo, sizeof(m->memo), stdin);
    m->memo[strlen(m->memo) - 1] = '\0';

    return 1;
}
void readAppointment(medical m)
{
    printf("  %s      %s      %s       %c           %s           %s  %s\n", m.patientName, m.date, m.birth, m.gender, m.medicDept, m.prof, m.memo);
}
void listAppointment(medical *m[], int cnt)
{
    printf("========================Make an medical appointment with H-medic========================\n");
    printf("========================================================================================\n");
    printf("No PatientName    date           birth      gender   medicDepartment      prof     memo          \n");
    printf("----------------------------------------------------------------------------------------\n");
    int n = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (m[i] == NULL)
            continue;
        n++;
        printf("%2d ", n);
        readAppointment(*m[i]);
    }
    printf("\n");
}
int updateAppointment(medical *m)
{
    int check = 0;

    printf("**************************************************\n");
    printf("ȯ�ڸ���? ");
    fflush(stdin);
    fgets(m->patientName, sizeof(m->patientName), stdin);
    m->patientName[strlen(m->patientName) - 1] = '\0';

    do
    {
        if (check != 0)
            printf("�߸��Է��ϼ̽��ϴ�...���Ŀ� �°� ����� �Է��ϼ���!\n\n");

        printf("��� �������ڴ�(eg. 20230505(2023�� 5�� 5��))? ");
        fflush(stdin);
        fgets(m->date, sizeof(m->date), stdin);
        m->date[strlen(m->date) - 1] = '\0';
        check++;
    } while (strlen(m->date) != 8);

    check = 0;
    do
    {
        if (check != 0)
            printf("�߸��Է��ϼ̽��ϴ�...���Ŀ� �°� ����� �Է��ϼ���!\n\n");

        printf("���������(eg. 20230505(2023�� 5�� 5��))? ");
        fflush(stdin);
        fgets(m->birth, sizeof(m->birth), stdin);
        m->birth[strlen(m->birth) - 1] = '\0';
        check++;
    } while (strlen(m->birth) != 8);

    check = 0;
    do
    {
        if (check != 0)
            printf("�߸��Է��ϼ̽��ϴ�...���Ŀ� �°� ����� �Է��ϼ���!\n\n");

        fflush(stdin);
        printf("������(���� : F, ���� : M)? ");
        scanf("%c", &m->gender);
        check++;
    } while (m->gender != 'M' && m->gender != 'F');

    check = 0;
    do
    {
        if (check != 0)
            printf("�ش� ���� �������� �ʽ��ϴ�...���� �����ϴ� ���� �����ϼ���!\n\n");

        printf("\n[����� �ܰ� ����� ���� ����� �̺����İ� ����� �Ű�� ����� ����ΰ� ����� �Ҿư� ����� �Ȱ� �����]\n");
        printf("����������? ");
        fflush(stdin);
        fgets(m->medicDept, sizeof(m->medicDept), stdin);
        m->medicDept[strlen(m->medicDept) - 1] = '\0';
        check++;
    } while (strstr(m->medicDept, "�ܰ�") == NULL && strstr(m->medicDept, "����") == NULL && strstr(m->medicDept, "�̺����İ�") == NULL && strstr(m->medicDept, "�Ű��") == NULL && strstr(m->medicDept, "����ΰ�") == NULL && strstr(m->medicDept, "�Ҿư�") == NULL && strstr(m->medicDept, "�Ȱ�") == NULL);

    strcpy(m->prof, proflist(m->medicDept));

    printf("Ư�̻�����(���� ����)? ");
    fflush(stdin);
    fgets(m->memo, sizeof(m->memo), stdin);
    m->memo[strlen(m->memo) - 1] = '\0';

    return 1;
}
int deleteAppointment(medical **m, int cnt, int no)
{
    int dlt_ok;
    printf("������ �����Ͻðڽ��ϱ�(����:1 ���:0)? ");
    scanf("%d", &dlt_ok);
    if (dlt_ok != 1)
        return 0;

    int n = 0;
    for(int i = 0; i < cnt; i++) {
        if((m[i]) == NULL) continue;
        n++;
        if(n == no) {
            (m[i]) = NULL;
            free((m[i]));
        }
        
    }

    // if ((*m) == NULL)
    //     free((*m));
    // (*m) = NULL;

    return 1;
}
int selectAppointment(medical *m[], int cnt)
{
    int select;
    listAppointment(m, cnt);

    printf("��ȣ��(���:0)? ");
    scanf("%d", &select);

    return select;
}
void saveToFile(medical *m[], int cnt)
{
    FILE *fp;
    fp = fopen("medical.txt", "wt");
    for (int i = 0; i < cnt; i++)
    {
        if (m[i] == NULL)
            continue;
        fprintf(fp, "%s,%s,%s,%c %s,%s,%s\n", m[i]->patientName, m[i]->date, m[i]->birth, m[i]->gender, m[i]->medicDept, m[i]->prof, m[i]->memo);
    }
    fclose(fp);
    printf("=============����Ǿ����ϴ� ^0^=============\n");
}
int loadFile(medical *m[])
{
    FILE *fp;
    fp = fopen("medical.txt", "rt");
    char trash;
    int i = 0;
    if (fp == NULL)
    {
        printf("=> ���� ����!\n");
        return 0;
    }
    for (i = 0; i < 100; i++)
    {
        m[i] = (medical *)malloc(sizeof(medical));
        fscanf(fp, "%[^,]s", m[i]->patientName);
        if (feof(fp))
        {
            break;
        }

        fscanf(fp, "%c", &trash);
        fscanf(fp, "%[^,]s", m[i]->date);
        fscanf(fp, "%c", &trash);
        fscanf(fp, "%[^,]s", m[i]->birth);
        fscanf(fp, "%c", &trash);
        fscanf(fp, "%c", &m[i]->gender);
        fscanf(fp, "%c", &trash);
        fscanf(fp, "%[^,]s", m[i]->medicDept);
        fscanf(fp, "%c", &trash);
        fscanf(fp, "%[^,]s", m[i]->prof);
        fscanf(fp, "%c", &trash);
        fscanf(fp, "%[^\n]s", m[i]->memo);

        fscanf(fp, "%c", &trash);
    }
    fclose(fp);
    printf("=> �ε� ����!\n");

    return i;
}

int searchByPatient(medical *m[], int cnt, char Pname[], int menu_check)
{
    int no = 0;
    int scnt = 0;

    if (menu_check != 2)
    {
        printf("========================Make an medical appointment with H-medic========================\n");
        printf("========================================================================================\n");
        printf("No PatientName    date           birth      gender   medicDepartment      prof     memo          \n");
        printf("----------------------------------------------------------------------------------------\n");
    }
    for (int i = 0; i < cnt; i++)
    {
        if (m[i] == NULL)
            continue;
        
        if (menu_check == 2)
        {
            if (strcmp(m[i]->patientName, Pname) == 0)
                return -1;
        }
        else
        {
            if (strstr(m[i]->patientName, Pname))
            {
                no++;
                printf("%2d", no);
                readAppointment(*m[i]);
                scnt++;
            }
        }
    }

    if (scnt == 0)
    {
        if (menu_check != 2)
            printf("ã���ô� ���� ȯ�ڰ� �����ϴ�...\n");
        return 0;
    }
    return 1;
}
void searchByDate(medical *m[], int cnt)
{
    char date[10];
    int no = 0;
    while (1)
    {
        printf("ã�ƺ� ���� ��¥��? (eg. 20230505(2023�� 5�� 5��)) : ");
        scanf("%s", date);
        if (strlen(date) == 8)
            break;
        printf("�߸��Է��ϼ̽��ϴ�...���Ŀ� �°� ����� �Է��ϼ���!\n\n");
    }
    printf("========================================================================================\n");
    printf("No PatientName    date           birth      gender   medicDepartment      prof     memo          \n");
    printf("----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < cnt; i++)
    {
        if (m[i] == NULL)
            continue;
        if (strstr(m[i]->date, date))
        {
            no++;
            printf("%2d", no);
            readAppointment(*m[i]);
        }
    }
    if (no == 0)
        printf("ã���ô� ��¥�� ������ ������ �����ϴ�.\n");
}

void searchByDepartment(medical *m[], int cnt)
{
    char deptName[15];
    int i = 0, check = 0, print_count = 0;
    do
    {
        if (check != 0)
            printf("�ش� ���� �������� �ʽ��ϴ�...���� �����ϴ� ���� �����ϼ���!\n\n");

        printf("\n[����� �ܰ� ����� ���� ����� �̺����İ� ����� �Ű�� ����� ����ΰ� ����� �Ҿư� ����� �Ȱ� �����]\n");
        printf("���� ������ �˻��ϰ� ���� �������? ");
        fflush(stdin);
        fgets(deptName, sizeof(deptName), stdin);
        deptName[strlen(deptName) - 1] = '\0';
        check++;
    } while (strstr(deptName, "�ܰ�") == NULL && strstr(deptName, "����") == NULL && strstr(deptName, "�̺����İ�") == NULL && strstr(deptName, "�Ű��") == NULL && strstr(deptName, "����ΰ�") == NULL && strstr(deptName, "�Ҿư�") == NULL && strstr(deptName, "�Ȱ�") == NULL);

    printf("\n\n�˻��� ��û�Ͻ� ������� '%s'�Դϴ�!\n\n", deptName);

    printf("========================Make an medical appointment with H-medic========================\n");
    printf("========================================================================================\n");
    printf("No PatientName    date           birth      gender   medicDepartment      prof     memo          \n");
    printf("----------------------------------------------------------------------------------------\n");
    for (i = 0; i < cnt; i++)
    {
        if (m[i] == NULL)
            continue;
        if (strstr(m[i]->medicDept, deptName))
        {

            printf("%d", print_count + 1);
            readAppointment(*m[i]);
            print_count++;
        }
    }
    if (print_count == 0)
    {
        printf(">>>>>> ���� '%s'�� ���� ������ �����ϴ�!\n", deptName);
    }
}
void searchByProf(medical *m[], int cnt)
{
    char prof[15] = "find";
    int no = 0;

    strcpy(prof, proflist(prof));

    printf("========================================================================================\n");
    printf("No PatientName    date           birth      gender   medicDepartment      prof     memo          \n");
    printf("----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < cnt; i++)
    {
        if (m[i] == NULL)
            continue;
        if (strcmp(m[i]->prof, prof) == 0)
        {
            no++;
            printf("%2d", no);
            readAppointment(*m[i]);
        }
    }
    if (no == 0)
        printf(">>>>>> �ش� �������� ���� ������ �����ϴ�.\n");
}