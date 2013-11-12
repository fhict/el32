/* Hello World program in C */

#include <stdio.h>
#include "hello.h"
#include "world.h"

void printhello(void)
{
    printf("Hello");
}

int main(void)
{
    printhello();
    printworld();
    return 0;
}
