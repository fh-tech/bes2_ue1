#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/wait.h>


#include "search.h"

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

    while ((c = getopt(argc, argv, "Ri")) != EOF) {
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
                printf("case insensitive set\n");
                break;
                // invalid option
            case '?':
                error = 1;
                break;
            default:
                //cant reach here
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

    //Remaining arguments that are no options are in
    //argv[optind] bis argv[argc-1]
    //starting second argument search for filenames
    char *dirname = argv[optind];
    optind++;

    //make an array of the pids
    pid_t *the_slaves = calloc(argc - optind, sizeof(pid_t));
    int i = 0;
    while (optind < argc) {
        // save forked process ids into an array
        the_slaves[i++] = search_forked(dirname, argv[optind++], recursive, case_insensitive);
    }

    int status = 0;
    pid_t wpid = 0;
    // wait for ALL children to finish
    while ((wpid = wait(&status)) > 0) {
        printf("Exit status of %d was %d (%s)\n", (int) wpid, status,
               (status > 0) ? "reject" : "accept");
    }

    // free the pids
    free(the_slaves);

    exit(EXIT_SUCCESS);
}

