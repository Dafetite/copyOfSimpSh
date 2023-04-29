#include "head.h"


/**
 * memReallocationFxn - WILL reallocate memory
 * @ptr: points to the arr
 * Return: pointer to newly allocated memory
 */
char *memReallocationFxn(char *ptr)
{
	int countA = 0;
	char *pointerVar;

	if (ptr == NULL)
		return (NULL);

	while (*(ptr + countA) != '\n')
		countA++;

	pointerVar = malloc(sizeof(char) * countA + 1);
	if (pointerVar == NULL)
		return (NULL);
	/* 10NE */
	else
		countA = 0;

	while (*(ptr + countA) != '\n')
	{
		*(pointerVar + countA) = *(ptr + countA);
		countA++;
	}
	*(pointerVar + countA) = '\0';
	return (pointerVar);
}

