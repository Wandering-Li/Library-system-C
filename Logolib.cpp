
/*��������������������������������������������������������������������������������������������������������������������*/
/*                                                     Logo���                                                       */
/*��������������������������������������������������������������������������������������������������������������������*/

void LogoGo(int flag)//Logo��������չʾLogo 1���� 0������
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
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
	strcpy(Logo1[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
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

void LogoOops()//LogoOops��������չʾError��logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoRegist()//LogoRegist��������չʾRegist��logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoLogin()//LogoLogin��������չʾLogin��logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoVisitor()//LogoVisitor��������չʾ�ο͵�¼�����logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoUser()//LogoUser��������չʾ��ͨ�û���¼�����logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoAdmin()//LogoAdmin��������չʾ����Ա��¼�����logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookIn()//LogoBookIn��������չʾ�鼮�������logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookOut()//LogoBookOut��������չʾ�鼮��������logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookSearch()//LogoBookSearch��������չʾ����ͼ���logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoUserSearch()//LogoSearchUser��������չʾ�����û���Ϣ��logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookBorrow()//BookBorrow��������չʾ��������logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookReturn()//BookReturn��������չʾ��������logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoHistory()//������ʷ��Ϣ��Ѱ�����logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}

void LogoBookAdjust()//LogoBookAdjust��������չʾ�޸�ͼ����Ϣ��logo
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
	strcpy(Logo[9], "\t\t\t\t\t\t\t\t\t\t������������     ͼ�����ϵͳ\n");
	strcpy(Logo[10], "\t\t\t\t\t\t\t\t\t\tTX6 library management system\n");
	printf("\n\n\n");
	for (i = 0; i < 11; i++)
		printf("%s", Logo[i]);
	printf("\n\n\n");
}
