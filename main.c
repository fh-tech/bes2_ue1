#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <assert.h>

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

// globale Variable fuer den Programmnamen will be set automatically depending on executable name
char *program_name = NULL;

/**
 * prints usage information
 */
void print_usage() {
    fprintf(stderr, "Usage: %s [-R] [-i] searchpath filename1 [filename2] ...[filename n]\n", program_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int c;
    int error = 0;
    char *inputFile = NULL;
    int cOptionA = 0;

    program_name = argv[0];

    while ((c = getopt(argc, argv, "Ri:"))!=EOF) {
        switch (c) {
            // option for recursive
            case 'R':
                if (cOptionA) {
                    error = 1;
                    break;
                }
                cOptionA = 1;
                printf("%s: parsing option a\n", program_name);
                break;
                // case insensitive flag
            case 'i':
                // option already used?
                if (inputFile!=NULL) {
                    error = 1;
                    break;
                }
                inputFile = optarg; /* optarg zeigt auf Optionsargument */
                printf("%s: parsing option f, argument: %s\n", program_name, inputFile);
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
        print_usage();
    }
    // false count of options
    if ((argc < optind + 1) || (argc > optind + 2)) {
        print_usage();
    }

    /* Die restlichen Argumente, die keine Optionen sind, befinden sich in
     * argv[optind] bis argv[argc-1]
     */
    while (optind < argc) {
        /* aktuelles Argument: argv[optind] */
        printf("%s: parsing argument %s\n", program_name, argv[optind]);

        optind++;
    }
    return EXIT_SUCCESS;
}

