#include "../include/utils.h"
#include "../include/shell.h"
#include "../include/types.h"
#include "../include/colors.h"
#include "../include/screen.h"
#include "../include/string.h"
#include "../include/system.h"
#include "../include/keyboard.h"
#include "../include/file_manager.h"
#include "../include/save_manager.h"
#include "../include/command_handler.h"

void main()
{
    checkSaves();
    startShell();
    runShell();
}
