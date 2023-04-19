#include <stdlib.h>
#include <stdio.h>

#include "phrase_helpers.h"

char *parse_filepath(int argc, char *argv[]){
    char *result = NULL;
    if (argc < 2) {
        printf("Debe escribir un path hacia el archivo que quiera leer");
        exit(EXIT_FAILURE);
    }
    result = argv[1];
    return result;
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size){
    FILE *file = NULL;
    file = fopen(path, "r");
    unsigned int i = 0u;
    char char_value;

    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    
    while (feof(file) == 0 && i < max_size){    //vamos a leer el archivo hasta que feof retorne un valor que no sea cero;
        fscanf(file, "%i -> *%c*\n", &indexes[i], &char_value); //guarda los valores;
        if (indexes[i] > max_size){
            fprintf(stderr, "Invalid array index at the line %i\n", i+1);
            exit(EXIT_FAILURE);
        }
        else{
            letters[i] = char_value; //guarda el char que acabamos de leer en el indice que leimos en esta iteracion del ciclo;
        }
        i++;
    }

    return i;

}

