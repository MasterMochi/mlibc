/******************************************************************************/
/*                                                                            */
/* src/stdio/vsnprintf.c                                                      */
/*                                                                 2024/06/22 */
/* Copyright (C) 2023-2024 Mochi.                                             */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/* インクルード                                                               */
/******************************************************************************/
/* 標準ヘッダ */
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* systemヘッダ */
#include <sys/types.h>

/* 共通ヘッダ */
#include <mlibc.h>


/******************************************************************************/
/* 定義                                                                       */
/******************************************************************************/
/* フラグ */
#define FLAG_ALT   ( 0x01 ) /**< 代替形式（#） */
#define FLAG_ZERO  ( 0x02 ) /**< 0埋め（0）    */
#define FLAG_LEFT  ( 0x04 ) /**< 左詰め（-）   */
#define FLAG_SPACE ( 0x08 ) /**< 空白埋め（ ） */
#define FLAG_SIGN  ( 0x10 ) /**< 符号付き（+） */

/* 長さ修飾子 */
#define LENGTH_DEFAULT     ( 0x00 ) /**< 未指定           */
#define LENGTH_CHAR        ( 0x01 ) /**< char（hh）       */
#define LENGTH_SHORT       ( 0x02 ) /**< short（h）       */
#define LENGTH_LONG        ( 0x03 ) /**< long（l）        */
#define LENGTH_LONG_LONG   ( 0x04 ) /**< long long（ll）  */
#define LENGTH_LONG_DOUBLE ( 0x05 ) /**< long double（L） */
#define LENGTH_INTMAX      ( 0x06 ) /**< intmax（j）      */
#define LENGTH_SIZE        ( 0x07 ) /**< size（z）        */
#define LENGTH_PTRDIFF     ( 0x08 ) /**< ptrdiff（Z）     */

/* バッファサイズ */
#define BUFFER_SIZE_INTEGER ( 20 )  /**< 整数文字列バッファサイズ */

/* 大文字小文字 */
#define LOWER_CASE ( 0 )    /**< 小文字 */
#define UPPER_CASE ( 1 )    /**< 大文字 */

/** 出力先情報 */
typedef struct {
    char    *pOutput;   /**< 出力先文字列                      */
    size_t  size;       /**< 出力先最大文字数（\\0を含まない） */
    int     writeIdx;   /**< 書込みインデックス                */
} OutputInfo_t;

/** 入力先情報 */
typedef struct {
    const char *pInput; /**< 書式付き文字列     */
    int        readIdx; /**< 読込みインデックス */
    va_list    args;    /**< 変換元変数リスト   */
} InputInfo_t;

/** 変換情報 */
typedef struct ConvertInfo {
    uint8_t    flag;                        /**< フラグ           */
    uint8_t    length;                      /**< 長さ修飾子       */
    uint8_t    upperLower;                  /**< 大文字小文字     */
    int        width;                       /**< 長さフィールド幅 */
    int        precision;                   /**< 精度             */
    int        base;                        /**< 進数             */
    /** 変換関数 */
    void       ( *pConverter )( OutputInfo_t       *pOutputInfo,
                                InputInfo_t        *pInputInfo,
                                struct ConvertInfo *pConvertInfo );
    char       sign;                        /**< 符号文字         */
    ssize_t    lenSign;                     /**< 符号文字数       */
    const char *pAlt;                       /**< 代替形式文字列   */
    ssize_t    lenAlt;                      /**< 代替形式文字数   */
    char       value[ BUFFER_SIZE_INTEGER ];/**< 数値文字列       */
    ssize_t    lenVal;                      /**< 数値文字数       */
    ssize_t    lenZero;                     /**< 0文字数          */
} ConvertInfo_t;

/** 変換関数型 */
typedef void ( *Converter_t )( OutputInfo_t  *pOutputInfo,
                               InputInfo_t   *pInputInfo,
                               ConvertInfo_t *pConvertInfo );


/******************************************************************************/
/* ローカル関数プロトタイプ宣言                                               */
/******************************************************************************/
MLIBC_PROTO( static ssize_t, CalcLenZero( ConvertInfo_t *pConvertInfo ) );

MLIBC_PROTO( static void, Convert(                OutputInfo_t *pOutputInfo, InputInfo_t *pInputInfo ) );
MLIBC_PROTO( static void, ConvertChar(            OutputInfo_t *pOutputInfo, InputInfo_t *pInputInfo, ConvertInfo_t *pConvertInfo ) );
MLIBC_PROTO( static void, ConvertPercent(         OutputInfo_t *pOutputInfo, InputInfo_t *pInputInfo, ConvertInfo_t *pConvertInfo ) );
MLIBC_PROTO( static void, ConvertSignedInteger(   OutputInfo_t *pOutputInfo, InputInfo_t *pInputInfo, ConvertInfo_t *pConvertInfo ) );
MLIBC_PROTO( static void, ConvertString(          OutputInfo_t *pOutputInfo, InputInfo_t *pInputInfo, ConvertInfo_t *pConvertInfo ) );
MLIBC_PROTO( static void, ConvertUnsignedInteger( OutputInfo_t *pOutputInfo, InputInfo_t *pInputInfo, ConvertInfo_t *pConvertInfo ) );

