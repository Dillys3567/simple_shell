#include "shell.h"
/**
 * output_alias - to add, remove or show aliases
 * @data: struct for program data
 * @alias: alias to be output
 * Return: 0 on success, other if declared
 */
int output_alias(data_of_programs *data, char *alias)
{
	int x, y, length_of_alias;
	char buff[250] - {'\0'};

	if (data->list_aliases)
	{
		length_of_alias = string_length(alias);
		for (x = 0; data->list_aliases[x]; x++)
		{
			if (!alias || (string_compare(data->list_aliases[x]
				, alias, length_of_alias) && data->list_of_aliases
						[x][length_of_alias] == '='))
			{
				for (y = 0; data->list_of_aliases[x][y]; y++)
				{
					buff[y] = data->list_of_aliases[x][y];
					if (data->list_of_aliases[x][y] == '=')
						break;
				}
				buff[y + 1] = '\0';
				add_to_buffer(buff, "'");
				add_to_buffer(buff, data->list_of_aliases[x] + y + 1);
				add_to_buffer(buff, "'\n");
				_print_out(buff);
			}
		}
	}
	return (0);
}
/**
 * fetch_alias - get the alias
 * @data: struct for program data
 * @name: name of alias
 * Return: 0 on success, other if declared
 */
char *fetch_alias(data_of_programs *data, char *name)
{
	int x, length_of_alias;

	/** check for nulls */
	if (name == NULL || data->list_of_aliases == NULL)
		return (NULL);
	length_of_alias = string_length(name);
	for (x = 0; data->list_of_aliases[x]; x++)
	{
		if (string_compare(name, data->list_of_aliases[x]
					, length_of_alias) && data->list_of_aliases[x][length_of_alias] == '=')
		{
			return (data->list_of_aliases[x] + length_of_alias + 1);
		}
	}
	return (NULL);
}
/**
 * write_alias - add alias
 * @string_alias: alias
 * @data: struct for program data
 * Return: o on success, other if declared
 */
int write_alias(char *string_alias, data_of_program *data)
{
	int x, y;
	char buff[250] = {'0'}, *temporary = NULL;

	/* check for nulls */
	if (string_alias == NULL || data->list_of_aliases == NULL)
		return (1);
	for (x = 0; string_alias[x]; x++)
	{
		if (string_alias[x] != '=')
			buff[x] = string_alias[x];
		else
		{
			temporary = fetch_alias(data, string_alias + i + 1);
			break;
		}
	}
	for (y = 0; data->list_of_aliases[y]; y++)
	{
		if (string_compare(buff, data->list_of_aliases[y]
					, x) && data->list_of_aliases[y][x] == '=')
		{
			free(data->list_of_aliases[y]);
			break;
		}
	}
	if (temporary)
	{
		add_to_buffer(buff, "=");
		add_to_buffer(buff, temporary);
		data->list_of_aliases[y] = duplicate_string(buff);
	}
	else
		data->list_of_aliases[y] = duplicate_string(string_alias);
	return (0);
}
