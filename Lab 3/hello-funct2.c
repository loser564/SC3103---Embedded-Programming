#include "hello-funct2.h"
#include "hello.h"
static int count = 0;


void incrementCount(){
	count = count +1 ;
}

int getCount(){
	return count;
}

void hellofunct2a(){
	incrementCount();
	getCount();
}

void hellofunct2() {
    printf("Hello World from funct2!\n");
    delay(0x7fffffff);
}
