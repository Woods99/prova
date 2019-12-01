#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "matrix.c"
#include "global.h"
#include <string.h>
#include <signal.h>


void my_handler_sig(int signum){
static int conteggio=0;

printf("il giocatore %d ha piazzato le sue pedine\n",++conteggio);

}
       
  
int main() 
{ 
	
	key_t key_struct;
	int shmid;
	struct mat * m5;
	struct sigaction sa;
	int c_num_g;


	// start handle(gestire) signal
	bzero(&sa, sizeof(sa));  /* set all bytes to zero */	
	sa.sa_handler = my_handler_sig;
	sigaction(SIGINT, &sa, NULL);
	

	// ftok to generate unique key 
	key_struct = ftok("shmfile",MY_KEY_STRUCT); 
	
	// shmget returns an identifier in shmid 
	shmid = shmget(key_struct,100024,0666|IPC_CREAT); 
	
	// shmat to attach to shared memory 
	m5 = (struct mat *) shmat(shmid,(void *)0,0);
	m5->rows=SO_ALTEZZA;
	m5->cols=SO_BASE;
	mat_fill_pos(m5);
	mat_insert_data(m5);
	m5->c_letter=0;
	

	c_num_g=atoi(getenv("SO_NUM_G"));
	pid_t child_pid;
	lettere(m5,c_num_g);

	
	
	shmdt(m5);				//preparo la detach
	for (int i=0; i<c_num_g; i++) {
		switch (child_pid = fork()) {
		case -1:
			
			fprintf(stderr, "Error with the fork\n");
			exit(EXIT_FAILURE);
		case 0:					 
			execlp("./giocatore","abcd",(char *)0);		
			break;
			
		default:
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																											
			printf("Il PID del padre è %5d (PARENT)%d\n",getpid(), child_pid);
			break;
		}

	}
	sleep(2.8);
	m5=(struct mat *) shmat(shmid,(void *)0,0);
	mat_print(m5);
	shmdt(m5);	

	//char * newstr;	
	/*
	printf("la strina prima di fare fgets %s",str);
	printf("inserisci la stringa");
	fgets(str,sizeof(str),stdin); 
	printf("Data written in memory: %s\n",str); */

	
	//detach from shared memory
	shmctl(shmid,IPC_RMID,NULL);
		 
  	
    return 0; 
} 
