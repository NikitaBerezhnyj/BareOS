#ifndef SAVE_MANAGER_H
#define SAVE_MANAGER_H

#include "screen.h"

void createSaves()
{
    print("Create save file...\n");
    // Логіка для створення файлу збереження
}

void loadSaves()
{
    print("Load save...\n");
    // Логіка для завантаження збереження
}

void updateSaves()
{
    print("Update save...\n");
    // Логіка для оновлення збереження
}

void checkSaves()
{
    print("Check save...\n");
    int is_save = 1; // Умовно, що є збереження
    if (is_save == 0)
    {
        createSaves();
    }
    else
    {
        loadSaves();
    }
    // Можливо, тут потрібно додати додаткову логіку для перевірки існування збережень
}

#endif // SAVE_MANAGER_H