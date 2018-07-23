#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"

struct {
    int id;
    char producto[51];
    char direccion[51];
    char localidad[51];
    char recibe[51];
} typedef tEntrega;

struct {
    int id;
    char localidad[51];
} typedef tLocalidad;

tEntrega* entrega_new(void);
int entrega_setId(tEntrega*, int);
int entrega_setProducto(tEntrega*, char*);
int entrega_setDireccion(tEntrega*, char*);
int entrega_setLocalidad(tEntrega*, char*);
int entrega_setRecibe(tEntrega*, char*);
void entrega_print(tEntrega*);
int entregas_print(ArrayList*);
int listar_localidades(ArrayList*, void*);
