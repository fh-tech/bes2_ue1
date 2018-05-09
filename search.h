//
// Created by vik on 09.05.18.
//

#ifndef BES_UE1_SEARCH_H
#define BES_UE1_SEARCH_H

/**
 * prints found entries in specified format
 * @param pid of the forked process that found it
 * @param filename the name of the file
 * @param abs_path the absolute path of the file
 */
void printFoundFile(char *pid, char *filename, char *abs_path);


/**
 * extracts the absolute path to a file
 * @param name name of the file
 * @return char * with the absolute path
 */
char *get_absPath(char *dirname, char *name);

/**
 * takes two char *s and if they should be compared case_insensitive
 * @param string1
 * @param string2
 * @param case_insensitive
 * @return 1 if equal 0 if not
 */
int compare_filenames(char *string1, char *string2, int case_insensitive);


/**
 * searches for a file in the specified folder
 * @param dirp directory to search in
 * @param toSearch filename that we search for
 * @param recursive if set searches in sub folders also
 * @param case_insensitive if set ignores case
 */
void searchFile(const char *dirname, char *toSearch, int case_insensitive, int recursive);


#endif //BES_UE1_SEARCH_H
