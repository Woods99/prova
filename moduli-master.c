#include "header.h"


board * allocBoard(int SO_BASE, int SO_ALTEZZA){
	struct board * input;
    
    input = malloc(sizeof(*input));
    input->colonne = SO_BASE;
	input->righe = SO_ALTEZZA;
	input->dati = malloc(sizeof(input->dati)*SO_ALTEZZA*SO_BASE);
    
    for(i = 0; i < input->righe; i++){
        for(j = 0; j < input->colonne; j++)
            input->dati[j+i*input->colonne] = dot;
        
    }
	return input;
}

/*void createSharedMem(struct board * input){
    id_smem = shmget(IPC_PRIVATE, sizeof(input)*SO_NUM_G*SO_NUM_P, IPC_CREAT|IPC_EXCL|0600);
    
}*/

void printUpDownSpaces(const struct board * input){
    for(c = 0; c < input->colonne; c++){
        if(c != input->colonne-1)
            printf("%c%c%c%c", plus, minus, minus, minus);
        else
            printf("%c%c%c%c%c\n", plus, minus, minus, minus, plus);
    }
}

void printMidSpaces(const struct board * input){
    for(r = 0; r < input->righe; r++){
        for(c = 0; c < input->colonne; c++){

            ch = input->dati[c+r*input->colonne];
            if(c != input->colonne-1){
                    printf("%c %c ", side, ch);
            }
            else{
                    printf("%c %c %c", side, ch, side);
            }
        }
        printf("\n");
        printUpDownSpaces(input);
    }
}

void printBoard(const struct board * input){
    printf("Stampa stato attuale scacchiera:\n");
    printUpDownSpaces(input);
    printMidSpaces(input);
    printf("\n");
}

void putFlags(const struct board * input, int SO_FLAG){
    
    for(i = 0; i < SO_FLAG; i++){
        l = rand()%input->righe;
        m = rand()%input->colonne;
        input->dati[m+l*input->colonne] = flag;
    }
}

void freeBoard(struct board *input)
{
	free(input->dati);
	free(input);
}