MAIN_ROLLER=roll_die
CC=gcc

default:
	$(CC) -o $(MAIN_ROLLER).exe $(MAIN_ROLLER).c
debug:
	$(CC) -g -o $(MAIN_ROLLER).exe $(MAIN_ROLLER).c
