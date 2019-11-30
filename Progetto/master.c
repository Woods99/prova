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







extern char **environ;  /* declared extern, defined by the OS somewhere per printare le variabili globali*/

int main(int argc, char * argv[]) {
struct mat * m1, * m2;

key_t key;
int shmid;	//id memory

int sum=0;
pid_t child_pid;

char * get_env;
int c_num_g=0;
int c_num_p=0;


int n_flag_min=0;
int n_flag_max=0;
int flag=0;	



//allocate shared memory
// ftok to generate unique key 
key = ftok("shmfile",MY_KEY_STR); 

// shmget returns an identifier in shmid 
shmid = shmget(key,1024,0666|IPC_CREAT); 

// shmat to attach to shared memory 
	
m1 = (struct mat *) shmat(shmid,(void*)0,0); 





if((getenv("SO_FLAG_MIN"))==NULL)
fprintf(stderr, "Errore variabile d'ambiente SO_FLAG_MIN non presente\n");
else{
	get_env=getenv("SO_FLAG_MIN");
	n_flag_min=mycVar(get_env,n_flag_min);
}

if((getenv("SO_FLAG_MAX"))==NULL)
fprintf(stderr, "Errore variabile d'ambiente SO_FLAG_MAX non presente\n");
else{
	get_env=getenv("SO_FLAG_MAX");
	n_flag_max=mycVar(get_env,n_flag_max);
}


m1=mat_read_alloc(m1);
flag=mycFlag(n_flag_min,n_flag_max);
m1=mat_insert_flag_value(m1,flag);
mat_print(m1);





	
	putenv("Innesco=2");
	if((getenv("SO_NUM_G"))==NULL)
	fprintf(stderr, "Errore variabile d'ambiente SO_NUM_G non presente\n");
	else{
		get_env=getenv("SO_NUM_G");
		c_num_g=mycVar(get_env,c_num_g);
	}
	
	
	if((getenv("SO_NUM_P"))==NULL)
	fprintf(stderr,"Errore variabile d'ambiente SO_NUM_P non presente\n");
	else{
		get_env=getenv("SO_NUM_P");
		c_num_p=mycVar(get_env,c_num_p);
		
	}
	
	char* env_vars[] = {
		"SO_NUM_P=10",
		"SO_ALTEZZA=20",
		"SO_BASE=60",
		NULL
	};
	
	char* args[] = {
		"c_num_p",    
		"VAR1",
		"CASA"
		"FALAF",
		NULL
	};
	printf("%d\n",c_num_g);
	
	
	
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
sleep(1);							//in questo punto è necessario aspettare che il padre finisca 									//dopo che i suoi figli siano terminati 


//mat_free(m1);	problema con il liberare la struct	
//shmdt(m1);
}




