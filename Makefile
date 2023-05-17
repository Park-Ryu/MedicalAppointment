CC=gcc
CFLAGS= -W -Wall
TARGET=mymusic
OBJECTS= main.c menu.o medic.o
all:$(TARGET)
$(TARGET): $(OBJECTS)
        $(CC) $(CFLAGS) -o $@ $^
clean:
        rm *.o mymedic
