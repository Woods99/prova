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