MLIBC_PROTO( static void, GetConvertInfo( InputInfo_t *pInputInfo, ConvertInfo_t *pConvertInfo ) );
MLIBC_PROTO( static void, GetFlag(        InputInfo_t *pInputInfo, ConvertInfo_t *pConvertInfo ) );
MLIBC_PROTO( static void, GetLength(      InputInfo_t *pInputInfo, ConvertInfo_t *pConvertInfo ) );
MLIBC_PROTO( static void, GetPrecision(   InputInfo_t *pInputInfo, ConvertInfo_t *pConvertInfo ) );
MLIBC_PROTO( static void, GetSpecifier(   InputInfo_t *pInputInfo, ConvertInfo_t *pConvertInfo ) );
MLIBC_PROTO( static void, GetWidth(       InputInfo_t *pInputInfo, ConvertInfo_t *pConvertInfo ) );

MLIBC_PROTO( static          long long, PopSignedInteger(   InputInfo_t *pInputInfo, ConvertInfo_t *pConvertInfo ) );
MLIBC_PROTO( static unsigned long long, PopUnsignedInteger( InputInfo_t *pInputInfo, ConvertInfo_t *pConvertInfo ) );

MLIBC_PROTO( static bool, PutChar(    OutputInfo_t *pOutputInfo, char          c,             ssize_t sizeChar ) );
MLIBC_PROTO( static bool, PutInteger( OutputInfo_t *pOutputInfo, ConvertInfo_t *pConvertInfo ) );
MLIBC_PROTO( static bool, PutStr(     OutputInfo_t *pOutputInfo, const char    *pStr,         ssize_t sizeStr ) );

MLIBC_PROTO( static void, SetAlt(             ConvertInfo_t *pConvertInfo ) );
MLIBC_PROTO( static void, SetInteger(         ConvertInfo_t *pConvertInfo, unsigned long long value ) );
MLIBC_PROTO( static void, SetSign(            ConvertInfo_t *pConvertInfo,          long long value ) );
MLIBC_PROTO( static void, SetZeroVsPrecision( ConvertInfo_t *pConvertInfo ) );


/******************************************************************************/
/* ローカル関数定義                                                           */
/******************************************************************************/
/******************************************************************************/
/**
 * @brief           0文字数計算
 * @details         精度と整数値表示文字数から0文字数を計算する。
 *
 * @param[in]       *pConvertInfo 変換情報
 *
 * @return          0文字数を返す。
 */
/******************************************************************************/
static ssize_t CalcLenZero( ConvertInfo_t *pConvertInfo )
{
    /* 桁数比較 */
    if ( ( ssize_t ) pConvertInfo->precision > pConvertInfo->lenVal ) {
        /* 未達 */

        return ( ssize_t ) pConvertInfo->precision - pConvertInfo->lenVal;

    } else {
        /* 過達 */

        return 0;
    }
}


/******************************************************************************/
/**
 * @brief           変換
 * @details         変換指定を処理する。
 *
 * @param[in,out]   *pOutputInfo 出力先情報
 * @param[in,out]   *pInputInfo  入力先情報
 */
/******************************************************************************/
static void Convert( OutputInfo_t *pOutputInfo,
                     InputInfo_t  *pInputInfo   )
{
    ConvertInfo_t convertInfo;  /* 変換情報   */

    /* 初期化 */
    memset( &convertInfo, 0, sizeof ( ConvertInfo_t ) );

    /* 変換情報取得 */
    MLIBC_CALL( GetConvertInfo( pInputInfo, &convertInfo ) );

    /* 変換判定 */
    if ( convertInfo.pConverter != NULL ) {
        /* 変換有り */

        /* 変換 */
        ( convertInfo.pConverter )( pOutputInfo, pInputInfo, &convertInfo );
    }

    return;
}


/******************************************************************************/
/**
 * @brief           文字変換
 * @details         文字に変換する。
 *
 * @param[in,out]   *pOutputInfo  出力先情報
 * @param[in,out]   *pInputInfo   入力先情報
 * @param[in]       *pConvertInfo 変換情報
 */
/******************************************************************************/
static void ConvertChar( OutputInfo_t  *pOutputInfo,
                         InputInfo_t   *pInputInfo,
                         ConvertInfo_t *pConvertInfo )
{
    char    c;
    ssize_t lenSpace;

    /* 文字取得 */
    c = ( char ) va_arg( pInputInfo->args, int );

    /* 空白文字数計算 */
    lenSpace = ( ssize_t ) pConvertInfo->width - 1;

    /* 右寄せ判定 */
    if ( ( pConvertInfo->flag & FLAG_LEFT ) == 0 ) {
        /* 右寄せ */

        /* 空白出力 */
        MLIBC_CALL( PutChar( pOutputInfo, ' ', lenSpace ) );
    }

    /* 文字出力 */
    MLIBC_CALL( PutChar( pOutputInfo, c, 1 ) );

    /* 左寄せ判定 */
    if ( ( pConvertInfo->flag & FLAG_LEFT ) != 0 ) {
        /* 左寄せ */

        MLIBC_CALL( PutChar( pOutputInfo, ' ', lenSpace ) );
    }

    return;
}


