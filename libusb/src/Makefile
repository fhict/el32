CC = i586-linux-gcc
CFLAGS = -O2 -Wall -Werror
LDFLAGS = -lusb-1.0
HEADERS =
SOURCES = xpadtest.c
OBJECTS = $(SOURCES:.c=.o)
TARGETS = xpadtest

.PHONY: all clean

all: $(TARGETS)

$(TARGETS) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS)

$(OBJECTS): $(HEADERS)

clean:
	@rm -rf $(TARGETS) $(OBJECTS)
