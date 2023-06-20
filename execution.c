#include "shell.h"
/**
 * execution - execute command
 * @data: struct for program data
 * Return: 0 on success, -1 on failure
 */
int execution(data_of_programs *data)
{
	int r_value = 0, stat;
	pid_t pid;

	r_value = lists_of_builtins(data);
	if (r_value != -1)
		return (r_value);

	r_value = finding_program(data);
	if (r_value)
	{
		return (r_value);
	}
	else
	{
		pid = fork();
		if (pid == -1)
		{
			print_error(data->commands_name);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			r_value = exec_value(data->tokens[0], datat->tokens, data->environment);
			if (r_value == -1)
				print_error(data->commands_name), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&stat);
			if (WIFEXITED(stat))
				errNo = WEXITSTATUS(stat);
			else if (WIFSIGNALED(stat))
				errNo = 128 + WTERMSIG(stat);
		}
	}
	return (0);
}
