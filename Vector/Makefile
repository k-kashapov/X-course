CC  = g++

INCLUDE_DIR = include
BUILD_DIR   = build

SRCS = main.cpp Vector.cpp Coordinates.cpp Misc.cpp

CC_FLAGS  = -Wall -Wextra -I $(INCLUDE_DIR) -lraylib
DBG_FLAGS = -fsanitize=address -ggdb

all: build

build: $(SRCS)
	   $(CC) $^ $(CC_FLAGS) -o $(BUILD_DIR)/vector.elf

debug: $(SRCS)
	   $(CC) $^ $(CC_FLAGS) $(DBG_FLAGS) -o $(BUILD_DIR)/vector.elf

run: build
	 @$(BUILD_DIR)/vector.elf

clean:
	  rm $(BUILD_DIR)/*
