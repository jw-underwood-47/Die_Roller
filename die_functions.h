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

#include "string_parse.h"

/* take a string specifying number and size of dice in format
 * [num][d]size, such as 4d8.  For single dice, can just pass
 * in "d6" or 6. Returns roll or sum of all rolls. */
int roll_dice(char* type_and_num){
    int index;
    if ((index = char_in_string('d', type_and_num)) == -1){ // only one die
        int mod = atoi((type_and_num[0] == 'd') ? &type_and_num[1] : type_and_num);
        int result = (rand()%mod)+1;
        return result;
    }
    else{ // user wants to roll multiple identical dice
        int num_dice = atoi(type_and_num), total = 0, result;
        int mod = atoi(&type_and_num[index+1]); // max value of die
        for (int i = 0; i < num_dice; i++){ // roll all the dice
            result = (rand()%mod)+1;
            printf("Die %d: %d\n", i, result);
            total += result;
        }
        return total;
    }
}

/* take a string corresponding to a die modifier and return an int.
 * string can say to roll dice to determine modifier with [num][d]size
 * using roll_dice */
int get_mod (char* input){
    int result;
    int pos = (input[0] == '+') ? 1 : 0;
    if (char_in_string('d', input) != -1){
        result = roll_dice(&input[1]);
    }
    else{
        result = atoi(&input[1]);
    }
    return (pos) ? result : -result;
}
