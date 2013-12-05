#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main (void)
{
	int i;
	
	if ((i = shm_open ("sharedmem", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR)) == -1){
		perror("cannot open");
		return -1;
	}
	
	printf("OK!\n");

	shm_unlink ("sharedmem");

	return (0);
}
