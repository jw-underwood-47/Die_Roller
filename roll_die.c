#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char*argv[]){
    srand(time(NULL));
    if (argc == 2){
        printf("You rolled a %d\n", (rand()%(atoi(argv[1])))+1);
    }
}
