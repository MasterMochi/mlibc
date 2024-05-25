#******************************************************************************#
#*                                                                            *#
#* src/Makefile                                                               *#
#*                                                                 2024/05/01 *#
#* Copyright (C) 2023-2024 Mochi.                                             *#
#*                                                                            *#
#******************************************************************************#
#******************************************************************************#
#* 設定                                                                       *#
#******************************************************************************#
# ライブラリ
LIB = libc

# ソースコード
SRCS  = stdio/vsnprintf.c
SRCS += stdio/snprintf.c
SRCS += stdlib/free.c
SRCS += stdlib/llabs.c
SRCS += stdlib/malloc.c
SRCS += string/memcpy.c
SRCS += string/memset.c
SRCS += string/strcmp.c
SRCS += string/strcpy.c
SRCS += string/strlen.c
SRCS += string/strncmp.c
SRCS += string/strncpy.c
SRCS += string/strnlen.c

# ビルドディレクトリ
BUILD_DIR   = ../build
# リリースディレクトリ
RELEASE_DIR = $(BUILD_DIR)/release
# オブジェクトディレクトリ
OBJ_DIR     = $(BUILD_DIR)/obj

# Cフラグ
CFLAGS += -O
CFLAGS += -Wall
CFLAGS += -masm=intel
CFLAGS += -m32
CFLAGS += -ffreestanding
CFLAGS += -Iinclude
CFLAGS += -I$(RELEASE_DIR)/include
CFLAGS += -I$(BUILD_DIR)/include


#******************************************************************************#
#* 定義                                                                       *#
#******************************************************************************#
# オブジェクトサブディレクトリ
OBJ_SUBDIRS = $(sort $(addprefix $(OBJ_DIR)/, $(dir $(SRCS))))

# オブジェクトファイル
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# 依存関係ファイル
DEPS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.d))


#******************************************************************************#
#* phonyターゲット                                                            *#
#******************************************************************************#
.PHONY: all
all: $(OBJ_SUBDIRS) $(RELEASE_DIR)/$(LIB).a Makefile

.PHONY: clean
clean:
	-rm -rf $(RELEASE_DIR)/$(LIB).a
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
ifdef OBJ_SUBDIRS_FE
$(OBJ_SUBDIRS_FE):
	mkdir -p $@
endif

# ライブラリ
$(RELEASE_DIR)/$(LIB).a: $(OBJS) Makefile
	$(AR) rcs $(OBJ_DIR)/$(LIB).a $(OBJS)
	ln -srf $(OBJ_DIR)/$(LIB).a $@

# アセンブラファイルコンパイル
$(OBJ_DIR)/%.o: %.s Makefile
	$(AS) -o $@ $<

# Cファイルコンパイル
$(OBJ_DIR)/%.o: %.c Makefile
	$(CC) $(CFLAGS) -o $@ -c $< -MD -MP


#******************************************************************************#
