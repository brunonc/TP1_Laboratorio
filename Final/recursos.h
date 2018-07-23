#ifndef RECURSOS_H_INCLUDED
#define RECURSOS_H_INCLUDED

int factorial(int);
int verificaSN(char[]);
float getFloat(char[]);
int getInt(char[]);
char getChar(char[]);
int getRandomInt(int, int, int);
int buscarMayorSecuencial(int[]);
int buscarMenorSecuencial(int[]);
int buscarValor(int[], int);
void ordenarAscPorburbujeo(int[]);
void ordenarDescPorburbujeo(int[]);
int esNumerico(char[]);
int esNumericoFlotante(char[]);
int esAlfabetico(char[]);
int esAlfaNumerico(char[]);
int esTarjeta(char[]);
void initIntArray(int[], int);
void getString(char[], char[]);
int getStringLetras(char[], char[]);
int getStringNumeros(char[], char[]);
int getStringNumerosFlotantes(char[], char[]);
int getValidInt(char[], char[], int, int);
void getValidString(char[], char[], char[]);
void getValidTarjeta(char[], char[], char[]);
int getStringTarjeta(char[], char[]);
int esNombreArch(char[]);
int getStringArch(char[], char[]);
void getValidArch(char[], char[], char[]);

#endif // RECURSOS_H_INCLUDED
