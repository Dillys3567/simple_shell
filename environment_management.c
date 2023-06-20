#include "shell.h"
/**
 * environment_get_key - get environment variable
 * @key: environment variable
 * @data: struct of program data
 * Return: pointer to variable or NULL
 */
char *environment_get_key(char *key, data_of_programs *data)
{
	int x, length_of_key = 0;

	if (key == NULL || data->environment == NULL)
		return (NULL);
	length_of_key = string_length(key);
	for (x = 0; data->environment[x]; x++)
	{
		if (string_compare(key, data->environment[x], length_of_key) && data->
				environment[x][length_of_key] == '=')
		{
			return (data->environment[x] + length_of_key + 1);
		}
	}
	return (NULL);
}
/**
 * environment_set_key - overwrite environment variable
 * @key: environment variable
 * @value: new value
 * @data: struct for program data
 * Return: 1 if params are NULL, 2 on error and 0 on success
 */
int environment_set_key(char *key, char *value, data_of_programs *data)
{
	int x, length_of_key = 0, new_key = 1;

	if (key == NULL || value == NULL || data->environment == NULL)
		return (1);
	length_of_key = string_length(key);

	for (x = 0; data->environment[x]; x++)
	{
		if (string_compare(key, data->environment[x], length_of_key) && data->
				env[x][length_of_key] == '=')
		{
			new_key = 0;
			free(data->environment[x]);
			break;
		}
	}
	data->environment[x] = string_concatenate(duplicate_string(key), '=');
	data->environment[x] = string_concatenate(data->environment[x], value);

	if (new_key)
	{
		data->environment[x + 1] = NULL;
	}
	return (0);
}
/**
 * environment_remove_key - remove key
 * @key: key
 * @data: struct for program data
 * Return: 1 if removed, 0 if not exist
 */
int environment_remove_key(char *key, data_of_programs *data)
{
	int x, length_of_key = 0;

	if (key == NULL || data->environment == NULL)
		return  (0);
	length_of_key = string_length(key);

	for (x = 0; data->environment[x]; x++)
	{
		if (string_compare(key, data->environment[x], length_of_key) && data
				->environment[x][length_of_key] == '=')
		{
			free(data->environment[x]);
			x++;
			for (; data->environment[x]; x++)
			{
				data->environment[x - 1] = data->environment[x];
			}
			data->environment[x - 1] == NULL;
			return (1);
		}
	}
	return (0);
}
/**
 * print_environment - print currrent environment
 * @data: struct for program data
 */
void print_environment(data_of_programs *data)
{
	int y;

	for (y = 0; data->environemnt[y]; y++)
	{
		_print(data->environment[y]);
		_print("\n");
	}
}
