#include <stdlib.h>
#include <stdio.h>

#include "sort.h"

void sortphrase(char l[], char s[], unsigned int indexes[], unsigned int length){
    for (unsigned int i = 0u; i < length; ++i){
        s[i] = l[indexes[i]];
    }
}