#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "types.h"
#include "system.h"
#include "string.h"
#include "colors.h"

// Оголошення функцій
void listFiles()
{
    print("Лист файлів в дерикторії");
}

void treeFiles()
{
    print("Повне дерево файлів");
}

void changeDir()
{
    print("Зміна директорії");
}

void createDir()
{
    print("Створення директорії");
}

void removeDir()
{
    print("Видалення директорії");
}

void createFile()
{
    print("Створення файлу");
}

void removeFile()
{
    print("Видалення файлу");
}

void writeFile()
{
    print("Запис у файл");
}

void contentFile()
{
    print("Вивід вмісту файлу");
}

#endif // FILE_MANAGER_H