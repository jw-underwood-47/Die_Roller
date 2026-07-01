#include "string_parse.h"

/* take an array specifying number and size of dice in format
 * [num][d]size, such as 4d8.  For single dice, can just pass
 * in "d6" or 6. Returns roll or sum of all rolls. */
int roll_dice(char* type_and_num){
    int index;
    if ((index = char_in_string('d', type_and_num)) == 0){
        int mod = atoi((type_and_num[0] == 'd') ? &type_and_num[1] : type_and_num);
            int result = (rand()%mod)+1;
            return result;
        }
        else{ // user wants to roll multiple identical dice
            int num_dice = atoi(type_and_num), total = 0, result;
            int mod = atoi(&type_and_num[index+1]);
            for (int i = 0; i < num_dice; i++){
                result = (rand()%mod)+1;
                printf("Die %d: %d\n", i, result);
                total += result;
            }
            return total;
        }

}
