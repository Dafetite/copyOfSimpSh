#include "head.h"


/**
 * errorHandlerFxn - outputs an error message if file not found
 * @argv: array passed to function as arguments of strings
 * @arr: array of tokens the user entered
 * @comdcount_int: number of commands entered by user
 * @line: user;s input
 * @nline: the user input without a newline char
 */

void errorHandlerFxn(char **argv, char **arr, int comdcount_int, char *line,
		   char *nline)
{
	char *numberC;

	numberC = intPrintFxn(comdcount_int);

	write(STDERR_FILENO, argv[0], strLenCounterFxn(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, numberC, strLenCounterFxn(numberC));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, arr[0], strLenCounterFxn(arr[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "not found\n", 10);
	free(numberC);
	freeAllFxn(line, nline, arr);
	exit(0);
}

/**
 * pathHandlerFxn - loops through the PATH variable to
 * concatenate with the appropraite command
 * @str: the PATH variables to concatenate
 * @env: environment variable n
 * Return: pointer to the concatenated string matched
 */


char *pathHandlerFxn(char *str, char **env)
{
	char *patH, *conctnt;
	linked_t *lisT, *temP;
	struct stat strtre;

	if (str == NULL || env == NULL || *env == NULL)
		return (NULL);
	/* 2NE */
	patH = envPathFxn("PATH", env);
	if (patH == NULL)
	{
		write(STDERR_FILENO, "PATH not found", 14);
		_exit(0);
	}
	lisT = createLinkedtFxn(patH);
	if (lisT == NULL)
	{
		write(STDERR_FILENO, "Issues with PATH", 16);
		_exit(0);
	}
	lisT = addNodesListFxn(patH, lisT);
	temP = lisT;
	while (temP != NULL)
	{
		/* 3 */
		if (patH[0] != ':')
			conctnt = stringConcatingFxn(temP->directory, str);
		else
			conctnt = stringConcatingFxn("./", str);
		if (conctnt == NULL)
			return (NULL);
		if (stat(conctnt, &strtre) == 0 && access(conctnt, X_OK) == 0)
		{
			freeListFxn(lisT);
			return (conctnt);
		}
		temP = temP->next;
		free(conctnt);
	}
	freeListFxn(lisT);
	return (NULL);
}

