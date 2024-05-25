/******************************************************************************/
/*                                                                            */
/* integ_test/stdio/vsnprintf.c                                               */
/*                                                                 2024/05/02 */
/* Copyright (C) 2024 Mochi.                                                  */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/* インクルード                                                               */
/******************************************************************************/
/* 標準ヘッダ */
#include <stdarg.h>

/* cunitヘッダ */
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>


/******************************************************************************/
/* 定義                                                                       */
/******************************************************************************/
#define SUITE_PREFIX "stdio/vsnprintf@"
#define vsnprintf _vsnprintf

/******************************************************************************/
/* テスト対象ファイル                                                         */
/******************************************************************************/
#include "stdio/vsnprintf.c"


/******************************************************************************/
/* vsnprintf                                                                  */
/******************************************************************************/
int test_vsnprintf_main( char       *s,
                         size_t     n,
                         const char *format,
                         ...                 )
{
    int     ret;
    va_list arg;

    va_start( arg, format );

    ret = vsnprintf( s, n, format, arg );

    va_end( arg );

    return ret;
}

#define TEST_VSNPRINTF( _NO,                                                \
                        _IN_N,                                              \
                        _IN_FORMAT,                                         \
                        _OUT_RET,                                           \
                        _OUT_S,                                             \
                        ...         )                                       \
    static void test_vsnprintf_##_NO( void )                                \
    {                                                                       \
        unsigned int  i;                                                    \
        int           ret;                                                  \
        char          s[ _IN_N + 1 ];                                       \
                                                                            \
        /* INPUT初期化 */                                                   \
        for ( i = 0; i < _IN_N + 1; i++ ) {                                 \
            s[ i ] = 0;                                                     \
        }                                                                   \
                                                                            \
        ret = test_vsnprintf_main( s, _IN_N, _IN_FORMAT, ##__VA_ARGS__ );   \
                                                                            \
        /* OUTPUT判定 */                                                    \
        CU_ASSERT_EQUAL(        ret, _OUT_RET );                            \
        CU_ASSERT_STRING_EQUAL( s,   _OUT_S   );                            \
                                                                            \
        printf( "[%s]...", s );                                             \
        return;                                                             \
    }

/*            | # | INPUT           | OUTPUT                  | INPUT      */
/*            |   | n | format      | ret | s                 | ...        */
TEST_VSNPRINTF(  1,  0, "DUMMY"     ,    0, ""                             );
TEST_VSNPRINTF(  2, 11, "1234567890",   10, "1234567890"                   );

TEST_VSNPRINTF(  3, 12, "%d."       ,   11, "1234567890."     , 1234567890 );
TEST_VSNPRINTF(  4, 12, "%i."       ,   11, "1234567890."     , 1234567890 );
TEST_VSNPRINTF(  5, 10, "%o."       ,    9, "12345670."       ,  012345670 );
TEST_VSNPRINTF(  6,  9, "%x."       ,    8, "abcdef0."        ,  0xabcdef0 );
TEST_VSNPRINTF(  7,  9, "%X."       ,    8, "ABCDEF0."        ,  0xABCDEF0 );
TEST_VSNPRINTF(  8,  3, "%c."       ,    2, "Z."              , 'Z'        );
TEST_VSNPRINTF(  9,  8, "%s."       ,    7, "String."         , "String"   );
TEST_VSNPRINTF( 10, 12, "%p."       ,   11, "0x55aa55aa."     , 0x55AA55AA );
TEST_VSNPRINTF( 11,  3, "%%."       ,    2, "%."                           );

TEST_VSNPRINTF( 12, 17, "%15d."     ,   16, "     1234567890.", 1234567890 );
TEST_VSNPRINTF( 13, 17, "%15i."     ,   16, "     1234567890.", 1234567890 );
TEST_VSNPRINTF( 14, 17, "%15o."     ,   16, "       12345670.",  012345670 );
TEST_VSNPRINTF( 15, 17, "%15x."     ,   16, "        abcdef0.",  0xabcdef0 );
TEST_VSNPRINTF( 16, 17, "%15X."     ,   16, "        ABCDEF0.",  0XABCDEF0 );
TEST_VSNPRINTF( 17, 17, "%15c."     ,   16, "              Z.", 'Z'        );
TEST_VSNPRINTF( 18, 17, "%15s."     ,   16, "         String.", "String"   );
TEST_VSNPRINTF( 19, 17, "%15p."     ,   16, "     0x55aa55aa.", 0x55AA55AA );
TEST_VSNPRINTF( 20,  3, "%15%."     ,    2, "%."                           );

TEST_VSNPRINTF( 21, 12, "%#d."      ,   11, "1234567890."     , 1234567890 );
TEST_VSNPRINTF( 22, 12, "%#i."      ,   11, "1234567890."     , 1234567890 );
TEST_VSNPRINTF( 23, 11, "%#o."      ,   10, "012345670."      ,  012345670 );
TEST_VSNPRINTF( 24, 11, "%#x."      ,   10, "0xabcdef0."      ,  0xabcdef0 );
TEST_VSNPRINTF( 25, 11, "%#X."      ,   10, "0XABCDEF0."      ,  0XABCDEF0 );
TEST_VSNPRINTF( 26,  3, "%#c."      ,    2, "Z."              , 'Z'        );
TEST_VSNPRINTF( 27,  8, "%#s."      ,    7, "String."         , "String"   );
TEST_VSNPRINTF( 28, 12, "%#p."      ,   11, "0x55aa55aa."     , 0x55AA55AA );
TEST_VSNPRINTF( 29,  3, "%#%."      ,    2, "%."                           );

TEST_VSNPRINTF( 30, 17, "%015d."    ,   16, "000001234567890.", 1234567890 );
TEST_VSNPRINTF( 31, 17, "%015i."    ,   16, "000001234567890.", 1234567890 );
TEST_VSNPRINTF( 32, 17, "%015o."    ,   16, "000000012345670.",  012345670 );
TEST_VSNPRINTF( 33, 17, "%015x."    ,   16, "00000000abcdef0.",  0xabcdef0 );
TEST_VSNPRINTF( 34, 17, "%015X."    ,   16, "00000000ABCDEF0.",  0XABCDEF0 );
TEST_VSNPRINTF( 35, 17, "%015c."    ,   16, "              Z.", 'Z'        );
TEST_VSNPRINTF( 36, 17, "%015s."    ,   16, "         String.", "String"   );
TEST_VSNPRINTF( 37, 17, "%015p."    ,   16, "0x0000055aa55aa.", 0x55AA55AA );
TEST_VSNPRINTF( 38,  3, "%015%."    ,    2, "%."                           );

TEST_VSNPRINTF( 39, 17, "%-015d."   ,   16, "1234567890     .", 1234567890 );
TEST_VSNPRINTF( 40, 17, "%-015i."   ,   16, "1234567890     .", 1234567890 );
TEST_VSNPRINTF( 41, 17, "%-015o."   ,   16, "12345670       .",  012345670 );
TEST_VSNPRINTF( 42, 17, "%-015x."   ,   16, "abcdef0        .",  0xabcdef0 );
TEST_VSNPRINTF( 43, 17, "%-015X."   ,   16, "ABCDEF0        .",  0xABCDEF0 );
TEST_VSNPRINTF( 44, 17, "%-015c."   ,   16, "Z              .", 'Z'        );
TEST_VSNPRINTF( 45, 17, "%-015s."   ,   16, "String         .", "String"   );
TEST_VSNPRINTF( 46, 17, "%-015p."   ,   16, "0x55aa55aa     .", 0x55AA55AA );
TEST_VSNPRINTF( 47,  3, "%-015%."   ,    2, "%."                           );

TEST_VSNPRINTF( 48, 13, "% d."      ,   12, " 1234567890."    , 1234567890 );
TEST_VSNPRINTF( 49, 13, "% i."      ,   12, " 1234567890."    , 1234567890 );
TEST_VSNPRINTF( 50, 10, "% o."      ,    9, "12345670."       ,  012345670 );
TEST_VSNPRINTF( 51,  9, "% x."      ,    8, "abcdef0."        ,  0xabcdef0 );
TEST_VSNPRINTF( 52,  9, "% X."      ,    8, "ABCDEF0."        ,  0XABCDEF0 );
TEST_VSNPRINTF( 53,  3, "% c."      ,    2, "Z."              , 'Z'        );
TEST_VSNPRINTF( 54,  8, "% s."      ,    7, "String."         , "String"   );
TEST_VSNPRINTF( 55, 12, "% p."      ,   11, "0x55aa55aa."     , 0x55AA55AA );
TEST_VSNPRINTF( 56,  3, "% %."      ,    2, "%."                           );

TEST_VSNPRINTF( 57, 13, "%+ d."     ,   12, "+1234567890."    , 1234567890 );
TEST_VSNPRINTF( 58, 13, "%+ i."     ,   12, "+1234567890."    , 1234567890 );
TEST_VSNPRINTF( 59, 10, "%+ o."     ,    9, "12345670."       ,  012345670 );
TEST_VSNPRINTF( 60,  9, "%+ x."     ,    8, "abcdef0."        ,  0xabcdef0 );
TEST_VSNPRINTF( 61,  9, "%+ X."     ,    8, "ABCDEF0."        ,  0xABCDEF0 );
TEST_VSNPRINTF( 62,  3, "%+ c."     ,    2, "Z."              , 'Z'        );
TEST_VSNPRINTF( 63,  8, "%+ s."     ,    7, "String."         , "String"   );
TEST_VSNPRINTF( 64, 12, "%+ p."     ,   11, "0x55aa55aa."     , 0x55AA55AA );
TEST_VSNPRINTF( 65,  3, "%+ %."     ,    2, "%."                           );

static void test_vsnprintf( void )
{
    CU_pSuite suite = CU_add_suite( SUITE_PREFIX "vsnprintf", NULL, NULL );

    CU_add_test( suite, "#_1", test_vsnprintf_1  );
    CU_add_test( suite, "#_2", test_vsnprintf_2  );
    CU_add_test( suite, "#_3", test_vsnprintf_3  );
    CU_add_test( suite, "#_4", test_vsnprintf_4  );
    CU_add_test( suite, "#_5", test_vsnprintf_5  );
    CU_add_test( suite, "#_6", test_vsnprintf_6  );
    CU_add_test( suite, "#_7", test_vsnprintf_7  );
    CU_add_test( suite, "#_8", test_vsnprintf_8  );
    CU_add_test( suite, "#_9", test_vsnprintf_9  );
    CU_add_test( suite, "#10", test_vsnprintf_10 );
    CU_add_test( suite, "#11", test_vsnprintf_11 );
    CU_add_test( suite, "#12", test_vsnprintf_12 );
    CU_add_test( suite, "#13", test_vsnprintf_13 );
    CU_add_test( suite, "#14", test_vsnprintf_14 );
    CU_add_test( suite, "#15", test_vsnprintf_15 );
    CU_add_test( suite, "#16", test_vsnprintf_16 );
    CU_add_test( suite, "#17", test_vsnprintf_17 );
    CU_add_test( suite, "#18", test_vsnprintf_18 );
    CU_add_test( suite, "#19", test_vsnprintf_19 );
    CU_add_test( suite, "#20", test_vsnprintf_20 );
    CU_add_test( suite, "#21", test_vsnprintf_21 );
    CU_add_test( suite, "#22", test_vsnprintf_22 );
    CU_add_test( suite, "#23", test_vsnprintf_23 );
    CU_add_test( suite, "#24", test_vsnprintf_24 );
    CU_add_test( suite, "#25", test_vsnprintf_25 );
    CU_add_test( suite, "#26", test_vsnprintf_26 );
    CU_add_test( suite, "#27", test_vsnprintf_27 );
    CU_add_test( suite, "#28", test_vsnprintf_28 );
    CU_add_test( suite, "#29", test_vsnprintf_29 );
    CU_add_test( suite, "#30", test_vsnprintf_30 );
    CU_add_test( suite, "#31", test_vsnprintf_31 );
    CU_add_test( suite, "#32", test_vsnprintf_32 );
    CU_add_test( suite, "#33", test_vsnprintf_33 );
    CU_add_test( suite, "#34", test_vsnprintf_34 );
    CU_add_test( suite, "#35", test_vsnprintf_35 );
    CU_add_test( suite, "#36", test_vsnprintf_36 );
    CU_add_test( suite, "#37", test_vsnprintf_37 );
    CU_add_test( suite, "#38", test_vsnprintf_38 );
    CU_add_test( suite, "#39", test_vsnprintf_39 );
    CU_add_test( suite, "#40", test_vsnprintf_40 );
    CU_add_test( suite, "#41", test_vsnprintf_41 );
    CU_add_test( suite, "#42", test_vsnprintf_42 );
    CU_add_test( suite, "#43", test_vsnprintf_43 );
    CU_add_test( suite, "#44", test_vsnprintf_44 );
    CU_add_test( suite, "#45", test_vsnprintf_45 );
    CU_add_test( suite, "#46", test_vsnprintf_46 );
    CU_add_test( suite, "#47", test_vsnprintf_47 );
    CU_add_test( suite, "#48", test_vsnprintf_48 );
    CU_add_test( suite, "#49", test_vsnprintf_49 );
    CU_add_test( suite, "#50", test_vsnprintf_50 );
    CU_add_test( suite, "#51", test_vsnprintf_51 );
    CU_add_test( suite, "#52", test_vsnprintf_52 );
    CU_add_test( suite, "#53", test_vsnprintf_53 );
    CU_add_test( suite, "#54", test_vsnprintf_54 );
    CU_add_test( suite, "#55", test_vsnprintf_55 );
    CU_add_test( suite, "#56", test_vsnprintf_56 );
    CU_add_test( suite, "#57", test_vsnprintf_57 );
    CU_add_test( suite, "#58", test_vsnprintf_58 );
    CU_add_test( suite, "#59", test_vsnprintf_59 );
    CU_add_test( suite, "#60", test_vsnprintf_60 );
    CU_add_test( suite, "#61", test_vsnprintf_61 );
    CU_add_test( suite, "#62", test_vsnprintf_62 );
    CU_add_test( suite, "#63", test_vsnprintf_63 );
    CU_add_test( suite, "#64", test_vsnprintf_64 );
    CU_add_test( suite, "#65", test_vsnprintf_65 );

    return;
}

/******************************************************************************/
/* テスト対象登録                                                             */
/******************************************************************************/
void stdio_vsnprintf( void )
{
    test_vsnprintf();

    return;
}


/******************************************************************************/

