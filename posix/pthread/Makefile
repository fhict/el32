CC = i586-linux-gcc
CFLAGS = -O2 -Wall -Werror
LDFLAGS = -lpthread

all: mythread threads

mythread: mythread.c
	${CC} $(CFLAGS) $(LDFLAGS) -o mythread mythread.c
	
threads: threads.c
	${CC} $(CFLAGS) $(LDFLAGS) -o threads threads.c

clean:
	@rm -f mythread threads
