// TX6.cpp : Defines the entry point for the console application.
//


/*��������������������������������������������������������������������������������������������������������������������*/
/*                                                        ͷ�ļ�                                                      */
/*��������������������������������������������������������������������������������������������������������������������*/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "stdlib.h"
#include <time.h>
#include "Logolib.cpp"
#include "LogoFlash.cpp"

/*��������������������������������������������������������������������������������������������������������������������*/
/*                                                       ��������                                                     */
/*��������������������������������������������������������������������������������������������������������������������*/

void LoginInterface();//LoginInterfave()��������
void LoginInt2();//
void BookIn();
//Logo����
void LogoOops();
void LogoGo(int flag);
void LogoRegist();
void LogoLogin();
void LogoVisitor();
void LogoAdmin();
void LogoUser();
void LogoBookIn();
void LogoBookOut();
void LogoBookSearch();
void LogoUserSearch();
void LogoBookBorrow();
//
void BookLend();
void BookSearch();
void Timenow();
void BookBorrowBottom(int number);
void UserSearch();
void BookInfIn();
void UserInformationIn();
void IfLate();
void BookInfOut();
void BookOut();
void BookAdjust();
void AdminBookSearch();
void SearchInterface();
int TimeCheck(int Usercode);
void LogoBookReturn();
void BookReturn();
void AdminBkSchInt1();
void AdminBkSchInt2();
void Initialize(char *str);
void UserLogin();
void HistoryPrint();
void HistoryWrite();
/*��������������������������������������������������������������������������������������������������������������������*/
/*                                                          �ṹ��                                                    */
/*��������������������������������������������������������������������������������������������������������������������*/

struct history
{
	char name[40];
	int year;
	int month;
	int day;
	int hour;
	int min;
	char bookname[40];
	char booknumber[10];
	char inorout[5];
	char late;
	char phone[20];
}history[1000];

struct times
{
	int year;
	int month;
	int day;
	int hour;
	int min;
	int days;
} nowtime, future;
struct booklend
{
	struct times outtime;
	char bookname[40];
	char booknumber[40];
	struct times shouldback;

}book[3];

struct allbook//������
{
	char bookname[40];
	char booknumber[10];
	char booktype[10];
	char who[20];
	struct times outtime;
	struct times shouldback;
	char inshelf;
	char late;
	char author[40];
	char press[40];

}allbook[1000];

struct xinxi//��ͨ�û��˺�
{
	char name[20];
	char password[20];
	char phone[20];
	struct booklend book[3];
	int borrowingbook;

}xinxi[100];

struct administrator//����Ա�˺�
{
	char name[20];
	char password[20];
}
administrator = { {"1"},{"1"} };

/*��������������������������������������������������������������������������������������������������������������������*/
/*                                                       ȫ�ֱ���                                                     */
/*��������������������������������������������������������������������������������������������������������������������*/

static int UserNum = 0;//�û�����ȫ�ֱ���
static int BookNum = 0;//�鼮��Ŀȫ�ֱ���
static char GetOptSTR[1000];//�ж��û�����ר���ַ���
static int TAG = 0;//�ص���ǩ���û�=1������Ա=2���ο�=3��
static int Usercode;//������¼���û������
static int hisnum=0;//ȫ����ʷ��¼����

/*��������������������������������������������������������������������������������������������������������������������*/
/*                                                         UI���                                                     */
/*��������������������������������������������������������������������������������������������������������������������*/
void LoginIntUI()//��ʼ����
{
	printf("\t\t\t\t\t\t\t\t\t\t    ����ǰ���ʵ���:������\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t   ��ӭʹ��TX6ͼ�����ϵͳ\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t1.�û�ע��\t   2.�û���¼ \n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.�˳�\n\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t��ѡ�����:");
}

void AdminOptUI()
{
	printf("\t\t\t\t\t\t\t\t\t\t����ǰ���ʵ���:����Աѡ�����\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.�鼮���\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2.�鼮����\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t3.�鼮��ʷ��¼\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t4.�鼮��Ϣ��ѯ\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t5.�鼮��Ϣ�޸�\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.�˳���¼\n\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t��ѡ�����:");
}

void UserOptUI()
{
	printf("\t\t\t\t\t\t\t\t\t\t����ǰ���ʵ���:��ͨ�û�ѡ�����\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.�鼮��ѯ\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2.�鼮����\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t3.�鼮�黹\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t4.������Ϣ��ѯ\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.�˳���¼\n\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t��ѡ�����:");
}

void VisitorLogUI()
{
	printf("\t\t\t\t\t\t\t\t\t\t ����ǰ���ʵ���:�ο͵�¼����\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.�鼮��ѯ\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.���� \n\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t��ѡ�����:");
}

void LoginInt2UI()
{
	printf("\t\t\t\t\t\t\t\t\t\t  ����ǰ���ʵ���:��¼����\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.��ͨ�û���¼\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2.����Ա��¼\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t3.�ο͵�¼\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.����\n\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t��ѡ�����:");
}

void SearchIntUI()
{
	printf("\t\t\t\t\t\t\t\t\t\t ����ǰ���ʵ���:�鼮��������\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.���Ʋ�ѯ\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2.�����ѯ\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t3.���߲�ѯ\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t4.�������ѯ\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.����\n\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t��ѡ�����:");
}


/*��������������������������������������������������������������������������������������������������������������������*/
/*                                                    �����ͺ���                                                      */
/*��������������������������������������������������������������������������������������������������������������������*/
int CheckString(char *str, char str1)
{
	int i = 0, k = 0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] == str1)
			break;
	}
	if (i == strlen(str))
		k = 0;
	else
		k = 1;
	return k;
}


int LengthLimit(char *str, int low, int up)//�ַ������޶��������Ϸ���1�����Ϸ���0
{
	int k = 0;
	if (strlen(str) < low || strlen(str) > up)
		k = 1;
	else
		k = 0;
	return k;
}

void setCursorPosition(int x, int y)//�Զ���Ĺ�궨λ����
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color)//�Զ����������ɫ����
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void CoverPlus(char *question, char *require, char *str, int x, int y)//�����ڸǺ�����ǿ��
{
	int i = 0;
	char str1[30];
	do
	{
		str[i] = getch();
		if (str[i] == '\r' || i > 20)
			break;
		if (str[i] == '\b')
		{
			if (i <= 1)
			{
				setCursorPosition(x, y);
				printf("%s", question);
				setColor(8);
				printf("%s", require);
				setColor(15);
				setCursorPosition((x + strlen(question)), y);
				if (i == 0)
					continue;
			}
			else
			{
				str1[i - 1] = '\0';
				setCursorPosition(x, y);
				printf("%s%s", question, str1);
				printf("                                ");
				setCursorPosition((x + strlen(question) + i), y);
			}
			i--;
			printf("\b");
		}
		else
		{
			str1[i] = '*';
			str1[i + 1] = '\0';
			setCursorPosition(x, y);
			printf("%s%s", question, str1);
			printf("                                ");
			setCursorPosition((x + strlen(question) + i), y);
			i++;
		}
	} while (str[i] != '\n');
	str[i] = '\0';
	printf("\n");
}

void GetBookName(char *question,char *require,char *error,char *right,char *str,int x,int y,int num)
{
	int i=0;
	while (1)
	{
		i=0;
		setCursorPosition(x, y);
		printf("%s",question);
		setColor(8);
		printf("%s",require);
		setCursorPosition((x+strlen(question)), y);
		setColor(15);
		do
		{
			str[i] = getch();
			str[i + 1] = '\0';
			setCursorPosition(x, y);
			printf("%s%s",question, str);
			printf("                                  ");//���require
			setCursorPosition(((x+strlen(question)) + i), y);
			if (str[i] == '\r' || i > num)
					break;
			if (str[i] == '\b')
			{
				if (i <= 1)
				{
					setCursorPosition(x, y);
					printf("%s",question);
					setColor(8);
					printf("%s",require);
					setColor(15);
					setCursorPosition((x+strlen(question)), y);
					if (i == 0)
						continue;
				}
				i--;
				printf("\b");
			}
			else
				i++;
		} while (str[i] != '\n');
		str[i] = '\0';
		printf("\n");
		if (strlen(str) == 0 || i > num || CheckString(str, ' '))
		{
			printf("\n\t\t\t\t\t\t\t\t%s\n\n",error);
			Initialize(str);
		}
		else
		{
			printf("\n\t\t\t\t\t\t\t\t%s\n\n",right);
			break;
		}
	}//whileѭ������
}
void Tips(int flag)//��ʾ������0-ע��ɹ��� 1-��½�ɹ��� 2-�˺Ż�������� 3-�������������������� 
				   //4-��л����ʹ�ã� 5-������������벻һ�£��Ƿ��������:
{
	int i = 0;
	char tips[7][1000];
	strcpy(tips[0], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>!ע��ɹ�!<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[1], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>!��½�ɹ�!<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[2], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>!�˺Ż��������!<<<<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[3], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>!��������  ����������!<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[4], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>!δ��ѯ�������Ϣ!<<<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[5],	"\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>!��ͼ�鳬ʱδ�����޷���������!<<<<<<<<<<<<<<<\n");
	strcpy(tips[6], "��   л   ��   ��   ʹ   ��   !\n");
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n\n");
	switch (flag)
	{
	case 0:system("color 0A"); printf("%s\a", tips[0]); break;
	case 1:system("color 0A"); printf("%s\a", tips[1]); break;
	case 2:system("color 04"); printf("%s\a", tips[2]); break;
	case 3:system("color 04"); printf("%s\a", tips[3]); break;
	case 4:system("color 04"); printf("%s\a", tips[4]); break;
	case 5:system("color 04"); printf("%s\a", tips[5]); break;
	case 6:system("color 0F"); printf("\t\t\t\t\t\t\t\t\t\t");for (i = 0; i < strlen(tips[6]); i++) { printf("%c", tips[6][i]); Sleep(100); }break;
	}
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n"); Sleep(1000);
}

int CheckAlpha(char *str)//�鿴�Ƿ��з����֣��з���1
{
	int i = 0, k = 0;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i]<'0' || str[i]>'9')
		{
			k = 1;
			break;
		}
	}
	return k;
}

void Initialize(char *str)//�ַ������ʼ��
{
	int i = 0;
	for (i = 0; i < strlen(str); i++)
		str[i] = '\0';
}

char GetOption(char *str)//�û������ж�����
{
	char k;
	if (strlen(str) != 1)
		k = 'E';
	else
		k = str[0];
	return k;
	Initialize(GetOptSTR);
}

int CheckNumber(int str)//�û������Ƿ�Ϊ�����֣����ǽ���תΪ������
{
	int k = 0;
	gets(GetOptSTR);
	if (CheckAlpha(GetOptSTR))
		k = 1;
	else
	{
		str = atol(GetOptSTR);
		k = 0;
	}
	Initialize(GetOptSTR);
	return k;
}







/*��������������������������������������������������������������������������������������������������������������������*/
/*                                                    ��Ҫ����                                                        */
/*��������������������������������������������������������������������������������������������������������������������*/

void LoadInfor()/*�ⲿ�����ڰ�txt�ļ�����û���Ϣ¼�뵽���򻺴�֮�У����ڽ��������û�������Ƚϡ���Ҫ����ǰ��*/
{
	int year, month, day, hour, min;
	FILE*fp1;
	if ((fp1 = fopen("time.txt", "r")) != NULL)
	{
		fscanf(fp1, "%d %d %d %d %d", &year, &month, &day, &hour, &min);
		fclose(fp1);
		char fileName[256] = { 0 },ch;
		sprintf(fileName, "%d.%d.%d.%d.%duser.txt", year, month, day, hour, min);
		FILE*fp2;

			if ((fp2 = fopen(fileName, "a+")) == NULL)
			{
				printf("cannot open file\n");
				exit(0);
			}
			else{
				ch=fgetc(fp2);
				if(ch!=EOF)
				{	fp2 = fopen(fileName, "r");
				for (UserNum = 0; feof(fp2) == 0; UserNum++)//�û��ṹ����Ϣ�����ʽ������ ���� �绰 �ڽ��鼮���� ��һ����Ľ���� �� �� ʱ �� ���� ��� Ӧ�������� �ڶ��������� 
				{
					fscanf(fp2, "%s %s %s %d %d %d %d %d %d %d %s %s %d %d %d %d %d %d %d %d %d %d %d %d %s %s %d %d %d %d %d %d %d %d %d %d %d %d %s %s %d %d %d %d %d %d \n",
						&xinxi[UserNum].name, &xinxi[UserNum].password, &xinxi[UserNum].phone, &xinxi[UserNum].borrowingbook,
						&xinxi[UserNum].book[0].outtime.year, &xinxi[UserNum].book[0].outtime.month, &xinxi[UserNum].book[0].outtime.day,
						&xinxi[UserNum].book[0].outtime.hour, &xinxi[UserNum].book[0].outtime.min, &xinxi[UserNum].book[0].outtime.days,
						&xinxi[UserNum].book[0].bookname, &xinxi[UserNum].book[0].booknumber, &xinxi[UserNum].book[0].shouldback.year,
						&xinxi[UserNum].book[0].shouldback.month, &xinxi[UserNum].book[0].shouldback.day, &xinxi[UserNum].book[0].shouldback.hour,
						&xinxi[UserNum].book[0].shouldback.min, &xinxi[UserNum].book[0].shouldback.days,

						&xinxi[UserNum].book[1].outtime.year, &xinxi[UserNum].book[1].outtime.month, &xinxi[UserNum].book[1].outtime.day,
						&xinxi[UserNum].book[1].outtime.hour, &xinxi[UserNum].book[1].outtime.min, &xinxi[UserNum].book[1].outtime.days,
						&xinxi[UserNum].book[1].bookname, &xinxi[UserNum].book[1].booknumber, &xinxi[UserNum].book[1].shouldback.year,
						&xinxi[UserNum].book[1].shouldback.month, &xinxi[UserNum].book[1].shouldback.day, &xinxi[UserNum].book[1].shouldback.hour,
						&xinxi[UserNum].book[1].shouldback.min, &xinxi[UserNum].book[1].shouldback.days,

						&xinxi[UserNum].book[2].outtime.year, &xinxi[UserNum].book[2].outtime.month, &xinxi[UserNum].book[2].outtime.day,
						&xinxi[UserNum].book[2].outtime.hour, &xinxi[UserNum].book[2].outtime.min, &xinxi[UserNum].book[2].outtime.days,
						&xinxi[UserNum].book[2].bookname, &xinxi[UserNum].book[2].booknumber, &xinxi[UserNum].book[2].shouldback.year,
						&xinxi[UserNum].book[2].shouldback.month, &xinxi[UserNum].book[2].shouldback.day, &xinxi[UserNum].book[2].shouldback.hour,
						&xinxi[UserNum].book[2].shouldback.min, &xinxi[UserNum].book[2].shouldback.days);
				}
				}
				fclose(fp2);
		}
	
	}
}

