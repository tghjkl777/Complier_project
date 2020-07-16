/*
* reportError.c
* Programmer: 1615022 박지영, 1515069 한해주, 1515033 송영인
* Date: 6/ 04/ 2019
* Description:

scanner 와 parser를 통해 걸러진 에러들의 종류를 출력한다. 

void printError(ERRORS err):
에러 타입에 맞는 에러 메시지 출력.
void printNumOfErrors():
발생한 총 에러의 수를 사용자에게 출력.

*/
#include <stdio.h>
#include <stdlib.h>
#include "glob.h"

yyerror(s)
char* s;
{
}

// 상황에 맞는 에러메시지 출력
void printError(ERRORS err) {
	
	switch (err) {
	case STOverflow: { // 심볼테이블 오버플로우
		cErrors++;
		exit(0);
		break;
	}
	case longID: { // 길이가 10을 넘는 identifier
		cErrors++;
		printf("%d\t\tToo long identifier!\n", cLine);
		break;
	}
	case falseID: { // 숫자로 시작하는 잘못된 identifier
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

// 총 에러 수 출력
void printNumOfErrors() {
	if (cErrors == 0)
		printf("\nNO errors detected\n");
	else
		printf("\n%d errors detected\n", cErrors);
}