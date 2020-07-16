/*
* reportError.c
* Programmer: 1615022 ������, 1515069 ������, 1515033 �ۿ���
* Date: 6/ 04/ 2019
* Description:

scanner �� parser�� ���� �ɷ��� �������� ������ ����Ѵ�. 

void printError(ERRORS err):
���� Ÿ�Կ� �´� ���� �޽��� ���.
void printNumOfErrors():
�߻��� �� ������ ���� ����ڿ��� ���.

*/
#include <stdio.h>
#include <stdlib.h>
#include "glob.h"

yyerror(s)
char* s;
{
}

// ��Ȳ�� �´� �����޽��� ���
void printError(ERRORS err) {
	
	switch (err) {
	case STOverflow: { // �ɺ����̺� �����÷ο�
		cErrors++;
		exit(0);
		break;
	}
	case longID: { // ���̰� 10�� �Ѵ� identifier
		cErrors++;
		printf("%d\t\tToo long identifier!\n", cLine);
		break;
	}
	case falseID: { // ���ڷ� �����ϴ� �߸��� identifier
		cErrors++;
		printf("%d\t\tIllegal identifier!\n", cLine);
		break;
	}
	case wrong_st: {
		cErrors++;
		printf("%d\t\tWrong statement!\n", cLine);
		break;
	}
	case wrong_funcdef: {
		cErrors++;
		printf("%d\t\tWrong function definition!\n", cLine);
		break;
	}
	case nobrace: {
		cErrors++;
		printf("%d\t\tNo brace!\n", cLine);
		break;
	}
	case nosemi: {
		cErrors++;
		printf("%d\t\tNo semicolon!\n", cLine-1);
		break;
	}
	case nobracket: {
		cErrors++;
		printf("%d\t\tNo bracket!\n", cLine);
		break;
	}
	case nocomma: {
		cErrors++;
		printf("%d\t\tNo comma in function parameter!\n", cLine);
		break;
	}
	case notDefinedError: {
		cErrors++;
		printf("%d\t\tNot defined Error!\n", cLine);
		break;
	}
	}

}

// �� ���� �� ���
void printNumOfErrors() {
	if (cErrors == 0)
		printf("\nNO errors detected\n");
	else
		printf("\n%d errors detected\n", cErrors);
}