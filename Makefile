#Kaleb Hedrick G01311347
#CS 262,Lab section 202
# Lab 9
CC = gcc
CFLAGS = -g -Wall -std=c89 -pedantic-errors
TARGET = lab9_khedric8_202
LIBS = -lm
all: $(TARGET).c
	$(CC) $(TARGET).c -o $(TARGET) $(CFLAGS) $(LIBS)
clear:
	rm $(TARGET)
