/******************************************************************************/
/*                                                                            */
/* unit_test/stdio/vsnprintf.c                                                */
/*                                                                 2024/06/22 */
/* Copyright (C) 2024 Mochi.                                                  */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/* インクルード                                                               */
/******************************************************************************/
/* 標準ヘッダ */
#include <limits.h>
#include <stdarg.h>

/* cunitヘッダ */
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

/* 共通ヘッダ */
#include <test.h>


/******************************************************************************/
/* 定義                                                                       */
/******************************************************************************/
#define SUITE_PREFIX "stdio/vsnprintf.c@"


/******************************************************************************/
/* テスト対象ファイル                                                         */
/******************************************************************************/
#include "stdio/vsnprintf.c"


/******************************************************************************/
/* スタブ関数定義                                                             */
/******************************************************************************/
/* CalcLenZero */
struct {
    ConvertInfo_t *pConvertInfo;
    ssize_t       ret;
} param_CalcLenZero;
static ssize_t stub_CalcLenZero( ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) CalcLenZero );

    param_CalcLenZero.pConvertInfo = pConvertInfo;

    return param_CalcLenZero.ret;
}

/* Convert */
struct {
    OutputInfo_t *pOutputInfo;
    OutputInfo_t outputInfo;
    InputInfo_t  *pInputInfo;
    InputInfo_t  inputInfo;
} param_Convert;
static void stub_Convert( OutputInfo_t *pOutputInfo,
                          InputInfo_t  *pInputInfo   )
{
    UtilSetCallCount( ( void * ) Convert );

    param_Convert.pOutputInfo = pOutputInfo;
    param_Convert.outputInfo  = *pOutputInfo;
    param_Convert.pInputInfo  = pInputInfo;
    param_Convert.inputInfo   = *pInputInfo;

    return;
}

/* ConvertChar */
struct {
    OutputInfo_t  *pOutputInfo;
    InputInfo_t   *pInputInfo;
    ConvertInfo_t *pConvertInfo;
} param_ConvertChar;
static void stub_ConvertChar( OutputInfo_t  *pOutputInfo,
                              InputInfo_t   *pInputInfo,
                              ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) ConvertChar );

    param_ConvertChar.pOutputInfo  = pOutputInfo;
    param_ConvertChar.pInputInfo   = pInputInfo;
    param_ConvertChar.pConvertInfo = pConvertInfo;

    return;
}

/* ConvertPercent */
struct {
    OutputInfo_t  *pOutputInfo;
    InputInfo_t   *pInputInfo;
    ConvertInfo_t *pConvertInfo;
} param_ConvertPercent;
static void stub_ConvertPercent( OutputInfo_t  *pOutputInfo,
                                 InputInfo_t   *pInputInfo,
                                 ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) ConvertPercent );

    param_ConvertPercent.pOutputInfo  = pOutputInfo;
    param_ConvertPercent.pInputInfo   = pInputInfo;
    param_ConvertPercent.pConvertInfo = pConvertInfo;

    return;
}

/* ConvertSignedInteger */
struct {
    OutputInfo_t  *pOutputInfo;
    InputInfo_t   *pInputInfo;
    ConvertInfo_t *pConvertInfo;
} param_ConvertSignedInteger;
static void stub_ConvertSignedInteger( OutputInfo_t  *pOutputInfo,
                                       InputInfo_t   *pInputInfo,
                                       ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) ConvertSignedInteger );

    param_ConvertSignedInteger.pOutputInfo  = pOutputInfo;
    param_ConvertSignedInteger.pInputInfo   = pInputInfo;
    param_ConvertSignedInteger.pConvertInfo = pConvertInfo;

    return;
}

/* ConvertString */
struct {
    OutputInfo_t  *pOutputInfo;
    InputInfo_t   *pInputInfo;
    ConvertInfo_t *pConvertInfo;
} param_ConvertString;
static void stub_ConvertString( OutputInfo_t  *pOutputInfo,
                                InputInfo_t   *pInputInfo,
                                ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) ConvertString );

    param_ConvertString.pOutputInfo  = pOutputInfo;
    param_ConvertString.pInputInfo   = pInputInfo;
    param_ConvertString.pConvertInfo = pConvertInfo;

    return;
}

/* ConvertUnsignedInteger */
struct {
    OutputInfo_t  *pOutputInfo;
    InputInfo_t   *pInputInfo;
    ConvertInfo_t *pConvertInfo;
} param_ConvertUnsignedInteger;
static void stub_ConvertUnsignedInteger( OutputInfo_t  *pOutputInfo,
                                         InputInfo_t   *pInputInfo,
                                         ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) ConvertUnsignedInteger );

    param_ConvertUnsignedInteger.pOutputInfo  = pOutputInfo;
    param_ConvertUnsignedInteger.pInputInfo   = pInputInfo;
    param_ConvertUnsignedInteger.pConvertInfo = pConvertInfo;

    return;
}

/* GetConvertInfo */
struct {
    InputInfo_t   *pInputInfo;
    ConvertInfo_t *pConvertInfo;
    ConvertInfo_t convertInfo;
} param_GetConvertInfo;
static void stub_GetConvertInfo( InputInfo_t   *pInputInfo,
                                 ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) GetConvertInfo );

    param_GetConvertInfo.pInputInfo   = pInputInfo;
    param_GetConvertInfo.pConvertInfo = pConvertInfo;

    *pConvertInfo = param_GetConvertInfo.convertInfo;

    return;
}

/* GetFlag */
struct {
    InputInfo_t   *pInputInfo;
    ConvertInfo_t *pConvertInfo;
} param_GetFlag;
static void stub_GetFlag( InputInfo_t   *pInputInfo,
                          ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) GetFlag );

    param_GetFlag.pInputInfo   = pInputInfo;
    param_GetFlag.pConvertInfo = pConvertInfo;

    return;
}

/* GetLength */
struct {
    InputInfo_t   *pInputInfo;
    ConvertInfo_t *pConvertInfo;
} param_GetLength;
static void stub_GetLength( InputInfo_t   *pInputInfo,
                            ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) GetLength );

    param_GetLength.pInputInfo   = pInputInfo;
    param_GetLength.pConvertInfo = pConvertInfo;

    return;
}

/* GetPrecision */
struct {
    InputInfo_t   *pInputInfo;
    ConvertInfo_t *pConvertInfo;
} param_GetPrecision;
static void stub_GetPrecision( InputInfo_t   *pInputInfo,
                               ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) GetPrecision );

    param_GetPrecision.pInputInfo   = pInputInfo;
    param_GetPrecision.pConvertInfo = pConvertInfo;

    return;
}

/* GetSpecifier */
struct {
    InputInfo_t   *pInputInfo;
    ConvertInfo_t *pConvertInfo;
} param_GetSpecifier;
static void stub_GetSpecifier( InputInfo_t   *pInputInfo,
                               ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) GetSpecifier );

    param_GetSpecifier.pInputInfo   = pInputInfo;
    param_GetSpecifier.pConvertInfo = pConvertInfo;

    return;
}

/* GetWidth */
struct {
    InputInfo_t   *pInputInfo;
    ConvertInfo_t *pConvertInfo;
} param_GetWidth;
static void stub_GetWidth( InputInfo_t   *pInputInfo,
                           ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) GetWidth );

    param_GetWidth.pInputInfo   = pInputInfo;
    param_GetWidth.pConvertInfo = pConvertInfo;

    return;
}

/* PopSignedInteger */
struct {
    InputInfo_t   *pInputInfo;
    ConvertInfo_t *pConvertInfo;
    long long     ret;
} param_PopSignedInteger;
static long long stub_PopSignedInteger( InputInfo_t   *pInputInfo,
                                        ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) PopSignedInteger );

    param_PopSignedInteger.pInputInfo   = pInputInfo;
    param_PopSignedInteger.pConvertInfo = pConvertInfo;

    return param_PopSignedInteger.ret;
}

/* PopUnsignedInteger */
struct {
    InputInfo_t        *pInputInfo;
    ConvertInfo_t      *pConvertInfo;
    unsigned long long ret;
} param_PopUnsignedInteger;
static unsigned long long stub_PopUnsignedInteger( InputInfo_t   *pInputInfo,
                                                   ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) PopUnsignedInteger );

    param_PopUnsignedInteger.pInputInfo   = pInputInfo;
    param_PopUnsignedInteger.pConvertInfo = pConvertInfo;

    return param_PopUnsignedInteger.ret;
}

/* PutChar */
struct {
    OutputInfo_t *pOutputInfo;
    char         c;
    ssize_t      sizeChar;
    bool         ret;
} param_PutChar[ 5 ];
static bool stub_PutChar( OutputInfo_t *pOutputInfo,
                          char         c,
                          ssize_t      sizeChar      )
{
    unsigned int idx;

    idx = UtilSetCallCount( ( void * ) PutChar ) - 1;

    param_PutChar[ idx ].pOutputInfo = pOutputInfo;
    param_PutChar[ idx ].c           = c;
    param_PutChar[ idx ].sizeChar    = sizeChar;

    return param_PutChar[ idx ].ret;
}

/* PutInteger */
struct {
    OutputInfo_t  *pOutputInfo;
    ConvertInfo_t *pConvertInfo;
    bool          ret;
} param_PutInteger;
static bool stub_PutInteger( OutputInfo_t  *pOutputInfo,
                             ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) PutInteger );

    param_PutInteger.pOutputInfo  = pOutputInfo;
    param_PutInteger.pConvertInfo = pConvertInfo;

    return param_PutInteger.ret;
}

/* PutStr */
struct {
    OutputInfo_t *pOutputInfo;
    const char   *pStr;
    ssize_t      sizeStr;
    bool         ret;
} param_PutStr;
static bool stub_PutStr( OutputInfo_t *pOutputInfo,
                         const char   *pStr,
                         ssize_t      sizeStr       )
{
    UtilSetCallCount( ( void * ) PutStr );

    param_PutStr.pOutputInfo = pOutputInfo;
    param_PutStr.pStr        = pStr;
    param_PutStr.sizeStr     = sizeStr;

    return param_PutStr.ret;
}

/* SetAlt */
struct {
    ConvertInfo_t *pConvertInfo;
} param_SetAlt;
static void stub_SetAlt( ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) SetAlt );

    param_SetAlt.pConvertInfo = pConvertInfo;

    return;
}

/* SetInteger */
struct {
    ConvertInfo_t      *pConvertInfo;
    unsigned long long value;
} param_SetInteger;
static void stub_SetInteger( ConvertInfo_t      *pConvertInfo,
                             unsigned long long value          )
{
    UtilSetCallCount( ( void * ) SetInteger );

    param_SetInteger.pConvertInfo = pConvertInfo;
    param_SetInteger.value        = value;

    return;
}

/* SetSign */
struct {
    ConvertInfo_t *pConvertInfo;
    long long     value;
} param_SetSign;
static void stub_SetSign( ConvertInfo_t *pConvertInfo,
                          long long     value          )
{
    UtilSetCallCount( ( void * ) SetSign );

    param_SetSign.pConvertInfo = pConvertInfo;
    param_SetSign.value        = value;

    return;
}

/* SetZeroVsPrecision */
struct {
    ConvertInfo_t *pConvertInfo;
} param_SetZeroVsPrecision;
static void stub_SetZeroVsPrecision( ConvertInfo_t *pConvertInfo )
{
    UtilSetCallCount( ( void * ) SetZeroVsPrecision );

    param_SetZeroVsPrecision.pConvertInfo = pConvertInfo;

    return;
}


/******************************************************************************/
/* CalcLenZero                                                                */
/******************************************************************************/
#define TEST_CALCLENZERO( _NO,                  \
                          _IN_PRECISION,        \
                          _IN_LENVAL,           \
                          _OUT_RET       )      \
    static void test_CalcLenZero_##_NO( void )  \
    {                                           \
        ssize_t       ret;                      \
        ConvertInfo_t convertInfo;              \
                                                \
        /* INPUT設定 */                         \
        convertInfo.precision = _IN_PRECISION;  \
        convertInfo.lenVal    = _IN_LENVAL;     \
                                                \
        ret = CalcLenZero( &convertInfo );      \
                                                \
        /* OUTPUT判定 */                        \
        CU_ASSERT_EQUAL( ret, _OUT_RET );       \
                                                \
        return;                                 \
    }

/*--------------+---+-------------------------------------------------------------------------------+-----------------------------------*/
/*              | # | INPUT                                                                         | OUTPUT                            */
/*              |   +-------------------------------------------------------------------------------+-----------------------------------*/
/*              |   | pConvertInfo                                                                  | return                            */
/*              |   +-------------------------------------------+-----------------------------------+                                   */
/*              |   | precision                                 | lenVal                            |                                   */
/*--------------+---+-------------------------------------------+-----------------------------------+-----------------------------------*/
TEST_CALCLENZERO(  1, /* 最小     */ INT_MIN                    , /* 最小 */                       1,                                 0 );
TEST_CALCLENZERO(  2,                INT_MIN                    , /* 中間 */ BUFFER_SIZE_INTEGER / 2,                                 0 );
TEST_CALCLENZERO(  3,                INT_MIN                    , /* 最大 */ BUFFER_SIZE_INTEGER    ,                                 0 );
/*--------------+---+-------------------------------------------+-----------------------------------+-----------------------------------*/
TEST_CALCLENZERO(  4, /* < lenVal */                       1 - 1, /* 最小 */                       1,                                 0 );
TEST_CALCLENZERO(  5,                BUFFER_SIZE_INTEGER / 2 - 1, /* 中間 */ BUFFER_SIZE_INTEGER / 2,                                 0 );
TEST_CALCLENZERO(  6,                BUFFER_SIZE_INTEGER     - 1, /* 最大 */ BUFFER_SIZE_INTEGER    ,                                 0 );
/*--------------+---+-------------------------------------------+-----------------------------------+-----------------------------------*/
TEST_CALCLENZERO(  7, /* = lenVal */                           1, /* 最小 */                       1,                                 0 );
TEST_CALCLENZERO(  8,                BUFFER_SIZE_INTEGER / 2    , /* 中間 */ BUFFER_SIZE_INTEGER / 2,                                 0 );
TEST_CALCLENZERO(  9,                BUFFER_SIZE_INTEGER        , /* 最大 */ BUFFER_SIZE_INTEGER    ,                                 0 );
/*--------------+---+-------------------------------------------+-----------------------------------+-----------------------------------*/
TEST_CALCLENZERO( 10, /* > lenVal */                       1 + 1, /* 最小 */                       1,                                 1 );
TEST_CALCLENZERO( 11,                BUFFER_SIZE_INTEGER / 2 + 1, /* 中間 */ BUFFER_SIZE_INTEGER / 2,                                 1 );
TEST_CALCLENZERO( 12,                BUFFER_SIZE_INTEGER     + 1, /* 最大 */ BUFFER_SIZE_INTEGER    ,                                 1 );
/*--------------+---+-------------------------------------------+-----------------------------------+-----------------------------------*/
TEST_CALCLENZERO( 13, /* 最大     */ INT_MAX                    , /* 最小 */                       1, INT_MAX - 1                       );
TEST_CALCLENZERO( 14,                INT_MAX                    , /* 中間 */ BUFFER_SIZE_INTEGER / 2, INT_MAX - BUFFER_SIZE_INTEGER / 2 );
TEST_CALCLENZERO( 15,                INT_MAX                    , /* 最大 */ BUFFER_SIZE_INTEGER    , INT_MAX - BUFFER_SIZE_INTEGER     );
/*--------------+---+-------------------------------------------+-----------------------------------+-----------------------------------*/

static void test_CalcLenZero( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "CalcLenZero", NULL, NULL );

    CU_add_test( suite, "#_1", test_CalcLenZero_1  );
    CU_add_test( suite, "#_2", test_CalcLenZero_2  );
    CU_add_test( suite, "#_3", test_CalcLenZero_3  );
    CU_add_test( suite, "#_4", test_CalcLenZero_4  );
    CU_add_test( suite, "#_5", test_CalcLenZero_5  );
    CU_add_test( suite, "#_6", test_CalcLenZero_6  );
    CU_add_test( suite, "#_7", test_CalcLenZero_7  );
    CU_add_test( suite, "#_8", test_CalcLenZero_8  );
    CU_add_test( suite, "#_9", test_CalcLenZero_9  );
    CU_add_test( suite, "#10", test_CalcLenZero_10 );
    CU_add_test( suite, "#11", test_CalcLenZero_11 );
    CU_add_test( suite, "#12", test_CalcLenZero_12 );
    CU_add_test( suite, "#13", test_CalcLenZero_13 );
    CU_add_test( suite, "#14", test_CalcLenZero_14 );
    CU_add_test( suite, "#15", test_CalcLenZero_15 );

    return;
}


/******************************************************************************/
/* Convert                                                                    */
/******************************************************************************/
#define TEST_CONVERT( _NO,                                                                          \
                      _IN_POUTPUTINFO,                                                              \
                      _IN_PINPUTINFO,                                                               \
                      _IN_PCONVERTER,                                                               \
                      _OUT_CALLCNT,                                                                 \
                      _OUT_CALLFUNC_0,                                                              \
                      _OUT_CALLFUNC_1,                                                              \
                      _OUT_PINPUTINFO_0,                                                            \
                      _OUT_POUTPUTINFO_0, _OUT_PINPUTINFO_1, _OUT_PCONVERTINFO_0,                   \
                      _OUT_POUTPUTINFO_1, _OUT_PINPUTINFO_2, _OUT_PCONVERTINFO_1,                   \
                      _OUT_POUTPUTINFO_2, _OUT_PINPUTINFO_3, _OUT_PCONVERTINFO_2,                   \
                      _OUT_POUTPUTINFO_3, _OUT_PINPUTINFO_4, _OUT_PCONVERTINFO_3,                   \
                      _OUT_POUTPUTINFO_4, _OUT_PINPUTINFO_5, _OUT_PCONVERTINFO_4  )                 \
    static void test_Convert_##_NO( void )                                                          \
    {                                                                                               \
        OutputInfo_t *pOutputInfo;                                                                  \
        InputInfo_t  *pInputInfo;                                                                   \
                                                                                                    \
        /* INPUT設定 */                                                                             \
        pOutputInfo = ( OutputInfo_t * ) _IN_POUTPUTINFO;                                           \
        pInputInfo  = ( InputInfo_t  * ) _IN_PINPUTINFO;                                            \
        param_GetConvertInfo.convertInfo.pConverter = _IN_PCONVERTER;                               \
                                                                                                    \
        /* OUTPUT初期化 */                                                                          \
        UtilInit();                                                                                 \
        param_GetConvertInfo.pInputInfo           = NULL;                                           \
        param_GetConvertInfo.pConvertInfo         = NULL;                                           \
        param_ConvertChar.pOutputInfo             = NULL;                                           \
        param_ConvertChar.pInputInfo              = NULL;                                           \
        param_ConvertChar.pConvertInfo            = NULL;                                           \
        param_ConvertPercent.pOutputInfo          = NULL;                                           \
        param_ConvertPercent.pInputInfo           = NULL;                                           \
        param_ConvertPercent.pConvertInfo         = NULL;                                           \
        param_ConvertSignedInteger.pOutputInfo    = NULL;                                           \
        param_ConvertSignedInteger.pInputInfo     = NULL;                                           \
        param_ConvertSignedInteger.pConvertInfo   = NULL;                                           \
        param_ConvertString.pOutputInfo           = NULL;                                           \
        param_ConvertString.pInputInfo            = NULL;                                           \
        param_ConvertString.pConvertInfo          = NULL;                                           \
        param_ConvertUnsignedInteger.pOutputInfo  = NULL;                                           \
        param_ConvertUnsignedInteger.pInputInfo   = NULL;                                           \
        param_ConvertUnsignedInteger.pConvertInfo = NULL;                                           \
                                                                                                    \
        Convert( pOutputInfo, pInputInfo );                                                         \
                                                                                                    \
        /* OUTPUT結果判定 */                                                                        \
        CU_ASSERT_EQUAL(         UtilGetCallCount(),                        _OUT_CALLCNT        );  \
        CU_ASSERT_PTR_EQUAL(     UtilGetCallFunc( 0 ),                      _OUT_CALLFUNC_0     );  \
        CU_ASSERT_PTR_EQUAL(     UtilGetCallFunc( 1 ),                      _OUT_CALLFUNC_1     );  \
        CU_ASSERT_PTR_EQUAL(     param_GetConvertInfo.pInputInfo,           _OUT_PINPUTINFO_0   );  \
        CU_ASSERT_PTR_NOT_EQUAL( param_GetConvertInfo.pConvertInfo,         NULL                );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertChar.pOutputInfo,             _OUT_POUTPUTINFO_0  );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertChar.pInputInfo,              _OUT_PINPUTINFO_1   );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertChar.pConvertInfo,            _OUT_PCONVERTINFO_0 );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertPercent.pOutputInfo,          _OUT_POUTPUTINFO_1  );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertPercent.pInputInfo,           _OUT_PINPUTINFO_2   );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertPercent.pConvertInfo,         _OUT_PCONVERTINFO_1 );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertSignedInteger.pOutputInfo,    _OUT_POUTPUTINFO_2  );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertSignedInteger.pInputInfo,     _OUT_PINPUTINFO_3   );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertSignedInteger.pConvertInfo,   _OUT_PCONVERTINFO_2 );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertString.pOutputInfo,           _OUT_POUTPUTINFO_3  );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertString.pInputInfo,            _OUT_PINPUTINFO_4   );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertString.pConvertInfo,          _OUT_PCONVERTINFO_3 );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertUnsignedInteger.pOutputInfo,  _OUT_POUTPUTINFO_4  );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertUnsignedInteger.pInputInfo,   _OUT_PINPUTINFO_5   );  \
        CU_ASSERT_PTR_EQUAL(     param_ConvertUnsignedInteger.pConvertInfo, _OUT_PCONVERTINFO_4 );  \
                                                                                                    \
        return;                                                                                     \
    }

