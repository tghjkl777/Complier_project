
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TEOF	258
#define	TCONST	259
#define	TELSE	260
#define	TIF	261
#define	TEIF	262
#define	TINT	263
#define	TFLOAT	264
#define	TCHAR	265
#define	TSTRING	266
#define	TRETURN	267
#define	TVOID	268
#define	TWHILE	269
#define	TOPENBR	270
#define	TCLOSEBR	271
#define	TOPENSQBR	272
#define	TCLOSESQBR	273
#define	TOPENPRTH	274
#define	TCLOSEPRTH	275
#define	TCOMMA	276
#define	TSEMICOLON	277
#define	TPLUS	278
#define	TMINUS	279
#define	TMULTIPLY	280
#define	TDIVIDE	281
#define	TMOD	282
#define	TASSIGN	283
#define	TADDASSIGN	284
#define	TSUBASSIGN	285
#define	TMULASSIGN	286
#define	TDIVASSIGN	287
#define	TMODASSIGN	288
#define	TNOT	289
#define	TAND	290
#define	TOR	291
#define	TEQUAL	292
#define	TNOTEQU	293
#define	TLESS	294
#define	TGREAT	295
#define	TLESSE	296
#define	TGREATE	297
#define	TINC	298
#define	TDEC	299
#define	TNUMBER	300
#define	TIDENT	301
#define	TLONGIDENT	302
#define	TFALSEIDENT	303
#define	TERROR	304

#line 1 "parser.y"

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

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		172
#define	YYFLAG		-32768
#define	YYNTBASE	50

#define YYTRANSLATE(x) ((unsigned)(x) <= 304 ? yytranslate[x] : 96)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    17,    20,    23,
    26,    30,    32,    34,    37,    39,    41,    43,    45,    47,
    49,    51,    53,    55,    59,    61,    62,    64,    68,    71,
    74,    78,    82,    85,    87,    88,    90,    93,    97,   101,
   103,   107,   109,   113,   117,   119,   124,   129,   131,   132,
   134,   135,   137,   140,   142,   144,   146,   148,   150,   153,
   156,   158,   159,   166,   175,   181,   185,   187,   189,   193,
   197,   201,   205,   209,   213,   215,   219,   221,   225,   227,
   231,   235,   237,   241,   245,   249,   253,   255,   259,   263,
   265,   269,   273,   277,   279,   282,   285,   288,   291,   293,
   298,   303,   306,   309,   311,   312,   314,   316,   320,   322,
   324,   326
};

static const short yyrhs[] = {    51,
     0,    52,     0,    51,    52,     0,    53,     0,    69,     0,
    46,    22,     0,    46,     1,     0,    54,    65,     0,    54,
    22,     0,    54,     1,     0,    55,    60,    61,     0,    56,
     0,    57,     0,    56,    57,     0,    58,     0,    59,     0,
     4,     0,     8,     0,    13,     0,     9,     0,    10,     0,
    46,     0,     1,     0,    19,    62,    20,     0,    63,     0,
     0,    64,     0,    63,    21,    64,     0,    63,    64,     0,
    55,    72,     0,    15,    66,    16,     0,    15,    66,     1,
     0,    67,    74,     0,    68,     0,     0,    69,     0,    68,
    69,     0,    55,    70,    22,     0,    55,    70,     1,     0,
    71,     0,    70,    21,    71,     0,    72,     0,    72,    28,
    45,     0,    72,    28,    11,     0,    46,     0,    46,    17,
    73,    18,     0,    46,    17,    73,     1,     0,    45,     0,
     0,    75,     0,     0,    76,     0,    75,    76,     0,    65,
     0,    77,     0,    79,     0,    80,     0,    81,     0,    78,
    22,     0,    82,     1,     0,    82,     0,     0,     6,    19,
    82,    20,    76,     7,     0,     6,    19,    82,    20,    76,
     5,    76,     7,     0,    14,    19,    82,    20,    76,     0,
    12,    78,    22,     0,    83,     0,    84,     0,    90,    28,
    83,     0,    90,    29,    83,     0,    90,    30,    83,     0,
    90,    31,    83,     0,    90,    32,    83,     0,    90,    33,
    83,     0,    85,     0,    84,    36,    85,     0,    86,     0,
    85,    35,    86,     0,    87,     0,    86,    37,    87,     0,
    86,    38,    87,     0,    88,     0,    87,    40,    88,     0,
    87,    39,    88,     0,    87,    42,    88,     0,    87,    41,
    88,     0,    89,     0,    88,    23,    89,     0,    88,    24,
    89,     0,    90,     0,    89,    25,    90,     0,    89,    26,
    90,     0,    89,    27,    90,     0,    91,     0,    24,    90,
     0,    34,    90,     0,    43,    90,     0,    44,    90,     0,
    95,     0,    91,    17,    82,    18,     0,    91,    19,    92,
    20,     0,    91,    43,     0,    91,    44,     0,    93,     0,
     0,    94,     0,    83,     0,    94,    21,    83,     0,    46,
     0,    45,     0,    11,     0,    19,    82,    20,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    46,    49,    50,    53,    54,    55,    56,    63,    64,    65,
    72,    75,    78,    79,    82,    83,    86,    89,    94,    99,
   104,   111,   121,   127,   130,   131,   134,   135,   136,   142,
   153,   154,   161,   164,   165,   168,   169,   172,   178,   188,
   189,   192,   193,   194,   197,   213,   226,   233,   234,   237,
   238,   241,   242,   245,   246,   247,   248,   249,   252,   253,
   260,   261,   264,   265,   268,   271,   274,   277,   278,   279,
   280,   281,   282,   283,   286,   287,   290,   291,   294,   295,
   296,   299,   300,   301,   302,   303,   306,   307,   308,   311,
   312,   313,   314,   317,   318,   319,   320,   321,   324,   325,
   326,   327,   328,   331,   332,   335,   338,   339,   342,   345,
   346,   347
};

