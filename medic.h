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