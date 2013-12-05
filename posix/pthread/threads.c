#include <pthread.h>
#include <stdio.h>

void *PrintHello(void * id)
{
	printf("Thread%d: Hello World!\n", (int) id);
	pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
	pthread_t thread0, thread1;
	pthread_create(&thread0, NULL, PrintHello, (void *) 0);
	pthread_create(&thread1, NULL, PrintHello, (void *) 1);
	pthread_exit(NULL);
}
