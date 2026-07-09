CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCFILES = fs.c main.c
OBJFILES = $(SRCFILES:.c=.o)
TARGET = filesystem

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJFILES) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
