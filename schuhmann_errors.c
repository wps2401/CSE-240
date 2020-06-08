/* schuhmann_errors.c
 * Author: William Schuhmann
 * Created on: May 26, 2020
 * ID: 1215016803
 */

#include <stdio.h>

// CSE 240 Code with Errors
// Before starting this assignment, please compile and run this program.
// You will first notice that the program will not compile. Fix the errors and define the error types.
// Next, you will notice that the program is printing incorrect information. Fix the errors and define those error types.

/* !!!!!!!!!!!!!!!!!!!!!
	This code is used in concert with an online quiz!
	Make sure you're using it correctly!

	You should fix the errors and compile and run the code on general.asu.edu

	Each Problem is answered online!
	!!!!!!!!!!!!!!!!!!!!
*/

/*
	Fix the errors, rename the file with your last name: <lastname>_errors.c and turn it in
*/
int main(int argc, char** argv)
{
	int problem = 0;

	// Problem 1
	printf("Problem #%d\n", problem);
	int value = 50;
	printf("Integer value is %d\n", value);

	problem++;

	// Problem 2
	printf("Problem #%d\n", problem);
	float fractionalNumber = 5.5;
	printf("Value: %f should be 5.5\n", fractionalNumber);

	problem++;

	// Problem 3
	printf("Problem #%d\n", problem);
	int fullValue = 66;
	printf("One-third of %d is %d\n", fullValue, fullValue * 1 / 3);

	problem++;

	// Problem 4
	printf("Problem #%d\n", problem);
	int amIWrong;
	int intValue;
	do
	{
		printf("Give me an integer value: x = ");
		amIWrong = scanf("%d", &intValue);
		if(amIWrong == 0) while ((getchar()) != '\n');
	}while(amIWrong == 0);

	problem++;

//Problem 5
	printf("Problem #%d\n", problem);
	if (intValue == 100)
		printf("x is equal to 100.\n");
	if (intValue > 100)
		printf("x is greater than 100.\n");
	if(intValue < 100)
		printf("x is less than 100.\n");

	problem++;

	// Problem 6
	printf("Problem #%d\n", problem);

	if (intValue % 2 == 0)
		printf("%d is an even number.\n", intValue);
	if (intValue % 2 != 0)
		printf("%d is an odd number.\n", intValue );

	problem++;

	// Problem 7
	char message[] = "World!";
	printf("Problem #%d\n", problem);
	printf("Hello %s\n", message);

	problem++;

	printf("Problem #%d\n", problem);
	printf("Did you find it?\n");

	problem ++ ;
	printf("Problem #%d\n", problem);

//DONE//
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
system("pause"); //pause the output with a "press anything to continue" so you can see output
#endif
}