/*----------+---+-------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*          | # | INPUT                                                 | OUTPUT                                                                                                                                                                                                                                                                                                                                                                                        */
/*          |   +-------------+------------+----------------------------+---------+---------------------------------------+----------------------+-------------------------------------------------------------+-------------------------------------------------------------+-------------------------------------------------------------+-------------------------------------------------------------+--------------------------------------------------------------*/
/*          |   | pOutputInfo | pInputInfo | param_GetConvertInfo       | callcnt | callfunc                              | param_GetConvertInfo | param_ConvertChar                                           | param_ConvertPercent                                        | param_ConvertSignedInteger                                  | param_ConvertString                                         | param_ConvertUnsignedInteger                                 */
/*          |   |             |            +----------------------------+         +---------------+-----------------------+----------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+-----------------------------------*/
/*          |   |             |            | convertInfo                |         | ( 0 )         | ( 1 )                 | pInputInfo           | pOutputInfo | pInputInfo | pConvertInfo                     | pOutputInfo | pInputInfo | pConvertInfo                     | pOutputInfo | pInputInfo | pConvertInfo                     | pOutputInfo | pInputInfo | pConvertInfo                     | pOutputInfo | pInputInfo | pConvertInfo                      */
/*          |   |             |            +----------------------------+         |               |                       |                      |             |            |                                  |             |            |                                  |             |            |                                  |             |            |                                  |             |            |                                   */
/*          |   |             |            | pConverter                 |         |               |                       |                      |             |            |                                  |             |            |                                  |             |            |                                  |             |            |                                  |             |            |                                   */
/*----------+---+-------------+------------+----------------------------+---------+---------------+-----------------------+----------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+-----------------------------------*/
TEST_CONVERT(  1, 0xFFFFFFFF  , 0x55AA55AA , NULL                       ,        1, GetConvertInfo, NULL                  , 0x55AA55AA           , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                              );
TEST_CONVERT(  2, 0xFFFFFFFF  , 0xAA55AA55 , NULL                       ,        1, GetConvertInfo, NULL                  , 0xAA55AA55           , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                              );
/*----------+---+-------------+------------+----------------------------+---------+---------------+-----------------------+----------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+-----------------------------------*/
TEST_CONVERT(  3, 0xAA55AA55  , 0x55AA55AA , stub_ConvertChar           ,        2, GetConvertInfo, ConvertChar           , 0x55AA55AA           , 0xAA55AA55  , 0x55AA55AA , param_GetConvertInfo.pConvertInfo, NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                              );
TEST_CONVERT(  4, 0x55AA55AA  , 0xAA55AA55 , stub_ConvertChar           ,        2, GetConvertInfo, ConvertChar           , 0xAA55AA55           , 0x55AA55AA  , 0xAA55AA55 , param_GetConvertInfo.pConvertInfo, NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                              );
/*----------+---+-------------+------------+----------------------------+---------+---------------+-----------------------+----------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+-----------------------------------*/
TEST_CONVERT(  5, 0xAA55AA55  , 0x55AA55AA , stub_ConvertPercent        ,        2, GetConvertInfo, ConvertPercent        , 0x55AA55AA           , NULL        , NULL       , NULL                             , 0xAA55AA55  , 0x55AA55AA , param_GetConvertInfo.pConvertInfo, NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                              );
TEST_CONVERT(  6, 0x55AA55AA  , 0xAA55AA55 , stub_ConvertPercent        ,        2, GetConvertInfo, ConvertPercent        , 0xAA55AA55           , NULL        , NULL       , NULL                             , 0x55AA55AA  , 0xAA55AA55 , param_GetConvertInfo.pConvertInfo, NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                              );
/*----------+---+-------------+------------+----------------------------+---------+---------------+-----------------------+----------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+-----------------------------------*/
TEST_CONVERT(  7, 0xAA55AA55  , 0x55AA55AA , stub_ConvertSignedInteger  ,        2, GetConvertInfo, ConvertSignedInteger  , 0x55AA55AA           , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , 0xAA55AA55  , 0x55AA55AA , param_GetConvertInfo.pConvertInfo, NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                              );
TEST_CONVERT(  8, 0x55AA55AA  , 0xAA55AA55 , stub_ConvertSignedInteger  ,        2, GetConvertInfo, ConvertSignedInteger  , 0xAA55AA55           , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , 0x55AA55AA  , 0xAA55AA55 , param_GetConvertInfo.pConvertInfo, NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                              );
/*----------+---+-------------+------------+----------------------------+---------+---------------+-----------------------+----------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+-----------------------------------*/
TEST_CONVERT(  9, 0xAA55AA55  , 0x55AA55AA , stub_ConvertString         ,        2, GetConvertInfo, ConvertString         , 0x55AA55AA           , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , 0xAA55AA55  , 0x55AA55AA , param_GetConvertInfo.pConvertInfo, NULL        , NULL       , NULL                              );
TEST_CONVERT( 10, 0x55AA55AA  , 0xAA55AA55 , stub_ConvertString         ,        2, GetConvertInfo, ConvertString         , 0xAA55AA55           , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , 0x55AA55AA  , 0xAA55AA55 , param_GetConvertInfo.pConvertInfo, NULL        , NULL       , NULL                              );
/*----------+---+-------------+------------+----------------------------+---------+---------------+-----------------------+----------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+-----------------------------------*/
TEST_CONVERT( 11, 0xAA55AA55  , 0x55AA55AA , stub_ConvertUnsignedInteger,        2, GetConvertInfo, ConvertUnsignedInteger, 0x55AA55AA           , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , 0xAA55AA55  , 0x55AA55AA , param_GetConvertInfo.pConvertInfo );
TEST_CONVERT( 12, 0x55AA55AA  , 0xAA55AA55 , stub_ConvertUnsignedInteger,        2, GetConvertInfo, ConvertUnsignedInteger, 0xAA55AA55           , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , NULL        , NULL       , NULL                             , 0x55AA55AA  , 0xAA55AA55 , param_GetConvertInfo.pConvertInfo );
/*----------+---+-------------+------------+----------------------------+---------+---------------+-----------------------+----------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+----------------------------------+-------------+------------+-----------------------------------*/

static void test_Convert( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "Convert", NULL, NULL );

    CU_add_test( suite, "#_1", test_Convert_1  );
    CU_add_test( suite, "#_2", test_Convert_2  );
    CU_add_test( suite, "#_3", test_Convert_3  );
    CU_add_test( suite, "#_4", test_Convert_4  );
    CU_add_test( suite, "#_5", test_Convert_5  );
    CU_add_test( suite, "#_6", test_Convert_6  );
    CU_add_test( suite, "#_7", test_Convert_7  );
    CU_add_test( suite, "#_8", test_Convert_8  );
    CU_add_test( suite, "#_9", test_Convert_9  );
    CU_add_test( suite, "#10", test_Convert_10 );
    CU_add_test( suite, "#11", test_Convert_11 );
    CU_add_test( suite, "#12", test_Convert_12 );

    return;
}


/******************************************************************************/
/* ConvertChar                                                                */
/******************************************************************************/
static void test_ConvertChar_main( OutputInfo_t  *pOutputInfo,
                                   InputInfo_t   *pInputInfo,
                                   ConvertInfo_t *pConvertInfo,
                                   ...                          )
{
    va_start( pInputInfo->args, pConvertInfo );

    ConvertChar( pOutputInfo, pInputInfo, pConvertInfo );

    va_end( pInputInfo->args );

    return;
}

#define TEST_CONVERTCHAR( _NO,                                                  \
                          _IN_C,                                                \
                          _IN_WIDTH,                                            \
                          _IN_FLAG,                                             \
                          _OUT_C_0, _OUT_SIZECHAR_0,                            \
                          _OUT_C_1, _OUT_SIZECHAR_1  )                          \
    static void test_ConvertChar_##_NO( void )                                  \
    {                                                                           \
        OutputInfo_t  outputInfo;                                               \
        InputInfo_t   inputInfo;                                                \
        ConvertInfo_t convertInfo;                                              \
                                                                                \
        /* INPUT設定 */                                                         \
        UtilInit();                                                             \
        convertInfo.width = _IN_WIDTH;                                          \
        convertInfo.flag  = _IN_FLAG;                                           \
                                                                                \
        /* OUTPUT初期化 */                                                      \
        param_PutChar[ 0 ].pOutputInfo = NULL;                                  \
        param_PutChar[ 0 ].c           = ~( _OUT_C_0 );                         \
        param_PutChar[ 0 ].sizeChar    = ~( _OUT_SIZECHAR_0 );                  \
        param_PutChar[ 1 ].pOutputInfo = NULL;                                  \
        param_PutChar[ 1 ].c           = ~( _OUT_C_1 );                         \
        param_PutChar[ 1 ].sizeChar    = ~( _OUT_SIZECHAR_1 );                  \
                                                                                \
        test_ConvertChar_main( &outputInfo, &inputInfo, &convertInfo, _IN_C );  \
                                                                                \
        /* OUTPUT判定 */                                                        \
        CU_ASSERT_PTR_EQUAL( param_PutChar[ 0 ].pOutputInfo, &outputInfo     ); \
        CU_ASSERT_EQUAL(     param_PutChar[ 0 ].c,           _OUT_C_0        ); \
        CU_ASSERT_EQUAL(     param_PutChar[ 0 ].sizeChar,    _OUT_SIZECHAR_0 ); \
        CU_ASSERT_PTR_EQUAL( param_PutChar[ 1 ].pOutputInfo, &outputInfo     ); \
        CU_ASSERT_EQUAL(     param_PutChar[ 1 ].c,           _OUT_C_1        ); \
        CU_ASSERT_EQUAL(     param_PutChar[ 1 ].sizeChar,    _OUT_SIZECHAR_1 ); \
        CU_ASSERT_EQUAL(     UtilGetCallCount(),             2               ); \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 0 ),           PutChar         ); \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 1 ),           PutChar         ); \
                                                                                \
        return;                                                                 \
}

/*--------------+---+-------------------------------------------------------+----------------------------------------------*/
/*              | # | INPUT                                                 | OUTPUT                                       */
/*              |   +--------------------+----------------------------------+----------------------+-----------------------*/
/*              |   | c                  | *pConvertInfo                    | PutChar[ 0 ]         | Putchar[ 1 ]          */
/*              |   |                    +-----------------------+----------+---------+------------+---------+-------------*/
/*              |   |                    | width                 | flag     | c       | sizeChar   | c       | sizeChar    */
/*--------------+---+--------------------+-----------------------+----------+---------+------------+---------+-------------*/
TEST_CONVERTCHAR(  1, /* 最小 */ CHAR_MIN, /* 最大 */ INT_MAX    ,         0, ' '     , INT_MAX - 1, CHAR_MIN,           1 );
TEST_CONVERTCHAR(  2, /* 中間 */        0, /* 中間 */          -1,         0, ' '     ,      -1 - 1,        0,           1 );
TEST_CONVERTCHAR(  3, /* 最大 */ CHAR_MAX, /* 最小 */ INT_MIN + 1,         0, ' '     , INT_MIN    , CHAR_MAX,           1 );
/*--------------+---+--------------------+-----------------------+----------+---------+------------+---------+-------------*/
TEST_CONVERTCHAR(  4, /* 最小 */ CHAR_MIN, /* 最大 */ INT_MAX    , FLAG_LEFT, CHAR_MIN,           1, ' '     , INT_MAX - 1 );
TEST_CONVERTCHAR(  5, /* 中間 */        0, /* 中間 */          -1, FLAG_LEFT,        0,           1, ' '     ,      -1 - 1 );
TEST_CONVERTCHAR(  6, /* 最大 */ CHAR_MAX, /* 最小 */ INT_MIN + 1, FLAG_LEFT, CHAR_MAX,           1, ' '     , INT_MIN     );
/*--------------+---+--------------------+-----------------------+----------+---------+------------+---------+-------------*/

static void test_ConvertChar( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "ConvertChar", NULL, NULL );

    CU_add_test( suite, "#_1", test_ConvertChar_1 );
    CU_add_test( suite, "#_2", test_ConvertChar_2 );
    CU_add_test( suite, "#_3", test_ConvertChar_3 );
    CU_add_test( suite, "#_4", test_ConvertChar_4 );
    CU_add_test( suite, "#_5", test_ConvertChar_5 );
    CU_add_test( suite, "#_6", test_ConvertChar_6 );

    return;
}


/******************************************************************************/
/* ConvertPercent                                                             */
/******************************************************************************/
#define TEST_CONVERTPERCENT( _NO,                                               \
                             _IN_POUTPUTINFO )                                  \
    static void test_ConvertPercent_##_NO( void )                               \
    {                                                                           \
        /* INPUT設定 */                                                         \
        UtilInit();                                                             \
                                                                                \
        /* OUTPUT初期化 */                                                      \
        param_PutChar[ 0 ].pOutputInfo = NULL;                                  \
        param_PutChar[ 0 ].c           = 0;                                     \
        param_PutChar[ 0 ].sizeChar    = 0;                                     \
                                                                                \
        ConvertPercent( ( OutputInfo_t * ) _IN_POUTPUTINFO, NULL, NULL );       \
                                                                                \
        CU_ASSERT_EQUAL(     UtilGetCallCount(),             1               ); \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 0 ),           PutChar         ); \
        CU_ASSERT_PTR_EQUAL( param_PutChar[ 0 ].pOutputInfo, _IN_POUTPUTINFO ); \
        CU_ASSERT_PTR_EQUAL( param_PutChar[ 0 ].c,           '%'             ); \
        CU_ASSERT_PTR_EQUAL( param_PutChar[ 0 ].sizeChar,    1               ); \
                                                                                \
        return;                                                                 \
    }

/*-----------------+---+-------------*/
/*                 | # | INPUT       */
/*                 |   +-------------*/
/*                 |   | pOutputInfo */
/*-----------------+---+-------------*/
TEST_CONVERTPERCENT(  1, 0x55AA55AA  );
TEST_CONVERTPERCENT(  2, 0xAA55AA55  );
/*-----------------+---+-------------*/

static void test_ConvertPercent( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "ConvertPercent", NULL, NULL );

    CU_add_test( suite, "#_1", test_ConvertPercent_1 );
    CU_add_test( suite, "#_2", test_ConvertPercent_2 );

    return;
}


/******************************************************************************/
/* ConvertSignedInteger                                                       */
/******************************************************************************/
#define TEST_CONVERTSIGNEDINTEGER( _NO,                                                                 \
                                   _IN_VALUE,                                                           \
                                   _IN_LENGTH,                                                          \
                                   _IN_LENSIGN,                                                         \
                                   _IN_LENZERO,                                                         \
                                   _IN_LENVAL,                                                          \
                                   _IN_WIDTH,                                                           \
                                   _IN_FLAG,                                                            \
                                   _IN_SIGN,                                                            \
                                   _OUT_C_0,                                                            \
                                   _OUT_SIZECHAR_0,                                                     \
                                   _OUT_C_1,                                                            \
                                   _OUT_SIZECHAR_1,                                                     \
                                   _OUT_CALLCNT,                                                        \
                                   _OUT_CALLFUNC_0,                                                     \
                                   _OUT_CALLFUNC_1,                                                     \
                                   _OUT_CALLFUNC_2,                                                     \
                                   _OUT_CALLFUNC_3,                                                     \
                                   _OUT_CALLFUNC_4,                                                     \
                                   _OUT_CALLFUNC_5,                                                     \
                                   _OUT_CALLFUNC_6  )                                                   \
    static void test_ConvertSignedInteger_##_NO( void )                                                 \
    {                                                                                                   \
        OutputInfo_t  outputInfo;                                                                       \
        InputInfo_t   inputInfo;                                                                        \
        ConvertInfo_t convertInfo;                                                                      \
                                                                                                        \
        /* INPUT設定 */                                                                                 \
        UtilInit();                                                                                     \
        convertInfo.length         = _IN_LENGTH;                                                        \
        convertInfo.lenSign        = _IN_LENSIGN;                                                       \
        convertInfo.lenZero        = _IN_LENZERO;                                                       \
        convertInfo.lenVal         = _IN_LENVAL;                                                        \
        convertInfo.width          = _IN_WIDTH;                                                         \
        convertInfo.flag           = _IN_FLAG;                                                          \
        convertInfo.sign           = _IN_SIGN;                                                          \
        param_PopSignedInteger.ret = _IN_VALUE;                                                         \
                                                                                                        \
        /* OUTPUT初期化 */                                                                              \
        param_PopSignedInteger.pInputInfo     = NULL;                                                   \
        param_PopSignedInteger.pConvertInfo   = NULL;                                                   \
        param_SetSign.pConvertInfo            = NULL;                                                   \
        param_SetSign.value                   = ~( _IN_VALUE );                                         \
        param_SetInteger.pConvertInfo         = NULL;                                                   \
        param_SetInteger.value                = ~( _IN_VALUE );                                         \
        param_SetZeroVsPrecision.pConvertInfo = NULL;                                                   \
        param_PutChar[ 0 ].pOutputInfo        = NULL;                                                   \
        param_PutChar[ 0 ].c                  = ~( _OUT_C_0 );                                          \
        param_PutChar[ 0 ].sizeChar           = ~( _OUT_SIZECHAR_0 );                                   \
        param_PutChar[ 1 ].pOutputInfo        = NULL;                                                   \
        param_PutChar[ 1 ].c                  = ~( _OUT_C_1 );                                          \
        param_PutChar[ 1 ].sizeChar           = ~( _OUT_SIZECHAR_1 );                                   \
        param_PutInteger.pOutputInfo          = NULL;                                                   \
        param_PutInteger.pConvertInfo         = NULL;                                                   \
                                                                                                        \
        ConvertSignedInteger( &outputInfo, &inputInfo, &convertInfo );                                  \
                                                                                                        \
        /* OUTPUT判定 */                                                                                \
        CU_ASSERT_PTR_EQUAL( param_PopSignedInteger.pInputInfo,     &inputInfo                       ); \
        CU_ASSERT_EQUAL(     param_PopSignedInteger.pConvertInfo,   &convertInfo                     ); \
        CU_ASSERT_PTR_EQUAL( param_SetSign.pConvertInfo,            &convertInfo                     ); \
        CU_ASSERT_EQUAL(     param_SetSign.value,                   _IN_VALUE                        ); \
        CU_ASSERT_PTR_EQUAL( param_SetInteger.pConvertInfo,         &convertInfo                     ); \
        CU_ASSERT_EQUAL(     param_SetInteger.value,                ( unsigned long long ) _IN_VALUE ); \
        CU_ASSERT_PTR_EQUAL( param_SetZeroVsPrecision.pConvertInfo, &convertInfo                     ); \
        CU_ASSERT_PTR_EQUAL( param_PutChar[ 0 ].pOutputInfo,        &outputInfo                      ); \
        CU_ASSERT_EQUAL(     param_PutChar[ 0 ].c,                  _OUT_C_0                         ); \
        CU_ASSERT_EQUAL(     param_PutChar[ 0 ].sizeChar,           _OUT_SIZECHAR_0                  ); \
        CU_ASSERT_PTR_EQUAL( param_PutChar[ 1 ].pOutputInfo,        &outputInfo                      ); \
        CU_ASSERT_EQUAL(     param_PutChar[ 1 ].c,                  _OUT_C_1                         ); \
        CU_ASSERT_EQUAL(     param_PutChar[ 1 ].sizeChar,           _OUT_SIZECHAR_1                  ); \
        CU_ASSERT_PTR_EQUAL( param_PutInteger.pOutputInfo,          &outputInfo                      ); \
        CU_ASSERT_PTR_EQUAL( param_PutInteger.pConvertInfo,         &convertInfo                     ); \
        CU_ASSERT_EQUAL(     UtilGetCallCount(),                    _OUT_CALLCNT                     ); \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 0 ),                  _OUT_CALLFUNC_0                  ); \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 1 ),                  _OUT_CALLFUNC_1                  ); \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 2 ),                  _OUT_CALLFUNC_2                  ); \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 3 ),                  _OUT_CALLFUNC_3                  ); \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 4 ),                  _OUT_CALLFUNC_4                  ); \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 5 ),                  _OUT_CALLFUNC_5                  ); \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 6 ),                  _OUT_CALLFUNC_6                  ); \
                                                                                                        \
        return;                                                                                         \
    }

