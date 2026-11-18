COMP = g++
OUT = $(wildcard src/*.cpp)
TARGET = build/juke_box_prototype

LIBS = $(shell pkg-config --libs alsa sdl3) 
CFLAGS = -std=c++20 -Wall -Wextra -g $(shell pkg-config --cflags alsa sdl3)

all:
	$(COMP) $(OUT) $(LIBS) $(CFLAGS) -o $(TARGET)
	./$(TARGET)