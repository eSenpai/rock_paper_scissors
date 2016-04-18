/*
The main task is to make a rock paper scissors game with AI

Made by Dominykas
*/

#include <stdio.h>          //Default
#include <time.h>           //For seed
#include <stdlib.h>         //Random selection generation
#include <string.h>         //For use in strcpy
#include <stdbool.h>        //For use in checkSelection function

//Prints the result, ie if the user losses, wins or it is a draw
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

//Compares the users guess with the computers selection and changes the gamestate
//The gamestate sets if the player is going to win, lose or it is going to be a draw
void checkSelection(char guess[], char selection[], int *gamestate){
	if(strcmp(guess, "rock") == 0){
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

//Generates a computer selection
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
	char guess[100];         //The users guess ie. (rock, paper, scissors)
	char selection[100];     //The computers selection (rock, paper, scissors)
	int gamestate = 0;       //Makes the user win, lose or the game is a draw
	
	printf("%s", "Type in: rock, paper or scissors.\n");
	fgets(guess, 99, stdin);
	guess[strlen(guess)-1] = '\0';      //Sets the last character as a null terminator, so it can be compared

	randomSelection(selection);         //Gets a random selection for the computer
	printf("%s %s %s %s\n", "Guess: ", guess, "Computer guess: ", selection);

	checkSelection(guess, selection, &gamestate);  //Checks who won or if it is a draw

	printResult(gamestate);             //Prints the result
	return 0;
}