/******************************************************************************/
/**
 * @brief           %変換
 * @details         %に変換する。
 *
 * @param[in,out]   *pOutputInfo  出力先情報
 * @param[in,out]   *pInputInfo   入力先情報(未使用)
 * @param[in]       *pConvertInfo 変換情報(未使用)
 */
/******************************************************************************/
static void ConvertPercent( OutputInfo_t  *pOutputInfo,
                            InputInfo_t   *pInputInfo,
                            ConvertInfo_t *pConvertInfo )
{
    /* %出力 */
    MLIBC_CALL( PutChar( pOutputInfo, '%', 1 ) );

    return;
}


/******************************************************************************/
/**
 * @brief           符号付き整数変換
 * @details         可変長引数を符号付き10進数に変換する。
 *
 * @param[in,out]   *pOutputInfo  出力先情報
 * @param[in,out]   *pInputInfo   入力先情報
 * @param[in]       *pConvertInfo 変換情報
 */
/******************************************************************************/
static void ConvertSignedInteger( OutputInfo_t  *pOutputInfo,
                                  InputInfo_t   *pInputInfo,
                                  ConvertInfo_t *pConvertInfo )
{
    ssize_t   lenAll;   /* 表示文字数 */
    ssize_t   lenSpace; /* 空白文字数 */
    long long value;    /* 数値       */

    /* 初期化 */
    lenAll   = 0;
    lenSpace = 0;
    value    = 0;

    /* 整数値取得 */
    value = MLIBC_CALL( PopSignedInteger( pInputInfo, pConvertInfo ) );

    /* 符号設定 */
    MLIBC_CALL( SetSign( pConvertInfo, value ) );

    /* 整数文字列設定 */
    MLIBC_CALL( SetInteger( pConvertInfo, ( unsigned long long ) llabs( value ) ) );

    /* 0フラグvs精度設定 */
    MLIBC_CALL( SetZeroVsPrecision( pConvertInfo ) );

    /* 表示文字数計算 */
    lenAll = pConvertInfo->lenSign +
             pConvertInfo->lenZero +
             pConvertInfo->lenVal;

    /* 空白文字数計算 */
    lenSpace = ( ssize_t ) pConvertInfo->width - lenAll;

    /* 右寄せ判定 */
    if ( ( pConvertInfo->flag & FLAG_LEFT ) == 0 ) {
        /* 右寄せ */

        /* 空白出力 */
        MLIBC_CALL( PutChar( pOutputInfo, ' ', lenSpace ) );
    }

    /* 符号出力 */
    MLIBC_CALL(
        PutChar( pOutputInfo,
                 pConvertInfo->sign,
                 pConvertInfo->lenSign )
    );

    /* 整数文字列出力 */
    MLIBC_CALL( PutInteger( pOutputInfo, pConvertInfo ) );

    /* 左寄せ判定 */
    if ( ( pConvertInfo->flag & FLAG_LEFT ) != 0 ) {
        /* 左寄せ */

        /* 空白出力 */
        MLIBC_CALL( PutChar( pOutputInfo, ' ', lenSpace ) );
    }

    return;
}


/******************************************************************************/
/**
 * @brief           文字列変換
 * @details         文字列に変換する。
 *
 * @param[in,out]   *pOutputInfo  出力先情報
 * @param[in,out]   *pInputInfo   入力先情報
 * @param[in]       *pConvertInfo 変換情報
 */
/******************************************************************************/
static void ConvertString( OutputInfo_t  *pOutputInfo,
                           InputInfo_t   *pInputInfo,
                           ConvertInfo_t *pConvertInfo )
{
    char    *pStr;
    ssize_t lenStr;
    ssize_t lenSpace;

    /* 文字列取得 */
    pStr = va_arg( pInputInfo->args, char * );

    /* 精度指定判定 */
    if ( pConvertInfo->precision >= 0 ) {
        /* 指定有り */

        /* 指定文字数内の\0までの文字数取得 */
        lenStr = strnlen( pStr, pConvertInfo->precision );

    } else {
        /* 指定無し */

        /* \0までの文字数取得 */
        lenStr = strlen( pStr );
    }

    /* 空白文字数計算 */
    lenSpace = ( ssize_t ) pConvertInfo->width - lenStr;

    /* 右寄せ判定 */
    if ( ( pConvertInfo->flag & FLAG_LEFT ) == 0 ) {
        /* 右寄せ */

        /* 空白出力 */
        MLIBC_CALL( PutChar( pOutputInfo, ' ', lenSpace ) );
    }

    /* 文字列出力 */
    MLIBC_CALL( PutStr( pOutputInfo, pStr, lenStr ) );

    /* 左寄せ判定 */
    if ( ( pConvertInfo->flag & FLAG_LEFT ) != 0 ) {
        /* 左寄せ */

        /* 空白出力 */
        MLIBC_CALL( PutChar( pOutputInfo, ' ', lenSpace ) );
    }

    return;
}


/******************************************************************************/
/**
 * @brief           符号無し整数変換
 * @details         可変長引数を符号無し整数に変換します。
 *
 * @param[in,out]   *pOutputInfo  出力先情報
 * @param[in,out]   *pInputInfo   入力先情報
 * @param[in]       *pConvertInfo 変換情報
 */
