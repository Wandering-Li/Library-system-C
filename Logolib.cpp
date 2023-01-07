
/*——————————————————————————————————————————————————————————*/
/*                                                     Logo设计                                                       */
/*——————————————————————————————————————————————————————————*/

void LogoGo(int flag)//Logo函数用于展示Logo 1播放 0不播放
{
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t***         *****   ******   ******        ***            **\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t***   *****   ***   ******   ****   *****    *****    ******\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t***   *****   ***   ******   ***   ***************    ******\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t***         *****   ******   ***   ***************    ******\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t***   *****   ***   ******   ***   ***************    ******\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t***   *****   ****   ****   *****   *****    *****    ******\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t***         ********      *********        *******    ******\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	char Logo1[11][1000];
	strcpy(Logo1[0], "\t\t\t\t\t\t\t\t                                                            \n");
	strcpy(Logo1[1], "\t\t\t\t\t\t\t\t   ---------     ---      ---      --------   ------------  \n");
	strcpy(Logo1[2], "\t\t\t\t\t\t\t\t   ---     ---   ---      ---    ---     ----     ----      \n");
	strcpy(Logo1[3], "\t\t\t\t\t\t\t\t   ---     ---   ---      ---   ---               ----      \n");
	strcpy(Logo1[4], "\t\t\t\t\t\t\t\t   ---------     ---      ---   ---               ----      \n");
	strcpy(Logo1[5], "\t\t\t\t\t\t\t\t   ---     ---   ---      ---   ---               ----      \n");
	strcpy(Logo1[6], "\t\t\t\t\t\t\t\t   ---     ---    ---    ---     ---     ----     ----      \n");
	strcpy(Logo1[7], "\t\t\t\t\t\t\t\t   ---------        ------         --------       ----      \n");
	strcpy(Logo1[8], "\t\t\t\t\t\t\t\t                                                            \n");
	strcpy(Logo1[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo1[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	int i = 0, j = 0, k = 0, l = 16;
	if (flag == 0)
	{
		printf("\n\n\n");
		for (i = 0; i < 11; i++)
			printf("%s", Logo[i]);
		printf("\n\n\n");
	}
	else
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		for (i = 0; i < 11; i++)
			printf("%s", Logo[i]);
		while (l - 3 > 0)
		{
			system("cls");
			for (k = 0; k < l; k++)
				printf("\n");
			for (i = 0; i < 11; i++)
				printf("%s", Logo[i]);
			Sleep(50);
			l--;
		}
		for (j = 0; j < 10; j++)
		{
			system("cls");
			printf("\n\n\n");
			for (i = 0; i < 11; i++)
				printf("%s", Logo1[i]);
			Sleep(80);
			system("cls");
			printf("\n\n\n");
			for (i = 0; i < 11; i++)
				printf("%s", Logo[i]);
			Sleep(80);
		}
		printf("\n\n\n");
	}
}

void LogoOops()//LogoOops函数用于展示Error的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t****         ******************************************  ***\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t***  *******  *****************************************  ***\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t***  *******  ****       ****        *****        *****  ***\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t***  *******  ***  *****  ***  *****  ***  ************  ***\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t***  *******  ***  *****  ***  *****  ****       ******  ***\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t***  *******  ***  *****  ***        ***********  **********\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t****         *****       ****  **********        ******  ***\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoRegist()//LogoRegist函数用于展示Regist的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t***       **************************************************\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t***  ****  *****************************************  ******\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t***  ****  ****      *****       ***  ***       ****  ******\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t***  ****  ***  ****  ***  ****  *******  ********        **\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t***       ****        ***        ***  ***       ****  ******\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t***  **  *****  ***************  ***  *********  ***  **  **\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t***  ****   ***      *****       ***  ***       ****      **\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoLogin()//LogoLogin函数用于展示Login的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t***  *******************************************************\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t***  *******************************************************\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t***  ************       ******        ****  ****  *      ***\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t***  ***********  *****  ****  *****  **********   *****  **\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t***  ***********  *****  ****         ****  ****  ******  **\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t***  ***********  *****  ***********  ****  ****  ******  **\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t***          ****       ******        ****  ****  ******  **\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoVisitor()//LogoVisitor函数用于展示游客登录界面的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t*******************                       *******************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t*******************  *******     *******  *******************\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t*******************  *****   @@@   *****  *******************\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t*******************  *****  @   @  *****  *******************\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t*******************  *****     @   *****  *******************\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t*******************  *******  @   ******  *******************\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t*******************  ****           ****  *******************\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t*******************  **       #       **  *******************\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t*******************                       *******************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoUser()//LogoUser函数用于展示普通用户登录界面的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t*******************                       *******************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t*******************  *******     *******  *******************\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t*******************  *****         *****  *******************\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t*******************  *****         *****  *******************\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t*******************  *****         *****  *******************\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t*******************  *******     *******  *******************\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t*******************  ****   *****   ****  *******************\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t*******************  **   *********   **  *******************\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t*******************                       *******************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoAdmin()//LogoAdmin函数用于展示管理员登录界面的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t*******************                       ******************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t*******************  *******     *******  ******************\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t*******************  *****         *****  ******************\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t*******************  *****         *****  ******************\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t*******************  *****         *****  ******************\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t*******************  *******     *******  ******************\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t*******************  ****   ****||  ****  ******************\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t*******************  **   ******<>*   **  ******************\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t*******************                       ******************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookIn()//LogoBookIn函数用于展示书籍入库界面的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t******************   *********************          ********\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t******************     ***************** *******************\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t********            ***  ***************          **********\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t********            *****  ************ ********************\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t********            ***  ****************          *********\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t******************     ***************** *******************\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t******************   ********************          *********\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookOut()//LogoBookOut函数用于展示书籍出库界面的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t***************  *************************          ********\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t************     *********************** *******************\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t**********  ***            *************          **********\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t********  *****            ************ ********************\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t**********  ***            **************          *********\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t************     *********************** *******************\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t***************  ************************          *********\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookSearch()//LogoBookSearch函数用于展示查找图书的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t***********      **************          ||          *******\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t**********     @  *************  ~~~~~~  ||  ~~~~~~  *******\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t**********        *************  ~~~~~~  ||  ~~~~~~  *******\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t***********      **************  ~~~~~~  ||  ~~~~~~  *******\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t***************   *************  ~~~~~~  ||  ~~~~~~  *******\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t****************   ************  ~~~~~~  ||  ~~~~~~  *******\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t*****************   ***********          ||          *******\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoUserSearch()//LogoSearchUser函数用于展示查找用户信息的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t************      ***************                   ********\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t***********     @  **************  ****  ****       ********\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t***********        **************  ***    ***  XXX  ********\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t************      ***************  ****  ****   @   ********\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t****************   **************  **      **  ~~~  ********\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t*****************   *************   xxxxxxxx   ~~~  ********\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t******************   ************                   ********\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookBorrow()//BookBorrow函数用于展示借书界面的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t********** ** ************** ****************           ****\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t********* ** ** ***********  ****************   ~~~~~   ****\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t**** *** ** ** ** ********           ********   ~~~~~   ****\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t**** ** ** ** ** ********            ********           ****\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t****           ***********           ********           ****\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t****          *************  ****************   xxxxx   ****\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t*****        *************** ****************           ****\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookReturn()//BookReturn函数用于展示还书界面的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t********** ** ******************* ***********           ****\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t********* ** ** *****************  **********   ~~~~~   ****\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t**** *** ** ** ** *******           *********   ~~~~~   ****\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t**** ** ** ** ** ********            ********           ****\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t****           **********           *********           ****\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t****          *******************  **********   xxxxx   ****\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t*****        ******************** ***********           ****\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoHistory()//用于历史信息搜寻界面的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t********      ********************* ***** ***** ************\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t*******     @  ******************* ****** ****** ***********\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t*******        ****************** ******* ******* **********\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t********      ******************* ******* ------- **********\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t************   ****************** *************** **********\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t*************   ****************** ************* ***********\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t**************   ****************** *********** ************\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookAdjust()//LogoBookAdjust函数用于展示修改图书信息的logo
{
	int i = 0;
	char Logo[11][1000];
	strcpy(Logo[0], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[1], "\t\t\t\t\t\t\t\t************ ****** ***********          ||          *******\n");
	strcpy(Logo[2], "\t\t\t\t\t\t\t\t***********  ******  **********  ~~~~~~  ||  ~~~~~~  *******\n");
	strcpy(Logo[3], "\t\t\t\t\t\t\t\t***********   ****   **********  ~~~~~~  ||  ~~~~~~  *******\n");
	strcpy(Logo[4], "\t\t\t\t\t\t\t\t************        ***********  ~~~~~~  ||  ~~~~~~  *******\n");
	strcpy(Logo[5], "\t\t\t\t\t\t\t\t**************    *************  ~~~~~~  ||  ~~~~~~  *******\n");
	strcpy(Logo[6], "\t\t\t\t\t\t\t\t**************    *************  ~~~~~~  ||  ~~~~~~  *******\n");
	strcpy(Logo[7], "\t\t\t\t\t\t\t\t**************    *************          ||          *******\n");
	strcpy(Logo[8], "\t\t\t\t\t\t\t\t************************************************************\n");
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t烫烫烫烫烫烫     图书管理系统\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}
