#include "shell.h"
/**
 * variables_expansion - expand variables
 * @data: struct for program data
 */
void variables_expansion(data_of_programs *data)
{
	int x, y;
	char lines[BUFFER_SIZE} = {0}, expansions[BUFFER_SIZE] = {'\0'}
		, *temporary;

	if (data->input_lines == NULL)
		return;

	add_to_buffer(lines, data->input_lines);
	for (x = 0; lines[x]; x++)
		if (lines[x] == '#')
			lines[x--] = '\0';
		else if (lines[x] == '$' && lines[x + 1] == '?')
		{
			lines[x] = '\0';
			long_to_str(errNo, expansions, 10);
			add_to_buffer(lines, expansions);
			add_to_buffer(lines, data->input_lines + x + 2);
		}
		else if (lines[x] == '$' && (lines[x + 1] == ' ' || lines[x + 1] == '\0'))
			continue;
		else if (lines[x] == '$')
		{
			for (y = 1; lines[x + y] && lines[x + y] != ' '; y++)
				expansions[y - 1] = lines[x + y];
			temporary = environment_get_key(expansions, data);
			lines[x] = '\0', expansions[0] = '\0';
			add_to_buffer(expansions, line + x + y);
			temporary ? add_to_buffer(lines, temporary) : 1;
			add_to_buffer(lines, expansions);
		}
	if (!string_compare(data->input_lines, lines, 0))
	{
		free(data->input_lines);
		data->input_lines = duplicate_string(lines);
	}
}
/**
 * alias_expansion - expand alias
 * @data: struct for program data
 */
void alias_expansion(data_of_programs *data)
{
	int x, y, expanded = 0;
	char lines[BUFFER_SIZE] = {0}, expansions[BUFFER_SIZE] = {'\0'}
		, *temporary;

	if (data->input_lines == NULL)
		return;
	add_to_buffer(lines, data->input_lines);

	for (x = 0; lines[x]; x++)
	{
		for (y = 0; lines[x + y] && lines[x + y] != ' '; y++)
			expansions[y] = lines[x + y];
		expansions[y] = '\0';

		temporary = fetch_alias(data, expansions);
		if (temporary)
		{
			expansions[0] = '\0';
			add_to_buffer(expansions, lines + x + y);
			lines[x] = '\0';
			add_to_buffer(lines, temporary);
			lines[string_length(lines)] = '\0';
			add_to_buffer(lines, expansions);
			expanded = 1;
		}
		break;
	}
	if (expanded)
	{
		free(data->input_lines);
		data->input_lines = duplicate_string(lines);
	}
}
/**
 * add_to_buffer - append to buffer
 * @buffer: buffer
 * @strings: string to add
 * Return: length
 */
int add_to_buffer(char *buffer, char *strings)
{
	int len, x;

	len = string_length(buffer);
	for (x = 0; strings[x]; x++)
		buffer[len + x] = strings[x];
	buffer[len + x] = '\0';
	return (len + x);
}
