#include <stdio.h>
#include <stdlib.h>

#include "recursos.h"
#include "ArrayList.h"
#include "entrega.h"

int main() {
    ArrayList* entregas;
    entregas = al_newArrayList();
    ArrayList* localidades;
    localidades = al_newArrayList();

    char arch[20];
    FILE* pFile;

    tEntrega* aux;

    int opcion = 0;

    while(opcion != 5) {
        printf("\n------------  MENU PRINCIPAL ------------");
        opcion = getInt("\n1 - Cargar archivo \n2 - Imprimir entregas \n3 - Imprimir localidades\n4 - Generar archivo de reparto para localidad\n5 - SALIR\n\n\n");
        switch(opcion) {
            case 1: // Cargar archivo
                getValidArch("Ingrese el nombre del archivo: ", "El nombre del archivo no es valido", arch);
                while(parserEntrega(pFile, entregas, arch) == -1) {
                    printf("El archivo no existe!\n");
                    getValidArch("Ingrese el nombre del archivo: ", "El nombre del archivo no es valido", arch);
                }
                break;
            case 2: // Imprimir entregas
                if(al_isEmpty(entregas) || entregas_print(entregas) == -1) {
                    printf("No existen entregas cargadas!\n");
                }
                break;
            case 3: // Imprimir localidades
                localidades = al_filter_localidades(entregas, listar_localidades);
                for(int i = 0; i < al_len(localidades); i++) {
                    printf("%s", localidades+i);
                }
                break;
            case 4: // Generar archivo de reparto para localidad
                break;
            case 5:
                break;
        }
    }

    return 0;
}