/*-----------------------+---+-----------------------------------------------------------------------------------------------------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*                       | # | INPUT                                                                                                           | OUTPUT                                                                                                                                                       */
/*                       |   +---------------------+-------------------------------------------------------------------------------------------+------------------------------------------------------+----------+--------------------------------------------------------------------------------------------*/
/*                       |   | value               | pConvertInfo                                                                              | PutChar()                                            | Call cnt | Call func                                                                                  */
/*                       |   |                     +----------------+----------+----------+----------+--------+-----------+--------------------+------------------------+-----------------------------+          +-----------------+--------+-----------+-------------------+--------+-----------+------------*/
/*                       |   |                     | length         | lenSign  | lenZero  | lenVal   | width  | flag      | sign               | [ 0 ]                  | [ 2 ]                       |          | [ 0 ]           | [ 1 ]  | [ 2 ]     | [ 3 ]             | [ 4 ]  | [ 5 ]     | [ 6 ]      */
/*                       |   |                     |                |          |          |          |        |           |                    |----+-------------------+---------+-------------------+          |                 |        |           |                   |        |           |            */
/*                       |   |                     |                |          |          |          |        |           |                    | c  | sizeChar          | c       | sizeChar          |          |                 |        |           |                   |        |           |            */
/*-----------------------+---+---------------------+----------------+----------+----------+----------+--------+-----------+--------------------+----+-------------------+---------+-------------------+----------+-----------------+--------+-----------+-------------------+--------+-----------+------------*/
TEST_CONVERTSIGNEDINTEGER(  1, /* 最小 */ LLONG_MIN, /* 最大 */ 0xFF,         0,         0,         0,       0,          0,                   0, ' ',                  0,        0,                  0,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutChar   , PutInteger );
TEST_CONVERTSIGNEDINTEGER(  2, /* 中間 */         0, /* 中間 */ 0x7F,         0,         0,         0,       0,          0,                   0, ' ',                  0,        0,                  0,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutChar   , PutInteger );
TEST_CONVERTSIGNEDINTEGER(  3, /* 最大 */ LLONG_MAX, /* 最小 */    0,         0,         0,         0,       0,          0,                   0, ' ',                  0,        0,                  0,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutChar   , PutInteger );
/*-----------------------+---+---------------------+----------------+----------+----------+----------+--------+-----------+--------------------+----+-------------------+---------+-------------------+----------+-----------------+--------+-----------+-------------------+--------+-----------+------------*/
TEST_CONVERTSIGNEDINTEGER(  4,                    0,               0, SSIZE_MAX,         0,         0,       0,          0,                   0, ' ', 0 - SSIZE_MAX     ,        0, SSIZE_MAX         ,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutChar   , PutInteger );
TEST_CONVERTSIGNEDINTEGER(  5,                    0,               0,         0, SSIZE_MAX,         0,       0,          0,                   0, ' ', 0 - SSIZE_MAX     ,        0,                  0,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutChar   , PutInteger );
TEST_CONVERTSIGNEDINTEGER(  6,                    0,               0,         0,         0, SSIZE_MAX,       0,          0,                   0, ' ', 0 - SSIZE_MAX     ,        0,                  0,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutChar   , PutInteger );
TEST_CONVERTSIGNEDINTEGER(  7,                    0,               0,         0,         0,         0, INT_MAX,          0,                   0, ' ', INT_MAX           ,        0,                  0,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutChar   , PutInteger );
TEST_CONVERTSIGNEDINTEGER(  8,                    0,               0,         1,         2,         3,      45, ~FLAG_LEFT,                   0, ' ', 45 - ( 1 + 2 + 3 ),        0,                  1,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutChar   , PutInteger );
/*-----------------------+---+---------------------+----------------+----------+----------+----------+--------+-----------+--------------------+----+-------------------+---------+-------------------+----------+-----------------+--------+-----------+-------------------+--------+-----------+------------*/
TEST_CONVERTSIGNEDINTEGER(  9,                    0,               0, SSIZE_MAX,         0,         0,       0,  FLAG_LEFT,                   0,   0, SSIZE_MAX         , ' '     , 0 - SSIZE_MAX     ,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutInteger, PutChar    );
TEST_CONVERTSIGNEDINTEGER( 10,                    0,               0,         0, SSIZE_MAX,         0,       0,  FLAG_LEFT,                   0,   0,                  0, ' '     , 0 - SSIZE_MAX     ,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutInteger, PutChar    );
TEST_CONVERTSIGNEDINTEGER( 11,                    0,               0,         0,         0, SSIZE_MAX,       0,  FLAG_LEFT,                   0,   0,                  0, ' '     , 0 - SSIZE_MAX     ,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutInteger, PutChar    );
TEST_CONVERTSIGNEDINTEGER( 12,                    0,               0,         0,         0,         0, INT_MAX,  FLAG_LEFT,                   0,   0,                  0, ' '     , INT_MAX           ,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutInteger, PutChar    );
TEST_CONVERTSIGNEDINTEGER( 13,                    0,               0,         4,         3,         2,      10,       0xFF,                   0,   0,                  4, ' '     , 10 - ( 4 + 3 + 2 ),         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutInteger, PutChar    );
/*-----------------------+---+---------------------+----------------+----------+----------+----------+--------+-----------+--------------------+----+-------------------+---------+-------------------+----------+-----------------+--------+-----------+-------------------+--------+-----------+------------*/
TEST_CONVERTSIGNEDINTEGER( 14,                    0,               0,         0,         0,         0,       0,          0, /* 最小 */ CHAR_MIN, ' ',                  0, CHAR_MIN,                  0,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutChar   , PutInteger );
TEST_CONVERTSIGNEDINTEGER( 15,                    0,               0,         0,         0,         0,       0,          0, /* 最大 */ CHAR_MAX, ' ',                  0, CHAR_MAX,                  0,         7, PopSignedInteger, SetSign, SetInteger, SetZeroVsPrecision, PutChar, PutChar   , PutInteger );
/*-----------------------+---+---------------------+----------------+----------+----------+----------+--------+-----------+--------------------+----+-------------------+---------+-------------------+----------+-----------------+--------+-----------+-------------------+--------+-----------+------------*/

static void test_ConvertSignedInteger( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "ConvertSignedInteger", NULL, NULL );

    CU_add_test( suite, "#_1", test_ConvertSignedInteger_1  );
    CU_add_test( suite, "#_2", test_ConvertSignedInteger_2  );
    CU_add_test( suite, "#_3", test_ConvertSignedInteger_3  );
    CU_add_test( suite, "#_4", test_ConvertSignedInteger_4  );
    CU_add_test( suite, "#_5", test_ConvertSignedInteger_5  );
    CU_add_test( suite, "#_6", test_ConvertSignedInteger_6  );
    CU_add_test( suite, "#_7", test_ConvertSignedInteger_7  );
    CU_add_test( suite, "#_8", test_ConvertSignedInteger_8  );
    CU_add_test( suite, "#_9", test_ConvertSignedInteger_9  );
    CU_add_test( suite, "#10", test_ConvertSignedInteger_10 );
    CU_add_test( suite, "#11", test_ConvertSignedInteger_11 );
    CU_add_test( suite, "#12", test_ConvertSignedInteger_12 );
    CU_add_test( suite, "#13", test_ConvertSignedInteger_13 );
    CU_add_test( suite, "#14", test_ConvertSignedInteger_14 );
    CU_add_test( suite, "#15", test_ConvertSignedInteger_15 );

    return;
}


/******************************************************************************/
/* ConvertString                                                              */
/******************************************************************************/
static void test_ConvertString_main( OutputInfo_t  *pOutputInfo,
                                     InputInfo_t   *pInputInfo,
                                     ConvertInfo_t *pConvertInfo,
                                     ...                          )
{
    va_start( pInputInfo->args, pConvertInfo );

    ConvertString( pOutputInfo, pInputInfo, pConvertInfo );

    va_end( pInputInfo->args );

    return;
}

#define TEST_CONVERTSTRING( _NO,                                                    \
                            _IN_STR,                                                \
                            _IN_PRECISION,                                          \
                            _IN_WIDTH,                                              \
                            _IN_FLAG,                                               \
                            _OUT_C,                                                 \
                            _OUT_SIZECHAR,                                          \
                            _OUT_SIZESTR,                                           \
                            _OUT_CALLFUNC_0,                                        \
                            _OUT_CALLFUNC_1  )                                      \
    static void test_ConvertString_##_NO( void )                                    \
    {                                                                               \
        OutputInfo_t  outputInfo;                                                   \
        InputInfo_t   inputInfo;                                                    \
        ConvertInfo_t convertInfo;                                                  \
                                                                                    \
        /* INPUT設定 */                                                             \
        UtilInit();                                                                 \
        convertInfo.precision = _IN_PRECISION;                                      \
        convertInfo.width     = _IN_WIDTH;                                          \
        convertInfo.flag      = _IN_FLAG;                                           \
                                                                                    \
        /* OUTPUT初期化 */                                                          \
        param_PutChar[ 0 ].pOutputInfo = NULL;                                      \
        param_PutChar[ 0 ].c           = ~( _OUT_C );                               \
        param_PutChar[ 0 ].sizeChar    = ~( _OUT_SIZECHAR );                        \
                                                                                    \
        test_ConvertString_main( &outputInfo, &inputInfo, &convertInfo, _IN_STR );  \
                                                                                    \
        /* OUTPUT判定 */                                                            \
        CU_ASSERT_PTR_EQUAL( param_PutChar[ 0 ].pOutputInfo, &outputInfo     );     \
        CU_ASSERT_EQUAL(     param_PutChar[ 0 ].c,           _OUT_C          );     \
        CU_ASSERT_EQUAL(     param_PutChar[ 0 ].sizeChar,    _OUT_SIZECHAR   );     \
        CU_ASSERT_PTR_EQUAL( param_PutStr.pOutputInfo,       &outputInfo     );     \
        CU_ASSERT_EQUAL(     param_PutStr.pStr,              _IN_STR         );     \
        CU_ASSERT_EQUAL(     param_PutStr.sizeStr,           _OUT_SIZESTR    );     \
        CU_ASSERT_EQUAL(     UtilGetCallCount(),             2               );     \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 0 ),           _OUT_CALLFUNC_0 );     \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 1 ),           _OUT_CALLFUNC_1 );     \
                                                                                    \
        return;                                                                     \
}

/*----------------+---+----------------------------------------------------------------+----------------------------------------------*/
/*                | # | INPUT                                                          | OUTPUT                                       */
/*                |   +-----------------+----------------------------------------------+-----------------+---------+------------------*/
/*                |   | pStr            | *pConvertInfo                                | PutChar[ 0 ]    | PutStr  | Call func        */
/*                |   |                 +-----------+-----------------------+----------+----+------------+---------+--------+---------*/
/*                |   |                 | precision | width                 | flag     | c  | sizeChar   | sizeStr | [ 0 ]  | [ 1 ]   */
/*----------------+---+-----------------+-----------+-----------------------+----------+----+------------+---------+--------+---------*/
TEST_CONVERTSTRING(  1, /* 0文字 */ ""  ,         -1, /* 最大 */ INT_MAX    ,         0, ' ', INT_MAX - 0,        0, PutChar, PutStr  );
TEST_CONVERTSTRING(  4,             ""  ,         -1,            INT_MAX    , FLAG_LEFT, ' ', INT_MAX - 0,        0, PutStr , PutChar );
TEST_CONVERTSTRING(  2,             ""  ,         -1, /* 中間 */          -1,         0, ' ',      -1 - 0,        0, PutChar, PutStr  );
TEST_CONVERTSTRING(  5,             ""  ,         -1,                     -1, FLAG_LEFT, ' ',      -1 - 0,        0, PutStr , PutChar );
TEST_CONVERTSTRING(  3,             ""  ,         -1, /* 最小 */ INT_MIN    ,         0, ' ', INT_MIN    ,        0, PutChar, PutStr  );
TEST_CONVERTSTRING(  6,             ""  ,         -1,            INT_MIN    , FLAG_LEFT, ' ', INT_MIN    ,        0, PutStr , PutChar );
/*----------------+---+-----------------+-----------+-----------------------+----------+----+------------+---------+--------+---------*/
TEST_CONVERTSTRING(  7, /* 1文字 */ "1" ,         -1, /* 最大 */ INT_MAX    ,         0, ' ', INT_MAX - 1,        1, PutChar, PutStr  );
TEST_CONVERTSTRING(  8,             "1" ,         -1,            INT_MAX    , FLAG_LEFT, ' ', INT_MAX - 1,        1, PutStr , PutChar );
TEST_CONVERTSTRING(  9,             "1" ,         -1, /* 中間 */          -1,         0, ' ',      -1 - 1,        1, PutChar, PutStr  );
TEST_CONVERTSTRING( 10,             "1" ,         -1,                     -1, FLAG_LEFT, ' ',      -1 - 1,        1, PutStr , PutChar );
TEST_CONVERTSTRING( 11,             "1" ,         -1, /* 最小 */ INT_MIN + 1,         0, ' ', INT_MIN    ,        1, PutChar, PutStr  );
TEST_CONVERTSTRING( 12,             "1" ,         -1,            INT_MIN + 1, FLAG_LEFT, ' ', INT_MIN    ,        1, PutStr , PutChar );
/*----------------+---+-----------------+-----------+-----------------------+----------+----+------------+---------+--------+---------*/
TEST_CONVERTSTRING( 13, /* 2文字 */ "12",         -1, /* 最大 */ INT_MAX    ,         0, ' ', INT_MAX - 2,        2, PutChar, PutStr  );
TEST_CONVERTSTRING( 14,             "12",         -1,            INT_MAX    , FLAG_LEFT, ' ', INT_MAX - 2,        2, PutStr , PutChar );
TEST_CONVERTSTRING( 15,             "12",         -1, /* 中間 */          -1,         0, ' ',      -1 - 2,        2, PutChar, PutStr  );
TEST_CONVERTSTRING( 16,             "12",         -1,                     -1, FLAG_LEFT, ' ',      -1 - 2,        2, PutStr , PutChar );
TEST_CONVERTSTRING( 17,             "12",         -1, /* 最小 */ INT_MIN + 2,         0, ' ', INT_MIN    ,        2, PutChar, PutStr  );
TEST_CONVERTSTRING( 18,             "12",         -1,            INT_MIN + 2, FLAG_LEFT, ' ', INT_MIN    ,        2, PutStr , PutChar );
/*----------------+---+-----------------+-----------+-----------------------+----------+----+------------+---------+--------+---------*/
TEST_CONVERTSTRING( 19, "1234567890"    ,          0, /* 最大 */ INT_MAX    ,         0, ' ', INT_MAX - 0,        0, PutChar, PutStr  );
TEST_CONVERTSTRING( 20, "1234567890"    ,          1, /* 最大 */ INT_MAX    , FLAG_LEFT, ' ', INT_MAX - 1,        1, PutStr , PutChar );
TEST_CONVERTSTRING( 21, "1234567890"    ,          2, /* 最大 */ INT_MAX    ,         0, ' ', INT_MAX - 2,        2, PutChar, PutStr  );
/*----------------+---+-----------------+-----------+-----------------------+----------+----+------------+---------+--------+---------*/

static void test_ConvertString( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "ConvertString", NULL, NULL );

    CU_add_test( suite, "#_1", test_ConvertString_1  );
    CU_add_test( suite, "#_2", test_ConvertString_2  );
    CU_add_test( suite, "#_3", test_ConvertString_3  );
    CU_add_test( suite, "#_4", test_ConvertString_4  );
    CU_add_test( suite, "#_5", test_ConvertString_5  );
    CU_add_test( suite, "#_6", test_ConvertString_6  );
    CU_add_test( suite, "#_7", test_ConvertString_7  );
    CU_add_test( suite, "#_8", test_ConvertString_8  );
    CU_add_test( suite, "#_9", test_ConvertString_9  );
    CU_add_test( suite, "#10", test_ConvertString_10 );
    CU_add_test( suite, "#11", test_ConvertString_11 );
    CU_add_test( suite, "#12", test_ConvertString_12 );
    CU_add_test( suite, "#13", test_ConvertString_13 );
    CU_add_test( suite, "#14", test_ConvertString_14 );
    CU_add_test( suite, "#15", test_ConvertString_15 );
    CU_add_test( suite, "#16", test_ConvertString_16 );
    CU_add_test( suite, "#17", test_ConvertString_17 );
    CU_add_test( suite, "#18", test_ConvertString_18 );
    CU_add_test( suite, "#19", test_ConvertString_19 );
    CU_add_test( suite, "#20", test_ConvertString_20 );
    CU_add_test( suite, "#21", test_ConvertString_21 );

    return;
}




/******************************************************************************/
/* ConvertUnsginedInteger                                                     */
/******************************************************************************/
#define TEST_CONVERTUNSIGNEDINTEGER( _NO,                                               \
                                     _IN_VALUE,                                         \
                                     _IN_LENGTH,                                        \
                                     _IN_LENALT,                                        \
                                     _IN_LENZERO,                                       \
                                     _IN_LENVAL,                                        \
                                     _IN_WIDTH,                                         \
                                     _IN_FLAG,                                          \
                                     _IN_PALT,                                          \
                                     _OUT_C,                                            \
                                     _OUT_SIZECHAR,                                     \
                                     _OUT_CALLCNT,                                      \
                                     _OUT_CALLFUNC_0,                                   \
                                     _OUT_CALLFUNC_1,                                   \
                                     _OUT_CALLFUNC_2,                                   \
                                     _OUT_CALLFUNC_3,                                   \
                                     _OUT_CALLFUNC_4,                                   \
                                     _OUT_CALLFUNC_5,                                   \
                                     _OUT_CALLFUNC_6  )                                 \
    static void test_ConvertUnsignedInteger_##_NO( void )                               \
    {                                                                                   \
        OutputInfo_t  outputInfo;                                                       \
        InputInfo_t   inputInfo;                                                        \
        ConvertInfo_t convertInfo;                                                      \
                                                                                        \
        /* INPUT設定 */                                                                 \
        UtilInit();                                                                     \
        convertInfo.length           = _IN_LENGTH;                                      \
        convertInfo.lenAlt           = _IN_LENALT;                                      \
        convertInfo.lenZero          = _IN_LENZERO;                                     \
        convertInfo.lenVal           = _IN_LENVAL;                                      \
        convertInfo.width            = _IN_WIDTH;                                       \
        convertInfo.flag             = _IN_FLAG;                                        \
        convertInfo.pAlt             = _IN_PALT;                                        \
        param_PopUnsignedInteger.ret = _IN_VALUE;                                       \
                                                                                        \
        /* OUTPUT初期化 */                                                              \
        param_PopUnsignedInteger.pInputInfo   = NULL;                                   \
        param_PopUnsignedInteger.pConvertInfo = NULL;                                   \
        param_SetAlt.pConvertInfo             = NULL;                                   \
        param_SetInteger.pConvertInfo         = NULL;                                   \
        param_SetInteger.value                = ~( _IN_VALUE );                         \
        param_SetZeroVsPrecision.pConvertInfo = NULL;                                   \
        param_PutChar[ 0 ].pOutputInfo        = NULL;                                   \
        param_PutChar[ 0 ].c                  = ~( _OUT_C );                            \
        param_PutChar[ 0 ].sizeChar           = ~( _OUT_SIZECHAR );                     \
        param_PutStr.pOutputInfo              = NULL;                                   \
        param_PutStr.pStr                     = NULL;                                   \
        param_PutStr.sizeStr                  = ~( _IN_LENALT );                        \
        param_PutInteger.pOutputInfo          = NULL;                                   \
        param_PutInteger.pConvertInfo         = NULL;                                   \
                                                                                        \
        ConvertUnsignedInteger( &outputInfo, &inputInfo, &convertInfo );                \
                                                                                        \
        /* OUTPUT判定 */                                                                \
        CU_ASSERT_PTR_EQUAL( param_PopUnsignedInteger.pInputInfo,   &inputInfo      );  \
        CU_ASSERT_EQUAL(     param_PopUnsignedInteger.pConvertInfo, &convertInfo    );  \
        CU_ASSERT_PTR_EQUAL( param_SetAlt.pConvertInfo,             &convertInfo    );  \
        CU_ASSERT_PTR_EQUAL( param_SetInteger.pConvertInfo,         &convertInfo    );  \
        CU_ASSERT_EQUAL(     param_SetInteger.value,                _IN_VALUE       );  \
        CU_ASSERT_PTR_EQUAL( param_SetZeroVsPrecision.pConvertInfo, &convertInfo    );  \
        CU_ASSERT_PTR_EQUAL( param_PutChar[ 0 ].pOutputInfo,        &outputInfo     );  \
        CU_ASSERT_EQUAL(     param_PutChar[ 0 ].c,                  _OUT_C          );  \
        CU_ASSERT_EQUAL(     param_PutChar[ 0 ].sizeChar,           _OUT_SIZECHAR   );  \
        CU_ASSERT_PTR_EQUAL( param_PutStr.pOutputInfo,              &outputInfo     );  \
        CU_ASSERT_PTR_EQUAL( param_PutStr.pStr,                     _IN_PALT        );  \
        CU_ASSERT_EQUAL(     param_PutStr.sizeStr,                  _IN_LENALT      );  \
        CU_ASSERT_PTR_EQUAL( param_PutInteger.pOutputInfo,          &outputInfo     );  \
        CU_ASSERT_PTR_EQUAL( param_PutInteger.pConvertInfo,         &convertInfo    );  \
        CU_ASSERT_EQUAL(     UtilGetCallCount(),                    _OUT_CALLCNT    );  \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 0 ),                  _OUT_CALLFUNC_0 );  \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 1 ),                  _OUT_CALLFUNC_1 );  \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 2 ),                  _OUT_CALLFUNC_2 );  \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 3 ),                  _OUT_CALLFUNC_3 );  \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 4 ),                  _OUT_CALLFUNC_4 );  \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 5 ),                  _OUT_CALLFUNC_5 );  \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 6 ),                  _OUT_CALLFUNC_6 );  \
                                                                                        \
        return;                                                                         \
    }

/*-------------------------+---+---------------------------------------------------------------------------------------------------------+---------------------------------------------------------------------------------------------------------------------------------*/
/*                         | # | INPUT                                                                                                   | OUTPUT                                                                                                                          */
/*                         |   +-------------------------+-------------------------------------------------------------------------------+------------------------+----------+---------------------------------------------------------------------------------------------*/
/*                         |   | value                   | pConvertInfo                                                                  | PutChar()              | Call cnt | Call func                                                                                   */
/*                         |   |                         +----------------+----------+----------+----------+--------+-----------+--------+------------------------+          +-------------------+-------+-----------+-------------------+--------+-----------+------------*/
/*                         |   |                         | length         | lenAlt   | lenZero  | lenVal   | width  | flag      | pAlt   | [ 0 ]                  |          | [ 0 ]             | [ 1 ] | [ 2 ]     | [ 3 ]             | [ 4 ]  | [ 5 ]     | [ 6 ]      */
/*                         |   |                         |                |          |          |          |        |           |        |----+-------------------+          |                   |       |           |                   |        |           |            */
/*                         |   |                         |                |          |          |          |        |           |        | c  | sizeChar          |          |                   |       |           |                   |        |           |            */
/*-------------------------+---+-------------------------+----------------+----------+----------+----------+--------+-----------+--------+----+-------------------+----------+-------------------+-------+-----------+-------------------+--------+-----------+------------*/
TEST_CONVERTUNSIGNEDINTEGER(  1, /* 最小 */             0, /* 最大 */ 0xFF,         0,         0,         0,       0,          0, "DUMMY", ' ',                  0,         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutChar, PutStr    , PutInteger );
TEST_CONVERTUNSIGNEDINTEGER(  2, /* 中間 */ LLONG_MAX / 2, /* 中間 */ 0x7F,         0,         0,         0,       0,          0, "DUMMY", ' ',                  0,         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutChar, PutStr    , PutInteger );
TEST_CONVERTUNSIGNEDINTEGER(  3, /* 最大 */ LLONG_MAX    , /* 最小 */    0,         0,         0,         0,       0,          0, "DUMMY", ' ',                  0,         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutChar, PutStr    , PutInteger );
/*-------------------------+---+-------------------------+----------------+----------+----------+----------+--------+-----------+--------+----+-------------------+----------+-------------------+-------+-----------+-------------------+--------+-----------+------------*/
TEST_CONVERTUNSIGNEDINTEGER(  4,                        0,               0, SSIZE_MAX,         0,         0,       0,          0, "DUMMY", ' ', 0 - SSIZE_MAX     ,         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutChar, PutStr    , PutInteger );
TEST_CONVERTUNSIGNEDINTEGER(  5,                        0,               0,         0, SSIZE_MAX,         0,       0,          0, "DUMMY", ' ', 0 - SSIZE_MAX     ,         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutChar, PutStr    , PutInteger );
TEST_CONVERTUNSIGNEDINTEGER(  6,                        0,               0,         0,         0, SSIZE_MAX,       0,          0, "DUMMY", ' ', 0 - SSIZE_MAX     ,         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutChar, PutStr    , PutInteger );
TEST_CONVERTUNSIGNEDINTEGER(  7,                        0,               0,         0,         0,         0, INT_MAX,          0, "DUMMY", ' ', INT_MAX           ,         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutChar, PutStr    , PutInteger );
TEST_CONVERTUNSIGNEDINTEGER(  8,                        0,               0,         1,         2,         3,      45, ~FLAG_LEFT, "DUMMY", ' ', 45 - ( 1 + 2 + 3 ),         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutChar, PutStr    , PutInteger );
/*-------------------------+---+-------------------------+----------------+----------+----------+----------+--------+-----------+--------+----+-------------------+----------+-------------------+-------+-----------+-------------------+--------+-----------+------------*/
TEST_CONVERTUNSIGNEDINTEGER(  9,                        0,               0, SSIZE_MAX,         0,         0,       0,  FLAG_LEFT, "DUMMY", ' ', 0 - SSIZE_MAX     ,         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutStr , PutInteger, PutChar    );
TEST_CONVERTUNSIGNEDINTEGER( 10,                        0,               0,         0, SSIZE_MAX,         0,       0,  FLAG_LEFT, "DUMMY", ' ', 0 - SSIZE_MAX     ,         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutStr , PutInteger, PutChar    );
TEST_CONVERTUNSIGNEDINTEGER( 11,                        0,               0,         0,         0, SSIZE_MAX,       0,  FLAG_LEFT, "DUMMY", ' ', 0 - SSIZE_MAX     ,         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutStr , PutInteger, PutChar    );
TEST_CONVERTUNSIGNEDINTEGER( 12,                        0,               0,         0,         0,         0, INT_MAX,  FLAG_LEFT, "DUMMY", ' ', INT_MAX           ,         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutStr , PutInteger, PutChar    );
TEST_CONVERTUNSIGNEDINTEGER( 13,                        0,               0,         4,         3,         2,      10,       0xFF, "DUMMY", ' ', 10 - ( 4 + 3 + 2 ),         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutStr , PutInteger, PutChar    );
/*-------------------------+---+-------------------------+----------------+----------+----------+----------+--------+-----------+--------+----+-------------------+----------+-------------------+-------+-----------+-------------------+--------+-----------+------------*/
TEST_CONVERTUNSIGNEDINTEGER( 14,                        0,               0,         0,         0,         0,       0,          0, "0x"   , ' ',                  0,         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutChar, PutStr    , PutInteger );
TEST_CONVERTUNSIGNEDINTEGER( 15,                        0,               0,         0,         0,         0,       0,          0, "0X"   , ' ',                  0,         7, PopUnsignedInteger, SetAlt, SetInteger, SetZeroVsPrecision, PutChar, PutStr    , PutInteger );
/*-------------------------+---+-------------------------+----------------+----------+----------+----------+--------+-----------+--------+----+-------------------+----------+-------------------+-------+-----------+-------------------+--------+-----------+------------*/

