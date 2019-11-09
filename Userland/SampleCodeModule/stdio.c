#include <stdio.h>
#include <string.h>
#include <callSyscall.h>
void putchar(char c){
	callSyscall(WRITE,(void*) 1,(void*)c,(void*)1,(void*)0,(void*)0,(void*)0);
}
char getchar(){
	char c;
	callSyscall((void*)READ,(void*)c,(void*)1,(void*)0,(void*)0,(void*)0,(void*)0);
	return c;
}

void printf(const char* buffer){
	callSyscall(WRITE,(void*)1,(void*)buffer,(void*)strlen(buffer),(void*)0,(void*)0,(void*)0);
}

void scanf(char*buffer){
	char c;
	while((c = getchar()) != '\n'){
		*buffer = c;
		buffer++;
	}

}

