#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "medic.h"
#include "menu.h"
int main()
{
    medical *m1[100];
    int menu = 0;
    int cnt = 0, ind = 0, dup_check = 0, no = 0;
    char name[15];
    cnt += loadFile(m1);
    ind = cnt;
    if (cnt != 0)
        listAppointment(m1, cnt);
    while (1)
    {
        menu = selectMenu();

        if (cnt == 0 && (menu == 1 || menu == 3 || menu == 4 || menu == 5 || menu == 6 || menu == 7 || menu == 8 || menu == 9))
        {
            printf("����� �����Ͱ� �����ϴ�...�ٽ� �Է��ϼ���!\n\n");
            continue;
        }
        if (menu == 1)
        {
            listAppointment(m1, cnt);
        }
        else if (menu == 2)
        {
            printf("**************************************************\n");
            printf("ȯ�ڸ���? ");
            fflush(stdin);
            fgets(name, sizeof(name), stdin);
            name[strlen(name) - 1] = '\0';
            dup_check = searchByPatient(m1, cnt, name, menu);

            if (dup_check == -1)
            {
                printf("�̹� ������ �����մϴ�...'���� ����'�� �̿����ּ���! \n\n");
                continue;
            }
            m1[ind] = (medical *)malloc(sizeof(medical));
            strcpy(m1[ind]->patientName, name);
            cnt += addAppointment(m1[ind++]);
        }
        else if (menu == 3)
        {
            int udt_ck;
            no = selectAppointment(m1, cnt);
            if (no == 0)
            {
                printf("=> ��ҵ�!\n");
                continue;
            }
            udt_ck = updateAppointment(m1[no - 1]);
            if (udt_ck == 1)
                printf("=> ������!\n");
        }
        else if (menu == 4)
        {
            int dlt_ck;
            no = selectAppointment(m1, cnt);
            if (no == 0)
            {
                printf("=> ��ҵ�!\n");
                continue;
            }
            dlt_ck = deleteAppointment(&m1[no - 1]);
            if (dlt_ck == 1)
            {
                printf("=> ������!\n");
            }
            else
            {
                printf("=> ��ҵ�!\n");
            }
        }
        else if (menu == 5)
        {
            saveToFile(m1, cnt);
        }
        else if (menu == 6)
        {
            listAppointment(m1, cnt);
            int search;
            printf("�˻��ϰ� ���� ���� ȯ�ڸ���? ");
            fflush(stdin);
            fgets(name, sizeof(name), stdin);
            name[strlen(name) - 1] = '\0';
            search = searchByPatient(m1, cnt, name, menu);
            if (search == 1)
                printf("\n=> �˻� �Ϸ�\n");
        }
        else if (menu == 7)
        {
            listAppointment(m1, cnt);
            searchByDate(m1, cnt);
        }
        else if (menu == 8)
        {
            searchByDepartment(m1, cnt);
        }
        else if (menu == 9)
        {
            searchByProf(m1, cnt);
        }
        else if (menu == 0)
            break;
        else
        {
            printf("�߸� �Է��ϼ̽��ϴ�...�ٽ� �Է��ϼ���!\n\n");
            continue;
        }
        printf("\n");
    }
}