static void test_ConvertUnsignedInteger( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "ConvertUnsignedInteger", NULL, NULL );

    CU_add_test( suite, "#_1", test_ConvertUnsignedInteger_1  );
    CU_add_test( suite, "#_2", test_ConvertUnsignedInteger_2  );
    CU_add_test( suite, "#_3", test_ConvertUnsignedInteger_3  );
    CU_add_test( suite, "#_4", test_ConvertUnsignedInteger_4  );
    CU_add_test( suite, "#_5", test_ConvertUnsignedInteger_5  );
    CU_add_test( suite, "#_6", test_ConvertUnsignedInteger_6  );
    CU_add_test( suite, "#_7", test_ConvertUnsignedInteger_7  );
    CU_add_test( suite, "#_8", test_ConvertUnsignedInteger_8  );
    CU_add_test( suite, "#_9", test_ConvertUnsignedInteger_9  );
    CU_add_test( suite, "#10", test_ConvertUnsignedInteger_10 );
    CU_add_test( suite, "#11", test_ConvertUnsignedInteger_11 );
    CU_add_test( suite, "#12", test_ConvertUnsignedInteger_12 );
    CU_add_test( suite, "#13", test_ConvertUnsignedInteger_13 );
    CU_add_test( suite, "#14", test_ConvertUnsignedInteger_14 );
    CU_add_test( suite, "#15", test_ConvertUnsignedInteger_15 );

    return;
}


/******************************************************************************/
/* GetConvertInfo                                                             */
/******************************************************************************/
#define TEST_GETCONVERTINFO( _NO,                                                   \
                             _IN_PINPUTINFO,                                        \
                             _IN_PCONVERTINFO,                                      \
                             _OUT_CALLCNT,                                          \
                             _OUT_CALLFUNC_0,                                       \
                             _OUT_CALLFUNC_1,                                       \
                             _OUT_CALLFUNC_2,                                       \
                             _OUT_CALLFUNC_3,                                       \
                             _OUT_CALLFUNC_4,                                       \
                             _OUT_PINPUTINFO,                                       \
                             _OUT_PCONVERTINFO )                                    \
    static void test_GetConvertInfo_##_NO( void )                                   \
    {                                                                               \
        InputInfo_t   *pInputInfo;                                                  \
        ConvertInfo_t *pConvertInfo;                                                \
                                                                                    \
        /* INPUT設定 */                                                             \
        pInputInfo   = ( InputInfo_t   * ) _IN_PINPUTINFO;                          \
        pConvertInfo = ( ConvertInfo_t * ) _IN_PCONVERTINFO;                        \
                                                                                    \
        /* OUTPUT初期化 */                                                          \
        UtilInit();                                                                 \
        param_GetFlag.pInputInfo        = ( InputInfo_t   * ) ~_OUT_PINPUTINFO;     \
        param_GetFlag.pConvertInfo      = ( ConvertInfo_t * ) ~_OUT_PCONVERTINFO;   \
        param_GetWidth.pInputInfo       = ( InputInfo_t   * ) ~_OUT_PINPUTINFO;     \
        param_GetWidth.pConvertInfo     = ( ConvertInfo_t * ) ~_OUT_PCONVERTINFO;   \
        param_GetPrecision.pInputInfo   = ( InputInfo_t   * ) ~_OUT_PINPUTINFO;     \
        param_GetPrecision.pConvertInfo = ( ConvertInfo_t * ) ~_OUT_PCONVERTINFO;   \
        param_GetLength.pInputInfo      = ( InputInfo_t   * ) ~_OUT_PINPUTINFO;     \
        param_GetLength.pConvertInfo    = ( ConvertInfo_t * ) ~_OUT_PCONVERTINFO;   \
        param_GetSpecifier.pInputInfo   = ( InputInfo_t   * ) ~_OUT_PINPUTINFO;     \
        param_GetSpecifier.pConvertInfo = ( ConvertInfo_t * ) ~_OUT_PCONVERTINFO;   \
                                                                                    \
        GetConvertInfo( pInputInfo, pConvertInfo );                                 \
                                                                                    \
        /* OUTPUT判定 */                                                            \
        CU_ASSERT_EQUAL(     UtilGetCallCount(),              _OUT_CALLCNT      );  \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 0 ),            _OUT_CALLFUNC_0   );  \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 1 ),            _OUT_CALLFUNC_1   );  \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 2 ),            _OUT_CALLFUNC_2   );  \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 3 ),            _OUT_CALLFUNC_3   );  \
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 4 ),            _OUT_CALLFUNC_4   );  \
        CU_ASSERT_PTR_EQUAL( param_GetFlag.pInputInfo,        _OUT_PINPUTINFO   );  \
        CU_ASSERT_PTR_EQUAL( param_GetFlag.pConvertInfo,      _OUT_PCONVERTINFO );  \
        CU_ASSERT_PTR_EQUAL( param_GetWidth.pInputInfo,       _OUT_PINPUTINFO   );  \
        CU_ASSERT_PTR_EQUAL( param_GetWidth.pConvertInfo,     _OUT_PCONVERTINFO );  \
        CU_ASSERT_PTR_EQUAL( param_GetPrecision.pInputInfo,   _OUT_PINPUTINFO   );  \
        CU_ASSERT_PTR_EQUAL( param_GetPrecision.pConvertInfo, _OUT_PCONVERTINFO );  \
        CU_ASSERT_PTR_EQUAL( param_GetLength.pInputInfo,      _OUT_PINPUTINFO   );  \
        CU_ASSERT_PTR_EQUAL( param_GetLength.pConvertInfo,    _OUT_PCONVERTINFO );  \
        CU_ASSERT_PTR_EQUAL( param_GetSpecifier.pInputInfo,   _OUT_PINPUTINFO   );  \
        CU_ASSERT_PTR_EQUAL( param_GetSpecifier.pConvertInfo, _OUT_PCONVERTINFO );  \
                                                                                    \
        return;                                                                     \
    }

/*-----------------+---+---------------------------+-----------------------------------------------------------------------------------------------*/
/*                 | # | INPUT                     | OUTPUT                                                                                        */
/*                 |   +------------+--------------+---------+---------------------------------------------------------+------------+--------------*/
/*                 |   | pInputInfo | pConvertInfo | callcnt | callfunc                                                | pInputInfo | pConvertInfo */
/*                 |   |            |              |         +--------+---------+-------------+----------+-------------+            |              */
/*                 |   |            |              |         | ( 0 )  | ( 1 )   | ( 2 )       | ( 3 )    | ( 4 )       |            |              */
/*-----------------+---+------------+--------------+---------+--------+---------+-------------+----------+-------------+------------+--------------*/
TEST_GETCONVERTINFO(  1, 0x00000000 , 0xFFFFFFFF   ,        5, GetFlag, GetWidth, GetPrecision, GetLength, GetSpecifier, 0x00000000 , 0xFFFFFFFF   );
TEST_GETCONVERTINFO(  2, 0x5A5A5A5A , 0xA5A5A5A5   ,        5, GetFlag, GetWidth, GetPrecision, GetLength, GetSpecifier, 0x5A5A5A5A , 0xA5A5A5A5   );
TEST_GETCONVERTINFO(  3, 0xFFFFFFFF , 0x00000000   ,        5, GetFlag, GetWidth, GetPrecision, GetLength, GetSpecifier, 0xFFFFFFFF , 0x00000000   );
/*-----------------+---+------------+--------------+---------+--------+---------+-------------+----------+-------------+------------+--------------*/

static void test_GetConvertInfo( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "GetConvertInfo", NULL, NULL );

    CU_add_test( suite, "#_1", test_GetConvertInfo_1 );
    CU_add_test( suite, "#_2", test_GetConvertInfo_2 );
    CU_add_test( suite, "#_3", test_GetConvertInfo_3 );

    return;
}


/******************************************************************************/
/* GetFlag                                                                    */
/******************************************************************************/
#define TEST_GETFLAG( _NO,                                  \
                      _IN_PINPUT,                           \
                      _IN_READIDX,                          \
                      _OUT_READIDX,                         \
                      _OUT_FLAG    )                        \
    static void test_GetFlag_##_NO( void )                  \
    {                                                       \
        InputInfo_t   inputInfo;                            \
        ConvertInfo_t convertInfo;                          \
                                                            \
        /* INPUT設定 */                                     \
        inputInfo.pInput  = _IN_PINPUT;                     \
        inputInfo.readIdx = _IN_READIDX;                    \
                                                            \
        /* OUTPUT初期化 */                                  \
        convertInfo.flag = ~_OUT_FLAG;                      \
                                                            \
        GetFlag( &inputInfo, &convertInfo );                \
                                                            \
        /* OUTPUT判定 */                                    \
        CU_ASSERT_EQUAL( inputInfo.readIdx, _OUT_READIDX ); \
        CU_ASSERT_EQUAL( convertInfo.flag,  _OUT_FLAG    ); \
        return;                                             \
    }

/*----------+---+---------------------+-----------------------------------------------*/
/*          | # | INPUT               | OUTPUT                                        */
/*          |   +---------------------+------------+----------------------------------*/
/*          |   | pInputInfo          | pInputInfo | pConvertInfo                     */
/*          |   +-----------+---------+------------+----------------------------------*/
/*          |   | pInput    | readIdx | readIdx    | flag                             */
/*----------+---+-----------+---------+------------+----------------------------------*/
TEST_GETFLAG(  1, "#"       ,        0,           1, FLAG_ALT                         );
TEST_GETFLAG(  2, "0"       ,        0,           1, FLAG_ZERO                        );
TEST_GETFLAG(  3, "-"       ,        0,           1, FLAG_LEFT                        );
TEST_GETFLAG(  4, " "       ,        0,           1, FLAG_SPACE                       );
TEST_GETFLAG(  5, "+"       ,        0,           1, FLAG_SIGN                        );
TEST_GETFLAG(  6, "'"       ,        0,           1, 0                                );
TEST_GETFLAG(  7, "I"       ,        0,           1, 0                                );
/*----------+---+-----------+---------+------------+----------------------------------*/
TEST_GETFLAG(  8, "0-"      ,        0,           2, FLAG_LEFT                        );
TEST_GETFLAG(  9, "-0"      ,        0,           2, FLAG_LEFT                        );
/*----------+---+-----------+---------+------------+----------------------------------*/
TEST_GETFLAG( 10, " +"      ,        0,           2, FLAG_SIGN                        );
TEST_GETFLAG( 11, "+ "      ,        0,           2, FLAG_SIGN                        );
/*----------+---+-----------+---------+------------+----------------------------------*/
TEST_GETFLAG( 12, "#0- +'I" ,        0,           7, FLAG_ALT | FLAG_LEFT | FLAG_SIGN );
TEST_GETFLAG( 13, "I'+ -0#" ,        0,           7, FLAG_ALT | FLAG_LEFT | FLAG_SIGN );
/*----------+---+-----------+---------+------------+----------------------------------*/
TEST_GETFLAG( 14, "##"      ,        0,           2, FLAG_ALT                         );
TEST_GETFLAG( 15, "00"      ,        0,           2, FLAG_ZERO                        );
TEST_GETFLAG( 16, "--"      ,        0,           2, FLAG_LEFT                        );
TEST_GETFLAG( 17, "  "      ,        0,           2, FLAG_SPACE                       );
TEST_GETFLAG( 18, "++"      ,        0,           2, FLAG_SIGN                        );
TEST_GETFLAG( 19, "''"      ,        0,           2, 0                                );
TEST_GETFLAG( 20, "II"      ,        0,           2, 0                                );
/*----------+---+-----------+---------+------------+----------------------------------*/
TEST_GETFLAG( 21, "I'+ -0#" ,        6,           7, FLAG_ALT                         );
TEST_GETFLAG( 22, "#I'+ -0" ,        6,           7, FLAG_ZERO                        );
TEST_GETFLAG( 23, "0#I'+ -" ,        6,           7, FLAG_LEFT                        );
TEST_GETFLAG( 24, "-0#I'+ " ,        6,           7, FLAG_SPACE                       );
TEST_GETFLAG( 25, " -0#I'+" ,        6,           7, FLAG_SIGN                        );
TEST_GETFLAG( 26, "+ -0#I'" ,        6,           7, 0                                );
TEST_GETFLAG( 27, "'+ -0#I" ,        6,           7, 0                                );
/*----------+---+-----------+---------+------------+----------------------------------*/

static void test_GetFlag( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "GetFlag", NULL, NULL );

    CU_add_test( suite, "#_1", test_GetFlag_1  );
    CU_add_test( suite, "#_2", test_GetFlag_2  );
    CU_add_test( suite, "#_3", test_GetFlag_3  );
    CU_add_test( suite, "#_4", test_GetFlag_4  );
    CU_add_test( suite, "#_5", test_GetFlag_5  );
    CU_add_test( suite, "#_6", test_GetFlag_6  );
    CU_add_test( suite, "#_7", test_GetFlag_7  );
    CU_add_test( suite, "#_8", test_GetFlag_8  );
    CU_add_test( suite, "#_9", test_GetFlag_9  );
    CU_add_test( suite, "#10", test_GetFlag_10 );
    CU_add_test( suite, "#11", test_GetFlag_11 );
    CU_add_test( suite, "#12", test_GetFlag_12 );
    CU_add_test( suite, "#13", test_GetFlag_13 );
    CU_add_test( suite, "#14", test_GetFlag_14 );
    CU_add_test( suite, "#15", test_GetFlag_15 );
    CU_add_test( suite, "#16", test_GetFlag_16 );
    CU_add_test( suite, "#17", test_GetFlag_17 );
    CU_add_test( suite, "#18", test_GetFlag_18 );
    CU_add_test( suite, "#19", test_GetFlag_19 );
    CU_add_test( suite, "#20", test_GetFlag_20 );
    CU_add_test( suite, "#21", test_GetFlag_21 );
    CU_add_test( suite, "#22", test_GetFlag_22 );
    CU_add_test( suite, "#23", test_GetFlag_23 );
    CU_add_test( suite, "#24", test_GetFlag_24 );
    CU_add_test( suite, "#25", test_GetFlag_25 );
    CU_add_test( suite, "#26", test_GetFlag_26 );
    CU_add_test( suite, "#27", test_GetFlag_27 );

    return;
}


/******************************************************************************/
/* GetLength                                                                  */
/******************************************************************************/
#define TEST_GETLENGTH( _NO,                                \
                        _IN_PINPUT,                         \
                        _IN_READIDX,                        \
                        _OUT_READIDX,                       \
                        _OUT_LENGTH   )                     \
    static void test_GetLength_##_NO( void )                \
    {                                                       \
        InputInfo_t   inputInfo;                            \
        ConvertInfo_t convertInfo;                          \
                                                            \
        /* INPUT設定 */                                     \
        inputInfo.pInput  = _IN_PINPUT;                     \
        inputInfo.readIdx = _IN_READIDX;                    \
                                                            \
        /* OUTPUT初期化 */                                  \
        convertInfo.length = ~_OUT_LENGTH;                  \
                                                            \
        GetLength( &inputInfo, &convertInfo );              \
                                                            \
        /* OUTPUT判定 */                                    \
        CU_ASSERT_EQUAL( inputInfo.readIdx,  _OUT_READIDX );\
        CU_ASSERT_EQUAL( convertInfo.length, _OUT_LENGTH  );\
                                                            \
        return;                                             \
    }

/*------------+---+---------------------+---------------------------------*/
/*            | # | INPUT               | OUTPUT                          */
/*            |   +---------------------+------------+--------------------*/
/*            |   | pInputInfo          | pInputInfo | pConvertInfo       */
/*            |   +-----------+---------+------------+--------------------*/
/*            |   | pInput    | readIdx | readIdx    | length             */
/*------------+---+-----------+---------+------------+--------------------*/
TEST_GETLENGTH(  1, "hh"      ,        0,           2, LENGTH_CHAR        );
TEST_GETLENGTH(  2, "h"       ,        0,           1, LENGTH_SHORT       );
TEST_GETLENGTH(  3, "ll"      ,        0,           2, LENGTH_LONG_LONG   );
TEST_GETLENGTH(  4, "l"       ,        0,           1, LENGTH_LONG        );
TEST_GETLENGTH(  5, "L"       ,        0,           1, LENGTH_LONG_DOUBLE );
TEST_GETLENGTH(  6, "j"       ,        0,           1, LENGTH_INTMAX      );
TEST_GETLENGTH(  7, "z"       ,        0,           1, LENGTH_SIZE        );
TEST_GETLENGTH(  8, "Z"       ,        0,           1, LENGTH_PTRDIFF     );
TEST_GETLENGTH(  9, ""        ,        0,           0, LENGTH_DEFAULT     );
/*------------+---+-----------+---------+------------+--------------------*/

static void test_GetLength( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "GetLength", NULL, NULL );

    CU_add_test( suite, "#_1",  test_GetLength_1  );
    CU_add_test( suite, "#_2",  test_GetLength_2  );
    CU_add_test( suite, "#_3",  test_GetLength_3  );
    CU_add_test( suite, "#_4",  test_GetLength_4  );
    CU_add_test( suite, "#_5",  test_GetLength_5  );
    CU_add_test( suite, "#_6",  test_GetLength_6  );
    CU_add_test( suite, "#_7",  test_GetLength_7  );
    CU_add_test( suite, "#_8",  test_GetLength_8  );
    CU_add_test( suite, "#_9",  test_GetLength_9  );

    return;
}


/******************************************************************************/
/* GetPrecision                                                               */
/******************************************************************************/
static void test_GetPrecision_main( InputInfo_t   *pInputInfo,
                                    ConvertInfo_t *pConvertInfo,
                                    ...                          )
{
    /* INPUT初期化 */
    va_start( pInputInfo->args, pConvertInfo );

    GetPrecision( pInputInfo, pConvertInfo );

    va_end( pInputInfo->args );

    return;
}

#define TEST_GETPRECISION( _NO,                                     \
                           _IN_PINPUT,                              \
                           _IN_READIDX,                             \
                           _IN_ARG,                                 \
                           _OUT_READIDX,                            \
                           _OUT_PRECISION )                         \
    static void test_GetPrecision_##_NO( void )                     \
    {                                                               \
        InputInfo_t   inputInfo;                                    \
        ConvertInfo_t convertInfo;                                  \
                                                                    \
        /* INPUT初期化 */                                           \
        inputInfo.pInput  = _IN_PINPUT;                             \
        inputInfo.readIdx = _IN_READIDX;                            \
                                                                    \
        /* OUTPUT初期化 */                                          \
        convertInfo.precision = ~( _OUT_PRECISION );                \
                                                                    \
        test_GetPrecision_main( &inputInfo, &convertInfo, _IN_ARG );\
                                                                    \
        /* OUTPUT判定 */                                            \
        CU_ASSERT_EQUAL( inputInfo.readIdx,     _OUT_READIDX   );   \
        CU_ASSERT_EQUAL( convertInfo.precision, _OUT_PRECISION );   \
                                                                    \
        return;                                                     \
    }