static const char * const yytname[] = {   "$","error","$undefined.","TEOF","TCONST",
"TELSE","TIF","TEIF","TINT","TFLOAT","TCHAR","TSTRING","TRETURN","TVOID","TWHILE",
"TOPENBR","TCLOSEBR","TOPENSQBR","TCLOSESQBR","TOPENPRTH","TCLOSEPRTH","TCOMMA",
"TSEMICOLON","TPLUS","TMINUS","TMULTIPLY","TDIVIDE","TMOD","TASSIGN","TADDASSIGN",
"TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TMODASSIGN","TNOT","TAND","TOR","TEQUAL",
"TNOTEQU","TLESS","TGREAT","TLESSE","TGREATE","TINC","TDEC","TNUMBER","TIDENT",
"TLONGIDENT","TFALSEIDENT","TERROR","mini_c","translation_unit","external_dcl",
"function_def","function_header","dcl_spec","dcl_specifiers","dcl_specifier",
"type_qualifier","type_specifier","function_name","formal_param","opt_formal_param",
"formal_param_list","param_dcl","compound_st","compound","opt_dcl_list","declaration_list",
"declaration","init_dcl_list","init_declarator","declarator","opt_number","opt_stat_list",
"statement_list","statement","expression_st","opt_expression","if_st","while_st",
"return_st","expression","assignment_exp","logical_or_exp","logical_and_exp",
"equality_exp","relational_exp","additive_exp","multiplicative_exp","unary_exp",
"postfix_exp","opt_actual_param","actual_param","actual_param_list","primary_exp",
""
};
#endif

static const short yyr1[] = {     0,
    50,    51,    51,    52,    52,    52,    52,    53,    53,    53,
    54,    55,    56,    56,    57,    57,    58,    59,    59,    59,
    59,    60,    60,    61,    62,    62,    63,    63,    63,    64,
    65,    65,    66,    67,    67,    68,    68,    69,    69,    70,
    70,    71,    71,    71,    72,    72,    72,    73,    73,    74,
    74,    75,    75,    76,    76,    76,    76,    76,    77,    77,
    78,    78,    79,    79,    80,    81,    82,    83,    83,    83,
    83,    83,    83,    83,    84,    84,    85,    85,    86,    86,
    86,    87,    87,    87,    87,    87,    88,    88,    88,    89,
    89,    89,    89,    90,    90,    90,    90,    90,    91,    91,
    91,    91,    91,    92,    92,    93,    94,    94,    95,    95,
    95,    95
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     2,     2,     2,
     3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     3,     1,     0,     1,     3,     2,     2,
     3,     3,     2,     1,     0,     1,     2,     3,     3,     1,
     3,     1,     3,     3,     1,     4,     4,     1,     0,     1,
     0,     1,     2,     1,     1,     1,     1,     1,     2,     2,
     1,     0,     6,     8,     5,     3,     1,     1,     3,     3,
     3,     3,     3,     3,     1,     3,     1,     3,     1,     3,
     3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
     3,     3,     3,     1,     2,     2,     2,     2,     1,     4,
     4,     2,     2,     1,     0,     1,     1,     3,     1,     1,
     1,     3
};

