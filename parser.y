%{
/*
*parser.y 
*programmer : 1615022 박지영, 1515069 한해주, 1515033 송영인
*Date : 6/04/2019
*Description :
*  Modified Mici C 를 위한 파서 구현
* parser를 통해 데이터의 ident의 속성을 찾는다. 찾는 속성은 integer scalar 변수, float scalar 변수, integer array 변수, float array 변수,void 함수명, integer 함수명, float 함수명, …함수의 ..type 의 파라메터, 그리고 지정되지 않은 것을 속성을 잡는다. 
* parser 구현시 해당하는 구문 오류를 잡는다. 
* 잡는 오류는 printError()를 통해 출력되게 된다. 
*/


   #include <stdio.h>
   #include <stdlib.h>
   #include <ctype.h>
   #include <malloc.h>

   #include "glob.h"

   extern type_int;
   extern type_void;
   extern type_float;
   extern type_char;
   extern is_param;

   void line(int);
   void semantic(int);
   extern printError();
   extern yylex();
   extern yyerror(char* s);
%}

%token TEOF TCONST TELSE TIF TEIF TINT TFLOAT TCHAR TSTRING TRETURN TVOID TWHILE
%token TOPENBR TCLOSEBR TOPENSQBR TCLOSESQBR TOPENPRTH TCLOSEPRTH TCOMMA TSEMICOLON TPLUS 
%token TMINUS TMULTIPLY TDIVIDE TMOD
%token TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TNOT TAND TOR
%token TEQUAL TNOTEQU TLESS TGREAT TLESSE TGREATE
%token TINC TDEC
%token TNUMBER
%token TIDENT TLONGIDENT TFALSEIDENT
%token TERROR
%% 

mini_c          : translation_unit       
				;

translation_unit    : external_dcl            
					| translation_unit external_dcl   
					;

external_dcl       : function_def            
				   | declaration            
				   | TIDENT TSEMICOLON
				   | TIDENT error
				   {
					  yyerrok;
					  printError(wrong_st);
				   }
				   ;

function_def       : function_header compound_st      
				   | function_header TSEMICOLON
				   | function_header error
				   {
					  yyerrok;
					  printError(wrong_funcdef);
				   }
				   ;

function_header    : dcl_spec function_name formal_param   
					;

dcl_spec       : dcl_specifiers         
				;

dcl_specifiers      : dcl_specifier            
					| dcl_specifiers dcl_specifier      
					;

dcl_specifier       : type_qualifier            
					 | type_specifier        
					 ;

type_qualifier       : TCONST            
					 ;

type_specifier       : TINT      {type_int = 1;
                                 type_void = 0;
                                 type_float = 0;
                                 type_char = 0;
                                 }
					| TVOID      {type_int = 0;
                                 type_void = 1;
                                 type_float = 0;
                                 type_char = 0;
                                 }
					| TFLOAT     {type_int = 0;
                                 type_void = 0;
                                 type_float = 1;
                                 type_char = 0;
                                 }
					| TCHAR      {type_int = 0;
                                 type_void = 0;
                                 type_float = 0;
                                 type_char = 1;
                                 }
					;
          
function_name    : TIDENT    {
                              if(look_id->type==0){
								  look_id->type = 5; // function name
								  type_int = 0;
								  type_void = 0;
								  type_float = 0;
								  type_char = 0;
								  look_tmp = look_id;
                              }
                             }
				| error {
						yyerrok;
						printError(wrong_funcdef);
						}
				;

formal_param       : TOPENPRTH opt_formal_param TCLOSEPRTH 
					;
					
opt_formal_param    : formal_param_list        
					|               
					;
					
formal_param_list    : param_dcl            
					| formal_param_list TCOMMA param_dcl    
					| formal_param_list param_dcl {
													  yyerrok;
													  printError(nocomma);
												  }
					;

param_dcl       : dcl_spec declarator         {
												if(look_id->type==1){
													type_int = 0;
													type_void = 0;
													type_float = 0;
													type_char = 0;
													look_id->type=9; 
												}
											}
				;
                     
compound_st       : TOPENBR compound TCLOSEBR    
				| TOPENBR compound error
				{
				   yyerrok;
				   printError(nobrace);
				}
				;

compound : opt_dcl_list opt_stat_list 
		;
		
opt_dcl_list       : declaration_list         
					 |               
					 ;
					 
declaration_list    : declaration            
					 | declaration_list declaration       
					 ;

declaration       : dcl_spec init_dcl_list TSEMICOLON      {
															 type_int = 0;
															 type_void = 0;
															 type_float = 0;
															 type_char = 0;
															}            
				   | dcl_spec init_dcl_list error
												   {
													   type_int = 0;
													   type_void = 0;
													   type_float = 0;
													   type_char = 0;
													   printError(nosemi);
												   }
				   ;