/*---------------+---+-----------------------------------------------+---------------------------*/
/*               | # | INPUT                                         | OUTPUT                    */
/*               |   +-----------------------------------------------+------------+--------------*/
/*               |   | pInputInfo                                    | pInputInfo | pConvertInfo */
/*               |   +------------------+---------+------------------+------------+--------------*/
/*               |   | pInput           | readIdx | arg              | readIdx    | precision    */
/*---------------+---+------------------+---------+------------------+------------+--------------*/
TEST_GETPRECISION(  1, /* arg */ ".*"   ,        0, /* min */ INT_MIN,           2, INT_MIN      );
TEST_GETPRECISION(  2, /* arg */ ".*"   ,        0, /* mid */       0,           2,            0 );
TEST_GETPRECISION(  3, /* arg */ ".*"   ,        0, /* max */ INT_MAX,           2, INT_MAX      );
/*---------------+---+------------------+---------+------------------+------------+--------------*/
TEST_GETPRECISION(  4, /* arg */ "a.*"  ,        1, /* min */ INT_MIN,           3, INT_MIN      );
TEST_GETPRECISION(  5, /* arg */ "a.*"  ,        1, /* mid */       0,           3,            0 );
TEST_GETPRECISION(  6, /* arg */ "a.*"  ,        1, /* max */ INT_MAX,           3, INT_MAX      );
/*---------------+---+------------------+---------+------------------+------------+--------------*/
TEST_GETPRECISION(  7, /* num */ ".0"   ,        0, INT_MAX          ,           2,            0 );
TEST_GETPRECISION(  8, /* num */ ".1"   ,        0, INT_MAX          ,           2,            1 );
TEST_GETPRECISION(  9, /* num */ ".2"   ,        0, INT_MAX          ,           2,            2 );
TEST_GETPRECISION( 10, /* num */ ".3"   ,        0, INT_MAX          ,           2,            3 );
TEST_GETPRECISION( 11, /* num */ ".4"   ,        0, INT_MAX          ,           2,            4 );
TEST_GETPRECISION( 12, /* num */ ".5"   ,        0, INT_MAX          ,           2,            5 );
TEST_GETPRECISION( 13, /* num */ ".6"   ,        0, INT_MAX          ,           2,            6 );
TEST_GETPRECISION( 14, /* num */ ".7"   ,        0, INT_MAX          ,           2,            7 );
TEST_GETPRECISION( 15, /* num */ ".8"   ,        0, INT_MAX          ,           2,            8 );
TEST_GETPRECISION( 16, /* num */ ".9"   ,        0, INT_MAX          ,           2,            9 );
/*---------------+---+------------------+---------+------------------+------------+--------------*/
TEST_GETPRECISION( 17, /* num */ ".00"  ,        0, INT_MAX          ,           3,            0 );
TEST_GETPRECISION( 18, /* num */ ".10"  ,        0, INT_MAX          ,           3,           10 );
TEST_GETPRECISION( 19, /* num */ ".20"  ,        0, INT_MAX          ,           3,           20 );
TEST_GETPRECISION( 20, /* num */ ".30"  ,        0, INT_MAX          ,           3,           30 );
TEST_GETPRECISION( 21, /* num */ ".40"  ,        0, INT_MAX          ,           3,           40 );
TEST_GETPRECISION( 22, /* num */ ".50"  ,        0, INT_MAX          ,           3,           50 );
TEST_GETPRECISION( 23, /* num */ ".60"  ,        0, INT_MAX          ,           3,           60 );
TEST_GETPRECISION( 24, /* num */ ".70"  ,        0, INT_MAX          ,           3,           70 );
TEST_GETPRECISION( 25, /* num */ ".80"  ,        0, INT_MAX          ,           3,           80 );
TEST_GETPRECISION( 26, /* num */ ".90"  ,        0, INT_MAX          ,           3,           90 );
/*---------------+---+------------------+---------+------------------+------------+--------------*/
TEST_GETPRECISION( 27, /* num */ ".11"  ,        0, INT_MAX          ,           3,           11 );
TEST_GETPRECISION( 28, /* num */ ".22"  ,        0, INT_MAX          ,           3,           22 );
TEST_GETPRECISION( 29, /* num */ ".33"  ,        0, INT_MAX          ,           3,           33 );
TEST_GETPRECISION( 30, /* num */ ".44"  ,        0, INT_MAX          ,           3,           44 );
TEST_GETPRECISION( 31, /* num */ ".55"  ,        0, INT_MAX          ,           3,           55 );
TEST_GETPRECISION( 32, /* num */ ".66"  ,        0, INT_MAX          ,           3,           66 );
TEST_GETPRECISION( 33, /* num */ ".77"  ,        0, INT_MAX          ,           3,           77 );
TEST_GETPRECISION( 34, /* num */ ".88"  ,        0, INT_MAX          ,           3,           88 );
TEST_GETPRECISION( 35, /* num */ ".99"  ,        0, INT_MAX          ,           3,           99 );
/*---------------+---+------------------+---------+------------------+------------+--------------*/
TEST_GETPRECISION( 36, /* other */ "d"  ,        0, INT_MAX          ,           0,           -1 );
TEST_GETPRECISION( 37, /* other */ "dd" ,        1, INT_MAX          ,           1,           -1 );
/*---------------+---+------------------+---------+------------------+------------+--------------*/
TEST_GETPRECISION( 38, /* other */ ".d" ,        0, INT_MAX          ,           1,           -1 );
TEST_GETPRECISION( 39, /* other */ "d.d",        1, INT_MAX          ,           2,           -1 );
/*---------------+---+------------------+---------+------------------+------------+--------------*/

static void test_GetPrecision( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "GetPrecision", NULL, NULL );

    CU_add_test( suite, "#_1", test_GetPrecision_1  );
    CU_add_test( suite, "#_2", test_GetPrecision_2  );
    CU_add_test( suite, "#_3", test_GetPrecision_3  );
    CU_add_test( suite, "#_4", test_GetPrecision_4  );
    CU_add_test( suite, "#_5", test_GetPrecision_5  );
    CU_add_test( suite, "#_6", test_GetPrecision_6  );
    CU_add_test( suite, "#_7", test_GetPrecision_7  );
    CU_add_test( suite, "#_8", test_GetPrecision_8  );
    CU_add_test( suite, "#_9", test_GetPrecision_9  );
    CU_add_test( suite, "#10", test_GetPrecision_10 );
    CU_add_test( suite, "#11", test_GetPrecision_11 );
    CU_add_test( suite, "#12", test_GetPrecision_12 );
    CU_add_test( suite, "#13", test_GetPrecision_13 );
    CU_add_test( suite, "#14", test_GetPrecision_14 );
    CU_add_test( suite, "#15", test_GetPrecision_15 );
    CU_add_test( suite, "#16", test_GetPrecision_16 );
    CU_add_test( suite, "#17", test_GetPrecision_17 );
    CU_add_test( suite, "#18", test_GetPrecision_18 );
    CU_add_test( suite, "#19", test_GetPrecision_19 );
    CU_add_test( suite, "#20", test_GetPrecision_20 );
    CU_add_test( suite, "#21", test_GetPrecision_21 );
    CU_add_test( suite, "#22", test_GetPrecision_22 );
    CU_add_test( suite, "#23", test_GetPrecision_23 );
    CU_add_test( suite, "#24", test_GetPrecision_24 );
    CU_add_test( suite, "#25", test_GetPrecision_25 );
    CU_add_test( suite, "#26", test_GetPrecision_26 );
    CU_add_test( suite, "#27", test_GetPrecision_27 );
    CU_add_test( suite, "#28", test_GetPrecision_28 );
    CU_add_test( suite, "#29", test_GetPrecision_29 );
    CU_add_test( suite, "#30", test_GetPrecision_30 );
    CU_add_test( suite, "#31", test_GetPrecision_31 );
    CU_add_test( suite, "#32", test_GetPrecision_32 );
    CU_add_test( suite, "#33", test_GetPrecision_33 );
    CU_add_test( suite, "#34", test_GetPrecision_34 );
    CU_add_test( suite, "#35", test_GetPrecision_35 );
    CU_add_test( suite, "#36", test_GetPrecision_36 );
    CU_add_test( suite, "#37", test_GetPrecision_37 );
    CU_add_test( suite, "#38", test_GetPrecision_38 );
    CU_add_test( suite, "#39", test_GetPrecision_39 );

    return;
}


/******************************************************************************/
/* GetSpecifier                                                               */
/******************************************************************************/
#define TEST_GETSPECIFIER( _NO,                                         \
                           _IN_PINPUT,                                  \
                           _IN_READIDX,                                 \
                           _IN_BASE,                                    \
                           _IN_UPPERLOWER,                              \
                           _IN_FLAG,                                    \
                           _OUT_READIDX,                                \
                           _OUT_BASE,                                   \
                           _OUT_UPPERLOWER,                             \
                           _OUT_FLAG,                                   \
                           _OUT_PCONVERTER  )                           \
    static void test_GetSpecifier_##_NO( void )                         \
    {                                                                   \
        InputInfo_t   inputInfo;                                        \
        ConvertInfo_t convertInfo;                                      \
                                                                        \
        /* INPUT設定 */                                                 \
        inputInfo.pInput  = _IN_PINPUT;                                 \
        inputInfo.readIdx = _IN_READIDX;                                \
                                                                        \
        /* OUTPUT初期化 */                                              \
        convertInfo.base       = _IN_BASE;                              \
        convertInfo.upperLower = _IN_UPPERLOWER;                        \
        convertInfo.flag       = _IN_FLAG;                              \
        convertInfo.pConverter = ( void * ) 0xFFFFFFFF;                 \
                                                                        \
        GetSpecifier( &inputInfo, &convertInfo );                       \
                                                                        \
        /* OUTPUT判定 */                                                \
        CU_ASSERT_EQUAL(     inputInfo.readIdx,      _OUT_READIDX    ); \
        CU_ASSERT_EQUAL(     convertInfo.base,       _OUT_BASE       ); \
        CU_ASSERT_EQUAL(     convertInfo.upperLower, _OUT_UPPERLOWER ); \
        CU_ASSERT_EQUAL(     convertInfo.flag,       _OUT_FLAG       ); \
        CU_ASSERT_PTR_EQUAL( convertInfo.pConverter, _OUT_PCONVERTER ); \
                                                                        \
        return;                                                         \
    }

/*---------------+---+------------------------------------------------+-------------------------------------------------------------------*/
/*               | # | INPUT                                          | OUTPUT                                                            */
/*               |   +------------------------------------------------+------------+------------------------------------------------------*/
/*               |   | pInputInfo                                     | pInputInfo | pConvertInfo                                         */
/*               |   +--------+---------+------+------------+---------+------------+------+------------+---------+------------------------*/
/*               |   | pInput | readIdx | base | upperLower | flag    | readIdx    | base | upperLower | flag    | pConverter             */
/*---------------+---+--------+---------+------+------------+---------+------------+------+------------+---------+------------------------*/
TEST_GETSPECIFIER(  1, "d"    ,        0,     0, UPPER_CASE ,        0,           1,    10, LOWER_CASE ,        0, ConvertSignedInteger   );
TEST_GETSPECIFIER(  2, "i"    ,        0,     0, UPPER_CASE ,        0,           1,    10, LOWER_CASE ,        0, ConvertSignedInteger   );
TEST_GETSPECIFIER(  3, "o"    ,        0,     0, UPPER_CASE ,        0,           1,     8, LOWER_CASE ,        0, ConvertUnsignedInteger );
TEST_GETSPECIFIER(  4, "u"    ,        0,     0, UPPER_CASE ,        0,           1,    10, LOWER_CASE ,        0, ConvertUnsignedInteger );
TEST_GETSPECIFIER(  5, "x"    ,        0,     0, UPPER_CASE ,        0,           1,    16, LOWER_CASE ,        0, ConvertUnsignedInteger );
TEST_GETSPECIFIER(  6, "X"    ,        0,     0, LOWER_CASE ,        0,           1,    16, UPPER_CASE ,        0, ConvertUnsignedInteger );
TEST_GETSPECIFIER(  7, "c"    ,        0,     0,           0,        0,           1,     0,           0,        0, ConvertChar            );
TEST_GETSPECIFIER(  8, "s"    ,        0,     0,           0,        0,           1,     0,           0,        0, ConvertString          );
/*---------------+---+--------+---------+------+------------+---------+------------+------+------------+---------+------------------------*/
TEST_GETSPECIFIER(  9, "p"    ,        0,     0, UPPER_CASE ,        0,           1,    16, LOWER_CASE , FLAG_ALT, ConvertUnsignedInteger );
TEST_GETSPECIFIER( 10, "p"    ,        0,     0, UPPER_CASE , FLAG_ALT,           1,    16, LOWER_CASE , FLAG_ALT, ConvertUnsignedInteger );
/*---------------+---+--------+---------+------+------------+---------+------------+------+------------+---------+------------------------*/
TEST_GETSPECIFIER( 11, "%"    ,        0,     0,           0,        0,           1,     0,           0,        0, ConvertPercent         );
TEST_GETSPECIFIER( 12, ""     ,        0,     0,           0,        0,           0,     0,           0,        0, NULL                   );
/*---------------+---+--------+---------+------+------------+---------+------------+------+------------+---------+------------------------*/

static void test_GetSpecifier( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "GetSpecifier", NULL, NULL );

    CU_add_test( suite, "#_1", test_GetSpecifier_1  );
    CU_add_test( suite, "#_2", test_GetSpecifier_2  );
    CU_add_test( suite, "#_3", test_GetSpecifier_3  );
    CU_add_test( suite, "#_4", test_GetSpecifier_4  );
    CU_add_test( suite, "#_5", test_GetSpecifier_5  );
    CU_add_test( suite, "#_6", test_GetSpecifier_6  );
    CU_add_test( suite, "#_7", test_GetSpecifier_7  );
    CU_add_test( suite, "#_8", test_GetSpecifier_8  );
    CU_add_test( suite, "#_9", test_GetSpecifier_9  );
    CU_add_test( suite, "#10", test_GetSpecifier_10 );
    CU_add_test( suite, "#11", test_GetSpecifier_11 );
    CU_add_test( suite, "#12", test_GetSpecifier_12 );

    return;
}


/******************************************************************************/
/* GetWidth                                                                   */
/******************************************************************************/
static void test_GetWidth_main( InputInfo_t   *pInputInfo,
                                ConvertInfo_t *pConvertInfo,
                                ...                          )
{
    /* INPUT初期化 */
    va_start( pInputInfo->args, pConvertInfo );

    GetWidth( pInputInfo, pConvertInfo );

    va_end( pInputInfo->args );

    return;
}

#define TEST_GETWIDTH( _NO,                                         \
                       _IN_PINPUT,                                  \
                       _IN_READIDX,                                 \
                       _IN_ARG,                                     \
                       _OUT_READIDX,                                \
                       _OUT_WIDTH    )                              \
    static void test_GetWidth_##_NO( void )                         \
    {                                                               \
        InputInfo_t   inputInfo;                                    \
        ConvertInfo_t convertInfo;                                  \
                                                                    \
        /* INPUT初期化 */                                           \
        inputInfo.pInput  = _IN_PINPUT;                             \
        inputInfo.readIdx = _IN_READIDX;                            \
                                                                    \
        /* OUTPUT初期化 */                                          \
        convertInfo.width = ~( _OUT_WIDTH );                        \
                                                                    \
        test_GetWidth_main( &inputInfo, &convertInfo, _IN_ARG );    \
                                                                    \
        /* OUTPUT判定 */                                            \
        CU_ASSERT_EQUAL( inputInfo.readIdx, _OUT_READIDX );         \
        CU_ASSERT_EQUAL( convertInfo.width, _OUT_WIDTH   );         \
                                                                    \
        return;                                                     \
    }

/*-----------+---+-----------------------------------------------+---------------------------*/
/*           | # | INPUT                                         | OUTPUT                    */
/*           |   +-----------------------------------------------+------------+--------------*/
/*           |   | pInputInfo                                    | pInputInfo | pConvertInfo */
/*           |   +------------------+---------+------------------+------------+--------------*/
/*           |   | pInput           | readIdx | arg              | readIdx    | width        */
/*-----------+---+------------------+---------+------------------+------------+--------------*/
TEST_GETWIDTH(  1, /* arg */ "*"    ,        0, /* min */ INT_MIN,           1, INT_MIN      );
TEST_GETWIDTH(  2, /* arg */ "*"    ,        0, /* mid */       0,           1,            0 );
TEST_GETWIDTH(  3, /* arg */ "*"    ,        0, /* max */ INT_MAX,           1, INT_MAX      );
/*-----------+---+------------------+---------+------------------+------------+--------------*/
TEST_GETWIDTH(  4, /* arg */ "a*"   ,        1, /* min */ INT_MIN,           2, INT_MIN      );
TEST_GETWIDTH(  5, /* arg */ "a*"   ,        1, /* mid */       0,           2,            0 );
TEST_GETWIDTH(  6, /* arg */ "a*"   ,        1, /* max */ INT_MAX,           2, INT_MAX      );
/*-----------+---+------------------+---------+------------------+------------+--------------*/
TEST_GETWIDTH(  7, /* num */ "0"    ,        0, INT_MAX          ,           1,            0 );
TEST_GETWIDTH(  8, /* num */ "1"    ,        0, INT_MAX          ,           1,            1 );
TEST_GETWIDTH(  9, /* num */ "2"    ,        0, INT_MAX          ,           1,            2 );
TEST_GETWIDTH( 10, /* num */ "3"    ,        0, INT_MAX          ,           1,            3 );
TEST_GETWIDTH( 11, /* num */ "4"    ,        0, INT_MAX          ,           1,            4 );
TEST_GETWIDTH( 12, /* num */ "5"    ,        0, INT_MAX          ,           1,            5 );
TEST_GETWIDTH( 13, /* num */ "6"    ,        0, INT_MAX          ,           1,            6 );
TEST_GETWIDTH( 14, /* num */ "7"    ,        0, INT_MAX          ,           1,            7 );
TEST_GETWIDTH( 15, /* num */ "8"    ,        0, INT_MAX          ,           1,            8 );
TEST_GETWIDTH( 16, /* num */ "9"    ,        0, INT_MAX          ,           1,            9 );
/*-----------+---+------------------+---------+------------------+------------+--------------*/
TEST_GETWIDTH( 17, /* num */ "00"   ,        0, INT_MAX          ,           2,            0 );
TEST_GETWIDTH( 18, /* num */ "10"   ,        0, INT_MAX          ,           2,           10 );
TEST_GETWIDTH( 19, /* num */ "20"   ,        0, INT_MAX          ,           2,           20 );
TEST_GETWIDTH( 20, /* num */ "30"   ,        0, INT_MAX          ,           2,           30 );
TEST_GETWIDTH( 21, /* num */ "40"   ,        0, INT_MAX          ,           2,           40 );
TEST_GETWIDTH( 22, /* num */ "50"   ,        0, INT_MAX          ,           2,           50 );
TEST_GETWIDTH( 23, /* num */ "60"   ,        0, INT_MAX          ,           2,           60 );
TEST_GETWIDTH( 24, /* num */ "70"   ,        0, INT_MAX          ,           2,           70 );
TEST_GETWIDTH( 25, /* num */ "80"   ,        0, INT_MAX          ,           2,           80 );
TEST_GETWIDTH( 26, /* num */ "90"   ,        0, INT_MAX          ,           2,           90 );
/*-----------+---+------------------+---------+------------------+------------+--------------*/
TEST_GETWIDTH( 27, /* num */ "11"   ,        0, INT_MAX          ,           2,           11 );
TEST_GETWIDTH( 28, /* num */ "22"   ,        0, INT_MAX          ,           2,           22 );
TEST_GETWIDTH( 29, /* num */ "33"   ,        0, INT_MAX          ,           2,           33 );
TEST_GETWIDTH( 30, /* num */ "44"   ,        0, INT_MAX          ,           2,           44 );
TEST_GETWIDTH( 31, /* num */ "55"   ,        0, INT_MAX          ,           2,           55 );
TEST_GETWIDTH( 32, /* num */ "66"   ,        0, INT_MAX          ,           2,           66 );
TEST_GETWIDTH( 33, /* num */ "77"   ,        0, INT_MAX          ,           2,           77 );
TEST_GETWIDTH( 34, /* num */ "88"   ,        0, INT_MAX          ,           2,           88 );
TEST_GETWIDTH( 35, /* num */ "99"   ,        0, INT_MAX          ,           2,           99 );
/*-----------+---+------------------+---------+------------------+------------+--------------*/
TEST_GETWIDTH( 36, /* other */ "d"  ,        0, INT_MAX          ,           0,           -1 );
TEST_GETWIDTH( 37, /* other */ "dd" ,        1, INT_MAX          ,           1,           -1 );
/*-----------+---+------------------+---------+------------------+------------+--------------*/

static void test_GetWidth( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "GetWidth", NULL, NULL );

    CU_add_test( suite, "#_1", test_GetWidth_1  );
    CU_add_test( suite, "#_2", test_GetWidth_2  );
    CU_add_test( suite, "#_3", test_GetWidth_3  );
    CU_add_test( suite, "#_4", test_GetWidth_4  );
    CU_add_test( suite, "#_5", test_GetWidth_5  );
    CU_add_test( suite, "#_6", test_GetWidth_6  );
    CU_add_test( suite, "#_7", test_GetWidth_7  );
    CU_add_test( suite, "#_8", test_GetWidth_8  );
    CU_add_test( suite, "#_9", test_GetWidth_9  );
    CU_add_test( suite, "#10", test_GetWidth_10 );
    CU_add_test( suite, "#11", test_GetWidth_11 );
    CU_add_test( suite, "#12", test_GetWidth_12 );
    CU_add_test( suite, "#13", test_GetWidth_13 );
    CU_add_test( suite, "#14", test_GetWidth_14 );
    CU_add_test( suite, "#15", test_GetWidth_15 );
    CU_add_test( suite, "#16", test_GetWidth_16 );
    CU_add_test( suite, "#17", test_GetWidth_17 );
    CU_add_test( suite, "#18", test_GetWidth_18 );
    CU_add_test( suite, "#19", test_GetWidth_19 );
    CU_add_test( suite, "#20", test_GetWidth_20 );
    CU_add_test( suite, "#21", test_GetWidth_21 );
    CU_add_test( suite, "#22", test_GetWidth_22 );
    CU_add_test( suite, "#23", test_GetWidth_23 );
    CU_add_test( suite, "#24", test_GetWidth_24 );
    CU_add_test( suite, "#25", test_GetWidth_25 );
    CU_add_test( suite, "#26", test_GetWidth_26 );
    CU_add_test( suite, "#27", test_GetWidth_27 );
    CU_add_test( suite, "#28", test_GetWidth_28 );
    CU_add_test( suite, "#29", test_GetWidth_29 );
    CU_add_test( suite, "#30", test_GetWidth_30 );
    CU_add_test( suite, "#31", test_GetWidth_31 );
    CU_add_test( suite, "#32", test_GetWidth_32 );
    CU_add_test( suite, "#33", test_GetWidth_33 );
    CU_add_test( suite, "#34", test_GetWidth_34 );
    CU_add_test( suite, "#35", test_GetWidth_35 );
    CU_add_test( suite, "#36", test_GetWidth_36 );
    CU_add_test( suite, "#37", test_GetWidth_37 );

    return;
}


/******************************************************************************/
/* PopSigedInteger                                                            */
/******************************************************************************/
static long long test_PopSignedInteger_main( uint8_t length, ... )
{
    InputInfo_t   inputInfo;
    ConvertInfo_t convertInfo;
    long long     ret;

    va_start( inputInfo.args, length );

    convertInfo.length = length;

    ret = PopSignedInteger( &inputInfo, &convertInfo );

    va_end( inputInfo.args );

    return ret;
}

