/*
 * Author: William Schuhmann
 *   
 * Date: 6/26/2020
 *
 * Description: Homework 3 C File
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char** GenerateLand(int width, int height);
char PickLandType();
char GenerateNeighbor(char item);
void PrintLand(char** land, int width, int height);
char NewFromRuralLand();
char NewFromForest();
char NewFromTown();
char NewFromWater();
char NewFromCity();
char NewFromMountain();


char** GenerateLand(int width, int height)
{
	char** land;	
	land = (char**)(malloc(height * sizeof(char*)));
	int i;
	int j;
	
	for (i = 0; i < width; i++)
	{
		land[i] = (char*)(malloc(width * sizeof(char))); 
	}
	
	land[0][0] = PickLandType();
//	printf("Before first column\n");
	for(i = 0; i < height - 1; i++)
	{
		land[i+1][0] = GenerateNeighbor(land[i][0]);
	}
//	printf("after fisrt column\n");
//	printf("land: \n");
	PrintLand(land, width, height);

	for(int i = 0; i < width -1; i++)
	{
		land[0][i+1] = GenerateNeighbor(land[0][i]);
	}
	PrintLand(land, width, height); 
	for(i = 1; i < height; i++)
	{
		for(j = 1; j < width - 1; j++)
		{
	//			printf("fill other rows i, j = %d, %d", i, j);
				int random = (rand() % 2);
//				printf("random for coin toss %d\n", random);
				if(random == 0)
				{
				//	printf("coin toss rand == 0 land[i-1][j] %c\n", land[i-1][j]);
					land[i][j] = GenerateNeighbor(land[i-1][j]);
				}else
				{
				//	printf("rand != 0 land[i][j-1] %c\n", land[i][j-1]);
					land[i][j] = GenerateNeighbor(land[i][j-1]);
				}
				//	printf("after generate neighbor");
				PrintLand(land, width, height);	
		}
	}
	return land; 
}

char PickLandType()
{
	char optionBank[6] = "RFTCMW";
	int option = ((rand() % 6) + 1);
	char seed = optionBank[option];
	printf("Seed: %c\n", seed);
	return seed;
	
}

char GenerateNeighbor(char item)
{
//	printf("item in gen neigh %c\n", item);
	switch(item)	
	{
		case 'R': 
			return NewFromRuralLand();
			break;
		case 'F':
			return NewFromForest();
			break;
		case 'T':
			return NewFromTown();
			break;
		case 'C':
			return NewFromCity();
			break;
		case 'M':
			return NewFromMountain();
			break;
		case 'W':
			return NewFromWater();
			break;
		default:
			printf("Invalid Input\n");
			break;
		
	}
}

void PrintLand(char** land, int width, int height)
{
	int i;
	int j;
	printf("in print land");
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			printf("%c", land[i][j]);
		}
		printf("\n");
	}
}

//Following functions to be called GenerateNeighbor(char item) function.

char NewFromRuralLand()
{
//	printf("new from rural land\n");
	int randomNum = ((rand() % 99) + 0);
	if (randomNum >= 0 && randomNum<= 9)	//0-9 W 10%
	{
		return 'W';
	}else if (randomNum >= 10 && randomNum <= 19)	//10-19 M 10%
	{
		return 'M';
	}else if (randomNum >= 20 && randomNum <= 34)	//20-34 T 15% 
	{
		return 'T';
	}else if (randomNum >= 35 && randomNum <= 59)	//35-59 F 25%
	{
		return 'F';
	}else	//R 40%
	{
		return 'R';
	}
}

char NewFromForest()
{
//	printf("new from forest\n");
	int randomNum = ((rand() % 99) + 0);
        if (randomNum >= 0 && randomNum <= 19)     //0-19 W 20%
        {       
                return 'W'; 
        }else if (randomNum >= 20 && randomNum <= 34)     //20-34 M 15%
        {       
                return 'M'; 
        }else if (randomNum >= 35 && randomNum <= 39)   //35-39 T 5% 
        {       
                return 'T'; 
        }else if (randomNum >= 40 && randomNum <= 79)   //40-79 F 40%
        {       
                return 'F';
        }else   //R 20%
        {       
                return 'R';
        }
}

char NewFromTown()
{
//	printf("new from town\n");
	int randomNum = ((rand() % 99) + 0);
        if (randomNum >= 0 && randomNum <= 9)     //0-9 W 10%
        {       
                return 'W'; 
        }else if (randomNum >= 10 && randomNum <= 14)     //10-14 M 15%
        {       
                return 'M'; 
        }else if (randomNum >= 15 && randomNum <= 34)   //15-34 C 20% 
        {       
                return 'C'; 
        }else if (randomNum >= 35 && randomNum <= 74)   //35-74 T 40%
        {       
                return 'T';
        }else if (randomNum >75 && randomNum <= 79)	//75-79 F 5%
        {       
                return 'F';
        }else	//R 10%
	{
		return 'R';
	}
}

char NewFromWater()
{
//	printf("new from water\n");
	int randomNum = ((rand() % 99) + 0);
        if (randomNum >= 0 && randomNum <= 39)     //0-39 W 40%
        {
                return 'W';
        }else if (randomNum >= 40 && randomNum <= 49)     //40-49 M 10%
        {
                return 'M';
        }else if (randomNum >= 50 && randomNum <= 59)   //50-59 C 10% 
        {
                return 'C';
        }else if (randomNum >= 60 && randomNum <= 64)   //60-64 T 5%
        {
                return 'T';
        }else if (randomNum >65 && randomNum <= 84)     //65-84 F 20%
        {
                return 'F';
        }else   //R 15%
        {
                return 'R';
        }

}

char NewFromCity()
{
//	printf("new from city\n");
	int randomNum = ((rand() % 99) + 0);
        if (randomNum >= 0 && randomNum <= 9)     //0-9 W 10%
        {
                return 'W';
        }else if (randomNum >= 10 && randomNum <= 19)     //10-19 M 10%
        {
                return 'M';
        }else if (randomNum >= 20 && randomNum <= 59)   //20-59 C 40% 
        {
                return 'C';
        }else if (randomNum >= 60 && randomNum <= 84)   //60-84 T 25%
        {
                return 'T';
        }else	//F 15%
        {
                return 'F';
        }
}

char NewFromMountain()
{
//	printf("new from mountain\n");
	int randomNum = ((rand() % 99) + 0);
        if (randomNum >= 0 && randomNum <= 14)     //0-14 W 15%
        {
                return 'W';
        }else if (randomNum >= 15 && randomNum<= 64)     //15-64 M 50%%
        {
                return 'M';
        }else if (randomNum >= 65 && randomNum <= 74)   //65-74 C 10% 
        {
                return 'C';
        }else if (randomNum >= 75 && randomNum <= 79)   //75-79 T 50%
        {
                return 'T';
        }else if (randomNum >80 && randomNum <= 94)     //80-94 F 15%
        {
                return 'F';
        }else   //R 5%
        {
                return 'R';
        }

}

//Main Function

int main()
{
	int width;
	int height;
	printf("Welcome to Fantasy Land Generator!\n");
	printf("Please enter a width (must be between 20 and 50):");
	scanf("%d", &width);
	printf("Please enter a height (must be between 20 and 50):");
	scanf("%d", &height);
	
	char** land = GenerateLand(width, height);
//	printf("before print land in main");
	PrintLand(land, width, height);
//	printf("after print in main");
	return 0;			
}

