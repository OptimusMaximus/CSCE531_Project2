/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 59 "gram.y" /* yacc.c:339  */


#include "tree.h"
#include "encode.h"
#include "message.h"


/* Function stack variables */
ST_ID func_id_stack[BS_DEPTH];
int fi_top = -1;

/* Cause the `yydebug' variable to be defined.  */
#define YYDEBUG 1

void set_yydebug(int);
void yyerror(const char *);

/* Like YYERROR but do call yyerror */
#define YYERROR1 { yyerror ("syntax error"); YYERROR; }

#line 87 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    LEX_ID = 258,
    LEX_ARRAY = 259,
    LEX_BEGIN = 260,
    LEX_CASE = 261,
    LEX_CONST = 262,
    LEX_DO = 263,
    LEX_DOWNTO = 264,
    LEX_END = 265,
    LEX_FILE = 266,
    LEX_FOR = 267,
    LEX_FUNCTION = 268,
    LEX_GOTO = 269,
    LEX_IF = 270,
    LEX_LABEL = 271,
    LEX_NIL = 272,
    LEX_OF = 273,
    LEX_PACKED = 274,
    LEX_PROCEDURE = 275,
    LEX_PROGRAM = 276,
    LEX_RECORD = 277,
    LEX_REPEAT = 278,
    LEX_SET = 279,
    LEX_THEN = 280,
    LEX_TO = 281,
    LEX_TYPE = 282,
    LEX_UNTIL = 283,
    LEX_VAR = 284,
    LEX_WHILE = 285,
    LEX_WITH = 286,
    LEX_FORWARD = 287,
    pp_SIN = 288,
    pp_COS = 289,
    pp_EXP = 290,
    pp_LN = 291,
    pp_SQRT = 292,
    pp_ARCTAN = 293,
    rr_POW = 294,
    rr_EXPON = 295,
    r_WRITE = 296,
    r_READ = 297,
    r_INITFDR = 298,
    r_LAZYTRYGET = 299,
    r_LAZYGET = 300,
    r_LAZYUNGET = 301,
    r_POW = 302,
    r_EXPON = 303,
    z_ABS = 304,
    z_ARCTAN = 305,
    z_COS = 306,
    z_EXP = 307,
    z_LN = 308,
    z_SIN = 309,
    z_SQRT = 310,
    z_POW = 311,
    z_EXPON = 312,
    set_card = 313,
    set_isempty = 314,
    set_equal = 315,
    set_le = 316,
    set_less = 317,
    set_in = 318,
    set_clear = 319,
    set_include = 320,
    set_exclude = 321,
    set_include_range = 322,
    set_copy = 323,
    set_intersection = 324,
    set_union = 325,
    set_diff = 326,
    set_symdiff = 327,
    p_DONEFDR = 328,
    gpc_IOCHECK = 329,
    gpc_RUNTIME_ERROR = 330,
    p_INPUT = 331,
    p_OUTPUT = 332,
    p_REWRITE = 333,
    p_RESET = 334,
    p_PUT = 335,
    p_GET = 336,
    p_WRITE = 337,
    p_READ = 338,
    p_WRITELN = 339,
    p_READLN = 340,
    p_PAGE = 341,
    p_NEW = 342,
    p_DISPOSE = 343,
    p_ABS = 344,
    p_SQR = 345,
    p_SIN = 346,
    p_COS = 347,
    p_EXP = 348,
    p_LN = 349,
    p_SQRT = 350,
    p_ARCTAN = 351,
    p_TRUNC = 352,
    p_ROUND = 353,
    p_PACK = 354,
    p_UNPACK = 355,
    p_ORD = 356,
    p_CHR = 357,
    p_SUCC = 358,
    p_PRED = 359,
    p_ODD = 360,
    p_EOF = 361,
    p_EOLN = 362,
    p_MAXINT = 363,
    p_TRUE = 364,
    p_FALSE = 365,
    bp_RANDOM = 366,
    bp_RANDOMIZE = 367,
    BREAK = 368,
    CONTINUE = 369,
    RETURN_ = 370,
    RESULT = 371,
    EXIT = 372,
    FAIL = 373,
    p_CLOSE = 374,
    CONJUGATE = 375,
    p_DEFINESIZE = 376,
    SIZEOF = 377,
    BITSIZEOF = 378,
    ALIGNOF = 379,
    TYPEOF = 380,
    gpc_RETURNADDRESS = 381,
    gpc_FRAMEADDRESS = 382,
    LEX_LABEL_ADDR = 383,
    LEX_INTCONST = 384,
    LEX_STRCONST = 385,
    LEX_REALCONST = 386,
    LEX_RANGE = 387,
    LEX_ELLIPSIS = 388,
    LEX_ASSIGN = 389,
    LEX_IN = 390,
    LEX_NE = 391,
    LEX_GE = 392,
    LEX_LE = 393,
    LEX_OR = 394,
    LEX_OR_ELSE = 395,
    LEX_CEIL_PLUS = 396,
    LEX_CEIL_MINUS = 397,
    LEX_FLOOR_PLUS = 398,
    LEX_FLOOR_MINUS = 399,
    LEX_DIV = 400,
    LEX_MOD = 401,
    LEX_AND = 402,
    LEX_AND_THEN = 403,
    LEX_SHL = 404,
    LEX_SHR = 405,
    LEX_XOR = 406,
    LEX_CEIL_MULT = 407,
    LEX_CEIL_DIV = 408,
    LEX_FLOOR_MULT = 409,
    LEX_FLOOR_DIV = 410,
    LEX_POW = 411,
    LEX_POWER = 412,
    LEX_IS = 413,
    LEX_AS = 414,
    LEX_NOT = 415,
    LEX_EXTERNAL = 416,
    ucsd_STR = 417,
    p_MARK = 418,
    p_RELEASE = 419,
    p_UPDATE = 420,
    p_GETTIMESTAMP = 421,
    p_UNBIND = 422,
    p_EXTEND = 423,
    bp_APPEND = 424,
    p_BIND = 425,
    p_SEEKREAD = 426,
    p_SEEKWRITE = 427,
    p_SEEKUPDATE = 428,
    LEX_SYMDIFF = 429,
    p_ARG = 430,
    p_CARD = 431,
    p_EMPTY = 432,
    p_POSITION = 433,
    p_LASTPOSITION = 434,
    p_LENGTH = 435,
    p_TRIM = 436,
    p_BINDING = 437,
    p_DATE = 438,
    p_TIME = 439,
    LEX_RENAME = 440,
    LEX_IMPORT = 441,
    LEX_USES = 442,
    LEX_QUALIFIED = 443,
    LEX_ONLY = 444,
    prec_if = 445,
    LEX_ELSE = 446,
    lower_than_error = 447
  };
