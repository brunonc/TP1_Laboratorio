#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entrega.h"
#include "ArrayList.h"

int parserEntrega(FILE* pFile , ArrayList* pArrayListEntregas, char* nombre) {
    int res = -1;
    tEntrega* auxEntrega;

    int auxId;
    char auxProducto[51];
    char auxDireccion[51];
    char auxLocalidad[51];
    char auxRecibe[51];

    pFile = fopen(nombre, "r");
    if (pFile != NULL && pArrayListEntregas != NULL) {
        fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,\n]\n", auxId, auxProducto, auxDireccion, auxLocalidad, auxRecibe);
        while(!feof(pFile)) {
            auxEntrega = entrega_new();
            fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,\n]\n", auxId, auxProducto, auxDireccion, auxLocalidad, auxRecibe);
            entrega_setId(auxEntrega, atoi(auxId));
            entrega_setProducto(auxEntrega, auxProducto);
            entrega_setDireccion(auxEntrega, auxDireccion);
            entrega_setLocalidad(auxEntrega, auxLocalidad);
            entrega_setRecibe(auxEntrega, auxRecibe);
            //entrega_print(auxEntrega);
            al_add(pArrayListEntregas, auxEntrega);
        }
        res = 0;
        fclose(pFile);
    }

    return res;
}
