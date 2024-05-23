#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "screen.h"
#include "system.h"
#include "string.h"
#include "types.h"

uint8 getAsciiCode(uint8 scanCode, uint8 shiftPressed)
{
    uint8 asciiCode = 0;
    if (shiftPressed)
    {
        switch (scanCode)
        {
        case 12:
            asciiCode = '_';
            break; // Minus
        case 13:
            asciiCode = '+';
            break; // Equal
        case 16:
            asciiCode = 'Q';
            break;
        case 17:
            asciiCode = 'W';
            break;
        case 18:
            asciiCode = 'E';
            break;
        case 19:
            asciiCode = 'R';
            break;
        case 20:
            asciiCode = 'T';
            break;
        case 21:
            asciiCode = 'Y';
            break;
        case 22:
            asciiCode = 'U';
            break;
        case 23:
            asciiCode = 'I';
            break;
        case 24:
            asciiCode = 'O';
            break;
        case 25:
            asciiCode = 'P';
            break;
        case 30:
            asciiCode = 'A';
            break;
        case 31:
            asciiCode = 'S';
            break;
        case 32:
            asciiCode = 'D';
            break;
        case 33:
            asciiCode = 'F';
            break;
        case 34:
            asciiCode = 'G';
            break;
        case 35:
            asciiCode = 'H';
            break;
        case 36:
            asciiCode = 'J';
            break;
        case 37:
            asciiCode = 'K';
            break;
        case 38:
            asciiCode = 'L';
            break;
        case 39:
            asciiCode = ':';
            break;
        case 40:
            asciiCode = '"';
            break;
        case 41:
            asciiCode = '~';
            break; // Back tick (`)
        case 43:
            asciiCode = '|';
            break; // \ (< for some keyboards)
        case 44:
            asciiCode = 'Z';
            break;
        case 45:
            asciiCode = 'X';
            break;
        case 46:
            asciiCode = 'C';
            break;
        case 47:
            asciiCode = 'V';
            break;
        case 48:
            asciiCode = 'B';
            break;
        case 49:
            asciiCode = 'N';
            break;
        case 50:
            asciiCode = 'M';
            break;
        case 51:
            asciiCode = '<';
            break; // Comma
        case 52:
            asciiCode = '>';
            break; // Period
        case 53:
            asciiCode = '?';
            break; // Forward slash
        case 2:
            asciiCode = '!';
            break; // 1
        case 3:
            asciiCode = '@';
            break; // 2
        case 4:
            asciiCode = '#';
            break; // 3
        case 5:
            asciiCode = '$';
            break; // 4
        case 6:
            asciiCode = '%';
            break; // 5
        case 7:
            asciiCode = '^';
            break; // 6
        case 8:
            asciiCode = '&';
            break; // 7
        case 9:
            asciiCode = '*';
            break; // 8
        case 10:
            asciiCode = '(';
            break; // 9
        case 11:
            asciiCode = ')';
            break; // 0
        default:
            break;
        }
    }
    else
    {
        switch (scanCode)
        {
        case 16:
            asciiCode = 'q';
            break;
        case 17:
            asciiCode = 'w';
            break;
        case 18:
            asciiCode = 'e';
            break;
        case 19:
            asciiCode = 'r';
            break;
        case 20:
            asciiCode = 't';
            break;
        case 21:
            asciiCode = 'y';
            break;
        case 22:
            asciiCode = 'u';
            break;
        case 23:
            asciiCode = 'i';
            break;
        case 24:
            asciiCode = 'o';
            break;
        case 25:
            asciiCode = 'p';
            break;
        case 30:
            asciiCode = 'a';
            break;
        case 31:
            asciiCode = 's';
            break;
        case 32:
            asciiCode = 'd';
            break;
        case 33:
            asciiCode = 'f';
            break;
        case 34:
            asciiCode = 'g';
            break;
        case 35:
            asciiCode = 'h';
            break;
        case 36:
            asciiCode = 'j';
            break;
        case 37:
            asciiCode = 'k';
            break;
        case 38:
            asciiCode = 'l';
            break;
        case 39:
            asciiCode = ';';
            break;
        case 40:
            asciiCode = '\'';
            break;
        case 41:
            asciiCode = '`';
            break; // Back tick (`)
        case 43:
            asciiCode = '\\';
            break; // \ (< for some keyboards)
        case 44:
            asciiCode = 'z';
            break;
        case 45:
            asciiCode = 'x';
            break;
        case 46:
            asciiCode = 'c';
            break;
        case 47:
            asciiCode = 'v';
            break;
        case 48:
            asciiCode = 'b';
            break;
        case 49:
            asciiCode = 'n';
            break;
        case 50:
            asciiCode = 'm';
            break;
        case 51:
            asciiCode = ',';
            break; // Comma
        case 52:
            asciiCode = '.';
            break; // Period
        case 53:
            asciiCode = '/';
            break; // Forward slash
        case 55:
            asciiCode = '/';
            break; // Forward slash (diff scancode)
        case 57:
            asciiCode = ' ';
            break; // Space
        case 26:
            asciiCode = '[';
            break; // Open bracket
        case 27:
            asciiCode = ']';
            break; // Close bracket
        case 12:
            asciiCode = '-';
            break; // Minus
        case 13:
            asciiCode = '=';
            break; // Equal
        case 2:
            asciiCode = '1';
            break; // 1
        case 3:
            asciiCode = '2';
            break; // 2
        case 4:
            asciiCode = '3';
            break; // 3
        case 5:
            asciiCode = '4';
            break; // 4
        case 6:
            asciiCode = '5';
            break; // 5
        case 7:
            asciiCode = '6';
            break; // 6
        case 8:
            asciiCode = '7';
            break; // 7
        case 9:
            asciiCode = '8';
            break; // 8
        case 10:
            asciiCode = '9';
            break; // 9
        case 11:
            asciiCode = '0';
            break; // 0
        default:
            break;
        }
    }
    return asciiCode;
}