#endif
/* Tokens.  */
#define LEX_ID 258
#define LEX_ARRAY 259
#define LEX_BEGIN 260
#define LEX_CASE 261
#define LEX_CONST 262
#define LEX_DO 263
#define LEX_DOWNTO 264
#define LEX_END 265
#define LEX_FILE 266
#define LEX_FOR 267
#define LEX_FUNCTION 268
#define LEX_GOTO 269
#define LEX_IF 270
#define LEX_LABEL 271
#define LEX_NIL 272
#define LEX_OF 273
#define LEX_PACKED 274
#define LEX_PROCEDURE 275
#define LEX_PROGRAM 276
#define LEX_RECORD 277
#define LEX_REPEAT 278
#define LEX_SET 279
#define LEX_THEN 280
#define LEX_TO 281
#define LEX_TYPE 282
#define LEX_UNTIL 283
#define LEX_VAR 284
#define LEX_WHILE 285
#define LEX_WITH 286
#define LEX_FORWARD 287
#define pp_SIN 288
#define pp_COS 289
#define pp_EXP 290
#define pp_LN 291
#define pp_SQRT 292
#define pp_ARCTAN 293
#define rr_POW 294
#define rr_EXPON 295
#define r_WRITE 296
#define r_READ 297
#define r_INITFDR 298
#define r_LAZYTRYGET 299
#define r_LAZYGET 300
#define r_LAZYUNGET 301
#define r_POW 302
#define r_EXPON 303
#define z_ABS 304
#define z_ARCTAN 305
#define z_COS 306
#define z_EXP 307
#define z_LN 308
#define z_SIN 309
#define z_SQRT 310
#define z_POW 311
#define z_EXPON 312
#define set_card 313
#define set_isempty 314
#define set_equal 315
#define set_le 316
#define set_less 317
#define set_in 318
#define set_clear 319
#define set_include 320
#define set_exclude 321
#define set_include_range 322
#define set_copy 323
#define set_intersection 324
#define set_union 325
#define set_diff 326
#define set_symdiff 327
#define p_DONEFDR 328
#define gpc_IOCHECK 329
#define gpc_RUNTIME_ERROR 330
#define p_INPUT 331
#define p_OUTPUT 332
#define p_REWRITE 333
#define p_RESET 334
#define p_PUT 335
#define p_GET 336
#define p_WRITE 337
#define p_READ 338
#define p_WRITELN 339
#define p_READLN 340
#define p_PAGE 341
#define p_NEW 342
#define p_DISPOSE 343
#define p_ABS 344
#define p_SQR 345
#define p_SIN 346
#define p_COS 347
#define p_EXP 348
#define p_LN 349
#define p_SQRT 350
#define p_ARCTAN 351
#define p_TRUNC 352
#define p_ROUND 353
#define p_PACK 354
#define p_UNPACK 355
#define p_ORD 356
#define p_CHR 357
#define p_SUCC 358
#define p_PRED 359
#define p_ODD 360
#define p_EOF 361
#define p_EOLN 362
#define p_MAXINT 363
#define p_TRUE 364
#define p_FALSE 365
#define bp_RANDOM 366
#define bp_RANDOMIZE 367
#define BREAK 368
#define CONTINUE 369
#define RETURN_ 370
#define RESULT 371
#define EXIT 372
#define FAIL 373
#define p_CLOSE 374
#define CONJUGATE 375
#define p_DEFINESIZE 376
#define SIZEOF 377
#define BITSIZEOF 378
#define ALIGNOF 379
#define TYPEOF 380
#define gpc_RETURNADDRESS 381
#define gpc_FRAMEADDRESS 382
#define LEX_LABEL_ADDR 383
#define LEX_INTCONST 384
#define LEX_STRCONST 385
#define LEX_REALCONST 386
#define LEX_RANGE 387
#define LEX_ELLIPSIS 388
#define LEX_ASSIGN 389
#define LEX_IN 390
#define LEX_NE 391
#define LEX_GE 392
#define LEX_LE 393
#define LEX_OR 394
#define LEX_OR_ELSE 395
#define LEX_CEIL_PLUS 396
#define LEX_CEIL_MINUS 397
#define LEX_FLOOR_PLUS 398
#define LEX_FLOOR_MINUS 399
#define LEX_DIV 400
#define LEX_MOD 401
#define LEX_AND 402
#define LEX_AND_THEN 403
#define LEX_SHL 404
#define LEX_SHR 405
#define LEX_XOR 406
#define LEX_CEIL_MULT 407
#define LEX_CEIL_DIV 408
#define LEX_FLOOR_MULT 409
#define LEX_FLOOR_DIV 410
#define LEX_POW 411
#define LEX_POWER 412
#define LEX_IS 413
#define LEX_AS 414
#define LEX_NOT 415
#define LEX_EXTERNAL 416
#define ucsd_STR 417
#define p_MARK 418
#define p_RELEASE 419
#define p_UPDATE 420
#define p_GETTIMESTAMP 421
#define p_UNBIND 422
#define p_EXTEND 423
#define bp_APPEND 424
#define p_BIND 425
#define p_SEEKREAD 426
#define p_SEEKWRITE 427
#define p_SEEKUPDATE 428
#define LEX_SYMDIFF 429
#define p_ARG 430
#define p_CARD 431
#define p_EMPTY 432
#define p_POSITION 433
#define p_LASTPOSITION 434
#define p_LENGTH 435
#define p_TRIM 436
#define p_BINDING 437
#define p_DATE 438
#define p_TIME 439
#define LEX_RENAME 440
#define LEX_IMPORT 441
#define LEX_USES 442
#define LEX_QUALIFIED 443
#define LEX_ONLY 444
#define prec_if 445
#define LEX_ELSE 446
#define lower_than_error 447

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 85 "gram.y" /* yacc.c:355  */

    char        *y_string;
    long         y_int;
    int          y_cint;
    double       y_real;
    ST_ID        y_stid;
    TYPE         y_type;
    PARAM_LIST   y_paramlist;
    INDEX_LIST   y_indexlist;
    PARAM        y_param;
    VAR_ID_LIST  y_varidlist;
    FUNC_HEADING y_funchead;
    DIRECTIVE 	 y_dir;
    EXPR	 	 y_expr;
    EXPR_LIST	 y_exprlist;
    EXPR_NULLOP  y_nullop;
    EXPR_UNOP    y_unop;
    EXPR_BINOP   y_binop;
    EXPR_ID      y_exprid;

#line 532 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 547 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  51
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1610

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  210
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  139
/* YYNRULES -- Number of rules.  */
#define YYNRULES  370
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  552

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   447

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     201,   202,   151,   143,   203,   142,   200,   150,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   206,   209,
     135,   136,   137,     2,   205,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   207,     2,   208,   204,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     138,   139,   140,   141,   144,   145,   146,   147,   148,   149,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   222,   222,   226,   226,   230,   234,   235,   239,   240,
     244,   248,   252,   256,   258,   259,   260,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     276,   277,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   290,   291,   293,   294,   295,   296,   297,   299,
     300,   301,   302,   303,   304,   305,   306,   309,   311,   315,
     316,   320,   321,   325,   326,   327,   333,   337,   338,   342,
     346,   347,   348,   349,   353,   354,   358,   359,   363,   364,
     368,   369,   373,   374,   375,   379,   380,   384,   388,   389,
     393,   396,   397,   398,   399,   400,   404,   405,   409,   413,
     414,   418,   422,   427,   431,   432,   436,   437,   441,   442,
     446,   447,   451,   452,   456,   457,   458,   459,   463,   464,
     465,   471,   475,   476,   481,   482,   488,   492,   495,   497,
     498,   499,   503,   504,   508,   512,   516,   517,   521,   522,
     526,   527,   531,   532,   536,   540,   541,   545,   546,   554,
     558,   559,   563,   567,   568,   569,   568,   574,   575,   579,
     580,   584,   585,   589,   590,   595,   597,   601,   602,   606,
     607,   613,   617,   621,   622,   626,   627,   631,   632,   633,
     634,   638,   642,   643,   647,   651,   652,   656,   660,   661,
     665,   669,   670,   674,   675,   679,   683,   684,   688,   689,
     690,   694,   698,   702,   706,   707,   711,   712,   713,   714,
     718,   724,   725,   729,   730,   734,   740,   744,   745,   746,
     750,   751,   755,   756,   757,   758,   759,   760,   761,   762,
     763,   766,   768,   772,   773,   777,   778,   779,   784,   785,
     786,   787,   788,   789,   790,   791,   795,   796,   797,   798,
     799,   800,   801,   802,   803,   804,   805,   806,   807,   808,
     809,   810,   811,   815,   816,   817,   821,   822,   823,   824,
     828,   832,   836,   837,   841,   842,   846,   847,   853,   857,
     861,   862,   863,   867,   868,   869,   870,   871,   874,   875,
     876,   880,   881,   885,   886,   887,   888,   892,   893,   897,
     901,   902,   903,   904,   905,   909,   913,   914,   918,   919,
     923,   924,   925,   926,   927,   928,   929,   930,   934,   935,
     939,   940,   944,   945,   949,   950,   951,   955,   956,   960,
     961,   965,   966,   967,   968,   969,   970,   971,   972,   973,
     974,   975,   976,   977,   978,   979,   980,   981,   982,   983,
     984,   985,   986,   987,   991,   992,   996,   997,   998,   999,
    1000,  1001,  1005,  1006,  1007,  1008,  1012,  1013,  1017,  1020,
    1022
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LEX_ID", "LEX_ARRAY", "LEX_BEGIN",
  "LEX_CASE", "LEX_CONST", "LEX_DO", "LEX_DOWNTO", "LEX_END", "LEX_FILE",
  "LEX_FOR", "LEX_FUNCTION", "LEX_GOTO", "LEX_IF", "LEX_LABEL", "LEX_NIL",
  "LEX_OF", "LEX_PACKED", "LEX_PROCEDURE", "LEX_PROGRAM", "LEX_RECORD",
  "LEX_REPEAT", "LEX_SET", "LEX_THEN", "LEX_TO", "LEX_TYPE", "LEX_UNTIL",
  "LEX_VAR", "LEX_WHILE", "LEX_WITH", "LEX_FORWARD", "pp_SIN", "pp_COS",
  "pp_EXP", "pp_LN", "pp_SQRT", "pp_ARCTAN", "rr_POW", "rr_EXPON",
  "r_WRITE", "r_READ", "r_INITFDR", "r_LAZYTRYGET", "r_LAZYGET",
  "r_LAZYUNGET", "r_POW", "r_EXPON", "z_ABS", "z_ARCTAN", "z_COS", "z_EXP",
  "z_LN", "z_SIN", "z_SQRT", "z_POW", "z_EXPON", "set_card", "set_isempty",
  "set_equal", "set_le", "set_less", "set_in", "set_clear", "set_include",
  "set_exclude", "set_include_range", "set_copy", "set_intersection",
  "set_union", "set_diff", "set_symdiff", "p_DONEFDR", "gpc_IOCHECK",
  "gpc_RUNTIME_ERROR", "p_INPUT", "p_OUTPUT", "p_REWRITE", "p_RESET",
  "p_PUT", "p_GET", "p_WRITE", "p_READ", "p_WRITELN", "p_READLN", "p_PAGE",
  "p_NEW", "p_DISPOSE", "p_ABS", "p_SQR", "p_SIN", "p_COS", "p_EXP",
  "p_LN", "p_SQRT", "p_ARCTAN", "p_TRUNC", "p_ROUND", "p_PACK", "p_UNPACK",
  "p_ORD", "p_CHR", "p_SUCC", "p_PRED", "p_ODD", "p_EOF", "p_EOLN",
  "p_MAXINT", "p_TRUE", "p_FALSE", "bp_RANDOM", "bp_RANDOMIZE", "BREAK",
  "CONTINUE", "RETURN_", "RESULT", "EXIT", "FAIL", "p_CLOSE", "CONJUGATE",
  "p_DEFINESIZE", "SIZEOF", "BITSIZEOF", "ALIGNOF", "TYPEOF",
  "gpc_RETURNADDRESS", "gpc_FRAMEADDRESS", "LEX_LABEL_ADDR",
  "LEX_INTCONST", "LEX_STRCONST", "LEX_REALCONST", "LEX_RANGE",
  "LEX_ELLIPSIS", "LEX_ASSIGN", "'<'", "'='", "'>'", "LEX_IN", "LEX_NE",
  "LEX_GE", "LEX_LE", "'-'", "'+'", "LEX_OR", "LEX_OR_ELSE",
  "LEX_CEIL_PLUS", "LEX_CEIL_MINUS", "LEX_FLOOR_PLUS", "LEX_FLOOR_MINUS",
  "'/'", "'*'", "LEX_DIV", "LEX_MOD", "LEX_AND", "LEX_AND_THEN", "LEX_SHL",
  "LEX_SHR", "LEX_XOR", "LEX_CEIL_MULT", "LEX_CEIL_DIV", "LEX_FLOOR_MULT",
  "LEX_FLOOR_DIV", "LEX_POW", "LEX_POWER", "LEX_IS", "LEX_AS", "LEX_NOT",
  "LEX_EXTERNAL", "ucsd_STR", "p_MARK", "p_RELEASE", "p_UPDATE",
  "p_GETTIMESTAMP", "p_UNBIND", "p_EXTEND", "bp_APPEND", "p_BIND",
  "p_SEEKREAD", "p_SEEKWRITE", "p_SEEKUPDATE", "LEX_SYMDIFF", "p_ARG",
  "p_CARD", "p_EMPTY", "p_POSITION", "p_LASTPOSITION", "p_LENGTH",
  "p_TRIM", "p_BINDING", "p_DATE", "p_TIME", "LEX_RENAME", "LEX_IMPORT",
  "LEX_USES", "LEX_QUALIFIED", "LEX_ONLY", "prec_if", "LEX_ELSE",
  "lower_than_error", "'.'", "'('", "')'", "','", "'^'", "'@'", "':'",
  "'['", "']'", "';'", "$accept", "pascal_program",
  "main_program_declaration", "$@1", "program_heading",
  "optional_par_id_list", "id_list", "typename", "identifier",
  "new_identifier", "new_identifier_1", "any_global_declaration_part",
  "any_declaration_part", "any_decl", "simple_decl",
  "constant_definition_part", "constant_definition_list",
  "constant_definition", "constant", "number", "unsigned_number", "sign",
  "constant_literal", "predefined_literal", "string",
  "type_definition_part", "type_definition_list", "type_definition",
  "type_denoter", "new_ordinal_type", "enumerated_type", "enum_list",
  "enumerator", "subrange_type", "new_pointer_type", "pointer_char",
  "pointer_domain_type", "new_procedural_type",
  "optional_procedural_type_formal_parameter_list",
  "procedural_type_formal_parameter_list",
  "procedural_type_formal_parameter", "new_structured_type", "array_type",
  "array_index_list", "ordinal_index_type", "set_type", "record_type",
  "record_field_list", "fixed_part", "record_section", "variant_part",
  "rest_of_variant", "variant_selector", "variant_type", "variant_list",
  "variant", "case_constant_list", "one_case_constant",
  "variable_declaration_part", "variable_declaration_list",
  "variable_declaration", "function_declaration", "@2", "$@3",
  "function_heading", "directive_list", "directive", "functiontype",
  "optional_par_formal_parameter_list", "formal_parameter_list",
  "formal_parameter", "statement_part", "compound_statement",
  "statement_sequence", "statement", "structured_statement",
  "with_statement", "structured_variable_list", "structured_variable",
  "conditional_statement", "simple_if", "if_statement", "case_statement",
  "optional_semicolon_or_else_branch", "case_element_list", "case_element",
  "case_default", "repetitive_statement", "repeat_statement",
  "while_statement", "for_statement", "for_direction", "simple_statement",
  "empty_statement", "optional_par_actual_parameter_list",
  "actual_parameter_list", "actual_parameter",
  "assignment_or_call_statement",
  "variable_or_function_access_maybe_assignment", "rest_of_statement",
  "standard_procedure_statement", "optional_par_write_parameter_list",
  "write_actual_parameter_list", "write_actual_parameter",
  "rts_proc_onepar", "rts_proc_parlist", "statement_extensions",
  "return_statement", "break_statement", "continue_statement",
  "variable_access_or_typename", "index_expression_list",
  "index_expression_item", "static_expression", "boolean_expression",
  "expression", "simple_expression", "term", "signed_primary", "primary",
  "signed_factor", "factor", "address_operator",
  "variable_or_function_access",
  "variable_or_function_access_no_standard_function",
  "variable_or_function_access_no_id", "set_constructor",
  "set_constructor_element_list", "member_designator",
  "standard_functions", "optional_par_actual_parameter", "rts_fun_optpar",
  "rts_fun_onepar", "rts_fun_parlist", "relational_operator",
  "multiplying_operator", "adding_operator", "semi", "optional_semicolon", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,    60,    61,    62,   390,   391,
     392,   393,    45,    43,   394,   395,   396,   397,   398,   399,
      47,    42,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
      46,    40,    41,    44,    94,    64,    58,    91,    93,    59
};
# endif