/******************************************************************************/
static void ConvertUnsignedInteger( OutputInfo_t  *pOutputInfo,
                                    InputInfo_t   *pInputInfo,
                                    ConvertInfo_t *pConvertInfo )
{
    ssize_t            lenAll;      /* 表示文字数 */
    ssize_t            lenSpace;    /* 空白文字数 */
    unsigned long long value;       /* 数値       */

    /* 初期化 */
    lenAll   = 0;
    lenSpace = 0;
    value    = 0;

    /* 数値取得 */
    value = MLIBC_CALL( PopUnsignedInteger( pInputInfo, pConvertInfo ) );

    /* 代替形式文字列設定 */
    MLIBC_CALL( SetAlt( pConvertInfo ) );

    /* 整数文字列設定 */
    MLIBC_CALL( SetInteger( pConvertInfo, value ) );

    /* 0フラグvs精度設定 */
    MLIBC_CALL( SetZeroVsPrecision( pConvertInfo ) );

    /* 表示文字数計算 */
    lenAll = pConvertInfo->lenAlt  +
             pConvertInfo->lenZero +
             pConvertInfo->lenVal;

    /* 空白文字数計算 */
    lenSpace = ( ssize_t ) pConvertInfo->width - lenAll;

    /* 右寄せ判定 */
    if ( ( pConvertInfo->flag & FLAG_LEFT ) == 0 ) {
        /* 右寄せ */

        /* 空白出力 */
        MLIBC_CALL( PutChar( pOutputInfo, ' ', lenSpace ) );
    }

    /* 代替形式出力 */
    MLIBC_CALL(
        PutStr( pOutputInfo,
                pConvertInfo->pAlt,
                pConvertInfo->lenAlt )
    );

    /* 整数文字列出力 */
    MLIBC_CALL( PutInteger( pOutputInfo, pConvertInfo ) );

    /* 左寄せ判定 */
    if ( ( pConvertInfo->flag & FLAG_LEFT ) != 0 ) {
        /* 左寄せ */

        /* 空白出力 */
        MLIBC_CALL( PutChar( pOutputInfo, ' ', lenSpace ) );
    }

    return;
}


/******************************************************************************/
/**
 * @brief           変換情報取得
 * @details         変換情報を取得する。
 *
 * @param[in,out]   *pInputInfo   入力先情報
 * @param[out]      *pConvertInfo 変換情報
 */
/******************************************************************************/
static void GetConvertInfo( InputInfo_t   *pInputInfo,
                            ConvertInfo_t *pConvertInfo )
{
    /* フラグ取得 */
    MLIBC_CALL( GetFlag( pInputInfo, pConvertInfo ) );

    /* 長さフィールド取得 */
    MLIBC_CALL( GetWidth( pInputInfo, pConvertInfo ) );

    /* 精度取得 */
    MLIBC_CALL( GetPrecision( pInputInfo, pConvertInfo ) );

    /* 長さ修飾子取得 */
    MLIBC_CALL( GetLength( pInputInfo, pConvertInfo ) );

    /* 変換指定子取得 */
    MLIBC_CALL( GetSpecifier( pInputInfo, pConvertInfo ) );

    return;
}


/******************************************************************************/
/**
 * @brief           フラグ取得
 * @details         フラグを取得し変換情報に設定する。
 *
 * @param[in,out]   *pInputInfo   入力先情報
 * @param[out]      *pConvertInfo 変換情報
 */
/******************************************************************************/
static void GetFlag( InputInfo_t   *pInputInfo,
                     ConvertInfo_t *pConvertInfo )
{
    char    c;
    uint8_t flag;

    /* 初期化 */
    flag = 0;

    while( true ) {
        /* 1文字読込み */
        c = pInputInfo->pInput[ pInputInfo->readIdx ];

        if ( c == '#' ) {
            flag |= FLAG_ALT;

        } else if ( c == '0' ) {
            if ( ( flag & FLAG_LEFT ) == 0 ) {
                flag |= FLAG_ZERO;
            }

        } else if ( c == '-' ) {
            flag &= ~FLAG_ZERO;
            flag |= FLAG_LEFT;

        } else if ( c == ' ' ) {
            if ( ( flag & FLAG_SIGN ) == 0 ) {
                flag |= FLAG_SPACE;
            }

        } else if ( c == '+' ) {
            flag &= ~FLAG_SPACE;
            flag |= FLAG_SIGN;

        } else if ( c == '\'' ) {
            /* 未対応 */

        } else if ( c == 'I' ) {
            /* 未対応 */

        } else {
            /* フラグ以外 */
            break;
        }

        /* 次の文字へ */
        ( pInputInfo->readIdx )++;
    }

    /* フラグ設定 */
    pConvertInfo->flag = flag;

    return;
}


/******************************************************************************/
/**
 * @brief           長さ修飾子取得
 * @details         長さ修飾子を取得し変換情報に設定する。
 *
 * @param[in,out]   *pInputInfo   入力先情報
 * @param[out]      *pConvertInfo 変換情報
 */
