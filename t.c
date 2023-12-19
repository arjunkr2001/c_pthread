#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

char inp[100];

void *displayClock(void *arg){
	while(1){
		system("clear");
		time_t ct;
		struct tm *lt;
		time(&ct);
		lt = localtime(&ct);
		printf("%02d:%02d:%02d %s\n> ",lt->tm_hour,lt->tm_min,lt->tm_sec,inp);
		fflush(stdout);
		sleep(1);
	}
	return NULL;
}

void *readInput(void *arg){
	while(1){
		system("clear");
		//printf("\n> ");
		fgets(inp,sizeof(inp),stdin);
		fflush(stdout);
	}
	return NULL;
}

int main(){
	pthread_t clkt,inpt;
	pthread_create(&clkt,NULL,displayClock,NULL);
	pthread_create(&inpt,NULL,readInput,NULL);
	pthread_join(clkt,NULL);
	pthread_join(inpt,NULL);
	return 0;
}