void Registe() /*ע��*7.14����������*/
{

	FILE*fp;
	char checkpassword[30];
	int i = 0, flag = 0;
	system("cls"); 
	system("color 0f");
	LogoRegist();
	printf("\t\t\t\t\t\t\t\t\t\t  ����ǰ���ʵ���:ע�����\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n");
	setColor(15);
	printf("\t\t\t\t\t\t\t\t    ��1���û���->");
	setColor(8);
	printf("��2������->��3��ȷ������->��4���ֻ�����    \n\n");
	setColor(15);
	while (1)
	{
		setCursorPosition(64, 22);
		printf(">>�����������û���:");
		setColor(8);
		printf("���Ȳ�����20λ�ַ��Ҳ��ú��пո�");
		setCursorPosition(83, 22);
		setColor(15);
		do
		{
			xinxi[UserNum].name[i] = getch();
			xinxi[UserNum].name[i + 1] = '\0';
			setCursorPosition(64, 22);
			printf(">>�����������û���:%s", xinxi[UserNum].name);
			printf("                                ");//���require
			setCursorPosition((83 + i), 22);
			if (xinxi[UserNum].name[i] == '\r' || i > 20)
				break;
			if (xinxi[UserNum].name[i] == '\b')
			{
				if (i <= 1)
				{
					setCursorPosition(64, 22);
					printf(">>�����������û���:");
					setColor(8);
					printf("���Ȳ�����20λ�ַ��Ҳ��ú��пո�");
					setColor(15);
					setCursorPosition(83, 22);
					if (i == 0)
						continue;
				}
				i--;
				printf("\b");
			}
			else
				i++;
		} while (xinxi[UserNum].name[i] != '\n');
		xinxi[UserNum].name[i] = '\0';
		printf("\n");
		for (i = 0; i < UserNum; i++)
		{
			if (strcmp(xinxi[UserNum].name, xinxi[i].name) == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)//�ظ�����
		{
			printf("\n\t\t\t\t\t\t\t\t  *����* �û����Ѵ���!�Ƿ��¼?(Y/N):");
			gets(GetOptSTR);
			while(GetOption(GetOptSTR)!='Y'&&GetOption(GetOptSTR)!='N')
			{
				system("cls");
				LogoOops();
				Tips(3);
				printf("\n\t\t\t\t\t\t\t\t�û����Ѵ���!�Ƿ��¼?(Y/N):");
				gets(GetOptSTR);
			}
			if(GetOption(GetOptSTR)=='Y')
				UserLogin();
			else
			{
				setCursorPosition(0,23);
				printf("\n\t\t\t\t\t\t\t\t  *����* �û����Ѵ���!�Ƿ��¼?(Y/N):  \n\n");
			}
		}
		else if (strlen(xinxi[UserNum].name) == 0 || strlen(xinxi[UserNum].name) > 20 || CheckString(xinxi[UserNum].name, ' '))//�����ж�
			printf("\n\t\t\t\t\t\t\t\t  *����* �û��������Ϲ淶!           \n\n");
		else
		{
			printf("\n\t\t\t\t\t\t\t\t  *��ȷ*                             \n\n");
			break;
		}
		flag = 0;
		i = 0;
	}
	char question1[] = { ">>��������������:" };
	char question2[] = { ">>��ȷ����������:" };
	char require[] = { "���Ȳ�����20λ�ַ��Ҳ��ú��пո�" };
	char require2[] = { "                                " };
	setCursorPosition(64, 26);
	printf("%s", question1);
	setColor(8);
	printf("%s", require);
	while (1)
	{
		while (1)
		{
			setColor(15);
			setCursorPosition(0, 20);
			printf("\t\t\t\t\t\t\t\t    ��1���û���->��2������->");
			setColor(8);
			printf("��3��ȷ������->��4���ֻ�����    \n\n");
			setColor(15);
			setCursorPosition(81, 26);
			CoverPlus(question1, require, xinxi[UserNum].password, 64, 26);
			if (strlen(xinxi[UserNum].password) == 0 || strlen(xinxi[UserNum].password) > 20 || CheckString(xinxi[UserNum].password, ' '))//�����ж�
			{
				printf("\n\t\t\t\t\t\t\t\t  *����* ���벻���Ϲ淶��\n\n");
				setCursorPosition(64, 26);
				printf("%s", question1);
				setColor(8);
				printf("%s", require);
				setCursorPosition(64, 26);
				Initialize(xinxi[UserNum].password);
			}
			else
			{
				printf("\n\t\t\t\t\t\t\t\t  *��ȷ*                 \n\n");
				break;
			}
		}
		setCursorPosition(64, 30);
		printf("%s%s", question2, require2);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t    ��1���û���->��2������->��3��ȷ������->");
		setColor(8);
		printf("��4���ֻ�����    \n\n");
		setColor(15);
		setCursorPosition(81, 30);
		CoverPlus(question2, require2, checkpassword, 64, 30);
		if (strcmp(checkpassword, xinxi[UserNum].password) != 0)
		{
			printf("\n\t\t\t\t\t\t\t\t  *����* �����������벻һ�£�\n\n");
			setCursorPosition(64, 26);
			printf("%s", question1);
			setColor(8);
			printf("%s", require);
			setColor(15);
			setCursorPosition(64, 30);
			printf("%s%s", question2, require2);
			setCursorPosition(64, 26);
			Initialize(xinxi[UserNum].password);
			Initialize(checkpassword);
		}
		else
		{
			printf("\n\t\t\t\t\t\t\t\t  *��ȷ*                     \n\n");
			break;
		}
	}
	while (1)
	{
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t    ��1���û���->��2������->��3��ȷ������->��4���ֻ�����    \n\n");
		setCursorPosition(0, 34);
		printf("\t\t\t\t\t\t\t\t>>�����������ֻ�����:");
		gets(xinxi[UserNum].phone);
		if (strlen(xinxi[UserNum].phone) != 11 || CheckAlpha(xinxi[UserNum].phone))
		{
			printf("\n\t\t\t\t\t\t\t\t  *����* ��������ȷ���ֻ����룡\n\n");
			setCursorPosition(0, 34);
			printf("\t\t\t\t\t\t\t\t>>�����������ֻ�����:%s", require2);
			setCursorPosition(0, 34);
			Initialize(xinxi[UserNum].phone);
		}
		else
			break;
	}
	system("cls");
	LogoRegist();
	Tips(0);
	xinxi[UserNum].borrowingbook = 0;
	for (i = 0; i < 3; i++)
	{
		strcpy(xinxi[UserNum].book[i].bookname, "/");
		strcpy(xinxi[UserNum].book[i].booknumber, "/");
		xinxi[UserNum].book[i].shouldback.day = 0;
		xinxi[UserNum].book[i].shouldback.days = 0;
		xinxi[UserNum].book[i].shouldback.month = 0;
		xinxi[UserNum].book[i].shouldback.min = 0;
		xinxi[UserNum].book[i].shouldback.year = 0;
		xinxi[UserNum].book[i].outtime.day = 0;
		xinxi[UserNum].book[i].outtime.days = 0;
		xinxi[UserNum].book[i].outtime.month = 0;
		xinxi[UserNum].book[i].outtime.min = 0;
		xinxi[UserNum].book[i].outtime.year = 0;
	}
	UserNum++;
	LoginInterface();//ע��ɹ��󷵻�������	
}


void AdminOption()
{
	TAG = 2;//����Ա����
	while (1)
	{
		system("cls");
		system("color 0F");
		LogoAdmin();
		AdminOptUI();
		gets(GetOptSTR);//��ȡ�û�����
		switch (GetOption(GetOptSTR))
		{
		case '1': BookIn(); break;
		case '2': BookOut(); break;
		case '3': HistoryPrint(); break;
		case '4': AdminBookSearch(); break;
		case '5': BookAdjust();break;
		case '0': LoginInt2(); break;
		default:system("cls"); LogoOops(); Tips(3); break;
		}
	}

}

void UserOption()
{
	TAG = 1;//��ǰ�������û�����
	while (1)
	{
		system("cls");
		system("color 0f");
		LogoUser();
		UserOptUI();
		gets(GetOptSTR);//��ȡ�û�����
		switch (GetOption(GetOptSTR))
		{
		case '1': SearchInterface(); break;
		case '2': BookLend(); break;
		case '3': BookReturn(); break;
		case '4': UserSearch(); break;
		case '0': LoginInt2(); break;
		default:system("cls"); LogoOops(); Tips(3); break;
		}
	}
}

void UserLogin()/*��ͨ�û���¼����,��¼��Ϣ�뻺����Ϣ�Ƚ�*/
{
	int i = 0,flag = 1;//��½�ɹ��жϱ�ʾ
	char name[20];
	char password[20];
	char question1[]={">>��������������:"};
	char require[]={"                                "};
	while (1)
	{
		system("cls");
		system("color 0F");
		LogoLogin();
		printf("\t\t\t\t\t\t\t\t\t\t����ǰ���ʵ���:��ͨ�û���¼����  \n");
		printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t                   ��1���û���->");
		setColor(8);
		printf("��2������                    \n\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t>>�����������û���:");
		gets(name);
		printf("\n\n");
		setColor(15);
		setCursorPosition(0,20);
		printf("\t\t\t\t\t\t\t\t                   ��1���û���->��2������                    \n\n\n");
		setCursorPosition(64,26);
		printf("%s%s",question1,require);
		setCursorPosition(81,26);
		CoverPlus(question1,require,password,64,26);
		if(strlen(password)!=0)
		{
			for (i = 0; i <= UserNum; i++)
			{
				if (strcmp(name, xinxi[i].name) == 0)
					break;
			}
			if (strcmp(password, xinxi[i].password) == 0)
			{
				Usercode = i;
				flag = 0;
				system("cls");
				LogoLogin();
				Tips(1);
				UserOption();
			}
		}
		if (flag == 1)//�û���¼ʧ��
		{
			system("cls");
			LogoOops();
			Tips(2);
			printf("\t\t\t\t\t\t\t\t�Ƿ�������Ե�½?(Y/N):");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);
				printf("\t\t\t\t\t\t\t\t�Ƿ�������Ե�½?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')
				break;
		}

	}
	LoginInterface();//�û������������¼�򷵻�������
}


void VisitorLogin()//�ο͵�¼ѡ��
{
	TAG = 3;//�οͽ���
	while (1)
	{
		system("cls");
		system("color 0f");
		LogoVisitor();
		VisitorLogUI();
		gets(GetOptSTR);
		while (GetOption(GetOptSTR) != '0'&&GetOption(GetOptSTR) != '1')
		{
			system("cls");
			LogoOops();
			Tips(3);
			system("cls");
			system("color 0F");
			LogoVisitor();//�ο�Logo
			VisitorLogUI();
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == '1')
			SearchInterface();//�鼮����
		else
			LoginInt2();
	}
}

void AdminLogin()//����Ա��¼
{
	int i = 0;//���ɱ���������for
	char name[20];
	char password[20];
	char question1[]={">>��������������:"};
	char require[]={"                                "};
	while (1)
	{
		system("cls");
		system("color 0f");
		LogoLogin();
		printf("\t\t\t\t\t\t\t\t\t\t����ǰ���ʵ���:����Ա��½����\n");
		printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t                   ��1���û���->");
		setColor(8);
		printf("��2������                    \n\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t>>���������Ա�ʺ�:");
		gets(name);
		printf("\n\n");
		setColor(15);
		setCursorPosition(0,20);
		printf("\t\t\t\t\t\t\t\t                   ��1���û���->��2������                    \n\n\n");
		setCursorPosition(64,26);
		printf("%s%s",question1,require);
		setCursorPosition(81,26);
		CoverPlus(question1,require,password,64,26);
		if ((strcmp(name, administrator.name) != 0) || (strcmp(password, administrator.password) != 0))//�˺Ż����벻ƥ��
		{
			system("cls");
			LogoOops();
			Tips(2);
			printf("\t\t\t\t\t\t\t\t�Ƿ������½?(Y/N):");
			gets(GetOptSTR);
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);
				printf("\t\t\t\t\t\t\t\t�Ƿ������½?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')
				break;
		}
		else//��½�ɹ�
		{
			system("cls");
			LogoLogin();
			Tips(1);
			AdminOption();
		}
	}
	LoginInterface();//�û������������¼�򷵻�������
}
void LoginInt2()/*ѡ�����Ա��¼���û���¼���ο͵�¼*/
{
	TAG = 0;//TAG��ʼ��
	while(1)
	{
		system("cls");
		system("color 0f");
		LogoLogin();
		LoginInt2UI();
		gets(GetOptSTR);
		switch (GetOption(GetOptSTR))
		{
			case '1':UserLogin(); break;
			case '2':AdminLogin(); break;
			case '3':VisitorLogin(); break;
			case '0':LoginInterface(); break;
			default:system("cls"); LogoOops(); Tips(3); break;
		}
	}
}

void LoginInterface()//�û���¼��ʼ����
{
	while (1)
	{
		system("cls");
		system("color 0f");
		LogoGo(0);
		LoginIntUI();
		gets(GetOptSTR);
		switch (GetOption(GetOptSTR))
		{
			case '1': Registe(); break;
			case '2': LoginInt2(); break;
			case '0': BookInfIn(); UserInformationIn();system("cls");LogoGo(0);Tips(6);exit(0); break;
			default: system("cls"); LogoOops(); Tips(3); break;
		}
	}
}

void UserSearch()  /*�û���Ϣ��ѯ����*/
{
	char flag;
	system("cls");
	system("color 0f");
	LogoUserSearch();
	int line=0;
	printf("\t\t\t\t\t\t\t\t\t\t����ǰ���ʵ���:�û���Ϣ��ѯ����\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t\t  ����� ������                    ����������   ��Ӧ������");
	if (xinxi[Usercode].book[0].outtime.year == 0)
	{
		printf("\n\n\t\t\t\t\t\t\t\t�������Ľ�����Ϣ\n\n\n");
		printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t\t************************************************************\n");
		printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n\n");
	}
	else
	{
		setCursorPosition(67,24);
		puts("1");
		setCursorPosition(74,24);
		puts(xinxi[Usercode].book[0].bookname);
		setCursorPosition(100,24);
		printf("%d/%d/%d",xinxi[Usercode].book[0].outtime.year, xinxi[Usercode].book[0].outtime.month, xinxi[Usercode].book[0].outtime.day);
		setCursorPosition(113,24);
		printf("%d/%d/%d",xinxi[Usercode].book[0].shouldback.year, xinxi[Usercode].book[0].shouldback.month, xinxi[Usercode].book[0].shouldback.day);
		line++;
		if (xinxi[Usercode].book[1].outtime.year == 0)
			printf("\n\n\n\n\t\t\t\t\t\t\t\t��������������Ϣ");
		else
		{
			setCursorPosition(67,(24+2*line));
			puts("2");
			setCursorPosition(74,(24+2*line));
			puts(xinxi[Usercode].book[1].bookname);
			setCursorPosition(100,(24+2*line));
			printf("%d/%d/%d",xinxi[Usercode].book[1].outtime.year, xinxi[Usercode].book[1].outtime.month, xinxi[Usercode].book[1].outtime.day);
			setCursorPosition(113,(24+2*line));
			printf("%d/%d/%d",xinxi[Usercode].book[1].shouldback.year, xinxi[Usercode].book[1].shouldback.month, xinxi[Usercode].book[1].shouldback.day);
			line++;
			if (xinxi[Usercode].book[2].outtime.year == 0)
				printf("\n\n\n\n\t\t\t\t\t\t\t\t��������������Ϣ");
			else
			{
				setCursorPosition(67,(24+2*line));
				puts("3");
				setCursorPosition(74,(24+2*line));
				puts(xinxi[Usercode].book[2].bookname);
				setCursorPosition(100,(24+2*line));
				printf("%d/%d/%d",xinxi[Usercode].book[2].outtime.year, xinxi[Usercode].book[2].outtime.month, xinxi[Usercode].book[2].outtime.day);
				setCursorPosition(113,(24+2*line));
				printf("%d/%d/%d",xinxi[Usercode].book[2].shouldback.year, xinxi[Usercode].book[2].shouldback.month, xinxi[Usercode].book[2].shouldback.day);
			}
		}
		printf("\t\t\t     �û���: %s \n", xinxi[Usercode].name);
		printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t\t************************************************************\n");
		printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
	}
	line=0;
	printf("\t\t\t\t\t\t\t\t�������Խ��� %d ����\t\t\t�Ƿ����?(Y/N):", 3 - xinxi[Usercode].borrowingbook);
	gets(GetOptSTR);//��ȡ�û�����
	while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
	{
		system("cls");
		LogoOops();
		Tips(3);//��������
		printf("\t\t\t\t\t\t\t\t�Ƿ����?(Y/N):");
		gets(GetOptSTR);
	}
	if (GetOption(GetOptSTR) == 'N')//�����н���
		UserOption();
	else//���н���
		BookLend();
}

void BookIn()/*ͼ����ⲿ��*/
{
	int i = 0, j = 0, k = 0, flag = 0;
	struct inbook
	{
		char wantname[40];
		int typenum;
		char booktype[20];
		char author[20];
		char press[20];
	}inbook;
	char question1[]={">>���������ͼ������:"};
	char question2[]={">>���������ͼ�����:"};
	char question3[]={">>���������ͼ������:"};
	char question4[]={">>���������ͼ�������:"};
	char require1[]={"������20���ַ��Ҳ��ú��пո�"};
	char require2[]={"������8���ַ��Ҳ��ú��пո�"};
	char error1[]={"*����* ͼ�����Ʋ����Ϲ淶"};
	char error2[]={"*����* ͼ����಻���Ϲ淶"};
	char error3[]={"*����* ͼ�����߲����Ϲ淶"};
	char error4[]={"*����* ͼ������粻���Ϲ淶"};
	char right0[]={"*��ȷ*                   "};
	while (1)
	{
		system("cls");
		system("color 0f");
		LogoBookIn(); 
		printf("\t\t\t\t\t\t\t\t\t\t  ����ǰ���ʵ���:�鼮������\n");
		printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t     ��1������ͼ������->");
		setColor(8);
		printf("��2���鼮��Ϣ->��3���������      \n\n\n");
		setColor(15);
		GetBookName(question1,require1,error1,right0,inbook.wantname,64,22,20);
		setCursorPosition(0,20);
		setColor(15);
		printf("\t\t\t\t\t\t\t\t     ��1������ͼ������->��2���鼮��Ϣ->");
		setColor(8);
		printf("��3���������      \n\n\n");
		setColor(15);
		GetBookName(question2,require2,error2,right0,inbook.booktype,64,26,8);
		GetBookName(question3,require1,error3,right0,inbook.author,64,30,20);
		GetBookName(question4,require1,error4,right0,inbook.press,64,34,20);
		setCursorPosition(0,20);
		setColor(15);
		printf("\t\t\t\t\t\t\t\t     ��1������ͼ������->��2���鼮��Ϣ->��3���������      \n\n\n");
		setCursorPosition(0,38);
		while (1)
		{
			printf("\t\t\t\t\t\t\t\t>>���������ͼ������:");
			gets(GetOptSTR);
			if (CheckAlpha(GetOptSTR))
				printf("\n\t\t\t\t\t\t\t\t*����* ����Ƿ���\n\n");
			else
			{
				inbook.typenum = atol(GetOptSTR);
				Initialize(GetOptSTR);
				printf("\n\t\t\t\t\t\t\t\t*��ȷ*\n\n");
				break;
			}
		}
		for (j = BookNum; j < BookNum + inbook.typenum; j++)
		{
			strcpy(allbook[j].bookname, inbook.wantname);
			strcpy(allbook[j].booktype, inbook.booktype);
			strcpy(allbook[j].author, inbook.author);
			strcpy(allbook[j].press, inbook.press);
			itoa(j + 1, allbook[j].booknumber, 10);/*������ת�����ַ�����ʵ���Զ�����*/
			strcpy(allbook[j].who, "/");
			allbook[j].outtime.year = 0;
			allbook[j].outtime.month = 0;
			allbook[j].outtime.days = 0;
			allbook[j].outtime.day = 0;
			allbook[j].outtime.hour = 0;
			allbook[j].outtime.min = 0;
			allbook[j].shouldback.year = 0;
			allbook[j].shouldback.month = 0;
			allbook[j].shouldback.day = 0;
			allbook[j].shouldback.hour = 0;
			allbook[j].shouldback.min = 0;
			allbook[j].shouldback.days = 0;
			allbook[j].inshelf = 'Y';
			allbook[j].late = 'N';
		}
		BookNum = j;
		printf("\t\t\t\t\t\t\t\t*������*\n");
		printf("\n\t\t\t\t\t\t\t\t�Ƿ����¼��?(Y/N):");
		gets(GetOptSTR);//��ȡ�û�����
		while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
		{
			system("cls");
			LogoOops();
			Tips(3);//��������
			printf("\t\t\t\t\t\t\t\t�Ƿ����¼��?(Y/N):");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'N')//����whileѭ��
			break;
	}
	AdminOption();//������
}

void BookOut()/*ͼ����ⲿ��*/
{
	int num = 0;
	int typenum = 0;
	int xuhao;
	int j, k,m,flag=0;
	int i=0;
	char outbook[40];
	struct havebook
	{ char press[40];
	  int num;
	}havebook[100];	
	while (1)
	{
		while (1)
		{
			system("cls");
			system("color 0f");
			LogoBookOut();
			printf("\t\t\t\t\t\t\t\t\t\t  ����ǰ���ʵ���:�鼮�������\n");
			printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n");
			for(j=0;j<99;j++)
			{	strcpy(havebook[j].press,"\0");
				havebook[j].num=0;
			}
			setColor(15);
			printf("\t\t\t\t\t\t\t\t        ��1�������鼮��������->");
			setColor(8);
			printf("��2�����г������\n\n\n");
			setColor(15);
			printf("\t\t\t\t\t\t\t\t>>��������Ҫ�����ͼ������:");
			gets(outbook);
			setCursorPosition(0,20);
			setColor(15);
			printf("\t\t\t\t\t\t\t\t        ��1�������鼮��������->��2�����г������\n\n\n");
			setCursorPosition(0,24);
			printf("\n\t\t\t\t\t\t\t\t   ������ת�������");
			Sleep(1500);
			for (j = 0; j < BookNum; j++)
			{
				if (strcmp(outbook,allbook[j].bookname) == 0 && allbook[j].inshelf == 'Y')
				{	num++;
					for(m=0;m<99;m++)
						if(strcmp(allbook[j].press,havebook[m].press)==0)
							flag++;
					if(flag==0)
					{	
						strcpy(havebook[i].press,allbook[j].press);
						i++;
					}					
				}
				flag=0;
			}
			if (num == 0)
			{	
				system("cls");
				LogoOops();
				Tips(4);
				printf("\t\t\t\t\t\t\t\t�Ƿ���������?(Y/N):");
				gets(GetOptSTR);//��ȡ�û�����
				while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
				{
					system("cls");
					LogoOops();
					Tips(3);//��������
					printf("\t\t\t\t\t\t\t\t�Ƿ���������?(Y/N):");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'N')//����������
					AdminOption();
			}
			else
			{
				i=0;
				num=0;
				break;
			}
		}
		system("cls");
		system("color 0f");
		LogoBookAdjust();
		printf("\t\t\t\t\t\t\t\t\t        ����ǰ���ʵ���:�鼮�������\n");
		printf("\t\t\t\t\t\t\t��������������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t********************************************************************************\n");
		printf("\t\t\t\t\t\t\t��������������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t ����� ������                         ��������                      ���ڼ�����\n\n");
		for(m=0;strcmp(havebook[m].press,"\0")!=0;m++)	
		{
			for(i=0;i<BookNum;i++)		
			{
				if(strcmp(allbook[i].bookname,outbook)==0&&strcmp(allbook[i].press,havebook[m].press)==0&&allbook[i].inshelf=='Y')
				{
					havebook[m].num++;
				}
			}
		}
		for(m=0;strcmp(havebook[m].press,"\0")!=0;m++)
		{
			setCursorPosition(61,(24+2*m));
			printf("%d",m+1);
			setCursorPosition(65,(24+2*m));
			puts(outbook);
			setCursorPosition(96,(24+2*m));
			puts(havebook[m].press);
			setCursorPosition(130,(24+2*m));
			printf("%d",havebook[m].num);
		}
		printf("\n\n\n\t\t\t\t\t\t\t��������������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t********************************************************************************\n");
		printf("\t\t\t\t\t\t\t��������������������������������������������������������������������������������\n");
		while(1)
		{
			while(1)
			{
				printf("\n\t\t\t\t\t\t\t\t>>������Ҫ�����ͼ�����:");
				gets(GetOptSTR);
				if (CheckAlpha(GetOptSTR))
					printf("\n\t\t\t\t\t\t\t\t*����* ����Ƿ���\n");
				else
				{
					xuhao=atol(GetOptSTR);
					Initialize(GetOptSTR);
					break;
				}
			}
			if(xuhao>m)//������������
				printf("\n\t\t\t\t\t\t\t\t*����* û����ƥ����鼮!\n");
			else if(havebook[xuhao-1].num==0)
				printf("\n\t\t\t\t\t\t\t\t*����* �����ѱ�����,���ܳ���!\n");
			else
				break;
		}
		while (1)//���Գ���
		{
			printf("\n\t\t\t\t\t\t\t\t>>���������ͼ������:");
			gets(GetOptSTR);
			if (CheckAlpha(GetOptSTR))
				printf("\n\t\t\t\t\t\t\t\t>>*����* ����Ƿ���\n");
			else
			{
				typenum = atol(GetOptSTR);
				Initialize(GetOptSTR);
				if (typenum>havebook[xuhao-1].num)
				{
					printf("\n\t\t\t\t\t\t\t\t>>*����* ��������������ڼ���,����������!\n");
				}
				else
				{
					break;
				}
			}
		}
		for (j = 0; j < typenum; j++)
		{
			for (k = 0; k < BookNum; k++)
			{
				if (strcmp(outbook, allbook[k].bookname) == 0 && allbook[k].inshelf == 'Y'
					&&strcmp(allbook[k].press,havebook[xuhao-1].press)==0)
				{
					for (flag = k; flag < BookNum - 1; flag++)
					{
						strcpy(allbook[flag].bookname,allbook[flag + 1].bookname);
						strcpy(allbook[flag].booknumber,allbook[flag + 1].booknumber);
						strcpy(allbook[flag].booktype,allbook[flag + 1].booktype);
						strcpy(allbook[flag].who, allbook[flag + 1].who);
						allbook[flag].outtime.year = allbook[flag + 1].outtime.year;
						allbook[flag].outtime.month = allbook[flag + 1].outtime.month;
						allbook[flag].outtime.day = allbook[flag + 1].outtime.day;
						allbook[flag].outtime.hour = allbook[flag + 1].outtime.hour;
						allbook[flag].outtime.min = allbook[flag + 1].outtime.min;
						allbook[flag].outtime.days = allbook[flag + 1].outtime.days;
						allbook[flag].shouldback.year = allbook[flag + 1].shouldback.year;
						allbook[flag].shouldback.month = allbook[flag + 1].shouldback.month;
						allbook[flag].shouldback.day = allbook[flag + 1].shouldback.day;
						allbook[flag].shouldback.hour = allbook[flag + 1].shouldback.hour;
						allbook[flag].shouldback.min = allbook[flag + 1].shouldback.min;
						allbook[flag].shouldback.days = allbook[flag + 1].shouldback.days;
						allbook[flag].inshelf = allbook[flag + 1].inshelf;
						allbook[flag].late = allbook[flag + 1].late;
						strcpy(allbook[flag].author, allbook[flag + 1].author);
						strcpy(allbook[flag].press, allbook[flag + 1].press);
					}
					BookNum--;
				}
			}
		}
		printf("\n\t\t\t\t\t\t\t\t*ͼ��������*\n");
		for (i = 0; i < BookNum; i++)
			itoa(i + 1, allbook[i].booknumber, 10);
		printf("\n\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
		gets(GetOptSTR);//��ȡ�û�����
		while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
		{
			system("cls");
			LogoOops();
			Tips(3);//��������
			printf("\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'N')//����whileѭ��
			break;
	}
	AdminOption();
}

void BookAdjust()
{
	char wantname[30];
	int i;
	int flag=0;
	int number=0;
	while(1)
	{
		while(1)
		{
			system("cls");
			system("color 0f");
			LogoBookAdjust();//�鼮�޸�
			printf("\t\t\t\t\t\t\t\t\t      ����ǰ���ʵ���:�鼮��Ϣ�޸Ľ���\n");
			printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n");
			setColor(15);
			printf("\t\t\t\t\t\t\t\t        ��1�������鼮��������->");
			setColor(8);
			printf("��2�������޸Ĳ���\n\n\n");
			setColor(15);
			printf("\t\t\t\t\t\t\t\t>>��������Ҫ�޸ĵ�ͼ������:");
			gets(wantname);
			setCursorPosition(0,20);
			setColor(15);
			printf("\t\t\t\t\t\t\t\t        ��1�������鼮��������->��2�������޸Ĳ���\n\n\n");
			setCursorPosition(0,24);
			printf("\n\t\t\t\t\t\t\t\t   ������ת�������");
			Sleep(1500);
			for(i=0;i<BookNum;i++)
			{
				if(strcmp(wantname,allbook[i].bookname)==0)
					flag++;
			}
			if(flag==0)
			{	
				system("cls");
				LogoOops();
				Tips(4);
				printf("\t\t\t\t\t\t\t\t�Ƿ���������?(Y/N):");
				gets(GetOptSTR);//��ȡ�û�����
				while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
				{
					system("cls");
					LogoOops();
					Tips(3);//��������
					printf("\t\t\t\t\t\t\t\t�Ƿ���������?(Y/N):");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'N')//����������
					AdminOption();
			}
			else
			{	
				system("cls");
				system("color 0f");
				LogoBookAdjust();
				printf("\t\t\t\t\t\t\t\t\t      ����ǰ���ʵ���:�鼮��Ϣ�޸Ľ���\n");
				printf("\t\t\t\t\t\t    ����������������������������������������������������������������������������������������\n");
				printf("\t\t\t\t\t\t    ****************************************************************************************\n");
				printf("\t\t\t\t\t\t    ����������������������������������������������������������������������������������������\n");
				printf("\t\t\t\t\t\t      ����� ������             ������ ��������              ������             ���Ƿ��ڼ�\n\n");
				for(i=0;i<BookNum;i++)
				{
					if(strcmp(wantname,allbook[i].bookname)==0)
					{
						setCursorPosition(58,(24+2*i));
						puts(allbook[i].booknumber);
						setCursorPosition(62,(24+2*i));
						puts(allbook[i].bookname);
						setCursorPosition(82,(24+2*i));
						puts(allbook[i].booktype);
						setCursorPosition(89,(24+2*i));
						puts(allbook[i].press);
						setCursorPosition(111,(24+2*i));
						puts(allbook[i].author);
						setCursorPosition(133,(24+2*i));
						if(allbook[i].inshelf=='Y')
							printf("��");
						else
							printf("��");
						printf("\n\n");
					}
				}
				printf("\n\t\t\t\t\t\t    ����������������������������������������������������������������������������������������\n");
				printf("\t\t\t\t\t\t    ****************************************************************************************\n");
				printf("\t\t\t\t\t\t    ����������������������������������������������������������������������������������������\n");
				break;
			}
		}
		flag=0;
		while(1)
		{
			while (1)
			{
				printf("\t\t\t\t\t\t\t>>��������Ҫ�޸ĵ�ͼ�����:");
				gets(GetOptSTR);
				if (CheckAlpha(GetOptSTR))
					printf("\n\t\t\t\t\t\t\t*����* ����Ƿ���\n");
				else
				{
					number=atol(GetOptSTR);
					break;
				}
			}
			for(i=0;i<BookNum;i++)//�ж��Ƿ��ж�Ӧ���
			{
				if(strcmp(GetOptSTR,allbook[i].booknumber)==0&&strcmp(allbook[number-1].bookname,wantname)==0)
				{	
					flag++;
					break;
				}
			}
			if(flag==0)
				printf("\n\t\t\t\t\t\t\t*����* û����ƥ����鼮!\n");
			else if(allbook[number-1].inshelf=='N')
				printf("\n\t\t\t\t\t\t\t*����* �����ѱ�����,�����޸���Ϣ!\n");
			else
			{
				printf("\n\t\t\t\t\t\t\t*��ȷ*\n");
				flag=0;
				printf("\n\t\t\t\t\t\t\t>>������¼���鼮��Ϣ\n");
				printf("\n\t\t\t\t\t\t\t>>������ͼ������:");
				gets(allbook[number-1].bookname);
				printf("\n\t\t\t\t\t\t\t>>������ͼ�����:");
				gets(allbook[number-1].booktype);
				printf("\n\t\t\t\t\t\t\t>>������ͼ�������:");
				gets(allbook[number-1].press);
				printf("\n\t\t\t\t\t\t\t>>������ͼ������:");
				gets(allbook[number-1].author);
				printf("\n\t\t\t\t\t\t\t*�޸����!*\n");
			}
			printf("\n\t\t\t\t\t\t\t�Ƿ�����޸�����ͼ����Ϣ?(Y/N):");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{	
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\t�Ƿ�����޸�����ͼ����Ϣ?(Y/N):");
				gets(GetOptSTR);
			}	
			if (GetOption(GetOptSTR) == 'N')//�������޸�
				AdminOption();
			else
				break;	
		}//��whileѭ������
	}//��whileѭ������
}

void BookLend()/*�û�ͼ����Ĳ���*/
{	int flagx[100];
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>��������Ҫ��ѯ��ͼ������:"};
	char require[]={"֧��ģ����ѯ,��������ȷ��ͼ������"};
	char error[]={"*����* ͼ�����Ʋ����Ϲ淶"};
	char right[]={"*��ȷ* ������ת�������  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0,typenum=0;//count->�ؼ������Զ��ٸ�����,number->ĳ�鼮����
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//����ֵ������Ҫ
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t����ǰ���ʵ���:���Ʋ�ѯ����\n");
		printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          ��1�������鼮�ؼ���->");
		setColor(8);
		printf("��2���������鱾��Ϣ\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,20);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          ��1�������鼮�ؼ���->��2���������鱾��Ϣ\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//�ؼ�����Ƭ����
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//�����������������¼���ά����
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//�����ַ�����������
			{
				if (strstr(allbook[j].bookname, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//��������ҵ�
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//forѭ���ж��Ƿ��Ѿ���¼
				{
					if (strcmp(allbook[j].bookname, mohusearch[i]) == 0&&strcmp(allbook[j].author, author[i])==0&&strcmp(allbook[j].press,press[i])==0)
					{
						flag2 = 1;
						break;
					}
				}
				if (flag2 == 0)
				{
					strcpy(mohusearch[NO], allbook[j].bookname);
						strcpy(author[NO], allbook[j].author);
							strcpy(press[NO], allbook[j].press);
					NO++;
					count++;
				}
			}
		}
		if (count != 0)//����
		{
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t       ����� ������               ������ ��������              ������              ���ݲ������ɽ���\n\n");
			for (NO = 0; NO < count; NO++)//����ÿ��������Ӧ������
			{
				onecount=0;
				for (i = 0; i < BookNum; i++)
				{
					if (strcmp(mohusearch[NO], allbook[i].bookname) == 0&&strcmp(author[NO], allbook[i].author)==0&&strcmp(press[NO], allbook[i].press)==0)
					{
						flagx[NO]=i;
						flag = i;
						onecount++;
						if (allbook[i].inshelf == 'Y')
						number++;
					}
				}
				setCursorPosition(50,(24+2*NO));
				printf("%d",NO + 1);
				setCursorPosition(54,(24+2*NO));
				puts(allbook[flag].bookname);
				setCursorPosition(75,(24+2*NO));
				puts(allbook[flag].booktype);
				setCursorPosition(82,(24+2*NO));
				puts(allbook[flag].press);
				setCursorPosition(104,(24+2*NO));
				puts(allbook[flag].author);
				setCursorPosition(128,(24+2*NO));
				printf("%d",onecount);
				setCursorPosition(136,(24+2*NO));
				printf("%d",number);
				number = 0;
				printf("\n\n");
			}
			printf("\n\n\t\t\t\t\t      *��ѯ���*                                                                  ����ѯ��%d����Ϣ\n\n", count);
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t\t�Ƿ�������Ҫ���ĵ��鼮?(Y/N):");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				printf("\n\t\t\t\t\t\t*����* ����Ƿ�!\n");
				printf("\n\t\t\t\t\t\t�Ƿ�������Ҫ���ĵ��鼮?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//����whileѭ��
				break;
		}
		else//û������鼮
		{
			system("cls");
			LogoOops();
			Tips(4);//δ��ѯ�������Ϣ
			printf("\t\t\t\t\t\t\t\t�Ƿ�������������鼮?(Y/N):");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\t�Ƿ�������������鼮?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//����whileѭ��
				break;
		}
		while (1)
		{
			flag=0;
			printf("\n\t\t\t\t\t\t>>������������ĵ��鼮���:");
			gets(GetOptSTR);
			if (CheckAlpha(GetOptSTR))
				printf("\n\t\t\t\t\t\t*����* ����Ƿ�!\n");
			else
			{
				typenum = atol(GetOptSTR);
				for(i=0;i<BookNum;i++)//�ж��Ƿ��ж�Ӧ���
				{
					if(strcmp(GetOptSTR,allbook[i].booknumber)==0)
					{	
						flag++;
						break;
					}
				}	
				if (flag==0)
					printf("\n\t\t\t\t\t\t*����* û����ƥ����鼮!\n");
				else
				{
					Initialize(GetOptSTR);
					if(allbook[typenum].inshelf=='N')
					{
						printf("\n\t\t\t\t\t\t*����* �����ѱ�����!\n");
						printf("\n\t\t\t\t\t\t�Ƿ�������������鼮?(Y/N):");
						gets(GetOptSTR);//��ȡ�û�����
						while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
						{
							system("cls");
							LogoOops();
							Tips(3);//��������
							printf("\t\t\t\t\t\t\t\t�Ƿ�������������鼮?(Y/N):");
							gets(GetOptSTR);
						}
						if (GetOption(GetOptSTR) == 'N')//����whileѭ��
							break;
						else 
							continue;
					}
					if(allbook[typenum].inshelf=='Y')
						break;
				}
			}
		}
		BookBorrowBottom(flagx[typenum-1]);//���ĳɹ���־
		HistoryWrite();
		flag = 0;
		number = 0;
		printf("\n\t\t\t\t\t\t�Ƿ�������������鼮?(Y/N):");//�Ƿ���������鼮
		gets(GetOptSTR);
		while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
		{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\t�Ƿ�������������鼮?(Y/N):");
				gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'N')//�����������鼮
			UserOption();
		else//�������������鼮
			continue;
		/*��ʼ������*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//whileѭ������
}

void BookBorrowBottom(int number)//���鰴ť���º���������
{
	if (xinxi[Usercode].book[0].outtime.year == 0)
	{
		strcpy(allbook[number].who, xinxi[Usercode].name);
		strcpy(xinxi[Usercode].book[0].bookname, allbook[number].bookname);
		strcpy(xinxi[Usercode].book[0].booknumber, allbook[number].booknumber);
		xinxi[Usercode].book[0].outtime.year = nowtime.year;
		xinxi[Usercode].book[0].outtime.month = nowtime.month;
		xinxi[Usercode].book[0].outtime.day = nowtime.day;
		xinxi[Usercode].book[0].outtime.hour = nowtime.hour;
		xinxi[Usercode].book[0].outtime.min = nowtime.min;
		xinxi[Usercode].book[0].outtime.days = nowtime.days;
		allbook[number].inshelf = 'N';
		xinxi[Usercode].book[0].shouldback.year = future.year;
		xinxi[Usercode].book[0].shouldback.month = future.month;
		xinxi[Usercode].book[0].shouldback.day = future.day;
		allbook[number].outtime.year = nowtime.year;
		allbook[number].outtime.month = nowtime.month;
		allbook[number].outtime.day = nowtime.day;
		allbook[number].shouldback.year = future.year;
		allbook[number].shouldback.month = future.month;
		allbook[number].shouldback.day = future.day;
		xinxi[Usercode].borrowingbook += 1;
		strcpy(history[hisnum].name,xinxi[Usercode].name);
		history[hisnum].year=nowtime.year;
		history[hisnum].month=nowtime.month;
		history[hisnum].day=nowtime.day;
		history[hisnum].hour=nowtime.hour;
		history[hisnum].min=nowtime.min;
		strcpy(history[hisnum].inorout,"out");
		history[hisnum].late='N';
		strcpy(history[hisnum].phone,xinxi[Usercode].phone);
		strcpy(history[hisnum].booknumber,allbook[number].booknumber);
		strcpy(history[hisnum].bookname,allbook[number].bookname);
		hisnum++;
		printf("\n\t\t\t\t\t\t\t\t  *���ĳɹ�*\n\n");

	}
	else if (xinxi[Usercode].book[1].outtime.year == 0)

	{

		strcpy(allbook[number].who, xinxi[Usercode].name);
		strcpy(xinxi[Usercode].book[1].bookname, allbook[number].bookname);
		strcpy(xinxi[Usercode].book[1].booknumber, allbook[number].booknumber);
		xinxi[Usercode].book[1].outtime.year = nowtime.year;
		xinxi[Usercode].book[1].outtime.month = nowtime.month;
		xinxi[Usercode].book[1].outtime.day = nowtime.day;
		xinxi[Usercode].book[1].outtime.hour = nowtime.hour;
		xinxi[Usercode].book[1].outtime.min = nowtime.min;
		xinxi[Usercode].book[1].outtime.days = nowtime.days;
		allbook[number].inshelf = 'N';
		xinxi[Usercode].book[1].shouldback.year = future.year;
		xinxi[Usercode].book[1].shouldback.month = future.month;
		xinxi[Usercode].book[1].shouldback.day = future.day;
		allbook[number].outtime.year = nowtime.year;
		allbook[number].outtime.month = nowtime.month;
		allbook[number].outtime.day = nowtime.day;
		allbook[number].shouldback.year = future.year;
		allbook[number].shouldback.month = future.month;
		allbook[number].shouldback.day = future.day;
		xinxi[Usercode].borrowingbook += 1;
		strcpy(history[hisnum].name,xinxi[Usercode].name);
		history[hisnum].year=nowtime.year;
		history[hisnum].month=nowtime.month;
		history[hisnum].day=nowtime.day;
		history[hisnum].hour=nowtime.hour;
		history[hisnum].min=nowtime.min;
		strcpy(history[hisnum].inorout,"out");
		history[hisnum].late='N';
		strcpy(history[hisnum].phone,xinxi[Usercode].phone);
		strcpy(history[hisnum].booknumber,allbook[number].booknumber);
		strcpy(history[hisnum].bookname,allbook[number].bookname);
		hisnum++;

		printf("\n\t\t\t\t\t\t  *���ĳɹ�*\n");
	}
	else if (xinxi[Usercode].book[2].outtime.year == 0)

	{

		strcpy(allbook[number].who, xinxi[Usercode].name);
		strcpy(xinxi[Usercode].book[2].bookname, allbook[number].bookname);
		strcpy(xinxi[Usercode].book[2].booknumber, allbook[number].booknumber);
		xinxi[Usercode].book[2].outtime.year = nowtime.year;
		xinxi[Usercode].book[2].outtime.month = nowtime.month;
		xinxi[Usercode].book[2].outtime.day = nowtime.day;
		xinxi[Usercode].book[2].outtime.hour = nowtime.hour;
		xinxi[Usercode].book[2].outtime.min = nowtime.min;
		xinxi[Usercode].book[2].outtime.days = nowtime.days;
		allbook[number].inshelf = 'N';
		xinxi[Usercode].book[2].shouldback.year = future.year;
		xinxi[Usercode].book[2].shouldback.month = future.month;
		xinxi[Usercode].book[2].shouldback.day = future.day;
		allbook[number].outtime.year = nowtime.year;
		allbook[number].outtime.month = nowtime.month;
		allbook[number].outtime.day = nowtime.day;
		allbook[number].shouldback.year = future.year;
		allbook[number].shouldback.month = future.month;
		allbook[number].shouldback.day = future.day;
		xinxi[Usercode].borrowingbook += 1;
		strcpy(history[hisnum].name,xinxi[Usercode].name);
		history[hisnum].year=nowtime.year;
		history[hisnum].month=nowtime.month;
		history[hisnum].day=nowtime.day;
		history[hisnum].hour=nowtime.hour;
		history[hisnum].min=nowtime.min;
		strcpy(history[hisnum].inorout,"out");
		history[hisnum].late='N';
		strcpy(history[hisnum].phone,xinxi[Usercode].phone);
		strcpy(history[hisnum].booknumber,allbook[number].booknumber);
		strcpy(history[hisnum].bookname,allbook[number].bookname);
		hisnum++;

		printf("\n\t\t\t\t\t\t\t\t  *���ĳɹ�*\n\n");
	}
	else
		printf("\n\n\t\t\t\t\t\t\t\t���Ѿ�����3�����ˣ����Ѳ������ٽ���!\n");
}
void BookReturn()//�û������鰴ť֮��Ľ���
{
	char wantnum[40];
	int op,pp,line=0,i=0;
	while (1)
	{
			system("cls");
			system("color 0f");
			LogoBookReturn();
			printf("\t\t\t\t\t\t\t\t\t\t  ����ǰ���ʵ���:�鼮�黹����\n");
			printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
			printf("\t\t\t\t\t\t\t\t************************************************************\n");
			printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
			printf("\t\t\t\t\t\t\t\t  ����� ������                    ����������   ��Ӧ������");
			if (strcmp(xinxi[Usercode].book[0].booknumber, "/") != 0)
			{
				setCursorPosition(67,24);
				puts("1");
				setCursorPosition(74,24);
				puts(xinxi[Usercode].book[0].bookname);
				setCursorPosition(100,24);
				printf("%d/%d/%d",xinxi[Usercode].book[0].outtime.year, xinxi[Usercode].book[0].outtime.month, xinxi[Usercode].book[0].outtime.day);
				setCursorPosition(113,24);
				printf("%d/%d/%d",xinxi[Usercode].book[0].shouldback.year, xinxi[Usercode].book[0].shouldback.month, xinxi[Usercode].book[0].shouldback.day);
				line++;
			}
			if (strcmp(xinxi[Usercode].book[1].booknumber, "/") != 0)
			{
				setCursorPosition(67,(24+2*line));
				puts("2");
				setCursorPosition(74,(24+2*line));
				puts(xinxi[Usercode].book[1].bookname);
				setCursorPosition(100,(24+2*line));
				printf("%d/%d/%d",xinxi[Usercode].book[1].outtime.year, xinxi[Usercode].book[1].outtime.month, xinxi[Usercode].book[1].outtime.day);
				setCursorPosition(113,(24+2*line));
				printf("%d/%d/%d",xinxi[Usercode].book[1].shouldback.year, xinxi[Usercode].book[1].shouldback.month, xinxi[Usercode].book[1].shouldback.day);
				line++;
			}
			if (strcmp(xinxi[Usercode].book[2].booknumber, "/") != 0)
			{
				setCursorPosition(67,(24+2*line));
				puts("3");
				setCursorPosition(74,(24+2*line));
				puts(xinxi[Usercode].book[2].bookname);
				setCursorPosition(100,(24+2*line));
				printf("%d/%d/%d",xinxi[Usercode].book[2].outtime.year, xinxi[Usercode].book[2].outtime.month, xinxi[Usercode].book[2].outtime.day);
				setCursorPosition(113,(24+2*line));
				printf("%d/%d/%d",xinxi[Usercode].book[2].shouldback.year, xinxi[Usercode].book[2].shouldback.month, xinxi[Usercode].book[2].shouldback.day);
			}
			if(strcmp(xinxi[Usercode].book[0].booknumber, "/") == 0&&strcmp(xinxi[Usercode].book[1].booknumber, "/") == 0&&strcmp(xinxi[Usercode].book[2].booknumber, "/") == 0)
			{
				printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t     ��û����Ҫ�黹���鼮!\n");
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t�û���: %s \n", xinxi[Usercode].name);
				printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
				printf("\t\t\t\t\t\t\t\t************************************************************\n");
				printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
				printf("\t\t\t\t\t\t\t\tȷ���밴'Y'�����ϼ�:");
				gets(GetOptSTR);
				while (GetOption(GetOptSTR) != 'Y')
				{
					system("cls");
					LogoOops();
					Tips(3);//��������
					printf("\t\t\t\t\t\t\t\tȷ���밴'Y'�����ϼ�:");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'Y')//���黹�����鼮
					UserOption();
			}
			line=0;
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t�û���: %s \n", xinxi[Usercode].name);
			printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
			printf("\t\t\t\t\t\t\t\t************************************************************\n");
			printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n");
			while(1)
			{
				printf("\n\t\t\t\t\t\t\t\t>>������黹ͼ������:");
				gets(GetOptSTR);
				if (CheckAlpha(GetOptSTR))
					printf("\n\t\t\t\t\t\t\t\t*����* ����Ƿ�!\n");
				else
				{
					op = atol(GetOptSTR);
					pp=op-1;
					Initialize(GetOptSTR);
					strcpy(wantnum, xinxi[Usercode].book[op - 1].booknumber);
					if (strcmp(wantnum, "/") == 0 ||(op != 1&&op != 2&&op != 3))//�����������
						printf("\n\t\t\t\t\t\t\t\t*����* û�������ƥ����鼮!\n");
					else
					{
						printf("\n\t\t\t\t\t\t\t\tȷ��Ҫ�黹 %d %s ��?(Y/N):",op,xinxi[Usercode].book[pp].bookname);
						gets(GetOptSTR);
						while(GetOption(GetOptSTR)!='Y'&&GetOption(GetOptSTR)!='N')
						{
							system("cls");
							LogoOops();
							Tips(3);
							printf("\t\t\t\t\t\t\t\tȷ��Ҫ�黹 %d %s ��?(Y/N):",op,xinxi[Usercode].book[pp].bookname);
							gets(GetOptSTR);
						}
						if(GetOption(GetOptSTR)=='N')
						{
							printf("\n\t\t\t\t\t\t\t\t�Ƿ�黹�����鼮?(Y/N):");//�Ƿ�黹�����鼮
							gets(GetOptSTR);
							while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
							{
								system("cls");
								LogoOops();
								Tips(3);//��������
								printf("\t\t\t\t\t\t\t\t�Ƿ�黹�����鼮?(Y/N):");
								gets(GetOptSTR);
							}
								if (GetOption(GetOptSTR) == 'N')//���黹�����鼮
									UserOption();
						}
						else
							break;
					}
				}
			}
			int i, flag;
			for (flag = 0; flag < BookNum; flag++)
			{
				if (strcmp(wantnum, allbook[flag].booknumber) == 0)
					i = flag;
			}
			strcpy(allbook[i].who, "/");
			allbook[i].outtime.year = 0;
			allbook[i].outtime.month = 0;
			allbook[i].outtime.days = 0;
			allbook[i].outtime.day = 0;
			allbook[i].outtime.hour = 0;
			allbook[i].outtime.min = 0;
			allbook[i].shouldback.year = 0;
			allbook[i].shouldback.month = 0;
			allbook[i].shouldback.day = 0;
			allbook[i].shouldback.hour = 0;
			allbook[i].shouldback.min = 0;
			allbook[i].shouldback.days = 0;
			allbook[i].inshelf = 'Y';
			allbook[i].late = 'N';
			xinxi[Usercode].borrowingbook -= 1;
			strcpy(xinxi[Usercode].book[pp].bookname, "/");
			strcpy(xinxi[Usercode].book[pp].booknumber, "/");
			xinxi[Usercode].book[pp].shouldback.day = 0;
			xinxi[Usercode].book[pp].shouldback.days = 0;
			xinxi[Usercode].book[pp].shouldback.month = 0;
			xinxi[Usercode].book[pp].shouldback.min = 0;
			xinxi[Usercode].book[pp].shouldback.year = 0;
			xinxi[Usercode].book[pp].outtime.day = 0;
			xinxi[Usercode].book[pp].outtime.days = 0;
			xinxi[Usercode].book[pp].outtime.month = 0;
			xinxi[Usercode].book[pp].outtime.min = 0;
			xinxi[Usercode].book[pp].outtime.year = 0;
					strcpy(history[hisnum].name,xinxi[Usercode].name);
		history[hisnum].year=nowtime.year;
		history[hisnum].month=nowtime.month;
		history[hisnum].day=nowtime.day;
		history[hisnum].hour=nowtime.hour;
		history[hisnum].min=nowtime.min;
		strcpy(history[hisnum].inorout,"in");
		history[hisnum].late=allbook[i].late;
		strcpy(history[hisnum].phone,xinxi[Usercode].phone);
		strcpy(history[hisnum].booknumber,allbook[i].booknumber);
		strcpy(history[hisnum].bookname,allbook[i].bookname);
		hisnum++;
			printf("\n\t\t\t\t\t\t\t\t*�黹�ɹ�*\n");
			HistoryWrite();
			printf("\n\t\t\t\t\t\t\t\t�Ƿ�黹�����鼮?(Y/N):");//�Ƿ�黹�����鼮
			gets(GetOptSTR);
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\t�Ƿ�黹�����鼮?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//���黹�����鼮
				UserOption();
	}
}

void BookSearch()/*��ѯͼ����Ϣ����*/
{
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>��������Ҫ��ѯ��ͼ������:"};
	char require[]={"֧��ģ����ѯ,��������ȷ��ͼ������"};
	char error[]={"*����* ͼ�����Ʋ����Ϲ淶"};
	char right[]={"*��ȷ* ������ת�������  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0;//count->�ؼ������Զ��ٸ�����,number->ĳ�鼮����
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//����ֵ������Ҫ
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t����ǰ���ʵ���:���Ʋ�ѯ����\n");
		printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          ��1�������鼮�ؼ���->");
		setColor(8);
		printf("��2���������鱾��Ϣ\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,20);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          ��1�������鼮�ؼ���->��2���������鱾��Ϣ\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//�ؼ�����Ƭ����
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//�����������������¼���ά����
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//�����ַ�����������
			{
				if (strstr(allbook[j].bookname, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//��������ҵ�
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//forѭ���ж��Ƿ��Ѿ���¼
				{
					if (strcmp(allbook[j].bookname, mohusearch[i]) == 0&&strcmp(allbook[j].author, author[i])==0&&strcmp(allbook[j].press,press[i])==0)
					{
						flag2 = 1;
						break;
					}
				}
				if (flag2 == 0)
				{
					strcpy(mohusearch[NO], allbook[j].bookname);
						strcpy(author[NO], allbook[j].author);
							strcpy(press[NO], allbook[j].press);
					NO++;
					count++;
				}
			}
		}
		if (count != 0)//����
		{
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t       ����� ");
			setColor(3);
			printf("������");
			setColor(15);
			printf("               ������ ��������              ������              ���ݲ������ɽ���\n\n");
			for (NO = 0; NO < count; NO++)//����ÿ��������Ӧ������
			{
				onecount=0;
				for (i = 0; i < BookNum; i++)
				{
					if (strcmp(mohusearch[NO], allbook[i].bookname) == 0&&strcmp(author[NO], allbook[i].author)==0&&strcmp(press[NO], allbook[i].press)==0)
					{
						
						flag = i;
						onecount++;
						if (allbook[i].inshelf == 'Y')
						number++;
					}
				}
				setCursorPosition(50,(24+2*NO));
				printf("%d",NO + 1);
				setCursorPosition(54,(24+2*NO));
				setColor(3);
				puts(allbook[flag].bookname);
				setColor(15);
				setCursorPosition(75,(24+2*NO));
				puts(allbook[flag].booktype);
				setCursorPosition(82,(24+2*NO));
				puts(allbook[flag].press);
				setCursorPosition(104,(24+2*NO));
				puts(allbook[flag].author);
				setCursorPosition(128,(24+2*NO));
				printf("%d",onecount);
				setCursorPosition(136,(24+2*NO));
				printf("%d",number);
				number = 0;
				printf("\n\n");
			}
			printf("\n\n\t\t\t\t\t      *��ѯ���*                                                                  ����ѯ��%d����Ϣ\n\n", count);
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t\t  �Ƿ��������?(Y/N):");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//����whileѭ��
				break;
		}
		else//û������鼮
		{
			system("cls");
			LogoOops();
			Tips(4);//δ��ѯ�������Ϣ
			printf("\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//����whileѭ��
				break;
		}
		/*��ʼ������*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//whileѭ������
}


void TypeSearch()/*��ѯͼ����Ϣ����*/
{
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>��������Ҫ��ѯ��ͼ������:"};
	char require[]={"֧��ģ����ѯ,��������ȷ��ͼ������"};
	char error[]={"*����* ͼ�����಻���Ϲ淶"};
	char right[]={"*��ȷ* ������ת�������  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0;//count->�ؼ������Զ��ٸ�����,number->ĳ�鼮����
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//����ֵ������Ҫ
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t����ǰ���ʵ���:�����ѯ����\n");
		printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          ��1�������鼮�ؼ���->");
		setColor(8);
		printf("��2���������鱾��Ϣ\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,8);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          ��1�������鼮�ؼ���->��2���������鱾��Ϣ\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//�ؼ�����Ƭ����
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//�����������������¼���ά����
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//�����ַ�����������
			{
				if (strstr(allbook[j].booktype, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//��������ҵ�
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//forѭ���ж��Ƿ��Ѿ���¼
				{
					if (strcmp(allbook[j].bookname, mohusearch[i]) == 0&&strcmp(allbook[j].author, author[i])==0&&strcmp(allbook[j].press,press[i])==0)
					{
						flag2 = 1;
						break;
					}
				}
				if (flag2 == 0)
				{
					strcpy(mohusearch[NO], allbook[j].bookname);
						strcpy(author[NO], allbook[j].author);
							strcpy(press[NO], allbook[j].press);
					NO++;
					count++;
				}
			}
		}
		if (count != 0)//����
		{
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t       ����� ������               ");
			setColor(3);
			printf("������ ");
			setColor(15);
			printf("��������              ������              ���ݲ������ɽ���\n\n");
			for (NO = 0; NO < count; NO++)//����ÿ��������Ӧ������
			{
				onecount=0;
				for (i = 0; i < BookNum; i++)
				{
					if (strcmp(mohusearch[NO], allbook[i].bookname) == 0&&strcmp(author[NO], allbook[i].author)==0&&strcmp(press[NO], allbook[i].press)==0)
					{
						
						flag = i;
						onecount++;
						if (allbook[i].inshelf == 'Y')
						number++;
					}
				}
				setCursorPosition(50,(24+2*NO));
				printf("%d",NO + 1);
				setCursorPosition(54,(24+2*NO));
				puts(allbook[flag].bookname);
				setCursorPosition(75,(24+2*NO));
				setColor(3);
				puts(allbook[flag].booktype);
				setColor(15);
				setCursorPosition(82,(24+2*NO));
				puts(allbook[flag].press);
				setCursorPosition(104,(24+2*NO));
				puts(allbook[flag].author);
				setCursorPosition(128,(24+2*NO));
				printf("%d",onecount);
				setCursorPosition(136,(24+2*NO));
				printf("%d",number);
				number = 0;
				printf("\n\n");
			}
			printf("\n\n\t\t\t\t\t      *��ѯ���*                                                                  ����ѯ��%d����Ϣ\n\n", count);
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t\t  �Ƿ��������?(Y/N):");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//����whileѭ��
				break;
		}
		else//û������鼮
		{
			system("cls");
			LogoOops();
			Tips(4);//δ��ѯ�������Ϣ
			printf("\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//����whileѭ��
				break;
		}
		/*��ʼ������*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//whileѭ������
}


void AuthorSearch()/*��ѯͼ����Ϣ����*/
{
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>��������Ҫ��ѯ��ͼ������:"};
	char require[]={"֧��ģ����ѯ,��������ȷ��ͼ������"};
	char error[]={"*����* ͼ�����߲����Ϲ淶"};
	char right[]={"*��ȷ* ������ת�������  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0;//count->�ؼ������Զ��ٸ�����,number->ĳ�鼮����
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//����ֵ������Ҫ
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t����ǰ���ʵ���:����ѯ����\n");
		printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          ��1�������鼮�ؼ���->");
		setColor(8);
		printf("��2���������鱾��Ϣ\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,20);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          ��1�������鼮�ؼ���->��2���������鱾��Ϣ\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//�ؼ�����Ƭ����
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//�����������������¼���ά����
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//�����ַ�����������
			{
				if (strstr(allbook[j].author, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//��������ҵ�
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//forѭ���ж��Ƿ��Ѿ���¼
				{
					if (strcmp(allbook[j].bookname, mohusearch[i]) == 0&&strcmp(allbook[j].author, author[i])==0&&strcmp(allbook[j].press,press[i])==0)
					{
						flag2 = 1;
						break;
					}
				}
				if (flag2 == 0)
				{
					strcpy(mohusearch[NO], allbook[j].bookname);
						strcpy(author[NO], allbook[j].author);
							strcpy(press[NO], allbook[j].press);
					NO++;
					count++;
				}
			}
		}
		if (count != 0)//����
		{
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t       ����� ������               ������ ��������              ");
			setColor(3);
			printf("������");
			setColor(15);
			printf("              ���ݲ������ɽ���\n\n");
			for (NO = 0; NO < count; NO++)//����ÿ��������Ӧ������
			{
				onecount=0;
				for (i = 0; i < BookNum; i++)
				{
					if (strcmp(mohusearch[NO], allbook[i].author) == 0&&strcmp(author[NO], allbook[i].author)==0&&strcmp(press[NO], allbook[i].press)==0)
					{
						
						flag = i;
						onecount++;
						if (allbook[i].inshelf == 'Y')
						number++;
					}
				}
				setCursorPosition(50,(24+2*NO));
				printf("%d",NO + 1);
				setCursorPosition(54,(24+2*NO));
				puts(allbook[flag].bookname);
				setCursorPosition(75,(24+2*NO));
				puts(allbook[flag].booktype);
				setCursorPosition(82,(24+2*NO));
				puts(allbook[flag].press);
				setCursorPosition(104,(24+2*NO));
				setColor(3);
				puts(allbook[flag].author);
				setColor(15);
				setCursorPosition(128,(24+2*NO));
				printf("%d",onecount);
				setCursorPosition(136,(24+2*NO));
				printf("%d",number);
				number = 0;
				printf("\n\n");
			}
			printf("\n\n\t\t\t\t\t      *��ѯ���*                                                                  ����ѯ��%d����Ϣ\n\n", count);
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t\t  �Ƿ��������?(Y/N):");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//����whileѭ��
				break;
		}
		else//û������鼮
		{
			system("cls");
			LogoOops();
			Tips(4);//δ��ѯ�������Ϣ
			printf("\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//����whileѭ��
				break;
		}
		/*��ʼ������*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//whileѭ������
}


void PressSearch()/*��ѯͼ����Ϣ����*/
{
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>��������Ҫ��ѯ��ͼ�������:"};
	char require[]={"֧��ģ����ѯ,��������ȷ��ͼ�������"};
	char error[]={"*����* ͼ������粻���Ϲ淶"};
	char right[]={"*��ȷ* ������ת�������  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0;//count->�ؼ������Զ��ٸ�����,number->ĳ�鼮����
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//����ֵ������Ҫ
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t����ǰ���ʵ���:�������ѯ����\n");
		printf("\t\t\t\t\t\t\t\t������������������������������������������������������������\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          ��1�������鼮�ؼ���->");
		setColor(8);
		printf("��2���������鱾��Ϣ\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,20);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          ��1�������鼮�ؼ���->��2���������鱾��Ϣ\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//�ؼ�����Ƭ����
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//�����������������¼���ά����
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//�����ַ�����������
			{
				if (strstr(allbook[j].press, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//��������ҵ�
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//forѭ���ж��Ƿ��Ѿ���¼
				{
					if (strcmp(allbook[j].bookname, mohusearch[i]) == 0&&strcmp(allbook[j].author, author[i])==0&&strcmp(allbook[j].press,press[i])==0)
					{
						flag2 = 1;
						break;
					}
				}
				if (flag2 == 0)
				{
					strcpy(mohusearch[NO], allbook[j].bookname);
						strcpy(author[NO], allbook[j].author);
							strcpy(press[NO], allbook[j].press);
					NO++;
					count++;
				}
			}
		}
		if (count != 0)//����
		{
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t       ����� ������               ������ ");
			setColor(3);
			printf("��������");
			setColor(15);
			printf("              ������              ���ݲ������ɽ���\n\n");
			for (NO = 0; NO < count; NO++)//����ÿ��������Ӧ������
			{
				onecount=0;
				for (i = 0; i < BookNum; i++)
				{
					if (strcmp(mohusearch[NO], allbook[i].press) == 0&&strcmp(author[NO], allbook[i].author)==0&&strcmp(press[NO], allbook[i].press)==0)
					{
						
						flag = i;
						onecount++;
						if (allbook[i].inshelf == 'Y')
						number++;
					}
				}
				setCursorPosition(50,(24+2*NO));
				printf("%d",NO + 1);
				setCursorPosition(54,(24+2*NO));
				puts(allbook[flag].bookname);
				setCursorPosition(75,(24+2*NO));
				puts(allbook[flag].booktype);
				setCursorPosition(82,(24+2*NO));
				setColor(3);
				puts(allbook[flag].press);
				setColor(15);
				setCursorPosition(104,(24+2*NO));
				puts(allbook[flag].author);
				setCursorPosition(128,(24+2*NO));
				printf("%d",onecount);
				setCursorPosition(136,(24+2*NO));
				printf("%d",number);
				number = 0;
				printf("\n\n");
			}
			printf("\n\n\t\t\t\t\t      *��ѯ���*                                                                  ����ѯ��%d����Ϣ\n\n", count);
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ������������������������������������������������������������������������������������������������\n");
			printf("\t\t\t\t\t\t  �Ƿ��������?(Y/N):");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//����whileѭ��
				break;
		}
		else//û������鼮
		{
			system("cls");
			LogoOops();
			Tips(4);//δ��ѯ�������Ϣ
			printf("\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\t�Ƿ��������?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//����whileѭ��
				break;
		}
		/*��ʼ������*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//whileѭ������
}

void SearchInterface()//�鼮�����μ�����
{
	while (1)
	{
		system("cls");
		system("color 0F");
		LogoBookSearch();
		SearchIntUI();
		gets(GetOptSTR);
		switch (GetOption(GetOptSTR))
		{
		case '1': BookSearch(); break;
		case '2': TypeSearch(); break;
		case '3': AuthorSearch(); break;
		case '4': PressSearch(); break;
		case '0': break;
		default:system("cls"); LogoOops(); Tips(3); break;
		}
		if (GetOption(GetOptSTR) == '0')
			break;
	}
	switch (TAG)
	{
	case 1:UserOption(); break;
	case 3:VisitorLogin(); break;
	}
}



void Timenow()//�������ڰѵ�ǰʱ��¼��ṹ�壬��ӡ��ǰʱ�䡣��������ڽ������Ӧ��ʲôʱ���顣

{
	struct tm * localtime(const time_t * timer);
	time_t timep;

	struct tm *p;

	time(&timep);

	p = gmtime(&timep);

	nowtime.year = 1900 + p->tm_year;
	nowtime.month = 1 + p->tm_mon;
	nowtime.day = p->tm_mday;
	nowtime.hour = 8 + p->tm_hour;
	nowtime.min = p->tm_min;
	nowtime.days = p->tm_yday;

	int temp1 = 0, temp2 = 0, temp3 = 0;
	int a = nowtime.year, b = nowtime.month, c = nowtime.day;
	temp1 = a;//��ݲ���
	if (b == 3 || b == 5 || b == 8 || b == 10)//�¸�����30��
	{
		if (c == 31)
		{
			temp2 = b + 2;//����31�ţ��·ݼ�2
			temp3 = 1;
		}
		else
		{
			temp2 = b + 1;
			temp3 = c;
		}
	}
	else if (b == 4 || b == 6 || b == 7 || b == 9 || b == 12)//�¸�����31��
	{
		temp2 = b + 1;
		if (temp2 > 12)
		{
			temp1++;
			temp2 = 1;
		}
		temp3 = c + 1;
	}
	else if (b == 2)
	{
		temp2 = b + 1;
		if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)//����
			temp3 = c + 31 - 29;
		else
			temp3 = c + 31 - 28;
	}
	else
	{
		if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)//����
		{
			if (c > 29)
			{
				temp2 = b + 2;
				temp3 = c + 31 - 29;
			}
			else
			{
				temp2 = b + 1;
				temp3 = c;
			}
		}
		else
		{
			if (c > 28)
			{
				temp2 = b + 2;
				temp3 = c + 31 - 28;
			}
			else
			{
				temp2 = b + 1;
				temp3 = c;
			}
		}
	}
	future.year = temp1;
	future.month = temp2;
	future.day = temp3;
	future.hour = nowtime.hour;
	future.min = nowtime.min;

	/* printf("������%d��", 1900 + p->tm_year);/*��ȡ��ǰ���,��1900��ʼ������Ҫ��1900*/

	/* printf("%d��", 1 + p->tm_mon);/*��ȡ��ǰ�·�,��Χ��0-11,����Ҫ��1*/

	/* printf("%d��", p->tm_mday);/*��ȡ��ǰ�·�����,��Χ��1-31*/

	/* printf("%dʱ", 8 + p->tm_hour);/*��ȡ��ǰʱ,�����ȡ������ʱ��,�պ����˸�Сʱ*/


	/* printf("%d��", p->tm_min); /*��ȡ��ǰ��*/

	/* printf("%d\n", p->tm_yday); /*�ӽ���1��1�������������������ΧΪ0-365*/
	 /*ע�����ز���Դ������*/
}


void BookInfIn()
{
	FILE *fcount5;
	if ((fcount5 = fopen("time.txt", "w")) == NULL)
	{
		printf("cannot open the file");
		exit(0);
	}
	fseek(fcount5, 0, SEEK_SET);
	fprintf(fcount5, "%d %d %d %d %d", nowtime.year, nowtime.month, nowtime.day, nowtime.hour, nowtime.min);
	fclose(fcount5);

	FILE *fcount2;
	char fileName2[256] = { 0 };
	sprintf(fileName2, "%d.%d.%d.%d.%dbook.txt", nowtime.year, nowtime.month, nowtime.day, nowtime.hour, nowtime.min);
	if ((fcount2 = fopen(fileName2, "w+")) == NULL)
	{
		printf("cannot open the file");
		exit(0);
	}

	for (int cao = 0; cao < BookNum; cao++)
	{
		fprintf(fcount2, "%s %s %c %c %d %d %d %d %d %d %d %d %d %d %s %s %s %s \n",
			allbook[cao].booknumber, allbook[cao].bookname,
			allbook[cao].inshelf, allbook[cao].late, allbook[cao].outtime.year,
			allbook[cao].outtime.month, allbook[cao].outtime.day, allbook[cao].outtime.hour,
			allbook[cao].outtime.min, allbook[cao].shouldback.year, allbook[cao].shouldback.month,
			allbook[cao].shouldback.day, allbook[cao].shouldback.hour, allbook[cao].shouldback.min,
			allbook[cao].who, allbook[cao].booktype,allbook[cao].author, allbook[cao].press);
	}
	fclose(fcount2);
}


void BookInfOut()
{
	int year, month, day, hour, min;
	FILE *fp3;
	if ((fp3 = fopen("time.txt", "r")) != NULL)
	{

		fscanf(fp3, "%d %d %d %d %d", &year, &month, &day, &hour, &min);
		fclose(fp3);
		char fileName[256] = { 0 },ch;
		sprintf(fileName, "%d.%d.%d.%d.%dbook.txt", year, month, day, hour, min);
		FILE *fp4;
	
			if ((fp4 = fopen(fileName, "r")) == NULL)
			{
				printf("cannot open file\n");
				exit(0);
			}
			else
			{
				ch=fgetc(fp4);
				if(ch!=EOF)
				{
					fp4 = fopen(fileName, "r");
				for (BookNum = 0; feof(fp4) == 0; BookNum++)
				{
					fscanf(fp4, "%s %s %c %c %d %d %d %d %d %d %d %d %d %d %s %s %s %s \n",
						&allbook[BookNum].booknumber, &allbook[BookNum].bookname,
						&allbook[BookNum].inshelf, &allbook[BookNum].late, &allbook[BookNum].outtime.year,
						&allbook[BookNum].outtime.month, &allbook[BookNum].outtime.day, &allbook[BookNum].outtime.hour,
						&allbook[BookNum].outtime.min, &allbook[BookNum].shouldback.year, &allbook[BookNum].shouldback.month,
						&allbook[BookNum].shouldback.day, &allbook[BookNum].shouldback.hour, &allbook[BookNum].shouldback.min,
						&allbook[BookNum].who, &allbook[BookNum].booktype,allbook[BookNum].author, allbook[BookNum].press);
				}
				}
			fclose(fp4);
			}
	}
}

void UserInformationIn()
{
	int gan = 0;
	FILE *fcount;
	if ((fcount = fopen("time.txt", "w")) == NULL)
	{
		printf("cannot open the file");
		exit(0);
	}
	fseek(fcount, 0, SEEK_SET);//��պ���
	fprintf(fcount, "%d %d %d %d %d", nowtime.year, nowtime.month, nowtime.day, nowtime.hour, nowtime.min);
	fclose(fcount);
	FILE *fcount1;
	char fileName1[256] = { 0 };
	sprintf(fileName1, "%d.%d.%d.%d.%duser.txt", nowtime.year, nowtime.month, nowtime.day, nowtime.hour, nowtime.min);
	if ((fcount1 = fopen(fileName1, "w+")) == NULL)
	{
		printf("cannot open the file");
		exit(0);
	}
	for (gan = 0; gan < UserNum; gan++)
	{
		fprintf(fcount1, "%s %s %s %d %d %d %d %d %d %d %s %s %d %d %d %d %d %d %d %d %d %d %d %d %s %s %d %d %d %d %d %d %d %d %d %d %d %d %s %s %d %d %d %d %d %d \n",
			xinxi[gan].name, xinxi[gan].password, xinxi[gan].phone, xinxi[gan].borrowingbook,
			xinxi[gan].book[0].outtime.year, xinxi[gan].book[0].outtime.month, xinxi[gan].book[0].outtime.day,
			xinxi[gan].book[0].outtime.hour, xinxi[gan].book[0].outtime.min, xinxi[gan].book[0].outtime.days,
			xinxi[gan].book[0].bookname, xinxi[gan].book[0].booknumber, xinxi[gan].book[0].shouldback.year,
			xinxi[gan].book[0].shouldback.month, xinxi[0].book[0].shouldback.day, xinxi[gan].book[0].shouldback.hour,
			xinxi[gan].book[0].shouldback.min, xinxi[gan].book[0].shouldback.days,
			xinxi[gan].book[1].outtime.year, xinxi[gan].book[1].outtime.month, xinxi[gan].book[1].outtime.day,
			xinxi[gan].book[1].outtime.hour, xinxi[gan].book[1].outtime.min, xinxi[gan].book[1].outtime.days,
			xinxi[gan].book[1].bookname, xinxi[gan].book[1].booknumber, xinxi[gan].book[1].shouldback.year,
			xinxi[gan].book[1].shouldback.month, xinxi[gan].book[1].shouldback.day, xinxi[gan].book[1].shouldback.hour,
			xinxi[gan].book[1].shouldback.min, xinxi[0].book[1].shouldback.days,
			xinxi[gan].book[2].outtime.year, xinxi[gan].book[2].outtime.month, xinxi[gan].book[2].outtime.day,
			xinxi[gan].book[2].outtime.hour, xinxi[gan].book[2].outtime.min, xinxi[gan].book[2].outtime.days,
			xinxi[gan].book[2].bookname, xinxi[gan].book[2].booknumber, xinxi[gan].book[2].shouldback.year,
			xinxi[gan].book[2].shouldback.month, xinxi[gan].book[2].shouldback.day, xinxi[gan].book[2].shouldback.hour,
			xinxi[gan].book[2].shouldback.min, xinxi[gan].book[2].shouldback.days);

	}
	fclose(fcount1);
}

void AdminBkSchInt1()
{
	int i=0;
	if(getch()!=0x1b)
	{
		system("cls");
		system("color 0f");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t      ����ǰ���ʵ���:����Ա�鼮��Ϣ����\n");
		printf("\t\t\t\t\t\t\t����������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t****************************************************************************\n");
		printf("\t\t\t\t\t\t\t����������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t  ����� ������               ������ ��������              ������\n\n");
		if(BookNum==0)
			printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tû���鼮�ڼ�!\n\n\n\n\n");
		for (i = 0; i < BookNum; i++)
		{
			setCursorPosition(61,(24+2*i));
			puts(allbook[i].booknumber);
			setCursorPosition(66,(24+2*i));
			puts(allbook[i].bookname);
			setCursorPosition(86,(24+2*i));
			puts(allbook[i].booktype);
			setCursorPosition(93,(24+2*i));
			puts(allbook[i].press);
			setCursorPosition(115,(24+2*i));
			puts(allbook[i].author);
		}
		setCursorPosition(0,26+2*i);
		printf("\t\t\t\t\t\t\t����������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t****************************************************************************\n");
		printf("\t\t\t\t\t\t\t����������������������������������������������������������������������������\n\n");
		printf("\t\t\t\t\t\t\t\t��������鿴������Ϣ,ESC������");
		AdminBkSchInt2();
	}
	else
		AdminOption();
}

void AdminBkSchInt2()
{
	int i=0;
	if(getch()!=0x1b)
	{
		system("cls");
		system("color 0f");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t      ����ǰ���ʵ���:����Ա�鼮��Ϣ����\n");
		printf("\t\t\t\t\t\t\t����������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t****************************************************************************\n");
		printf("\t\t\t\t\t\t\t����������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t  ����� ������                ���Ƿ��ڼ� ������ʱ��   ��Ӧ��ʱ��  ��������\n\n");
		if(BookNum==0)
			printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tû���鼮�ڼ�!\n\n\n\n\n");
		for (i = 0; i < BookNum; i++)
		{
			setCursorPosition(61,(24+2*i));
			puts(allbook[i].booknumber);
			setCursorPosition(66,(24+2*i));
			puts(allbook[i].bookname);
			setCursorPosition(92,(24+2*i));
			if(allbook[i].inshelf=='Y')
			{
				printf("��");
				setCursorPosition(110,(24+2*i));
				printf("���˽���");
			}
			else
			{
				printf("��");
				setCursorPosition(99,(24+2*i));
				printf("%d/%d/%d",allbook[i].outtime.year, allbook[i].outtime.month, allbook[i].outtime.day);
				setCursorPosition(112,(24+2*i));
				if(allbook[i].late=='Y')
					setColor(4);
				else
					setColor(10);
				printf("%d/%d/%d",allbook[i].shouldback.year, allbook[i].shouldback.month,allbook[i].shouldback.day);
				setColor(15);
				setCursorPosition(124,(24+2*i));
				puts(allbook[i].who);
			}
		}
		setCursorPosition(0,26+2*i);
		printf("\t\t\t\t\t\t\t����������������������������������������������������������������������������\n");
		printf("\t\t\t\t\t\t\t****************************************************************************\n");
		printf("\t\t\t\t\t\t\t����������������������������������������������������������������������������\n\n");
		printf("\t\t\t\t\t\t\t\t��������鿴�鼮��Ϣ,ESC������");
		AdminBkSchInt1();
	}
	else
		AdminOption();
}
void AdminBookSearch()
{
	int i=0;
	system("cls");
	system("color 0f");
	LogoBookSearch();
	printf("\t\t\t\t\t\t\t\t\t      ����ǰ���ʵ���:����Ա�鼮��Ϣ����\n");
	printf("\t\t\t\t\t\t\t����������������������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t****************************************************************************\n");
	printf("\t\t\t\t\t\t\t����������������������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t  ����� ������               ������ ��������              ������\n\n");
	if(BookNum==0)
		printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tû���鼮�ڼ�!\n\n\n\n\n");
	for (i = 0; i < BookNum; i++)
	{
		setCursorPosition(61,(24+2*i));
		puts(allbook[i].booknumber);
		setCursorPosition(66,(24+2*i));
		puts(allbook[i].bookname);
		setCursorPosition(86,(24+2*i));
		puts(allbook[i].booktype);
		setCursorPosition(93,(24+2*i));
		puts(allbook[i].press);
		setCursorPosition(115,(24+2*i));
		puts(allbook[i].author);
	}
	setCursorPosition(0,26+2*i);
	printf("\t\t\t\t\t\t\t����������������������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t\t****************************************************************************\n");
	printf("\t\t\t\t\t\t\t����������������������������������������������������������������������������\n\n");
	printf("\t\t\t\t\t\t\t\t��������鿴������Ϣ,ESC������");
	AdminBkSchInt2();
}


void HistoryRead()
{
	int i=0;
	char ch;
	FILE*fp9;
	if ((fp9 = fopen("history.txt", "a+")) == NULL)
	{
		printf("cannot open file.txt");
		exit(0);
	}
	else
	{
		ch=fgetc(fp9);
		if(ch!=EOF)
		{
			for (hisnum= 0; feof(fp9) == 0; hisnum++)//���ڴ����û�����ʷ��¼������ ���� ��� ʱ�� ������ �Ƿ����� ��ϵ�绰
			{
				fscanf(fp9, "%s %s %s %d %d %d %d %d %s %c %s \n",
					&history[hisnum].name, &history[hisnum].bookname, &history[hisnum].booknumber, &history[hisnum].year,
					&history[hisnum].month, &history[hisnum].day, &history[hisnum].hour, &history[hisnum].min
					, &history[hisnum].inorout, &history[hisnum].late, &history[hisnum].phone);	
			}
		}
		fclose(fp9);	
	}
}

void HistoryPrint()
{
	int i=0;
	system("cls");
	system("color 0f");
	LogoHistory();
	printf("\t\t\t\t\t\t\t\t\t\t����ǰ���ʵ���:��ʷ��Ϣ����\n");
	printf("\t\t\t\t\t\t    ������������������������������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t    ************************************************************************************\n");
	printf("\t\t\t\t\t\t    ������������������������������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t    ���û�����       ������          ����Ũ����/�黹��ʱ��          ���Ƿ�ʱ���û���ϵ�绰\n");
	if(hisnum==0)
		printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t������ʷ��Ϣ\n\n\n\n");
	for(i=0;i<hisnum;i++)
	{
		setCursorPosition(52,(24+2*i));
		puts(history[i].name);
		setCursorPosition(69,(24+2*i));
		puts(history[i].bookname);
		setCursorPosition(88,(24+2*i));
		puts(history[i].booknumber);
		setCursorPosition(94,(24+2*i));
		if(strcmp(history[i].inorout,"in"))
			puts("���");
		else
			puts("�黹");
		setCursorPosition(103,(24+2*i));
		printf("%d/%d/%d/%d/%d",history[i].year,history[i].month, history[i].day, history[i].hour, history[i].min);
		setCursorPosition(121,(24+2*i));
		if(history[i].late=='Y')
		{	
			setColor(4);
			puts("��");
			setColor(15);
		}
		else
			puts("��");
		setCursorPosition(130,(24+2*i));
		puts(history[i].phone);
		printf("\n\n");
	}
	printf("\t\t\t\t\t\t    ������������������������������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t    ************************************************************************************\n");
	printf("\t\t\t\t\t\t    ������������������������������������������������������������������������������������\n");
	printf("\t\t\t\t\t\t    ȷ���밴'Y'�������ϼ�:");
	gets(GetOptSTR);
	while(GetOption(GetOptSTR)!='Y')
	{
		system("cls");
		LogoOops();
		Tips(3);
		printf("\t\t\t\t\t\t\t\tȷ���밴'Y'�������ϼ�:");
		gets(GetOptSTR);
	}
	if(GetOption(GetOptSTR)=='Y')
		AdminOption();
}

void HistoryWrite()
{
	FILE*fp8;
	int i=0;
	if ((fp8 = fopen("history.txt", "w")) == NULL)
	{
		printf("�޷�����ʷ��¼�ļ�\n");
		exit(0);
	}
	for (i=0;i< hisnum ; i++)//���ڴ����û�����ʷ��¼������ ���� ��� ʱ�� ������ �Ƿ����� ��ϵ�绰
	{
		fprintf(fp8, "%s %s %s %d %d %d %d %d %s %c %s \n",
			history[i].name, history[i].bookname, history[i].booknumber, history[i].year,
			history[i].month, history[i].day, history[i].hour, history[i].min
			, history[i].inorout, history[i].late, history[i].phone);
	}
	fclose(fp8);
}

int main()
{
	Timenow();
	BookInfOut();
	LoadInfor();
	HistoryRead();
	LogoFlash(0);
	LogoGo(0);
	LoginInterface();	
	return 0;
}


int TimeCheck(int Usercode)/*�ж��Ƿ�ʱ*/
{
	if (xinxi[Usercode].book[0].shouldback.year < nowtime.year&&xinxi[Usercode].book[0].shouldback.year != 0)
	{
		system("cls");
		LogoOops();
		Tips(5);
		printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
		gets(GetOptSTR);//��ȡ�û�����
		while (GetOption(GetOptSTR) != 'Y')
		{
			system("cls");
			LogoOops();
			Tips(3);//��������
			printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'Y')//������һ��
		{
			system("cls");
			system("color 0f");
			LogoAdmin();
			UserOption();
		}
	}
	if (xinxi[Usercode].book[0].shouldback.year == nowtime.year)
	{
		if (xinxi[Usercode].book[0].shouldback.month < nowtime.month)
		{
			system("cls");
			LogoOops();
			Tips(5);
			printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y')
			{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'Y')//������һ��
			{
				system("cls");
				system("color 0f");
				LogoAdmin();
				UserOption();
			}
		}
		if (xinxi[Usercode].book[0].shouldback.month == nowtime.month&&xinxi[Usercode].book[0].shouldback.month != 0)
		{
			if (xinxi[Usercode].book[0].shouldback.day < nowtime.day)
			{
				system("cls");
				LogoOops();
				Tips(5);
				printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
				gets(GetOptSTR);//��ȡ�û�����
				while (GetOption(GetOptSTR) != 'Y')
				{
					system("cls");
					LogoOops();
					Tips(3);//��������
					printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'Y')//������һ��
				{
					system("cls");
					system("color 0f");
					LogoAdmin();
					UserOption();
				}
			}
		}
	}
	if (xinxi[Usercode].book[1].shouldback.year < nowtime.year&&xinxi[Usercode].book[1].shouldback.year != 0)
	{
		system("cls");
		LogoOops();
		Tips(5);
		printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
		gets(GetOptSTR);//��ȡ�û�����
		while (GetOption(GetOptSTR) != 'Y')
		{
			system("cls");
			LogoOops();
			Tips(3);//��������
			printf("\t\t\t\t\t\t\t\tȷ���밴Y������һ��:");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'Y')//������һ��
		{
			system("cls");
			system("color 0f");
			LogoAdmin();
			UserOption();
		}
	}
	if (xinxi[Usercode].book[1].shouldback.year == nowtime.year)
	{
		if (xinxi[Usercode].book[1].shouldback.month < nowtime.month)
		{
			system("cls");
			LogoOops();
			Tips(5);
			printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y')
			{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'Y')//������һ��
			{
				system("cls");
				system("color 0f");
				LogoAdmin();
				UserOption();
			}
		}
		if (xinxi[Usercode].book[1].shouldback.month == nowtime.month&&xinxi[Usercode].book[1].shouldback.month != 0)
		{
			if (xinxi[Usercode].book[1].shouldback.day < nowtime.day)
			{
				system("cls");
				LogoOops();
				Tips(5);
				printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
				gets(GetOptSTR);//��ȡ�û�����
				while (GetOption(GetOptSTR) != 'Y')
				{
					system("cls");
					LogoOops();
					Tips(3);//��������
					printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'Y')//������һ��
				{
					system("cls");
					system("color 0f");
					LogoAdmin();
					UserOption();
				}
			}
		}
	}
	if (xinxi[Usercode].book[2].shouldback.year < nowtime.year&&xinxi[Usercode].book[2].shouldback.year != 0)
	{
		system("cls");
		LogoOops();
		Tips(5);
		printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
		gets(GetOptSTR);//��ȡ�û�����
		while (GetOption(GetOptSTR) != 'Y')
		{
			system("cls");
			LogoOops();
			Tips(3);//��������
			printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'Y')//������һ��
		{
			system("cls");
			system("color 0f");
			LogoAdmin();
			UserOption();
		}
	}
	if (xinxi[Usercode].book[2].shouldback.year == nowtime.year)
	{
		if (xinxi[Usercode].book[2].shouldback.month < nowtime.month)
		{
			system("cls");
			LogoOops();
			Tips(5);
			printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
			gets(GetOptSTR);//��ȡ�û�����
			while (GetOption(GetOptSTR) != 'Y')
			{
				system("cls");
				LogoOops();
				Tips(3);//��������
				printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'Y')//������һ��
			{
				system("cls");
				system("color 0f");
				LogoAdmin();
				UserOption();
			}
		}
		if (xinxi[Usercode].book[2].shouldback.month == nowtime.month&&xinxi[Usercode].book[2].shouldback.month != 0)
		{
			if (xinxi[Usercode].book[2].shouldback.day < nowtime.day)
			{
				system("cls");
				LogoOops();
				Tips(5);
				printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
				gets(GetOptSTR);//��ȡ�û�����
				while (GetOption(GetOptSTR) != 'Y')
				{
					system("cls");
					LogoOops();
					Tips(3);//��������
					printf("\t\t\t\t\t\t\t\tȷ���밴'Y'������һ��:");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'Y')//������һ��
				{
					system("cls");
					system("color 0f");
					LogoAdmin();
					UserOption();
				}
			}
		}
	}
	return 0;
}

void IfLate()//�����ж��û��Ƿ�����δ�������ڵ����鼮��Ϣ֮��
{
	int i;
	for (i = 0; i < BookNum; i++)
	{
		if (allbook[i].shouldback.year < nowtime.year&&allbook[i].shouldback.year != 0)
			allbook[i].late = 'Y';
		if (allbook[i].shouldback.year == nowtime.year)
		{
			if (allbook[i].shouldback.month < nowtime.month)
				allbook[i].late = 'Y';
			if (allbook[i].shouldback.month == nowtime.month&&allbook[i].shouldback.month != 0)
				if (allbook[i].shouldback.day < nowtime.day)
					allbook[i].late = 'Y';
		}
	}
}

