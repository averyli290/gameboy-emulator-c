# https://stackoverflow.com/questions/14589614/make-recursive-all-c-files

CC = gcc
CFLAGS = -c -Wall -g -Os -Isrc/cpu -Isrc/cpu/registers -Isrc/cpu/load -Isrc/memory
LD = $(CC)

TARGET = bin

OBJECTS = $(patsubst %.c, %.o, $(shell find . -name "*.c"))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm $(OBJECTS)