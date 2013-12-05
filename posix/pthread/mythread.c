#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define SYNCHRONISED

static pthread_t thread;
#ifdef SYNCHRONISED
static pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;
#endif
static int shared = 0;

static void *mythread(void *ptr) {
	int i, tmp;

	for (i = 0; i < 10; i++) {
#ifdef SYNCHRONISED
		pthread_mutex_lock(&mymutex);
#endif
		printf("processing...\n");
		tmp = shared;
		tmp++;
		/* sleep for one second
		 * pretend we are waiting for something
		*   without mutex: very likely to mess-up :P */
		sleep(1);
		shared = tmp;
#ifdef SYNCHRONISED
		pthread_mutex_unlock(&mymutex);
#endif
		/* non-critical section:
		 * sleep for one second
		 * pretend we are waiting for something
		* and avoid being unfair */
		sleep(1);
}
	pthread_exit(NULL);
}

int main(){
	int i, tmp;
	
	/* start thread */
	pthread_create(&thread, NULL, mythread, NULL);
	
	for (i = 0; i < 10; i++) {
#ifdef SYNCHRONISED
		pthread_mutex_lock(&mymutex);
#endif
		printf("doing other stuff...\n");
		tmp = shared;
		tmp--;
		/* sleep for one second
		 * pretend we are waiting for something
		*   without mutex: very likely to mess-up :P */
		sleep(1);
		shared = tmp;
#ifdef SYNCHRONISED
		pthread_mutex_unlock(&mymutex);
#endif
		/* non-critical section:
		 * sleep for one second
		 * pretend we are waiting for something
		* and avoid being unfair */
		sleep(1);
}

	/* wait for thread to complete */
	pthread_join(thread, NULL);

	/* it will be zero, unless we messed-up (when compiling without -DSYNCHRONISED) */
	printf("ready %d\n", shared);

	return 0;
}
