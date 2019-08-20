#include "holberton.h"

char *_strtok(char *s, char *deli)
{
	int c;
	static char *str;

	if (!s)
		s = str;
	do
	{
		if ((c = *s++) == 0)
			return (0);
	} while (_strchr(deli, c));
	--s;
	str = s + _strcspn(s, deli);
	if (*str != 0)
		*str++ = 0;
	return (s);
}

/**
 * _strcspn - gets the length of a prefix string
 * @s: string
 * @pre: prefix string
 * Return: number of bytes in the initial seg of s
 */
unsigned int _strcspn(char *s, char *pre)
{
	unsigned int len = 0, i = 0;

	while (s[len] != 0)
	{
		int flag = 0;

		for (i = 0; pre[i] != 0; i++)
		{
			if (s[len] != pre[i])
			{
				len++;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
	return (len);
}
/**
 * _strchr - locates character in string
 * @s: string
 * @b: character to locate
 * Return: pointer to the first occurrence of the character
 */
char *_strchr(char *s, char b)
{
	while (*s != 0)
	{
		if (*s == b)
			return (s);
		s++;
	}
	if (*s == b)
		return (s);
	return (0);
}
