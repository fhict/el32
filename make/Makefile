CC = i586-linux-gcc
CFLAGS = -O2 -Wall -Werror
LDFLAGS = 
HEADERS = hello.h world.h
SOURCES = hello.c world.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = helloworld

.PHONY: all clean

all: $(TARGET)
 
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(OBJECTS): $(HEADERS)

clean:
	@rm -rf $(TARGETS) $(OBJECTS)
