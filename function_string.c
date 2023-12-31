#include "shell.h"

/**
 *  * str_len - checks the length of a string
 *  * @string: pointer to string to check
 *  *
 *  * Return: int length of the string
 *  */

int str_len(char *string)
{
        int len = 0;

        while (string[len])
        len++;
        return (len);
}

/**
 * * str_dup - Returns a pointer to a newly-allocated space in memory
 * * containing a copy of the string given as parameter.
 * * @string: The string to be copied.
 * *
 * * Return: If str == NULL or insufficient memory is available - NULL.
 * * Otherwise - a pointer to the duplicated string.
 * */
char *str_dup(char *string)
{
        int i = 0;
        int length = 0;
        char *dup = NULL;
        if (string == NULL)
                return (NULL);
        for (i = 0; *(string + i); i++)
                length++;

        dup = malloc(sizeof(char) * (length + 10));

        if (dup == NULL)
	        return (NULL);
	for (i = 0; *(string + i); i++)
        	*(dup + i) = *(string + i);

       *(dup + length) = '\0';
     return (dup);
}

/**
 * * *str_cpy -  copies the string pointed to by src
 * * @dest: char type string
 * * @src: char type string
 * * Description: Copy the string pointed to by pointer `src` to
 * * the buffer pointed to by `dest`
 * * Return: Pointer to dest
 * */

char *str_cpy(char *dest, char *src)
{
        int i = -1;
        do {
                i++;
                dest[i] = src[i];
        } while (src[i] != '\0');

        return (dest);
}
/**
 * * *str_cat - concatenates @src to @dest
 * * @src: the source string to append to @dest
 * * @dest: the destiation string to be concatenated upon
 * * Return: char
 *     */

char *str_cat(char *dest, char *src)
{
        int index = 0;
        int dest_len = 0;

        while (dest[index++])
                dest_len++;
        for (index = 0; src[index]; index++)
        dest[dest_len++] = src[index];
        return (dest);
}

/**
 *  * _strncmp - Compares at most the first n bytes of two strings.
 *  * @str1: A pointer to the first string to be compared.
 *  * @str2: A pointer to the second string to be compared.
 * * @n: number of bytes to compare
 * *
 * * Return: If str1 < str2, the negative difference of
 * * the first unmatched characters.
 *  If str1 == str2, 0.
 * *         If str1 > str2, the positive difference of
 * *         the first unmatched characters.
 *  */
int _strncmp(char *str1, char *str2, size_t n)
{
        while ((*str1 && *str2) && (*str1 == *str2))
                {
                str1++;
                str2++;
                n--;
                }
        return (*str1 - *str2);
}
