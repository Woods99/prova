#define _GNU_SOURCE

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>
#include<sys/wait.h>

#define EX "./char-loop"

int main(int argc, char* argv[]){
	int n_kids = atoi(argv[1]);
	int* figli;
	int i,value = 1;
	int status;
	char* param[] = {
		EX,
		"c",
		NULL
	};

	figli = malloc(sizeof(int) * n_kids);
	for(i = 0; i < n_kids; i++){
		if(value != 0){
			value = fork();
			figli[i] = value;
		}
	}
	
	if(value == 0){
		execve(EX, param, NULL);

	for(i = 0; i < n_kids; i++){
		sleep(1);
		kill(figli[i], SIGINT);
		waitpid(figli[i], &status, 0);
		printf("Il processo %d è terminato con %d\n", figli[i], WEXITSTATUS(status));
	}
}
	
}

