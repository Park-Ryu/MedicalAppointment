<div align="center">
<h1>Medical Appointment system</h1>
<p align="center"><img src="https://user-images.githubusercontent.com/126576242/236667615-241d0d4c-c3d8-43c2-b798-d49e5f2f970b.png" height="300px" width="300px"></p>
  
### ? Experience a convenient medical appointment system!
<br/>
<img src="https://img.shields.io/badge/HTML-E34F26?style=flat&logo=HTML5&logoColor=white"/>
<img src="https://img.shields.io/badge/C-00CCFF?style=flat&logo=C&logoColor=white"/>
<img src="https://img.shields.io/badge/VisualStudioCode-0000FF?style=flat-square&logo=VisualStudioCode&logoColor="black"/>
<img src="https://img.shields.io/badge/Markdown-000000?style=flat-square&logo=Markdown&logoColor="white"/>

</div>

## ?H-medic에 대한 설명
### Medical Appointment System
?<b> 다양한 진료과와 교수가 존재하는 종합 병원의 진료 예약을 관리해주는 시스템입니다. 진료 예약, 수정, 취소는 물론이며,
  
   병원에서도 더 편리하게 진료 예약을 관리할 수 있도록 교수별, 일자별, 진료과별 예약 현황까지 알 수 있습니다.
 
<br/>

## ?H-Medic CRUD & Function
### 코드 및 기능
```c
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
 
```
<br/>
  
## ? 팀원 소개 및 역할
### Member
####  ? 박원진 ?github 주소: https://github.com/Wonjin-david
####  ? 류지연 ?github 주소: https://github.com/jeeyunryu
<table>
  <tr>
    <td style = "width: 50%;">
      <img src="https://user-images.githubusercontent.com/126576242/236665332-2f80adb4-9b32-4a7e-bc93-aca8e4597df4.png" style = "width : 20vw"/>
    </td>
    <td style = "width: 50%;">
      <img src="https://user-images.githubusercontent.com/68150327/236711722-93e72af3-cfe7-4390-b30f-a77bc7c388b1.jpg" style = "width : 20vw"/>
    </td>
  </tr>
  <tr>
    <td><b> 박원진 </b></td>
    <td><b> 류지연 </b></td>
  </tr>
  <tr>
    <td><b> 한동대학교 20학번 전산심화 </b></td>
    <td><b> 한동대학교 20학번 전산심화 </b></td>
  </tr>
  <tr>
    <td>
      역할1<br>
      역할1<br>
      역할1<br>
      역할1<br>
    </td>
    <td>
      역할1<br>
      역할1<br>
      역할1<br>
      역할1<br>
    </td>
  </tr>
</table>

