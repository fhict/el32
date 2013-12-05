CC = i586-linux-gcc
CFLAGS = -O2 -Wall -Werror
LDFLAGS = -lrt

.PHONY: all clean

all: send receive

send: send.c
	${CC} $(CFLAGS) $(LDFLAGS) -o send send.c
	
receive: receive.c
	${CC} $(CFLAGS) $(LDFLAGS) -o receive receive.c

clean:
	@rm -f send receive
