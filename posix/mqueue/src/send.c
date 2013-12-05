#include <stdio.h>
#include <string.h>
#include <mqueue.h>

#define QUEUE_NAME  "/my_queue"
#define PRIORITY     1
#define SIZE        256

int main(){

    mqd_t ds;
    char text[] = "Hello Posix World";
    struct mq_attr queue_attr;

    /* Attributes for our queue. Those can be set only during creating. */
    queue_attr.mq_maxmsg = 32;  /* max. number of messages in queue at the same time */
    queue_attr.mq_msgsize = SIZE;   /* max. message size */

    /* Creates a new queue named "/my_queue" and opens it for
     * sending and receiving. The queue file permissions are set rw for owner and nothing for group/others.
	* Queue limits set to values provided above. */
    if ((ds = mq_open(QUEUE_NAME, O_CREAT | O_RDWR , 0600, &queue_attr)) == (mqd_t)-1){
        perror("Creating queue error");
        return -1;
}

    /* Send a message to the queue with priority 1.
     * Higher the number, higher is the priority. A high priority message is inserted
     * before a low priority message. First-in First-out for equal priority messages.
	*/
    if (mq_send(ds, text, strlen(text), PRIORITY) == -1){
        perror("Sending message error");
	return -1;
}

    /* Close queue... */
    if (mq_close(ds) == -1)
        perror("Closing queue error");

    return 0;
}
