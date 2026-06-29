MAIN_ROLLER=roll_die
CC=gcc

default:
	$(CC) -o $(MAIN_ROLLER).exe $(MAIN_ROLLER).c
