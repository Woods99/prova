#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include "global.h"
#include "matrix.c"
#include <signal.h>


void my_handler_sig(int signum){
static int conteggio=0;

printf("il giocatore %d ha piazzato le sue pedine\n",++conteggio);

}



extern char **environ;  /* declared extern, defined by the OS somewhere per printare le variabili globali*/

int main(int argc, char * argv[]) {
	struct sigaction sa;
	struct mat * m1, * m2;

	key_t key_struct;
	int shmid;	//id memory
	int shmidlett;

	int sum=0;
	pid_t child_pid;

	char * get_env;
	int c_num_g=0;
	int c_num_p=0;
	int so_altezza;
	int so_base;

	int n_flag_min=0;
	int n_flag_max=0;
	int flag=0;	


	// start handle(gestire) signal
	bzero(&sa, sizeof(sa));  /* set all bytes to zero */	
	sa.sa_handler = my_handler_sig;
	sigaction(SIGINT, &sa, NULL);	


	if((getenv("SO_ALTEZZA"))==NULL)
	fprintf(stderr, "Errore variabile d'ambiente SO_ALTEZZA non presente\n");
	else{
		
		so_altezza=atoi(getenv("SO_ALTEZZA"));
	}

	
	if((getenv("SO_BASE"))==NULL)
	fprintf(stderr, "Errore variabile d'ambiente SO_BASE non presente\n");
	else{
		
		so_base=atoi(getenv("SO_BASE"));
	}	


	//allocate shared memory
	// ftok to generate unique key 
	key_struct = ftok("shmfile",MY_KEY_STRUCT); 

	// shmget returns an identifier in shmid 
	shmid = shmget(key_struct,100024,0666|IPC_CREAT); 

	// shmat to attach to shared memory 	
	m1 = (struct mat *) shmat(shmid,(void*)0,0); 
	m1->rows=so_altezza;
	m1->cols=so_base;
	mat_insert_data(m1);
	m1->c_letter=0;



	if((getenv("SO_FLAG_MIN"))==NULL)
	fprintf(stderr, "Errore variabile d'ambiente SO_FLAG_MIN non presente\n");
	else{
		
		n_flag_min=atoi(getenv("SO_FLAG_MIN"));
	}

	if((getenv("SO_FLAG_MAX"))==NULL)
	fprintf(stderr, "Errore variabile d'ambiente SO_FLAG_MAX non presente\n");
	else{
		n_flag_max=atoi(getenv("SO_FLAG_MAX"));
	}


	
	flag=mycFlag(n_flag_min,n_flag_max);
	m1=mat_insert_flag_value(m1,flag);			//inserimento bandierine e relativo punteggio
	mat_print(m1);

	


	
	
	putenv("Innesco=2");
	if((getenv("SO_NUM_G"))==NULL)
	fprintf(stderr,"Errore variabile d'ambiente SO_NUM_G non presente\n");
	else{
		
		c_num_g=atoi(getenv("SO_NUM_G"));
		
	}
	
	if((getenv("SO_NUM_P"))==NULL)
	fprintf(stderr,"Errore variabile d'ambiente SO_NUM_P non presente\n");
	else{
		
		c_num_p=atoi(getenv("SO_NUM_P"));
		
	}
	

	printf("%d\n",c_num_g);
	insert_lettere(m1,c_num_g);
	



	shmdt(m1);				//preparo la detach
	for (int i=0; i<c_num_g; i++) {
		switch (child_pid = fork()) {
		case -1:
			
			fprintf(stderr, "Error with the fork\n");
			exit(EXIT_FAILURE);
		case 0:
			printf("Sono il figlio giocatore e Il mio PID è %5d (CHILD)\n",getpid());					 				 
			execlp("./giocatore","abcd",(char *)0);		
			break;
			
		default:
			printf("Il PID del padre è %5d (PARENT)%d\n",getpid(), child_pid);
			break;
		}

	}
	sleep(2.8);
	m1=(struct mat *) shmat(shmid,(void *)0,0);
	mat_print(m1);
	shmdt(m1);						

	//detach from shared memory
	shmctl(shmid,IPC_RMID,NULL);



	//mat_free(m1);	problema con il liberare la struct	
	//shmdt(m1);
}




