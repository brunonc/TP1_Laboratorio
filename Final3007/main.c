#include <stdio.h>
#include <stdlib.h>

#include "recursos.h"
#include "letra.h"

int main() {
        ArrayList* letras = al_newArrayList();
        ArrayList* sinRepe;
        FILE* pFile;
        char palabra[20];

        int opcion = 0;

        while(opcion != 5) {
        printf("\n------------  MENU PRINCIPAL ------------");
        opcion = getInt("\n1 - Alta \n2 - Completar \n3 - Comprobar\n4 - Generar y listar\n5 - SALIR\n\n\n");
        switch(opcion) {
            case 1: // Alta
                parsearDatos(pFile, letras);
                break;
            case 2: // Completar
                completarDatos(letras);
                break;
            case 3: // Comprobar
                getString("Ingrese la palabra a comprobar: ", palabra);
                if(comprobar(letras, palabra) == 0) {
                    printf("No se puede formar esa palabra!");
                } else {
                    printf("La palabra se puede formar exitosamente!");
                }
                break;
            case 4: // Generar y listar
                sinRepe = generar(letras);
                if(al_sort(sinRepe, comparar, 1) == -1) {
                    printf("No se pudo ordenar");
                }
                for(int i = 0; i < al_len(sinRepe); i++) {
                    letra_print((Eletra*) al_get(sinRepe, i));
                }
                guardarArch(sinRepe);
                break;
            case 5:
                break;
        }
    }

    return 0;
}
