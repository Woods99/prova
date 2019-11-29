#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include "matrix.c"


/*
char * create_shared_memory(size_t size) {
  // Our memory buffer will be readable and writable:
  int protection = PROT_READ | PROT_WRITE;

  // The buffer will be shared (meaning other processes can access it), but
  // anonymous (meaning third-party processes cannot obtain an address for it),
  // so only this process and its children will be able to use it:
  int visibility = MAP_SHARED | MAP_ANONYMOUS;

  // The remaining parameters to `mmap()` are not important for this use case,
  // but the manpage for `mmap` explains their purpose.
  return mmap(NULL, size, protection, visibility, -1, 0);
}*/




int main()
{

struct mat * m1, *m2, *m3;

m1=mat_read_alloc();
mat_print(m1);
int n_flag=5;
m1=mat_insert_flag_value(m1,n_flag);



mat_print_value(m1);
mat_print(m1);



/*
char* parent_message = "hello";  // parent process will write this message
  char* child_message = "goodbye"; // child process will then write this one
char * old_msg;
  char * shmem = create_shared_memory(128);

  memcpy(shmem, parent_message, sizeof(parent_message));*/
	
	pid_t child_pid;

	char* env_vars[] = {
		"SO_NUM_P=c_num_p",
		NULL
	};
	
	char* args[] = {
		"c_num_p",    
		NULL
	};
/*
old_msg=shmem;
printf("%s\n",old_msg);*/

//mat_print(shmem);
//m2=shmem;

/*
	for (int i=0; i<2; i++) {
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
	
	*/
/*		
  int pid = fork();

  if (pid == 0) {
    printf("Child read: %s\n", shmem);
    memcpy(shmem, child_message, sizeof(child_message));
    printf("Child wrote: %s\n", shmem);

  } else {
    printf("Parent read: %s\n", shmem);
    sleep(1);
    printf("After 1s, parent read: %s\n", shmem);
  }

*/















mat_free(m1);
}
