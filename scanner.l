%{
/*
*scanner.l 
*programmer : 1615022 박지영, 1515069 한해주, 1515033 송영인
*Date : 6/04/2019
*Description :
*  Modified Mici C 를 위한 스캐너 구현
*이전 과제와 다르게 float 와 char 자료형에 대한 키워드를 추가 하였다. 
* 이전 과제와 다르게 이쪽 스캐너에 분류된 idetifier에 대해서 심벌 테이블, 해시테이블 생성을 위한 연산을 수행한다. 수행되는 연산은 symtable.c에 지정된 함수들을 사용한다. 
* 스캐너에서 잡을수 있는 에러또한 이쪽에 선별한다. 선별된 에러는 longID,falseID 이다 스택 오버 플로우느 포함하지 않았다. 
*/

#include <stdio.h>
#include <stdlib.h>

#include "tn.h"
#include "glob.h"


extern ComputeHS(int nextid, int nextfree);
extern LookupHS(int nextid, int nextfree);
extern AddHT(int hashcode);
extern PrintHStable();
extern printError(ERRORS);
extern yyerror(char* s);

extern int cLine;
extern int cErrors;

extern type_int;
extern type_void;
extern type_float;
extern type_char;
extern is_param;

int i;
%}

%%

"const"               return(TCONST);
"else"               return(TELSE);
"if"               return(TIF);
"endif"		return(TEIF);
"int"               return(TINT);
"float"               return(TFLOAT);
"char"               return(TCHAR);
"return"            return(TRETURN);
"void"               return(TVOID);
"while"               return(TWHILE);

"{"                      return(TOPENBR);
"}"               return(TCLOSEBR);
"["               return(TOPENSQBR);
"]"               return(TCLOSESQBR);
"("               return(TOPENPRTH);
")"               return(TCLOSEPRTH);
","               return(TCOMMA);
";"               return(TSEMICOLON);

"+"               return(TPLUS);
"-"               return(TMINUS);
"*"               return(TMULTIPLY);
"/"               return(TDIVIDE);
"%"               return(TMOD);

"="               return(TASSIGN);
"+="               return(TADDASSIGN);
"-="               return(TSUBASSIGN);
"*="               return(TMULASSIGN);
"/="               return(TDIVASSIGN);
"%="               return(TMODASSIGN);

"!"               return(TNOT);
"&&"               return(TAND);
"||"               return(TOR);

"=="               return(TEQUAL);
"!="               return(TNOTEQU);
"<"               return(TLESS);
">"               return(TGREAT);
"<="               return(TLESSE);
">="               return(TGREATE);

"++"               return(TINC);
"--"               return(TDEC);

0[0-7]+ 					|
[+-]?[0-9]+					|
0(x|X)[0-9A-Fa-f]+			|
[0-9]+"."[0-9]+(e[+-]?[0-9]+)?   return(TNUMBER);

[A-Za-z_][A-Za-z0-9_]?[A-Za-z0-9_]?[A-Za-z0-9_]?[A-Za-z0-9_]?[A-Za-z0-9_]?[A-Za-z0-9_]?[A-Za-z0-9_]?[A-Za-z0-9_]?[A-Za-z0-9_]?	{
								if(nextfree>=STsize){
									printError(STOverflow);
									//printf("Error>> OVERFLOW\n");
									//PrintHStable();
									exit(1);
								}
								nextid = nextfree;
								nextfree += (yyleng+1);
								for(i=0; i<yyleng; i++){
									ST[nextid+i] = yytext[i];
								}
								ComputeHS(nextid, nextfree);
								LookupHS(nextid, hashcode);

								if(!found){
									AddHT(hashcode);
								}
								else{
									for(i=nextid; i<nextfree-1; i++){
										ST[i] = '\0';
									}
									nextfree = nextid;
								}
								return(TIDENT);

							}

[A-Za-z_][A-Za-z0-9_]*	{
						printError(longID);
						//return(TLONGIDENT);
					}
[0-9][A-Za-z0-9_]+ 		{
							printError(falseID);
							//return(TFALSEIDENT);
						}

\"(\\.|[^\"])*\"      {return TSTRING;}
							
"//".*               ;
[ \t]               ;
"\n"            {cLine++;}
.               {cErrors++; return(TERROR);}
%%

int yywrap()
{
   return 1;
}