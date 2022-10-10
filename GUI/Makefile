CC = g++

INCLUDE_DIR = include
BUILD_DIR   = build

SRCS = GUI.cpp Misc.cpp Vector.cpp Button.cpp

CC_FLAGS  = -Wall -Wextra -I $(INCLUDE_DIR) \
			-lraylib -Wno-unused-variable


DBG_FLAGS = -fsanitize=address -ggdb

.PHONY: build, debug, run, clean

all: build

build: GUI.elf

GUI.elf: $(SRCS)
	     $(CC) $^ $(CC_FLAGS) -o $(BUILD_DIR)/GUI.elf

debug: $(SRCS)
	   $(CC) $^ $(CC_FLAGS) $(DBG_FLAGS) -o $(BUILD_DIR)/GUI.elf

run: build
	 @$(BUILD_DIR)/GUI.elf

clean:
	  - rm $(BUILD_DIR)/* 2>/dev/null
