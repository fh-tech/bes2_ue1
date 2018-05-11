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
void printFoundFile(pid_t pid, char *filename, char *abs_path);


/**
 * extracts the absolute path to a file
 * @param name name of the file
 * @return char * with the absolute path
 */
char *get_absPath(const char *path);


/**
 * takes two char *s and if they should be compared case_insensitive
 * @param string1
 * @param string2
 * @param case_insensitive
 * @return 1 if equal 0 if not
 */
int compare_filenames(char *string1, char *string2, int case_insensitive);


/**
 * searches for a file in dirpath and if recursive is set and a folder is found searches recursively in subfolders too
 * @param dirpath relative or absolute path
 * @param toSearch filename to be searched for
 * @param case_insensitive exact match or case insensitive
 * @param recursive search in subfolders too or not
 */
void searchFile(const char *dirpath, char *toSearch, int case_insensitive, int recursive);


/**
 * combines strings old_path and filename like old_path/filename
 * @param old_path
 * @param filename
 * @return char * of form old_path/filename
 */
char * build_newPath(const char * old_path, char * filename);


/**
 * searches for a file in a new process otherwise works like searchfile
 * @param dirname
 * @param toSearch
 * @param recursive
 * @param case_insensitive
 * @return process id of the forked process
 */
pid_t search_forked(const char *dirname, char *toSearch, int recursive, int case_insensitive);



#endif //BES_UE1_SEARCH_H
