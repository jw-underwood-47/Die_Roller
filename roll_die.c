#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char*argv[]){
    srand(time(NULL));
    switch(argc){
        case 0:
        case 1: printf("error: expected at least one argument, got none\n");
                exit(-1);
        case 2: printf("You rolled a %d\n", (rand()%(atoi(argv[1])))+1);
    }
}
