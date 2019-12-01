#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include "global.h"
#include "matrix.c"


int main(int argc, char * argv[])
{



	key_t key_gioc_ped;
	key_t keysopsris;
	int shmid_gioc_ped;	
	struct mat * m3;
	int value;	
	struct sembuf sops;
		

	key_gioc_ped = ftok("shmfile",MY_KEY_STRUCT); 
	shmid_gioc_ped=shmget(key_gioc_ped,1024,0666|IPC_CREAT|IPC_PRIVATE); 
	m3 = (struct mat *) shmat(shmid_gioc_ped,(void *)0,0); 

	value=atoi(argv[0]);		//carattere ricevuto dal giocatore
		

		

	keysopsris = ftok("shmfile",KEY_SOPS_RIS); 
	int shmidlett=shmget (keysopsris ,2,0666|IPC_CREAT|IPC_STAT);
	

	sops.sem_flg=0;			//nessun flag su operazioni di semafori


	/* Only the first semaphore is available */
	semctl(shmidlett, 0, SETVAL, 1);
		
		

		
	/* try accessing semaphore 0 */
	sops.sem_num = 0;
	sops.sem_op = -1;
	sops.sem_flg = 0;
	semop(shmidlett, &sops, 1);

					
	mat_insert_char(m3,value);	//risorsa da proteggere					


	sops.sem_num = 0;
	sops.sem_op = 1;
	sops.sem_flg = 0;
	/* release semaphore 0 */
	semop(shmidlett, &sops, 1);
							
								

	shmdt(m3);
	
	exit(1);
}