/******************************************************************************/
static void GetLength( InputInfo_t   *pInputInfo,
                       ConvertInfo_t *pConvertInfo )
{
    char    c;
    uint8_t length;

    /* 1文字読込み */
    c = pInputInfo->pInput[ pInputInfo->readIdx ];

    /* 長さ修飾子判定 */
    if ( c == 'h' ) {
        ( pInputInfo->readIdx )++;

        /* 長さ修飾子2文字目判定 */
        if ( pInputInfo->pInput[ pInputInfo->readIdx ] == 'h' ) {
            ( pInputInfo->readIdx )++;
            length = LENGTH_CHAR;

        } else {
            length = LENGTH_SHORT;
        }

    } else if ( c == 'l' ) {
        ( pInputInfo->readIdx )++;

        /* 長さ修飾子2文字目判定 */
        if ( pInputInfo->pInput[ pInputInfo->readIdx ] == 'l' ) {
            ( pInputInfo->readIdx )++;
            length = LENGTH_LONG_LONG;

        } else {
            length = LENGTH_LONG;
        }

    } else if ( c == 'L' ) {
        ( pInputInfo->readIdx )++;
        length = LENGTH_LONG_DOUBLE;

    } else if ( c == 'j' ) {
        ( pInputInfo->readIdx )++;
        length = LENGTH_INTMAX;

    } else if ( c == 'z' ) {
        ( pInputInfo->readIdx )++;
        length = LENGTH_SIZE;

    } else if ( c == 'Z' ) {
        ( pInputInfo->readIdx )++;
        length = LENGTH_PTRDIFF;

    } else {
        length = LENGTH_DEFAULT;
    }

    /* 変換情報設定 */
    pConvertInfo->length = length;

    return;
}


/******************************************************************************/
/**
 * @brief           精度取得
 * @details         精度を取得し変換情報に設定する。
 *
 * @param[in,out]   *pInputInfo   入力先情報
 * @param[out:      *pConvertInfo 変換情報
 */
/******************************************************************************/
static void GetPrecision( InputInfo_t   *pInputInfo,
                          ConvertInfo_t *pConvertInfo )
{
    char c;
    int  precision;

    /* 初期化 */
    precision               =  0;
    pConvertInfo->precision = -1;

    /* 1文字読込み */
    c = pInputInfo->pInput[ pInputInfo->readIdx ];

    /* 1文字目判定 */
    if ( c != '.' ) {
        /* 精度指定でない */

        return;
    }

    /* 次の文字読込み */
    ( pInputInfo->readIdx )++;
    c = pInputInfo->pInput[ pInputInfo->readIdx ];

    /* 2文字目判定 */
    if ( c == '*' ) {
        /* 引数指定 */

        ( pInputInfo->readIdx )++;

        /* 変換情報設定 */
        pConvertInfo->precision = va_arg( pInputInfo->args, int );

        return;
    }

    /* 数字が続くまで繰り返す */
    while ( ( '0' <= c ) && ( c <= '9' ) ) {
        /* 整数変換 */
        precision               = precision * 10 + ( c - '0' );
        pConvertInfo->precision = precision;

        /* 次の文字読込み */
        ( pInputInfo->readIdx )++;
        c = pInputInfo->pInput[ pInputInfo->readIdx ];
    }

    return;
}


/******************************************************************************/
/**
 * @brief           変換指定子情報取得
 * @details         変換指定子を判定し情報を取得する。
 *
 * @param[in,out]   *pInputInfo   入力先情報
 * @param[out]      *pConvertInfo 変換情報
 */
/******************************************************************************/
static void GetSpecifier( InputInfo_t   *pInputInfo,
                          ConvertInfo_t *pConvertInfo )
{
    char c;

    /* 変換指定子取得 */
    c = pInputInfo->pInput[ pInputInfo->readIdx ];

    /* 変換指定子判定 */
    if ( ( c == 'd' ) || ( c == 'i' ) ) {
        /* 符号付き10進数 */

        ( pInputInfo->readIdx )++;

        /* 変換情報設定 */
        pConvertInfo->base       = 10;
        pConvertInfo->upperLower = LOWER_CASE;
        pConvertInfo->pConverter = ConvertSignedInteger;

    } else if ( c == 'o' ) {
        /* 符号無し8進数 */

        ( pInputInfo->readIdx )++;

        /* 変換情報設定 */
        pConvertInfo->base       = 8;
        pConvertInfo->upperLower = LOWER_CASE;
        pConvertInfo->pConverter = ConvertUnsignedInteger;

    } else if ( c == 'u' ) {
        /* 符号無し10進数 */

        ( pInputInfo->readIdx )++;

        /* 変換情報設定 */
        pConvertInfo->base       = 10;
        pConvertInfo->upperLower = LOWER_CASE;
        pConvertInfo->pConverter = ConvertUnsignedInteger;

    } else if ( c == 'x' ) {
        /* 符号無し16進数(小文字) */

        ( pInputInfo->readIdx )++;

        pConvertInfo->base       = 16;
        pConvertInfo->upperLower = LOWER_CASE;
        pConvertInfo->pConverter = ConvertUnsignedInteger;

    } else if ( c == 'X' ) {
        /* 符号無し16進数(大文字) */

        ( pInputInfo->readIdx )++;

        /* 変更情報設定 */
        pConvertInfo->base       = 16;
        pConvertInfo->upperLower = UPPER_CASE;
        pConvertInfo->pConverter = ConvertUnsignedInteger;

    } else if ( c == 'c' ) {
        /* 文字 */

        ( pInputInfo->readIdx )++;

        pConvertInfo->pConverter = ConvertChar;

    } else if ( c == 's' ) {
        /* 文字列 */

        ( pInputInfo->readIdx )++;

        pConvertInfo->pConverter = ConvertString;

    } else if ( c == 'p' ) {
        /* ポインタ */

        ( pInputInfo->readIdx )++;

        pConvertInfo->base        = 16;
        pConvertInfo->upperLower  = LOWER_CASE;
        pConvertInfo->flag       |= FLAG_ALT;
        pConvertInfo->pConverter  = ConvertUnsignedInteger;

    } else if ( c == '%' ) {
        /* % */

        ( pInputInfo->readIdx )++;

        pConvertInfo->pConverter = ConvertPercent;

    } else {
        /* 未定義 */

        /* 変換情報設定 */
        pConvertInfo->pConverter = NULL;
    }

    return;
}


