#include "head.h"

/**
 * strDuplicateFxn - rets a pointer to allocated space
 * containing the copy of orig string
 * @str: str that will be copied into the newly allocated space
 * Return: pointer to the newly allocated space
 */
char *strDuplicateFxn(char *str)
{
	int count1 = 0;
	int len = 0;
	char *newStr;

	if (str == NULL)
		return (NULL);

	while (*(str + count1) != '\0')
	{
		len++;
		count1++;
	}

	count1 = 0;
	newStr = malloc(sizeof(char) * len + 1);

	if (newStr == NULL)
		return (NULL);

	while (*(str + count1) != '\0')
	{
		*(newStr + count1) = *(str + count1);
		count1++;
	}
	*(newStr + count1) = '\0';
	return (newStr);
}

/**
 * concatFxn - concats strs
 * @concatenate: memory space to use for concatenation
 * @s1: string 1
 * @s2: string 2
 * Return: points to concatenated allocated memory space
 */

char *concatFxn(char *concatenate, char *s1, char *s2)
{
	int cCount = 0;
	int sSount = 0;

	while (*(s1 + sSount) != '\0')
	{
		*(concatenate + cCount) = *(s1 + sSount);
		cCount++;
		sSount++;
	}

	sSount = 0;
	while (*(s2 + sSount) != '\0')
	{
		*(concatenate + cCount) = *(s2 + sSount);
		cCount++;
		sSount++;
	}
	*(concatenate + cCount) = '\0';
	return (concatenate);
}

/**
 * strLenCounterFxn - counts the chars of a string
 * @s: string parameter
 * Return: length of str
 */

int strLenCounterFxn(char *s)
{
	int lengtH = 0;
	int count = 0;

	if (s == NULL)
		return (-1);

	while (s[count] != '\0')
	{
		lengtH = lengtH + 1;
		count++;
	}

	return (lengtH);

}

/**
 * stringConcatingFxn - will appends source chars to the destination str
 * @s1: str - s1
 * @s2: str - s1
 * Return: the concatd str
 */
char *stringConcatingFxn(char *s1, char *s2)
{
	int lenA = 0;
	int lenB = 0;
	char *concat;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		/* 8NE */
		else
			*s1 = '\0';
	}

	if (s2 == NULL)
	{
		s2 = malloc(sizeof(char));
		if (s2 == NULL)
			return (NULL);
		/* 9NE */
		else
			*s2 = '\0';
	}

	lenA = strLenCounterFxn(s1);
	lenB = strLenCounterFxn(s2);

	concat = malloc(sizeof(char) * (lenA + lenB + 1));
	if (concat == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}

	return (concatFxn(concat, s1, s2));
}


/**
 * stringsCompareFxn - Compares 2 strings pointed to
 * @s1: pointer to s1
 * @s2: pointer to s2
 * Return: negative if s1 < s2 or 0 if s1 = s2 and positve if if s1 > s2
 */

int stringsCompareFxn(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}

	if ((*s1 == '\0') && (*s2 == '\0'))
		return (0);
	else if (*s1 > *s2)
		return ((int)(*s1 - *s2));
	else
		return ((int)(*s1 - *s2));
}

