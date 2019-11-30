#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "matrix.c"
#include "global.h"
 


       

  
int main() 
{ 
	
	
	struct mat * m1, *m2, *m3;
	int ricalcolo=0;
	int c_num_g;

	//mat_print(m1);
	


	// ftok to generate unique key 
	key_t key = ftok("shmfile",MY_KEY_STRUCT); 

	// shmget returns an identifier in shmid 
	int shmid = shmget(key,100024,0666|IPC_CREAT); 

	
	

	
	// shmat to attach to shared memory 
//	mat_print(m1);
	
	struct mat * m5 = (struct mat *) shmat(shmid,(void *)0,0); 
	m5->rows=20;
	m5->cols=60;
	mat_fill_pos(m5);
	mat_insert_data(m5);


	key_t keylett = ftok("shmfile",MY_KEY_LETTER); 
	int shmidlett=shmget (keylett ,1,0666|IPC_CREAT);
	


	c_num_g=atoi(getenv("SO_NUM_G"));
	pid_t child_pid;
	char* env_vars[] = {
		"SO_NUM_P=c_num_p",
		NULL
	};
	
	char* args[] = {
		"c_num_p",    
		NULL
	};
		
		lettere(m5,c_num_g);
	

	for (int i=0; i<c_num_g; i++) {
		switch (child_pid = fork()) {
		case -1:
			
			fprintf(stderr, "Error with the fork\n");
			exit(EXIT_FAILURE);
		case 0:
			printf("Sono il figlio giocatore e Il mio PID è %5d (CHILD)\n",getpid());					 
			execve("giocatore",args,env_vars);		
			break;
			
		default:
			
			printf("Il PID del padre è %5d (PARENT)%d\n",getpid(), child_pid);
			break;
		}

	}
	sleep(1);
	for(int i=0;i<2;i++)
	printf("sono il padre e il valore in lettere %d è %d\n",i,m5->lettere[i]);
	//char * newstr;	
	/*
	printf("la strina prima di fare fgets %s",str);
	printf("inserisci la stringa");
	fgets(str,sizeof(str),stdin); 
	printf("Data written in memory: %s\n",str); */
	//detach from shared memory  
	shmdt(m5); 
  
    return 0; 
} 
