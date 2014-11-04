//sed '2d' list.txt > temp.txt && cp temp.txt list.txt
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>

int main(int argc, char ** argv){

	int del = atoi(argv[1]);
	//printf("%d\n",del);
	if(del == 0){
		puts("Please enter an item to delete");
		//system("list");
		exit(0);
	}else{
		char buf[100];
   		sprintf(buf, "sed '%dd' list.txt > temp.txt && cp temp.txt list.txt", del); // puts string into buffer
		int success = system(buf);
	}

}