// TX6.cpp : Defines the entry point for the console application.
//


/*——————————————————————————————————————————————————————————*/
/*                                                        头文件                                                      */
/*——————————————————————————————————————————————————————————*/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "stdlib.h"
#include <time.h>
#include "Logolib.cpp"
#include "LogoFlash.cpp"

/*——————————————————————————————————————————————————————————*/
/*                                                       函数声明                                                     */
/*——————————————————————————————————————————————————————————*/

void LoginInterface();//LoginInterfave()函数声明
void LoginInt2();//
void BookIn();
//Logo声明
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
/*——————————————————————————————————————————————————————————*/
/*                                                          结构体                                                    */
/*——————————————————————————————————————————————————————————*/

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

struct allbook//所有书
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

struct xinxi//普通用户账号
{
	char name[20];
	char password[20];
	char phone[20];
	struct booklend book[3];
	int borrowingbook;

}xinxi[100];

struct administrator//管理员账号
{
	char name[20];
	char password[20];
}
administrator = { {"1"},{"1"} };

/*——————————————————————————————————————————————————————————*/
/*                                                       全局变量                                                     */
/*——————————————————————————————————————————————————————————*/

static int UserNum = 0;//用户数量全局变量
static int BookNum = 0;//书籍数目全局变量
static char GetOptSTR[1000];//判定用户输入专用字符串
static int TAG = 0;//回弹标签，用户=1，管理员=2，游客=3；
static int Usercode;//锁定登录的用户的序号
static int hisnum=0;//全局历史记录条数

/*——————————————————————————————————————————————————————————*/
/*                                                         UI设计                                                     */
/*——————————————————————————————————————————————————————————*/
void LoginIntUI()//初始界面
{
	printf("\t\t\t\t\t\t\t\t\t\t    您当前访问的是:主界面\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t   欢迎使用TX6图书管理系统\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t1.用户注册\t   2.用户登录 \n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.退出\n\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t请选择操作:");
}

void AdminOptUI()
{
	printf("\t\t\t\t\t\t\t\t\t\t您当前访问的是:管理员选项界面\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.书籍入库\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2.书籍出库\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t3.书籍历史记录\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t4.书籍信息查询\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t5.书籍信息修改\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.退出登录\n\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t请选择操作:");
}

void UserOptUI()
{
	printf("\t\t\t\t\t\t\t\t\t\t您当前访问的是:普通用户选项界面\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.书籍查询\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2.书籍借阅\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t3.书籍归还\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t4.个人信息查询\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.退出登录\n\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t请选择操作:");
}

void VisitorLogUI()
{
	printf("\t\t\t\t\t\t\t\t\t\t 您当前访问的是:游客登录界面\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.书籍查询\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.返回 \n\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t请选择操作:");
}

void LoginInt2UI()
{
	printf("\t\t\t\t\t\t\t\t\t\t  您当前访问的是:登录界面\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.普通用户登录\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2.管理员登录\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t3.游客登录\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.返回\n\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t请选择操作:");
}

void SearchIntUI()
{
	printf("\t\t\t\t\t\t\t\t\t\t 您当前访问的是:书籍检索界面\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.名称查询\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2.种类查询\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t3.作者查询\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t4.出版社查询\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.返回\n\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t请选择操作:");
}


/*——————————————————————————————————————————————————————————*/
/*                                                    功能型函数                                                      */
/*——————————————————————————————————————————————————————————*/
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


int LengthLimit(char *str, int low, int up)//字符长度限定，不符合返回1，符合返回0
{
	int k = 0;
	if (strlen(str) < low || strlen(str) > up)
		k = 1;
	else
		k = 0;
	return k;
}

void setCursorPosition(int x, int y)//自定义的光标定位函数
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color)//自定义的文字颜色函数
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void CoverPlus(char *question, char *require, char *str, int x, int y)//密码遮盖函数增强版
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
			printf("                                  ");//清除require
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
	}//while循环结束
}
void Tips(int flag)//提示函数，0-注册成功！ 1-登陆成功！ 2-账号或密码错误！ 3-输入有误！请您重新输入 
				   //4-感谢您的使用！ 5-两次输入的密码不一致！是否继续输入:
{
	int i = 0;
	char tips[7][1000];
	strcpy(tips[0], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>!注册成功!<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[1], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>!登陆成功!<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[2], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>!账号或密码错误!<<<<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[3], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>!输入有误  请重新输入!<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[4], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>!未查询到相关信息!<<<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[5],	"\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>!有图书超时未还，无法继续借书!<<<<<<<<<<<<<<<\n");
	strcpy(tips[6], "感   谢   您   的   使   用   !\n");
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t——————————————————————————————\n\n\n");
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
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n"); Sleep(1000);
}

int CheckAlpha(char *str)//查看是否含有非数字，有返回1
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

void Initialize(char *str)//字符数组初始化
{
	int i = 0;
	for (i = 0; i < strlen(str); i++)
		str[i] = '\0';
}

char GetOption(char *str)//用户输入判定函数
{
	char k;
	if (strlen(str) != 1)
		k = 'E';
	else
		k = str[0];
	return k;
	Initialize(GetOptSTR);
}

int CheckNumber(int str)//用户输入是否为纯数字，若是将其转为纯数字
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







/*——————————————————————————————————————————————————————————*/
/*                                                    主要函数                                                        */
/*——————————————————————————————————————————————————————————*/

void LoadInfor()/*这部分用于把txt文件里的用户信息录入到程序缓存之中，用于接下来的用户名密码比较。需要放在前面*/
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
				for (UserNum = 0; feof(fp2) == 0; UserNum++)//用户结构体信息储存格式：姓名 密码 电话 在借书籍数量 第一本书的借出年 月 日 时 分 书名 书号 应还。。。 第二本，，， 
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

