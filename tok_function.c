#include "head.h"
#define DELIMITERS " \t\0"

/**
 * tokenizeFxn - divides and stores the user input into tokens
 * @line: string to be divided
 * Return: the array of str(tokens)
 */

char **tokenizeFxn(char *line)
{
	int countA = 0;
	int tokCount = 0;
	char **tokArr;
	char *tok, *copyOfTok;

	if (line == NULL)
		return (NULL);
	while (*(line + countA) != '\0')
	{
		if (line[countA] != ' ' && (line[countA + 1] == ' '
		|| line[countA + 1] == '\0' || line[countA + 1] == '\t'))
			tokCount++;
		countA++;
	}

	countA = 0;
	tokArr = malloc(sizeof(char *) * (tokCount + 1));
	if (tokArr == NULL)
		return (NULL);
	tok = strtok(line, DELIMITERS);
	while (tok != NULL)
	{
		copyOfTok = strDuplicateFxn(tok);
		if (copyOfTok != NULL)
		{
			*(tokArr + countA) = copyOfTok;
			tok = strtok(NULL, DELIMITERS);
			countA++;
		}
		/* 13NE */
		else
		{
			free(tokArr);
			return (NULL);
		}
	}
	*(tokArr + countA) = NULL;
	return (tokArr);
}