init_dcl_list       : init_declarator         
         | init_dcl_list TCOMMA init_declarator    
		 ;
		 
init_declarator    : declarator               
          | declarator TASSIGN TNUMBER       
          | declarator TASSIGN TSTRING
          ;
          
declarator       : TIDENT               {
                                 if(look_id->type==0)
                                 {
                                    if(type_int == 1)
                                       look_id->type = 1;
                                    if(type_void == 1)
                                       look_id->type = 2;
                                    if(type_float == 1)
                                       look_id->type = 3;
                                    if(type_char == 1)
                                       look_id->type = 4;
                                    
                                 }
                                 look_tmp = look_id;
                                 
                                 }
              | TIDENT TOPENSQBR opt_number TCLOSESQBR      {
                                                     if(look_id->type==0) {
                                                        if(type_int == 1)
                                                           look_id->type = 6; // integer array variable
                                                        else if(type_float == 1)
                                                           look_id->type = 7; // float array variable
                                                        else if(type_char == 1)
                                                           look_id->type = 8; // char array variable
                                                     }
                                                           look_tmp = look_id;
                                                  }

                                                  
              | TIDENT TOPENSQBR opt_number error
              {
                 yyerrok;
                 printError(nobracket);
              };


opt_number       : TNUMBER            
              |               
			  ;
			  
opt_stat_list       : statement_list         
          |               
		  ;
		  
statement_list       : statement            
          | statement_list statement       
		  ;
		  
statement       : compound_st         
            | expression_st         
            | if_st               
            | while_st            
            | return_st            
            ;
			
expression_st    : opt_expression TSEMICOLON         
            | expression error
            {
               yyerrok;
               printError(nosemi);
            }
            ;

opt_expression    : expression            
          |              
		  ;
		  
if_st          : TIF TOPENPRTH expression TCLOSEPRTH statement TEIF    
         | TIF TOPENPRTH expression TCLOSEPRTH statement TELSE statement TEIF    
		 ;
		 
while_st       : TWHILE TOPENPRTH expression TCLOSEPRTH statement    
				;
				
return_st       : TRETURN opt_expression TSEMICOLON      
				;
				
expression       : assignment_exp         
				;
				
assignment_exp    : logical_or_exp         
         | unary_exp TASSIGN assignment_exp       
         | unary_exp TADDASSIGN assignment_exp    
         | unary_exp TSUBASSIGN assignment_exp    
         | unary_exp TMULASSIGN assignment_exp    
         | unary_exp TDIVASSIGN assignment_exp    
         | unary_exp TMODASSIGN assignment_exp    
         ;
		 
logical_or_exp    : logical_and_exp         
         | logical_or_exp TOR logical_and_exp    
		 ;
		 
logical_and_exp    : equality_exp            
          | logical_and_exp TAND equality_exp    
		  ;
		  
equality_exp       : relational_exp         
         | equality_exp TEQUAL relational_exp    
         | equality_exp TNOTEQU relational_exp    
		 ;
		 
relational_exp    : additive_exp          
         | relational_exp TGREAT additive_exp    
         | relational_exp TLESS additive_exp    
         | relational_exp TGREATE additive_exp    
         | relational_exp TLESSE additive_exp    
		 ;
		 
additive_exp       : multiplicative_exp         
         | additive_exp TPLUS multiplicative_exp    
         | additive_exp TMINUS multiplicative_exp    
		 ;
		 
multiplicative_exp    : unary_exp            
             | multiplicative_exp TMULTIPLY unary_exp    
             | multiplicative_exp TDIVIDE unary_exp    
             | multiplicative_exp TMOD unary_exp    
			 ;
			 
unary_exp       : postfix_exp            
            | TMINUS unary_exp            
            | TNOT unary_exp            
            | TINC unary_exp         
            | TDEC unary_exp         
			;
			
postfix_exp       : primary_exp            
               | postfix_exp TOPENSQBR expression TCLOSESQBR    
               | postfix_exp TOPENPRTH opt_actual_param TCLOSEPRTH    
               | postfix_exp TINC         
               | postfix_exp TDEC         
			   ;
			   
opt_actual_param    : actual_param            
           |               
		   ;
		   
actual_param       : actual_param_list         
					;
					
actual_param_list    : assignment_exp         
            | actual_param_list TCOMMA assignment_exp    
			;

primary_exp       : TIDENT            {
                           if(look_id->type == 0) look_id->type = 10;
                           }
              | TNUMBER            
              | TSTRING
              | TOPENPRTH expression TCLOSEPRTH         
			  ;
             

%%