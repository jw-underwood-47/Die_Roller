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

int main(int argc, char*argv[]){
    srand(time(NULL));
    switch(argc){
        case 0:
        case 1: printf("error: expected at least one argument, got none\n");
                exit(-1);
        case 2: printf("You rolled a %d\n", (rand()%(atoi(argv[1])))+1);
    }
}
