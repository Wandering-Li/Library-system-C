
/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/
/*                                                     Logo譜柴                                                       */
/*！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！*/

void LogoGo(int flag)//Logo痕方喘噐婢幣Logo 1殴慧 0音殴慧
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
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
	strcpy(Logo1[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
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

void LogoOops()//LogoOops痕方喘噐婢幣Error議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoRegist()//LogoRegist痕方喘噐婢幣Regist議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoLogin()//LogoLogin痕方喘噐婢幣Login議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoVisitor()//LogoVisitor痕方喘噐婢幣嗄人鞠村順中議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoUser()//LogoUser痕方喘噐婢幣噸宥喘薩鞠村順中議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoAdmin()//LogoAdmin痕方喘噐婢幣砿尖埀鞠村順中議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookIn()//LogoBookIn痕方喘噐婢幣慕汐秘垂順中議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookOut()//LogoBookOut痕方喘噐婢幣慕汐竃垂順中議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookSearch()//LogoBookSearch痕方喘噐婢幣臥孀夕慕議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoUserSearch()//LogoSearchUser痕方喘噐婢幣臥孀喘薩佚連議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookBorrow()//BookBorrow痕方喘噐婢幣処慕順中議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookReturn()//BookReturn痕方喘噐婢幣珊慕順中議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoHistory()//喘噐煽雰佚連朴儖順中議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookAdjust()//LogoBookAdjust痕方喘噐婢幣俐個夕慕佚連議logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t面面面面面面     夕慕砿尖狼由\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}
