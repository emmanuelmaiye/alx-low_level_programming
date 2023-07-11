#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * number - function to calculate number of words
 * @str: string being passed to check for words
 *
 * Return: number of words
 */
int number(char *str)
{
	int a, num = 0;

	for (a = 0; str[a] != '\0'; a++)
	{
		if (*str == ' ')
			str++;
		else
		{
			for (; str[a] != ' ' && str[a] != '\0'; a++)
				str++;
			num++;
		}
	}
	return (num);
}

/**
 * free_everything - frees the memory
 * @string: pointer values being passed for freeing
 * @i: counter
 */
void free_everything(char **string, int i)
{
	for (; i > 0;)
		free(string[--i]);
	free(string);
}

/**
 * allocate_word - allocates memory for a word and copies it
 * @found_word: pointer to the beginning of the word
 * @length: length of the word
 *
 * Return: pointer to the allocated memory containing the word
 */
char *allocate_word(char *found_word, int length)
{
	char *word = malloc((length + 1) * sizeof(char));

	if (word == NULL)
		return (NULL);

	int i;
	for (i = 0; i < length; i++)
	{
		word[i] = found_word[i];
	}
	word[length] = '\0';

	return (word);
}

/**
 * strtow - function that splits string into words
 * @str: string being passed
 * Return: null if string is empty or null or function fails
 */
char **strtow(char *str)
{
	int total_words = 0, b = 0, c = 0, length = 0;
	char **words, *found_word;

	if (str == NULL || *str == '\0')
		return (NULL);
	total_words = number(str);
	if (total_words == 0)
		return (NULL);
	words = malloc((total_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	for (; *str != '\0' && b < total_words;)
	{
		if (*str == ' ')
			str++;
		else
		{
			found_word = str;
			for (; *str != ' ' && *str != '\0';)
			{
				length++;
				str++;
			}
			words[b] = allocate_word(found_word, length);
			if (words[b] == NULL)
			{
				free_everything(words, b);
				return (NULL);
			}
			b++;
			c = 0;
			length = 0;
			str++;
		}
	}
	return (words);
}

