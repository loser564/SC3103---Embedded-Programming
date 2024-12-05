#include "hello-funct2.h"
#include "hello.h"
#include <stdio.h>



int main() {
    printf("Hello World from main!\n");
    delay(0x5fffff);
    hellofunct1();
    hellofunct2();
    printf("Bye!\n");
    return 0;
}


