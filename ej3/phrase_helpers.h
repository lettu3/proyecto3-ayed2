#ifndef _PHRASE_HELPERS_H
#define _PHRASE_HELPERS_H

char *parse_filepath
(int argc, char *argv[]);
/*
    Parse the filepath given by command line argument.
*/

unsigned int data_from_file
(const char *path, unsigned int indexes[], char letters[], unsigned int max_size);
/*
    Each element is read from the file located at 'filepath'.
    The file must exist in disk and must have its contents in the following
    format:
    <char_index> -> *<char>*
    <char_index> -> *<char>*
    ...
    Those elements are copied into the arrays 'indexes' and 'letters'. 
    The array_length must be lower or equal to 'max_size'.
    Returns the length of the array.
*/


#endif