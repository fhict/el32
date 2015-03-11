CC = gcc
CFLAGS = -O2 -Wall -Werror
LDFLAGS = -lrt -lpthread
HEADERS = 
SOURCES = mq_open.c mq_send.c mq_receive.c
OBJECTS = $(SOURCES:.c=.o)
TARGETS = mq_open mq_send mq_receive

.PHONY: all clean

all: $(TARGETS)

open : mq_open.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

send : mq_send.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

receive : mq_receive.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(OBJECTS): $(HEADERS)

clean:
	@rm -rf $(TARGETS) $(OBJECTS)