static const short yydefact[] = {     0,
    17,    18,    20,    21,    19,     0,     1,     2,     4,     0,
     0,    12,    13,    15,    16,     5,     7,     6,     3,    10,
    35,     9,     8,    23,    45,     0,     0,    40,    42,    14,
     0,     0,    51,    34,    36,    49,    26,    11,    39,     0,
    38,     0,    45,    32,    31,     0,   111,    62,     0,     0,
     0,     0,     0,     0,   110,   109,    54,    33,    50,    52,
    55,     0,    56,    57,    58,     0,    67,    68,    75,    77,
    79,    82,    87,    90,    94,    99,    37,    48,     0,     0,
     0,    25,    27,    41,    44,    43,     0,     0,    61,     0,
     0,    95,    96,    97,    98,    53,    59,    60,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   105,   102,
   103,    47,    46,    30,    24,     0,    29,     0,    66,     0,
   112,    76,    90,    78,    80,    81,    84,    83,    86,    85,
    88,    89,    91,    92,    93,    69,    70,    71,    72,    73,
    74,     0,   107,     0,   104,   106,    28,    62,    62,   100,
   101,     0,     0,    65,   108,    62,    63,     0,    64,     0,
     0,     0
};

static const short yydefgoto[] = {   170,
     7,     8,     9,    10,    80,    12,    13,    14,    15,    26,
    38,    81,    82,    83,    57,    32,    33,    34,    16,    27,
    28,    29,    79,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,   154,   155,   156,    76
};

static const short yypact[] = {    21,
-32768,-32768,-32768,-32768,-32768,    13,    21,-32768,-32768,    11,
     1,   125,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   125,-32768,-32768,-32768,    33,   -10,    71,-32768,     4,-32768,
    -7,    26,    67,   125,-32768,    42,   125,-32768,-32768,    -7,
-32768,    -1,    29,-32768,-32768,    61,-32768,    97,    87,    97,
    97,    97,    97,    97,-32768,-32768,-32768,-32768,    67,-32768,
-32768,    76,-32768,-32768,-32768,    23,-32768,    84,    91,    32,
    35,    79,    58,   122,    -6,-32768,-32768,-32768,    50,    -7,
   110,   115,-32768,-32768,-32768,-32768,    97,   117,-32768,    97,
   112,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    97,    97,
    97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
    97,    97,    97,    97,    97,    97,    97,    97,    97,-32768,
-32768,-32768,-32768,-32768,-32768,   125,-32768,   136,-32768,   137,
-32768,    91,-32768,    32,    35,    35,    79,    79,    79,    79,
    58,    58,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   140,-32768,   139,-32768,   141,-32768,   103,   103,-32768,
-32768,    97,    83,-32768,-32768,   103,-32768,   153,-32768,   161,
   163,-32768
};

