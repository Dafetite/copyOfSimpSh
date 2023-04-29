#include "head.h"

/**
 * checkBFxns - this function checks if th command
 * passed exist in the shell or not
 * @arr: aarray of str commands for execution
 * @env: environment variable(s)
 * @line: user's input
 * @newline: the user input but without a
 * newline character
 * @changedirnum: number of commands the user entered
 *
 * Return: 0 if command is found and 1 if not
 */

int checkBFxns(char **arr, char **env, char *line,
char *newline, int changedirnum)
{
	if (arr == NULL || *arr == NULL)
		return (1);
	if (env == NULL || *env == NULL)
		return (1);
	if (stringsCompareFxn((arr[0]), "exit") == 0)
		return (exitHandlerFxn(arr, line, newline, changedirnum));

	/* 4 */
	else if (stringsCompareFxn((arr[0]), "env") == 0)
		return (environHandlerFxn(env));

	else if (stringsCompareFxn((arr[0]), "cd") == 0)
		return (changeDirHandlerFxn(arr, env));

	else
		return (1);
}