#define YYPACT_NINF -454

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-454)))

#define YYTABLE_NINF -371

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      24,  1487,    81,  -108,  -109,  -454,  -454,  -454,  -454,  -454,
    -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,
    -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,
    -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,
    -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,   -71,
    -454,  -454,  -454,  -454,  -454,  1487,  -454,   371,   -52,  -454,
    1487,  1487,  1487,  1487,  1487,   102,  -454,  -454,  -454,  -454,
    -454,  -454,  -109,  -454,  1487,     2,  1487,  -454,   -55,   -55,
      68,  -109,  -454,   -86,  1487,  -454,   860,  -454,  -454,   -10,
    -454,   657,  -454,  1283,   -26,  -454,    47,  1487,    47,  -454,
    -454,   657,   593,   657,   860,   657,   593,  -454,  -454,  -454,
    -454,  -454,  -454,    30,    57,    30,    57,    57,    59,    61,
    -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,
    -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,
    -454,   657,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,
    -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,
    -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,
    -454,  -454,  -454,   657,  -454,  -148,  -454,    -3,  -454,  -454,
    -454,  -454,    56,  -454,  -454,  -454,  -454,  -454,  -454,  -454,
    -454,  -454,   130,  -454,    70,    73,  -454,  -454,  -454,  -454,
     593,   -65,    76,   -76,  -454,    78,    89,    91,  -454,  -454,
    -454,  -109,  -454,  -454,  -454,  -454,  -454,  -454,  -454,  -454,
    -454,   657,   457,  -454,  -454,   657,  -454,  -454,   166,  -109,
     236,   -40,    48,  -454,    72,  -454,   725,   -65,  -454,  -454,
    1487,   -80,  -155,  -454,   311,  -454,   177,   111,   120,   120,
    1331,   305,  1487,  -454,  -454,  -454,  -454,   197,  -454,  -454,
      14,  -454,  -454,  -454,  -454,  -454,  -454,  1175,  -454,  -454,
    -454,  -454,  -454,  -454,  -109,   104,   -99,   308,   236,   -13,
     337,    29,  -454,   -65,   657,  -454,   657,  -454,  -454,  -454,
    -454,  1049,   657,   236,   148,  -454,   860,   860,   657,  -454,
     657,   657,   -65,  1487,   657,  -454,   657,   657,  -454,   657,
     657,   371,   -10,   657,  -454,  -454,  -454,   306,  -142,  -454,
    -454,  -454,  -454,  -454,  -454,  -454,   657,  -454,  -454,  -454,
     657,  -454,  -454,   657,   657,   657,   657,  -454,  -454,  -454,
    -454,   657,   657,   725,   725,   311,  -454,   -39,   311,  -454,
    1283,  -454,  -454,    23,  1439,   -26,  -454,   990,   -24,   341,
     143,  -454,  -454,    47,  -454,   -43,  -454,   217,  -454,  -454,
    -454,  -454,  -454,  -454,   657,   657,   860,   657,   860,   860,
     593,   147,    11,  -454,   236,    44,  -454,   155,   159,   167,
      54,  -454,  -454,  -454,   236,   178,    64,  -454,  -125,  -454,
     352,    98,   179,   190,   129,  -454,   102,  -454,  -454,   657,
     657,  -454,   -40,   -40,    48,    48,    48,    48,  -454,  -454,
    -454,  -454,  -454,   311,  -454,  -454,  -454,  -454,  -112,  -454,
    1487,   -19,  -123,  -454,  -454,   -90,   247,   262,  -454,   191,
    -454,   383,  -454,    47,  -454,     6,  1331,  -454,  -454,  -454,
    1487,  -454,   -18,  -454,  -154,  -454,   271,   200,  -454,  -454,
    -454,  -454,  -454,   657,  -454,   657,  -454,   657,  -454,  -454,
     657,  -454,  -454,   657,  -454,   657,  -454,  -454,  -454,  -454,
    -109,   236,  -454,  -454,    23,   386,    -9,   311,  -454,  1439,
      23,   657,  -454,  -454,  -454,  -454,   657,   860,  -454,   396,
     860,   525,  -454,   657,  -454,  -454,   657,   227,  -454,  -454,
     140,  -454,   236,  -454,  -454,    47,   311,  -454,  -454,  -454,
    -154,  -454,    15,  -454,  -454,  -454,  -109,  -454,  -454,  -454,
      33,   657,  -454,  -454,  -454,  -454,   206,   525,  -454,   207,
     860,   236,  1331,  -454,  1331,  -454,   209,   211,   205,  -454,
    -454,  -454
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     0,     0,     0,    13,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    28,    29,    14,    16,
      15,    49,    50,    51,    52,    53,    54,    55,    56,     6,
      12,     1,     2,   368,    57,     0,     5,     3,     0,     8,
       0,     0,     0,     0,     0,     0,    58,    61,    63,    64,
      65,    62,     0,     7,     0,     0,    66,    67,   165,   165,
       0,     0,    88,     0,   149,   150,   210,     4,   171,   154,
       9,     0,    68,     0,   163,   157,     0,    87,     0,   151,
      11,     0,     0,     0,   210,     0,     0,   311,   310,   246,
     247,   238,   239,   231,   211,   231,   211,   211,     0,     0,
     331,   332,   333,   334,   335,   336,   337,   338,   340,   341,
     250,   251,   343,   344,   354,   355,   345,   329,   330,   270,
     271,   266,   268,   269,   242,   256,   258,   257,   261,   262,
     260,   259,   240,   241,   243,   244,   245,   248,   249,   252,
     253,   254,   255,   339,   342,   346,   347,   348,   349,   350,
     351,   352,   353,     0,   305,   217,   177,     0,   173,   175,
     178,   179,   189,   185,   186,   180,   198,   199,   200,   176,
     206,   207,   220,   208,     0,     0,   209,   263,   265,   264,
       0,     0,   306,   219,   307,   327,     0,     0,   161,   162,
      59,     0,   159,    82,    84,    83,    76,    85,    77,    79,
      78,     0,     0,   308,   301,     0,   300,    81,    80,     0,
     278,   282,   283,   288,   291,   293,     0,   299,   309,   302,
       0,     0,     0,   167,     0,   158,    10,     0,   110,   110,
     128,     0,     0,   104,   105,    91,    70,     0,    72,    75,
       0,    73,    90,    92,    96,    97,    93,     0,    94,    95,
     118,   119,   120,    89,     0,     0,     0,     0,   279,     0,
       0,     0,   182,   184,     0,   224,     0,   226,   225,   227,
     228,     0,     0,   267,     0,   172,   210,   210,     0,   216,
       0,     0,   218,     0,     0,   314,     0,     0,   325,     0,
       0,   155,   153,     0,   303,   297,   318,   322,     0,   320,
     292,    86,    69,   360,   359,   361,     0,   356,   358,   357,
       0,   366,   367,     0,     0,     0,     0,   364,   365,   362,
     363,     0,     0,     0,     0,     0,   304,     0,     0,   166,
       0,    10,   164,     0,     0,   163,   108,     0,     0,     0,
     369,   132,   131,     0,   101,     0,    99,     0,    71,    74,
     106,   103,   107,   152,     0,     0,   210,     0,   210,   210,
       0,   235,     0,   233,   215,     0,   213,    11,     0,   309,
       0,   313,   174,   188,   221,     0,     0,   312,     0,   274,
     276,     0,     0,     0,     0,    60,     0,   160,   298,     0,
       0,   319,   281,   280,   286,   287,   285,   284,   290,   289,
     294,   295,   296,     0,   169,   168,   125,   124,     0,   122,
       0,   114,     0,   112,   109,    10,    16,    15,   140,     0,
     141,     0,   139,     0,   127,   368,     0,   129,   126,    98,
       0,   102,     0,   145,   369,   193,   147,     0,   187,   201,
     202,   181,   183,     0,   232,     0,   212,     0,   317,   229,
       0,   222,   223,     0,   315,     0,   316,   328,   324,   326,
       0,   323,   321,   170,     0,     0,   117,     0,   111,     0,
       0,     0,   134,   133,   130,   100,     0,   210,   196,     0,
     210,     0,   191,     0,   205,   204,     0,   236,   234,   214,
       0,   275,   277,   156,   123,     0,     0,   115,   113,   138,
     369,   142,     0,   146,   195,   190,   192,   197,   194,   148,
       0,     0,   230,   121,   116,   135,     0,     0,   136,     0,
     210,   237,   128,   143,   128,   203,     0,     0,   369,   144,
     370,   137
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -454,  -454,  -454,  -454,  -454,  -454,   -35,  -162,   -85,    13,
    -454,  -454,  -454,   113,  -454,  -454,  -454,   333,    55,  -454,
     -33,   -94,   -50,  -454,  -454,  -454,  -454,   328,   -88,  -329,
    -454,  -454,   -15,  -454,  -454,  -139,  -454,   164,   187,  -454,
     -41,  -454,  -454,  -454,   -47,  -454,  -454,  -408,  -454,    -7,
       3,  -454,  -454,   -38,  -454,   -84,  -453,   -34,  -454,  -454,
     372,  -454,  -454,  -454,  -454,  -454,   146,   106,   385,  -454,
     117,    62,   -62,   -98,  -264,  -454,  -454,  -454,    90,  -454,
    -454,  -454,  -454,  -454,  -454,   -32,   -45,  -454,  -454,  -454,
    -454,  -454,  -454,  -454,   133,  -267,  -212,  -454,  -454,  -454,
    -454,   358,  -454,    12,  -454,  -454,  -454,  -454,  -454,  -454,
    -454,  -454,     5,   -83,   -96,     8,  -236,    53,  -194,  -454,
     172,  -151,   -68,   -81,  -454,   -74,  -454,  -454,    69,  -454,
    -454,  -454,  -454,  -454,  -454,  -454,  -454,    -4,  -427
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    65,     4,    56,   358,   255,   223,    59,
      50,    57,   311,    66,    67,    68,    76,    77,   257,   258,
     224,   225,   226,   227,   228,    69,    81,    82,   262,   263,
     264,   365,   366,   265,   266,   267,   371,   268,   355,   432,
     433,   269,   270,   428,   429,   271,   272,   359,   360,   361,
     362,   535,   441,   442,   520,   521,   452,   453,    70,    84,
      85,    71,   210,   406,    72,   211,   212,   245,    94,   242,
     243,    87,   176,   177,   178,   179,   180,   281,   282,   181,
     182,   183,   184,   499,   454,   455,   500,   185,   186,   187,
     188,   506,   189,   190,   287,   385,   386,   191,   192,   299,
     193,   285,   382,   383,   194,   195,   196,   197,   198,   199,
     388,   398,   399,   456,   277,   384,   231,   232,   233,   234,
     314,   235,   236,   237,   202,   238,   239,   318,   319,   204,
     308,   205,   206,   207,   330,   342,   336,   296,   447
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   175,   260,    88,   260,   201,   279,   295,   229,   280,
     274,   256,   203,   256,    49,   377,  -370,   100,   200,   175,
      58,   276,   208,   201,   427,   283,   246,   502,   440,    83,
     203,   320,   392,   393,   396,   375,   200,   379,   522,   401,
     213,   540,   -11,   404,   498,     1,   261,   349,   261,    83,
     246,   247,  -308,  -308,    53,   445,  -308,  -308,   241,  -308,
     248,   410,   305,   259,   213,   259,   411,   249,    89,   250,
     315,   251,   381,    75,    78,    79,    80,    97,   473,   488,
     390,    51,   352,   474,   522,   346,    53,    90,   395,    75,
     412,   484,    52,   538,   413,   402,   485,   403,   305,   230,
      53,   303,   331,   332,   333,   253,   254,    86,   304,   275,
      80,   278,   458,   278,   460,   461,   -13,    74,   334,   302,
      98,   551,   374,    74,  -309,  -309,   348,   313,  -309,  -309,
      55,  -309,   214,   215,   546,   303,   547,   305,    91,   253,
     254,   335,   304,   216,   305,   218,    93,   418,   419,   293,
      73,    74,   216,   217,   218,   427,   214,   215,   209,   449,
     450,   440,   315,   305,    74,   219,   220,   423,   323,   324,
     325,   326,   327,   328,   329,   368,   216,   217,   218,    74,
     244,   294,   443,   422,    74,   496,   424,   487,   497,   219,
     220,   426,   420,   421,    74,   438,    53,   516,   337,   338,
     339,   340,   341,   510,    96,   347,    53,   312,  -370,   504,
     201,   175,   175,   464,   465,   201,   201,   389,   496,   313,
     100,   539,   203,   203,   252,   322,   505,   369,   200,   200,
     317,   284,   380,   524,   213,   343,   344,   345,   350,   323,
     324,   325,   326,   327,   328,   329,   466,   467,   252,   289,
     290,   253,   254,   381,   297,   509,   469,   470,   286,   260,
     291,   483,   292,   260,   298,   364,   472,   467,   256,   260,
     373,   300,   256,   260,   301,   448,   545,   306,   256,   307,
     370,   459,   256,   323,   324,   325,   326,   327,   328,   329,
     309,   175,   310,   175,   175,   201,   321,   201,   201,   283,
     476,   467,   203,   261,   203,   203,   394,   261,   200,   -11,
     200,   200,   400,   261,   351,   241,   397,   261,   353,   431,
     259,   354,   426,   363,   259,   517,   214,   215,   438,   367,
     259,   479,   467,   376,   259,   323,   324,   325,   326,   327,
     328,   329,   532,   467,    88,   378,   216,   217,   218,   260,
     391,   444,   445,   463,   534,   492,   446,  -273,   256,   219,
     220,   468,   323,   324,   325,   326,   327,   328,   329,  -272,
     439,   323,   324,   325,   326,   327,   328,   329,    60,   -84,
     471,   477,   230,   457,    61,   278,   414,   415,   416,   417,
     260,    62,   478,   261,   -83,   486,   260,   490,    63,   256,
      64,   491,   526,   503,   515,   256,   525,   542,   544,    92,
     259,   548,   175,   549,   550,   175,   201,   481,   317,   201,
     529,   260,   451,   203,   405,   273,   203,   533,   489,   200,
     256,   372,   200,   531,   261,   495,   356,   514,   409,   493,
     261,   323,   324,   325,   326,   327,   328,   329,   518,   494,
     501,   259,   519,   543,   431,   175,    99,   259,   407,   201,
     100,   434,   523,   364,    95,   261,   203,   425,   480,   528,
     462,   507,   200,   288,   213,   536,   513,   508,   511,   482,
       0,   400,   259,   512,   475,   408,     0,   323,   324,   325,
     326,   327,   328,   329,     0,     0,     0,     0,     0,   230,
       0,     0,     0,     0,   230,     0,     0,     0,     0,   230,
       0,   230,     0,     0,   530,     0,   537,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
       0,     0,     0,   107,   108,     0,     0,     0,     0,   541,
       0,     0,   213,     0,   118,   230,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,   132,   133,
     134,   135,   136,   137,   138,     0,   214,   215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   216,   217,   218,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,   219,
     220,   107,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,     0,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   221,     0,   132,   133,   134,   135,
     136,   137,   138,     0,   214,   215,     0,     0,     0,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,     0,     0,     0,   216,   217,   218,     0,   173,     0,
     100,     0,   174,     0,   222,   316,     0,   219,   220,   107,
     108,     0,     0,     0,   213,     0,     0,     0,     0,     0,
     118,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   221,     0,   132,   133,   134,   135,   136,   137,
     138,     0,     0,     0,     0,     0,     0,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,     0,     0,   527,     0,     0,   173,     0,   100,     0,
     174,     0,   222,   107,   108,     0,     0,     0,     0,     0,
       0,     0,   213,     0,   118,     0,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,     0,     0,   132,   133,
     134,   135,   136,   137,   138,     0,   214,   215,     0,     0,
       0,     0,     0,     0,     0,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,     0,   216,   217,   218,     0,
       0,     0,     0,     0,   173,     0,     0,     0,     0,   219,
     220,   107,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   118,     0,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   221,     0,   132,   133,   134,   135,
     136,   137,   138,     0,   214,   215,     0,     0,     0,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,     0,
       0,     0,     0,     0,   216,   217,   218,     0,   173,     0,
       0,     0,   174,   100,   222,    86,   101,     0,     0,     0,
       0,     0,   102,     0,     0,   103,     0,     0,     0,     0,
       0,     0,     0,   104,     0,     0,     0,     0,     0,     0,
     105,   106,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,     0,     0,     0,
     174,     0,   222,     0,     0,     0,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,     0,     0,
       0,     0,     0,   139,   140,   141,     0,   142,   143,   144,
       0,   145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   435,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   146,     0,     0,   213,     0,     0,
       0,     0,     0,     0,   147,     0,   148,   149,   150,     0,
       0,     0,     0,     0,     0,     0,     0,   151,     0,     0,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,     0,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   387,     0,     0,     0,     0,     0,     0,     0,
       0,   173,     0,     0,     0,   174,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,   436,
     437,     0,     0,    41,    42,    43,    44,    45,    46,     0,
       0,     0,    47,    48,     0,     0,     0,     0,     0,   216,
     217,   218,     0,     0,     0,   107,   108,     0,     0,     0,
       0,     0,   219,   220,     0,     0,   118,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,     0,     0,
     132,   133,   134,   135,   136,   137,   138,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,     0,
       0,   252,     0,     0,     0,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     5,     0,    41,    42,
      43,    44,    45,    46,     0,     0,     0,    47,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   240,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,   357,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,     0,    41,    42,    43,    44,
      45,    46,     0,     0,     0,    47,    48,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     5,     0,    41,    42,    43,    44,    45,    46,
       0,     0,     0,    47,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   430,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,     0,    41,    42,    43,    44,    45,    46,     0,     0,
       0,    47,    48,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,     0,
      41,    42,    43,    44,    45,    46,     0,     0,     0,    47,
      48
};

