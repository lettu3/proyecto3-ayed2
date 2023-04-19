#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x >= 0){
        y = x;
    }
    else {
        y = (-1) * x;
    }
}

int main(void) {
    int a=0, res=0;
    a = -10;
    absolute(a, res);
    printf("El valor de res es %i\n", res);
    return EXIT_SUCCESS;
}

//El resultado imprimido en pantalla no es el deseado 
//no coincide con en el programa del lenguaje utilizado en el teorico (ya que ese si retorna el valor correcto)

