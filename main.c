/*
The main task is to make a rock paper scissors game with AI

Made by Dominykas
*/

#include <stdio.h>          //Default
#include <time.h>           //For seed
#include <stdlib.h>         //Random selection generation
#include <string.h>         //For use in strcpy
#include <stdbool.h>        //For use in checkSelection function

void printResult(int gamestate){
	if(gamestate == 2){
		printf("%s,\n", "Draw!");
	}
	if(gamestate == 1){
		printf("%s,\n", "You win!");
	}
	if(gamestate == 0){
		printf("%s,\n", "You lose!");
	}
}

void checkSelection(char guess[], char selection[], int *gamestate){
	if(strcmp(guess, "rock") == 0){
		printf("%i\n", 1);
		if(!strcmp(selection, "paper")){
			*gamestate = 0;
		}
		if(!strcmp(selection, "scissors")){
			*gamestate = 1;
		}
		if(!strcmp(selection, "rock")){
			*gamestate = 2;
		}
	}
	if(strcmp(guess, "paper") == 0){
		printf("%i\n", 2);
		if(!strcmp(selection, "paper")){
			*gamestate = 2;
		}
		if(!strcmp(selection, "scissors")){
			*gamestate = 0;
		}
		if(!strcmp(selection, "rock")){
			*gamestate = 1;
		}
	}
	if(strcmp(guess, "scissors") == 0){
		printf("%i\n", 3);
		if(!strcmp(selection, "paper")){
			*gamestate = 1;
		}
		if(!strcmp(selection, "scissors")){
			*gamestate = 2;
		}
		if(!strcmp(selection, "rock")){
			*gamestate = 0;
		}
	}
}

void randomSelection(char selection[]){
	srand(time(NULL));
	int randNum = rand() % 3;
	
	if(randNum == 0){
		strcpy(selection, "rock");
	}else if(randNum == 1){
		strcpy(selection, "paper");
	}else{
		strcpy(selection, "scissors");
	}
}

int main(void){
	char guess[100];
	char selection[100];
	int gamestate = 0;
	
	printf("%s", "Type in: rock, paper or scissors.\n");
	fgets(guess, 99, stdin);

	randomSelection(selection);
	printf("%s %s %s %s\n", "Guess: ", guess, "Computer guess: ", selection);

	checkSelection(guess, selection, &gamestate);
	printf("%i\n", gamestate);

	printResult(gamestate);
	return 0;
}
