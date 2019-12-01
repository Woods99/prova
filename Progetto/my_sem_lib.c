#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "global.h"



/* Try to access the resource */
int sem_reserve(int sem_id, int sem_num) {
	struct sembuf sops;
	
	sops.sem_num = sem_num;
	sops.sem_op = -1;
	sops.sem_flg = 0;
	return semop(sem_id, &sops, 1);
}



int sem_release(int sem_id, int sem_num) {
	struct sembuf sops;
  
	sops.sem_num = sem_num;
	sops.sem_op = 1;
	sops.sem_flg = 0;
	
	return semop(sem_id, &sops, 1);
}

void reset_sem(int sem_id)
{
//	semctl(sem_id, ID_READY, SETVAL, 0);
	semctl(sem_id, ID_GIOCATORE_1, SETVAL, 0);
	semctl(sem_id, ID_GIOCATORE_2, SETVAL, 0);
/*	semctl(sem_id, ID_UOVO, SETVAL, 0);
	semctl(sem_id, ID_SALE, SETVAL, 0);
	semctl(sem_id, ID_POMODORO, SETVAL, 0);
	semctl(sem_id, ID_PANCETTA, SETVAL, 0);
	semctl(sem_id, ID_CIPOLLA, SETVAL, 0);
	semctl(sem_id, ID_PATATE, SETVAL, 0);
	semctl(sem_id, ID_PADELLA, SETVAL, 0);
	semctl(sem_id, ID_PENTOLA, SETVAL, 0);
	semctl(sem_id, ID_FORNELLO, SETVAL, 0);*/
}
