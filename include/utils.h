#ifndef UTILS_H
#define UTILS_H

#include "types.h"
#include "screen.h"

int atoi(const char *str)
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return res;
}

uint8 isDigit(char c)
{
    return c >= '0' && c <= '9';
}

void strNcpy(char *dest, const char *src, int n)
{
    for (int i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[n] = '\0';
}

int isSpace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int isBlankOrEmpty(const char *str)
{
    while (*str)
    {
        if (!isSpace((unsigned char)*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

int calculate(const char *expr)
{
    int result = 0;
    int currNum = 0;
    char op = '+';

    for (int i = 0; expr[i] != '\0'; i++)
    {
        if (isDigit(expr[i]))
        {
            currNum = currNum * 10 + (expr[i] - '0');
        }
        else if (isSpace(expr[i]))
        {
            continue;
        }
        else
        {
            switch (op)
            {
            case '+':
                result += currNum;
                break;
            case '-':
                result -= currNum;
                break;
            case '*':
                result *= currNum;
                break;
            case '/':
                if (currNum == 0)
                {
                    print("Error: Division by zero\n");
                    return 0;
                }
                result /= currNum;
                break;
            }
            op = expr[i];
            currNum = 0;
        }
    }

    switch (op)
    {
    case '+':
        result += currNum;
        break;
    case '-':
        result -= currNum;
        break;
    case '*':
        result *= currNum;
        break;
    case '/':
        if (currNum == 0)
        {
            print("Error: Division by zero\n");
            return 0;
        }
        result /= currNum;
        break;
    }

    return result;
}

#endif