static const yytype_int16 yycheck[] =
{
       4,    86,    96,    65,    98,    86,   104,    10,    91,   105,
      98,    96,    86,    98,     1,    28,    10,     3,    86,   104,
      55,   102,    32,   104,   353,   106,     3,   454,   357,    64,
     104,   225,   296,   297,   301,   134,   104,     8,   491,   306,
      17,     8,   132,   310,   198,    21,    96,   202,    98,    84,
       3,     4,   200,   201,   209,   209,   204,   205,    93,   207,
      13,   203,   201,    96,    17,    98,   208,    20,    72,    22,
     221,    24,   284,    60,    61,    62,    63,    81,   203,   202,
     292,     0,   244,   208,   537,   236,   209,    74,   300,    76,
     326,   203,   200,   520,   330,   307,   208,   309,   237,    91,
     209,   200,   142,   143,   144,   204,   205,     5,   207,   101,
      97,   103,   376,   105,   378,   379,   206,   203,   158,   200,
     206,   548,    18,   203,   200,   201,   206,   221,   204,   205,
     201,   207,   109,   110,   542,   200,   544,   276,   136,   204,
     205,   181,   207,   129,   283,   131,   201,   341,   342,   141,
     202,   203,   129,   130,   131,   484,   109,   110,   168,   202,
     203,   490,   313,   302,   203,   142,   143,   206,   135,   136,
     137,   138,   139,   140,   141,   260,   129,   130,   131,   203,
     206,   173,   206,   345,   203,   203,   348,   206,   206,   142,
     143,   353,   343,   344,   203,   357,   209,   206,   150,   151,
     152,   153,   154,   470,   136,   240,   209,   211,   202,     9,
     291,   296,   297,   202,   203,   296,   297,   291,   203,   313,
       3,   206,   296,   297,   201,   229,    26,   260,   296,   297,
     222,   201,   203,   497,    17,   163,   164,   165,   242,   135,
     136,   137,   138,   139,   140,   141,   202,   203,   201,   116,
     117,   204,   205,   465,   198,   467,   202,   203,   201,   353,
     201,   423,   201,   357,   134,   252,   202,   203,   353,   363,
     274,   201,   357,   367,   201,   363,   540,   201,   363,   201,
     267,   377,   367,   135,   136,   137,   138,   139,   140,   141,
     201,   376,   201,   378,   379,   376,   130,   378,   379,   380,
     202,   203,   376,   353,   378,   379,   298,   357,   376,   132,
     378,   379,   304,   363,     3,   350,   303,   367,   207,   354,
     353,   201,   484,    18,   357,   487,   109,   110,   490,   132,
     363,   202,   203,    25,   367,   135,   136,   137,   138,   139,
     140,   141,   202,   203,   406,     8,   129,   130,   131,   443,
     202,    10,   209,   206,   516,   443,   360,   202,   443,   142,
     143,   202,   135,   136,   137,   138,   139,   140,   141,   202,
     357,   135,   136,   137,   138,   139,   140,   141,     7,   132,
     202,   202,   374,   375,    13,   377,   333,   334,   335,   336,
     484,    20,   202,   443,   132,   430,   490,   206,    27,   484,
      29,    18,   500,   132,    18,   490,    10,   201,   201,    76,
     443,   202,   497,   202,   209,   500,   497,   409,   410,   500,
     503,   515,   367,   497,   311,    97,   500,   515,   432,   497,
     515,   267,   500,   206,   484,   450,   249,   484,   132,   446,
     490,   135,   136,   137,   138,   139,   140,   141,   489,   446,
     454,   484,   490,   537,   489,   540,    84,   490,   312,   540,
       3,   355,   496,   450,    79,   515,   540,   350,   406,   501,
     380,   463,   540,   115,    17,   520,   480,   465,   473,   410,
      -1,   473,   515,   475,   132,   313,    -1,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,   491,
      -1,    -1,    -1,    -1,   496,    -1,    -1,    -1,    -1,   501,
      -1,   503,    -1,    -1,   506,    -1,   520,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    76,    77,    -1,    -1,    -1,    -1,   531,
      -1,    -1,    17,    -1,    87,   537,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,   142,
     143,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   167,    -1,   101,   102,   103,   104,
     105,   106,   107,    -1,   109,   110,    -1,    -1,    -1,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,    -1,   201,    -1,
       3,    -1,   205,    -1,   207,   208,    -1,   142,   143,    76,
      77,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,   167,    -1,   101,   102,   103,   104,   105,   106,
     107,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,    -1,   201,    -1,     3,    -1,
     205,    -1,   207,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    87,    -1,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,    -1,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,    -1,   129,   130,   131,    -1,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,    -1,   142,
     143,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   167,    -1,   101,   102,   103,   104,
     105,   106,   107,    -1,   109,   110,    -1,    -1,    -1,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,    -1,   201,    -1,
      -1,    -1,   205,     3,   207,     5,     6,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,
     205,    -1,   207,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,    -1,   117,   118,   119,
      -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,   154,    -1,   156,   157,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,   205,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    -1,    -1,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,   142,   143,    -1,    -1,    87,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,    -1,
     101,   102,   103,   104,   105,   106,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      -1,   201,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,     3,    -1,   113,   114,
     115,   116,   117,   118,    -1,    -1,    -1,   122,   123,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,    -1,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,   122,   123,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,     3,    -1,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      -1,    -1,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,   122,   123,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    -1,    -1,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,   122,
     123
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    21,   211,   212,   214,     3,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   113,   114,   115,   116,   117,   118,   122,   123,   219,
     220,     0,   200,   209,   347,   201,   215,   221,   216,   219,
       7,    13,    20,    27,    29,   213,   223,   224,   225,   235,
     268,   271,   274,   202,   203,   219,   226,   227,   219,   219,
     219,   236,   237,   216,   269,   270,     5,   281,   282,   347,
     219,   136,   227,   201,   278,   278,   136,   347,   206,   270,
       3,     6,    12,    15,    23,    30,    31,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   113,
     114,   115,   117,   118,   119,   121,   144,   154,   156,   157,
     158,   167,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   201,   205,   218,   282,   283,   284,   285,
     286,   289,   290,   291,   292,   297,   298,   299,   300,   302,
     303,   307,   308,   310,   314,   315,   316,   317,   318,   319,
     332,   333,   334,   335,   339,   341,   342,   343,    32,   168,
     272,   275,   276,    17,   109,   110,   129,   130,   131,   142,
     143,   167,   207,   218,   230,   231,   232,   233,   234,   323,
     325,   326,   327,   328,   329,   331,   332,   333,   335,   336,
      29,   216,   279,   280,   206,   277,     3,     4,    13,    20,
      22,    24,   201,   204,   205,   217,   218,   228,   229,   230,
     231,   232,   238,   239,   240,   243,   244,   245,   247,   251,
     252,   255,   256,   237,   238,   325,   333,   324,   325,   283,
     324,   287,   288,   333,   201,   311,   201,   304,   311,   304,
     304,   201,   201,   325,   325,    10,   347,   198,   134,   309,
     201,   201,   333,   200,   207,   245,   201,   201,   340,   201,
     201,   222,   347,   231,   330,   331,   208,   325,   337,   338,
     328,   130,   347,   135,   136,   137,   138,   139,   140,   141,
     344,   142,   143,   144,   158,   181,   346,   150,   151,   152,
     153,   154,   345,   163,   164,   165,   331,   216,   206,   202,
     347,     3,   217,   207,   201,   248,   248,     6,   216,   257,
     258,   259,   260,    18,   219,   241,   242,   132,   218,   230,
     219,   246,   247,   347,    18,   134,    25,    28,     8,     8,
     203,   306,   312,   313,   325,   305,   306,     3,   320,   335,
     306,   202,   284,   284,   325,   306,   305,   219,   321,   322,
     325,   305,   306,   306,   305,   223,   273,   276,   330,   132,
     203,   208,   326,   326,   327,   327,   327,   327,   328,   328,
     331,   331,   217,   206,   217,   280,   217,   239,   253,   254,
      29,   216,   249,   250,   277,     3,   109,   110,   217,   219,
     239,   262,   263,   206,    10,   209,   347,   348,   238,   202,
     203,   228,   266,   267,   294,   295,   323,   325,   284,   324,
     284,   284,   288,   206,   202,   203,   202,   203,   202,   202,
     203,   202,   202,   203,   208,   132,   202,   202,   202,   202,
     281,   325,   338,   217,   203,   208,   216,   206,   202,   347,
     206,    18,   238,   259,   260,   242,   203,   206,   198,   293,
     296,   347,   348,   132,     9,    26,   301,   325,   313,   306,
     305,   322,   325,   347,   254,    18,   206,   217,   250,   263,
     264,   265,   266,   267,   284,    10,   283,   198,   295,   323,
     325,   206,   202,   238,   217,   261,   296,   347,   348,   206,
       8,   325,   201,   265,   201,   284,   257,   257,   202,   202,
     209,   348
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   210,   211,   213,   212,   214,   215,   215,   216,   216,
     217,   218,   219,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   221,   221,   222,
     222,   223,   223,   224,   224,   224,   225,   226,   226,   227,
     228,   228,   228,   228,   229,   229,   230,   230,   231,   231,
     232,   232,   233,   233,   233,   234,   234,   235,   236,   236,
     237,   238,   238,   238,   238,   238,   239,   239,   240,   241,
     241,   242,   243,   244,   245,   245,   246,   246,   247,   247,
     248,   248,   249,   249,   250,   250,   250,   250,   251,   251,
     251,   252,   253,   253,   254,   254,   255,   256,   257,   257,
     257,   257,   258,   258,   259,   260,   261,   261,   262,   262,
     263,   263,   264,   264,   265,   266,   266,   267,   267,   268,
     269,   269,   270,   271,   272,   273,   271,   274,   274,   275,
     275,   276,   276,   277,   277,   278,   278,   279,   279,   280,
     280,   281,   282,   283,   283,   284,   284,   285,   285,   285,
     285,   286,   287,   287,   288,   289,   289,   290,   291,   291,
     292,   293,   293,   294,   294,   295,   296,   296,   297,   297,
     297,   298,   299,   300,   301,   301,   302,   302,   302,   302,
     303,   304,   304,   305,   305,   306,   307,   308,   308,   308,
     309,   309,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   311,   311,   312,   312,   313,   313,   313,   314,   314,
     314,   314,   314,   314,   314,   314,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   316,   316,   316,   317,   317,   317,   317,
     318,   319,   320,   320,   321,   321,   322,   322,   323,   324,
     325,   325,   325,   326,   326,   326,   326,   326,   327,   327,
     327,   328,   328,   329,   329,   329,   329,   330,   330,   331,
     331,   331,   331,   331,   331,   332,   333,   333,   334,   334,
     335,   335,   335,   335,   335,   335,   335,   335,   336,   336,
     337,   337,   338,   338,   339,   339,   339,   340,   340,   341,
     341,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   343,   343,   344,   344,   344,   344,
     344,   344,   345,   345,   345,   345,   346,   346,   347,   348,
     348
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     5,     3,     0,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     0,
       2,     1,     1,     1,     1,     1,     2,     1,     2,     4,
       1,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     2,     1,     1,     1,     1,     2,     3,
       0,     3,     1,     3,     1,     3,     4,     2,     1,     1,
       1,     6,     1,     3,     1,     1,     3,     3,     0,     2,
       3,     1,     1,     3,     3,     5,     1,     5,     3,     1,
       1,     1,     1,     3,     5,     1,     3,     1,     3,     2,
       1,     2,     4,     4,     0,     0,     7,     3,     4,     1,
       3,     1,     1,     0,     2,     0,     3,     1,     3,     3,
       4,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     1,     1,     1,     4,     3,     1,
       6,     1,     2,     1,     3,     3,     1,     2,     1,     1,
       1,     4,     4,     8,     1,     1,     1,     1,     1,     1,
       0,     0,     3,     1,     3,     1,     2,     1,     2,     1,
       0,     2,     4,     4,     2,     2,     2,     2,     2,     4,
       6,     0,     3,     1,     3,     1,     3,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       3,     3,     1,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     2,     1,     3,     3,     3,     1,     2,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     4,     4,     4,     2,     3,
       1,     3,     1,     3,     4,     2,     4,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 226 "gram.y" /* yacc.c:1646  */
    {enter_main_body();}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 226 "gram.y" /* yacc.c:1646  */
    {exit_main_body();}
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 234 "gram.y" /* yacc.c:1646  */
    {}
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 235 "gram.y" /* yacc.c:1646  */
    { (yyval.y_varidlist) = (yyvsp[-1].y_varidlist); }
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 239 "gram.y" /* yacc.c:1646  */
    { (yyval.y_varidlist) = build_var_id_list(NULL, (yyvsp[0].y_stid)); }
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 240 "gram.y" /* yacc.c:1646  */
    { (yyval.y_varidlist) = build_var_id_list((yyvsp[-2].y_varidlist), (yyvsp[0].y_stid)); }
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 244 "gram.y" /* yacc.c:1646  */
    { (yyval.y_type) = check_typename(st_enter_id((yyvsp[0].y_string))); }
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 248 "gram.y" /* yacc.c:1646  */
    { (yyval.y_stid) = st_enter_id((yyvsp[0].y_string)); }
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 252 "gram.y" /* yacc.c:1646  */
    { (yyval.y_stid) = (yyvsp[0].y_string); }
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 256 "gram.y" /* yacc.c:1646  */
    { (yyval.y_string) = st_enter_id((yyvsp[0].y_string)); }
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 315 "gram.y" /* yacc.c:1646  */
    {(yyval.y_cint) = 0;}
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 316 "gram.y" /* yacc.c:1646  */
    {(yyval.y_cint) = (yyvsp[-1].y_cint) + (yyvsp[0].y_cint);}
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 325 "gram.y" /* yacc.c:1646  */
    {/*ignore*/}
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 326 "gram.y" /* yacc.c:1646  */
    { (yyval.y_cint) = 0;}
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 346 "gram.y" /* yacc.c:1646  */
    {}
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 347 "gram.y" /* yacc.c:1646  */
    {}
#line 2448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 348 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr); }
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 349 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr); }
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 353 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_un_expr((yyvsp[-1].y_unop), (yyvsp[0].y_expr)); }
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 354 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr); }
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 358 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_intconst_expr((yyvsp[0].y_int), ty_build_basic(TYSIGNEDLONGINT)); }
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 359 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_realconst_expr((double) (yyvsp[0].y_real));}
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 363 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = PLUS_OP; }
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 364 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = NEG_OP; }
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 368 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_strconst_expr((yyvsp[0].y_string)); }
#line 2502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 373 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_null_expr(NIL_OP); }
#line 2508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 374 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_intconst_expr(0, ty_build_basic(TYSIGNEDCHAR)); }
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 375 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_intconst_expr(1, ty_build_basic(TYSIGNEDCHAR)); }
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 379 "gram.y" /* yacc.c:1646  */
    { (yyval.y_string) = (yyvsp[0].y_string); }
