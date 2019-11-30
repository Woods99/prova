#include <time.h>


void lettere(struct mat *m,int n_proc){
int ricalcolo=0;
	do{
		srand(time(NULL));
		for(int i=0;i<n_proc;i++){
		int value=rand() % (90 + 1 - 65) + 65;	
		m->lettere[i]=value;	
		}
		ricalcolo=0;
		for(int i=0;i<n_proc;i++){
			for(int j=0;j<n_proc;j++){
			if(m->lettere[i]==m->lettere[j]) ++ricalcolo;
			}
		}
	}while(!ricalcolo);
	
}