#define TEST_POPSIGNEDINTEGER( _NO,                                                 \
                               _IN_TYPE,                                            \
                               _IN_VALUE,                                           \
                               _IN_LENGTH,                                          \
                               _OUT_VALUE  )                                        \
    static void test_PopSignedInteger_##_NO( void )                                 \
    {                                                                               \
        long long ret;                                                              \
                                                                                    \
        ret = test_PopSignedInteger_main( _IN_LENGTH, ( _IN_TYPE ) ( _IN_VALUE ) ); \
                                                                                    \
        /* OUTPUT判定 */                                                            \
        CU_ASSERT_EQUAL( ret, ( long long ) ( _OUT_VALUE ) );                       \
                                                                                    \
        return;                                                                     \
    }

/*-------------------+---+----------------------------------------------------+--------------*/
/*                   | # | INPUT                                              | OUTPUT       */
/*                   |   +----------------------------------+-----------------+--------------*/
/*                   |   | argument                         | length          | ret          */
/*                   |   +----------+-----------------------+                 |              */
/*                   |   | type     | value                 |                 |              */
/*-------------------+---+----------+-----------------------+-----------------+--------------*/
TEST_POPSIGNEDINTEGER(  1, char     , /* min */ CHAR_MIN    , LENGTH_CHAR     , CHAR_MIN     );
TEST_POPSIGNEDINTEGER(  2, char     , /* mid */ 0           , LENGTH_CHAR     , 0            );
TEST_POPSIGNEDINTEGER(  3, char     , /* max */ CHAR_MAX    , LENGTH_CHAR     , CHAR_MAX     );
/*-------------------+---+----------+-----------------------+-----------------+--------------*/
TEST_POPSIGNEDINTEGER(  4, short    , /* min */ SHRT_MIN    , LENGTH_SHORT    , SHRT_MIN     );
TEST_POPSIGNEDINTEGER(  5, short    , /* mid */ 0           , LENGTH_SHORT    , 0            );
TEST_POPSIGNEDINTEGER(  6, short    , /* max */ SHRT_MAX    , LENGTH_SHORT    , SHRT_MAX     );
/*-------------------+---+----------+-----------------------+-----------------+--------------*/
TEST_POPSIGNEDINTEGER(  7, long     , /* min */ LONG_MIN    , LENGTH_LONG     , LONG_MIN     );
TEST_POPSIGNEDINTEGER(  8, long     , /* mid */ 0l          , LENGTH_LONG     , 0l           );
TEST_POPSIGNEDINTEGER(  9, long     , /* max */ LONG_MAX    , LENGTH_LONG     , LONG_MAX     );
/*-------------------+---+----------+-----------------------+-----------------+--------------*/
TEST_POPSIGNEDINTEGER( 10, long long, /* min */ LLONG_MIN   , LENGTH_LONG_LONG, LLONG_MIN    );
TEST_POPSIGNEDINTEGER( 11, long long, /* mid */ 0ll         , LENGTH_LONG_LONG, 0ll          );
TEST_POPSIGNEDINTEGER( 12, long long, /* max */ LLONG_MAX   , LENGTH_LONG_LONG, LLONG_MAX    );
/*-------------------+---+----------+-----------------------+-----------------+--------------*/
TEST_POPSIGNEDINTEGER( 13, intmax_t , /* min */ INTMAX_MIN  , LENGTH_INTMAX   , INTMAX_MIN   );
TEST_POPSIGNEDINTEGER( 14, intmax_t , /* mid */ 0           , LENGTH_INTMAX   , 0            );
TEST_POPSIGNEDINTEGER( 15, intmax_t , /* max */ INTMAX_MAX  , LENGTH_INTMAX   , INTMAX_MAX   );
/*-------------------+---+----------+-----------------------+-----------------+--------------*/
TEST_POPSIGNEDINTEGER( 16, size_t   , /* min */ 0           , LENGTH_SIZE     , 0            );
TEST_POPSIGNEDINTEGER( 17, size_t   , /* mid */ SIZE_MAX / 2, LENGTH_SIZE     , SIZE_MAX / 2 );
TEST_POPSIGNEDINTEGER( 18, size_t   , /* max */ SIZE_MAX    , LENGTH_SIZE     , SIZE_MAX     );
/*-------------------+---+----------+-----------------------+-----------------+--------------*/
TEST_POPSIGNEDINTEGER( 19, ptrdiff_t, /* min */ PTRDIFF_MIN , LENGTH_PTRDIFF  , PTRDIFF_MIN  );
TEST_POPSIGNEDINTEGER( 20, ptrdiff_t, /* mid */ 0           , LENGTH_PTRDIFF  , 0            );
TEST_POPSIGNEDINTEGER( 21, ptrdiff_t, /* max */ PTRDIFF_MAX , LENGTH_PTRDIFF  , PTRDIFF_MAX  );
/*-------------------+---+----------+-----------------------+-----------------+--------------*/
TEST_POPSIGNEDINTEGER( 22, int      , /* min */ INT_MIN     , LENGTH_DEFAULT  , INT_MIN      );
TEST_POPSIGNEDINTEGER( 23, int      , /* mid */ 0           , LENGTH_DEFAULT  , 0            );
TEST_POPSIGNEDINTEGER( 24, int      , /* max */ INT_MAX     , LENGTH_DEFAULT  , INT_MAX      );
/*-------------------+---+----------+-----------------------+-----------------+--------------*/

static void test_PopSignedInteger( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "PopSignedInteger", NULL, NULL );

    CU_add_test( suite, "#_1", test_PopSignedInteger_1  );
    CU_add_test( suite, "#_2", test_PopSignedInteger_2  );
    CU_add_test( suite, "#_3", test_PopSignedInteger_3  );
    CU_add_test( suite, "#_4", test_PopSignedInteger_4  );
    CU_add_test( suite, "#_5", test_PopSignedInteger_5  );
    CU_add_test( suite, "#_6", test_PopSignedInteger_6  );
    CU_add_test( suite, "#_7", test_PopSignedInteger_7  );
    CU_add_test( suite, "#_8", test_PopSignedInteger_8  );
    CU_add_test( suite, "#_9", test_PopSignedInteger_9  );
    CU_add_test( suite, "#10", test_PopSignedInteger_10 );
    CU_add_test( suite, "#11", test_PopSignedInteger_11 );
    CU_add_test( suite, "#12", test_PopSignedInteger_12 );
    CU_add_test( suite, "#13", test_PopSignedInteger_13 );
    CU_add_test( suite, "#14", test_PopSignedInteger_14 );
    CU_add_test( suite, "#15", test_PopSignedInteger_15 );
    CU_add_test( suite, "#16", test_PopSignedInteger_16 );
    CU_add_test( suite, "#17", test_PopSignedInteger_17 );
    CU_add_test( suite, "#18", test_PopSignedInteger_18 );
    CU_add_test( suite, "#19", test_PopSignedInteger_19 );
    CU_add_test( suite, "#20", test_PopSignedInteger_20 );
    CU_add_test( suite, "#21", test_PopSignedInteger_21 );
    CU_add_test( suite, "#22", test_PopSignedInteger_22 );
    CU_add_test( suite, "#23", test_PopSignedInteger_23 );
    CU_add_test( suite, "#24", test_PopSignedInteger_24 );

    return;
}


/******************************************************************************/
/* PopUnsignedInteger                                                         */
/******************************************************************************/
static unsigned long long test_PopUnsignedInteger_main( uint8_t length, ... )
{
    InputInfo_t        inputInfo;
    ConvertInfo_t      convertInfo;
    unsigned long long ret;

    va_start( inputInfo.args, length );

    convertInfo.length = length;

    ret = PopUnsignedInteger( &inputInfo, &convertInfo );

    va_end( inputInfo.args );

    return ret;
}

#define TEST_POPUNSIGNEDINTEGER( _NO,                                                   \
                                 _IN_TYPE,                                              \
                                 _IN_VALUE,                                             \
                                 _IN_LENGTH,                                            \
                                 _OUT_VALUE  )                                          \
    static void test_PopUnsignedInteger_##_NO( void )                                   \
    {                                                                                   \
        unsigned long long ret;                                                         \
                                                                                        \
        ret = test_PopUnsignedInteger_main( _IN_LENGTH, ( _IN_TYPE ) ( _IN_VALUE ) );   \
                                                                                        \
        /* OUTPUT判定 */                                                                \
        CU_ASSERT_EQUAL( ret, ( unsigned long long ) ( _OUT_VALUE ) );                  \
                                                                                        \
        return;                                                                         \
    }

/*---------------------+---+------------------------------------------------------------------+-------------------*/
/*                     | # | INPUT                                                            | OUTPUT            */
/*                     |   +------------------------------------------------+-----------------+-------------------*/
/*                     |   | argument                                       | length          | ret               */
/*                     |   +-------------------+----------------------------+                 |                   */
/*                     |   | type              | value                      |                 |                   */
/*---------------------+---+-------------------+----------------------------+-----------------+-------------------*/
TEST_POPUNSIGNEDINTEGER(  1, unsigned char     , /* min */ 0u               , LENGTH_CHAR     , 0u                );
TEST_POPUNSIGNEDINTEGER(  2, unsigned char     , /* mid */ UCHAR_MAX / 2u   , LENGTH_CHAR     , UCHAR_MAX / 2u    );
TEST_POPUNSIGNEDINTEGER(  3, unsigned char     , /* max */ UCHAR_MAX        , LENGTH_CHAR     , UCHAR_MAX         );
/*---------------------+---+-------------------+----------------------------+-----------------+-------------------*/
TEST_POPUNSIGNEDINTEGER(  4, unsigned short    , /* min */ 0u               , LENGTH_SHORT    , 0u                );
TEST_POPUNSIGNEDINTEGER(  5, unsigned short    , /* mid */ USHRT_MAX / 2u   , LENGTH_SHORT    , USHRT_MAX / 2u    );
TEST_POPUNSIGNEDINTEGER(  6, unsigned short    , /* max */ USHRT_MAX        , LENGTH_SHORT    , USHRT_MAX         );
/*---------------------+---+-------------------+----------------------------+-----------------+-------------------*/
TEST_POPUNSIGNEDINTEGER(  7, unsigned long     , /* min */ 0ul              , LENGTH_LONG     , 0ul               );
TEST_POPUNSIGNEDINTEGER(  8, unsigned long     , /* mid */ ULONG_MAX / 2ul  , LENGTH_LONG     , ULONG_MAX / 2ul   );
TEST_POPUNSIGNEDINTEGER(  9, unsigned long     , /* max */ ULONG_MAX        , LENGTH_LONG     , ULONG_MAX         );
/*---------------------+---+-------------------+----------------------------+-----------------+-------------------*/
TEST_POPUNSIGNEDINTEGER( 10, unsigned long long, /* min */ 0ull             , LENGTH_LONG_LONG, 0ull              );
TEST_POPUNSIGNEDINTEGER( 11, unsigned long long, /* mid */ ULLONG_MAX / 2ull, LENGTH_LONG_LONG, ULLONG_MAX / 2ull );
TEST_POPUNSIGNEDINTEGER( 12, unsigned long long, /* max */ ULLONG_MAX       , LENGTH_LONG_LONG, ULLONG_MAX        );
/*---------------------+---+-------------------+----------------------------+-----------------+-------------------*/
TEST_POPUNSIGNEDINTEGER( 13, uintmax_t         , /* min */ 0u               , LENGTH_INTMAX   , 0u                );
TEST_POPUNSIGNEDINTEGER( 14, uintmax_t         , /* mid */ UINTMAX_MAX / 2u , LENGTH_INTMAX   , UINTMAX_MAX / 2u  );
TEST_POPUNSIGNEDINTEGER( 15, uintmax_t         , /* max */ UINTMAX_MAX      , LENGTH_INTMAX   , UINTMAX_MAX       );
/*---------------------+---+-------------------+----------------------------+-----------------+-------------------*/
TEST_POPUNSIGNEDINTEGER( 16, size_t            , /* min */ 0u               , LENGTH_SIZE     , 0u                );
TEST_POPUNSIGNEDINTEGER( 17, size_t            , /* mid */ SIZE_MAX / 2u    , LENGTH_SIZE     , SIZE_MAX / 2u     );
TEST_POPUNSIGNEDINTEGER( 18, size_t            , /* max */ SIZE_MAX         , LENGTH_SIZE     , SIZE_MAX          );
/*---------------------+---+-------------------+----------------------------+-----------------+-------------------*/
TEST_POPUNSIGNEDINTEGER( 19, ptrdiff_t         , /* min */ PTRDIFF_MIN      , LENGTH_PTRDIFF  , PTRDIFF_MIN       );
TEST_POPUNSIGNEDINTEGER( 20, ptrdiff_t         , /* mid */ 0u               , LENGTH_PTRDIFF  , 0u                );
TEST_POPUNSIGNEDINTEGER( 21, ptrdiff_t         , /* max */ PTRDIFF_MAX      , LENGTH_PTRDIFF  , PTRDIFF_MAX       );
/*---------------------+---+-------------------+----------------------------+-----------------+-------------------*/
TEST_POPUNSIGNEDINTEGER( 22, unsigned int      , /* min */ 0u               , LENGTH_DEFAULT  , 0u                );
TEST_POPUNSIGNEDINTEGER( 23, unsigned int      , /* mid */ UINT_MAX / 2u    , LENGTH_DEFAULT  , UINT_MAX / 2u     );
TEST_POPUNSIGNEDINTEGER( 24, unsigned int      , /* max */ UINT_MAX         , LENGTH_DEFAULT  , UINT_MAX          );
/*---------------------+---+-------------------+----------------------------+-----------------+-------------------*/

static void test_PopUnsignedInteger( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "PopUnsignedInteger", NULL, NULL );

    CU_add_test( suite, "#_1", test_PopUnsignedInteger_1  );
    CU_add_test( suite, "#_2", test_PopUnsignedInteger_2  );
    CU_add_test( suite, "#_3", test_PopUnsignedInteger_3  );
    CU_add_test( suite, "#_4", test_PopUnsignedInteger_4  );
    CU_add_test( suite, "#_5", test_PopUnsignedInteger_5  );
    CU_add_test( suite, "#_6", test_PopUnsignedInteger_6  );
    CU_add_test( suite, "#_7", test_PopUnsignedInteger_7  );
    CU_add_test( suite, "#_8", test_PopUnsignedInteger_8  );
    CU_add_test( suite, "#_9", test_PopUnsignedInteger_9  );
    CU_add_test( suite, "#10", test_PopUnsignedInteger_10 );
    CU_add_test( suite, "#11", test_PopUnsignedInteger_11 );
    CU_add_test( suite, "#12", test_PopUnsignedInteger_12 );
    CU_add_test( suite, "#13", test_PopUnsignedInteger_13 );
    CU_add_test( suite, "#14", test_PopUnsignedInteger_14 );
    CU_add_test( suite, "#15", test_PopUnsignedInteger_15 );
    CU_add_test( suite, "#16", test_PopUnsignedInteger_16 );
    CU_add_test( suite, "#17", test_PopUnsignedInteger_17 );
    CU_add_test( suite, "#18", test_PopUnsignedInteger_18 );
    CU_add_test( suite, "#19", test_PopUnsignedInteger_19 );
    CU_add_test( suite, "#20", test_PopUnsignedInteger_20 );
    CU_add_test( suite, "#21", test_PopUnsignedInteger_21 );
    CU_add_test( suite, "#22", test_PopUnsignedInteger_22 );
    CU_add_test( suite, "#23", test_PopUnsignedInteger_23 );
    CU_add_test( suite, "#24", test_PopUnsignedInteger_24 );

    return;
}


/******************************************************************************/
/* PutChar                                                                    */
/******************************************************************************/
#define TEST_PUTCHAR( _NO,                                              \
                      _IN_POUTPUT,                                      \
                      _IN_WRITEIDX,                                     \
                      _IN_SIZE,                                         \
                      _IN_C,                                            \
                      _IN_SIZECHAR,                                     \
                      _OUT_RET,                                         \
                      _OUT_POUTPUT,                                     \
                      _OUT_WRITEIDX )                                   \
    static void test_PutChar_##_NO( void )                              \
    {                                                                   \
        char         output[] = _IN_POUTPUT;                            \
        OutputInfo_t outputInfo;                                        \
        char         c;                                                 \
        ssize_t      sizeChar;                                          \
        bool         ret;                                               \
                                                                        \
        /* INPUT設定 */                                                 \
        outputInfo.pOutput  = output;                                   \
        outputInfo.writeIdx = _IN_WRITEIDX;                             \
        outputInfo.size     = _IN_SIZE;                                 \
        c                   = _IN_C;                                    \
        sizeChar            = _IN_SIZECHAR;                             \
                                                                        \
        ret = PutChar( &outputInfo, c, sizeChar );                      \
                                                                        \
        /* OUTPUT判定 */                                                \
        CU_ASSERT_EQUAL(        ret,                 _OUT_RET      );   \
        CU_ASSERT_STRING_EQUAL( outputInfo.pOutput,  _OUT_POUTPUT  );   \
        CU_ASSERT_EQUAL(        outputInfo.writeIdx, _OUT_WRITEIDX );   \
                                                                        \
        return;                                                         \
    }

/*----------+---+-----------------------------------------------------------+---------------------------*/
/*          | # | INPUT                                                     | OUTPUT                    */
/*          |   +-------------------------------------+----+----------------+------+--------------------*/
/*          |   | pOutputInfo                         | c  | sizeChar       | ret  | pOutputInfo        */
/*          |   +---------+----------------+----------+    |                |      +---------+----------*/
/*          |   | pOutput | writeIdx       | size     |    |                |      | pOutput | writeIdx */
/*----------+---+---------+----------------+----------+----+----------------+------+---------+----------*/
TEST_PUTCHAR(  1, ""      ,               1, /* > */ 0, 'T',               1, false, ""      ,        1 );
TEST_PUTCHAR(  2, ""      ,               0, /* = */ 0, 'T',               1, false, ""      ,        0 );
TEST_PUTCHAR(  3, "*"     ,               0, /* < */ 1, 'T',               1, true , "T"     ,        1 );
/*----------+---+---------+----------------+----------+----+----------------+------+---------+----------*/
TEST_PUTCHAR(  4, "*"     ,               0,         1, 'T', /* no loop */ 0, true , "*"     ,        0 );
TEST_PUTCHAR(  5, "**"    ,               0,         2, 'T', /*    loop */ 2, true , "TT"    ,        2 );
/*----------+---+---------+----------------+----------+----+----------------+------+---------+----------*/
TEST_PUTCHAR(  6, "***"   , /* no head */ 1,         3, 'T',               1, true , "*T*"   ,        2 );
/*----------+---+---------+----------------+----------+----+----------------+------+---------+----------*/

static void test_PutChar( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "PutChar", NULL, NULL );

    CU_add_test( suite, "#_1", test_PutChar_1 );
    CU_add_test( suite, "#_2", test_PutChar_2 );
    CU_add_test( suite, "#_3", test_PutChar_3 );
    CU_add_test( suite, "#_4", test_PutChar_4 );
    CU_add_test( suite, "#_5", test_PutChar_5 );
    CU_add_test( suite, "#_6", test_PutChar_6 );

    return;
}


/******************************************************************************/
/* PutInteger                                                                 */
/******************************************************************************/
#define TEST_PUTINTEGER( _NO,                                                                       \
                         _IN_LENVAL,                                                                \
                         _IN_LENZERO,                                                               \
                         _IN_RET      )                                                             \
    static void test_PutInteger_##_NO( void )                                                       \
    {                                                                                               \
        bool          ret;                                                                          \
        OutputInfo_t  outputInfo;                                                                   \
        ConvertInfo_t convertInfo;                                                                  \
        ssize_t       topIdx;                                                                       \
                                                                                                    \
        /* INPUT初期化 */                                                                           \
        UtilInit();                                                                                 \
        convertInfo.lenVal  = _IN_LENVAL;                                                           \
        convertInfo.lenZero = _IN_LENZERO;                                                          \
        param_PutStr.ret    = _IN_RET;                                                              \
                                                                                                    \
        /* OUTPUT初期化 */                                                                          \
        param_PutChar[ 0 ].pOutputInfo = NULL;                                                      \
        param_PutChar[ 0 ].c           = 0xFF;                                                      \
        param_PutChar[ 0 ].sizeChar    = ~( _IN_LENZERO );                                          \
        param_PutStr.pOutputInfo       = NULL;                                                      \
        param_PutStr.pStr              = NULL;                                                      \
        param_PutStr.sizeStr           = ~( _IN_LENVAL );                                           \
                                                                                                    \
        ret = PutInteger( &outputInfo, &convertInfo );                                              \
                                                                                                    \
        topIdx = BUFFER_SIZE_INTEGER - convertInfo.lenVal;                                          \
                                                                                                    \
        /* OUTPUT判定 */                                                                            \
        CU_ASSERT_PTR_EQUAL( param_PutChar[ 0 ].pOutputInfo, &outputInfo                      );    \
        CU_ASSERT_EQUAL(     param_PutChar[ 0 ].c,           '0'                              );    \
        CU_ASSERT_EQUAL(     param_PutChar[ 0 ].sizeChar,    _IN_LENZERO                      );    \
        CU_ASSERT_PTR_EQUAL( param_PutStr.pOutputInfo,       &outputInfo                      );    \
        CU_ASSERT_PTR_EQUAL( param_PutStr.pStr,              &( convertInfo.value[ topIdx ] ) );    \
        CU_ASSERT_EQUAL(     param_PutStr.sizeStr,           _IN_LENVAL                       );    \
        CU_ASSERT_EQUAL(     ret,                            _IN_RET                          );    \
                                                                                                    \
        return;                                                                                     \
    }

/*-------------+---+------------------------------------------------------*/
/*             | # | INPUT / OUTPUT                                       */
/*             |   +-------------------------------------------+----------*/
/*             |   | pConvertInfo                              | PutStr() */
/*             |   +---------------------+---------------------+----------*/
/*             |   | lenVal              | lenZero             | ret      */
/*-------------+---+---------------------+---------------------+----------*/
TEST_PUTINTEGER(  1, /* 最小 */ INT_MIN  ,                    0, false    );
TEST_PUTINTEGER(  2, /* 中間 */         0,                    0, true     );
TEST_PUTINTEGER(  3, /* 最大 */ SSIZE_MAX,                    0, false    );
/*-------------+---+---------------------+---------------------+----------*/
TEST_PUTINTEGER(  4,                    0, /* 最小 */ INT_MIN  , true     );
TEST_PUTINTEGER(  5,                    0, /* 中間 */         0, false    );
TEST_PUTINTEGER(  6,                    0, /* 最大 */ SSIZE_MAX, true     );
/*-------------+---+---------------------+---------------------+----------*/

