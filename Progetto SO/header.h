#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int SO_BASE, SO_ALTEZZA, SO_FLAG, SO_NUM_G, SO_NUM_P, SO_MAX_TIME, SO_ROUND_SCORE, SO_N_MOVES, SO_FLAG_MAX, SO_FLAG_MIN;

/*utility*/
extern char ** environ;
int c, r, k, i, j, l, m;
char ch;
/*char visual representation*/
char dot = 46;
char plus = 43;
char minus = 45;
char side = 124;
char flag = 126;
int player_id;
int id_smem;
struct board * scacchiera;

/*STRUCT*/
struct board{
	char * dati;
	int righe;
    int colonne;
};
typedef struct board board;

void createSharedMem();
void printBoard(const struct board * input);
void putFlags(const struct board * input, int SO_FLAG);
void freeBoard(struct board * input);
struct board * allocBoard(int SO_BASE, int SO_ALTEZZA);


/*PLAYERS*/
char nome;

/*PAWNS*/

/*COMMON*/
void printUpDownSpaces(const struct board * input);
void printMidSpaces(const struct board * input);