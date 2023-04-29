#include "head.h"

/**
 * envPathFxn - search for thr env variable
 * @name: the environment variable name
 * @env: environment variable gangan
 * Return: points to the env var
 */

char *envPathFxn(const char *name, char **env)
{
	int count1 = 0;
	int count2 = 0;

	if (name == NULL || env == NULL || *env == NULL)
		return (NULL);
	while (env[count1] != NULL)
	{
		while (env[count1][count2] == name[count2])
			count2++;
		if (env[count1][count2] == '=')
		{
			count2++;
			return (&(env[count1][count2]));
		}
		count1++;
		count2 = 0;
	}
	write(STDOUT_FILENO, "Not found in environment", 24);
	return (NULL);
}