/******************************************************************************/
/**
 * @brief           長さフィールド幅取得
 * @details         長さフィールド幅を取得し変換情報に設定する。
 *
 * @param[in,out]   *pInputInfo   入力先情報
 * @param[out]      *pConvertInfo 変換情報
 */
/******************************************************************************/
static void GetWidth( InputInfo_t   *pInputInfo,
                      ConvertInfo_t *pConvertInfo )
{
    char c;
    int  width;

    /* 初期化 */
    width               =  0;
    pConvertInfo->width = -1;

    /* 1文字読込み */
    c = pInputInfo->pInput[ pInputInfo->readIdx ];

    /* 1文字目判定 */
    if ( c == '*' ) {
        /* 引数指定 */

        ( pInputInfo->readIdx )++;

        /* 変換情報設定 */
        pConvertInfo->width = va_arg( pInputInfo->args, int );

        return;
    }

    /* 数字が続くまで繰り返す */
    while ( ( '0' <= c ) && ( c <= '9' ) ) {
        /* 整数変換 */
        width               = width * 10 + ( c - '0' );
        pConvertInfo->width = width;

        /* 次の文字読込み */
        ( pInputInfo->readIdx )++;
        c = pInputInfo->pInput[ pInputInfo->readIdx ];
    }

    return;
}


/******************************************************************************/
/**
 * @brief           符号付き引数値取得
 * @details         長さ修飾子に基づき符号付き引数値を取得する。
 *
 * @param[in,out]   *pInputInfo   入力先情報
 * @param[out]      *pConvertInfo 変換情報
 *
 * @return          引数値を返す。
 */
/******************************************************************************/
static long long PopSignedInteger( InputInfo_t   *pInputInfo,
                                   ConvertInfo_t *pConvertInfo )
{
    long long ret;

    /* 初期化 */
    ret = 0;

    /* 長さ修飾子判定 */
    if ( pConvertInfo->length == LENGTH_CHAR ) {
        /* hh */
        ret = ( long long ) va_arg( pInputInfo->args, int );

    } else if ( pConvertInfo->length == LENGTH_SHORT ) {
        /* h */
        ret = ( long long ) va_arg( pInputInfo->args, int );

    } else if ( pConvertInfo->length == LENGTH_LONG ) {
        /* l */
        ret =  ( long long ) va_arg( pInputInfo->args, long );

    } else if ( pConvertInfo->length == LENGTH_LONG_LONG ) {
        /* ll */
        ret =  va_arg( pInputInfo->args, long long );

    } else if ( pConvertInfo->length == LENGTH_INTMAX ) {
        /* j */
        ret =  ( long long ) va_arg( pInputInfo->args, intmax_t );

    } else if ( pConvertInfo->length == LENGTH_SIZE ) {
        /* z */
        ret =  ( long long ) va_arg( pInputInfo->args, size_t );

    } else if ( pConvertInfo->length == LENGTH_PTRDIFF ) {
        /* Z */
        ret =  ( long long ) va_arg( pInputInfo->args, ptrdiff_t );

    } else {
        /* 他 */
        ret = ( long long ) va_arg( pInputInfo->args, int );
    }

    return ret;
}


/******************************************************************************/
/**
 * @brief           符号無し引数値取得
 * @details         長さ修飾子に基づき符号無し引数値を取得する。
 *
 * @param[in,out]   *pInputInfo   入力先情報
 * @param[out]      *pConvertInfo 変換情報
 *
 * @return          引数値を返す。
 */
/******************************************************************************/
static unsigned long long PopUnsignedInteger( InputInfo_t   *pInputInfo,
                                              ConvertInfo_t *pConvertInfo )
{
    unsigned long long ret;

    /* 初期化 */
    ret = 0;

    /* 長さ修飾子判定 */
    if ( pConvertInfo->length == LENGTH_CHAR ) {
        /* hh */
        ret = ( unsigned long long ) va_arg( pInputInfo->args, unsigned int );

    } else if ( pConvertInfo->length == LENGTH_SHORT ) {
        /* h */
        ret = ( unsigned long long ) va_arg( pInputInfo->args, unsigned int );

    } else if ( pConvertInfo->length == LENGTH_LONG ) {
        /* l */
        ret =  ( unsigned long long ) va_arg( pInputInfo->args, unsigned long );

    } else if ( pConvertInfo->length == LENGTH_LONG_LONG ) {
        /* ll */
        ret =  va_arg( pInputInfo->args, unsigned long long );

    } else if ( pConvertInfo->length == LENGTH_INTMAX ) {
        /* j */
        ret =  ( unsigned long long ) va_arg( pInputInfo->args, intmax_t );

    } else if ( pConvertInfo->length == LENGTH_SIZE ) {
        /* z */
        ret =  ( unsigned long long ) va_arg( pInputInfo->args, size_t );

    } else if ( pConvertInfo->length == LENGTH_PTRDIFF ) {
        /* Z */
        ret =  ( unsigned long long ) va_arg( pInputInfo->args, ptrdiff_t );

    } else {
        /* 他 */
        ret = ( unsigned long long ) va_arg( pInputInfo->args, unsigned int );
    }

    return ret;
}


