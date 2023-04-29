#include "head.h"

/**
 * tensFxn - calculates and finds the factor of tens
 * @i: starting index of the string
 * @s: pointer to the str
 * Return: the tens multiplier if successful
 */

int tensFxn(int i, char *s)
{
	double tensVar = 1;

	while (s[i] >= '0' && s[i] <= '9')
	{
		tensVar *= 10;
		i++;
	}
	tensVar /= 10;
	return ((int) tensVar);
}

