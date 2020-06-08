/* schuhmann_mathloop.c
 * Author: William Schuhmann
 * Created on: May 26, 2020
 * ID: 1215016803
 */

#include <stdio.h>
void main()
{
	char ch;
	int a = 10, b = 20;
	double f = 0;
	int i;
	printf("ch = %c\n", ch);
	for(i=0; i<=5; i++)
	{
		scanf(" %c", &ch);
		printf("ch = %c\n", ch);
		switch (ch)
		{
			case '+': f = a + b;
				printf("f = %.0f\n", f);
				break;
			case '-': f = a - b;
				printf("f = %.0f\n", f);
				break;
			case '*': f = a * b;
				printf("f = %.0f\n", f);
				break;
			case '/': f = (double)a / (double)b;
				printf("f = %f\n", f);
				break;
			default: printf("Invalid Operator\n");
		}

	}
}
