#include "head.h"

/**
 * main - main entry point
 * @ac: numb of args
 * @av: array of strs
 * @env: present env
 * Return: 0 if EOF is reached of if user uses Ctrl + D
 */
int main(int ac, char **av, char **env)
{
	char *DlinE, *newLinE, **tok_arr;
	size_t lengthA = 0;
	ssize_t lineMagnitude;
	int numOfCommand = 0;

	(void)ac, (void)av;
	while (1)
	{
		DlinE = NULL, lengthA = 0, numOfCommand++;
		if (isatty(STDIN_FILENO) == 1)
			shellPromptFxn();
		signal(SIGINT, ctrlCHandlerFxn);
		lineMagnitude = getline(&DlinE, &lengthA, stdin);
		if (lineMagnitude == EOF || lineMagnitude == -1)
			return (ctrlDHandlerFxn(DlinE));
		if (DlinE[0] == '\n')
		{
			free(DlinE);
			continue;
		}
		newLinE = memReallocationFxn(DlinE);
		if (newLinE != NULL)
			tok_arr = tokenizeFxn(newLinE);
		else
		{
			free(DlinE);
			return (0);
		}
		if (tok_arr != NULL)
		{
			executeCommandFxn(tok_arr, env, av, DlinE, newLinE, numOfCommand);
			freeAllFxn(DlinE, newLinE, tok_arr);
		}
		else
		{
			free(DlinE);
			free(newLinE);
			return (0);
		}
	}
}

