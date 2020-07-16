/*
* main.c
* Programmer: 1615022 ������, 1515069 ������, 1515033 �ۿ���
* Date: 6/ 04/ 2019
* Description:
* yyparse()�� ���� �Է� �����Ϳ� ���� ��ū �м��� ���� �м��� �����Ѵ�. 
��ĳ�ʿ� �ļ��� ���� ������ ������ reportError.c �� ���ǵ� �Լ� printNumOfErrors() �� �� ������ ���������� ����Ѵ�. 
* printNumOfErrors()��  �� ������ ������ ����Ѵ�. 
* PrintHStable()�� ��ĳ�ʸ� ���� ������ identifer���� ��ū���� �ؽ��ڵ�, �� identifier�� �̸�, type �׸���, �� identifier�� ������ �� �ѹ��� ����Ѵ�. 

*/


#include <stdio.h>
#include <stdlib.h>
#include "glob.h"
#include "tn.h"

extern yylex();
extern char *yytext;

extern int cErrors;             // ���� ���� ī����
extern int cLine;               // �� ��ȣ ī����
extern void printNumOfErrors(); // ���� ���� ��� �Լ�
extern void PrintHStable();     // HS symbol table ��� �Լ�

extern int yyparse();
extern yyerror(char* s);


void main() {
	cErrors = 0; // ���� ���� 0���� �ʱ�ȭ
	cLine = 1;   // �� ��ȣ 1�� �ʱ�ȭ

	printf("*** MiniC parsing begins\n");
	yyparse(); // �ļ� ȣ���� ���� �м�
	printf("Parsing ends. *** \n");
	printNumOfErrors(); // ���� ���� ���

	if(cErrors == 0) // ��ĳ�� �� �ļ����� ������ �߻����� ���� ��쿡�� HS symbol table ���
		PrintHStable(); 
}