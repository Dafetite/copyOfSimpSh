#include "head.h"


/**
 * createLinkedtFxn - creates empty linked list
 * @string: the PATH variable name
 * Return: points to the empty linked list
 */
linked_t *createLinkedtFxn(char *string)
{
	int count = 0;
	int nodeS = 1;
	linked_t *nd, *hd, *tmp, *enD;

	tmp = malloc(sizeof(linked_t));
	if (tmp == NULL)
		return (NULL);
	/* 3NE */
	else
		hd = tmp;
	enD = malloc(sizeof(linked_t));
	if (enD == NULL)
	{
		free(tmp);
		return (NULL);
	}
	/* 4NE */
	enD->next = NULL;
	while (string[count] != '\0')
	{
		if (string[count] == ':')
			nodeS++;
		count++;
	}
	while ((nodeS - 2) > 0)
	{
		nd = malloc(sizeof(linked_t));
		if (nd == NULL)
		{
			free(tmp);
			free(enD);
			return (NULL);
		}
		tmp->next = nd;
		tmp = tmp->next;
		nodeS--;
	}
	tmp->next = enD;
	return (hd);
}

/**
 * addNodesListFxn - add PATH variable contents to empty
 * @str: PATH variable name
 * @list: pointer to the empty linked list
 * Return: pointer to the resultant linked list that is needed
 */

linked_t *addNodesListFxn(char *str, linked_t *list)
{
	linked_t *pointer, *hd;
	char *dirtry;
	int count1 = 0, count2 = 0, strcount = 0, dirlength = 0;

	if (str ==  NULL || list == NULL)
		return (NULL);
	/* 6NE */
		hd = list;
		pointer = hd;
	while (pointer != NULL)
	{
		if (str[count1] == ':' || str[count1] == '\0')
		{
			if (str[count1] != '\0')
				count1++;
			dirtry = malloc(sizeof(char) * dirlength + 2);
			if (dirtry == NULL)
				return (NULL);
			while (str[strcount] != ':' && str[strcount] != '\0')
			{
				dirtry[count2] = str[strcount];
				strcount++;
				count2++;
			}
			dirtry[count2++] = '/';
			dirtry[count2] = '\0';
			strcount = count1;
			count2 = 0;
			pointer->directory = dirtry;
			pointer = pointer->next;
		}
		else
		{
			dirlength++;
			count1++;
		}
	}
	return (hd);
}

/**
 * freeListFxn - this function will free the linked_t list
 * @head: the head of the linkedlist
 * Return: void
 */

void freeListFxn(linked_t *head)
{
	linked_t *nxtnd;

	while (head != NULL)
	{
		nxtnd = head->next;
		free(head->directory);
		free(head);
		head = nxtnd;
	}
}

/**
 * freeTokensFxn - frees the tokens in the t_array array
 * @tok_array: array of tokens
 * Return: void
 */

void freeTokensFxn(char **tok_array)
{
	int count = 0;

	while (tok_array[count] != NULL)
	{
		free(tok_array[count]);
		count++;
	}
	free(tok_array[count]);
}


/**
 * freeAllFxn - frees all allocated pointer variables that was used
 * @d_line: the line that was entered by the user
 * @newline: user input without the newline character
 * @tok_array: array of the tokens used
 * Return: void
 */
void freeAllFxn(char *d_line, char *newline, char **tok_array)
{
	freeTokensFxn(tok_array);
	free(d_line);
	free(newline);
	free(tok_array);
}

