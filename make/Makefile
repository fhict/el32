CC = gcc
CFLAGS = -O2 -Wall -Werror
LDFLAGS = 
HEADERS = hello.h world.h
SOURCES = hello.c world.c
OBJECTS = $(SOURCES:.c=.o)
TARGETS = helloworld

.PHONY: all clean

all: $(TARGETS)
 
$(TARGETS) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS)

$(OBJECTS): $(HEADERS)

clean:
	@rm -rf $(TARGETS) $(OBJECTS)
