/*
 * Author: William Schuhmann
 *
 * Date: 6/7/2020
 *
 * Description: Homework 2 C File
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Macros for Part 2
#define sub_macro(A, B)(A - B)
#define cube_macro(x)(x*x*x)
#define min_macro(a, b)(((a)<(b)) ? (a) : (b))
#define odd_macro(n) ((n % 2 == 0) ? 1 : 0)

//-------------------------------------------------------------------------- PART 1 -----------------------------------------------------------------------------

int menu()	//Menu Function
{
	int choice;
	printf("Welcome to the CSE240 Assignment 2!\n");
	printf("Menu:\n");
	printf("1 - CSE240 Mini-Game Collection\n");
	printf("2 - Macros vs Functions Throw-down\n");
	printf("0 - Exit\n");
	printf("Choose an option:\n");
	scanf("%d", &choice);
	switch(choice)
        {
		case 1:
                        miniGame();
                        break;
                case 2:
			macroFunc();
                        break;
                case 0:
                        break;
                default:
                        printf("Invalid Input\n");
                        break;
        }
}

int miniGame()	//Mini game function - Case 1 in switch statement.
{
	char name[30] = " ";
        int randomVal;
        srand(time(NULL));
        randomVal = RandomInRange(1, 100);
        getName(randomVal, name);
	
	int numRounds;
	printf("Welcome to CSE240 Mini-Game Collection!\n");
	printf("I am your opponent %s ", name);
												
	printf("\nHow many rounds should we play? (Choose an odd number)\n");	//Rounds Played
	do
	{
		scanf("%d", &numRounds);
		if (numRounds % 2 == 0 || numRounds < 0)
		{
			printf("Invalid input, must be positive and even.\n");
		}
	}while(numRounds % 2 == 0 || numRounds < 0);
	
	int playerScore = 0;            //Player Score
        int opScore = 0;                //Opponent Score
	int i;
	int outcome;
	for(i = 1; i <= numRounds; i++){
		int randGame = RandomInRange(1, 4);
		switch(randGame)
		{	
			case 1:
				outcome = evenOddGame(name);
				 if (outcome == 1)
                                {
                                        playerScore++;
                                }
                                else if(outcome == 2)
                                {
                                        opScore++;
                                }
				printf("The score is:\n");
				printf("Player: %d\n", playerScore);
				printf("%s: %d\n", name, opScore); 
				break;
			case 2:
				outcome = rpsGame();
				if (outcome == 1)
				{
					playerScore++;
				}
				else if(outcome == 2)
				{
					opScore++;
				}
                                printf("The score is:\n");
                                printf("Player: %d\n", playerScore);
                                printf("%s: %d\n", name, opScore);
				break;
			case 3:
				outcome = guessGame();
                                if (outcome == 1)
                                {
                                        playerScore++;
                                }
                                else if(outcome == 2)
                                {
                                        opScore++;
                                }

				printf("The score is:\n");
                                printf("Player: %d\n", playerScore);
                                printf("%s: %d\n", name, opScore);
				break;
			case 4:
				outcome = diceGame();
                                if (outcome == 1)
                                {
                                        playerScore++;
                                }
                                else if(outcome == 2)
                                {
                                        opScore++;
                                }
				printf("The score is:\n");
                                printf("Player: %d\n", playerScore);
                                printf("%s: %d\n", name, opScore);
				break;
			default:
				printf("Invalid Input\n");
				break;	
		}
	}	
	int winsNeeded = (numRounds - 1) / 2 + 1;
	if(playerScore == winsNeeded)
	{
		printf("Player wins! Congratulations\n");
		menu();
	}
	else if(opScore == winsNeeded)
	{
		printf("%s has beaten you!\n", name);
		menu();
	}
}

//Mini Game Functions (Evens or Odds, Rock Paper Scissors, Number Guessing)

int evenOddGame(char name[30])	// Even or Odds
{
	int playerGuess;
	int playerNum;
	printf("Even/Odd game!\n");
	printf("Guess even or odd! (0 for even, 1 for odd):");
		scanf("%d", &playerGuess);
	printf("Enter a number (between 0 and 100):");
		scanf("%d", &playerNum);
	int compNum;
	compNum = RandomInRange(1, 100);
	printf("Computer picked %d\n", compNum);
	int sum = compNum + playerNum;
	
	if (sum % 2 == 0)
	{
		printf("%d + %d = %d - EVEN!\n", playerNum, compNum, sum);
		if(playerGuess == 0)
		{
			printf("Player wins the round!\n");
			return 1;
		}
		else if (playerGuess == 1)
		{
			printf("%s wins the round!\n", name);
			return 2;
		}
	}
	else if (sum % 2 != 0)
	{
		printf("%d + %d = %d - ODD!\n", playerNum, compNum, sum);
		if(playerGuess == 1)
                {
                        printf("Player wins the round!\n");
			return 1;
                }
                else if (playerGuess == 0)
                {
                        printf("%s wins the round!\n", name);
			return 2;
                }
	}
}
int rpsGame(char name[30])		//Rock Paper Scissors
{
	printf("Rock, Paper, Scissors game!\n");
	printf("Choose a throw!\n");
	printf("1. Rock\n");
	printf("2. Paper\n");
	printf("3. Scissors\n");

	int playerThrow;
	scanf("%d", &playerThrow);
	int opThrow = RandomInRange(1,3);

	if (playerThrow == 1)		//Player Throws Rock (1).
	{
		if(opThrow == 1) 
		{
			printf("Draw! Both players threw rock.\n");
			return 0;
		}
		else if(opThrow == 2)
		{
			printf("%s wins, paper beats rock.\n", name);
			return 2;
		}
		else if(opThrow ==3)
		{
			printf("Player wins, rock beats scissors.\n");
			return 1;
		}
	}
	else if (playerThrow == 2)		//Player Throws Paper (2).
	{
		if(opThrow == 1)
                {
			printf("Player wins, paper beats rock.\n");
			return 1;
                }
                else if(opThrow == 2)
                {
			printf("Draw! Both players threw paper.\n");
			return 0;
                }
                else if(opThrow ==3)
                {
			printf("%s wins, scissors beats paper.\n", name);
			return 2;
                }
	}
	else if (playerThrow == 3)		//Player Throws Scissors (3).
	{
		if(opThrow == 1)
                {
			printf("%s wins, rock beats scissors.\n", name);
			return 2;
                }
                else if(opThrow == 2)
                {
			printf("Player wins, scissors beats paper.\n");
			return 1;
                }
                else if(opThrow ==3)
                {
			printf("Draw! Both players threw scissors.\n");
			return 0;
                }
	}
}

int guessGame(char name[30])	//Number Guessing
{
	printf("Number Guessing game!\n");
	int randomMax;
	int randomMin;
	int rand1;
	int rand2;
	int playerGuess;	
	int actualNum;
	int guessCount = 1;	
	do{
		rand1 = RandomInRange(1, 999);
	        rand2 = RandomInRange(1, 999);

		if (rand1 - rand2 > 0 && rand1 - rand2 >= 30 && rand1 - rand2 <= 100)
		{	
			randomMax = rand1;	
			randomMin = rand2;
		}	
		else if (rand2 - rand1 > 0 && rand2 - rand1 >= 30 && rand2 - rand1 <= 100)
		{	
			randomMax = rand2;
			randomMin = rand1;
		}
	}while((rand1 - rand2 > 0 || rand2 - rand1 > 0) && (rand1 - rand2 >= 30 || rand2 - rand1 >= 30) && (rand1 - rand2 <= 100 || rand2 - rand1 <= 100));

	printf("Player, I'm thinking of a number between %d and %d!\n", randomMin, randomMax);
	actualNum = RandomInRange(randomMin, randomMax);
	printf("You have 5 guesses!\n");
	
	while(playerGuess != actualNum)
	{
		printf("What's guess #%d?\n", guessCount);
        	scanf("%d", &playerGuess);
		if(playerGuess < actualNum)
		{
			printf("My number is higher!\n");
			guessCount++;
		}
		else if(playerGuess > actualNum)
		{
			printf("My number is lower!\n");
			guessCount++;
		}
	}
	if(guessCount < 5 && playerGuess == actualNum)
		{
			printf("Player wins!\n");
			return 1;
		}
		else if(guessCount == 5 && playerGuess != actualNum)
		{
			printf("Out of guesses, %s wins!\n", name);
			return 2;
		}
	
}

int diceGame(char name[30])		//Dice Roll Showdown
{
	int numSides;
	int numDice;
	printf("Dice Roll Showdown!\n");
	printf("How many sides do the dice have? (input a positive number):\n");
	scanf("%d", &numSides);	
	printf("How many dice will each player roll?\n");
	scanf("%d", &numDice);
	int i;
	int pRoll;
	int pRollSum = 0;
	printf("Player Rolled:\n");
	for (i = 1; i <= numDice; i++)
	{
		pRoll = RandomInRange(1, numSides);
		printf("%d\n", pRoll);
		pRollSum = pRollSum + pRoll;
	}	
	printf("Total: %d\n", pRollSum);

	int opRoll;
	int opRollSum = 0;
	for (i = 1; i <= numDice; i++)
        {
                opRoll = RandomInRange(1, numSides);
                printf("%d\n", opRoll);
                opRollSum = opRollSum + opRoll;
        }       
        printf("Total: %d\n", opRollSum);
	
	if(pRollSum > opRollSum)
	{
		printf("Player Wins!\n");
		return 1;
	}
	else if(opRollSum > pRollSum)
	{
		printf("%s Wins!\n", name);
		return 2;	
	}
	
	
}

int RandomInRange(int min, int max)	//Random number function, used to generate random number between min and max.
{
   	return ((rand() % max) + min);
}

void getName(int randVal, char *name)	//Iterates through list of names using random number.
{
	int i;
	FILE *fp;
	fp = fopen("random_names.txt", "r");	//Accesses random_names.txt for list of possible opponent names. 
	for(i=1; i<=100; i++)
	{
		fscanf(fp, "%s", name);
		if(i == randVal)
		{			
			return;
		}		
	}	
	fclose(fp);
}

//----------------------------------------------------------------------- PART 2 --------------------------------------------------------------------------------

int subf(int a, int b){
	return a - b;
}

int cubef(int a){
	return a * a * a;
}

int minf(int a, int b){
	if (a <= b){
		return a;
	} else{
		return b;
	}
}

int oddf(int a){
	if(a % 2 == 0){
		return 0;
	} else{
		return 1;
	}
}

int macroFunc()
{

	int a = 10, b = 17;
	subf(a, b);
    	printf("subf(a, b) = %d\n" , subf(a, b));

   	sub_macro(a, b);
    	printf("sub_macro(a, b) = %d\n" , sub_macro(a, b));

	subf(a++, b--);
    	printf("subf(a++, b--) = %d\n" , subf(a++, b--));

    	a = 10, b = 17;
    	sub_macro(a++, b--);
    	printf("sub_macro(a++, b--) = %d\n" , sub_macro(a++, b--));


    	a = 10, b = 17;
    	cubef(a);
    	printf("cubef(a) = %d\n" , cubef(a));

    	cube_macro(a);
    	printf("cube_macro(a) = %d\n" , cube_macro(a));

    	cubef(--a);
    	printf("cubef(--a) = %d\n" , cubef(--a));

	a = 10, b = 17;
    	cube_macro(--a);
    	printf("cube_macro(--a) = %d\n" , cube_macro(--a));


    	a = 10, b = 17;
    	minf(a, b);
    	printf("minf(a, b) = %d\n" , minf(a, b));

	min_macro(a, b);
    	printf("min_macro(a, b) = %d\n" , min_macro(a, b));

    	minf(--a, --b);
    	printf("minf(--a, --b) = %d\n" , minf(--a, --b));

    	a = 10, b = 17;
    	min_macro(--a, --b);
    	printf("minm(--a, --b) = %d\n" , min_macro(--a, --b));


	a = 10, b = 17;
    	oddf(a);
    	printf("oddf(a) = %d\n" , oddf(a));

    	odd_macro(a);
    	printf("odd_macro(a) = %d\n" , odd_macro(a));

	oddf(a++);
        printf("oddf(a++) = %d\n" , oddf(a++));

    	a = 10, b = 17;
    	odd_macro(a++);
    	printf("odd_macro(a++) = %d\n" , odd_macro(a++));


    	return 0;

}


void main()	//Main Function
{
	menu();
}
