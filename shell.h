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

    /*

#endif /* SHELL_H */
