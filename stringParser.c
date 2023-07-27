#include "shell.h"
/**
 ** _getline - gets line from STDIN and places it in the buffer
 ** @file: int assigned to the read of STDIN
 ** Return: pointer to buffer with formatted input from STDIN
 **/
char *_getline(int file)
{
        unsigned int i, index;
        char *buffer;
        static unsigned int buffer_size = BUFSIZE;

        buffer = malloc(sizeof(char) * buffer_size);
        if (buffer == NULL)
        {
        perror("malloc for buffer failed\n");
                return (NULL);
        }
        index = 0;
        _memset(buffer, '\0', buffer_size);
        while ((i = read(file, buffer + index, buffer_size - index)) > 0)
        {

        if (i < (buffer_size - index))
                return (buffer);
        buffer_size *= 2;
        _realloc(buffer, buffer_size, buffer_size / 2);
        if (buffer == NULL)
        {
        perror("realloc failed\n");
        return (NULL);
        }
                index += i;
        }
        if (i == 0)
        _memcpy(buffer, "exit", 5);
return (buffer);
}
/**
 * * parser - parses a string into tokens
 ** @str: string to parse
 ** @delimit: delimiters chosen by user
 ** Return: Double pointer to array of tokens
 * */
char **parser(char *str, char *delimit)
{
        char **tokenized, *saveptr, *token;
        unsigned int i, wc;
        wc = word_count(str);
        tokenized = malloc((wc + 1) * sizeof(char *));
        if (!tokenized)
        {
                perror("malloc failed\n");
                return (NULL);
        }
        tokenized[0] = token = _strtok_r(str, delimit, &saveptr);
        for (i = 1; token; i++)
        tokenized[i] = token = _strtok_r(NULL, delimit, &saveptr);
        return (tokenized);
}
