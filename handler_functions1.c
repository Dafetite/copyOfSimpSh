#include "head.h"

/**
 * exitHandlerFxn - handles the exit builtin
 * @array: -array of str commands for execution
 * @line: -input from user
 * @newline: -truncated newline from user input
 * @cmd_count: -number of commands entered by the user
 * Return: exit code specified by user or 0 for success
 */

int exitHandlerFxn(char **array, char *line, char *newline, int cmd_count)
{
	int numberC, count = 0;
	char *numberComm;

	/* 1 */
	if (array[1] != NULL)
	{
		numberC = atoIFxn(array[1]);
		if (numberC == -1)
		{
			numberComm = intPrintFxn(cmd_count);
			write(STDERR_FILENO, array[0], 7);
			write(STDERR_FILENO, numberComm, strLenCounterFxn(numberComm));
			write(STDERR_FILENO, ": exit: Illegal number: ", 24);
			while (array[1][count] != '\0')
				count++;
			write(STDOUT_FILENO, array[1], count);
			write(STDOUT_FILENO, "\n", 1);
			return (0);
		}
		/* 1NE */
		else
		{
			freeAllFxn(line, newline, array);
			_exit(numberC);
		}
	}

	else
	{
		freeAllFxn(line, newline, array);
		exit(2);
	}
}


/**
 * changeDirHandlerFxn - handle change directory builtin
 * @array:  -aarray of str commands for execution
 * @env: -environment variable(s)
 * Return: 0 for success
 */

int changeDirHandlerFxn(char **array, char **env)
{
	int count = 0;
	char cWorkingDir[1024];
	char *directoryN;

	/* 2 */
	if (array[1] != NULL)
	{
		getcwd(cWorkingDir, 1024);
		while (cWorkingDir[count] != '\0')
			count++;
		cWorkingDir[count++] = '/';
		cWorkingDir[count] = '\0';
		directoryN = stringConcatingFxn(cWorkingDir, array[1]);
		if (directoryN == NULL)
			return (0);
		if (chdir(directoryN) == -1)
		{
			perror(array[0]);
			write(STDERR_FILENO, "can't cd into directory\n", 24);
		}
		free(directoryN);
	}
	else
	{
		if (chdir(envPathFxn("HOME", env)) == -1)
		{
			perror(array[0]);
			write(STDERR_FILENO, "cd: can't cd to home\n", 21);
		}
	}
	return (0);
}

/**
 * environHandlerFxn - handles the environment builtin
 * @env: -environment variable(s)
 * Return: 0 fro success
 */

int environHandlerFxn(char **env)
{
	int count = 0, strlen = 0;

	while (env[count] != NULL)
	{
		strlen = strLenCounterFxn(env[count]);
		write(STDOUT_FILENO, env[count], strlen);
		write(STDOUT_FILENO, "\n", 1);
		count++;
	}
	return (0);
}

/**
 * ctrlCHandlerFxn - the Ctrl C handler
 * @signum: -signal-number received by function
 * Return: void
 */

void ctrlCHandlerFxn(int signum)
{
	(void)signum;

	write(STDOUT_FILENO, "\n$ ", 3);
}


/**
 * ctrlDHandlerFxn - th Ctrl D handler
 * @line: main line buffer to be freed
 * Return: 0 for success
 */

int ctrlDHandlerFxn(char *line)
{
	free(line);
	if (isatty(STDIN_FILENO) == 1)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}

