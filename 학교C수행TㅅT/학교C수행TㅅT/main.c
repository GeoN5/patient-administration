#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct STRUCT {
	char name[10];//환자이름
	char gender[6];//환자성
	char disease[20];//환자질병
}sick;

void gotoxy(int x, int y);//커서 xy함수
void show(void);//로딩함수
void frame(void);//틀함수
void useradd(sick *arr, int *count); //환자 등록함수
void userchange(sick *arr,int *count); //환자 정보수정함수
void usersearch(); //환자 검색함수
void userlist(sick *arr, int *count); //환자리스트함수
void userdelete(); //환자정보지우기함수
void usercount(int *count);//누적환자수함수
void removeCursor(void);//커서 삭제함수

void main()
{
	removeCursor();
	system("mode con cols=120 lines=40");

	sick arr[30];
	int count = 0;
	int choose = 0;

	while (1) {
		show();//로딩함수
		scanf("%d", &choose);
		gotoxy(56, 22);
		switch (choose)
		{
		case 1:
			system("cls");
			useradd(&arr, &count);
			break;
		case 2:
			system("cls");
			userchange(&arr, &count);
			break;
		case 3:
			system("cls");
			usersearch(&arr,&count);
			break;
		case 4:
			system("cls");
			userlist(&arr,&count);
			break;
		case 5:
			system("cls");
			userdelete(&arr,&count);
			break;
		case 6:
			system("cls");
			usercount(&count);
			break;
		case 7:
			gotoxy(56, 22);
			printf("다음에 또 이용해주세요^^\n");
			gotoxy(50, 24);
			Sleep(1000);
			return 0;
		default:
			printf("다시 입력해 주세여");
			Sleep(100);
			system("cls");
		}
	}
	system("pause>null");
}

void gotoxy(int x, int y)//커서 xy함수
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void show(void)//처음 로딩화면함수
{
	system("cls");
	int i;
	gotoxy(50, 3);
	printf("<환자 관리 프로그램>");
	gotoxy(47, 5);
	printf("!끄면 환자정보가 사라져요!");
	gotoxy(20, 8);
	printf("1. 환자 정보 등록하기(추가)");
	gotoxy(20, 10);
	printf("2. 환자 정보 수정하기(수정)");
	gotoxy(20, 12);
	printf("3. 환자 정보 보기(검색)");
	gotoxy(20, 14);
	printf("4. 환자 목록 보기");
	gotoxy(20, 16);
	printf("5. 환자 정보 지우기(삭제)");
	gotoxy(20, 18);
	printf("6. 누적 환자수 확인하기");
	gotoxy(20, 20);
	printf("7. 프로그램 종료");
	gotoxy(50, 22);
	printf("선택 : ");

	for (i = 0; i <= 30; i++) { //세로
		gotoxy(15, i);
		Sleep(1);
		printf("*");
		gotoxy(105, i);
		Sleep(1);
		printf("*");
	}
	for (i = 15; i <= 105; i++) {//가로
		gotoxy(i, 0);
		Sleep(1);
		printf("*");
		gotoxy(i,30);
		Sleep(1);
		printf("*\n");
	}
	gotoxy(56, 22);//선택 커서위치
}

void frame(void)//틀
{
	int i;
	for (i = 0; i <= 30; i++) { //세로
		gotoxy(15, i);
		printf("*");
		gotoxy(105, i);
		printf("*");
	}
	for (i = 15; i <= 105; i++) {//가로
		gotoxy(i, 0);
		printf("*");
		gotoxy(i, 30);
		printf("*\n");
	}
}

void useradd(sick *arr, int * count)//환자 추가
{
	char ch;
	frame();
	gotoxy(50, 4);
	printf("<환자 정보 등록하기>");
	gotoxy(46, 6);
	printf("환자의 정보를 입력해주세요!");
	gotoxy(44, 8);
	printf("되도록이면 띄어쓰기로 구분해줘요ㅠ");
	gotoxy(20, 12);
	printf("이름 , 성별 , 질병 : ");
	scanf("%s %s %s", arr[*count].name, arr[*count].gender,arr[*count].disease);
	gotoxy(20, 14);
	printf("추가된 환자정보\n");
	gotoxy(20, 16);
	printf("이름: %3s , 성별: %3s , 질병: %3s", arr[*count].name, arr[*count].gender,arr[*count].disease);
	gotoxy(20, 20);
	printf("환자 정보등록이 완료되었습니다.");
	++*count;
	gotoxy(55, 25);
	printf("뒤로가기[ESC]");
	ch=getch();
	if (ch == 27) {
		show();
	}
}

