#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "entrega.h"

int listar_localidades(tEntrega* entrega, char* localidad) {
    for(int i = 0; i < al_len(localidades); i++) {
        if(strcmpi((char*)localidades->pElements[i], ((tEntrega*)entrega)->localidad) != 0) {
                void* locate =
            al_add(localidades,((tEntrega*)entrega)->localidad );
        }
    }
}

tEntrega* entrega_new(void) {
    tEntrega* returnAux = (tEntrega*) malloc(sizeof(tEntrega));
    return returnAux;
}

int entrega_setId(tEntrega* this, int id) {
    int res;
    this->id = id;
    return res;
}

int entrega_setProducto(tEntrega* this, char* producto) {
    int res;
    strcpy(this->producto, producto);
    return res;
}

int entrega_setDireccion(tEntrega* this, char* direccion) {
    int res;
    strcpy(this->direccion, direccion);
    return res;
}

int entrega_setLocalidad(tEntrega* this, char* localidad) {
    int res;
    strcpy(this->localidad, localidad);
    return res;
}

int entrega_setRecibe(tEntrega* this, char* recibe) {
    int res;
    strcpy(this->recibe, recibe);
    return res;
}

void entrega_print(tEntrega* this) {
    printf("Id: %d\nProducto: %s\nDireccion: %s\nLocalidad: %s\nRecibe: %s\n\n", this->id, this->producto, this->direccion, this->localidad, this->recibe);
}

int entregas_print(ArrayList* entregas) {
    int res = -1;
    tEntrega* aux;
    if(entregas != NULL) {
        for(int i = 0; i < al_len(entregas); i++) {
            aux = (tEntrega*) al_get(entregas, i);
            entrega_print(aux);
        }
        res = 0;
    }
    return res;
}



