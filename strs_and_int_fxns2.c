#include "head.h"


/**
 * atoIFxn - will converts str to int
 * @s: str to be converted
 * Return: the int val of the str
 */
int atoIFxn(char *s)
{
	int countA, countB = 0;
	int theTens = 1;
	unsigned int integerS = 0;
	int negS = 0;
	int negNum = 0;
	int posNum = 0;

	while (s[countB] != '\0')
	{
		if (s[countB] > '9' || s[countB] < '0')
			return (-1);
		countB++;
	}

	while ((s[countA] > '9' || s[countA] < '0') && s[countA] != '\0')
	{
		if (s[countA] == '-')
			negNum++;
		if (s[countA] == '+')
			posNum++;
		countA++;
	}
	if (s[countA] == '\0')
		return (0);

	if ((negNum % 2) != 0)
		negS = 1;

	theTens = tensFxn(countA, s);
	while (s[countA] >= '0' && s[countA] <= '9')
	{
		integerS += ((s[countA] - '0') * theTens);
		theTens /= 10;
		countA++;
	}

	if (negS == 1)
		integerS *= -1;

	return ((int) integerS);
}

