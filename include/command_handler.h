#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include "types.h"
#include "screen.h"
#include "string.h"
#include "system.h"
#include "colors.h"
#include "utils.h"

extern void shutdown();
extern void reboot();

void handleCommand(string command)
{
    if (isBlankOrEmpty(command))
    {
        return;
    }
    else if (strEql(command, "help"))
    {
        print("\n");
        print("help     :  Display all commands\n");
        print("clear    :  Clear terminal\n");
        print("tree     :  Display all directories\n");
        print("ls       :  Display all files in directory\n");
        print("cd       :  Change directory\n");
        print("mkdir    :  Make directory\n");
        print("rmdir    :  Remove directory\n");
        print("touch    :  Create file\n");
        print("rmfile   :  Delete file\n");
        print("wrtxt    :  Write text in file\n");
        print("cat      :  Display file content\n");
        print("echo     :  Repeat text in quotes\n");
        print("calc     :  Calculate the expression\n");
        print("matrix   :  Display the matrix for testing all colors\n");
        print("color    :  Set text color\n");
        print("reboot   :  Reboot system\n");
        print("shutdown :  Shutting down system\n");
        print("\n");
    }
    else if (strEql(command, "clear"))
    {
        clearScreen();
    }
    else if (strEql(command, "tree"))
    {
        print("Display all directories\n");
    }
    else if (strEql(command, "ls"))
    {
        print("Display all files in directory\n");
    }
    else if (strEql(command, "cd"))
    {
        print("Change directory\n");
    }
    else if (strEql(command, "mkdir"))
    {
        print("Make directory\n");
    }
    else if (strEql(command, "rmdir"))
    {
        print("Remove directory\n");
    }
    else if (strEql(command, "touch"))
    {
        print("Create file\n");
    }
    else if (strEql(command, "rmfile"))
    {
        print("Delete file\n");
    }
    else if (strEql(command, "wrtxt"))
    {
        print("Write text in file\n");
    }
    else if (strEql(command, "cat"))
    {
        print("Display file content\n");
    }
    else if (cmdEql("echo", command))
    {
        if (command[4] == ' ' && command[5] == '\"')
        {
            uint8 i = 6;
            while (command[i] != 0 && command[i] != '\"')
            {
                printch(command[i]);
                i++;
            }
            if (command[i] == '\"' && command[i + 1] == 0)
            {
                print("\n");
            }
            else
            {
                print("invalid argument\n");
            }
        }
        else
        {
            print("invalid argument\n");
        }
    }
    else if (cmdEql("calc", command))
    {
        if (command[4] == ' ')
        {
            string expr = command + 5;
            int result = calculate(expr);
            printInt(result);
            print("\n");
        }
        else
        {
            print("invalid argument\n");
        }
    }
    else if (strEql(command, "matrix"))
    {
        print("Run Matrix rain\n");
    }
    else if (cmdEql("color", command))
    {
        if (strEql(command + 6, "--help"))
        {
            uint8 originalTextColor = getTextColor();
            setTextColor(WHITE);
            print("Usage: color <color_code>\n");
            print("Available colors:\n");
            setTextColor(BLACK);
            print("0: Black\n");
            setTextColor(BLUE);
            print("1: Blue\n");
            setTextColor(GREEN);
            print("2: Green\n");
            setTextColor(CYAN);
            print("3: Cyan\n");
            setTextColor(RED);
            print("4: Red\n");
            setTextColor(MAGENTA);
            print("5: Magenta\n");
            setTextColor(BROWN);
            print("6: Brown\n");
            setTextColor(LIGHT_GREY);
            print("7: Light gray\n");
            setTextColor(DARK_GREY);
            print("8: Dark gray\n");
            setTextColor(LIGHT_BLUE);
            print("9: Light blue\n");
            setTextColor(LIGHT_GREEN);
            print("10: Light green\n");
            setTextColor(LIGHT_CYAN);
            print("11: Light cyan\n");
            setTextColor(LIGHT_RED);
            print("12: Light red\n");
            setTextColor(LIGHT_MAGENTA);
            print("13: Light magenta\n");
            setTextColor(LIGHT_BROWN);
            print("14: Light brown\n");
            setTextColor(WHITE);
            print("15: White\n\n");
            setTextColor(originalTextColor);
        }
        else
        {
            uint8 textColor = atoi(command + 6);

            if (textColor <= 15)
            {
                setTextColor(textColor);
                print("Text color changed\n");
            }
            else
            {
                print("Invalid text color value\n");
            }
        }
    }
    else if (strEql(command, "reboot"))
    {
        print("Restarting...\n");
        reboot();
    }
    else if (strEql(command, "shutdown"))
    {
        print("Shutting down...\n");
        shutdown();
    }
    else
    {
        print("Unknown command: ");
        print(command);
        print("\n");
    }
}

#endif