#line 2526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 380 "gram.y" /* yacc.c:1646  */
    { (yyval.y_string) = (yyvsp[0].y_string); }
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 384 "gram.y" /* yacc.c:1646  */
    { resolve_all_ptr(); }
#line 2538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 393 "gram.y" /* yacc.c:1646  */
    { create_typename( (yyvsp[-2].y_stid), (yyvsp[0].y_type) ); }
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 404 "gram.y" /* yacc.c:1646  */
    {}
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 409 "gram.y" /* yacc.c:1646  */
    {}
#line 2556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 413 "gram.y" /* yacc.c:1646  */
    {}
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 414 "gram.y" /* yacc.c:1646  */
    {}
#line 2568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 418 "gram.y" /* yacc.c:1646  */
    {}
#line 2574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 422 "gram.y" /* yacc.c:1646  */
    { (yyval.y_type) = check_subrange((yyvsp[-2].y_expr), (yyvsp[0].y_expr)); }
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 427 "gram.y" /* yacc.c:1646  */
    { (yyval.y_type) = (yyvsp[0].y_type); }
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 436 "gram.y" /* yacc.c:1646  */
    {(yyval.y_type) = build_unresolved_pointer(ty_build_unresolved_ptr((yyvsp[0].y_stid)), NULL); }
