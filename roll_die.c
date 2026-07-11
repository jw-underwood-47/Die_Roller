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
#include <string.h>
#include "die_functions.h"

int main(int argc, char*argv[]){
    srand(time(NULL));
    switch(argc){
        case 0:
        case 1: printf("error: expected at least one argument, got none\n");
                exit(-1);
        case 2: int total = roll_dice(argv[1]); 
                if(char_in_string('d', argv[1]) > 0){ // rolled several dice
                    printf("Your total roll is %d\n", total);
                }
                else{ // only one die rolled
                    printf("You rolled a %d\n", total);
                }
                exit(0);
        default: // multiple dice, or modifiers
                int index = 1, mod_total = 0, base_index;
                while (index < argc){
                    base_index = index;
                    while ((++index < argc) &&
                        (char_in_string('+', argv[index]) || char_in_string('-', argv[index]))){
                            mod_total += get_mod(argv[index]);
                        }
                    total = roll_dice(argv[base_index]) + mod_total;
                    printf("Your total roll is %d\n", total);
                }
    }
}
