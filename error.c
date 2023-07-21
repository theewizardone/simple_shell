#include "shell.h"

/**
 * _eputs - outputs an input str
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
        int i = 0;

        if (!str)
                return;
        while (str[i] != '\0')
        {
                _eputchar(str[i]);
                i++;
        }
}

/**
 * _eputchar - writes the char c to stderr
 * @c: The char to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set accordingly.
 */
int _eputchar(char c)
{
        static int i;
        static char buf[WRITE_BUF_SIZE];

        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        {
                write(2, buf, i);
                i = 0;
        }
        if (c != BUF_FLUSH)
                buf[i++] = c;
        return (1);
}

/**
 * _putfd - writes the char c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set accordingly.
 */
int _putfd(char c, int fd)
{
        static int i;
        static char buf[WRITE_BUF_SIZE];

        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        {
                write(fd, buf, i);
                i = 0;
        }
        if (c != BUF_FLUSH)
                buf[i++] = c;
        return (1);
}

/**
 * _putsfd - outputs an input str
 * @str: the str to be outputed
 * @fd: the filedescriptor to write to
 *
 * Return: the no of chars put
 */
int _putsfd(char *str, int fd)
{
        int i = 0;

        if (!str)
                return (0);
        while (*str)
        {
                i += _putfd(*str++, fd);
        }
        return (0);
}