#line 2592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 437 "gram.y" /* yacc.c:1646  */
    {(yyval.y_type) = build_unresolved_pointer(ty_build_ptr((yyvsp[0].y_type)), (yyvsp[0].y_type)); }
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 441 "gram.y" /* yacc.c:1646  */
    { (yyval.y_type) = ty_build_func(ty_build_basic(TYVOID), (yyvsp[0].y_paramlist), TRUE); }
#line 2604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 442 "gram.y" /* yacc.c:1646  */
    { (yyval.y_type) = ty_build_func((yyvsp[0].y_type), (yyvsp[-1].y_paramlist), TRUE); }
#line 2610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 446 "gram.y" /* yacc.c:1646  */
    { (yyval.y_paramlist) = NULL; }
#line 2616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 447 "gram.y" /* yacc.c:1646  */
    { (yyval.y_paramlist) = check_param((yyvsp[-1].y_paramlist)); }
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 451 "gram.y" /* yacc.c:1646  */
    { (yyval.y_paramlist) = (yyvsp[0].y_paramlist); }
#line 2628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 452 "gram.y" /* yacc.c:1646  */
    { (yyval.y_paramlist) = concatenate_param_list ((yyvsp[-2].y_paramlist), (yyvsp[0].y_paramlist)); }
#line 2634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 456 "gram.y" /* yacc.c:1646  */
    {(yyval.y_paramlist)=build_param_list((yyvsp[0].y_varidlist),ty_build_basic(TYERROR),FALSE);}
