// TX6.cpp : Defines the entry point for the console application.
//


/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/
/*                                                        遊猟周                                                      */
/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "stdlib.h"
#include <time.h>
#include "Logolib.cpp"
#include "LogoFlash.cpp"

/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/
/*                                                       痕方蕗苧                                                     */
/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/

void LoginInterface();//LoginInterfave()痕方蕗苧
void LoginInt2();//
void BookIn();
//Logo蕗苧
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
/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/
/*                                                          潤更悶                                                    */
/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/

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

struct allbook//侭嗤慕
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

struct xinxi//噸宥喘薩嬲催
{
	char name[20];
	char password[20];
	char phone[20];
	struct booklend book[3];
	int borrowingbook;

}xinxi[100];

struct administrator//砿尖埀嬲催
{
	char name[20];
	char password[20];
}
administrator = { {"1"},{"1"} };

/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/
/*                                                       畠蕉延楚                                                     */
/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/

static int UserNum = 0;//喘薩方楚畠蕉延楚
static int BookNum = 0;//慕汐方朕畠蕉延楚
static char GetOptSTR[1000];//登協喘薩補秘廨喘忖憲堪
static int TAG = 0;//指起炎禰??喘薩=1??砿尖埀=2??嗄人=3??
static int Usercode;//迄協鞠村議喘薩議會催
static int hisnum=0;//畠蕉煽雰芝村訳方

/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/
/*                                                         UI譜柴                                                     */
/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/
void LoginIntUI()//兜兵順中
{
	printf("\t\t\t\t\t\t\t\t\t\t    艇輝念恵諒議頁:麼順中\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t   散哭聞喘TX6夕慕砿尖狼由\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t1.喘薩廣過\t   2.喘薩鞠村 \n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.曜竃\n\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t萩僉夲荷恬:");
}

void AdminOptUI()
{
	printf("\t\t\t\t\t\t\t\t\t\t艇輝念恵諒議頁:砿尖埀僉?扈臙?\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.慕汐秘垂\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2.慕汐竃垂\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t3.慕汐煽雰芝村\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t4.慕汐佚連臥儂\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t5.慕汐佚連俐個\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.曜竃鞠村\n\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t萩僉夲荷恬:");
}

void UserOptUI()
{
	printf("\t\t\t\t\t\t\t\t\t\t艇輝念恵諒議頁:噸宥喘薩僉?扈臙?\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.慕汐臥儂\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2.慕汐処堋\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t3.慕汐拷珊\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t4.倖繁佚連臥儂\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.曜竃鞠村\n\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t萩僉夲荷恬:");
}

void VisitorLogUI()
{
	printf("\t\t\t\t\t\t\t\t\t\t 艇輝念恵諒議頁:嗄人鞠村順中\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.慕汐臥儂\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.卦指 \n\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t萩僉夲荷恬:");
}

void LoginInt2UI()
{
	printf("\t\t\t\t\t\t\t\t\t\t  艇輝念恵諒議頁:鞠村順中\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.噸宥喘薩鞠村\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2.砿尖埀鞠村\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t3.嗄人鞠村\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.卦指\n\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t萩僉夲荷恬:");
}

void SearchIntUI()
{
	printf("\t\t\t\t\t\t\t\t\t\t 艇輝念恵諒議頁:慕汐殊沫順中\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t1.兆各臥儂\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t2.嶽窃臥儂\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t3.恬宀臥儂\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t4.竃井芙臥儂\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t0.卦指\n\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t萩僉夲荷恬:");
}


/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/
/*                                                    孔嬬侏痕方                                                      */
/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/
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


int LengthLimit(char *str, int low, int up)//忖憲海業?浙┌?音憲栽卦指1??憲栽卦指0
{
	int k = 0;
	if (strlen(str) < low || strlen(str) > up)
		k = 1;
	else
		k = 0;
	return k;
}

void setCursorPosition(int x, int y)//徭協吶議高炎協了痕方
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color)//徭協吶議猟忖冲弼痕方
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void CoverPlus(char *question, char *require, char *str, int x, int y)//畜鷹孳固痕方奐膿井
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
			printf("                                  ");//賠茅require
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
	}//while儉桟潤崩
}
void Tips(int flag)//戻幣痕方??0-廣過撹孔?? 1-鞠遜撹孔?? 2-嬲催賜畜鷹危列?? 3-補秘嗤列?’訥?嶷仟補秘 
				   //4-湖仍艇議聞喘?? 5-曾肝補秘議畜鷹音匯崑?（之饉茂?補秘:
{
	int i = 0;
	char tips[7][1000];
	strcpy(tips[0], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>!廣過撹孔!<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[1], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>!鞠遜撹孔!<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[2], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>!嬲催賜畜鷹危列!<<<<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[3], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>!補秘嗤列  萩嶷仟補秘!<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[4], "\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>!隆臥儂欺?犢慚渡?!<<<<<<<<<<<<<<<<<<<<<\n");
	strcpy(tips[5],	"\t\t\t\t\t\t\t\t>>>>>>>>>>>>>>>!嗤夕慕階扮隆珊??涙隈写偬処慕!<<<<<<<<<<<<<<<\n");
	strcpy(tips[6], "湖   仍   艇   議   聞   喘   !\n");
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n\n");
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
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n"); Sleep(1000);
}

int CheckAlpha(char *str)//臥心頁倦根嗤掲方忖??嗤卦指1
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

void Initialize(char *str)//忖憲方怏兜兵晒
{
	int i = 0;
	for (i = 0; i < strlen(str); i++)
		str[i] = '\0';
}

char GetOption(char *str)//喘薩補秘登協痕方
{
	char k;
	if (strlen(str) != 1)
		k = 'E';
	else
		k = str[0];
	return k;
	Initialize(GetOptSTR);
}

int CheckNumber(int str)//喘薩補秘頁倦葎歓方忖??飛頁繍凪廬葎歓方忖
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







/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/
/*                                                    麼勣痕方                                                        */
/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/

void LoadInfor()/*宸何蛍喘噐委txt猟周戦議喘薩佚連村秘欺殻會産贋岻嶄??喘噐俊和栖議喘薩兆畜鷹曳熟。俶勣慧壓念中*/
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
				for (UserNum = 0; feof(fp2) == 0; UserNum++)//喘薩潤更悶佚連刈贋鯉塀?歳嫦? 畜鷹 窮三 壓処慕汐方楚 及匯云慕議処竃定 埖 晩 扮 蛍 慕兆 慕催 哘珊。。。 及屈云?????? 
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

