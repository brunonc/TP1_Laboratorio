#ifndef LETRA_H_INCLUDED
#define LETRA_H_INCLUDED

#include "ArrayList.h"

struct {
    char letra;
    char nombre[22];
    int vocal;
    int consonante;
} typedef Eletra;

int parsearDatos(FILE*, ArrayList*);
Eletra* new_letra(void);
int letra_setLetra(Eletra*, char*);
int letra_setNombre(Eletra*, char*);
int letra_setVocal(Eletra*, int);
int letra_setConsonante(Eletra*, int);
char letra_getLetra(Eletra*);
int letra_getVocal(Eletra*);
int letra_getConsonante(Eletra*);
void letra_print(Eletra*);
int comprobar(ArrayList*, char*);
ArrayList* generar(ArrayList*);
int comparar(Eletra*, Eletra*);

#endif // LETRA_H_INCLUDED
