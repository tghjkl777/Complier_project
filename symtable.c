/*
* symtable.c
* Programmer: 1615022 박지영, 1515069 한해주, 1515033 송영인
* Date: 6/ 04/ 2019
* Description:
main 함수에서 scanner에 의해 올바른 identifier라고 판단되어진
token들을 symbol table과 hash table에 삽입하는 작업, 해시코드 계산 등을 수행하는 연산함수들이 저장되어 있다. 

이전 과제는 이 symtable 과 다른 c 프로그램에서 ident내용을 읽었지만 이번 symtable에서는 이미
scanner.l 에서 identifier내용을 읽고 이에 대한 해시코드 계산, 해시테이블 보기,해시테이블 삽입이 이루어지면  

.
void computeHashValue(int nextID, int nextFree)
symbol들의 ASCII값을 바탕으로 해시값을 계산하는 함수.
어떤 symbol의 해시값은 symbol을 구성하는 모든 character의 ASCII값 합산을 hash
table 크기로 나눈 값이 됨.

void lookupHT(int nextID, int hsValue):
어떤 symbol과 해시값 정보를 해시 테이블에 저장하려고 할 때,
이미 동일한 symbol이 해시테이블에 존재하고 있는지 확인하는 함수.
void addHT(int hsValue):
해시값을 해시테이블에 저장하는 함수.
만약 서로 다른 symbol이 같은 해시값을 갖는다면 연결리스트를 이용해서 구현.

void PrintHStable() : 해시테이블 출력함수 
해시테이블에 저장된 identifier의 해시코드값과, 그들의 속성 그리고 그 identifier가 있는 줄번호를 출력한다. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glob.h"
#include "tn.h"

#define STsize 1000
#define HTsize 1000

extern char *yytext;
extern int yyleng;

extern HTpointer HT[HTsize];
extern char ST[STsize];
extern int cLine;
extern int cErrors;
extern void printError(ERRORS);

// 심볼테이블, 해시테이블 관리에 필요한 변수
int nextid;
int nextfree;
int hashcode;
int found;

int foundIdx; // 해시테이블 탐색 시에 찾은 identifier의 심볼테이블에서의 시작 인덱스
ERRORS err; // 에러 관련 변수

// 해시값 계산
void ComputeHS(int nextID, int nextFree) {
	int i;
	int sum = 0;

	for (i = nextID; i < nextFree - 1; i++) {
		sum += (int)ST[i];
	}
	hashcode = sum % HTsize; // 전역변수 hashCode에 해시값 저장
}

// 해시테이블 삽입 시 동일값 존재 여부를 파악하고 그에 맞게 처리
void LookupHS(int nextID, int hsValue)
{
	int i, j;
	HTpointer target;
	found = 0;

	// 대응되는 해시값이 이미 HT에 있는 경우
	if (HT[hsValue] != NULL) {
		target = HT[hsValue]; // 시작 포인터 설정

		while (target != NULL && found == 0) {
			found = 1;
			i = target->index;
			j = nextID;
			foundIdx = i; // 전역변수 foundIdx에 ST 인덱스 값 저장

			while (ST[i] != '\0' && ST[j] != '\0' && found == 1) { // identifier의 구성 character가 모두 일치하는지 검사
				if (ST[i] != ST[j]) // 시작 캐릭터 다른 경우 -> 찾는 identifier 아닌 경우
					found = 0;
				else { // 시작 캐릭터 같은 경우 -> 계속해서 모든 인덱스의 캐릭터가 일치하는지 확인
					i++;
					j++;
				}
			}
			target = target->next; // 연결리스트 타고 넘어가면서 인덱스 탐색 
		}
	}
}

// 해시테이블 출력 함수
void PrintHStable() 
{
	printf("\n\n[[  HASH TABLE  ]]\n");
	HTpointer here;
	int i, j;
	for(i=0; i<HTsize; i++){
		if (HT[i] != NULL) {
			here = HT[i];
			do {
				printf("Hash Code %d: (", i);
				for (j = here->index; ST[j] != '\0'; j++) {
					printf("%c", ST[j]);
				}
				printf(" : ");
				switch (here->type) {
				case 1:
					printf("integer scalar variable, line = %d)\n", here->linenum);
					break;
				case 2:
					printf("void scalar variable, line = %d)\n", here->linenum);
					break;
				case 3:
					printf("float scalar variable, line = %d)\n", here->linenum);
					break;
				case 4:
					printf("char scalar variable, line = %d)\n", here->linenum);
					break;
				case 5:
					printf("function name, line = %d)\n", here->linenum);
					break;
				case 6:
					printf("integer array variable, line = %d)\n", here->linenum);
					break;
				case 7:
					printf("float array variable, line = %d)\n", here->linenum);
					break;
				case 8:
					printf("char array variable, line = %d)\n", here->linenum);
					break;
				case 9:
					printf("function parameter, line = %d)\n", here->linenum);
					break;
				case 10:
					printf("not defined function name or parameter, line = %d)\n", here->linenum);
					break;
				
				}
				here = here->next;
			} while (here != NULL);
		}
	}
}

// 해시테이블에 삽입
void AddHT(int hsValue) {
	HTpointer newPtr = (HTpointer)malloc(sizeof(HT));
	
	// 새로 삽입하는 경우
	if (HT[hsValue] == NULL) {
		newPtr->type = 0;
		newPtr->index = nextid;
		newPtr->linenum = cLine; // 줄번호 추가
		newPtr->next = NULL;
	}
	// 겹치는 해시값을 가질 때 삽입하는 경우 -> 연결리스트의 맨 앞에 삽입
	else {
		newPtr->type = 0;
		newPtr->index = nextid;
		newPtr->linenum = cLine; // 줄번호 추가
		newPtr->next = HT[hsValue];
	}
	HT[hsValue] = newPtr;
	look_id = newPtr;
}