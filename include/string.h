#ifndef STRING_H
#define STRING_H

#include "types.h"

uint16 strlength(string ch)
{
    uint16 i = 1;
    while (ch[i++])
        ;
    return --i;
}

uint8 strEql(string ch1, string ch2)
{
    uint8 result = 1;
    uint8 size = strlength(ch1);
    if (size != strlength(ch2))
        result = 0;
    else
    {
        uint8 i = 0;
        for (i; i <= size; i++)
        {
            if (ch1[i] != ch2[i])
                result = 0;
        }
    }
    return result;
}

uint8 cmdEql(string cmd, string input)
{
    uint8 i = 0;
    while (input[i] != ' ' && input[i] != 0)
    {
        if (input[i] != cmd[i])
            return 0;
        i++;
    }
    if (cmd[i] == 0)
        return 1;
    else
        return 0;
}

// void shiftStringLeft(string str, uint8 start)
// {
//     uint8 i = start;
//     while (str[i] != 0)
//     {
//         str[i] = str[i + 1];
//         i++;
//     }
// }

#endif
