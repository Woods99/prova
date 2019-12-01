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
#include <signal.h>






extern char **environ;  /* declared extern, defined by the OS somewhere */

int main(int argc, char * argv[]) {

	int child_pid;
	char * get_env;	
	key_t key_struct;
	key_t key_gioc_ped;
	struct mat * m3;
	struct mat * m4;
	struct mat * m5;
	int c_num_p=0;
	char arg_ecelp[50];
	int value;
	int shmid_gioc_ped;	
	int shmid;
	

	// ftok to generate unique key 
	key_struct = ftok("shmfile",MY_KEY_STRUCT); 
	key_gioc_ped = ftok("shmfile",KEY_GIOC_PED);
	
	// shmget returns an identifier in shmid 
	shmid = shmget(key_struct,1024,0666|IPC_CREAT); 
	shmid_gioc_ped=shmget(key_gioc_ped,1024,0666|IPC_CREAT); 
	
	// shmat to attach to shared memory 
	m3 = (struct mat *) shmat(shmid,(void *)0,0);
	m4 = (struct mat *) shmat(shmid_gioc_ped,(void *)0,0);


	value=m3->lettere[m3->c_letter];
	m3->c_letter+=1;
	printf("sono il PID %d e  ho preso lo %d\n",getpid(),m3->c_letter);	
	snprintf(arg_ecelp,sizeof(arg_ecelp),"%d",value);

	



	if((getenv("SO_NUM_P"))==NULL)
	fprintf(stderr,"Errore variabile d'ambiente SO_NUM_P non presente\n");
	else{										//Poi inseriremo le variabili d'ambiente ottenute
									//in un pezzo di memoria condivisa fra i processi
		c_num_p=atoi(getenv("SO_NUM_P"));
	}
	printf("%d\n",c_num_p);



	shmdt(m3); 					//preparo lo staccamento della memoria
	shmdt(m4); 
	for (int i=0; i<c_num_p; i++) {
		switch (child_pid = fork()) {
		case -1:
			fprintf(stderr, "Error with the fork\n");
			exit(EXIT_FAILURE);
		case 0:				 
			execlp("./pedina",arg_ecelp, (char*)0);		
			break;
			
		default:
			break;
		}

	}
	sleep(1.3);
	kill(getppid(),2);
	m5 = (struct mat *) shmat(shmid_gioc_ped,(void *)0,0);
	m3=m5;
	shmdt(m5);




	exit(1);

	}
