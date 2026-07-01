#include "string_parse.h"

int roll_dice(char* type_and_num){
    int index;
    if ((index = char_in_string('d', type_and_num)) == 0){
        int mod = atoi((type_and_num[0] == 'd') ? &type_and_num[1] : type_and_num);
            printf("You rolled a %d\n", (rand()%mod)+1);
        }
        else{ // user wants to roll multiple identical dice
            int num_dice = atoi(type_and_num), total = 0, result;
            int mod = atoi(&type_and_num[index+1]);
            for (int i = 0; i < num_dice; i++){
                result = (rand()%mod)+1;
                printf("Die %d: %d\n", i, result);
                total += result;
            }
            printf("Your total roll is %d\n", total);
        }

}
