#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#include "ArrayList.h"
#include "letra.h"

int parsearDatos(FILE* pFile, ArrayList* listaLetras) {
    int res = -1;
    Eletra* auxEletra;
    char cabecera[80];

    char auxLetra[3];
    char auxNombre[22];
    char auxVocal[2];
    char auxConsonante[2];


    pFile = fopen("datos.csv", "r");
    if(pFile != NULL && listaLetras != NULL) {
        fgets(cabecera, 80, pFile);
        while(!feof(pFile)) {
            auxEletra = new_letra();
            fscanf(pFile, "%[^,], %[^,], %[^,], %[^,\n]\n", auxLetra, auxNombre, auxVocal, auxConsonante);
            letra_setLetra(auxEletra, auxLetra[0]);
            letra_setNombre(auxEletra, auxNombre);
            letra_setVocal(auxEletra, atoi(auxVocal));
            letra_setConsonante(auxEletra, atoi(auxConsonante));
            al_add(listaLetras, auxEletra);
        }
        res = 0;
        fclose(pFile);
    }
    return res;
}

Eletra* new_letra(void) {
    Eletra* aux;
    aux = (Eletra*) malloc(sizeof(Eletra));
    return aux;
}

int letra_setLetra(Eletra* this, char* letra) {
    int res;
    this->letra = letra;
    return res;
}

int letra_setNombre(Eletra* this, char* nombre) {
    int res;
    strcpy(this->nombre, nombre);
    return res;
}

int letra_setVocal(Eletra* this, int vocal) {
    int res;
    this->vocal = vocal;
    return res;
}

int letra_setConsonante(Eletra* this, int consonante) {
    int res;
    this->consonante = consonante;
    return res;
}

char letra_getLetra(Eletra* this) {
    return this->letra;
}

char* letra_getNombre(Eletra* this) {
    return this->nombre;
}

int letra_getVocal(Eletra* this) {
    return this->vocal;
}

int letra_getConsonante(Eletra* this) {
    return this->consonante;
}

int completarDatos(ArrayList* listaLetras) {
    Eletra* aux;
    for(int i = 0; i < al_len(listaLetras); i++) {
        aux = (Eletra*)al_get(listaLetras, i);
        if(esVocal(aux)) {
            letra_setVocal(aux, 1);
        } else if (esConsonante(aux)) {
            letra_setConsonante(aux, 1);
        }
        al_set(listaLetras, i, aux);
    }
}

int esVocal(Eletra* this) {
    int res = 0;
    char letra = letra_getLetra(this);
    if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' || letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
        res = 1;
    }
    return res;
}

int esConsonante(Eletra* this) {
    int res = 0;
    char letra = letra_getLetra(this);
    if((letra < 'a' || letra > 'z') || (letra < 'A' || letra > 'Z')) {
        if(letra != 'a' && letra != 'e' && letra != 'i' && letra != 'o' && letra != 'u' && letra != 'A' && letra != 'E' && letra != 'I' && letra != 'O' && letra != 'U') {
            res = 1;
        }
    }
    return res;
}

void letra_print(Eletra* this) {
    printf("Letra: %c\nNombre: %s\nVocal: %d\nConsonante: %d\n\n", this->letra, this->nombre, this->vocal, this->consonante);
}

int comprobar(ArrayList* letras, char* palabra) {
    ArrayList* auxLetras = al_clone(letras);
    int i = 0;
    int j = 0;
    int continuar = 1;
    Eletra* aux;
    if(auxLetras != NULL && palabra != NULL) {
        while(palabra[i] != '\0' && continuar) {
            while(j < al_len(auxLetras)) {
                aux = (Eletra*)al_get(auxLetras, j);
                if(palabra[i] == letra_getLetra(aux)) {
                    al_remove(auxLetras, j);
                    continuar = 1;
                    break;
                } else {
                    continuar = 0;
                }
                j++;
            }
            i++;
        }
    }

    return continuar;
}

ArrayList* generar(ArrayList* letras) {
    ArrayList* res = al_newArrayList();
    Eletra* auxI;
    Eletra* auxJ;
    int cont;
    for(int i = 0; i < al_len(letras); i++) {
        cont = 0;
        auxI = (Eletra*) al_get(letras, i);
        for(int j = i + 1; j < al_len(letras); j++) {
            auxJ = (Eletra*) al_get(letras, j);
            if (auxI->letra == auxJ->letra) {
                cont++;
            }
        }
        if(cont == 0) {
            al_add(res, auxI);
        }
    }
    return res;
}

int comparar(Eletra* letraI, Eletra* letraJ) {
    int res;
    char i;
    char j;
    i = tolower(letra_getLetra(letraI));
    j = tolower(letra_getLetra(letraJ));
    if(i < j) {
        res = -1;
    } else if (i > j) {
        res = 1;
    } else {
        res = 0;
    }

    return res;
}

int guardarArch(ArrayList* letras) {
    Eletra* aux;
    FILE* p;
    p = fopen("sin_rep.csv", "w");
    if (p == NULL) {
        printf("Error abriendo el archivo");
        return 0;
    }
    fprintf(p, "\"letra\",\"nombre\",\"vocal\",\"constante\"\n");
    for(int i = 0; i < al_len(letras); i++) {
        aux = (Eletra*) al_get(letras, i);
        letra_print(aux);
        printf("Hola");
        fprintf(p,"%c,%s,%d,%d\n", letra_getLetra(aux), letra_getNombre(aux), letra_getVocal(aux), letra_getConsonante(aux));
    }
    fclose(p);
}
