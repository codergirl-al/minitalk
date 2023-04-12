#include "minitalk.h"

/*
** Convert a binary string to an ASCII character.
** binary: the binary string to convert (8 bits)
** returns: the corresponding ASCII character
*/
char    ft_convert_binary(char *binary)
{
    char    res;
    int     index;

    index = -1;
    res = 0;
    while (binary[++index] != '\0')
    {
        if (binary[index] == '1')
            res = res | (1 << (7 - index));
    }
    return (res);
}