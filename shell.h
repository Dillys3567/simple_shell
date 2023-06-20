#ifndef SHELL_H
#define SHELL_H

#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h> 

#include "macros.h"

/**
 * struct info- struct for the program's data
 * @program_name: the name of the executable
 * @input_line: pointer to the input read for _getline
 * @command_name: pointer to the first command typed by the user
 * @exec_counter: number of excecuted comands
 * @file_descriptor: file descriptor to the input of commands
 * @tokens: pointer to array of tokenized input
 * @env: copy of the environ
 * @alias_list: array of pointers with aliases.
 */
typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} data_of_program;

             /*To add, remove or show aliases*/
int output_alias(data_of_programs *data, char *alias);

                  /*To get the alias*/
char *fetch_alias(data_of_programs *data, char *name);

                  /*To add alias*/
int write_alias(char *string_alias, data_of_programs *data);

       /*To allow to read a line from command prompt*/
int _getlines(data_of programs * data);

   /*To check for logical operators and split*/
int check_ops_logic(char *array_of_commands[], int x,
		char array_of_operators[]);

    /*exit program with status*/
int exit_builtin(data_of_programs *data);

   /*change working dir*/
int cd_builtin(data_of_programs *data);

      /*set working dir*/
int set_working_directory(data_of_programs *data, char *new_dir);

      /*show environment of shell*/
int help_builtin(data_of_programs *data);

       /*aliases*/
int alias_builtin(data_of_program *data);

    /*search and execute builtins match*/
int list_of_builtins(data_of_programs *data);

    /*show shell environment*/
int builtin_environment(data_of_programs *data);

        /*set env*/
int builtin_set_environment(data_of_programs *data);

       /*unset env*/
int builtin_unset_environment(data_of_program *data);

      /*To free an array of pointers*/
void free_array_of_pointers(char **array);

     /*To free all fields of a program*/
void free_all_data(data_of_program *data);

     /*To free the fields needed for each loop of a program*/
void free_recurrent_data(data_of_program *data);

#endif /* SHELL_H */
