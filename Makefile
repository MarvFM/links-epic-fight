# source files
OBJS = $(wildcard src/*cpp)

# we want to use the compiler
CC = g++

# compiler flags
COMPILER_FLAGS = -Wall -O -std=c++11

# linker
LINKER_FLAGS = -lSDL2 -lSDL2_ttf

# output name
OBJ_NAME = links_epic_fight

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