#line 2640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 457 "gram.y" /* yacc.c:1646  */
    { (yyval.y_paramlist) = build_param_list((yyvsp[-2].y_varidlist), (yyvsp[0].y_type), FALSE); }
#line 2646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 458 "gram.y" /* yacc.c:1646  */
    { (yyval.y_paramlist) = build_param_list((yyvsp[-2].y_varidlist), (yyvsp[0].y_type), TRUE); }
#line 2652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 459 "gram.y" /* yacc.c:1646  */
    {(yyval.y_paramlist)=build_param_list((yyvsp[0].y_varidlist),ty_build_basic(TYERROR),TRUE); /*treat as semantic errors*/}
#line 2658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 471 "gram.y" /* yacc.c:1646  */
    { (yyval.y_type) = check_array((yyvsp[0].y_type), (yyvsp[-3].y_indexlist)); }
#line 2664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 475 "gram.y" /* yacc.c:1646  */
    { (yyval.y_indexlist) = create_list_from_type( (yyvsp[0].y_type) ); }
#line 2670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 476 "gram.y" /* yacc.c:1646  */
    { (yyval.y_indexlist) = concatenate_index_lists((yyvsp[-2].y_indexlist), (yyvsp[0].y_type)); }
#line 2676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 481 "gram.y" /* yacc.c:1646  */
    { (yyval.y_type) = (yyvsp[0].y_type); }
#line 2682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 482 "gram.y" /* yacc.c:1646  */
    { (yyval.y_type) = (yyvsp[0].y_type); }
#line 2688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 488 "gram.y" /* yacc.c:1646  */
    {}
#line 2694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 492 "gram.y" /* yacc.c:1646  */
    {}
#line 2700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 554 "gram.y" /* yacc.c:1646  */
    { (yyval.y_cint) = (yyvsp[0].y_cint);}
#line 2706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 559 "gram.y" /* yacc.c:1646  */
    { (yyval.y_cint) = (yyvsp[-1].y_cint) + (yyvsp[0].y_cint);}
#line 2712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 563 "gram.y" /* yacc.c:1646  */
    { create_gdecl((yyvsp[-3].y_varidlist), (yyvsp[-1].y_type)); declare_var((yyvsp[-3].y_varidlist), (yyvsp[-1].y_type));}
#line 2718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 567 "gram.y" /* yacc.c:1646  */
    { install_func_head((yyvsp[-3].y_funchead).id, (yyvsp[-3].y_funchead).ret_type, (yyvsp[-1].y_dir)); }
#line 2724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 568 "gram.y" /* yacc.c:1646  */
    { (yyval.y_cint) = prepare_to_enter_func_body((yyvsp[-1].y_funchead).id, (yyvsp[-1].y_funchead).ret_type);}
#line 2730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 569 "gram.y" /* yacc.c:1646  */
    { enter_func_body((yyvsp[-3].y_funchead).id, (yyvsp[-3].y_funchead).ret_type, (yyvsp[-1].y_cint)); }
#line 2736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 570 "gram.y" /* yacc.c:1646  */
    { exit_func_body((yyvsp[-6].y_funchead).id, (yyvsp[-6].y_funchead).ret_type);}
#line 2742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 574 "gram.y" /* yacc.c:1646  */
    {(yyval.y_funchead).id = (yyvsp[-1].y_stid), (yyval.y_funchead).ret_type = ty_build_basic(TYVOID);}
#line 2748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 575 "gram.y" /* yacc.c:1646  */
    { (yyval.y_funchead).id = (yyvsp[-2].y_stid), (yyval.y_funchead).ret_type = (yyvsp[0].y_type);}
#line 2754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 579 "gram.y" /* yacc.c:1646  */
    { (yyval.y_dir) = (yyvsp[0].y_dir);}
#line 2760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 580 "gram.y" /* yacc.c:1646  */
    {}
#line 2766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 584 "gram.y" /* yacc.c:1646  */
    { (yyval.y_dir) = DIR_FORWARD; }
#line 2772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 585 "gram.y" /* yacc.c:1646  */
    { (yyval.y_dir) = DIR_EXTERNAL; }
#line 2778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 589 "gram.y" /* yacc.c:1646  */
    {}
#line 2784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 590 "gram.y" /* yacc.c:1646  */
    { (yyval.y_type) = check_function_type((yyvsp[0].y_type)); }
#line 2790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 711 "gram.y" /* yacc.c:1646  */
    {}
#line 2796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 712 "gram.y" /* yacc.c:1646  */
    { encode_expr((yyvsp[0].y_expr)); }
#line 2802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 713 "gram.y" /* yacc.c:1646  */
    { encode_expr((yyvsp[0].y_expr)); }
#line 2808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 714 "gram.y" /* yacc.c:1646  */
    {/*Won't deal with these*/}
#line 2814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 724 "gram.y" /* yacc.c:1646  */
    { (yyval.y_exprlist) = NULL; }
#line 2820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 725 "gram.y" /* yacc.c:1646  */
    { (yyval.y_exprlist) = expr_list_reverse((yyvsp[-1].y_exprlist)); }
#line 2826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 729 "gram.y" /* yacc.c:1646  */
    { (yyval.y_exprlist) = expr_prepend((yyvsp[0].y_expr), NULL); }
#line 2832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 730 "gram.y" /* yacc.c:1646  */
    { (yyval.y_exprlist) = expr_prepend((yyvsp[0].y_expr), (yyvsp[-2].y_exprlist)); }
