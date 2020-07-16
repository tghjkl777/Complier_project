/*
* glob.h
* Programmer: 1615022 박지영, 1515069 한해주, 1515033 송영인
* Date: 6/ 04/ 2019
* Description:
* 코드 진행에 필요한 다양한 global 변수들을 저장한다. 
* 심벌 테이블과 헤시 데이블에 필요한 변수
* 에러체크를 위한 에러 타입 
* 에러개수 , 줄 넘버 변수
* 해시테이블에 저장되는 구초체 지정, 이전과제와 다르게 선언된 위치의 라인 넘버와, 속성이 저장된다.
* 파서에러 연산을 수행하기 위한 헤시테이블 구조체 포인터 변수 
*파서에서 변수 타입 지정에 사용된 변수
*
*/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#define STsize 1000 //size of string table
#define HTsize 1000	//size of hash table

// 에러 타입
enum ERRORS { noErr, STOverflow, longID, falseID, 
			wrong_st, wrong_funcdef, nobrace, nosemi, nobracket, nocomma, notDefinedError
			}; 
typedef enum errors ERRORS;

int cErrors; // 발생한 에러 개수
int cLine;	 // 텍스트 줄 번호

typedef struct HTentry* HTpointer;

typedef struct HTentry {
	int index; // HT에 지정된 identifier의 ST에서의 첫 인덱스
	int linenum; // 선언된 줄 번호
	HTpointer next; // 다음 위치를 가리킴
	int type; // 변수 타입
} HTentry;

HTpointer HT[HTsize];
char ST[STsize];

HTpointer look_id; // 현재 ID
HTpointer look_tmp;  // 수정을 위한 포인터

// 심볼테이블, 해시테이블 관리 변수
int nextid;
int nextfree;
int hashcode;
int found;

// 파서에서 변수 타입 지정에 사용된 변수
int type_int;
int type_void;
int type_float;
int type_char;