void userchange(sick *arr,int *count)//환자 정보 수정
{
	char name[8], ch;
	int index = 0;
	frame();
	gotoxy(50, 4);
	printf("<환자 정보 수정하기>");
	gotoxy(20, 8);
	printf("수정할 환자의 이름을 입력해주세요: ");
	scanf("%s", name);
	for (index = 0; index < *count; index++) {
		if (strcmp(name, arr[index].name) == 0) {
			break;
		}
	}
	if (index != *count) {//for문의 구조땜에 count와 같지 않을때에 실행
		gotoxy(20, 12);
		printf("검색한 환자의 현재 정보:");
		gotoxy(40, 14);
		printf("이름 : %5s  성별 : %5s  질병 : %5s", arr[index].name, arr[index].gender,arr[index].disease);
		gotoxy(20, 16);
		printf("변경할 환자 정보 입력(이름 , 성별 , 질병) : ");
		gotoxy(40, 18);
		scanf("%s %s %s", arr[index].name, arr[index].gender, arr[index].disease);
		gotoxy(20, 20);
		printf("변경된 환자의 정보: ");
		gotoxy(40, 22);
		printf("이름 : %5s  성별 : %5s  질병 : %5s", arr[index].name, arr[index].gender, arr[index].disease);
	}
	else {
		gotoxy(47, 17);
		printf("수정하실 환자의 이름이 없습니다.");
	}
	gotoxy(55, 25);
	printf("뒤로가기[ESC]");
	ch = getch();
	if (ch == 27) {
		show();
	}
}

void usersearch(sick *arr,int *count)//환자 검색
{
	char name[8],ch;
	int index = 0;
	frame();
	gotoxy(50, 4);
	printf("<환자 정보 검색하기>");
	gotoxy(20, 8);
	printf("검색할 환자의 이름을 입력해주세요: ");
	scanf("%s", name);
	for (index = 0; index < *count; index++) {
		if (strcmp(name, arr[index].name) == 0) {
			break;
		}
	}
	if (index != *count) {
		gotoxy(20, 15);
		printf("검색한 환자의 정보:");
		gotoxy(40, 17);
		printf("이름 : %5s \t성별 : %5s \t질병 : %5s", arr[index].name, arr[index].gender, arr[index].disease);
	}
	else {
		gotoxy(49, 17);
		printf("검색된 환자가 없습니다.");
	}
	gotoxy(55, 25);
	printf("뒤로가기[ESC]");
	ch = getch();
	if (ch == 27) {
		show();
	}
}

void userlist(sick *arr, int *count)//환자 목록
{
	int index=0,y=8,i=1;
	char ch;
	frame();
	gotoxy(52, 4);
	printf("<환자 리스트보기>");
	gotoxy(51, 6);
	printf("추가된 환자 리스트");
	for (index = 0; index < *count; index++) {
		gotoxy(27, y);
		printf("%d번째 환자 : %s",i,arr[index].name);
		y++;
		i++;
	}
	gotoxy(55, 25);
	printf("뒤로가기[ESC]");
	ch = getch();
	if (ch == 27) {
		show();
	}
}

void userdelete(sick *arr,int *count)//환자 정보 삭제
{
	char name[8], ch1, ch2;
	int index;
	frame();
	gotoxy(50, 4);
	printf("<환자 정보 삭제하기>");
	gotoxy(42, 8);
	printf("1. 1명 삭제\t\t2. 전체 삭제");
	gotoxy(51, 12);
	printf("선택 : ");
	gotoxy(57, 12);
	scanf("%c", &ch1);
	again:
	ch1 = getch();
	if (ch1 == 49) {//1
		gotoxy(42, 16);
		printf("삭제할 환자의 이름을 입력해주세요: ");
		scanf("%s", name);
		for (index = 0; index < *count; index++) {
			if (strcmp(name, arr[index].name) == 0) {
				break;
			}
		}
		if (index != *count) {
			arr[index].name[0] = '\0';
			arr[index].gender[0] = '\0';
			arr[index].disease[0] = '\0';
			gotoxy(47, 20);
			printf("%s환자의 정보가 삭제되었습니다.",name);
			gotoxy(47, 22);
			printf("환자 리스트를 확인해보세요!");
		}
		else {
			gotoxy(47, 20);
			printf("입력하신 환자가 없습니다.");
		}
	}
	else if (ch1 == 50) {//1
		for (index = 0; index < *count; index++) {
			arr[index].name[0] = '\0';
			arr[index].gender[0] = '\0';
			arr[index].disease[0] = '\0';
			gotoxy(47, 20);
			printf("모든 환자의 정보가 삭제되었습니다.");
			gotoxy(47, 22);
			printf("환자 리스트를 확인해보세요!");
		}
	}
	else {//default
		gotoxy(57, 12);
		printf("다시 입력해주세요");
		Sleep(500);
		goto again;
	}
	gotoxy(55, 25);
	printf("뒤로가기[ESC]");
	ch2 = getch();
	if (ch2 == 27) {
		show();
	}
}

void usercount(int *count)//환자누적함수
{
	char ch2;
	frame();
	gotoxy(50, 4);
	printf("<누적 환자 수 확인하기>");
	gotoxy(50, 15);
	printf("오늘의 누적 환자 : %d명", *count);
	gotoxy(55, 25);
	printf("뒤로가기[ESC]");
	ch2 = getch();
	if (ch2 == 27) {
		show();
	}
}

void removeCursor(void)//커서삭제
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}