static const short yypgoto[] = {-32768,
-32768,   157,-32768,-32768,    15,-32768,   154,-32768,-32768,-32768,
-32768,-32768,-32768,   -78,   155,-32768,-32768,-32768,     7,-32768,
   127,    88,-32768,-32768,-32768,   -59,-32768,   121,-32768,-32768,
-32768,   -47,   -96,-32768,    72,    70,     3,    -9,    37,   -46,
-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		171


static const short yytable[] = {    96,
    89,    24,    91,   127,    92,    93,    94,    95,    37,    85,
   118,    20,   119,    17,    11,   146,   147,   148,   149,   150,
   151,    11,   153,    98,     1,    21,    44,    35,     2,     3,
     4,    42,    22,     5,    18,    31,   120,   121,    43,   128,
    77,    45,   130,    86,   -61,    36,    25,   157,    31,    36,
   122,   -22,   133,   133,   133,   133,   133,   133,   133,   133,
   133,   133,   143,   144,   145,   165,     6,   123,   101,   102,
   152,    39,    46,   103,   104,   105,   106,    47,    48,    87,
    49,    21,   109,   110,   111,    50,    78,   166,   -62,   167,
    51,    40,    41,   137,   138,   139,   140,    97,   163,   164,
    52,   107,   108,   135,   136,    90,   168,    47,    46,    53,
    54,    55,    56,    47,    48,    50,    49,    21,     1,    99,
    51,    50,     2,     3,     4,   100,    51,     5,     1,   125,
    52,   131,     2,     3,     4,   126,    52,     5,   129,    53,
    54,    55,    56,   141,   142,    53,    54,    55,    56,   112,
   113,   114,   115,   116,   117,   158,   159,   160,   161,   169,
   171,   162,   172,    19,    23,    30,    84,   124,    88,   134,
   132
};

static const short yycheck[] = {    59,
    48,     1,    50,    82,    51,    52,    53,    54,    19,    11,
    17,     1,    19,     1,     0,   112,   113,   114,   115,   116,
   117,     7,   119,     1,     4,    15,     1,    21,     8,     9,
    10,    28,    22,    13,    22,    21,    43,    44,    46,    87,
    34,    16,    90,    45,    22,    17,    46,   126,    34,    17,
     1,    19,    99,   100,   101,   102,   103,   104,   105,   106,
   107,   108,   109,   110,   111,   162,    46,    18,    37,    38,
   118,     1,     6,    39,    40,    41,    42,    11,    12,    19,
    14,    15,    25,    26,    27,    19,    45,     5,    22,     7,
    24,    21,    22,   103,   104,   105,   106,    22,   158,   159,
    34,    23,    24,   101,   102,    19,   166,    11,     6,    43,
    44,    45,    46,    11,    12,    19,    14,    15,     4,    36,
    24,    19,     8,     9,    10,    35,    24,    13,     4,    20,
    34,    20,     8,     9,    10,    21,    34,    13,    22,    43,
    44,    45,    46,   107,   108,    43,    44,    45,    46,    28,
    29,    30,    31,    32,    33,    20,    20,    18,    20,     7,
     0,    21,     0,     7,    10,    12,    40,    80,    48,   100,
    99
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 7:
#line 57 "parser.y"
{
					  yyerrok;
					  printError(wrong_st);
				   ;
    break;}
case 10:
#line 66 "parser.y"
{
					  yyerrok;
					  printError(wrong_funcdef);
				   ;
    break;}
case 18:
#line 89 "parser.y"
{type_int = 1;
                                 type_void = 0;
                                 type_float = 0;
                                 type_char = 0;
                                 ;
    break;}
case 19:
#line 94 "parser.y"
{type_int = 0;
                                 type_void = 1;
                                 type_float = 0;
                                 type_char = 0;
                                 ;
    break;}
case 20:
#line 99 "parser.y"
{type_int = 0;
                                 type_void = 0;
                                 type_float = 1;
                                 type_char = 0;
                                 ;
    break;}
case 21:
#line 104 "parser.y"
{type_int = 0;
                                 type_void = 0;
                                 type_float = 0;
                                 type_char = 1;
                                 ;
    break;}
case 22:
#line 111 "parser.y"
{
                              if(look_id->type==0){
								  look_id->type = 5; // function name
								  type_int = 0;
								  type_void = 0;
								  type_float = 0;
								  type_char = 0;
								  look_tmp = look_id;
                              }
                             ;
    break;}
case 23:
#line 121 "parser.y"
{
						yyerrok;
						printError(wrong_funcdef);
						;
    break;}
case 29:
#line 136 "parser.y"
{
													  yyerrok;
													  printError(nocomma);
												  ;
    break;}
case 30:
#line 142 "parser.y"
{
												if(look_id->type==1){
													type_int = 0;
													type_void = 0;
													type_float = 0;
													type_char = 0;
													look_id->type=9; 
												}
											;
    break;}
case 32:
#line 155 "parser.y"
{
				   yyerrok;
				   printError(nobrace);
				;
    break;}
case 38:
#line 172 "parser.y"
{
															 type_int = 0;
															 type_void = 0;
															 type_float = 0;
															 type_char = 0;
															;
    break;}
case 39:
#line 179 "parser.y"
{
													   type_int = 0;
													   type_void = 0;
													   type_float = 0;
													   type_char = 0;
													   printError(nosemi);
												   ;
    break;}
case 45:
#line 197 "parser.y"
{
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
                                 
                                 ;
    break;}
case 46:
#line 213 "parser.y"
{
                                                     if(look_id->type==0) {
                                                        if(type_int == 1)
                                                           look_id->type = 6; // integer array variable
                                                        else if(type_float == 1)
                                                           look_id->type = 7; // float array variable
                                                        else if(type_char == 1)
                                                           look_id->type = 8; // char array variable
                                                     }
                                                           look_tmp = look_id;
                                                  ;
    break;}
case 47:
#line 227 "parser.y"
{
                 yyerrok;
                 printError(nobracket);
              ;
    break;}
case 60:
#line 254 "parser.y"
{
               yyerrok;
               printError(nosemi);
            ;
    break;}
case 109:
#line 342 "parser.y"
{
                           if(look_id->type == 0) look_id->type = 10;
                           ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 351 "parser.y"
