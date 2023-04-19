#include <stdlib.h>
#include <stdio.h>

#include "phrase_helpers.h"
#include "sort.h"

#define MAX_SIZE 1000



int main(int argc, char *argv[]) {
    char *path = NULL;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    /* -- completar -- */
    path = parse_filepath(argc, argv);
    length = data_from_file(path, indexes, letters, MAX_SIZE);

    sortphrase(letters, sorted, indexes, length);
    dump(sorted, length);

    return EXIT_SUCCESS;
}

