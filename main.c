#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <direct.h>
#include <stdbool.h>

// Some things for checking if file exit or not
#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif

int main()
{
    create_database("test");

    //     // Check dir and create if not exit
    //     const char *folder;
    //     folder = "database";
    //     struct stat sb;

    //     if (!(stat(folder, &sb) == 0 && S_ISDIR(sb.st_mode)))
    //     {
    //         // Create a dir
    //         char *dir_name = "./database";
    //         int result = -1;
    // #ifdef __linux__
    //         result = mkdir(dir_name, 777);
    // #else
    //         result = _mkdir(dir_name);
    // #endif
    //         if (!result)
    //         {
    //             puts("Error while creating directory");
    //             exit(EXIT_FAILURE);
    //         }
    //     }

    //     // check if config exit or not
    //     printf("%d", exists("./database/config.json"));

    return EXIT_SUCCESS;
}