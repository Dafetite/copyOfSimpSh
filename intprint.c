#include "head.h"

/**
 * intPrintFxn - print int
 * @num: numb value to convert into a str
 * Return: numb of char  that are eventually printed to stdout(standard output)
 */

char *intPrintFxn(int num)
{
	int intOfTens = num;
	char *intVal;
	int initTens = 1;
	int countA = 0;

	intVal = malloc(33);
	if (intVal == NULL)
		return (NULL);
	if (num != 0)
		num = num / 10;
	/* 14NE */
	else
	{
		intVal[countA] = 0 + '0';
		return (intVal);
	}

	while (num != 0)
	{
		num = num / 10;
		initTens *= 10;
	}

	while (initTens != 0)
	{
		intVal[countA] = (intOfTens / initTens) + '0';
		intOfTens = intOfTens % initTens;
		initTens /= 10;
		countA++;
	}
	intVal[countA] = '\0';
	return (intVal);
}

