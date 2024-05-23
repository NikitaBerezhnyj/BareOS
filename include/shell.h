#ifndef SHELL_H
#define SHELL_H

#include "types.h"
#include "colors.h"
#include "screen.h"
#include "command_handler.h"
#include "keyboard.h"

void startShell()
{
    string welcome_str = "Welcome to BareOS";
    clearScreen();
    setTextColor(GREEN);
    for (int i = 0; i < 80; i++)
    {
        print("-");
    }
    for (int i = 1; i < (80 - strlength(welcome_str) + 2) / 2; i++)
    {
        print("-");
    }
    print(welcome_str);
    for (int i = 1; i < (80 - strlength(welcome_str) + 3) / 2; i++)
    {
        print("-");
    }
    for (int i = 0; i < 80; i++)
    {
        print("-");
    }

    print("\n");
    setTextColor(WHITE);
}

void runShell()
{
    while (1)
    {
        print("$> ");
        string ch = readStr();
        print("\n");
        handleCommand(ch);
    }
}

#endif
