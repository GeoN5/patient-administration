#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

typedef struct STRUCT {
	char name[10];//ȯ���̸�
	char gender[6];//ȯ�ڼ�
	char disease[20];//ȯ������
}sick;

void gotoxy(int x, int y);//Ŀ�� xy�Լ�
void show(void);//�ε��Լ�
void frame(void);//Ʋ�Լ�
void useradd(sick *arr, int *count); //ȯ�� ����Լ�
void userchange(sick *arr,int *count); //ȯ�� ���������Լ�
void usersearch(); //ȯ�� �˻��Լ�
void userlist(sick *arr, int *count); //ȯ�ڸ���Ʈ�Լ�
void userdelete(); //ȯ������������Լ�
void usercount(int *count);//����ȯ�ڼ��Լ�
void removeCursor(void);//Ŀ�� �����Լ�

void main()
{
	removeCursor();
	system("mode con cols=120 lines=40");

	sick arr[30];
	int count = 0;
	int choose = 0;

	while (1) {
		show();//�ε��Լ�
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
			printf("������ �� �̿����ּ���^^\n");
			gotoxy(50, 24);
			Sleep(1000);
			return 0;
		default:
			printf("�ٽ� �Է��� �ּ���");
			Sleep(100);
			system("cls");
		}
	}
	system("pause>null");
}