static void test_PutInteger( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "PutInteger", NULL, NULL );

    CU_add_test( suite, "#_1", test_PutInteger_1 );
    CU_add_test( suite, "#_2", test_PutInteger_2 );
    CU_add_test( suite, "#_3", test_PutInteger_3 );
    CU_add_test( suite, "#_4", test_PutInteger_4 );
    CU_add_test( suite, "#_5", test_PutInteger_5 );
    CU_add_test( suite, "#_6", test_PutInteger_6 );

    return;
}


/******************************************************************************/
/* PutStr                                                                     */
/******************************************************************************/
#define TEST_PUTSTR( _NO,                                               \
                     _IN_POUTPUT,                                       \
                     _IN_WRITEIDX,                                      \
                     _IN_SIZE,                                          \
                     _IN_PSTR,                                          \
                     _IN_SIZESTR,                                       \
                     _OUT_RET,                                          \
                     _OUT_POUTPUT,                                      \
                     _OUT_WRITEIDX )                                    \
    static void test_PutStr_##_NO( void )                               \
    {                                                                   \
        char         output[] = _IN_POUTPUT;                            \
        OutputInfo_t outputInfo;                                        \
        const char   *pStr;                                             \
        ssize_t      sizeStr;                                           \
        bool         ret;                                               \
                                                                        \
        /* INPUT設定 */                                                 \
        outputInfo.pOutput  = output;                                   \
        outputInfo.writeIdx = _IN_WRITEIDX;                             \
        outputInfo.size     = _IN_SIZE;                                 \
        pStr                = _IN_PSTR;                                 \
        sizeStr             = _IN_SIZESTR;                              \
                                                                        \
        ret = PutStr( &outputInfo, pStr, sizeStr );                     \
                                                                        \
        /* OUTPUT判定 */                                                \
        CU_ASSERT_EQUAL(        ret,                 _OUT_RET      );   \
        CU_ASSERT_STRING_EQUAL( outputInfo.pOutput,  _OUT_POUTPUT  );   \
        CU_ASSERT_EQUAL       ( outputInfo.writeIdx, _OUT_WRITEIDX );   \
                                                                        \
        return;                                                         \
    }

/*---------+---+-------------------------------------------------------------+---------------------------*/
/*         | # | INPUT                                                       | OUTPUT                    */
/*         |   +-------------------------------------+------+----------------+------+--------------------*/
/*         |   | pOutputInfo                         | pStr | sizeStr        | ret  | pOutputInfo        */
/*         |   +---------+----------------+----------+      |                |      +---------+----------*/
/*         |   | pOutput | writeIdx       | size     |      |                |      | pOutput | writeIdx */
/*---------+---+---------+----------------+----------+------+----------------+------+---------+----------*/
TEST_PUTSTR(  1, ""      ,               1, /* > */ 0, "T"  ,               1, false, ""      ,        1 );
TEST_PUTSTR(  2, ""      ,               0, /* = */ 0, "T"  ,               1, false, ""      ,        0 );
TEST_PUTSTR(  3, "*"     ,               0, /* < */ 1, "T"  ,               1, true , "T"     ,        1 );
/*---------+---+---------+----------------+----------+------+----------------+------+---------+----------*/
TEST_PUTSTR(  4, "*"     ,               0,         1, "T"  , /* no loop */ 0, true , "*"     ,        0 );
TEST_PUTSTR(  5, "**"    ,               0,         2, "TE" , /*    loop */ 2, true , "TE"    ,        2 );
/*---------+---+---------+----------------+----------+------+----------------+------+---------+----------*/
TEST_PUTSTR(  6, "***"   , /* no head */ 1,         3, "T"  ,               1, true , "*T*"   ,        2 );
/*---------+---+---------+----------------+----------+------+----------------+------+---------+----------*/

static void test_PutStr( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "PutStr", NULL, NULL );

    CU_add_test( suite, "#_1", test_PutStr_1 );
    CU_add_test( suite, "#_2", test_PutStr_2 );
    CU_add_test( suite, "#_3", test_PutStr_3 );
    CU_add_test( suite, "#_4", test_PutStr_4 );
    CU_add_test( suite, "#_5", test_PutStr_5 );
    CU_add_test( suite, "#_6", test_PutStr_6 );

    return;
}


/******************************************************************************/
/* SetAlt                                                                     */
/******************************************************************************/
#define TEST_SETALT( _NO,                                           \
                     _IN_FLAG,                                      \
                     _IN_BASE,                                      \
                     _IN_UPPERLOWER,                                \
                     _OUT_PALT,                                     \
                     _OUT_LENALT     )                              \
    static void test_SetAlt_##_NO( void )                           \
    {                                                               \
        ConvertInfo_t convertInfo;                                  \
                                                                    \
        /* INPUT設定 */                                             \
        convertInfo.flag       = _IN_FLAG;                          \
        convertInfo.base       = _IN_BASE;                          \
        convertInfo.upperLower = _IN_UPPERLOWER;                    \
                                                                    \
        /* OUTPUT初期化 */                                          \
        convertInfo.pAlt   = "DUMMY";                               \
        convertInfo.lenAlt = SSIZE_MAX;                             \
                                                                    \
        SetAlt( &convertInfo );                                     \
                                                                    \
        /* OUTPUT判定 */                                            \
        CU_ASSERT_STRING_EQUAL( convertInfo.pAlt,   _OUT_PALT   );  \
        CU_ASSERT_EQUAL       ( convertInfo.lenAlt, _OUT_LENALT );  \
                                                                    \
        return;                                                     \
    }

/*---------+---+--------------------------------------------+---------------*/
/*         | # | INPUT                                      | OUTPUT        */
/*         |   +--------------------------------------------+---------------*/
/*         |   | pConvertInfo                               | pConvertInfo  */
/*         |   +------------------------+------+------------+------+--------*/
/*         |   | flag                   | base | upperLower | pAlt | lenAlt */
/*---------+---+------------------------+------+------------+------+--------*/
TEST_SETALT(  1, /* all無効 */      0x00,     8, UPPER_CASE , ""   ,      0 );
TEST_SETALT(  2,                    0x00,    10, LOWER_CASE , ""   ,      0 );
TEST_SETALT(  3,                    0x00,    16, UPPER_CASE , ""   ,      0 );
/*---------+---+------------------------+------+------------+------+--------*/
TEST_SETALT(  4, /* 無効    */ ~FLAG_ALT,     8, LOWER_CASE , ""   ,      0 );
TEST_SETALT(  5,               ~FLAG_ALT,    10, UPPER_CASE , ""   ,      0 );
TEST_SETALT(  6,               ~FLAG_ALT,    16, LOWER_CASE , ""   ,      0 );
/*---------+---+------------------------+------+------------+------+--------*/
TEST_SETALT(  7, /* 有効    */  FLAG_ALT,     8, UPPER_CASE , "0"  ,      1 );
TEST_SETALT(  8,                FLAG_ALT,    10, LOWER_CASE , ""   ,      0 );
TEST_SETALT(  9,                FLAG_ALT,    16, LOWER_CASE , "0x" ,      2 );
TEST_SETALT( 10,                FLAG_ALT,    16, UPPER_CASE , "0X" ,      2 );
/*---------+---+------------------------+------+------------+------+--------*/
TEST_SETALT( 11, /* all有効 */      0xFF,     8, UPPER_CASE , "0"  ,      1 );
TEST_SETALT( 12,                    0xFF,    10, LOWER_CASE , ""   ,      0 );
TEST_SETALT( 13,                    0xFF,    16, LOWER_CASE , "0x" ,      2 );
TEST_SETALT( 14,                    0xFF,    16, UPPER_CASE , "0X" ,      2 );
/*---------+---+------------------------+------+------------+------+--------*/

static void test_SetAlt( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "SetAlt", NULL, NULL );

    CU_add_test( suite, "#_1", test_SetAlt_1  );
    CU_add_test( suite, "#_2", test_SetAlt_2  );
    CU_add_test( suite, "#_3", test_SetAlt_3  );
    CU_add_test( suite, "#_4", test_SetAlt_4  );
    CU_add_test( suite, "#_5", test_SetAlt_5  );
    CU_add_test( suite, "#_6", test_SetAlt_6  );
    CU_add_test( suite, "#_7", test_SetAlt_7  );
    CU_add_test( suite, "#_8", test_SetAlt_8  );
    CU_add_test( suite, "#_9", test_SetAlt_9  );
    CU_add_test( suite, "#10", test_SetAlt_10 );
    CU_add_test( suite, "#11", test_SetAlt_11 );
    CU_add_test( suite, "#12", test_SetAlt_12 );
    CU_add_test( suite, "#13", test_SetAlt_13 );
    CU_add_test( suite, "#14", test_SetAlt_14 );

    return;
}


/******************************************************************************/
/* SetInteger                                                                 */
/******************************************************************************/
#define TEST_SETINTEGER( _NO,                                           \
                         _IN_BASE,                                      \
                         _IN_UPPERLOWER,                                \
                         _IN_VALUE,                                     \
                         _OUT_VALUE_STR,                                \
                         _OUT_LENVAL     )                              \
    static void test_SetInteger_##_NO( void )                           \
    {                                                                   \
        uint32_t      i;                                                \
        uint32_t      j;                                                \
        char          *pStr;                                            \
        ConvertInfo_t convertInfo;                                      \
                                                                        \
        /* INPUT初期化 */                                               \
        convertInfo.base       = _IN_BASE;                              \
        convertInfo.lenVal     = 0;                                     \
        convertInfo.upperLower = _IN_UPPERLOWER;                        \
                                                                        \
        /* OUTPUT初期化 */                                              \
        pStr = _OUT_VALUE_STR;                                          \
        for ( i = 0; i < BUFFER_SIZE_INTEGER; i++ ) {                   \
            convertInfo.value[ i ] = 0;                                 \
        }                                                               \
                                                                        \
        SetInteger( &convertInfo, _IN_VALUE );                          \
                                                                        \
        /* OUTPUT判定 */                                                \
        CU_ASSERT_EQUAL( convertInfo.lenVal, _OUT_LENVAL );             \
                                                                        \
        for ( i = BUFFER_SIZE_INTEGER - convertInfo.lenVal, j = 0;      \
              i < BUFFER_SIZE_INTEGER;                                  \
              i++, j++                                             ) {  \
            CU_ASSERT_EQUAL( convertInfo.value[ i ], pStr[ j ] );       \
        }                                                               \
                                                                        \
        return;                                                         \
    }

/*-------------+---+-----------------------------------+----------------*/
/*             | # | INPUT                             | OUTPUT         */
/*             |   +-------------------+---------------+----------------*/
/*             |   | pConvertInfo      | value         | pConvertInfo   */
/*             |   +------+------------+               +-------+--------*/
/*             |   | base | upperLower |               | value | lenVal */
/*-------------+---+------+------------+---------------+-------+--------*/
TEST_SETINTEGER(  1,     8, UPPER_CASE , /* 1桁 */   00, "0"   ,      1 );
TEST_SETINTEGER(  2,     8, UPPER_CASE ,             01, "1"   ,      1 );
TEST_SETINTEGER(  3,     8, UPPER_CASE ,             02, "2"   ,      1 );
TEST_SETINTEGER(  4,     8, UPPER_CASE ,             03, "3"   ,      1 );
TEST_SETINTEGER(  5,     8, UPPER_CASE ,             04, "4"   ,      1 );
TEST_SETINTEGER(  6,     8, UPPER_CASE ,             05, "5"   ,      1 );
TEST_SETINTEGER(  7,     8, UPPER_CASE ,             06, "6"   ,      1 );
TEST_SETINTEGER(  8,     8, UPPER_CASE ,             07, "7"   ,      1 );
/*-------------+---+------+------------+---------------+-------+--------*/
TEST_SETINTEGER(  9,     8, LOWER_CASE , /* 2桁 */  010, "10"  ,      2 );
TEST_SETINTEGER( 10,     8, LOWER_CASE ,            011, "11"  ,      2 );
TEST_SETINTEGER( 11,     8, LOWER_CASE ,            012, "12"  ,      2 );
TEST_SETINTEGER( 12,     8, LOWER_CASE ,            013, "13"  ,      2 );
TEST_SETINTEGER( 13,     8, LOWER_CASE ,            014, "14"  ,      2 );
TEST_SETINTEGER( 14,     8, LOWER_CASE ,            015, "15"  ,      2 );
TEST_SETINTEGER( 15,     8, LOWER_CASE ,            016, "16"  ,      2 );
TEST_SETINTEGER( 16,     8, LOWER_CASE ,            017, "17"  ,      2 );
/*-------------+---+------+------------+---------------+-------+--------*/
TEST_SETINTEGER( 17,    16, UPPER_CASE , /* 1桁 */  0x0, "0"   ,      1 );
TEST_SETINTEGER( 18,    16, UPPER_CASE ,            0x1, "1"   ,      1 );
TEST_SETINTEGER( 19,    16, UPPER_CASE ,            0x2, "2"   ,      1 );
TEST_SETINTEGER( 20,    16, UPPER_CASE ,            0x3, "3"   ,      1 );
TEST_SETINTEGER( 21,    16, UPPER_CASE ,            0x4, "4"   ,      1 );
TEST_SETINTEGER( 22,    16, UPPER_CASE ,            0x5, "5"   ,      1 );
TEST_SETINTEGER( 23,    16, UPPER_CASE ,            0x6, "6"   ,      1 );
TEST_SETINTEGER( 24,    16, UPPER_CASE ,            0x7, "7"   ,      1 );
TEST_SETINTEGER( 25,    16, UPPER_CASE ,            0x8, "8"   ,      1 );
TEST_SETINTEGER( 26,    16, UPPER_CASE ,            0x9, "9"   ,      1 );
TEST_SETINTEGER( 27,    16, UPPER_CASE ,            0xA, "A"   ,      1 );
TEST_SETINTEGER( 28,    16, UPPER_CASE ,            0xB, "B"   ,      1 );
TEST_SETINTEGER( 29,    16, UPPER_CASE ,            0xC, "C"   ,      1 );
TEST_SETINTEGER( 30,    16, UPPER_CASE ,            0xD, "D"   ,      1 );
TEST_SETINTEGER( 31,    16, UPPER_CASE ,            0xE, "E"   ,      1 );
TEST_SETINTEGER( 32,    16, UPPER_CASE ,            0xF, "F"   ,      1 );
/*-------------+---+------+------------+---------------+-------+--------*/
TEST_SETINTEGER( 33,    16, LOWER_CASE , /* 2桁 */ 0x10, "10"  ,      2 );
TEST_SETINTEGER( 34,    16, LOWER_CASE ,           0x11, "11"  ,      2 );
TEST_SETINTEGER( 35,    16, LOWER_CASE ,           0x12, "12"  ,      2 );
TEST_SETINTEGER( 36,    16, LOWER_CASE ,           0x13, "13"  ,      2 );
TEST_SETINTEGER( 37,    16, LOWER_CASE ,           0x14, "14"  ,      2 );
TEST_SETINTEGER( 38,    16, LOWER_CASE ,           0x15, "15"  ,      2 );
TEST_SETINTEGER( 39,    16, LOWER_CASE ,           0x16, "16"  ,      2 );
TEST_SETINTEGER( 40,    16, LOWER_CASE ,           0x17, "17"  ,      2 );
TEST_SETINTEGER( 41,    16, LOWER_CASE ,           0x18, "18"  ,      2 );
TEST_SETINTEGER( 42,    16, LOWER_CASE ,           0x19, "19"  ,      2 );
TEST_SETINTEGER( 43,    16, LOWER_CASE ,           0x1A, "1a"  ,      2 );
TEST_SETINTEGER( 44,    16, LOWER_CASE ,           0x1B, "1b"  ,      2 );
TEST_SETINTEGER( 45,    16, LOWER_CASE ,           0x1C, "1c"  ,      2 );
TEST_SETINTEGER( 46,    16, LOWER_CASE ,           0x1D, "1d"  ,      2 );
TEST_SETINTEGER( 47,    16, LOWER_CASE ,           0x1E, "1e"  ,      2 );
TEST_SETINTEGER( 48,    16, LOWER_CASE ,           0x1F, "1f"  ,      2 );
/*-------------+---+------+------------+---------------+-------+--------*/

static void test_SetInteger( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "SetAlt", NULL, NULL );

    CU_add_test( suite, "#_1", test_SetInteger_1  );
    CU_add_test( suite, "#_2", test_SetInteger_2  );
    CU_add_test( suite, "#_3", test_SetInteger_3  );
    CU_add_test( suite, "#_4", test_SetInteger_4  );
    CU_add_test( suite, "#_5", test_SetInteger_5  );
    CU_add_test( suite, "#_6", test_SetInteger_6  );
    CU_add_test( suite, "#_7", test_SetInteger_7  );
    CU_add_test( suite, "#_8", test_SetInteger_8  );
    CU_add_test( suite, "#_9", test_SetInteger_9  );
    CU_add_test( suite, "#10", test_SetInteger_10 );
    CU_add_test( suite, "#11", test_SetInteger_11 );
    CU_add_test( suite, "#12", test_SetInteger_12 );
    CU_add_test( suite, "#13", test_SetInteger_13 );
    CU_add_test( suite, "#14", test_SetInteger_14 );
    CU_add_test( suite, "#15", test_SetInteger_15 );
    CU_add_test( suite, "#16", test_SetInteger_16 );
    CU_add_test( suite, "#17", test_SetInteger_17 );
    CU_add_test( suite, "#18", test_SetInteger_18 );
    CU_add_test( suite, "#19", test_SetInteger_19 );
    CU_add_test( suite, "#20", test_SetInteger_20 );
    CU_add_test( suite, "#21", test_SetInteger_21 );
    CU_add_test( suite, "#22", test_SetInteger_22 );
    CU_add_test( suite, "#23", test_SetInteger_23 );
    CU_add_test( suite, "#24", test_SetInteger_24 );
    CU_add_test( suite, "#25", test_SetInteger_25 );
    CU_add_test( suite, "#26", test_SetInteger_26 );
    CU_add_test( suite, "#27", test_SetInteger_27 );
    CU_add_test( suite, "#28", test_SetInteger_28 );
    CU_add_test( suite, "#29", test_SetInteger_29 );
    CU_add_test( suite, "#30", test_SetInteger_30 );
    CU_add_test( suite, "#31", test_SetInteger_31 );
    CU_add_test( suite, "#32", test_SetInteger_32 );
    CU_add_test( suite, "#33", test_SetInteger_33 );
    CU_add_test( suite, "#34", test_SetInteger_34 );
    CU_add_test( suite, "#35", test_SetInteger_35 );
    CU_add_test( suite, "#36", test_SetInteger_36 );
    CU_add_test( suite, "#37", test_SetInteger_37 );
    CU_add_test( suite, "#38", test_SetInteger_38 );
    CU_add_test( suite, "#39", test_SetInteger_39 );
    CU_add_test( suite, "#40", test_SetInteger_40 );
    CU_add_test( suite, "#41", test_SetInteger_41 );
    CU_add_test( suite, "#42", test_SetInteger_42 );
    CU_add_test( suite, "#43", test_SetInteger_43 );
    CU_add_test( suite, "#44", test_SetInteger_44 );
    CU_add_test( suite, "#45", test_SetInteger_45 );
    CU_add_test( suite, "#46", test_SetInteger_46 );
    CU_add_test( suite, "#47", test_SetInteger_47 );
    CU_add_test( suite, "#48", test_SetInteger_48 );

    return;
}

/******************************************************************************/
/* SetSign                                                                    */
/******************************************************************************/
#define TEST_SETSIGN( _NO,                                      \
                      _IN_FLAG,                                 \
                      _IN_VALUE,                                \
                      _OUT_SIGN,                                \
                      _OUT_LENSIGN )                            \
    static void test_SetSign_##_NO( void )                      \
    {                                                           \
        ConvertInfo_t convertInfo;                              \
                                                                \
        /* INPUT初期化 */                                       \
        convertInfo.flag = _IN_FLAG;                            \
                                                                \
        /* OUTPUT初期化 */                                      \
        convertInfo.sign    = ~_OUT_SIGN;                       \
        convertInfo.lenSign = ~_OUT_LENSIGN;                    \
                                                                \
        SetSign( &convertInfo, _IN_VALUE );                     \
                                                                \
        /* OUTPUT判定 */                                        \
        CU_ASSERT_EQUAL( convertInfo.sign,    _OUT_SIGN    );   \
        CU_ASSERT_EQUAL( convertInfo.lenSign, _OUT_LENSIGN );   \
                                                                \
        return;                                                 \
    }

