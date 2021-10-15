/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    INT = 260,
    FLOAT = 261,
    CHAR = 262,
    VOID = 263,
    INCLUDE = 264,
    RETURN = 265,
    LE = 266,
    GE = 267,
    LT = 268,
    GT = 269,
    EQ = 270,
    NE = 271,
    NUM = 272,
    AND = 273,
    OR = 274,
    TR = 275,
    FL = 276,
    STRLT = 277,
    identifiers = 278,
    printff = 279,
    scanff = 280
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define INT 260
#define FLOAT 261
#define CHAR 262
#define VOID 263
#define INCLUDE 264
#define RETURN 265
#define LE 266
#define GE 267
#define LT 268
#define GT 269
#define EQ 270
#define NE 271
#define NUM 272
#define AND 273
#define OR 274
#define TR 275
#define FL 276
#define STRLT 277
#define identifiers 278
#define printff 279
#define scanff 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 55 "oldparser.y"
 
	struct var_name {
		char name[100];
		struct node1* nd;
	}nam; 
	
	struct gen_code {
		char tr[10];
		char fal[10];
		struct node1* nd;
	} gen; 

#line 120 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
