#include "moduli-master.c"


int main(){
    srand(time(0));
    SO_BASE = atoi(getenv("SO_BASE"));
    SO_ALTEZZA = atoi(getenv("SO_ALTEZZA"));
    SO_FLAG_MAX = atoi(getenv("SO_FLAG_MAX"));
    SO_FLAG_MIN = atoi(getenv("SO_FLAG_MIN"));
    SO_NUM_G = atoi(getenv("SO_NUM_G"));
    SO_NUM_P = atoi(getenv("SO_NUM_P"));
    SO_MAX_TIME = atoi(getenv("SO_MAX_TIME"));
    SO_N_MOVES = atoi(getenv("SO_N_MOVES"));
    SO_ROUND_SCORE = atoi(getenv("SO_ROUND_SCORE"));
    SO_FLAG = rand()%(SO_FLAG_MAX+1-SO_FLAG_MIN)+SO_FLAG_MIN;

    scacchiera = allocBoard(SO_BASE, SO_ALTEZZA);
    putFlags(scacchiera, SO_FLAG);
    printBoard(scacchiera);
    for(i = 0; i < SO_NUM_G; i++){
        player_id = fork();
    } 
}
ciao