/*----------+---+-----------------------------------------------------------------+----------------*/
/*          | # | INPUT                                                           | OUTPUT         */
/*          |   +--------------------------------------------+--------------------+----------------*/
/*          |   | pConvertInfo                               | value              | pConvertInfo   */
/*          |   +--------------------------------------------+                    +------+---------*/
/*          |   | flag                                       |                    | sign | lenSign */
/*----------+---+--------------------------------------------+--------------------+------+---------*/
TEST_SETSIGN(  1, /* all無効   */                        0x00, /* 最小 */ LONG_MIN, '-'  ,       1 );
TEST_SETSIGN(  2,                                        0x00, /* <  0 */       -1, '-'  ,       1 );
TEST_SETSIGN(  3,                                        0x00, /* >= 0 */        0,     0,       0 );
TEST_SETSIGN(  4,                                        0x00, /* 最大 */ LONG_MAX,     0,       0 );
/*----------+---+--------------------------------------------+--------------------+------+---------*/
TEST_SETSIGN(  5, /* 無効      */ ~( FLAG_SIGN | FLAG_SPACE ), /* 最小 */ LONG_MIN, '-'  ,       1 );
TEST_SETSIGN(  6,                 ~( FLAG_SIGN | FLAG_SPACE ), /* <  0 */       -1, '-'  ,       1 );
TEST_SETSIGN(  7,                 ~( FLAG_SIGN | FLAG_SPACE ), /* >= 0 */        0,     0,       0 );
TEST_SETSIGN(  8,                 ~( FLAG_SIGN | FLAG_SPACE ), /* 最大 */ LONG_MAX,     0,       0 );
/*----------+---+--------------------------------------------+--------------------+------+---------*/
TEST_SETSIGN(  9, /* sign有効  */    FLAG_SIGN               , /* 最小 */ LONG_MIN, '-'  ,       1 );
TEST_SETSIGN( 10,                    FLAG_SIGN               , /* <  0 */       -1, '-'  ,       1 );
TEST_SETSIGN( 11,                    FLAG_SIGN               , /* >= 0 */        0, '+'  ,       1 );
TEST_SETSIGN( 12,                    FLAG_SIGN               , /* 最大 */ LONG_MAX, '+'  ,       1 );
/*----------+---+--------------------------------------------+--------------------+------+---------*/
TEST_SETSIGN( 13, /* space有効 */                FLAG_SPACE  , /* 最小 */ LONG_MIN, '-'  ,       1 );
TEST_SETSIGN( 14,                                FLAG_SPACE  , /* <  0 */       -1, '-'  ,       1 );
TEST_SETSIGN( 15,                                FLAG_SPACE  , /* >= 0 */        0, ' '  ,       1 );
TEST_SETSIGN( 16,                                FLAG_SPACE  , /* 最大 */ LONG_MAX, ' '  ,       1 );
/*----------+---+--------------------------------------------+--------------------+------+---------*/
TEST_SETSIGN( 17, /* all有効   */                        0xFF, /* 最小 */ LONG_MIN, '-'  ,       1 );
TEST_SETSIGN( 18,                                        0xFF, /* <  0 */       -1, '-'  ,       1 );
TEST_SETSIGN( 19,                                        0xFF, /* >= 0 */        0, '+'  ,       1 );
TEST_SETSIGN( 20,                                        0xFF, /* 最大 */ LONG_MAX, '+'  ,       1 );
/*----------+---+--------------------------------------------+--------------------+------+---------*/

static void test_SetSign( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "SetSign", NULL, NULL );

    CU_add_test( suite, "#_1", test_SetSign_1  );
    CU_add_test( suite, "#_2", test_SetSign_2  );
    CU_add_test( suite, "#_3", test_SetSign_3  );
    CU_add_test( suite, "#_4", test_SetSign_4  );
    CU_add_test( suite, "#_5", test_SetSign_5  );
    CU_add_test( suite, "#_6", test_SetSign_6  );
    CU_add_test( suite, "#_7", test_SetSign_7  );
    CU_add_test( suite, "#_8", test_SetSign_8  );
    CU_add_test( suite, "#_9", test_SetSign_9  );
    CU_add_test( suite, "#10", test_SetSign_10 );
    CU_add_test( suite, "#11", test_SetSign_11 );
    CU_add_test( suite, "#12", test_SetSign_12 );
    CU_add_test( suite, "#13", test_SetSign_13 );
    CU_add_test( suite, "#14", test_SetSign_14 );
    CU_add_test( suite, "#15", test_SetSign_15 );
    CU_add_test( suite, "#16", test_SetSign_16 );
    CU_add_test( suite, "#17", test_SetSign_17 );
    CU_add_test( suite, "#18", test_SetSign_18 );
    CU_add_test( suite, "#19", test_SetSign_19 );
    CU_add_test( suite, "#20", test_SetSign_20 );

    return;
}


/******************************************************************************/
/* SetZeroVsPrecision                                                         */
/******************************************************************************/
#define TEST_SETZEROVSPRECISION( _NO,                                               \
                                 _IN_PRECISION,                                     \
                                 _IN_FLAG,                                          \
                                 _IN_WIDTH,                                         \
                                 _IN_LENSIGN,                                       \
                                 _IN_LENALT,                                        \
                                 _IN_CALCLENZERO,                                   \
                                 _OUT_FLAG,                                         \
                                 _OUT_PRECISION,                                    \
                                 _OUT_LENZERO,                                      \
                                 _OUT_CALLCNT,                                      \
                                 _OUT_CALLFUNC_0  )                                 \
    static void test_SetZeroVsPrecision_##_NO( void )                               \
    {                                                                               \
        ConvertInfo_t convertInfo;                                                  \
                                                                                    \
        /* INPUT初期化 */                                                           \
        convertInfo.precision = _IN_PRECISION;                                      \
        convertInfo.flag      = _IN_FLAG;                                           \
        convertInfo.width     = _IN_WIDTH;                                          \
        convertInfo.lenSign   = _IN_LENSIGN;                                        \
        convertInfo.lenAlt    = _IN_LENALT;                                         \
        param_CalcLenZero.ret = _IN_CALCLENZERO;                                    \
                                                                                    \
        /* OUTPUT初期化 */                                                          \
        UtilInit();                                                                 \
        convertInfo.lenZero = ~( _OUT_LENZERO );                                    \
                                                                                    \
        SetZeroVsPrecision( &convertInfo );                                         \
                                                                                    \
        /* OUTPUT判定 */                                                            \
        CU_ASSERT_EQUAL(     convertInfo.flag,               0xFF & ( _OUT_FLAG ) );\
        CU_ASSERT_EQUAL(     convertInfo.precision,          _OUT_PRECISION       );\
        CU_ASSERT_EQUAL(     convertInfo.lenZero,            _OUT_LENZERO         );\
        CU_ASSERT_EQUAL(     UtilGetCallCount(),             _OUT_CALLCNT         );\
        CU_ASSERT_PTR_EQUAL( UtilGetCallFunc( 0 ),           _OUT_CALLFUNC_0      );\
        CU_ASSERT_PTR_EQUAL( param_CalcLenZero.pConvertInfo, &convertInfo         );\
                                                                                    \
        return;                                                                     \
    }

/*---------------------+---+-------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------------------*/
/*                     | # | INPUT                                                                                                                   | OUTPUT                                                         */
/*                     |   +---------------------------------------------------------------------------------------------------+---------------------+---------------------------------------+----------+-------------*/
/*                     |   | pConvertInfo                                                                                      | CalcLenZero()       | pConvertInfo                          | call cnt | call func   */
/*                     |   +-------------------------+-------------------------+-------------------+-------------+-------------+                     +-----------+----------------+----------+          |             */
/*                     |   | precision               | flag                    | width             | lenSign     | lenAlt      |                     | flag      | precision      | lenZero  |          |             */
/*---------------------+---+-------------------------+-------------------------+-------------------+-------------+-------------+---------------------+-----------+----------------+----------+----------+-------------*/
TEST_SETZEROVSPRECISION(  1, /* 最小       */ INT_MIN, /* all無効 */       0x00,               0xAA,         0x55,         0xAA, /* 最小 */ INT_MIN  ,       0x00, INT_MIN        , INT_MIN  ,         1, CalcLenZero );
TEST_SETZEROVSPRECISION(  2,                  INT_MIN, /* 無効    */ ~FLAG_ZERO,               0x55,         0xAA,         0x55, /* 中間 */        -1, ~FLAG_ZERO, INT_MIN        ,        -1,         1, CalcLenZero );
TEST_SETZEROVSPRECISION(  3,                  INT_MIN, /* 有効    */  FLAG_ZERO,               0x00,         0x00,         0x00, /* 中間 */         0,  FLAG_ZERO,               0,         0,         1, CalcLenZero );
TEST_SETZEROVSPRECISION(  4,                  INT_MIN, /* all有効 */       0xFF,               0x00,         0x00,         0x00, /* 最大 */ SSIZE_MAX,       0xFF,               0, SSIZE_MAX,         1, CalcLenZero );
/*---------------------+---+-------------------------+-------------------------+-------------------+-------------+-------------+---------------------+-----------+----------------+----------+----------+-------------*/
TEST_SETZEROVSPRECISION(  5, /* 指定無     */      -1, /* all無効 */       0x00, /* 最小 */ INT_MIN, /* 最小 */ 0, /* 最小 */ 0, /* 最小 */ INT_MIN  ,       0x00,              -1, INT_MIN  ,         1, CalcLenZero );
TEST_SETZEROVSPRECISION(  6,                       -1,                     0x00, /* 最大 */ INT_MAX, /* 最大 */ 1, /* 最大 */ 2, /* 中間 */        -2,       0x00,              -1,        -2,         1, CalcLenZero );
/*---------------------+---+                         +-------------------------+-------------------+-------------+-------------+---------------------+-----------+----------------+----------+----------+-------------*/
TEST_SETZEROVSPRECISION(  7,                       -1, /* 無効    */ ~FLAG_ZERO, /* 最小 */ INT_MIN, /* 最小 */ 0, /* 最小 */ 0, /* 中間 */        -1, ~FLAG_ZERO,              -1,        -1,         1, CalcLenZero );
TEST_SETZEROVSPRECISION(  8,                       -1,               ~FLAG_ZERO, /* 最大 */ INT_MAX, /* 最大 */ 1, /* 最大 */ 2, /* 中間 */         0, ~FLAG_ZERO,              -1,         0,         1, CalcLenZero );
/*---------------------+---+                         +-------------------------+-------------------+-------------+-------------+---------------------+-----------+----------------+----------+----------+-------------*/
TEST_SETZEROVSPRECISION(  9,                       -1, /* 有効    */  FLAG_ZERO, /* 最小 */ INT_MIN, /* 最小 */ 0, /* 最小 */ 0, /* 中間 */         1,  FLAG_ZERO, INT_MIN - 0 - 0,         1,         1, CalcLenZero );
TEST_SETZEROVSPRECISION( 10,                       -1,                FLAG_ZERO, /* 最大 */ INT_MAX, /* 最大 */ 1, /* 最大 */ 2, /* 中間 */         2,  FLAG_ZERO, INT_MAX - 1 - 2,         2,         1, CalcLenZero );
/*---------------------+---+                         +-------------------------+-------------------+-------------+-------------+---------------------+-----------+----------------+----------+----------+-------------*/
TEST_SETZEROVSPRECISION( 11,                       -1, /* all有効 */       0xFF, /* 最小 */ INT_MIN, /* 最小 */ 0, /* 最小 */ 0, /* 中間 */         3,       0xFF, INT_MIN - 0 - 0,         3,         1, CalcLenZero );
TEST_SETZEROVSPRECISION( 12,                       -1,                     0xFF, /* 最大 */ INT_MAX, /* 最大 */ 1, /* 最大 */ 2, /* 最大 */ SSIZE_MAX,       0xFF, INT_MAX - 1 - 2, SSIZE_MAX,         1, CalcLenZero );
/*---------------------+---+-------------------------+-------------------------+-------------------+-------------+-------------+---------------------+-----------+----------------+----------+----------+-------------*/
TEST_SETZEROVSPRECISION( 13, /* 指定有 = 0 */       0, /* all無効 */       0x00,               0xAA,         0x55,         0xAA, /* 最小 */ INT_MIN  ,       0x00,               0, INT_MIN  ,         1, CalcLenZero );
TEST_SETZEROVSPRECISION( 14,                        0, /* 無効    */ ~FLAG_ZERO,               0x55,         0xAA,         0x55, /* 中間 */        -1, ~FLAG_ZERO,               0,        -1,         1, CalcLenZero );
TEST_SETZEROVSPRECISION( 15,                        0, /* 有効    */  FLAG_ZERO,               0xAA,         0x55,         0xAA, /* 中間 */         0,       0x00,               0,         0,         1, CalcLenZero );
TEST_SETZEROVSPRECISION( 16,                        0, /* all有効 */       0xFF,               0x55,         0xAA,         0x55, /* 最大 */ SSIZE_MAX, ~FLAG_ZERO,               0, SSIZE_MAX,         1, CalcLenZero );
/*---------------------+---+-------------------------+-------------------------+-------------------+-------------+-------------+---------------------+-----------+----------------+----------+----------+-------------*/
TEST_SETZEROVSPRECISION( 17, /* 指定有 > 0 */       1, /* all無効 */       0x00,               0xAA,         0x55,         0xAA, /* 最小 */ INT_MIN  ,       0x00,               1, INT_MIN  ,         1, CalcLenZero );
TEST_SETZEROVSPRECISION( 18,                        1, /* 無効    */ ~FLAG_ZERO,               0x55,         0xAA,         0x55, /* 中間 */        -1, ~FLAG_ZERO,               1,        -1,         1, CalcLenZero );
TEST_SETZEROVSPRECISION( 19,                        1, /* 有効    */  FLAG_ZERO,               0xAA,         0x55,         0xAA, /* 中間 */         0,       0x00,               1,         0,         1, CalcLenZero );
TEST_SETZEROVSPRECISION( 20,                        1, /* all有効 */       0xFF,               0x55,         0xAA,         0x55, /* 最大 */ SSIZE_MAX, ~FLAG_ZERO,               1, SSIZE_MAX,         1, CalcLenZero );
/*---------------------+---+-------------------------+-------------------------+-------------------+-------------+-------------+---------------------+-----------+----------------+----------+----------+-------------*/
TEST_SETZEROVSPRECISION( 21, /* 指定有最大 */ INT_MAX, /* all無効 */       0x00,               0xAA,         0x55,         0xAA, /* 最小 */ INT_MIN  ,       0x00, INT_MAX        , INT_MIN  ,         1, CalcLenZero );
TEST_SETZEROVSPRECISION( 22,                  INT_MAX, /* 無効    */ ~FLAG_ZERO,               0x55,         0xAA,         0x55, /* 中間 */        -1, ~FLAG_ZERO, INT_MAX        ,        -1,         1, CalcLenZero );
TEST_SETZEROVSPRECISION( 23,                  INT_MAX, /* 有効    */  FLAG_ZERO,               0xAA,         0x55,         0xAA, /* 中間 */         0,       0x00, INT_MAX        ,         0,         1, CalcLenZero );
TEST_SETZEROVSPRECISION( 24,                  INT_MAX, /* all有効 */       0xFF,               0x55,         0xAA,         0x55, /* 最大 */ SSIZE_MAX, ~FLAG_ZERO, INT_MAX        , SSIZE_MAX,         1, CalcLenZero );
/*---------------------+---+-------------------------+-------------------------+-------------------+-------------+-------------+---------------------+-----------+----------------+----------+----------+-------------*/

static void test_SetZeroVsPrecision( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "SetZeroVsPrecision", NULL, NULL );

    CU_add_test( suite, "#_1", test_SetZeroVsPrecision_1  );
    CU_add_test( suite, "#_2", test_SetZeroVsPrecision_2  );
    CU_add_test( suite, "#_3", test_SetZeroVsPrecision_3  );
    CU_add_test( suite, "#_4", test_SetZeroVsPrecision_4  );
    CU_add_test( suite, "#_5", test_SetZeroVsPrecision_5  );
    CU_add_test( suite, "#_6", test_SetZeroVsPrecision_6  );
    CU_add_test( suite, "#_7", test_SetZeroVsPrecision_7  );
    CU_add_test( suite, "#_8", test_SetZeroVsPrecision_8  );
    CU_add_test( suite, "#_9", test_SetZeroVsPrecision_9  );
    CU_add_test( suite, "#10", test_SetZeroVsPrecision_10 );
    CU_add_test( suite, "#11", test_SetZeroVsPrecision_11 );
    CU_add_test( suite, "#12", test_SetZeroVsPrecision_12 );
    CU_add_test( suite, "#13", test_SetZeroVsPrecision_13 );
    CU_add_test( suite, "#14", test_SetZeroVsPrecision_14 );
    CU_add_test( suite, "#15", test_SetZeroVsPrecision_15 );
    CU_add_test( suite, "#16", test_SetZeroVsPrecision_16 );
    CU_add_test( suite, "#17", test_SetZeroVsPrecision_17 );
    CU_add_test( suite, "#18", test_SetZeroVsPrecision_18 );
    CU_add_test( suite, "#19", test_SetZeroVsPrecision_19 );
    CU_add_test( suite, "#20", test_SetZeroVsPrecision_20 );
    CU_add_test( suite, "#21", test_SetZeroVsPrecision_21 );
    CU_add_test( suite, "#22", test_SetZeroVsPrecision_22 );
    CU_add_test( suite, "#23", test_SetZeroVsPrecision_23 );
    CU_add_test( suite, "#24", test_SetZeroVsPrecision_24 );

    return;
}


/******************************************************************************/
/* vsnprintf                                                                  */
/******************************************************************************/
static int test_vsnprintf_main( char       *s,
                                size_t     n,
                                const char *format,
                                ...                 )
{
    int     ret;
    va_list args;

    va_start( args, format );

    ret = vsnprintf( s, n, format, args );

    va_end( args );

    return ret;
}

#define TEST_VSNPRINTF( _NO,                                                            \
                        _IN_S,                                                          \
                        _IN_N,                                                          \
                        _IN_FORMAT,                                                     \
                        _OUT_RET,                                                       \
                        _OUT_S,                                                         \
                        _OUT_CALLCNT,                                                   \
                        _OUT_CALLFUNC_0,                                                \
                        _OUT_POUTPUT,                                                   \
                        _OUT_SIZE,                                                      \
                        _OUT_WRITEIDX,                                                  \
                        _OUT_PINPUT,                                                    \
                        _OUT_READIDX     )                                              \
    static void test_vsnprintf_##_NO( void )                                            \
    {                                                                                   \
        char       s[] = _IN_S;                                                         \
        const char *format;                                                             \
        int        ret;                                                                 \
                                                                                        \
        /* INPUT初期化 */                                                               \
        format = _IN_FORMAT;                                                            \
                                                                                        \
        /* OUTPUT初期化 */                                                              \
        UtilInit();                                                                     \
        param_Convert.pOutputInfo         = NULL;                                       \
        param_Convert.outputInfo.pOutput  = NULL;                                       \
        param_Convert.outputInfo.size     = SIZE_MAX;                                   \
        param_Convert.outputInfo.writeIdx = INT_MAX;                                    \
        param_Convert.pInputInfo          = NULL;                                       \
        param_Convert.inputInfo.pInput    = NULL;                                       \
        param_Convert.inputInfo.readIdx   = INT_MAX;                                    \
                                                                                        \
        ret = test_vsnprintf_main( s, _IN_N, format );                                  \
                                                                                        \
        /* OUTPUT判定 */                                                                \
        CU_ASSERT_EQUAL(        ret,                               _OUT_RET        );   \
        CU_ASSERT_STRING_EQUAL( s,                                 _OUT_S          );   \
        CU_ASSERT_EQUAL(        UtilGetCallCount(),                _OUT_CALLCNT    );   \
        CU_ASSERT_PTR_EQUAL(    UtilGetCallFunc( 0 ),              _OUT_CALLFUNC_0 );   \
        CU_ASSERT_PTR_EQUAL(    param_Convert.outputInfo.pOutput,  _OUT_POUTPUT    );   \
        CU_ASSERT_EQUAL(        param_Convert.outputInfo.size,     _OUT_SIZE       );   \
        CU_ASSERT_EQUAL(        param_Convert.outputInfo.writeIdx, _OUT_WRITEIDX   );   \
        CU_ASSERT_PTR_EQUAL(    param_Convert.inputInfo.pInput,    _OUT_PINPUT     );   \
        CU_ASSERT_EQUAL(        param_Convert.inputInfo.readIdx,   _OUT_READIDX    );   \
                                                                                        \
        return;                                                                         \
    }

/*------------+---+-----------------------------------------+--------------------------------------------------------------------------------------*/
/*            | # | INPUT                                   | OUTPUT                                                                               */
/*            |   +-----+----------------+------------------+-----+------+----------+-----------+------------------------------+-------------------*/
/*            |   | s   | n              | format           | ret | s    | call cnt | call func | pOutputInfo                  | pInputInfo        */
/*            |   |     |                |                  |     |      |          |           +---------+---------+----------+--------+----------*/
/*            |   |     |                |                  |     |      |          |           | pOutput | size    | writeIdx | pInput | readIdx  */
/*------------+---+-----+----------------+------------------+-----+------+----------+-----------+---------+---------+----------+--------+----------*/
TEST_VSNPRINTF(  1, ""  , /* min     */ 0, ""               ,    0, ""   ,         0, NULL      , NULL    , SIZE_MAX,   INT_MAX, NULL   ,  INT_MAX );
TEST_VSNPRINTF(  2, "*" , /* no loop */ 1, ""               ,    0, "\0" ,         0, NULL      , NULL    , SIZE_MAX,   INT_MAX, NULL   ,  INT_MAX );
/*------------+---+-----+----------------+------------------+-----+------+----------+-----------+---------+---------+----------+--------+----------*/
TEST_VSNPRINTF(  3, "*" , /*    loop */ 2, /* break  */ ""  ,    0, "\0" ,         0, NULL      , NULL    , SIZE_MAX,   INT_MAX, NULL   ,  INT_MAX );
TEST_VSNPRINTF(  4, "**", /*    loop */ 2, /* copy   */ "T" ,    1, "T\0",         0, NULL      , NULL    , SIZE_MAX,   INT_MAX, NULL   ,  INT_MAX );
TEST_VSNPRINTF(  5, "**", /*    loop */ 2, /* % copy */ "%T",    1, "T\0",         1, Convert   , s       ,        1,         0, format ,        1 );
TEST_VSNPRINTF(  6, "**", /*    loop */ 3, /* copy % */ "T%",    1, "T\0",         1, Convert   , s       ,        2,         1, format ,        2 );
/*------------+---+-----+----------------+------------------+-----+------+----------+-----------+---------+---------+----------+--------+----------*/

static void test_vsnprintf( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "vsnprintf", NULL, NULL );

    CU_add_test( suite, "#_1", test_vsnprintf_1 );
    CU_add_test( suite, "#_2", test_vsnprintf_2 );
    CU_add_test( suite, "#_3", test_vsnprintf_3 );
    CU_add_test( suite, "#_4", test_vsnprintf_4 );
    CU_add_test( suite, "#_5", test_vsnprintf_5 );
    CU_add_test( suite, "#_6", test_vsnprintf_6 );

    return;
}


/******************************************************************************/
/* テスト対象登録                                                             */
/******************************************************************************/
void stdio_vsnprintf( void )
{
    test_CalcLenZero();
    test_Convert();
    test_ConvertChar();
    test_ConvertPercent();
    test_ConvertSignedInteger();
    test_ConvertString();
    test_ConvertUnsignedInteger();
    test_GetConvertInfo();
    test_GetFlag();
    test_GetLength();
    test_GetPrecision();
    test_GetSpecifier();
    test_GetWidth();
    test_PopSignedInteger();
    test_PopUnsignedInteger();
    test_PutChar();
    test_PutInteger();
    test_PutStr();
    test_SetAlt();
    test_SetInteger();
    test_SetSign();
    test_SetZeroVsPrecision();
    test_vsnprintf();

    return;
}


/******************************************************************************/

