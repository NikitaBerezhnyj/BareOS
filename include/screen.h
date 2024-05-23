#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "system.h"
#include "string.h"
#include "colors.h"

int cursorX = 0, cursorY = 0;
const uint8 sw = 80, sh = 25, sd = 2;
uint8 textColor = WHITE;
extern uint8 cursorVisible;

void enableCursor(uint8 start, uint8 end)
{
    outportb(0x3D4, 0x0A);
    outportb(0x3D5, (inportb(0x3D5) & 0xC0) | start);
    outportb(0x3D4, 0x0B);
    outportb(0x3D5, (inportb(0x3D5) & 0xE0) | end);
}

void setTextColor(uint8 fg)
{
    textColor = fg;
}

uint8 getTextColor()
{
    return textColor;
}

void clearLine(uint8 from, uint8 to)
{
    uint16 i = sw * from * sd;
    string vidmem = (string)0xb8000;
    for (; i < (sw * (to + 1) * sd); i += 2)
    {
        vidmem[i] = ' ';
        vidmem[i + 1] = textColor;
    }
}

void updateCursor()
{
    unsigned temp = cursorY * sw + cursorX; // Позиція курсора = (y * ширина) + x
    outportb(0x3D4, 14);                    // Регістр керування: вибір локації курсора
    outportb(0x3D5, temp >> 8);             // Відправка старшого байта
    outportb(0x3D4, 15);                    // Регістр керування: вибір для відправки молодшого байта
    outportb(0x3D5, temp);                  // Відправка молодшого байта локації курсора
}

void displayCursor()
{
    string vidmem = (string)0xb8000;
    vidmem[(cursorY * sw + cursorX) * sd] = '_';
    vidmem[(cursorY * sw + cursorX) * sd + 1] = textColor;
}

void moveCursor(int8 offset)
{
    uint16 position = cursorY * sw + cursorX;
    position += offset;
    cursorX = position % sw;
    cursorY = position / sw;
    updateCursor();
}

void clearScreen()
{
    clearLine(0, sh - 1);
    cursorX = 0;
    cursorY = 0;
    updateCursor();
}

void scrollUp(uint8 lineNumber)
{
    string vidmem = (string)0xb8000;
    uint16 i = 0;
    for (; i < sw * (sh - 1) * sd; i++)
    {
        vidmem[i] = vidmem[i + sw * sd * lineNumber];
    }
    clearLine(sh - 1 - lineNumber, sh - 1);
    cursorY = (cursorY < lineNumber) ? 0 : cursorY - lineNumber;
    cursorX = 0;
    updateCursor();
}

void newLineCheck()
{
    if (cursorY >= sh - 1)
    {
        scrollUp(1);
    }
}

void printch(char c)
{
    string vidmem = (string)0xb8000;
    switch (c)
    {
    case 0x08: // Backspace
        if (cursorX > 0)
        {
            cursorX--;
            vidmem[(cursorY * sw + cursorX) * sd] = ' ';
            vidmem[(cursorY * sw + cursorX) * sd + 1] = textColor;
        }
        break;
    case 0x09: // Tab
        cursorX = (cursorX + 8) & ~(8 - 1);
        break;
    case '\r': // Carriage return
        cursorX = 0;
        break;
    case '\n': // Newline
        cursorX = 0;
        cursorY++;
        break;
    default:
        vidmem[(cursorY * sw + cursorX) * sd] = c;
        vidmem[(cursorY * sw + cursorX) * sd + 1] = textColor;
        cursorX++;
        break;
    }

    if (cursorX >= sw)
    {
        cursorX = 0;
        cursorY++;
    }

    newLineCheck();
    updateCursor();
}

void printInt(int num)
{
    if (num == 0)
    {
        printch('0');
        return;
    }

    if (num < 0)
    {
        printch('-');
        num = -num;
    }

    char buffer[10];
    int i = 0;

    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    while (i > 0)
    {
        printch(buffer[--i]);
    }
}

void print(string ch)
{
    for (uint16 i = 0; ch[i] != '\0'; i++)
    {
        printch(ch[i]);
    }
}

#endif // SCREEN_H
