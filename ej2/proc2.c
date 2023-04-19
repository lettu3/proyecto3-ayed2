#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    if (x >= 0){
        *y = x;
    }
    else {
        *y = (-1) * x;
    }
}

int main(void) {
    int *p;
    int a=0, res=0;  // No modificar esta declaración
    a = -10;

    p = &res;

    absolute(a, p);
    printf("El valor de res es %d\n", res);
    return EXIT_SUCCESS;
}

//Este programa si retorna los valores esperados para la variable res
//El parámetro int *y de absolute() es de tipo out si se mirara con el lenguaje del teorico, no me importa su contenido, solo le asigno un nuevo valor
//C solo tiene parametros de tipo in para sus funciones, estas pueden leer las variables locales de mi programa pero no pueden modificarlas por fuera de la misma funcion
//Se pueden modificar variables locales con una funcion, pero es necesario pasar parametros por referencia con punteros