void gotoxy(int x, int y)//Ŀ�� xy�Լ�
{
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void show(void)//ó�� �ε�ȭ���Լ�
{
	system("cls");
	int i;
	gotoxy(50, 3);
	printf("<ȯ�� ���� ���α׷�>");
	gotoxy(47, 5);
	printf("!���� ȯ�������� �������!");
	gotoxy(20, 8);
	printf("1. ȯ�� ���� ����ϱ�(�߰�)");
	gotoxy(20, 10);
	printf("2. ȯ�� ���� �����ϱ�(����)");
	gotoxy(20, 12);
	printf("3. ȯ�� ���� ����(�˻�)");
	gotoxy(20, 14);
	printf("4. ȯ�� ��� ����");
	gotoxy(20, 16);
	printf("5. ȯ�� ���� �����(����)");
	gotoxy(20, 18);
	printf("6. ���� ȯ�ڼ� Ȯ���ϱ�");
	gotoxy(20, 20);
	printf("7. ���α׷� ����");
	gotoxy(50, 22);
	printf("���� : ");

	for (i = 0; i <= 30; i++) { //����
		gotoxy(15, i);
		Sleep(1);
		printf("*");
		gotoxy(105, i);
		Sleep(1);
		printf("*");
	}
	for (i = 15; i <= 105; i++) {//����
		gotoxy(i, 0);
		Sleep(1);
		printf("*");
		gotoxy(i,30);
		Sleep(1);
		printf("*\n");
	}
	gotoxy(56, 22);//���� Ŀ����ġ
}

void frame(void)//Ʋ
{
	int i;
	for (i = 0; i <= 30; i++) { //����
		gotoxy(15, i);
		printf("*");
		gotoxy(105, i);
		printf("*");
	}
	for (i = 15; i <= 105; i++) {//����
		gotoxy(i, 0);
		printf("*");
		gotoxy(i, 30);
		printf("*\n");
	}
}

void useradd(sick *arr, int * count)//ȯ�� �߰�
{
	char ch;
	frame();
	gotoxy(50, 4);
	printf("<ȯ�� ���� ����ϱ�>");
	gotoxy(46, 6);
	printf("ȯ���� ������ �Է����ּ���!");
	gotoxy(44, 8);
	printf("�ǵ����̸� ����� ����������");
	gotoxy(20, 12);
	printf("�̸� , ���� , ���� : ");
	scanf("%s %s %s", arr[*count].name, arr[*count].gender,arr[*count].disease);
	gotoxy(20, 14);
	printf("�߰��� ȯ������\n");
	gotoxy(20, 16);
	printf("�̸�: %3s , ����: %3s , ����: %3s", arr[*count].name, arr[*count].gender,arr[*count].disease);
	gotoxy(20, 20);
	printf("ȯ�� ��������� �Ϸ�Ǿ����ϴ�.");
	++*count;
	gotoxy(55, 25);
	printf("�ڷΰ���[ESC]");
	ch=getch();
	if (ch == 27) {
		show();
	}
}

void userchange(sick *arr,int *count)//ȯ�� ���� ����
{
	char name[8], ch;
	int index = 0;
	frame();
	gotoxy(50, 4);
	printf("<ȯ�� ���� �����ϱ�>");
	gotoxy(20, 8);
	printf("������ ȯ���� �̸��� �Է����ּ���: ");
	scanf("%s", name);
	for (index = 0; index < *count; index++) {
		if (strcmp(name, arr[index].name) == 0) {
			break;
		}
	}
	if (index != *count) {//for���� �������� count�� ���� �������� ����
		gotoxy(20, 12);
		printf("�˻��� ȯ���� ���� ����:");
		gotoxy(40, 14);
		printf("�̸� : %5s  ���� : %5s  ���� : %5s", arr[index].name, arr[index].gender,arr[index].disease);
		gotoxy(20, 16);
		printf("������ ȯ�� ���� �Է�(�̸� , ���� , ����) : ");
		gotoxy(40, 18);
		scanf("%s %s %s", arr[index].name, arr[index].gender, arr[index].disease);
		gotoxy(20, 20);
		printf("����� ȯ���� ����: ");
		gotoxy(40, 22);
		printf("�̸� : %5s  ���� : %5s  ���� : %5s", arr[index].name, arr[index].gender, arr[index].disease);
	}
	else {
		gotoxy(47, 17);
		printf("�����Ͻ� ȯ���� �̸��� �����ϴ�.");
	}
	gotoxy(55, 25);
	printf("�ڷΰ���[ESC]");
	ch = getch();
	if (ch == 27) {
		show();
	}
}

void usersearch(sick *arr,int *count)//ȯ�� �˻�
{
	char name[8],ch;
	int index = 0;
	frame();
	gotoxy(50, 4);
	printf("<ȯ�� ���� �˻��ϱ�>");
	gotoxy(20, 8);
	printf("�˻��� ȯ���� �̸��� �Է����ּ���: ");
	scanf("%s", name);
	for (index = 0; index < *count; index++) {
		if (strcmp(name, arr[index].name) == 0) {
			break;
		}
	}
	if (index != *count) {
		gotoxy(20, 15);
		printf("�˻��� ȯ���� ����:");
		gotoxy(40, 17);
		printf("�̸� : %5s \t���� : %5s \t���� : %5s", arr[index].name, arr[index].gender, arr[index].disease);
	}
	else {
		gotoxy(49, 17);
		printf("�˻��� ȯ�ڰ� �����ϴ�.");
	}
	gotoxy(55, 25);
	printf("�ڷΰ���[ESC]");
	ch = getch();
	if (ch == 27) {
		show();
	}
}

void userlist(sick *arr, int *count)//ȯ�� ���
{
	int index=0,y=8,i=1;
	char ch;
	frame();
	gotoxy(52, 4);
	printf("<ȯ�� ����Ʈ����>");
	gotoxy(51, 6);
	printf("�߰��� ȯ�� ����Ʈ");
	for (index = 0; index < *count; index++) {
		gotoxy(27, y);
		printf("%d��° ȯ�� : %s",i,arr[index].name);
		y++;
		i++;
	}
	gotoxy(55, 25);
	printf("�ڷΰ���[ESC]");
	ch = getch();
	if (ch == 27) {
		show();
	}
}

void userdelete(sick *arr,int *count)//ȯ�� ���� ����
{
	char name[8], ch1, ch2;
	int index;
	frame();
	gotoxy(50, 4);
	printf("<ȯ�� ���� �����ϱ�>");
	gotoxy(42, 8);
	printf("1. 1�� ����\t\t2. ��ü ����");
	gotoxy(51, 12);
	printf("���� : ");
	gotoxy(57, 12);
	scanf("%c", &ch1);
	again:
	ch1 = getch();
	if (ch1 == 49) {//1
		gotoxy(42, 16);
		printf("������ ȯ���� �̸��� �Է����ּ���: ");
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
			printf("%sȯ���� ������ �����Ǿ����ϴ�.",name);
			gotoxy(47, 22);
			printf("ȯ�� ����Ʈ�� Ȯ���غ�����!");
		}
		else {
			gotoxy(47, 20);
			printf("�Է��Ͻ� ȯ�ڰ� �����ϴ�.");
		}
	}
	else if (ch1 == 50) {//1
		for (index = 0; index < *count; index++) {
			arr[index].name[0] = '\0';
			arr[index].gender[0] = '\0';
			arr[index].disease[0] = '\0';
			gotoxy(47, 20);
			printf("��� ȯ���� ������ �����Ǿ����ϴ�.");
			gotoxy(47, 22);
			printf("ȯ�� ����Ʈ�� Ȯ���غ�����!");
		}
	}
	else {//default
		gotoxy(57, 12);
		printf("�ٽ� �Է����ּ���");
		Sleep(500);
		goto again;
	}
	gotoxy(55, 25);
	printf("�ڷΰ���[ESC]");
	ch2 = getch();
	if (ch2 == 27) {
		show();
	}
}

void usercount(int *count)//ȯ�ڴ����Լ�
{
	char ch2;
	frame();
	gotoxy(50, 4);
	printf("<���� ȯ�� �� Ȯ���ϱ�>");
	gotoxy(50, 15);
	printf("������ ���� ȯ�� : %d��", *count);
	gotoxy(55, 25);
	printf("�ڷΰ���[ESC]");
	ch2 = getch();
	if (ch2 == 27) {
		show();
	}
}

void removeCursor(void)//Ŀ������
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}