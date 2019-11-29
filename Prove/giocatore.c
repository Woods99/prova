#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <unistd.h>
#include "global.h"
#include "matrix.c"







extern char **environ;  /* declared extern, defined by the OS somewhere */

int main(int argc, char * argv[]) {
/*
int child_pid;
char * get_env;	
int c_num_p=0;
int sum=0;
int i;
char* env_vars[] = {
	NULL
};
	
char* args[] = {
	NULL
};*/
struct mat * m4;
// ftok to generate unique key 
	key_t key = ftok("shmfile",MY_KEY_STRUCT); 
	

	// shmget returns an identifier in shmid 
	int shmid = shmget(key,1024,0666|IPC_CREAT); 

	// shmat to attach to shared memory 
	
	struct mat * m3 = (struct mat *) shmat(shmid,(void *)0,0); 
	printf("%d\n",m3->rows);
	printf("%d\n",m3->cols);
	printf("%d\n",m3->pos[0][0]);
	printf("%c\n",m3->data[0][0]);
	
/*
if((getenv("SO_NUM_P"))==NULL)
fprintf(stderr,"Errore variabile d'ambiente SO_NUM_P non presente\n");
else{										//Poi inseriremo le variabili d'ambiente ottenute
		get_env=getenv("SO_NUM_P");					//in un pezzo di memoria condivisa fra i processi
		i=atoi(get_env);
		//c_num_p=mycVar((*(get_env)),c_num_p);
		
	}
printf("%d\n",*(argv[3]));*/


/*
for (int i=0; i<c_num_p; i++) {
		switch (child_pid = fork()) {
		case -1:
			fprintf(stderr, "Error with the fork\n");
			exit(EXIT_FAILURE);
		case 0:
			printf("Sono il figlio pedina e Il mio PID è %5d (CHILD)  \n",getpid());					 
			execve("pedina",env_vars,args);		//conta env_vars
			break;
			
		default:
			printf("Il PID del padre è %5d (PARENT)%d\n",getpid(), child_pid);
			
			break;
		}

	}*/
shmdt(m4); 


exit(1);

}
