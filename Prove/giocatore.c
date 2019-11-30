#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "global.h"
#include "matrix.c"
#include <unistd.h>







extern char **environ;  /* declared extern, defined by the OS somewhere */

int main(int argc, char * argv[]) {

int child_pid;
char * get_env;	
int c_num_p=0;
int sum=0;

// ftok to generate unique key 
	key_t key = ftok("shmfile",MY_KEY_STRUCT); 
	key_t keylett = ftok("shmfile",KEY_MEM_CONTLETT); 

	// shmget returns an identifier in shmid 
	int shmid = shmget(key,1024,0666|IPC_CREAT); 
	int shmidlett = shmget(keylett,100024,0666|IPC_CREAT);
	// shmat to attach to shared memory 
	
	struct mat * m3 = (struct mat *) shmat(shmid,(void *)0,0); 
	int * cont_lett=(int *) shmat(shmidlett,(void *)0,0); 
	int value=m3->lettere[cont_lett[0]];
	m3->lett_cont[cont_lett[0]]=value;
	cont_lett[0]+=1;
	printf("sono il PID %d e  ho preso lo %d\n",getpid(),cont_lett[0]);

	int i =atoi(argv[0]);
	printf("%d",i);


	char arg_ecelp[50];	
	snprintf(arg_ecelp,sizeof(arg_ecelp),"%d",value);








/*
	int value;
	

	key_t keylett = ftok("shmfile",MY_KEY_LETTER); 
	int shmidlett=shmget (keylett ,3,0666|IPC_CREAT|IPC_STAT);
	for (int i=0; i</*NUM_PROC*///2; i++) {
		/* Only the first semaphore is available */
/*		semctl(shmidlett, i, SETVAL,i ? 0 : 1);
		
	}
	
	for (int i=0; i<2; i++) {
	for(int j=0; j<1; j++) {

				/* try accessing semaphore i */
/*				sem_reserve(shmidlett, i);
				

				value=m3->lettere[i];
				

				/* release semaphore i+1 */
/*				sem_release(shmidlett, 0 );
				

			}
printf("%c\n",value);
}*/
	
	

	
	

	
	
	
	

if((getenv("SO_NUM_P"))==NULL)
fprintf(stderr,"Errore variabile d'ambiente SO_NUM_P non presente\n");
else{										//Poi inseriremo le variabili d'ambiente ottenute
									//in un pezzo di memoria condivisa fra i processi
		c_num_p=atoi(getenv("SO_NUM_P"));
	}
printf("%d\n",c_num_p);




for (int i=0; i<c_num_p; i++) {
		switch (child_pid = fork()) {
		case -1:
			fprintf(stderr, "Error with the fork\n");
			exit(EXIT_FAILURE);
		case 0:
			printf("Sono il figlio pedina e Il mio PID è %5d (CHILD)  \n",getpid());					 
			execlp("./pedina",arg_ecelp,(char*)0);		//conta env_vars
			break;
			
		default:
			printf("Il PID del padre è %5d (PARENT)%d\n",getpid(), child_pid);
			
			break;
		}

	}
shmdt(m3); 


exit(1);

}
