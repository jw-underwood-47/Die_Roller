/*
 * Copyright (C) 2026 James Underwood
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as software
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <https://gnu.org>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string_parse.h"
#include <string.h>

int main(int argc, char*argv[]){
    srand(time(NULL));
    switch(argc){
        case 0:
        case 1: printf("error: expected at least one argument, got none\n");
                exit(-1);
        case 2: int index; 
        if ((index = char_in_string('d', argv[1])) == 0){
            int mod = atoi((argv[1][0] == 'd') ? &argv[1][1] : argv[1]);
            printf("You rolled a %d\n", (rand()%mod)+1);
        }
        else{ // user wants to roll multiple identical dice
            int num_dice = atoi(argv[1]), total = 0, result;
            int mod = atoi(&argv[1][index+1]);
            for (int i = 0; i < num_dice; i++){
                result = (rand()%mod)+1;
                printf("Die %d: %d\n", i, result);
                total += result;
            }
            printf("Your total roll is %d\n", total);
        }
    }
}