/******************************************************************************/
/**
 * @brief           文字出力
 * @details         文字を指定文字数出力する。
 *
 * @param[in,out]   *pOutputInfo 出力先情報
 * @param[in]       c            文字
 * @param[in]       sizeChar     文字数
 */
/******************************************************************************/
static bool PutChar( OutputInfo_t *pOutputInfo,
                     char         c,
                     ssize_t      sizeChar      )
{
    ssize_t cnt;

    /* 1文字毎に繰り返し */
    for ( cnt = 0; cnt < sizeChar; cnt++ ) {
        /* 最大出力先文字数判定 */
        if ( pOutputInfo->writeIdx >= pOutputInfo->size ) {
            /* 超過 */
            return false;
        }

        /* 1文字出力 */
        pOutputInfo->pOutput[ pOutputInfo->writeIdx++ ] = c;
    }

    return true;
}


/******************************************************************************/
/**
 * @brief           整数文字列出力
 * @details         整数文字列を出力する。
 *
 * @param[in,out]   *pOutputInfo  出力先情報
 * @param[in]       *pConvertInfo 変換情報
 */
/******************************************************************************/
static bool PutInteger( OutputInfo_t  *pOutputInfo,
                        ConvertInfo_t *pConvertInfo )
{
    bool    ret;
    ssize_t topIdx;

    /* 初期化 */
    ret    = false;
    topIdx = BUFFER_SIZE_INTEGER - pConvertInfo->lenVal;

    /* 0出力 */
    MLIBC_CALL( PutChar( pOutputInfo, '0', pConvertInfo->lenZero ) );

    /* 整数文字列出力 */
    ret =
        MLIBC_CALL(
            PutStr( pOutputInfo,
                    &( pConvertInfo->value[ topIdx ] ),
                    pConvertInfo->lenVal                )
        );

    return ret;
}


/******************************************************************************/
/**
 * @brief           文字列出力
 * @details         文字列を指定文字数出力する。
 *
 * @param[in,out]   *pOutputInfo 出力先情報
 * @param[in]       *pStr        文字列
 * @param[in]       sizeStr      出力文字数
 */
/******************************************************************************/
static bool PutStr( OutputInfo_t *pOutputInfo,
                    const char   *pStr,
                    ssize_t      sizeStr       )
{
    size_t cnt;

    /* 1文字毎に繰り返し */
    for ( cnt = 0; cnt < sizeStr; cnt++ ) {
        /* 最大出力先文字数判定 */
        if ( pOutputInfo->writeIdx >= pOutputInfo->size ) {
            /* 超過 */
            return false;
        }

        /* 1文字出力 */
        pOutputInfo->pOutput[ pOutputInfo->writeIdx++ ] = pStr[ cnt ];
    }

    return true;
}


/******************************************************************************/
/**
 * @brief           代替形式文字列設定
 * @details         代替形式の文字列を設定する。
 *
 * @param[in,out]   *pConvertInfo 変換情報
 */
/******************************************************************************/
static void SetAlt( ConvertInfo_t *pConvertInfo )
{
    const static char alt[ 2 ][ 3 ] = { { "0x" }, { "0X" } };

    /* 初期化 */
    pConvertInfo->pAlt   = "";
    pConvertInfo->lenAlt = 0;

    /* 代替形式フラグ判定 */
    if ( ( pConvertInfo->flag & FLAG_ALT ) != 0 ) {
        /* 有効 */

        /* 進数判定 */
        if ( pConvertInfo->base == 8 ) {
            /* 8進数 */

            pConvertInfo->pAlt   = "0";
            pConvertInfo->lenAlt = 1;

        } else if ( pConvertInfo->base == 16 ) {
            /* 16進数 */

            pConvertInfo->pAlt   = alt[ pConvertInfo->upperLower ];
            pConvertInfo->lenAlt = 2;

        } else {
            /* nothing */
        }
    }

    return;
}


/******************************************************************************/
/**
 * @brief           整数文字列設定
 * @details         整数を文字列に変換する。
 *
 * @param[in, out]  *pConvertInfo 変換情報
 * @param[in]       value         整数値
 */
