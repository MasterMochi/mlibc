#******************************************************************************#
#*                                                                            *#
#* unit_test/Makefile                                                         *#
#*                                                                 2024/04/30 *#
#* Copyright (C) 2024 Mochi.                                                  *#
#*                                                                            *#
#******************************************************************************#
#******************************************************************************#
#* 設定                                                                       *#
#******************************************************************************#
# プログラム名
PROG = mlibc

# ソースコード
SRCS  = main.c
SRCS += util.c
SRCS += stdio/vsnprintf.c

# ビルドディレクトリ
BUILD_DIR   = ../build/unit_test
# リリースディレクトリ
RELEASE_DIR = $(BUILD_DIR)
# オブジェクトディレクトリ
OBJ_DIR     = $(BUILD_DIR)

# Cフラグ
CFLAGS  = -Iinclude
CFLAGS += -I../src
CFLAGS += -I../src/include
CFLAGS += -coverage
CFLAGS += -Wall

# ライブラリ
LIBS = -lcunit


#******************************************************************************#
#* 定義                                                                       *#
#******************************************************************************#
# オブジェクトサブディレクトリ
OBJ_SUBDIRS = $(sort $(addprefix $(OBJ_DIR)/, $(dir $(SRCS))))

# オブジェクトファイル
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# 依存関係ファイル
DEPS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.d))

# gcovファイル
GCOVS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.gcov))


#******************************************************************************#
#* phonyターゲット                                                            *#
#******************************************************************************#
# コンパイル
.PHONY: all
all: $(OBJ_SUBDIRS) $(RELEASE_DIR)/$(PROG) Makefile

# テスト実行
.PHONY: run
run: all
	$(RELEASE_DIR)/$(PROG)

# gcovファイル生成
.PHONY: gcov
gcov: $(GCOVS) Makefile

# lcovファイル生成
.PHONY: lcov
lcov: Makefile
	lcov -b . -d ${OBJ_DIR} --rc lcov_branch_coverage=1 -c -o ${BUILD_DIR}/lcov.info
	genhtml --branch-coverage -o ${BUILD_DIR}/html ${BUILD_DIR}/lcov.info

# 全生成ファイルの削除
.PHONY: clean
clean:
	-rm -rf $(OBJ_DIR)


#******************************************************************************#
#* 生成規則                                                                   *#
#******************************************************************************#
# 依存関係
-include $(DEPS)

# オブジェクトサブディレクトリ
ifdef OBJ_SUBDIRS
$(OBJ_SUBDIRS):
	mkdir -p $@
endif

# 実行ファイル
$(RELEASE_DIR)/$(PROG): $(OBJS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)

# Cファイルコンパイル
$(OBJ_DIR)/%.o: %.c Makefile
	$(CC) $(CFLAGS) -o $@ -c $< -MD -MP

# gcovファイル生成
$(OBJ_DIR)/%.gcov: $(OBJ_DIR)/%.gcda
	gcov -l -p $< -o $(dir $<)


#******************************************************************************#

