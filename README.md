<div align="center">
<h1><b>H-medic : Medical Appointment system</b></h1>
<p align="center"><img src="https://user-images.githubusercontent.com/126576242/236667615-241d0d4c-c3d8-43c2-b798-d49e5f2f970b.png" height="300px" width="300px"></p>
  
### :hospital: Experience a convenient medical appointment system!
<br/>
<img src="https://img.shields.io/badge/HTML-E34F26?style=flat&logo=HTML5&logoColor=white"/>
<img src="https://img.shields.io/badge/C-00CCFF?style=flat&logo=C&logoColor=white"/>
<img src="https://img.shields.io/badge/VisualStudioCode-0000FF?style=flat-square&logo=VisualStudioCode&logoColor="black"/>
<img src="https://img.shields.io/badge/Markdown-000000?style=flat-square&logo=Markdown&logoColor="white"/>

</div>

## :rocket:H-medic�� ���� �Ұ� �� ��� ����
### Medical Appointment System
:point_right:<b> �پ��� ������� ������ �����ϴ� ���� ������ ���� ������ �������ִ� �ý����Դϴ�. ���� ����, ����, ��Ҵ� �����̸�,
  
   ���������� �� ���ϰ� ���� ������ ������ �� �ֵ��� ������, ���ں�, ������� ���� ��Ȳ���� �� �� �ֽ��ϴ�. </b>
  
  <br/>
  <b> �����: �ܰ�, ����, �̺����İ�, �Ű��, ����ΰ�, �Ҿư�, �Ȱ� </b>
    
    ? ���ϴ� �����, ���ϴ� ������ ��¥���� �����Ͽ� �����غ�����~ ?
                                                
 
<br/>
  
  
## :rocket:H-Medic CRUD & Function
### �ڵ� �� ���
```c
typedef struct{
    char patientName[15]; //(������)ȯ�� �̸�
    char date[10]; //���� ��¥
    char birth[10];// �������
    char gender; //����
    char medicDept[15]; //����ϴ� �����
    char prof[15]; //����ϴ� ����
    char memo[50]; //Ư�� ����
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
 
```
<br/>

## :rocket: ���� ȯ�� �� ���
:fire: <b> C��� </b>

:fire: <b> Visual Studio Code </b>

:fire: <b> Github </b>

  
<br/>  

## :rocket: ���� �Ұ� �� ����
### Member
####  :boy: �ڿ��� :star: github �ּ�: [�ڿ����� github](https://github.com/Wonjin-david)
####  :girl: ������ :star: github �ּ�: [�������� github](https://github.com/jeeyunryu)
<table>
  <tr>
    <td style = "width: 50%;">
      <img src="https://user-images.githubusercontent.com/126576242/236665332-2f80adb4-9b32-4a7e-bc93-aca8e4597df4.png" style = "width : 21vw"/>
    </td>
    <td style = "width: 50%;">
      <img src="https://user-images.githubusercontent.com/126576242/236810422-d0818d37-7fc5-4614-9f10-36968ffcc40b.jpg" style = "width : 20vw"/>
    </td>
  </tr>
  <tr>
    <td><b> �ڿ��� </b></td>
    <td><b> ������ </b></td>
  </tr>
  <tr>
    <td><b> �ѵ����б� 20�й� �����ȭ </b></td>
    <td><b> �ѵ����б� 20�й� �����ȭ </b></td>
  </tr>
  <tr>
    <td>
      <b>:bell:����</b><br>
      - CRUD �� add,read <br>
      - File io ����<br>
      - searchByDepartment, searchByProf ����<br>
      - README.md �ַ� ����Ͽ� ����<br>
      <br>
    </td>
    <td>
      <b>:bell:����</b><br>
      - CRUD �� update, delete<br>
      - main, menu ����<br>
      - searchByPatient, searchByDate ����<br>
      - Wiki �ַ� ����Ͽ� ����<br>
      <br>
    </td>
  </tr>
</table>