void Registe() /*廣過*7.14厚仟頼胆井*/
{

	FILE*fp;
	char checkpassword[30];
	int i = 0, flag = 0;
	system("cls"); 
	system("color 0f");
	LogoRegist();
	printf("\t\t\t\t\t\t\t\t\t\t  艇輝念恵諒議頁:廣過順中\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
	setColor(15);
	printf("\t\t\t\t\t\t\t\t    ‐1／喘薩兆->");
	setColor(8);
	printf("‐2／畜鷹->‐3／鳩範畜鷹->‐4／返字催鷹    \n\n");
	setColor(15);
	while (1)
	{
		setCursorPosition(64, 22);
		printf(">>萩譜崔艇議喘薩兆:");
		setColor(8);
		printf("海業音階狛20了忖憲拝音誼根嗤腎鯉");
		setCursorPosition(83, 22);
		setColor(15);
		do
		{
			xinxi[UserNum].name[i] = getch();
			xinxi[UserNum].name[i + 1] = '\0';
			setCursorPosition(64, 22);
			printf(">>萩譜崔艇議喘薩兆:%s", xinxi[UserNum].name);
			printf("                                ");//賠茅require
			setCursorPosition((83 + i), 22);
			if (xinxi[UserNum].name[i] == '\r' || i > 20)
				break;
			if (xinxi[UserNum].name[i] == '\b')
			{
				if (i <= 1)
				{
					setCursorPosition(64, 22);
					printf(">>萩譜崔艇議喘薩兆:");
					setColor(8);
					printf("海業音階狛20了忖憲拝音誼根嗤腎鯉");
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
		if (flag == 1)//嶷鹸?渣?
		{
			printf("\n\t\t\t\t\t\t\t\t  *危列* 喘薩兆厮贋壓!頁倦鞠村?(Y/N):");
			gets(GetOptSTR);
			while(GetOption(GetOptSTR)!='Y'&&GetOption(GetOptSTR)!='N')
			{
				system("cls");
				LogoOops();
				Tips(3);
				printf("\n\t\t\t\t\t\t\t\t喘薩兆厮贋壓!頁倦鞠村?(Y/N):");
				gets(GetOptSTR);
			}
			if(GetOption(GetOptSTR)=='Y')
				UserLogin();
			else
			{
				setCursorPosition(0,23);
				printf("\n\t\t\t\t\t\t\t\t  *危列* 喘薩兆厮贋壓!頁倦鞠村?(Y/N):  \n\n");
			}
		}
		else if (strlen(xinxi[UserNum].name) == 0 || strlen(xinxi[UserNum].name) > 20 || CheckString(xinxi[UserNum].name, ' '))//?渣禿亢?
			printf("\n\t\t\t\t\t\t\t\t  *危列* 喘薩兆音憲栽号袈!           \n\n");
		else
		{
			printf("\n\t\t\t\t\t\t\t\t  *屎鳩*                             \n\n");
			break;
		}
		flag = 0;
		i = 0;
	}
	char question1[] = { ">>萩譜崔艇議畜鷹:" };
	char question2[] = { ">>萩鳩範艇議畜鷹:" };
	char require[] = { "海業音階狛20了忖憲拝音誼根嗤腎鯉" };
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
			printf("\t\t\t\t\t\t\t\t    ‐1／喘薩兆->‐2／畜鷹->");
			setColor(8);
			printf("‐3／鳩範畜鷹->‐4／返字催鷹    \n\n");
			setColor(15);
			setCursorPosition(81, 26);
			CoverPlus(question1, require, xinxi[UserNum].password, 64, 26);
			if (strlen(xinxi[UserNum].password) == 0 || strlen(xinxi[UserNum].password) > 20 || CheckString(xinxi[UserNum].password, ' '))//?渣禿亢?
			{
				printf("\n\t\t\t\t\t\t\t\t  *危列* 畜鷹音憲栽号袈??\n\n");
				setCursorPosition(64, 26);
				printf("%s", question1);
				setColor(8);
				printf("%s", require);
				setCursorPosition(64, 26);
				Initialize(xinxi[UserNum].password);
			}
			else
			{
				printf("\n\t\t\t\t\t\t\t\t  *屎鳩*                 \n\n");
				break;
			}
		}
		setCursorPosition(64, 30);
		printf("%s%s", question2, require2);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t    ‐1／喘薩兆->‐2／畜鷹->‐3／鳩範畜鷹->");
		setColor(8);
		printf("‐4／返字催鷹    \n\n");
		setColor(15);
		setCursorPosition(81, 30);
		CoverPlus(question2, require2, checkpassword, 64, 30);
		if (strcmp(checkpassword, xinxi[UserNum].password) != 0)
		{
			printf("\n\t\t\t\t\t\t\t\t  *危列* 曾肝畜鷹補秘音匯崑??\n\n");
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
			printf("\n\t\t\t\t\t\t\t\t  *屎鳩*                     \n\n");
			break;
		}
	}
	while (1)
	{
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t    ‐1／喘薩兆->‐2／畜鷹->‐3／鳩範畜鷹->‐4／返字催鷹    \n\n");
		setCursorPosition(0, 34);
		printf("\t\t\t\t\t\t\t\t>>萩補秘艇議返字催鷹:");
		gets(xinxi[UserNum].phone);
		if (strlen(xinxi[UserNum].phone) != 11 || CheckAlpha(xinxi[UserNum].phone))
		{
			printf("\n\t\t\t\t\t\t\t\t  *危列* 萩補秘屎鳩議返字催鷹??\n\n");
			setCursorPosition(0, 34);
			printf("\t\t\t\t\t\t\t\t>>萩補秘艇議返字催鷹:%s", require2);
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
	LoginInterface();//廣過撹孔朔卦指麼順中	
}


void AdminOption()
{
	TAG = 2;//砿尖埀順中
	while (1)
	{
		system("cls");
		system("color 0F");
		LogoAdmin();
		AdminOptUI();
		gets(GetOptSTR);//資函喘薩補秘
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
	TAG = 1;//輝念順中頁喘薩順中
	while (1)
	{
		system("cls");
		system("color 0f");
		LogoUser();
		UserOptUI();
		gets(GetOptSTR);//資函喘薩補秘
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

void UserLogin()/*噸宥喘薩鞠村何蛍,鞠村佚連嚥産贋佚連曳熟*/
{
	int i = 0,flag = 1;//鞠遜撹孔登僅燕幣
	char name[20];
	char password[20];
	char question1[]={">>萩補秘艇議畜鷹:"};
	char require[]={"                                "};
	while (1)
	{
		system("cls");
		system("color 0F");
		LogoLogin();
		printf("\t\t\t\t\t\t\t\t\t\t艇輝念恵諒議頁:噸宥喘薩鞠村順中  \n");
		printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t                   ‐1／喘薩兆->");
		setColor(8);
		printf("‐2／畜鷹                    \n\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t>>萩補秘艇議喘薩兆:");
		gets(name);
		printf("\n\n");
		setColor(15);
		setCursorPosition(0,20);
		printf("\t\t\t\t\t\t\t\t                   ‐1／喘薩兆->‐2／畜鷹                    \n\n\n");
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
		if (flag == 1)//喘薩鞠村払移
		{
			system("cls");
			LogoOops();
			Tips(2);
			printf("\t\t\t\t\t\t\t\t頁倦写偬晦編鞠遜?(Y/N):");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);
				printf("\t\t\t\t\t\t\t\t頁倦写偬晦編鞠遜?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')
				break;
		}

	}
	LoginInterface();//喘薩飛音?觴茂?鞠村夸卦指麼順中
}


void VisitorLogin()//嗄人鞠村僉??
{
	TAG = 3;//嗄人順中
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
			LogoVisitor();//嗄人Logo
			VisitorLogUI();
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == '1')
			SearchInterface();//慕汐痕方
		else
			LoginInt2();
	}
}

void AdminLogin()//砿尖埀鞠村
{
	int i = 0;//徭喇延楚??喘噐for
	char name[20];
	char password[20];
	char question1[]={">>萩補秘艇議畜鷹:"};
	char require[]={"                                "};
	while (1)
	{
		system("cls");
		system("color 0f");
		LogoLogin();
		printf("\t\t\t\t\t\t\t\t\t\t艇輝念恵諒議頁:砿尖埀鞠遜順中\n");
		printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t                   ‐1／喘薩兆->");
		setColor(8);
		printf("‐2／畜鷹                    \n\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t>>萩補秘砿尖埀嬖催:");
		gets(name);
		printf("\n\n");
		setColor(15);
		setCursorPosition(0,20);
		printf("\t\t\t\t\t\t\t\t                   ‐1／喘薩兆->‐2／畜鷹                    \n\n\n");
		setCursorPosition(64,26);
		printf("%s%s",question1,require);
		setCursorPosition(81,26);
		CoverPlus(question1,require,password,64,26);
		if ((strcmp(name, administrator.name) != 0) || (strcmp(password, administrator.password) != 0))//嬲催賜畜鷹音謄塘
		{
			system("cls");
			LogoOops();
			Tips(2);
			printf("\t\t\t\t\t\t\t\t頁倦写偬鞠遜?(Y/N):");
			gets(GetOptSTR);
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);
				printf("\t\t\t\t\t\t\t\t頁倦写偬鞠遜?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')
				break;
		}
		else//鞠遜撹孔
		{
			system("cls");
			LogoLogin();
			Tips(1);
			AdminOption();
		}
	}
	LoginInterface();//喘薩飛音?觴茂?鞠村夸卦指麼順中
}
void LoginInt2()/*僉夲砿尖埀鞠村賜喘薩鞠村賜嗄人鞠村*/
{
	TAG = 0;//TAG兜兵晒
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

void LoginInterface()//喘薩鞠村兜兵順中
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

void UserSearch()  /*喘薩佚連臥儂何蛍*/
{
	char flag;
	system("cls");
	system("color 0f");
	LogoUserSearch();
	int line=0;
	printf("\t\t\t\t\t\t\t\t\t\t艇輝念恵諒議頁:喘薩佚連臥儂順中\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t************************************************************\n");
	printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t\t  ??會催 ??慕兆                    ??処堋晩豚   ??哘珊晩豚");
	if (xinxi[Usercode].book[0].outtime.year == 0)
	{
		printf("\n\n\t\t\t\t\t\t\t\t壙涙艇議処堋佚連\n\n\n");
		printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
		printf("\t\t\t\t\t\t\t\t************************************************************\n");
		printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n\n");
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
			printf("\n\n\n\n\t\t\t\t\t\t\t\t壙涙凪麿処堋佚連");
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
				printf("\n\n\n\n\t\t\t\t\t\t\t\t壙涙凪麿処堋佚連");
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
		printf("\t\t\t     喘薩兆: %s \n", xinxi[Usercode].name);
		printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
		printf("\t\t\t\t\t\t\t\t************************************************************\n");
		printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	}
	line=0;
	printf("\t\t\t\t\t\t\t\t艇珊辛參処堋 %d 云慕\t\t\t頁倦処堋?(Y/N):", 3 - xinxi[Usercode].borrowingbook);
	gets(GetOptSTR);//資函喘薩補秘
	while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
	{
		system("cls");
		LogoOops();
		Tips(3);//補秘嗤列
		printf("\t\t\t\t\t\t\t\t頁倦処堋?(Y/N):");
		gets(GetOptSTR);
	}
	if (GetOption(GetOptSTR) == 'N')//音序佩処堋
		UserOption();
	else//序佩処堋
		BookLend();
}

void BookIn()/*夕慕秘垂何蛍*/
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
	char question1[]={">>萩補秘秘垂夕慕兆各:"};
	char question2[]={">>萩補秘秘垂夕慕蛍窃:"};
	char question3[]={">>萩補秘秘垂夕慕恬宀:"};
	char question4[]={">>萩補秘秘垂夕慕竃井芙:"};
	char require1[]={"音階狛20倖忖憲拝音誼根嗤腎鯉"};
	char require2[]={"音階狛8倖忖憲拝音誼根嗤腎鯉"};
	char error1[]={"*危列* 夕慕兆各音憲栽号袈"};
	char error2[]={"*危列* 夕慕蛍窃音憲栽号袈"};
	char error3[]={"*危列* 夕慕恬宀音憲栽号袈"};
	char error4[]={"*危列* 夕慕竃井芙音憲栽号袈"};
	char right0[]={"*屎鳩*                   "};
	while (1)
	{
		system("cls");
		system("color 0f");
		LogoBookIn(); 
		printf("\t\t\t\t\t\t\t\t\t\t  艇輝念恵諒議頁:慕汐秘垂順中\n");
		printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t     ‐1／秘垂議夕慕兆各->");
		setColor(8);
		printf("‐2／慕汐佚連->‐3／秘垂方楚      \n\n\n");
		setColor(15);
		GetBookName(question1,require1,error1,right0,inbook.wantname,64,22,20);
		setCursorPosition(0,20);
		setColor(15);
		printf("\t\t\t\t\t\t\t\t     ‐1／秘垂議夕慕兆各->‐2／慕汐佚連->");
		setColor(8);
		printf("‐3／秘垂方楚      \n\n\n");
		setColor(15);
		GetBookName(question2,require2,error2,right0,inbook.booktype,64,26,8);
		GetBookName(question3,require1,error3,right0,inbook.author,64,30,20);
		GetBookName(question4,require1,error4,right0,inbook.press,64,34,20);
		setCursorPosition(0,20);
		setColor(15);
		printf("\t\t\t\t\t\t\t\t     ‐1／秘垂議夕慕兆各->‐2／慕汐佚連->‐3／秘垂方楚      \n\n\n");
		setCursorPosition(0,38);
		while (1)
		{
			printf("\t\t\t\t\t\t\t\t>>萩補秘秘垂夕慕方楚:");
			gets(GetOptSTR);
			if (CheckAlpha(GetOptSTR))
				printf("\n\t\t\t\t\t\t\t\t*危列* 補秘掲隈??\n\n");
			else
			{
				inbook.typenum = atol(GetOptSTR);
				Initialize(GetOptSTR);
				printf("\n\t\t\t\t\t\t\t\t*屎鳩*\n\n");
				break;
			}
		}
		for (j = BookNum; j < BookNum + inbook.typenum; j++)
		{
			strcpy(allbook[j].bookname, inbook.wantname);
			strcpy(allbook[j].booktype, inbook.booktype);
			strcpy(allbook[j].author, inbook.author);
			strcpy(allbook[j].press, inbook.press);
			itoa(j + 1, allbook[j].booknumber, 10);/*繍屁方廬算撹忖憲堪參糞?嶐垓?園會*/
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
		printf("\t\t\t\t\t\t\t\t*秘垂頼撹*\n");
		printf("\n\t\t\t\t\t\t\t\t頁倦写偬村秘?(Y/N):");
		gets(GetOptSTR);//資函喘薩補秘
		while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
		{
			system("cls");
			LogoOops();
			Tips(3);//補秘嗤列
			printf("\t\t\t\t\t\t\t\t頁倦写偬村秘?(Y/N):");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'N')//嬉篤while儉桟
			break;
	}
	AdminOption();//音写偬
}

void BookOut()/*夕慕竃垂何蛍*/
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
			printf("\t\t\t\t\t\t\t\t\t\t  艇輝念恵諒議頁:慕汐竃垂順中\n");
			printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
			for(j=0;j<99;j++)
			{	strcpy(havebook[j].press,"\0");
				havebook[j].num=0;
			}
			setColor(15);
			printf("\t\t\t\t\t\t\t\t        ‐1／補秘慕汐醤悶兆各->");
			setColor(8);
			printf("‐2／序佩竃垂荷恬\n\n\n");
			setColor(15);
			printf("\t\t\t\t\t\t\t\t>>萩補秘?誨?竃垂議夕慕兆各:");
			gets(outbook);
			setCursorPosition(0,20);
			setColor(15);
			printf("\t\t\t\t\t\t\t\t        ‐1／補秘慕汐醤悶兆各->‐2／序佩竃垂荷恬\n\n\n");
			setCursorPosition(0,24);
			printf("\n\t\t\t\t\t\t\t\t   屎壓柳廬朴沫潤惚");
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
				printf("\t\t\t\t\t\t\t\t頁倦嶷仟補秘?(Y/N):");
				gets(GetOptSTR);//資函喘薩補秘
				while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
				{
					system("cls");
					LogoOops();
					Tips(3);//補秘嗤列
					printf("\t\t\t\t\t\t\t\t頁倦嶷仟補秘?(Y/N):");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'N')//音嶷仟補秘
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
		printf("\t\t\t\t\t\t\t\t\t        艇輝念恵諒議頁:慕汐竃垂順中\n");
		printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
		printf("\t\t\t\t\t\t\t********************************************************************************\n");
		printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
		printf("\t\t\t\t\t\t\t ??會催 ??慕兆                         ??竃井芙                      ??壓尺方楚\n\n");
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
		printf("\n\n\n\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
		printf("\t\t\t\t\t\t\t********************************************************************************\n");
		printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
		while(1)
		{
			while(1)
			{
				printf("\n\t\t\t\t\t\t\t\t>>萩補秘勣竃垂議夕慕會催:");
				gets(GetOptSTR);
				if (CheckAlpha(GetOptSTR))
					printf("\n\t\t\t\t\t\t\t\t*危列* 補秘掲隈??\n");
				else
				{
					xuhao=atol(GetOptSTR);
					Initialize(GetOptSTR);
					break;
				}
			}
			if(xuhao>m)//補秘掲會催方忖
				printf("\n\t\t\t\t\t\t\t\t*危列* 短嗤?狷ヅ箋鎚藜?!\n");
			else if(havebook[xuhao-1].num==0)
				printf("\n\t\t\t\t\t\t\t\t*危列* 乎慕厮瓜処堋,音嬬竃垂!\n");
			else
				break;
		}
		while (1)//辛參竃垂
		{
			printf("\n\t\t\t\t\t\t\t\t>>萩補秘竃垂夕慕方楚:");
			gets(GetOptSTR);
			if (CheckAlpha(GetOptSTR))
				printf("\n\t\t\t\t\t\t\t\t>>*危列* 補秘掲隈??\n");
			else
			{
				typenum = atol(GetOptSTR);
				Initialize(GetOptSTR);
				if (typenum>havebook[xuhao-1].num)
				{
					printf("\n\t\t\t\t\t\t\t\t>>*危列* 補秘竃垂方寄噐壓尺方,萩嶷仟補秘!\n");
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
		printf("\n\t\t\t\t\t\t\t\t*夕慕竃垂頼撹*\n");
		for (i = 0; i < BookNum; i++)
			itoa(i + 1, allbook[i].booknumber, 10);
		printf("\n\t\t\t\t\t\t\t\t頁倦写偬竃垂?(Y/N):");
		gets(GetOptSTR);//資函喘薩補秘
		while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
		{
			system("cls");
			LogoOops();
			Tips(3);//補秘嗤列
			printf("\t\t\t\t\t\t\t\t頁倦写偬竃垂?(Y/N):");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'N')//嬉篤while儉桟
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
			LogoBookAdjust();//慕汐俐個
			printf("\t\t\t\t\t\t\t\t\t      艇輝念恵諒議頁:慕汐佚連俐個順中\n");
			printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
			setColor(15);
			printf("\t\t\t\t\t\t\t\t        ‐1／補秘慕汐醤悶兆各->");
			setColor(8);
			printf("‐2／序佩俐個荷恬\n\n\n");
			setColor(15);
			printf("\t\t\t\t\t\t\t\t>>萩補秘?誨?俐個議夕慕兆各:");
			gets(wantname);
			setCursorPosition(0,20);
			setColor(15);
			printf("\t\t\t\t\t\t\t\t        ‐1／補秘慕汐醤悶兆各->‐2／序佩俐個荷恬\n\n\n");
			setCursorPosition(0,24);
			printf("\n\t\t\t\t\t\t\t\t   屎壓柳廬朴沫潤惚");
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
				printf("\t\t\t\t\t\t\t\t頁倦嶷仟補秘?(Y/N):");
				gets(GetOptSTR);//資函喘薩補秘
				while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
				{
					system("cls");
					LogoOops();
					Tips(3);//補秘嗤列
					printf("\t\t\t\t\t\t\t\t頁倦嶷仟補秘?(Y/N):");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'N')//音嶷仟補秘
					AdminOption();
			}
			else
			{	
				system("cls");
				system("color 0f");
				LogoBookAdjust();
				printf("\t\t\t\t\t\t\t\t\t      艇輝念恵諒議頁:慕汐佚連俐個順中\n");
				printf("\t\t\t\t\t\t    ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
				printf("\t\t\t\t\t\t    ****************************************************************************************\n");
				printf("\t\t\t\t\t\t    ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
				printf("\t\t\t\t\t\t      ??會催 ??慕兆             ??蛍窃 ??竃井芙              ??恬宀             ??頁倦壓尺\n\n");
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
							printf("頁");
						else
							printf("倦");
						printf("\n\n");
					}
				}
				printf("\n\t\t\t\t\t\t    ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
				printf("\t\t\t\t\t\t    ****************************************************************************************\n");
				printf("\t\t\t\t\t\t    ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
				break;
			}
		}
		flag=0;
		while(1)
		{
			while (1)
			{
				printf("\t\t\t\t\t\t\t>>萩補秘俶勣俐個議夕慕會催:");
				gets(GetOptSTR);
				if (CheckAlpha(GetOptSTR))
					printf("\n\t\t\t\t\t\t\t*危列* 補秘掲隈??\n");
				else
				{
					number=atol(GetOptSTR);
					break;
				}
			}
			for(i=0;i<BookNum;i++)//登僅頁倦嗤斤哘會催
			{
				if(strcmp(GetOptSTR,allbook[i].booknumber)==0&&strcmp(allbook[number-1].bookname,wantname)==0)
				{	
					flag++;
					break;
				}
			}
			if(flag==0)
				printf("\n\t\t\t\t\t\t\t*危列* 短嗤?狷ヅ箋鎚藜?!\n");
			else if(allbook[number-1].inshelf=='N')
				printf("\n\t\t\t\t\t\t\t*危列* 乎慕厮瓜処堋,音嬬俐個佚連!\n");
			else
			{
				printf("\n\t\t\t\t\t\t\t*屎鳩*\n");
				flag=0;
				printf("\n\t\t\t\t\t\t\t>>萩嶷仟村秘慕汐佚連\n");
				printf("\n\t\t\t\t\t\t\t>>萩補秘夕慕兆各:");
				gets(allbook[number-1].bookname);
				printf("\n\t\t\t\t\t\t\t>>萩補秘夕慕蛍窃:");
				gets(allbook[number-1].booktype);
				printf("\n\t\t\t\t\t\t\t>>萩補秘夕慕竃井芙:");
				gets(allbook[number-1].press);
				printf("\n\t\t\t\t\t\t\t>>萩補秘夕慕恬宀:");
				gets(allbook[number-1].author);
				printf("\n\t\t\t\t\t\t\t*俐個頼撹!*\n");
			}
			printf("\n\t\t\t\t\t\t\t頁倦写偬俐個凪麿夕慕佚連?(Y/N):");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{	
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t頁倦写偬俐個凪麿夕慕佚連?(Y/N):");
				gets(GetOptSTR);
			}	
			if (GetOption(GetOptSTR) == 'N')//音序佩俐個
				AdminOption();
			else
				break;	
		}//和while儉桟潤崩
	}//悳while儉桟潤崩
}

void BookLend()/*喘薩夕慕処堋何蛍*/
{	int flagx[100];
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>萩補秘?誨?臥儂議夕慕兆各:"};
	char require[]={"屶隔庁冊臥儂,萩補秘屎鳩議夕慕兆各"};
	char error[]={"*危列* 夕慕兆各音憲栽号袈"};
	char right[]={"*屎鳩* 屎壓柳廬朴沫潤惚  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0,typenum=0;//count->購囚簡侭斤謹富倖慕兆,number->蝶慕汐方楚
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//験兜峙??載嶷勣
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t艇輝念恵諒議頁:兆各臥儂順中\n");
		printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          ‐1／補秘慕汐購囚簡->");
		setColor(8);
		printf("‐2／補竃?犢慂蕷笑渡?\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,20);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          ‐1／補秘慕汐購囚簡->‐2／補竃?犢慂蕷笑渡?\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//購囚簡俳頭刈贋
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//繍淫根朴沫?邉鎚蘆?村秘屈略方怏
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//侭嗤忖憲脅殊霞竃栖阻
			{
				if (strstr(allbook[j].bookname, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//壓慕垂嶄孀欺
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//for儉桟登僅頁倦厮将芝村
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
		if (count != 0)//嗤慕
		{
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t       ??會催 ??慕兆               ??蛍窃 ??竃井芙              ??恬宀              ??鋼茄方??辛処方\n\n");
			for (NO = 0; NO < count; NO++)//臥孀耽倖慕兆斤哘叱云慕
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
			printf("\n\n\t\t\t\t\t      *臥儂頼撹*                                                                  慌臥儂欺%d訳佚連\n\n", count);
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t\t頁倦嗤艇?誨?処堋議慕汐?(Y/N):");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				printf("\n\t\t\t\t\t\t*危列* 補秘掲隈!\n");
				printf("\n\t\t\t\t\t\t頁倦嗤艇?誨?処堋議慕汐?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//嬉篤while儉桟
				break;
		}
		else//短嗤?犢慂藜?
		{
			system("cls");
			LogoOops();
			Tips(4);//隆臥儂欺?犢慚渡?
			printf("\t\t\t\t\t\t\t\t頁倦写偬処堋凪麿慕汐?(Y/N):");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t頁倦写偬処堋凪麿慕汐?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//嬉篤while儉桟
				break;
		}
		while (1)
		{
			flag=0;
			printf("\n\t\t\t\t\t\t>>萩補秘艇?觸萪諜鎚藜?會催:");
			gets(GetOptSTR);
			if (CheckAlpha(GetOptSTR))
				printf("\n\t\t\t\t\t\t*危列* 補秘掲隈!\n");
			else
			{
				typenum = atol(GetOptSTR);
				for(i=0;i<BookNum;i++)//登僅頁倦嗤斤哘會催
				{
					if(strcmp(GetOptSTR,allbook[i].booknumber)==0)
					{	
						flag++;
						break;
					}
				}	
				if (flag==0)
					printf("\n\t\t\t\t\t\t*危列* 短嗤?狷ヅ箋鎚藜?!\n");
				else
				{
					Initialize(GetOptSTR);
					if(allbook[typenum].inshelf=='N')
					{
						printf("\n\t\t\t\t\t\t*危列* 乎慕厮瓜処堋!\n");
						printf("\n\t\t\t\t\t\t頁倦写偬処堋凪麿慕汐?(Y/N):");
						gets(GetOptSTR);//資函喘薩補秘
						while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
						{
							system("cls");
							LogoOops();
							Tips(3);//補秘嗤列
							printf("\t\t\t\t\t\t\t\t頁倦写偬処堋凪麿慕汐?(Y/N):");
							gets(GetOptSTR);
						}
						if (GetOption(GetOptSTR) == 'N')//嬉篤while儉桟
							break;
						else 
							continue;
					}
					if(allbook[typenum].inshelf=='Y')
						break;
				}
			}
		}
		BookBorrowBottom(flagx[typenum-1]);//処堋撹孔炎崗
		HistoryWrite();
		flag = 0;
		number = 0;
		printf("\n\t\t\t\t\t\t頁倦写偬処堋凪麿慕汐?(Y/N):");//頁倦処堋凪麿慕汐
		gets(GetOptSTR);
		while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
		{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t頁倦写偬処堋凪麿慕汐?(Y/N):");
				gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'N')//音処堋凪麿慕汐
			UserOption();
		else//写偬処堋凪麿慕汐
			continue;
		/*兜兵晒方象*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//while儉桟潤崩
}

void BookBorrowBottom(int number)//処慕梓泥梓和朔窟伏議並秤
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
		printf("\n\t\t\t\t\t\t\t\t  *処堋撹孔*\n\n");

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

		printf("\n\t\t\t\t\t\t  *処堋撹孔*\n");
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

		printf("\n\t\t\t\t\t\t\t\t  *処堋撹孔*\n\n");
	}
	else
		printf("\n\n\t\t\t\t\t\t\t\t艇厮将処阻3云慕阻??艇厮音辛參壅処慕!\n");
}
void BookReturn()//喘薩梓珊慕梓泥岻朔議順中
{
	char wantnum[40];
	int op,pp,line=0,i=0;
	while (1)
	{
			system("cls");
			system("color 0f");
			LogoBookReturn();
			printf("\t\t\t\t\t\t\t\t\t\t  艇輝念恵諒議頁:慕汐拷珊順中\n");
			printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t\t\t\t************************************************************\n");
			printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t\t\t\t  ??會催 ??慕兆                    ??処堋晩豚   ??哘珊晩豚");
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
				printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t     艇短嗤俶勣拷珊議慕汐!\n");
				printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t喘薩兆: %s \n", xinxi[Usercode].name);
				printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
				printf("\t\t\t\t\t\t\t\t************************************************************\n");
				printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
				printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧雫:");
				gets(GetOptSTR);
				while (GetOption(GetOptSTR) != 'Y')
				{
					system("cls");
					LogoOops();
					Tips(3);//補秘嗤列
					printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧雫:");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'Y')//音拷珊凪麿慕汐
					UserOption();
			}
			line=0;
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t喘薩兆: %s \n", xinxi[Usercode].name);
			printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t\t\t\t************************************************************\n");
			printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			while(1)
			{
				printf("\n\t\t\t\t\t\t\t\t>>萩補秘拷珊夕慕議會催:");
				gets(GetOptSTR);
				if (CheckAlpha(GetOptSTR))
					printf("\n\t\t\t\t\t\t\t\t*危列* 補秘掲隈!\n");
				else
				{
					op = atol(GetOptSTR);
					pp=op-1;
					Initialize(GetOptSTR);
					strcpy(wantnum, xinxi[Usercode].book[op - 1].booknumber);
					if (strcmp(wantnum, "/") == 0 ||(op != 1&&op != 2&&op != 3))//珊慕補秘危列
						printf("\n\t\t\t\t\t\t\t\t*危列* 短嗤嚥會催謄塘議慕汐!\n");
					else
					{
						printf("\n\t\t\t\t\t\t\t\t鳩協勣拷珊 %d %s 宅?(Y/N):",op,xinxi[Usercode].book[pp].bookname);
						gets(GetOptSTR);
						while(GetOption(GetOptSTR)!='Y'&&GetOption(GetOptSTR)!='N')
						{
							system("cls");
							LogoOops();
							Tips(3);
							printf("\t\t\t\t\t\t\t\t鳩協勣拷珊 %d %s 宅?(Y/N):",op,xinxi[Usercode].book[pp].bookname);
							gets(GetOptSTR);
						}
						if(GetOption(GetOptSTR)=='N')
						{
							printf("\n\t\t\t\t\t\t\t\t頁倦拷珊凪麿慕汐?(Y/N):");//頁倦拷珊凪麿慕汐
							gets(GetOptSTR);
							while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
							{
								system("cls");
								LogoOops();
								Tips(3);//補秘嗤列
								printf("\t\t\t\t\t\t\t\t頁倦拷珊凪麿慕汐?(Y/N):");
								gets(GetOptSTR);
							}
								if (GetOption(GetOptSTR) == 'N')//音拷珊凪麿慕汐
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
			printf("\n\t\t\t\t\t\t\t\t*拷珊撹孔*\n");
			HistoryWrite();
			printf("\n\t\t\t\t\t\t\t\t頁倦拷珊凪麿慕汐?(Y/N):");//頁倦拷珊凪麿慕汐
			gets(GetOptSTR);
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t頁倦拷珊凪麿慕汐?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//音拷珊凪麿慕汐
				UserOption();
	}
}

void BookSearch()/*臥儂夕慕佚連何蛍*/
{
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>萩補秘?誨?臥儂議夕慕兆各:"};
	char require[]={"屶隔庁冊臥儂,萩補秘屎鳩議夕慕兆各"};
	char error[]={"*危列* 夕慕兆各音憲栽号袈"};
	char right[]={"*屎鳩* 屎壓柳廬朴沫潤惚  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0;//count->購囚簡侭斤謹富倖慕兆,number->蝶慕汐方楚
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//験兜峙??載嶷勣
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t艇輝念恵諒議頁:兆各臥儂順中\n");
		printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          ‐1／補秘慕汐購囚簡->");
		setColor(8);
		printf("‐2／補竃?犢慂蕷笑渡?\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,20);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          ‐1／補秘慕汐購囚簡->‐2／補竃?犢慂蕷笑渡?\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//購囚簡俳頭刈贋
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//繍淫根朴沫?邉鎚蘆?村秘屈略方怏
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//侭嗤忖憲脅殊霞竃栖阻
			{
				if (strstr(allbook[j].bookname, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//壓慕垂嶄孀欺
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//for儉桟登僅頁倦厮将芝村
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
		if (count != 0)//嗤慕
		{
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t       ??會催 ");
			setColor(3);
			printf("??慕兆");
			setColor(15);
			printf("               ??蛍窃 ??竃井芙              ??恬宀              ??鋼茄方??辛処方\n\n");
			for (NO = 0; NO < count; NO++)//臥孀耽倖慕兆斤哘叱云慕
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
			printf("\n\n\t\t\t\t\t      *臥儂頼撹*                                                                  慌臥儂欺%d訳佚連\n\n", count);
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t\t  頁倦写偬朴沫?(Y/N):");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t頁倦写偬朴沫?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//嬉篤while儉桟
				break;
		}
		else//短嗤?犢慂藜?
		{
			system("cls");
			LogoOops();
			Tips(4);//隆臥儂欺?犢慚渡?
			printf("\t\t\t\t\t\t\t\t頁倦写偬朴沫?(Y/N):");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t頁倦写偬朴沫?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//嬉篤while儉桟
				break;
		}
		/*兜兵晒方象*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//while儉桟潤崩
}


void TypeSearch()/*臥儂夕慕佚連何蛍*/
{
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>萩補秘?誨?臥儂議夕慕嶽窃:"};
	char require[]={"屶隔庁冊臥儂,萩補秘屎鳩議夕慕嶽窃"};
	char error[]={"*危列* 夕慕嶽窃音憲栽号袈"};
	char right[]={"*屎鳩* 屎壓柳廬朴沫潤惚  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0;//count->購囚簡侭斤謹富倖慕兆,number->蝶慕汐方楚
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//験兜峙??載嶷勣
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t艇輝念恵諒議頁:嶽窃臥儂順中\n");
		printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          ‐1／補秘慕汐購囚簡->");
		setColor(8);
		printf("‐2／補竃?犢慂蕷笑渡?\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,8);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          ‐1／補秘慕汐購囚簡->‐2／補竃?犢慂蕷笑渡?\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//購囚簡俳頭刈贋
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//繍淫根朴沫?邉鎚蘆?村秘屈略方怏
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//侭嗤忖憲脅殊霞竃栖阻
			{
				if (strstr(allbook[j].booktype, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//壓慕垂嶄孀欺
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//for儉桟登僅頁倦厮将芝村
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
		if (count != 0)//嗤慕
		{
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t       ??會催 ??慕兆               ");
			setColor(3);
			printf("??蛍窃 ");
			setColor(15);
			printf("??竃井芙              ??恬宀              ??鋼茄方??辛処方\n\n");
			for (NO = 0; NO < count; NO++)//臥孀耽倖慕兆斤哘叱云慕
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
			printf("\n\n\t\t\t\t\t      *臥儂頼撹*                                                                  慌臥儂欺%d訳佚連\n\n", count);
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t\t  頁倦写偬朴沫?(Y/N):");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t頁倦写偬朴沫?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//嬉篤while儉桟
				break;
		}
		else//短嗤?犢慂藜?
		{
			system("cls");
			LogoOops();
			Tips(4);//隆臥儂欺?犢慚渡?
			printf("\t\t\t\t\t\t\t\t頁倦写偬朴沫?(Y/N):");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t頁倦写偬朴沫?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//嬉篤while儉桟
				break;
		}
		/*兜兵晒方象*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//while儉桟潤崩
}


void AuthorSearch()/*臥儂夕慕佚連何蛍*/
{
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>萩補秘?誨?臥儂議夕慕恬宀:"};
	char require[]={"屶隔庁冊臥儂,萩補秘屎鳩議夕慕恬宀"};
	char error[]={"*危列* 夕慕恬宀音憲栽号袈"};
	char right[]={"*屎鳩* 屎壓柳廬朴沫潤惚  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0;//count->購囚簡侭斤謹富倖慕兆,number->蝶慕汐方楚
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//験兜峙??載嶷勣
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t艇輝念恵諒議頁:恬宀儂順中\n");
		printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          ‐1／補秘慕汐購囚簡->");
		setColor(8);
		printf("‐2／補竃?犢慂蕷笑渡?\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,20);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          ‐1／補秘慕汐購囚簡->‐2／補竃?犢慂蕷笑渡?\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//購囚簡俳頭刈贋
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//繍淫根朴沫?邉鎚蘆?村秘屈略方怏
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//侭嗤忖憲脅殊霞竃栖阻
			{
				if (strstr(allbook[j].author, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//壓慕垂嶄孀欺
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//for儉桟登僅頁倦厮将芝村
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
		if (count != 0)//嗤慕
		{
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t       ??會催 ??慕兆               ??蛍窃 ??竃井芙              ");
			setColor(3);
			printf("??恬宀");
			setColor(15);
			printf("              ??鋼茄方??辛処方\n\n");
			for (NO = 0; NO < count; NO++)//臥孀耽倖慕兆斤哘叱云慕
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
			printf("\n\n\t\t\t\t\t      *臥儂頼撹*                                                                  慌臥儂欺%d訳佚連\n\n", count);
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t\t  頁倦写偬朴沫?(Y/N):");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t頁倦写偬朴沫?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//嬉篤while儉桟
				break;
		}
		else//短嗤?犢慂藜?
		{
			system("cls");
			LogoOops();
			Tips(4);//隆臥儂欺?犢慚渡?
			printf("\t\t\t\t\t\t\t\t頁倦写偬朴沫?(Y/N):");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t頁倦写偬朴沫?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//嬉篤while儉桟
				break;
		}
		/*兜兵晒方象*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//while儉桟潤崩
}


void PressSearch()/*臥儂夕慕佚連何蛍*/
{
	char wantname[40],author[100][40],press[100][40];
	char mohusearch[100][40];
	char qiepian[40][10];
	char question[]={">>萩補秘?誨?臥儂議夕慕竃井芙:"};
	char require[]={"屶隔庁冊臥儂,萩補秘屎鳩議夕慕竃井芙"};
	char error[]={"*危列* 夕慕竃井芙音憲栽号袈"};
	char right[]={"*屎鳩* 屎壓柳廬朴沫潤惚  "};
	int i = 0, j = 0, flag = 0, flag2 = 0, flag3 = 1, NO = 0, count = 0, number = 0, onecount = 0;//count->購囚簡侭斤謹富倖慕兆,number->蝶慕汐方楚
	while (1)
	{
		NO = 0, flag2 = 0, onecount = 0;//験兜峙??載嶷勣
		system("cls");
		system("color 0F");
		LogoBookSearch();
		printf("\t\t\t\t\t\t\t\t\t\t艇輝念恵諒議頁:竃井芙臥儂順中\n");
		printf("\t\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
		setColor(15);
		printf("\t\t\t\t\t\t\t\t          ‐1／補秘慕汐購囚簡->");
		setColor(8);
		printf("‐2／補竃?犢慂蕷笑渡?\n\n\n");
		setColor(15);
		GetBookName(question,require,error,right,wantname,64,22,20);
		setColor(15);
		setCursorPosition(0, 20);
		printf("\t\t\t\t\t\t\t\t          ‐1／補秘慕汐購囚簡->‐2／補竃?犢慂蕷笑渡?\n\n\n");
		Sleep(1500);
		system("cls");
		system("color 0F");
		LogoBookSearch();
		//購囚簡俳頭刈贋
		for (i = 0; i < 40; i++)
		{
			for (j = 0; j < 10; j++)
				qiepian[i][j] = '\0';
		}
		for (i = 0; i < strlen(wantname); i++)
			qiepian[i][0] = wantname[i];
		for (j = 0; j < BookNum; j++)//繍淫根朴沫?邉鎚蘆?村秘屈略方怏
		{
			flag3=1;
			for (i = 0; i < strlen(wantname); i++)//侭嗤忖憲脅殊霞竃栖阻
			{
				if (strstr(allbook[j].press, qiepian[i]) == NULL)
					flag3 = 0;
			}
			if (flag3 == 1)//壓慕垂嶄孀欺
			{
				flag2 = 0;
				for (i = 0; i < 100; i++)//for儉桟登僅頁倦厮将芝村
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
		if (count != 0)//嗤慕
		{
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t       ??會催 ??慕兆               ??蛍窃 ");
			setColor(3);
			printf("??竃井芙");
			setColor(15);
			printf("              ??恬宀              ??鋼茄方??辛処方\n\n");
			for (NO = 0; NO < count; NO++)//臥孀耽倖慕兆斤哘叱云慕
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
			printf("\n\n\t\t\t\t\t      *臥儂頼撹*                                                                  慌臥儂欺%d訳佚連\n\n", count);
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t     ************************************************************************************************\n");
			printf("\t\t\t\t\t     ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
			printf("\t\t\t\t\t\t  頁倦写偬朴沫?(Y/N):");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t頁倦写偬朴沫?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//嬉篤while儉桟
				break;
		}
		else//短嗤?犢慂藜?
		{
			system("cls");
			LogoOops();
			Tips(4);//隆臥儂欺?犢慚渡?
			printf("\t\t\t\t\t\t\t\t頁倦写偬朴沫?(Y/N):");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y'&&GetOption(GetOptSTR) != 'N')
			{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t頁倦写偬朴沫?(Y/N):");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'N')//嬉篤while儉桟
				break;
		}
		/*兜兵晒方象*/
		count = 0; flag = 0;
		for (i = 0; i < 100; i++)
			Initialize(mohusearch[i]);
	}//while儉桟潤崩
}

void SearchInterface()//慕汐朴沫肝雫順中
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



void Timenow()//?。〉池攬儺映以閏簑屡觸畊耕紕?嬉咫輝念扮寂。柴麻竃枠壓処慕議繁哘乎焚担扮昨珊慕。

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
	temp1 = a;//定芸音延
	if (b == 3 || b == 5 || b == 8 || b == 10)//和倖埖嗤30爺
	{
		if (c == 31)
		{
			temp2 = b + 2;//輝埖31催??埖芸紗2
			temp3 = 1;
		}
		else
		{
			temp2 = b + 1;
			temp3 = c;
		}
	}
	else if (b == 4 || b == 6 || b == 7 || b == 9 || b == 12)//和倖埖嗤31爺
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
		if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)//避定
			temp3 = c + 31 - 29;
		else
			temp3 = c + 31 - 28;
	}
	else
	{
		if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)//避定
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

	/* printf("?嶬敲?%d定", 1900 + p->tm_year);/*資函輝念定芸,貫1900蝕兵??侭參勣紗1900*/

	/* printf("%d埖", 1 + p->tm_mon);/*資函輝念埖芸,袈律頁0-11,侭參勣紗1*/

	/* printf("%d晩", p->tm_mday);/*資函輝念埖芸晩方,袈律頁1-31*/

	/* printf("%d扮", 8 + p->tm_hour);/*資函輝念扮,宸戦資函廉圭議扮寂,胡挫?牴邂妨?弌扮*/


	/* printf("%d蛍", p->tm_min); /*資函輝念蛍*/

	/* printf("%d\n", p->tm_yday); /*貫書定1埖1晩麻軟崛書議爺方??袈律葎0-365*/
	 /*廣?佐遼慍沈還貫斃?大*/
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
	fseek(fcount, 0, SEEK_SET);//賠腎痕方
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
		printf("\t\t\t\t\t\t\t\t\t      艇輝念恵諒議頁:砿尖埀慕汐佚連順中\n");
		printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
		printf("\t\t\t\t\t\t\t****************************************************************************\n");
		printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
		printf("\t\t\t\t\t\t\t  ??會催 ??慕兆               ??蛍窃 ??竃井芙              ??恬宀\n\n");
		if(BookNum==0)
			printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t短嗤慕汐壓尺!\n\n\n\n\n");
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
		printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
		printf("\t\t\t\t\t\t\t****************************************************************************\n");
		printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
		printf("\t\t\t\t\t\t\t\t梓販吭囚臥心処堋佚連,ESC囚卦指");
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
		printf("\t\t\t\t\t\t\t\t\t      艇輝念恵諒議頁:砿尖埀慕汐佚連順中\n");
		printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
		printf("\t\t\t\t\t\t\t****************************************************************************\n");
		printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
		printf("\t\t\t\t\t\t\t  ??會催 ??慕兆                ??頁倦壓尺 ??処堋扮寂   ??哘珊扮寂  ??処慕繁\n\n");
		if(BookNum==0)
			printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t短嗤慕汐壓尺!\n\n\n\n\n");
		for (i = 0; i < BookNum; i++)
		{
			setCursorPosition(61,(24+2*i));
			puts(allbook[i].booknumber);
			setCursorPosition(66,(24+2*i));
			puts(allbook[i].bookname);
			setCursorPosition(92,(24+2*i));
			if(allbook[i].inshelf=='Y')
			{
				printf("頁");
				setCursorPosition(110,(24+2*i));
				printf("涙繁処堋");
			}
			else
			{
				printf("倦");
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
		printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
		printf("\t\t\t\t\t\t\t****************************************************************************\n");
		printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
		printf("\t\t\t\t\t\t\t\t梓販吭囚臥心慕汐佚連,ESC囚卦指");
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
	printf("\t\t\t\t\t\t\t\t\t      艇輝念恵諒議頁:砿尖埀慕汐佚連順中\n");
	printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t****************************************************************************\n");
	printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t  ??會催 ??慕兆               ??蛍窃 ??竃井芙              ??恬宀\n\n");
	if(BookNum==0)
		printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t短嗤慕汐壓尺!\n\n\n\n\n");
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
	printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t\t****************************************************************************\n");
	printf("\t\t\t\t\t\t\t！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n\n");
	printf("\t\t\t\t\t\t\t\t梓販吭囚臥心処堋佚連,ESC囚卦指");
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
			for (hisnum= 0; feof(fp9) == 0; hisnum++)//喘噐刈贋喘薩議煽雰芝村。繁兆 慕兆 慕催 扮寂 竃賜秘 頁倦嘯豚 選狼窮三
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
	printf("\t\t\t\t\t\t\t\t\t\t艇輝念恵諒議頁:煽雰佚連順中\n");
	printf("\t\t\t\t\t\t    ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t    ************************************************************************************\n");
	printf("\t\t\t\t\t\t    ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t    ??喘薩侖兆       ??慕兆          ??慕催??処竃/拷珊??扮寂          ??頁倦階扮??喘薩選狼窮三\n");
	if(hisnum==0)
		printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t壙涙煽雰佚連\n\n\n\n");
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
			puts("処竃");
		else
			puts("拷珊");
		setCursorPosition(103,(24+2*i));
		printf("%d/%d/%d/%d/%d",history[i].year,history[i].month, history[i].day, history[i].hour, history[i].min);
		setCursorPosition(121,(24+2*i));
		if(history[i].late=='Y')
		{	
			setColor(4);
			puts("頁");
			setColor(15);
		}
		else
			puts("倦");
		setCursorPosition(130,(24+2*i));
		puts(history[i].phone);
		printf("\n\n");
	}
	printf("\t\t\t\t\t\t    ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t    ************************************************************************************\n");
	printf("\t\t\t\t\t\t    ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！\n");
	printf("\t\t\t\t\t\t    鳩範萩梓'Y'囚卦指貧雫:");
	gets(GetOptSTR);
	while(GetOption(GetOptSTR)!='Y')
	{
		system("cls");
		LogoOops();
		Tips(3);
		printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'囚卦指貧雫:");
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
		printf("涙隈嬉蝕煽雰芝村猟周\n");
		exit(0);
	}
	for (i=0;i< hisnum ; i++)//喘噐刈贋喘薩議煽雰芝村。繁兆 慕兆 慕催 扮寂 竃賜秘 頁倦嘯豚 選狼窮三
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


int TimeCheck(int Usercode)/*登僅頁倦階扮*/
{
	if (xinxi[Usercode].book[0].shouldback.year < nowtime.year&&xinxi[Usercode].book[0].shouldback.year != 0)
	{
		system("cls");
		LogoOops();
		Tips(5);
		printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
		gets(GetOptSTR);//資函喘薩補秘
		while (GetOption(GetOptSTR) != 'Y')
		{
			system("cls");
			LogoOops();
			Tips(3);//補秘嗤列
			printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'Y')//卦指貧匯雫
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
			printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y')
			{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'Y')//卦指貧匯雫
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
				printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
				gets(GetOptSTR);//資函喘薩補秘
				while (GetOption(GetOptSTR) != 'Y')
				{
					system("cls");
					LogoOops();
					Tips(3);//補秘嗤列
					printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'Y')//卦指貧匯雫
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
		printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
		gets(GetOptSTR);//資函喘薩補秘
		while (GetOption(GetOptSTR) != 'Y')
		{
			system("cls");
			LogoOops();
			Tips(3);//補秘嗤列
			printf("\t\t\t\t\t\t\t\t鳩範萩梓Y卦指貧匯雫:");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'Y')//卦指貧匯雫
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
			printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y')
			{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'Y')//卦指貧匯雫
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
				printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
				gets(GetOptSTR);//資函喘薩補秘
				while (GetOption(GetOptSTR) != 'Y')
				{
					system("cls");
					LogoOops();
					Tips(3);//補秘嗤列
					printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'Y')//卦指貧匯雫
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
		printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
		gets(GetOptSTR);//資函喘薩補秘
		while (GetOption(GetOptSTR) != 'Y')
		{
			system("cls");
			LogoOops();
			Tips(3);//補秘嗤列
			printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
			gets(GetOptSTR);
		}
		if (GetOption(GetOptSTR) == 'Y')//卦指貧匯雫
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
			printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
			gets(GetOptSTR);//資函喘薩補秘
			while (GetOption(GetOptSTR) != 'Y')
			{
				system("cls");
				LogoOops();
				Tips(3);//補秘嗤列
				printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
				gets(GetOptSTR);
			}
			if (GetOption(GetOptSTR) == 'Y')//卦指貧匯雫
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
				printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
				gets(GetOptSTR);//資函喘薩補秘
				while (GetOption(GetOptSTR) != 'Y')
				{
					system("cls");
					LogoOops();
					Tips(3);//補秘嗤列
					printf("\t\t\t\t\t\t\t\t鳩範萩梓'Y'卦指貧匯雫:");
					gets(GetOptSTR);
				}
				if (GetOption(GetOptSTR) == 'Y')//卦指貧匯雫
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

void IfLate()//喘噐登僅喘薩頁倦嘯豚隆住?┠都攀屡詈藜?佚連岻朔??
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