void Registe() /*注册*7.14更新完美版*/
{

	FILE*fp;
	char checkpassword[30];
	int i = 0, flag = 0;
	system("cls"); 
	system("color 0f");
	LogoRegist();
	printf("\t\t\t\t\t\t\t\t\t\t  您当前访问的是:注册界面\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n");
	setColor(15);
	printf("\t\t\t\t\t\t\t\t    【1】用户名->");
	setColor(8);
	printf("【2】密码->【3】确认密码->【4】手机号码    \n\n");
	setColor(15);
	while (1)
	{
		setCursorPosition(64, 22);
		printf(">>请设置您的用户名:");
		setColor(8);
		printf("长度不超过20位字符且不得含有空格");
		setCursorPosition(83, 22);
		setColor(15);
		do
		{
			xinxi[UserNum].name[i] = getch();
			xinxi[UserNum].name[i + 1] = '\0';
			setCursorPosition(64, 22);
			printf(">>请设置您的用户名:%s", xinxi[UserNum].name);
			printf("                                ");//清除require
			setCursorPosition((83 + i), 22);
			if (xinxi[UserNum].name[i] == '\r' || i > 20)
				break;
			if (xinxi[UserNum].name[i] == '\b')
			{
				if (i <= 1)
				{
					setCursorPosition(64, 22);
					printf(">>请设置您的用户名:");
					setColor(8);
					printf("长度不超过20位字符且不得含有空格");
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
		if (flag == 1)//重复限制
		{
			printf("\n\t\t\t\t\t\t\t\t  *错误* 用户名已存在!是否登录?(Y/N):");
			gets(GetOptSTR);
			while(GetOption(GetOptSTR)!='Y'&&GetOption(GetOptSTR)!='N')
			{
				system("cls");
				LogoOops();
				Tips(3);
				printf("\n\t\t\t\t\t\t\t\t用户名已存在!是否登录?(Y/N):");
				gets(GetOptSTR);
			}
			if(GetOption(GetOptSTR)=='Y')
				UserLogin();
			else
			{
				setCursorPosition(0,23);
				printf("\n\t\t\t\t\t\t\t\t  *错误* 用户名已存在!是否登录?(Y/N):  \n\n");
			}
		}
		else if (strlen(xinxi[UserNum].name) == 0 || strlen(xinxi[UserNum].name) > 20 || CheckString(xinxi[UserNum].name, ' '))//限制判断
			printf("\n\t\t\t\t\t\t\t\t  *错误* 用户名不符合规范!           \n\n");
		else
		{
			printf("\n\t\t\t\t\t\t\t\t  *正确*                             \n\n");
			break;
		}
		flag = 0;
		i = 0;
	}
	char question1[] = { ">>请设置您的密码:" };
	char question2[] = { ">>请确认您的密码:" };
	char require[] = { "长度不超过20位字符且不得含有空格" };
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
			printf("\t\t\t\t\t\t\t\t    【1】用户名->【2】密码->");
			setColor(8);
			printf("【3】确认密码->【4】手机号码    \n\n");
			setColor(15);
			setCursorPosition(81, 26);
			CoverPlus(question1, require, xinxi[UserNum].password, 64, 26);
			if (strlen(xinxi[UserNum].password) == 0 || strlen(xinxi[UserNum].password) > 20 || CheckString(xinxi[UserNum].password, ' '))//限制判断
			{
				printf("\n\t\t\t\t\t\t\t\t  *错误* 密码不符合规范！\n\n");
				setCursorPosition(64, 26);
				printf("%s", question1);
				setColor(8);
				printf("%s", require);
				setCursorPosition(64, 26);
				Initialize(xinxi[UserNum].password);
			}
			else
			{
				printf("\n\t\t\t\t\t\t\t\t  *正确*                 \n\n");
				break;
			}
		}
		setCursorPosition(64, 30);
		printf("%s%s", question2, require2);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t    【1】用户名->【2】密码->【3】确认密码->");
		setColor(8);
		printf("【4】手机号码    \n\n");
		setColor(15);
		setCursorPosition(81, 30);
		CoverPlus(question2, require2, checkpassword, 64, 30);
		if (strcmp(checkpassword, xinxi[UserNum].password) != 0)
		{
			printf("\n\t\t\t\t\t\t\t\t  *错误* 两次密码输入不一致！\n\n");
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
			printf("\n\t\t\t\t\t\t\t\t  *正确*                     \n\n");
			break;
		}
	}
	while (1)
	{
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t    【1】用户名->【2】密码->【3】确认密码->【4】手机号码    \n\n");
		setCursorPosition(0, 34);
		printf("\t\t\t\t\t\t\t\t>>请输入您的手机号码:");
		gets(xinxi[UserNum].phone);
		if (strlen(xinxi[UserNum].phone) != 11 || CheckAlpha(xinxi[UserNum].phone))
		{
			printf("\n\t\t\t\t\t\t\t\t  *错误* 请输入正确的手机号码！\n\n");
			setCursorPosition(0, 34);
			printf("\t\t\t\t\t\t\t\t>>请输入您的手机号码:%s", require2);
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
	LoginInterface();//注册成功后返回主界面	
}


void AdminOption()
{
	TAG = 2;//管理员界面
	while (1)
	{
		system("cls");
		system("color 0F");
		LogoAdmin();
		AdminOptUI();
		gets(GetOptSTR);//获取用户输入
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
	TAG = 1;//当前界面是用户界面
	while (1)
	{
		system("cls");
		system("color 0f");
		LogoUser();
		UserOptUI();
		gets(GetOptSTR);//获取用户输入
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

void UserLogin()/*普通用户登录部分,登录信息与缓存信息比较*/
{
	int i = 0,flag = 1;//登陆成功判断表示
	char name[20];
	char password[20];
	char question1[]={">>请输入您的密码:"};
	char require[]={"                                "};
	while (1)
	{
		system("cls");
		system("color 0F");
		LogoLogin();
		printf("\t\t\t\t\t\t\t\t\t\t您当前访问的是:普通用户登录界面  \n");
		printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t                   【1】用户名->");
		setColor(8);
		printf("【2】密码                    \n\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t>>请输入您的用户名:");
		gets(name);
		printf("\n\n");
		setColor(15);
		setCursorPosition(0,20);
		printf("\t\t\t\t\t\t\t\t                   【1】用户名->【2】密码                    \n\n\n");
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
		if (flag == 1)//用户登录失败
		{
			system("cls");
			LogoOops();
			Tips(2);
			printf("\t\t\t\t\t\t\t\t是否继续尝试登陆?(Y/N):");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);
				printf("\t\t\t\t\t\t\t\t是否继续尝试登陆?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')
				break;
		}

	}
	LoginInterface();//用户若不想继续登录则返回主界面
}


void VisitorLogin()//游客登录选项
{
	TAG = 3;//游客界面
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
			LogoVisitor();//游客Logo
			VisitorLogUI();
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == '1')
			SearchInterface();//书籍函数
		else
			LoginInt2();
	}
}

void AdminLogin()//管理员登录
{
	int i = 0;//自由变量，用于for
	char name[20];
	char password[20];
	char question1[]={">>请输入您的密码:"};
	char require[]={"                                "};
	while (1)
	{
		system("cls");
		system("color 0f");
		LogoLogin();
		printf("\t\t\t\t\t\t\t\t\t\t您当前访问的是:管理员登陆界面\n");
		printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t                   【1】用户名->");
		setColor(8);
		printf("【2】密码                    \n\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t>>请输入管理员帐号:");
		gets(name);
		printf("\n\n");
		setColor(15);
		setCursorPosition(0,20);
		printf("\t\t\t\t\t\t\t\t                   【1】用户名->【2】密码                    \n\n\n");
		setCursorPosition(64,26);
		printf("%s%s",question1,require);
		setCursorPosition(81,26);
		CoverPlus(question1,require,password,64,26);
		if ((strcmp(name, administrator.name) != 0) || (strcmp(password, administrator.password) != 0))//账号或密码不匹配
		{
			system("cls");
			LogoOops();
			Tips(2);
			printf("\t\t\t\t\t\t\t\t是否继续登陆?(Y/N):");
			gets(GetOptSTR);
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);
				printf("\t\t\t\t\t\t\t\t是否继续登陆?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')
				break;
		}
		else//登陆成功
		{
			system("cls");
			LogoLogin();
			Tips(1);
			AdminOption();
		}
	}
	LoginInterface();//用户若不想继续登录则返回主界面
}
void LoginInt2()/*选择管理员登录或用户登录或游客登录*/
{
	TAG = 0;//TAG初始化
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

void LoginInterface()//用户登录初始界面
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

void UserSearch()  /*用户信息查询部分*/
{
	char flag;
	system("cls");
	system("color 0f");
	LogoUserSearch();
	int line=0;
	printf("\t\t\t\t\t\t\t\t\t\t您当前访问的是:用户信息查询界面\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	printf("\t\t\t\t\t\t\t\t  ▼序号 ▼书名                    ▼借阅日期   ▼应还日期");
	if (xinxi[Usercode].book[0].outtime.year == 0)
	{
		printf("\n\n\t\t\t\t\t\t\t\t暂无您的借阅信息\n\n\n");
		printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
		printf("\t\t\t\t\t\t\t\t************************************************************\n");
		printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n\n");
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
			printf("\n\n\n\n\t\t\t\t\t\t\t\t暂无其他借阅信息");
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
				printf("\n\n\n\n\t\t\t\t\t\t\t\t暂无其他借阅信息");
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
		printf("\t\t\t     用户名: %s \n", xinxi[Usercode].name);
		printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
		printf("\t\t\t\t\t\t\t\t************************************************************\n");
		printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
	}
	line=0;
	printf("\t\t\t\t\t\t\t\t您还可以借阅 %d 本书\t\t\t是否借阅?(Y/N):", 3 - xinxi[Usercode].borrowingbook);
	gets(GetOptSTR);//获取用户输入
	while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
	{
		system("cls");
		LogoOops();
		Tips(3);//输入有误
		printf("\t\t\t\t\t\t\t\t是否借阅?(Y/N):");
		gets(GetOptSTR);
	}
	if (GetOption(GetOptSTR) == 'N')//不进行借阅
		UserOption();
	else//进行借阅
		BookLend();
}

void BookIn()/*图书入库部分*/
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
	char question1[]={">>请输入入库图书名称:"};
	char question2[]={">>请输入入库图书分类:"};
	char question3[]={">>请输入入库图书作者:"};
	char question4[]={">>请输入入库图书出版社:"};
	char require1[]={"不超过20个字符且不得含有空格"};
	char require2[]={"不超过8个字符且不得含有空格"};
	char error1[]={"*错误* 图书名称不符合规范"};
	char error2[]={"*错误* 图书分类不符合规范"};
	char error3[]={"*错误* 图书作者不符合规范"};
	char error4[]={"*错误* 图书出版社不符合规范"};
	char right0[]={"*正确*                   "};
	while (1)
	{
		system("cls");
		system("color 0f");
		LogoBookIn(); 
		printf("\t\t\t\t\t\t\t\t\t\t  您当前访问的是:书籍入库界面\n");
		printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t     【1】入库的图书名称->");
		setColor(8);
		printf("【2】书籍信息->【3】入库数量      \n\n\n");
		setColor(15);
		GetBookName(question1,require1,error1,right0,inbook.wantname,64,22,20);
		setCursorPosition(0,20);
		setColor(15);
		printf("\t\t\t\t\t\t\t\t     【1】入库的图书名称->【2】书籍信息->");
		setColor(8);
		printf("【3】入库数量      \n\n\n");
		setColor(15);
		GetBookName(question2,require2,error2,right0,inbook.booktype,64,26,8);
		GetBookName(question3,require1,error3,right0,inbook.author,64,30,20);
		GetBookName(question4,require1,error4,right0,inbook.press,64,34,20);
		setCursorPosition(0,20);
		setColor(15);
		printf("\t\t\t\t\t\t\t\t     【1】入库的图书名称->【2】书籍信息->【3】入库数量      \n\n\n");
		setCursorPosition(0,38);
		while (1)
		{
			printf("\t\t\t\t\t\t\t\t>>请输入入库图书数量:");
			gets(GetOptSTR);
			if (CheckAlpha(GetOptSTR))
				printf("\n\t\t\t\t\t\t\t\t*错误* 输入非法！\n\n");
			else
			{
				inbook.typenum = atol(GetOptSTR);
				Initialize(GetOptSTR);
				printf("\n\t\t\t\t\t\t\t\t*正确*\n\n");
				break;
			}
		}
		for (j = BookNum; j < BookNum + inbook.typenum; j++)
		{
			strcpy(allbook[j].bookname, inbook.wantname);
			strcpy(allbook[j].booktype, inbook.booktype);
			strcpy(allbook[j].author, inbook.author);
			strcpy(allbook[j].press, inbook.press);
			itoa(j + 1, allbook[j].booknumber, 10);/*将整数转换成字符串以实现自动编序*/
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
		printf("\t\t\t\t\t\t\t\t*入库完成*\n");
		printf("\n\t\t\t\t\t\t\t\t是否继续录入?(Y/N):");
		gets(GetOptSTR);//获取用户输入
		while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
		{
			system("cls");
			LogoOops();
			Tips(3);//输入有误
			printf("\t\t\t\t\t\t\t\t是否继续录入?(Y/N):");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'N')//打破while循环
			break;
	}
	AdminOption();//不继续
}

void BookOut()/*图书出库部分*/
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
			printf("\t\t\t\t\t\t\t\t\t\t  您当前访问的是:书籍出库界面\n");
			printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n");
			for(j=0;j<99;j++)
			{	strcpy(havebook[j].press,"\0");
				havebook[j].num=0;
			}
			setColor(15);
			printf("\t\t\t\t\t\t\t\t        【1】输入书籍具体名称->");
			setColor(8);
			printf("【2】进行出库操作\n\n\n");
			setColor(15);
			printf("\t\t\t\t\t\t\t\t>>请输入想要出库的图书名称:");
			gets(outbook);
			setCursorPosition(0,20);
			setColor(15);
			printf("\t\t\t\t\t\t\t\t        【1】输入书籍具体名称->【2】进行出库操作\n\n\n");
			setCursorPosition(0,24);
			printf("\n\t\t\t\t\t\t\t\t   正在跳转搜索结果");
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
				printf("\t\t\t\t\t\t\t\t是否重新输入?(Y/N):");
				gets(GetOptSTR);//获取用户输入
				while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
				{
					system("cls");
					LogoOops();
					Tips(3);//输入有误
					printf("\t\t\t\t\t\t\t\t是否重新输入?(Y/N):");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'N')//不重新输入
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
		printf("\t\t\t\t\t\t\t\t\t        您当前访问的是:书籍出库界面\n");
		printf("\t\t\t\t\t\t\t————————————————————————————————————————\n");
		printf("\t\t\t\t\t\t\t********************************************************************************\n");
		printf("\t\t\t\t\t\t\t————————————————————————————————————————\n");
		printf("\t\t\t\t\t\t\t ▼序号 ▼书名                         ▼出版社                      ▼在架数量\n\n");
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
		printf("\n\n\n\t\t\t\t\t\t\t————————————————————————————————————————\n");
		printf("\t\t\t\t\t\t\t********************************************************************************\n");
		printf("\t\t\t\t\t\t\t————————————————————————————————————————\n");
		while(1)
		{
			while(1)
			{
				printf("\n\t\t\t\t\t\t\t\t>>请输入要出库的图书序号:");
				gets(GetOptSTR);
				if (CheckAlpha(GetOptSTR))
					printf("\n\t\t\t\t\t\t\t\t*错误* 输入非法！\n");
				else
				{
					xuhao=atol(GetOptSTR);
					Initialize(GetOptSTR);
					break;
				}
			}
			if(xuhao>m)//输入非序号数字
				printf("\n\t\t\t\t\t\t\t\t*错误* 没有相匹配的书籍!\n");
			else if(havebook[xuhao-1].num==0)
				printf("\n\t\t\t\t\t\t\t\t*错误* 该书已被借阅,不能出库!\n");
			else
				break;
		}
		while (1)//可以出库
		{
			printf("\n\t\t\t\t\t\t\t\t>>请输入出库图书数量:");
			gets(GetOptSTR);
			if (CheckAlpha(GetOptSTR))
				printf("\n\t\t\t\t\t\t\t\t>>*错误* 输入非法！\n");
			else
			{
				typenum = atol(GetOptSTR);
				Initialize(GetOptSTR);
				if (typenum>havebook[xuhao-1].num)
				{
					printf("\n\t\t\t\t\t\t\t\t>>*错误* 输入出库数大于在架数,请重新输入!\n");
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
		printf("\n\t\t\t\t\t\t\t\t*图书出库完成*\n");
		for (i = 0; i < BookNum; i++)
			itoa(i + 1, allbook[i].booknumber, 10);
		printf("\n\t\t\t\t\t\t\t\t是否继续出库?(Y/N):");
		gets(GetOptSTR);//获取用户输入
		while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
		{
			system("cls");
			LogoOops();
			Tips(3);//输入有误
			printf("\t\t\t\t\t\t\t\t是否继续出库?(Y/N):");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'N')//打破while循环
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
			LogoBookAdjust();//书籍修改
			printf("\t\t\t\t\t\t\t\t\t      您当前访问的是:书籍信息修改界面\n");
			printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n");
			setColor(15);
			printf("\t\t\t\t\t\t\t\t        【1】输入书籍具体名称->");
			setColor(8);
			printf("【2】进行修改操作\n\n\n");
			setColor(15);
			printf("\t\t\t\t\t\t\t\t>>请输入想要修改的图书名称:");
			gets(wantname);
			setCursorPosition(0,20);
			setColor(15);
			printf("\t\t\t\t\t\t\t\t        【1】输入书籍具体名称->【2】进行修改操作\n\n\n");
			setCursorPosition(0,24);
			printf("\n\t\t\t\t\t\t\t\t   正在跳转搜索结果");
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
				printf("\t\t\t\t\t\t\t\t是否重新输入?(Y/N):");
				gets(GetOptSTR);//获取用户输入
				while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
				{
					system("cls");
					LogoOops();
					Tips(3);//输入有误
					printf("\t\t\t\t\t\t\t\t是否重新输入?(Y/N):");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'N')//不重新输入
					AdminOption();
			}
			else
			{	
				system("cls");
				system("color 0f");
				LogoBookAdjust();
				printf("\t\t\t\t\t\t\t\t\t      您当前访问的是:书籍信息修改界面\n");
				printf("\t\t\t\t\t\t    ————————————————————————————————————————————\n");
				printf("\t\t\t\t\t\t    ****************************************************************************************\n");
				printf("\t\t\t\t\t\t    ————————————————————————————————————————————\n");
				printf("\t\t\t\t\t\t      ▼序号 ▼书名             ▼分类 ▼出版社              ▼作者             ▼是否在架\n\n");
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
							printf("是");
						else
							printf("否");
						printf("\n\n");
					}
				}
				printf("\n\t\t\t\t\t\t    ————————————————————————————————————————————\n");
				printf("\t\t\t\t\t\t    ****************************************************************************************\n");
				printf("\t\t\t\t\t\t    ————————————————————————————————————————————\n");
				break;
			}
		}
		flag=0;
		while(1)
		{
			while (1)
			{
				printf("\t\t\t\t\t\t\t>>请输入需要修改的图书序号:");
				gets(GetOptSTR);
				if (CheckAlpha(GetOptSTR))
					printf("\n\t\t\t\t\t\t\t*错误* 输入非法！\n");
				else
				{
					number=atol(GetOptSTR);
					break;
				}
			}
			for(i=0;i<BookNum;i++)//判断是否有对应序号
			{
				if(strcmp(GetOptSTR,allbook[i].booknumber)==0&&strcmp(allbook[number-1].bookname,wantname)==0)
				{	
					flag++;
					break;
				}
			}
			if(flag==0)
				printf("\n\t\t\t\t\t\t\t*错误* 没有相匹配的书籍!\n");
			else if(allbook[number-1].inshelf=='N')
				printf("\n\t\t\t\t\t\t\t*错误* 该书已被借阅,不能修改信息!\n");
			else
			{
				printf("\n\t\t\t\t\t\t\t*正确*\n");
				flag=0;
				printf("\n\t\t\t\t\t\t\t>>请重新录入书籍信息\n");
				printf("\n\t\t\t\t\t\t\t>>请输入图书名称:");
				gets(allbook[number-1].bookname);
				printf("\n\t\t\t\t\t\t\t>>请输入图书分类:");
				gets(allbook[number-1].booktype);
				printf("\n\t\t\t\t\t\t\t>>请输入图书出版社:");
				gets(allbook[number-1].press);
				printf("\n\t\t\t\t\t\t\t>>请输入图书作者:");
				gets(allbook[number-1].author);
				printf("\n\t\t\t\t\t\t\t*修改完成!*\n");
			}
			printf("\n\t\t\t\t\t\t\t是否继续修改其他图书信息?(Y/N):");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{	
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t是否继续修改其他图书信息?(Y/N):");
				gets(GetOptSTR);
			}	
			if (GetOption(GetOptSTR) == 'N')//不进行修改
				AdminOption();
			else
				break;	
		}//下while循环结束
	}//总while循环结束
}

void BookLend()/*用户图书借阅部分*/
{	int flagx[100];
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>请输入想要查询的图书名称:"};
	char require[]={"支持模糊查询,请输入正确的图书名称"};
	char error[]={"*错误* 图书名称不符合规范"};
	char right[]={"*正确* 正在跳转搜索结果  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0,typenum=0;//count->关键词所对多少个书名,number->某书籍数量
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//赋初值，很重要
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t您当前访问的是:名称查询界面\n");
		printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          【1】输入书籍关键词->");
		setColor(8);
		printf("【2】输出相关书本信息\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,20);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          【1】输入书籍关键词->【2】输出相关书本信息\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//关键词切片储存
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//将包含搜索项的书名录入二维数组
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//所有字符都检测出来了
			{
				if (strstr(allbook[j].bookname, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//在书库中找到
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//for循环判断是否已经记录
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
		if (count != 0)//有书
		{
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t       ▼序号 ▼书名               ▼分类 ▼出版社              ▼作者              ▼馆藏数▼可借数\n\n");
			for (NO = 0; NO < count; NO++)//查找每个书名对应几本书
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
			printf("\n\n\t\t\t\t\t      *查询完成*                                                                  共查询到%d条信息\n\n", count);
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t\t是否有您想要借阅的书籍?(Y/N):");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				printf("\n\t\t\t\t\t\t*错误* 输入非法!\n");
				printf("\n\t\t\t\t\t\t是否有您想要借阅的书籍?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//打破while循环
				break;
		}
		else//没有相关书籍
		{
			system("cls");
			LogoOops();
			Tips(4);//未查询到相关信息
			printf("\t\t\t\t\t\t\t\t是否继续借阅其他书籍?(Y/N):");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t是否继续借阅其他书籍?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//打破while循环
				break;
		}
		while (1)
		{
			flag=0;
			printf("\n\t\t\t\t\t\t>>请输入您想借阅的书籍序号:");
			gets(GetOptSTR);
			if (CheckAlpha(GetOptSTR))
				printf("\n\t\t\t\t\t\t*错误* 输入非法!\n");
			else
			{
				typenum = atol(GetOptSTR);
				for(i=0;i<BookNum;i++)//判断是否有对应序号
				{
					if(strcmp(GetOptSTR,allbook[i].booknumber)==0)
					{	
						flag++;
						break;
					}
				}	
				if (flag==0)
					printf("\n\t\t\t\t\t\t*错误* 没有相匹配的书籍!\n");
				else
				{
					Initialize(GetOptSTR);
					if(allbook[typenum].inshelf=='N')
					{
						printf("\n\t\t\t\t\t\t*错误* 该书已被借阅!\n");
						printf("\n\t\t\t\t\t\t是否继续借阅其他书籍?(Y/N):");
						gets(GetOptSTR);//获取用户输入
						while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
						{
							system("cls");
							LogoOops();
							Tips(3);//输入有误
							printf("\t\t\t\t\t\t\t\t是否继续借阅其他书籍?(Y/N):");
							gets(GetOptSTR);
						}
						if (GetOption(GetOptSTR) == 'N')//打破while循环
							break;
						else 
							continue;
					}
					if(allbook[typenum].inshelf=='Y')
						break;
				}
			}
		}
		BookBorrowBottom(flagx[typenum-1]);//借阅成功标志
		HistoryWrite();
		flag = 0;
		number = 0;
		printf("\n\t\t\t\t\t\t是否继续借阅其他书籍?(Y/N):");//是否借阅其他书籍
		gets(GetOptSTR);
		while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
		{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t是否继续借阅其他书籍?(Y/N):");
				gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'N')//不借阅其他书籍
			UserOption();
		else//继续借阅其他书籍
			continue;
		/*初始化数据*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//while循环结束
}

void BookBorrowBottom(int number)//借书按钮按下后发生的事情
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
		printf("\n\t\t\t\t\t\t\t\t  *借阅成功*\n\n");

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

		printf("\n\t\t\t\t\t\t  *借阅成功*\n");
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

		printf("\n\t\t\t\t\t\t\t\t  *借阅成功*\n\n");
	}
	else
		printf("\n\n\t\t\t\t\t\t\t\t您已经借了3本书了，您已不可以再借书!\n");
}
void BookReturn()//用户按还书按钮之后的界面
{
	char wantnum[40];
	int op,pp,line=0,i=0;
	while (1)
	{
			system("cls");
			system("color 0f");
			LogoBookReturn();
			printf("\t\t\t\t\t\t\t\t\t\t  您当前访问的是:书籍归还界面\n");
			printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
			printf("\t\t\t\t\t\t\t\t************************************************************\n");
			printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
			printf("\t\t\t\t\t\t\t\t  ▼序号 ▼书名                    ▼借阅日期   ▼应还日期");
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
				printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t     您没有需要归还的书籍!\n");
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t用户名: %s \n", xinxi[Usercode].name);
				printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
				printf("\t\t\t\t\t\t\t\t************************************************************\n");
				printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
				printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上级:");
				gets(GetOptSTR);
				while (GetOption(GetOptSTR) != 'Y')
				{
					system("cls");
					LogoOops();
					Tips(3);//输入有误
					printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上级:");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'Y')//不归还其他书籍
					UserOption();
			}
			line=0;
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t用户名: %s \n", xinxi[Usercode].name);
			printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
			printf("\t\t\t\t\t\t\t\t************************************************************\n");
			printf("\t\t\t\t\t\t\t\t——————————————————————————————\n");
			while(1)
			{
				printf("\n\t\t\t\t\t\t\t\t>>请输入归还图书的序号:");
				gets(GetOptSTR);
				if (CheckAlpha(GetOptSTR))
					printf("\n\t\t\t\t\t\t\t\t*错误* 输入非法!\n");
				else
				{
					op = atol(GetOptSTR);
					pp=op-1;
					Initialize(GetOptSTR);
					strcpy(wantnum, xinxi[Usercode].book[op - 1].booknumber);
					if (strcmp(wantnum, "/") == 0 ||(op != 1&&op != 2&&op != 3))//还书输入错误
						printf("\n\t\t\t\t\t\t\t\t*错误* 没有与序号匹配的书籍!\n");
					else
					{
						printf("\n\t\t\t\t\t\t\t\t确定要归还 %d %s 吗?(Y/N):",op,xinxi[Usercode].book[pp].bookname);
						gets(GetOptSTR);
						while(GetOption(GetOptSTR)!='Y'&&GetOption(GetOptSTR)!='N')
						{
							system("cls");
							LogoOops();
							Tips(3);
							printf("\t\t\t\t\t\t\t\t确定要归还 %d %s 吗?(Y/N):",op,xinxi[Usercode].book[pp].bookname);
							gets(GetOptSTR);
						}
						if(GetOption(GetOptSTR)=='N')
						{
							printf("\n\t\t\t\t\t\t\t\t是否归还其他书籍?(Y/N):");//是否归还其他书籍
							gets(GetOptSTR);
							while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
							{
								system("cls");
								LogoOops();
								Tips(3);//输入有误
								printf("\t\t\t\t\t\t\t\t是否归还其他书籍?(Y/N):");
								gets(GetOptSTR);
							}
								if (GetOption(GetOptSTR) == 'N')//不归还其他书籍
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
			printf("\n\t\t\t\t\t\t\t\t*归还成功*\n");
			HistoryWrite();
			printf("\n\t\t\t\t\t\t\t\t是否归还其他书籍?(Y/N):");//是否归还其他书籍
			gets(GetOptSTR);
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t是否归还其他书籍?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//不归还其他书籍
				UserOption();
	}
}

void BookSearch()/*查询图书信息部分*/
{
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>请输入想要查询的图书名称:"};
	char require[]={"支持模糊查询,请输入正确的图书名称"};
	char error[]={"*错误* 图书名称不符合规范"};
	char right[]={"*正确* 正在跳转搜索结果  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0;//count->关键词所对多少个书名,number->某书籍数量
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//赋初值，很重要
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t您当前访问的是:名称查询界面\n");
		printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          【1】输入书籍关键词->");
		setColor(8);
		printf("【2】输出相关书本信息\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,20);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          【1】输入书籍关键词->【2】输出相关书本信息\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//关键词切片储存
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//将包含搜索项的书名录入二维数组
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//所有字符都检测出来了
			{
				if (strstr(allbook[j].bookname, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//在书库中找到
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//for循环判断是否已经记录
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
		if (count != 0)//有书
		{
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t       ▼序号 ");
			setColor(3);
			printf("▼书名");
			setColor(15);
			printf("               ▼分类 ▼出版社              ▼作者              ▼馆藏数▼可借数\n\n");
			for (NO = 0; NO < count; NO++)//查找每个书名对应几本书
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
			printf("\n\n\t\t\t\t\t      *查询完成*                                                                  共查询到%d条信息\n\n", count);
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t\t  是否继续搜索?(Y/N):");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t是否继续搜索?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//打破while循环
				break;
		}
		else//没有相关书籍
		{
			system("cls");
			LogoOops();
			Tips(4);//未查询到相关信息
			printf("\t\t\t\t\t\t\t\t是否继续搜索?(Y/N):");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t是否继续搜索?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//打破while循环
				break;
		}
		/*初始化数据*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//while循环结束
}


void TypeSearch()/*查询图书信息部分*/
{
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>请输入想要查询的图书种类:"};
	char require[]={"支持模糊查询,请输入正确的图书种类"};
	char error[]={"*错误* 图书种类不符合规范"};
	char right[]={"*正确* 正在跳转搜索结果  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0;//count->关键词所对多少个书名,number->某书籍数量
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//赋初值，很重要
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t您当前访问的是:种类查询界面\n");
		printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          【1】输入书籍关键词->");
		setColor(8);
		printf("【2】输出相关书本信息\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,8);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          【1】输入书籍关键词->【2】输出相关书本信息\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//关键词切片储存
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//将包含搜索项的书名录入二维数组
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//所有字符都检测出来了
			{
				if (strstr(allbook[j].booktype, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//在书库中找到
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//for循环判断是否已经记录
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
		if (count != 0)//有书
		{
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t       ▼序号 ▼书名               ");
			setColor(3);
			printf("▼分类 ");
			setColor(15);
			printf("▼出版社              ▼作者              ▼馆藏数▼可借数\n\n");
			for (NO = 0; NO < count; NO++)//查找每个书名对应几本书
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
			printf("\n\n\t\t\t\t\t      *查询完成*                                                                  共查询到%d条信息\n\n", count);
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t\t  是否继续搜索?(Y/N):");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t是否继续搜索?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//打破while循环
				break;
		}
		else//没有相关书籍
		{
			system("cls");
			LogoOops();
			Tips(4);//未查询到相关信息
			printf("\t\t\t\t\t\t\t\t是否继续搜索?(Y/N):");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t是否继续搜索?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//打破while循环
				break;
		}
		/*初始化数据*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//while循环结束
}


void AuthorSearch()/*查询图书信息部分*/
{
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>请输入想要查询的图书作者:"};
	char require[]={"支持模糊查询,请输入正确的图书作者"};
	char error[]={"*错误* 图书作者不符合规范"};
	char right[]={"*正确* 正在跳转搜索结果  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0;//count->关键词所对多少个书名,number->某书籍数量
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//赋初值，很重要
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t您当前访问的是:作者询界面\n");
		printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          【1】输入书籍关键词->");
		setColor(8);
		printf("【2】输出相关书本信息\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,20);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          【1】输入书籍关键词->【2】输出相关书本信息\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//关键词切片储存
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//将包含搜索项的书名录入二维数组
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//所有字符都检测出来了
			{
				if (strstr(allbook[j].author, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//在书库中找到
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//for循环判断是否已经记录
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
		if (count != 0)//有书
		{
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t       ▼序号 ▼书名               ▼分类 ▼出版社              ");
			setColor(3);
			printf("▼作者");
			setColor(15);
			printf("              ▼馆藏数▼可借数\n\n");
			for (NO = 0; NO < count; NO++)//查找每个书名对应几本书
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
			printf("\n\n\t\t\t\t\t      *查询完成*                                                                  共查询到%d条信息\n\n", count);
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t\t  是否继续搜索?(Y/N):");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t是否继续搜索?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//打破while循环
				break;
		}
		else//没有相关书籍
		{
			system("cls");
			LogoOops();
			Tips(4);//未查询到相关信息
			printf("\t\t\t\t\t\t\t\t是否继续搜索?(Y/N):");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t是否继续搜索?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//打破while循环
				break;
		}
		/*初始化数据*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//while循环结束
}


void PressSearch()/*查询图书信息部分*/
{
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>请输入想要查询的图书出版社:"};
	char require[]={"支持模糊查询,请输入正确的图书出版社"};
	char error[]={"*错误* 图书出版社不符合规范"};
	char right[]={"*正确* 正在跳转搜索结果  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0;//count->关键词所对多少个书名,number->某书籍数量
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//赋初值，很重要
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t您当前访问的是:出版社查询界面\n");
		printf("\t\t\t\t\t\t\t\t——————————————————————————————\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          【1】输入书籍关键词->");
		setColor(8);
		printf("【2】输出相关书本信息\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,20);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          【1】输入书籍关键词->【2】输出相关书本信息\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//关键词切片储存
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//将包含搜索项的书名录入二维数组
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//所有字符都检测出来了
			{
				if (strstr(allbook[j].press, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//在书库中找到
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//for循环判断是否已经记录
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
		if (count != 0)//有书
		{
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t       ▼序号 ▼书名               ▼分类 ");
			setColor(3);
			printf("▼出版社");
			setColor(15);
			printf("              ▼作者              ▼馆藏数▼可借数\n\n");
			for (NO = 0; NO < count; NO++)//查找每个书名对应几本书
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
			printf("\n\n\t\t\t\t\t      *查询完成*                                                                  共查询到%d条信息\n\n", count);
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ————————————————————————————————————————————————\n");
			printf("\t\t\t\t\t\t  是否继续搜索?(Y/N):");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t是否继续搜索?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//打破while循环
				break;
		}
		else//没有相关书籍
		{
			system("cls");
			LogoOops();
			Tips(4);//未查询到相关信息
			printf("\t\t\t\t\t\t\t\t是否继续搜索?(Y/N):");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t是否继续搜索?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//打破while循环
				break;
		}
		/*初始化数据*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//while循环结束
}

void SearchInterface()//书籍搜索次级界面
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



void Timenow()//！！用于把当前时间录入结构体，打印当前时间。计算出先在借书的人应该什么时候还书。

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
	temp1 = a;//年份不变
	if (b == 3 || b == 5 || b == 8 || b == 10)//下个月有30天
	{
		if (c == 31)
		{
			temp2 = b + 2;//当月31号，月份加2
			temp3 = 1;
		}
		else
		{
			temp2 = b + 1;
			temp3 = c;
		}
	}
	else if (b == 4 || b == 6 || b == 7 || b == 9 || b == 12)//下个月有31天
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
		if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)//闰年
			temp3 = c + 31 - 29;
		else
			temp3 = c + 31 - 28;
	}
	else
	{
		if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)//闰年
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

	/* printf("现在是%d年", 1900 + p->tm_year);/*获取当前年份,从1900开始，所以要加1900*/

	/* printf("%d月", 1 + p->tm_mon);/*获取当前月份,范围是0-11,所以要加1*/

	/* printf("%d日", p->tm_mday);/*获取当前月份日数,范围是1-31*/

	/* printf("%d时", 8 + p->tm_hour);/*获取当前时,这里获取西方的时间,刚好相差八个小时*/


	/* printf("%d分", p->tm_min); /*获取当前分*/

	/* printf("%d\n", p->tm_yday); /*从今年1月1日算起至今的天数，范围为0-365*/
	 /*注：次素材来源于网络*/
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
	fseek(fcount, 0, SEEK_SET);//清空函数
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
		printf("\t\t\t\t\t\t\t\t\t      您当前访问的是:管理员书籍信息界面\n");
		printf("\t\t\t\t\t\t\t——————————————————————————————————————\n");
		printf("\t\t\t\t\t\t\t****************************************************************************\n");
		printf("\t\t\t\t\t\t\t——————————————————————————————————————\n");
		printf("\t\t\t\t\t\t\t  ▼序号 ▼书名               ▼分类 ▼出版社              ▼作者\n\n");
		if(BookNum==0)
			printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t没有书籍在架!\n\n\n\n\n");
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
		printf("\t\t\t\t\t\t\t——————————————————————————————————————\n");
		printf("\t\t\t\t\t\t\t****************************************************************************\n");
		printf("\t\t\t\t\t\t\t——————————————————————————————————————\n\n");
		printf("\t\t\t\t\t\t\t\t按任意键查看借阅信息,ESC键返回");
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
		printf("\t\t\t\t\t\t\t\t\t      您当前访问的是:管理员书籍信息界面\n");
		printf("\t\t\t\t\t\t\t——————————————————————————————————————\n");
		printf("\t\t\t\t\t\t\t****************************************************************************\n");
		printf("\t\t\t\t\t\t\t——————————————————————————————————————\n");
		printf("\t\t\t\t\t\t\t  ▼序号 ▼书名                ▼是否在架 ▼借阅时间   ▼应还时间  ▼借书人\n\n");
		if(BookNum==0)
			printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t没有书籍在架!\n\n\n\n\n");
		for (i = 0; i < BookNum; i++)
		{
			setCursorPosition(61,(24+2*i));
			puts(allbook[i].booknumber);
			setCursorPosition(66,(24+2*i));
			puts(allbook[i].bookname);
			setCursorPosition(92,(24+2*i));
			if(allbook[i].inshelf=='Y')
			{
				printf("是");
				setCursorPosition(110,(24+2*i));
				printf("无人借阅");
			}
			else
			{
				printf("否");
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
		printf("\t\t\t\t\t\t\t——————————————————————————————————————\n");
		printf("\t\t\t\t\t\t\t****************************************************************************\n");
		printf("\t\t\t\t\t\t\t——————————————————————————————————————\n\n");
		printf("\t\t\t\t\t\t\t\t按任意键查看书籍信息,ESC键返回");
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
	printf("\t\t\t\t\t\t\t\t\t      您当前访问的是:管理员书籍信息界面\n");
	printf("\t\t\t\t\t\t\t——————————————————————————————————————\n");
	printf("\t\t\t\t\t\t\t****************************************************************************\n");
	printf("\t\t\t\t\t\t\t——————————————————————————————————————\n");
	printf("\t\t\t\t\t\t\t  ▼序号 ▼书名               ▼分类 ▼出版社              ▼作者\n\n");
	if(BookNum==0)
		printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t没有书籍在架!\n\n\n\n\n");
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
	printf("\t\t\t\t\t\t\t——————————————————————————————————————\n");
	printf("\t\t\t\t\t\t\t****************************************************************************\n");
	printf("\t\t\t\t\t\t\t——————————————————————————————————————\n\n");
	printf("\t\t\t\t\t\t\t\t按任意键查看借阅信息,ESC键返回");
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
			for (hisnum= 0; feof(fp9) == 0; hisnum++)//用于储存用户的历史记录。人名 书名 书号 时间 出或入 是否逾期 联系电话
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
	printf("\t\t\t\t\t\t\t\t\t\t您当前访问的是:历史信息界面\n");
	printf("\t\t\t\t\t\t    ——————————————————————————————————————————\n");
	printf("\t\t\t\t\t\t    ************************************************************************************\n");
	printf("\t\t\t\t\t\t    ——————————————————————————————————————————\n");
	printf("\t\t\t\t\t\t    ▼用户姓名       ▼书名          ▼书号▼借出/归还▼时间          ▼是否超时▼用户联系电话\n");
	if(hisnum==0)
		printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t暂无历史信息\n\n\n\n");
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
			puts("借出");
		else
			puts("归还");
		setCursorPosition(103,(24+2*i));
		printf("%d/%d/%d/%d/%d",history[i].year,history[i].month, history[i].day, history[i].hour, history[i].min);
		setCursorPosition(121,(24+2*i));
		if(history[i].late=='Y')
		{	
			setColor(4);
			puts("是");
			setColor(15);
		}
		else
			puts("否");
		setCursorPosition(130,(24+2*i));
		puts(history[i].phone);
		printf("\n\n");
	}
	printf("\t\t\t\t\t\t    ——————————————————————————————————————————\n");
	printf("\t\t\t\t\t\t    ************************************************************************************\n");
	printf("\t\t\t\t\t\t    ——————————————————————————————————————————\n");
	printf("\t\t\t\t\t\t    确认请按'Y'键返回上级:");
	gets(GetOptSTR);
	while(GetOption(GetOptSTR)!='Y')
	{
		system("cls");
		LogoOops();
		Tips(3);
		printf("\t\t\t\t\t\t\t\t确认请按'Y'键返回上级:");
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
		printf("无法打开历史记录文件\n");
		exit(0);
	}
	for (i=0;i< hisnum ; i++)//用于储存用户的历史记录。人名 书名 书号 时间 出或入 是否逾期 联系电话
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


int TimeCheck(int Usercode)/*判断是否超时*/
{
	if (xinxi[Usercode].book[0].shouldback.year < nowtime.year&&xinxi[Usercode].book[0].shouldback.year != 0)
	{
		system("cls");
		LogoOops();
		Tips(5);
		printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
		gets(GetOptSTR);//获取用户输入
		while (GetOption(GetOptSTR) != 'Y')
		{
			system("cls");
			LogoOops();
			Tips(3);//输入有误
			printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'Y')//返回上一级
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
			printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y')
			{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'Y')//返回上一级
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
				printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
				gets(GetOptSTR);//获取用户输入
				while (GetOption(GetOptSTR) != 'Y')
				{
					system("cls");
					LogoOops();
					Tips(3);//输入有误
					printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'Y')//返回上一级
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
		printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
		gets(GetOptSTR);//获取用户输入
		while (GetOption(GetOptSTR) != 'Y')
		{
			system("cls");
			LogoOops();
			Tips(3);//输入有误
			printf("\t\t\t\t\t\t\t\t确认请按Y返回上一级:");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'Y')//返回上一级
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
			printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y')
			{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'Y')//返回上一级
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
				printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
				gets(GetOptSTR);//获取用户输入
				while (GetOption(GetOptSTR) != 'Y')
				{
					system("cls");
					LogoOops();
					Tips(3);//输入有误
					printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'Y')//返回上一级
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
		printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
		gets(GetOptSTR);//获取用户输入
		while (GetOption(GetOptSTR) != 'Y')
		{
			system("cls");
			LogoOops();
			Tips(3);//输入有误
			printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'Y')//返回上一级
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
			printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
			gets(GetOptSTR);//获取用户输入
			while (GetOption(GetOptSTR) != 'Y')
			{
				system("cls");
				LogoOops();
				Tips(3);//输入有误
				printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'Y')//返回上一级
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
				printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
				gets(GetOptSTR);//获取用户输入
				while (GetOption(GetOptSTR) != 'Y')
				{
					system("cls");
					LogoOops();
					Tips(3);//输入有误
					printf("\t\t\t\t\t\t\t\t确认请按'Y'返回上一级:");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'Y')//返回上一级
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

void IfLate()//用于判断用户是否逾期未交（放在导入书籍信息之后）
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

