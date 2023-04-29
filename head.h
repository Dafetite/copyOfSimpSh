#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <limits.h>
#define DELIMITERS " \t\0"

/**
 * struct path_s - linked list structure for PATH variable
 * @directory: directory to lookup
 * @next: pointer to the next node
 */

typedef struct path_s
{
	char *directory;
	struct path_s *next;
} linked_t;


int _putchar(char c);

/* exec.c */
int executeCommandFxn(char **ar, char **env, char **av, char *line, char *nline,
		int cmd_count);

/* prompt.c */
void shellPromptFxn(void);

/* shell.c */
char **tokenizeFxn(char *line);

/* path functions */
linked_t *createLinkedtFxn(char *str);
linked_t *addNodesListFxn(char *str, linked_t *list);
char *envPathFxn(const char *name, char **env);
char *pathHandlerFxn(char *str, char **env);


/* error_handling */
void errorHandlerFxn(char **argv, char **ar, int cmdcount_int, char *line,
		   char *nline);

/* str helper functions */
int strLenCounterFxn(char *buffeR);
int stringsCompareFxn(char *s1, char *s2);
char *strDuplicateFxn(char *str);
char *concatFxn(char *concatenate, char *s1, char *s2);
char *stringConcatingFxn(char *s1, char *s2);

/* builtin functions */
int exitHandlerFxn(char **array, char *line, char *newline, int cmd_count);
int changeDirHandlerFxn(char **array, char **env);
int environHandlerFxn(char **env);
int checkBFxns(char **arr, char **env, char *line, char *newline, int changedirnum);

/* strint functions */
int atoIFxn(char *s);
int tensFxn(int i, char *s);
char *intPrintFxn(int num);

/* signal handler */
void ctrlCHandlerFxn(int signum);
int ctrlDHandlerFxn(char *line);

/* memory handling */
char *memReallocationFxn(char *p);
void freeListFxn(linked_t *head);
void freeTokensFxn(char **tok_array);
void freeAllFxn(char *d_line, char *newline, char **tok_array);

#endif