/******************************************************************************/
static void SetInteger( ConvertInfo_t      *pConvertInfo,
                        unsigned long long value          )
{
    int               base;
    char              *pStr;
    ssize_t           *pLenVal;
    const static char *pDigits;
    const static char digits[ 2 ][ 17 ] = { { "0123456789abcdef" },
                                            { "0123456789ABCDEF" }  };

    /* 初期化 */
    base     = pConvertInfo->base;
    pStr     = pConvertInfo->value;
    pLenVal  = &pConvertInfo->lenVal;
    *pLenVal = 0;
    pDigits  = digits[ pConvertInfo->upperLower ];

    /* 1桁毎に繰り返す */
    do {
        /* 文字数インクリメント */
        ( *pLenVal )++;

        /* 変換 */
        pStr[ BUFFER_SIZE_INTEGER - *pLenVal ] = pDigits[ value % base ];

        /* 次の桁へ */
        value /= base;

    } while ( ( value != 0 ) && ( *pLenVal < BUFFER_SIZE_INTEGER ) );

    return;
}


/******************************************************************************/
/**
 * @brief           符号文字設定
 * @details         符号を文字に変換する。
 *
 * @param[in,out]   *pConvertInfo 変換情報
 * @param[in]       value         整数値
 */
/******************************************************************************/
static void SetSign( ConvertInfo_t *pConvertInfo,
                     long long     value          )
{
    /* 符号判定 */
    if ( value < 0 ) {
        /* 負数 */

        pConvertInfo->sign    = '-';
        pConvertInfo->lenSign = 1;

    } else {
        /* 正数 */

        /* フラグ判定 */
        if ( ( pConvertInfo->flag & FLAG_SIGN ) != 0 ) {
            /* + */

            pConvertInfo->sign    = '+';
            pConvertInfo->lenSign = 1;

        } else if ( ( pConvertInfo->flag & FLAG_SPACE ) != 0 ) {
            /* space */

            pConvertInfo->sign    = ' ';
            pConvertInfo->lenSign = 1;

        } else {

            pConvertInfo->sign    = 0;
            pConvertInfo->lenSign = 0;
        }
    }

    return;
}


/******************************************************************************/
/**
 * @brief           0フラグvs精度設定
 * @details         精度が指定されている場合に0フラグを無効化する。0フラグが有
 *                  効で精度が指定されていない場合は、精度を設定する。また、0文
 *                  字数(不足桁数)を設定する。
 *
 * @param[in,out]   *pConvertInfo 変換情報
 *
 * @note            - 関数SetSign()の後に呼び出すこと
 *                  - 関数SetAlt()の後に呼び出すこと
 *                  - 関数SetInteger()の後に呼び出すこと
 */
/******************************************************************************/
static void SetZeroVsPrecision( ConvertInfo_t *pConvertInfo )
{
    /* 精度指定判定 */
    if ( pConvertInfo->precision >= 0 ) {
        /* 指定有り */

        /* 0フラグ無効化 */
        pConvertInfo->flag &= ~FLAG_ZERO;
    }

    /* 0フラグ判定 */
    if ( ( pConvertInfo->flag & FLAG_ZERO ) != 0 ) {
        /* 有効 */

        /* 最小桁数設定 */
        pConvertInfo->precision =         pConvertInfo->width   -
                                  ( int ) pConvertInfo->lenSign -
                                  ( int ) pConvertInfo->lenAlt;
    }

    /* 0文字数設定 */
    pConvertInfo->lenZero = MLIBC_CALL( CalcLenZero( pConvertInfo ) );

    return;
}


/******************************************************************************/
/* グローバル関数定義                                                         */
/******************************************************************************/
/******************************************************************************/
/**
 * @brief       vsnprintf
 * @details     書式付き文字列と可変長引数リストから文字列を出力する。文字列は
 *              文字列終端文字\\0を含めた最大出力文字数分を出力する。
 *
 * @param[out]  *s      出力先文字列
 * @param[in]   n       最大出力文字数（\\0を含む）
 * @param[in]   *format 書式付き文字列
 * @param[in]   arg     可変長引数リスト
 *
 * @return      出力文字数（\\0を含まない）を返す。
 */
/******************************************************************************/
int vsnprintf( char       *s,
               size_t     n,
               const char *format,
               va_list    arg      )
{
    InputInfo_t  inputInfo;     /* 入力先情報 */
    OutputInfo_t outputInfo;    /* 出力先情報 */

    /* 最大出力文字数0判定 */
    if ( n == 0 ) {

        return 0;

    }

    /* 入力先情報設定 */
    inputInfo.pInput  = format;
    inputInfo.readIdx = 0;
    va_copy( inputInfo.args, arg );

    /* 出力先情報設定 */
    outputInfo.pOutput  = s;
    outputInfo.size     = n - 1;
    outputInfo.writeIdx = 0;

    /* 1文字毎に繰り返す */
    while ( outputInfo.writeIdx < outputInfo.size ) {

        /* 文字判定 */
        if ( inputInfo.pInput[ inputInfo.readIdx ] == '%' ) {
            /* 変換指定 */

            inputInfo.readIdx++;
            MLIBC_CALL( Convert( &outputInfo, &inputInfo ) );

        } else if ( inputInfo.pInput[ inputInfo.readIdx ] == '\0' ) {
            /* null文字 */

            break;

        } else {
            /* その他 */

            /* 1文字コピー */
            outputInfo.pOutput[ outputInfo.writeIdx++ ] =
                inputInfo.pInput[ inputInfo.readIdx++ ];
        }

    }

    /* 文字列終端文字書込み */
    outputInfo.pOutput[ outputInfo.writeIdx ] = '\0';

    va_end( inputInfo.args );

    return outputInfo.writeIdx;
}


/******************************************************************************/