string readStr()
{
    char buff;
    string buffstr;
    uint8 i = 0;
    uint8 reading = 1;
    uint8 shiftPressed = 0; // Прапорець для натиснутої клавіші Shift

    // Очистити буфер перед зчитуванням
    buffstr[0] = 0;

    while (reading)
    {
        if (inportb(0x64) & 0x1)
        {
            uint8 scanCode = inportb(0x60);
            switch (scanCode)
            {
            case 42: // Left Shift
            case 54: // Right Shift
                shiftPressed = 1;
                break;
            case 170: // Left Shift released
            case 182: // Right Shift released
                shiftPressed = 0;
                break;
            case 28: // Enter
                i++;
                reading = 0;
                break;
            case 14: // Backspace
                if (i > 0)
                {
                    printch('\b');
                    i--;
                    buffstr[i] = 0;
                    // shiftStringLeft(buffstr, i);
                }
                break;
            case 83: // Delete
                // Реалізуйте функціонал видалення символу після курсору
                if (buffstr[i] != 0)
                {
                    uint8 j = i;
                    while (buffstr[j] != 0)
                    {
                        buffstr[j] = buffstr[j + 1];
                        j++;
                    }
                    print(buffstr + i); // Перемалювати строку після курсору
                    printch(' ');       // Затираємо останній символ
                    uint8 len = strlength(buffstr + i) + 1;
                    for (uint8 k = 0; k < len; k++)
                    {
                        printch('\b'); // Повертаємо курсор назад
                    }
                }
                break;
            case 75: // Left arrow
                if (i > 0)
                {
                    i--;
                    moveCursor(-1);
                }
                break;
            case 77: // Right arrow
                if (buffstr[i] != 0)
                {
                    i++;
                    moveCursor(1);
                }
                break;
            case 72: // Up arrow
                // Обробка дії при натисканні стрілки вверх
                break;
            case 80: // Down arrow
                // Обробка дії при натисканні стрілки вниз
                break;
            default:
                uint8 asciiCode = getAsciiCode(scanCode, shiftPressed);
                if (asciiCode != 0)
                {
                    printch(asciiCode);
                    buffstr[i] = asciiCode;
                    i++;
                }
                break;
            }
        }
    }
    buffstr[i - 1] = 0;
    return buffstr;
}

#endif // KEYBOARD_H