#line 2838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 734 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr); }
#line 2844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 740 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = check_assign_or_proc_call((yyvsp[-1].y_exprid).expr, (yyvsp[-1].y_exprid).id, (yyvsp[0].y_expr)); }
#line 2850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 744 "gram.y" /* yacc.c:1646  */
    { (yyval.y_exprid).expr = make_id_expr((yyvsp[0].y_stid)); (yyval.y_exprid).id = (yyvsp[0].y_stid); }
#line 2856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 745 "gram.y" /* yacc.c:1646  */
    {}
#line 2862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 746 "gram.y" /* yacc.c:1646  */
    { (yyval.y_exprid).expr = (yyvsp[0].y_expr); (yyval.y_exprid).id = NULL; }
#line 2868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 750 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = NULL; }
#line 2874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 751 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr); }
#line 2880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 755 "gram.y" /* yacc.c:1646  */
    {}
#line 2886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 756 "gram.y" /* yacc.c:1646  */
    {}
#line 2892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 757 "gram.y" /* yacc.c:1646  */
    {}
#line 2898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 758 "gram.y" /* yacc.c:1646  */
    {}
#line 2904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 759 "gram.y" /* yacc.c:1646  */
    {}
#line 2910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 760 "gram.y" /* yacc.c:1646  */
    {}
#line 2916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 761 "gram.y" /* yacc.c:1646  */
    {}
#line 2922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 762 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_un_expr(DISPOSE_OP, (yyvsp[-1].y_expr)); }
#line 2928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 763 "gram.y" /* yacc.c:1646  */
    {}
#line 2934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 272:
#line 836 "gram.y" /* yacc.c:1646  */
    {}
#line 2940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 273:
#line 837 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_id_expr(st_enter_id((yyvsp[0].y_string))); }
#line 2946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 846 "gram.y" /* yacc.c:1646  */
    {}
#line 2952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 847 "gram.y" /* yacc.c:1646  */
    {}
#line 2958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 853 "gram.y" /* yacc.c:1646  */
    {}
#line 2964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 857 "gram.y" /* yacc.c:1646  */
    {}
#line 2970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 861 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_bin_expr((yyvsp[-1].y_binop), (yyvsp[-2].y_expr), (yyvsp[0].y_expr)); }
#line 2976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 862 "gram.y" /* yacc.c:1646  */
    {}
#line 2982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 863 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr); }
#line 2988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 867 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr); }
#line 2994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 868 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_bin_expr((yyvsp[-1].y_binop), (yyvsp[-2].y_expr), (yyvsp[0].y_expr)); }
#line 3000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 869 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_bin_expr(SYMDIFF_OP, (yyvsp[-2].y_expr), (yyvsp[0].y_expr)); }
#line 3006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 870 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_bin_expr(OR_OP, (yyvsp[-2].y_expr), (yyvsp[0].y_expr)); }
#line 3012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 871 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_bin_expr(XOR_OP, (yyvsp[-2].y_expr), (yyvsp[0].y_expr)); }
#line 3018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 874 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr); }
#line 3024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 875 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_bin_expr((yyvsp[-1].y_binop), (yyvsp[-2].y_expr), (yyvsp[0].y_expr)); }
#line 3030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 876 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_bin_expr(AND_OP, (yyvsp[-2].y_expr), (yyvsp[0].y_expr)); }
#line 3036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 880 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr); }
#line 3042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 881 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_un_expr((yyvsp[-1].y_unop), (yyvsp[0].y_expr)); }
#line 3048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 293:
#line 885 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr); }
#line 3054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 294:
#line 886 "gram.y" /* yacc.c:1646  */
    {}
#line 3060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 887 "gram.y" /* yacc.c:1646  */
    {}
#line 3066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 888 "gram.y" /* yacc.c:1646  */
    {}
#line 3072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 892 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr); }
#line 3078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 893 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_un_expr((yyvsp[-1].y_unop), (yyvsp[0].y_expr)); }
#line 3084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 897 "gram.y" /* yacc.c:1646  */
    { if (ty_query((yyvsp[0].y_expr)->type) == TYFUNC) {
                                      (yyval.y_expr) = make_fcall_expr((yyvsp[0].y_expr), NULL);
                                   } else { (yyval.y_expr) = (yyvsp[0].y_expr); }
                                 }
#line 3093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 901 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr); }
#line 3099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 902 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[0].y_expr); }
#line 3105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 903 "gram.y" /* yacc.c:1646  */
    {}
#line 3111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 904 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_un_expr(NOT_OP, (yyvsp[0].y_expr)); }
#line 3117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 905 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_un_expr(ADDRESS_OP, (yyvsp[0].y_expr)); }
#line 3123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 918 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_id_expr((yyvsp[0].y_stid)); }
#line 3129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 923 "gram.y" /* yacc.c:1646  */
    {/*Not using */}
#line 3135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 924 "gram.y" /* yacc.c:1646  */
    {/*Not using*/}
#line 3141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 925 "gram.y" /* yacc.c:1646  */
    {/*Not using*/}
#line 3147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 926 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[-1].y_expr); }
#line 3153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 928 "gram.y" /* yacc.c:1646  */
    {/*Project 3*/}
#line 3159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 929 "gram.y" /* yacc.c:1646  */
    {}
#line 3165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 930 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_un_expr(NEW_OP, (yyvsp[-1].y_expr)); }
#line 3171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 949 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_un_expr((yyvsp[-3].y_unop), (yyvsp[-1].y_expr)); }
#line 3177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 950 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_null_expr((yyvsp[-1].y_nullop)); }
#line 3183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 326:
#line 951 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = make_un_expr((yyvsp[-3].y_unop), (yyvsp[-1].y_exprlist)->expr); }
#line 3189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 955 "gram.y" /* yacc.c:1646  */
    {}
#line 3195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 956 "gram.y" /* yacc.c:1646  */
    { (yyval.y_expr) = (yyvsp[-1].y_expr); }
#line 3201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 329:
#line 960 "gram.y" /* yacc.c:1646  */
    {}
#line 3207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 330:
#line 961 "gram.y" /* yacc.c:1646  */
    {}
#line 3213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 965 "gram.y" /* yacc.c:1646  */
    {}
#line 3219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 966 "gram.y" /* yacc.c:1646  */
    {}
#line 3225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 967 "gram.y" /* yacc.c:1646  */
    {}
#line 3231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 968 "gram.y" /* yacc.c:1646  */
    {}
#line 3237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 335:
#line 969 "gram.y" /* yacc.c:1646  */
    {}
#line 3243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 336:
#line 970 "gram.y" /* yacc.c:1646  */
    {}
#line 3249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 337:
#line 971 "gram.y" /* yacc.c:1646  */
    {}
#line 3255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 338:
#line 972 "gram.y" /* yacc.c:1646  */
    {}
#line 3261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 339:
#line 973 "gram.y" /* yacc.c:1646  */
    {}
#line 3267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 340:
#line 974 "gram.y" /* yacc.c:1646  */
    {}
#line 3273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 341:
#line 975 "gram.y" /* yacc.c:1646  */
    {}
#line 3279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 342:
#line 976 "gram.y" /* yacc.c:1646  */
    {}
#line 3285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 343:
#line 977 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = ORD_OP; }
#line 3291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 344:
#line 978 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = CHR_OP; }
#line 3297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 345:
#line 979 "gram.y" /* yacc.c:1646  */
    {}
#line 3303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 346:
#line 980 "gram.y" /* yacc.c:1646  */
    {}
#line 3309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 981 "gram.y" /* yacc.c:1646  */
    {}
#line 3315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 348:
#line 982 "gram.y" /* yacc.c:1646  */
    {}
#line 3321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 349:
#line 983 "gram.y" /* yacc.c:1646  */
    {}
#line 3327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 350:
#line 984 "gram.y" /* yacc.c:1646  */
    {}
#line 3333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 351:
#line 985 "gram.y" /* yacc.c:1646  */
    {}
#line 3339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 352:
#line 986 "gram.y" /* yacc.c:1646  */
    {}
#line 3345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 353:
#line 987 "gram.y" /* yacc.c:1646  */
    {}
#line 3351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 354:
#line 991 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = SUCC_OP; }
#line 3357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 355:
#line 992 "gram.y" /* yacc.c:1646  */
    { (yyval.y_unop) = PRED_OP; }
#line 3363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 996 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binop) = NE_OP; }
#line 3369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 357:
#line 997 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binop) = LE_OP; }
#line 3375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 358:
#line 998 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binop) = GE_OP; }
#line 3381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 359:
#line 999 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binop) = EQ_OP; }
#line 3387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1000 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binop) = LESS_OP; }
#line 3393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1001 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binop) = GREATER_OP; }
#line 3399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1005 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binop) = DIV_OP; }
#line 3405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1006 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binop) = MOD_OP; }
#line 3411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1007 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binop) = REALDIV_OP; }
#line 3417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1008 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binop) = MUL_OP; }
#line 3423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1012 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binop) = SUB_OP; }
#line 3429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1013 "gram.y" /* yacc.c:1646  */
    { (yyval.y_binop) = ADD_OP; }
#line 3435 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3439 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1025 "gram.y" /* yacc.c:1906  */


void yyerror(const char *msg)
{
    error(msg);
}

/* Sets the value of the 'yydebug' variable to VALUE.
   This is a function so we don't have to have YYDEBUG defined
   in order to build the compiler.  */
void
set_yydebug (int value)
{
#if YYDEBUG != 0
  yydebug = value;
#else
  warning ("YYDEBUG not defined.");
#endif
}
