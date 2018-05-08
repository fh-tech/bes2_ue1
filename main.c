#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <assert.h>
#include <dirent.h>
#include <errno.h>
#include <memory.h>
#include <ctype.h>

/**
 * Note:
 * searchpath can be absolute or relative
 * -i makes case insensitive
 * -R recursive otherwise in relative searchpath
 * filenames are no paths but just names
 * Wildcards for filenames dont need to be supported
 * -R, -i at any position possible
 * Output on stdout - unsorted
 */



/**
 * prints found entries in specified format
 * @param pid of the forked process that found it
 * @param filename the name of the file
 * @param abs_path the absolute path of the file
 */
void printFoundFile(char *pid, char *filename, char *abs_path) {
    printf("%s: %s: %s\n", pid, filename, abs_path);
}

/**
 * extracts the absolute path to a file
 * @param name name of the file
 * @return char * with the absolute path
 */
char *get_absPath(char *name) {
    return realpath(name, NULL);
}

/**
 * manipulates some_string to be lower case
 * @param some_string char * to be lowercase
 */
void to_lower(char *some_string) {
    int counter = 0;
    char mychar;
    while ((mychar = some_string[counter])!='\0') {
        some_string[counter] = (char) tolower(mychar);
        counter++;
    }
    some_string[counter] = '\0';
}

/**
 * searches for a file in the specified folder
 * @param dirp directory to search in
 * @param toSearch filename that we search for
 * @param recursive if set searches in sub folders also
 * @param case_insensitive if set ignores case
 */
void searchFile(char *dirname, char *toSearch, int case_insensitive, int recursive) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(dirname))) return;

    while ((entry = readdir(dir))!=NULL) {
        if (entry->d_type==DT_DIR) {
            if(recursive) {
                if (!strcmp(entry->d_name, ".")==0 && !strcmp(entry->d_name, "..")==0) {
                    searchFile(entry->d_name, toSearch, case_insensitive, recursive);
                }
            }
        } else {
            // print for debugging
            printf("Name: %s Type: %d\n", entry->d_name, entry->d_type);

            size_t len = strlen(entry->d_name);
            char filename[len];
            strcpy(filename, entry->d_name);
            if (case_insensitive) {
                to_lower(filename);
                to_lower(toSearch);
            }
            if (strcmp(filename, toSearch)==0) {
//            printf("found match for %s: %s\n", toSearch, direntp->d_name);
                char *abs_path = get_absPath(entry->d_name);
                printFoundFile("", entry->d_name, abs_path);
            }
        }
    }
    // EINTR is error code for disrupted -- dont forget to close the file
    while ((closedir(dir)==-1) && (errno==EINTR));
}

/**
 * Opens a directory
 * @param dirname name of directory to be opened
 * @return NULL or DIR*
 */
DIR *openDir(char *dirname) {
    return opendir(dirname);
}

/**
 * prints usage information
 */
void print_usage(char *program_name) {
    fprintf(stderr, "Usage: %s [-R] [-i] searchpath filename1 [filename2] ...[filename n]\n", program_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int c;
    int error = 0;
    int recursive = 0;
    int case_insensitive = 0;
    char *program_name = argv[0];

    while ((c = getopt(argc, argv, "Ri"))!=EOF) {
        switch (c) {
            // option for recursive
            case 'R':
                if (recursive) {
                    fprintf(stderr, "multiple usage of flags is not allowed\n");
                    error = 1;
                    break;
                }
                recursive = 1;
//                printf("recursive set\n");
                break;
                // case insensitive flag
            case 'i':
                if (case_insensitive) {
                    fprintf(stderr, "multiple usage of flags is not allowed\n");
                    error = 1;
                    break;
                }
                case_insensitive = 1;
//                printf("case insensitive set\n");
                break;
                // invalid option
            case '?':error = 1;
                break;
            default: //cant reach here
                assert(0); //assert used when this code part can normally be never reached
        }
    }

    // options were false
    if (error) {
        print_usage(program_name);
    }

    // false count of options
    if ((argc < optind + 2)) {
        fprintf(stderr, "false number of arguments\n");
        print_usage(program_name);
    }




   /* DIR *dirp = openDir(dirname);
    if (dirp==NULL) {
        perror("Failed to open directory");
        exit(EXIT_FAILURE);
    }*/


    /* Remaining arguments that are no options are in
     * argv[optind] bis argv[argc-1]
     */
    //starting second argument search for filenames
    char *dirname = argv[optind];
    optind++;
    while (optind < argc) {
        searchFile(dirname, argv[optind++], recursive, case_insensitive);
    }

    exit(EXIT_SUCCESS);
}

