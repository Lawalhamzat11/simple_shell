#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stdint.h>
#define BUFFERSIZE 1024


/**
  * strings - Typedef for char *
  */
typedef char *strings;
/**
 * struct made_in - lists of made
 * @command: command
 * @fun: The function
 */
typedef struct made_in
{
	strings command;
	int (*fun)();
} made_t;

/**
 * struct lists_s - Defines a singly linked lists
 * @str: A pointer to a dynamically allocated strings
 * @length: The length of the strings
 * @next: A pointer to the next node in t
 */
typedef struct lists_s
{
	strings str;
	unsigned int length;
	struct lists_s *next;
} lists_t;
extern strings *environ;

size_t lists_len(lists_t *first);
lists_t *addnode_begin(lists_t **first, strings str);
lists_t *add_node_end(lists_t **first, strings str);
void free_lists(lists_t *first);
lists_t *get_node(lists_t **first, strings str);

int _putchar(char c);
void print(strings str);
void arr_print(strings *arr);
size_t print_lists(lists_t *first);

int _strlen(strings s);
int _strncmp(strings s1, strings s2, int n);
strings _strdup(strings str);
strings _strcpy(strings dest, strings src);
strings _strcat(strings dest, strings src);

int _strcmp(strings s1, strings s2);
void sign_hand(int signal);
strings _strchr(strings str, char c);
int length_char(strings str, char c);
int _atoi(strings s);

int count_words(strings str, char delim);
int word_len(strings s, char delim);
strings *_strtok(strings str, char delim);

int arr_size(strings *arr);
lists_t *arr_to_lists(strings *arr);
strings *lists_to_arr(lists_t **first);
void free_arr(strings *arr);

strings _getenv(strings name, lists_t **firster);
int _setenv(strings name, strings value, lists_t **firster);
int _unsetenv(strings name, lists_t **firster);
int _delete(lists_t **first, strings strings);
strings _var_string(strings name, strings value);

int get_line(strings input, int size);
int shell_exit(strings *token);
void clear_buff(strings buffer);
strings _memcpy(strings dest, strings src, int n);
void *_realloc(void *ptr, unsigned int old, unsigned int new_size);

int command_loop(strings buffer, strings line, lists_t **firster);

strings *path_dir(lists_t **firster);
strings command_path(strings str, lists_t **firster);
int run_command(strings *line, lists_t **firster);

int custom_commands(strings *input, lists_t **firster);
int exit_command(strings *line);
int print_env(strings *line, lists_t **firster);
int _set_env(strings *line, lists_t **firster);
int un_set_env(strings *line, lists_t **firster);


#endif
