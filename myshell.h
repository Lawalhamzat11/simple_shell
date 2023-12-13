#ifndef MY_SHELL_H
#define MY_SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stdint.h>
#define BUFFSIZE 1024


/**
  * string - Typedef for char *
  */
typedef char *string;
/**
 * struct customs_in - lists of customs
 * @cmd: command
 * @func: The function
 */
typedef struct customs_in
{
	string cmd;
	int (*func)();
} customs_t;

/**
 * struct lists_s - Defines a singly linked lists
 * @str: A pointer to a dynamically allocated string
 * @length: The length of the string
 * @next: A pointer to the next node in t
 */
typedef struct lists_s
{
	string str;
	unsigned int length;
	struct lists_s *next;
} lists_t;
extern string *environ;

size_t lists_len(lists_t *first);
lists_t *addnode_begin(lists_t **first, string str);
lists_t *add_node_end(lists_t **first, string str);
void free_lists(lists_t *first);
lists_t *get_node(lists_t **first, string str);

int _putchar(char c);
void print(string str);
void arr_print(string *arr);
size_t print_lists(lists_t *first);

int _strlen(string s);
int _strncmp(string s1, string s2, int n);
string _strdup(string str);
string _strcpy(string dest, string src);
string _strcat(string dest, string src);

int _strcmp(string s1, string s2);
void sign_hand(int signal);
string _strchr(string str, char c);
int length_char(string str, char c);
int _atoi(string s);

int count_words(string str, char delim);
int wordlen(string s, char delim);
string *_strtok(string str, char delim);

int arr_size(string *arr);
lists_t *arr_to_lists(string *arr);
string *lists_to_arr(lists_t **first);
void free_arr(string *arr);

string _getenv(string name, lists_t **header);
int _setenv(string name, string value, lists_t **header);
int _unsetenv(string name, lists_t **header);
int _delete(lists_t **first, string string);
string _var_string(string name, string value);

int processline(string input, int size);
int exit_shell(string *token);
void clear_buff(string buff);
string _memcpy(string dest, string src, int n);
void *_realloc(void *ptr, unsigned int old, unsigned int new_size);

int cmd_loop(string buff, string line, lists_t **header);

string *path_dirs(lists_t **header);
string cmd_path(string str, lists_t **header);
int run_command(string *line, lists_t **header);

int custom_commands(string *input, lists_t **header);
int exit_cmd(string *line);
int print_env(string *line, lists_t **header);
int _set_env(string *line, lists_t **header);
int un_set_env(string *line, lists_t **header);


#endif
