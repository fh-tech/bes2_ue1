//
// Created by vik on 09.05.18.
//

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <memory.h>
#include <ctype.h>
#include <unistd.h>

#include "search.h"

void printFoundFile(pid_t pid, char *filename, char *abs_path) {
    printf("%d: %s: %s\n", pid, filename, abs_path);
}

char *get_absPath(const char *path) {
    char * real_path = realpath(path, NULL);
    return real_path;
}

int compare_filenames(char *string1, char *string2, int case_insensitive) {
    size_t len1 = strlen(string1);
    size_t len2 = strlen(string2);
    if(len1 != len2) return 0;

    for(size_t i = 0; i < len1; i++) {
        char c1 = case_insensitive ? (char)tolower(string1[i]) : string1[i];
        char c2 = case_insensitive ? (char)tolower(string2[i]) : string2[i];
        if(c1 != c2) return 0;
    }
    // all were equal
    return 1;
}

pid_t search_forked(const char *dirname, char *toSearch, int recursive, int case_insensitive) {
    pid_t pid = fork();

    switch(pid) {
        case 0:
            searchFile(dirname, toSearch, recursive, case_insensitive);
            exit(EXIT_SUCCESS);
        case -1:
            fprintf(stderr, "Child could not be started.");
            exit(EXIT_FAILURE);
        default:
            return pid;
    }
}

char * build_newPath(const char * old_path, char * filename) {
    // +3 because strlen does not count null termination + 1 byte for "/"
    char * newPath = calloc(strlen(old_path) + strlen(filename) + 3, 1);
    strcat(newPath, old_path);
    strcat(newPath, "/");
    strcat(newPath, filename);
    return newPath;
}

void searchFile(const char *dirpath, char *toSearch, int recursive, int case_insensitive) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(dirpath))) {
        perror(dirpath);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char *filename = entry->d_name;

        switch (entry->d_type) {
            case DT_DIR: {
                if (recursive) {
                    if (!strcmp(filename, ".") == 0 && !strcmp(filename, "..") == 0) {
                        char * newPath = build_newPath(dirpath, filename);
                        searchFile(newPath, toSearch, recursive, case_insensitive);
                        free(newPath);
                    }
                }
                break;
            }
            case DT_REG: {
                int equal = compare_filenames(filename, toSearch, case_insensitive);
                if (equal) {
                    char * combined_name = build_newPath(dirpath, filename);
                    char *abs_path = get_absPath(combined_name);
                    printFoundFile(getpid(), toSearch, abs_path);
                    free(combined_name);
                    free(abs_path);
                }
                break;
            }
            default:
                break;
        }
    }
    // EINTR is error code for disrupted -- dont forget to close the file
    while ((closedir(dir) == -1) && (errno == EINTR));
}