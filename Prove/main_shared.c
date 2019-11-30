#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "matrix.c"
#include "global.h"
#include <string.h>



       

  
int main() 
{ 
	
	
	struct mat * m1, *m2, *m3;
	int ricalcolo=0;
	int c_num_g;

	//mat_print(m1);
	


	// ftok to generate unique key 
	key_t key = ftok("shmfile",MY_KEY_STRUCT); 
	key_t keylett = ftok("shmfile",KEY_MEM_CONTLETT); 
	// shmget returns an identifier in shmid 
	int shmid = shmget(key,100024,0666|IPC_CREAT); 
	int shmidlett = shmget(keylett,100024,0666|IPC_CREAT);
	
	

	
	// shmat to attach to shared memory 
//	mat_print(m1);
	
	struct mat * m5 = (struct mat *) shmat(shmid,(void *)0,0); 
	m5->rows=20;
	m5->cols=60;
	mat_fill_pos(m5);
	mat_insert_data(m5);
	int * cont_lett=shmat(shmidlett,NULL,0); 
	cont_lett[0]=0;

	
	
	c_num_g=atoi(getenv("SO_NUM_G"));
	pid_t child_pid;
	


	lettere(m5,c_num_g);
	char str[50];	
	snprintf(str,sizeof(str),"%d",'c');
	
	for (int i=0; i<c_num_g; i++) {
		switch (child_pid = fork()) {
		case -1:
			
			fprintf(stderr, "Error with the fork\n");
			exit(EXIT_FAILURE);
		case 0:
			printf("Sono il figlio giocatore e Il mio PID è %5d (CHILD)\n",getpid());
			sleep(0.3);					 
			execlp("./giocatore",str,"abcd",(char *)0);		
			break;
			
		default:
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																											\
			printf("Il PID del padre è %5d (PARENT)%d\n",getpid(), child_pid);
			break;
		}

	}
	sleep(2);
	for(int i=0;i<c_num_g;i++)
	printf("sono il padre e il valore in lettere %d è %d\n",i,m5->lett_cont[i]);
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
