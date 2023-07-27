#include "shell.h"
/**
 ** str_cmp - Compares two strings.
 ** @s1: A pointer to the first string to be compared.
 ** @s2: A pointer to the second string to be compared.
 **
 ** Return: If str1 < str2, the negative difference of
 ** the first unmatched characters.
 ** If str1 == str2, 0.
 ** If str1 > str2, the positive difference of
 ** the first unmatched characters.
 **/
int str_cmp(char *s1, char *s2)
{
        while (*s1 && *s2 && *s1 == *s2)
        {
                s1++;
                s2++;
        }

        return (*s1 - *s2);
}
/**
 *   * _strcat_realloc - concatenates 2 strings and reallocates automatically
 *     * @dest: destination to copy to
 *       * @src: source to copy from
 *         * Return: pointer to concatenated strings
 *           */
char *_strcat_realloc(char *dest, char *src)
{
        unsigned int dest_len, src_len, i;

        dest_len = str_len(dest);
        src_len = str_len(src);
        dest = _realloc(dest, dest_len, dest_len + src_len + 1);
        if (dest == NULL)
                return (NULL);
        for (i = 0; i < src_len; i++)
        {
                dest[i + dest_len] = src[i];
        }
                dest[i + dest_len] = '\0';
        return (dest);
}
/**
 *  * _atoi - converts a string to an integer
 *   * @s: the input string
 *    * Return: the converted int
 *     */
int _atoi(char *s)
{
        int n, sign, result;

        for (n = result = 0, sign = 1; s[n]; n++)
        {
                if (s[n] == '-')
                sign *= -1;
                if (s[n] >= '0' && s[n] <= '9')
                result = 10 * result - (s[n] - '0');
                if (result < 0 && (s[n] < '0' || s[n] > '9'))
                break;
        }
        if (sign > 0)
                result *= -1;
        return (result);
}
