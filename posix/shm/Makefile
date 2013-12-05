CC = i586-linux-gcc
CFLAGS = -O2 -Wall -Werror
LDFLAGS = -lrt

all: tryshm shm shm2

tryshm: tryshm.c
	${CC} $(CFLAGS) $(LDFLAGS) -o tryshm tryshm.c
shm: shm.c
	${CC} $(CFLAGS) $(LDFLAGS) -o shm shm.c
shm2: shm2.c
	${CC} $(CFLAGS) $(LDFLAGS) -o shm2 shm2.c
	
clean:
	rm -f tryshm shm shm2
