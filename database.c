#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <stdbool.h>

#include "database.h"

#include <io.h>
#define F_OK 0
#define access _access

#define db_path "./database"
#define db_config_file db_path "/" \
                               "config.json"

bool create_database(char *name)
{
    if (chdir(db_path))
    {
        int check = _mkdir(db_path);
        if (!check)
        {
            printf("Database Folder Created.\n");
        }
        else
        {
            printf("Error: Unable to create database.\n");
            return false;
        }
    }

    if (!exists(db_path, "config.json"))
    {
        printf("not exist\n");
        FILE *_db_config_file = fopen(db_config_file, "w+");

        if (_db_config_file == NULL)
        {
            printf("Error: Unable to create database config file.\n");
            return false;
        }
        else
        {
            printf("Database config file created.\n");
        }
        fclose(_db_config_file);
    }

    char database_path[100];
    sprintf(database_path, "%s/%s.json", db_path, name);

    printf("%s.\n", database_path);

    FILE *fp = fopen(database_path, "w");
    if (fp == NULL)
    {
        printf("Error: Unable to database file.\n");
        return false;
    }

    return true;
}

bool exists(const char *folder_path, const char *file_name)
{
    // Create a buffer to hold the full path
    char full_path[256]; // Adjust the size as needed

    // Combine the folder path and file name to create the full path
    snprintf(full_path, sizeof(full_path), "%s/%s", folder_path, file_name);

    // Check if the file exists
    if (access(full_path, F_OK) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
