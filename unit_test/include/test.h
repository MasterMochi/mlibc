/******************************************************************************/
/*                                                                            */
/* unit_test/include/test.h                                                   */
/*                                                                 2024/04/30 */
/* Copyright (C) 2024 Mochi.                                                  */
/*                                                                            */
/******************************************************************************/
#ifndef _TEST_H_
#define _TEST_H_
/******************************************************************************/
/* 定義                                                                       */
/******************************************************************************/
/** 関数プロトタイプ宣言スタブ化マクロ */
#define MLIBC_PROTO( _SPECS, _DECL ) _SPECS stub_##_DECL

/** 関数呼出しスタブ化マクロ */
#define MLIBC_CALL( _FUNC ) stub_##_FUNC


/******************************************************************************/
/* 関数プロトタイプ宣言                                                       */
/******************************************************************************/
/*-------*/
/* stdio */
/*-------*/
extern void stdio_vsnprintf( void );


/*--------*/
/* util.c */
/*--------*/
extern unsigned int UtilGetCallCount( void );
extern void *UtilGetCallFunc( unsigned int no );
extern void UtilInit( void );
extern void UtilInitCallCount( void );
extern unsigned int UtilSetCallCount( void *pFunc );


/******************************************************************************/
#endif

