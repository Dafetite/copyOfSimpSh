#include "head.h"

/**
 * executeCommandFxn - will execute a line of code in the shell
 * @ar: the array of str-commands that we want to executed
 * @env: the environment var
 * @av: the array of command line args
 * @line: the user input
 * @nline: user input with the newline (truncated)
 * @cmd_count: numb of user input commands
 * Return: success is 0 and -1 is failure
 */
int executeCommandFxn(char **ar, char **env, char **av,
char *line, char *nline, int cmd_count)
{
	pid_t pid;
	char *concatedst;
	int signaL;
	struct stat statuS;

	if (ar == NULL || *ar == NULL || av == NULL || *av == NULL)
		return (-1);
	if (env == NULL || *env == NULL)
		return (-1);
	if (checkBFxns(ar, env, line, nline, cmd_count) == 0)
		return (0);
	pid = fork();

	if (pid == -1)
	{
		write(STDOUT_FILENO, "Error forking", 13);
		return (-1);
	}
	if (pid != 0)
		wait(&signaL);
	else
	{
		if (ar[0][0] != '/')
		{
			concatedst = pathHandlerFxn(ar[0], env);
			if (concatedst == NULL)
				errorHandlerFxn(av, ar, cmd_count, line, nline);
			else
				execve(concatedst, ar, NULL);
		}
		else
		{
			if (access(ar[0], X_OK) == -1)
				errorHandlerFxn(av, ar, cmd_count, line, nline);
			if (stat(ar[0], &statuS) == -1)
				errorHandlerFxn(av, ar, cmd_count, line, nline);
			execve(ar[0], ar, NULL);
		}
	}
	return (0);
}

