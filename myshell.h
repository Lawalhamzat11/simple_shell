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
 * struct customs_in - list of customs
 * @cmd: command
 * @func: The function
 */
typedef struct customs_in
{
	string cmd;
	int (*func)();
} customs_t;

/**
 * struct list_s - Defines a singly linked list
 * @str: A pointer to a dynamically allocated string
 * @length: The length of the string
 * @next: A pointer to the next node in t
 */
typedef struct list_s
{
	string str;
	unsigned int length;
	struct list_s *next;
} list_t;
extern string *environ;

size_t list_len(list_t *head);
list_t *_addNode_begin(list_t **head, string str);
list_t *add_node_end(list_t **head, string str);
void free_list(list_t *head);
list_t *_get_node(list_t **head, string str);

int _putchar(char c);
void myprint(string str);
void print_arr(string *arr);
size_t print_list(list_t *head);

int _strlen(string s);
int _strncmp(string s1, string s2, int n);
string _strdup(string str);
string _strcpy(string dest, string src);
string _strcat(string dest, string src);

int _strcmp(string s1, string s2);
void sign_handle(int signal);
string _strchr(string str, char c);
int length_char(string str, char c);
int _atoi(string s);

int count_words(string str, char delim);
int wordlen(string s, char delim);
string *_strtok(string str, char delim);

int arr_size(string *arr);
list_t *arr_to_list(string *arr);
string *list_to_arr(list_t **head);
void free_arr(string *arr);

string _getenv(string name, list_t **header);
int _setenv(string name, string value, list_t **header);
int _unsetenv(string name, list_t **header);
int _delete(list_t **head, string string);
string _var_string(string name, string value);

int processline(string input, int size);
int exit_shell(string *token);
void clear_buff(string buff);
string _memcpy(string dest, string src, int n);
void *_realloc(void *ptr, unsigned int old, unsigned int new_size);

int cmd_loop(string buff, string line, list_t **header);

string *path_dirs(list_t **header);
string cmd_path(string str, list_t **header);
int run_command(string *line, list_t **header);

int custom_commands(string *input, list_t **header);
int exit_cmd(string *line);
int print_env(string *line, list_t **header);
int _set_env(string *line, list_t **header);
int un_set_env(string *line, list_t **header);


#endif
