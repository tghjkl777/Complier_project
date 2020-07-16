/*
* main.c
* Programmer: 1615022 박지영, 1515069 한해주, 1515033 송영인
* Date: 6/ 04/ 2019
* Description:
* yyparse()를 통해 입력 데이터에 대한 토큰 분석과 구문 분석을 진행한다. 
스캐너와 파서를 통해 잡혀진 에러를 reportError.c 의 정의된 함수 printNumOfErrors() 가 그 에러가 무엇인지를 출력한다. 
* printNumOfErrors()는  총 에러의 개수를 출력한다. 
* PrintHStable()는 스캐너를 통해 잡혀진 identifer들의 토큰들을 해시코드, 그 identifier의 이름, type 그리고, 이 identifier가 쓰여진 줄 넘버를 출력한다. 

*/


#include <stdio.h>
#include <stdlib.h>
#include "glob.h"
#include "tn.h"

extern yylex();
extern char *yytext;

extern int cErrors;             // 에러 갯수 카운팅
extern int cLine;               // 줄 번호 카운팅
extern void printNumOfErrors(); // 에러 갯수 출력 함수
extern void PrintHStable();     // HS symbol table 출력 함수

extern int yyparse();
extern yyerror(char* s);


void main() {
	cErrors = 0; // 에러 갯수 0개로 초기화
	cLine = 1;   // 줄 번호 1로 초기화

	printf("*** MiniC parsing begins\n");
	yyparse(); // 파서 호출해 문법 분석
	printf("Parsing ends. *** \n");
	printNumOfErrors(); // 에러 개수 출력

	if(cErrors == 0) // 스캐너 및 파서에서 에러가 발생하지 않은 경우에만 HS symbol table 출력
		PrintHStable(); 
}