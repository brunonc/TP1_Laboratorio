#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*!
   \brief Calcula el factorial de manera recursiva.
   \param n El entero del cual se desea calcular el factorial.
   \return Un entero que representa el resultado del factorial.
*/
int factorial(int n) {
  int res;
  if (n == 1) {
    return 1;
  }
  res = n * factorial(n - 1);
  return res;
}

/*!
   \brief Verifica una opcion de Si o No.
   \param mensaje[] El mensaje a mostrar.
   \return Devuelve 0 para N o 1 para S.
*/
int verificaSN(char mensaje[]) {
  char input;
  printf("%s [S/N]?", mensaje);
  input = toupper(getche());
  while (!((input == 'S') || (input == 'N'))) {
    printf("La opcion ingresada no es valida.\n%s [S/N?]", mensaje);
    input = toupper(getche());
  }
  return input == 'S';
}

/*!
   \brief Obtiene un numero y lo devuelve en res.
   \param mensaje[] El mensaje a mostrar.
   \return Un flotante que representa el numero ingresado.
*/
float getFloat(char mensaje[]) {
  float res;
  printf("%s", mensaje);
  scanf("%f", &res);
  return res;
}

/*!
   \brief Obtiene un numero y lo devuelve en res.
   \param mensaje[] El mensaje a mostrar.
   \return Un entero que representa el numero ingresado.
*/
int getInt(char mensaje[]) {
  int res;
  printf("%s", mensaje);
  scanf("%d", &res);
  return res;
}

/*!
   \brief Obtiene un caracter y lo devuelve en res.
   \param mensaje[] El mensaje a mostrar.
   \return Un char que representa el caracter ingresado.
*/
char getChar(char mensaje[]) {
  char res;
  printf("%s", mensaje);
  fflush(stdin); // Win
  scanf("%c", &res);
  return res;
}

/*!
   \brief Genera un entero aleatorio.
   \param desde El minimo.
   \param hasta El maximo.
   \param iniciar Indica si se trata del primer numero solicitado. 1 indica que si.
   \return Un entero que representa el numero aleatorio generado.
*/
int getRandomInt(int desde , int hasta, int iniciar) {
  if(iniciar) {
    srand(time(NULL));
  }
  return rand() % (hasta - desde + 1) + desde;
}

/*!
   \brief Busca el mayor entero en el array pasado como parametro.
   \param vec[] El array en el cual se debe buscar.
   \return Un entero que representa el mayor elemento del array.
*/
int buscarMayorSecuencial(int vec[]) {
  int mayor = vec[0];
  int i;
  int vecSize = sizeof(vec) / sizeof(int);
  for (i = 1; i < vecSize; i++) {
    if (vec[i] > mayor) {
      mayor = vec[i];
    }
  }
  return mayor;
}

/*!
   \brief Busca el menor entero en el array pasado como parametro.
   \param vec[] El array en el cual se desea buscar.
   \return Un entero que representa el menor elemento del array.
*/
int buscarMenorSecuencial(int vec[]) {
  int menor = vec[0];
  int i;
  int vecSize = sizeof(vec) / sizeof(int);
  for (i = 1; i < vecSize; i++) {
    if (vec[i] < menor) {
      menor = vec[i];
    }
  }
  return menor;
}

/*!
   \brief Busca un numero en el vector, ambos pasados como parametro.
   \param vec[] El vector en el cual buscar.
   \param valor Un entero que se corresponde con el valor a buscar en el vector.
   \return Devuelve un entero que representa la posicion en el vector, ssi se encontro el valor, o el valor -1 si no se encontro.
*/
int buscarValor(int vec[], int valor) {
  int i;
  int vecSize = sizeof(vec) / sizeof(int);
  for (i = 0; i < vecSize; i++) {
    if (vec[i] == valor) {
      return i;
    }
  }
  return -1;
}

/*!
   \brief Ordena de manera ascendente un vector por burbujeo.
   \param vec[] El vector a ordenar.
*/
void ordenarAscPorburbujeo(int vec[]) {
  int i, j, aux;
  int vecSize = sizeof(vec) / sizeof(int);
  for (i = 0; i < vecSize - 1; i++) {
    for (j = i + 1; j < vecSize; j++) {
      if (vec[i] > vec[j]) {
        aux = vec[i];
        vec[i] = vec[j];
        vec[j] = aux;
      }
    }
  }
}

/*!
   \brief Ordena de manera descendente un vector por burbujeo.
   \param vec[] El vector a ordenar.
*/
void ordenarDescPorburbujeo(int vec[]) {
  int i, j, aux;
  int vecSize = sizeof(vec) / sizeof(int);
  for (i = 0; i < vecSize - 1; i++) {
    for (j = i + 1; j < vecSize; j++) {
      if (vec[i] < vec[j]) {
        aux = vec[i];
        vec[i] = vec[j];
        vec[j] = aux;
      }
    }
  }
}

/*!
   \brief Verifica si la cadena recibida es numerica.
   \param str[] Cadena de caracteres a ser analizada.
   \return Devuelve 1 ssi la cadena es numerica y 0 en caso contrario.
*/
int esNumerico(char str[]) {
  int i = 0;
  while (str[i] != '\0') {
    if(str[i] < '0' || str[i] > '9') {
      return 0;
    }
    i++;
  }
  return 1;
}

/*!
   \brief Verifica si el valor ingresado es numerico aceptando flotantes.
   \param str[] Cadena de caracteres a ser analizada.
   \return Devuelve 1 ssi la cadena es numerica y 0 en caso contrario.
*/
int esNumericoFlotante(char str[]) {
  int i = 0;
  int cantidadPuntos = 0;
  while (str[i] != '\0') {
    if (str[i] == '.' && cantidadPuntos == 0) {
      cantidadPuntos++;
      i++;
      continue;
    }
    if (str[i] < '0' || str[i] > '9') {
      return 0;
    }
    i++;
  }
  return 1;
}

/*!
   \brief Verifica si la cadena recibida es alfabetica (incluido espacios).
   \param str[] Cadena de caracteres a ser analizada.
   \return Devuelve 1 ssi la cadena es alfabetica y 0 en caso contrario.
*/
int esAlfabetico(char str[]) {
  int i = 0;
  while (str[i] != '\0') {
    if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) {
      return 0;
    }
    i++;
  }
  return 1;
}

/*!
   \brief Verifica si la cadena recibida es alfanumerica (incluido espacios).
   \param str[] Cadena de caracteres a ser analizada.
   \return Devuelve 1 ssi la cadena es alfanumerica y 0 en caso contrario.
*/
int esAlfaNumerico(char str[]) {
  int i = 0;
  while (str[i] != '\0') {
    if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9')) {
      return 0;
    }
    i++;
  }
  return 1;
}

/*!
   \brief Verifica si la cadena recibida tiene el formato <numero>-<numero> con espacios incluidos.
   \param str[] Cadena de caracteres a ser analizada.
   \return Devuelve 1 ssi la cadena tiene el formato adecuado, 0 en caso contrario.
*/
int esTarjeta(char str[]) {
  int i = 0;
  int contGuiones = 0;
  while (str[i] != '\0') {
    if ((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9')) {
      return 0;
    }
    if (str[i] == '-') {
      contGuiones++;
    }
    i++;
  }
  if (contGuiones == 1) { // debe tener un guion
    return 1;
  }
  return 0;
}

/*!
   \brief Inicializa un array de enteros con el valor pasado como parametro.
   \param array[] El array a inicializar.
   \param valor El valor (entero) que se cargara en cada posicion.
*/
void initIntArray(int array[], int valor) {
  int i;
  int arrSize = sizeof(array) / sizeof(int);
    for(i = 0; i < arrSize; i++) {
      array[i] = valor;
    }
}

/*!
   \brief Solicita un texto y lo retorna.
   \param mensaje[] Es el mensaje de solicitud de la cadena.
   \param input[] Array donde se cargara la cadena.
*/
void getString(char mensaje[], char input[]) {
  printf("%s", mensaje);
  scanf ("%s", input);
}

/*!
   \brief Solicita un texto y lo retorna.
   \param mensaje[] Es el mensaje de solicitud de la cadena.
   \param input[] Array donde se cargara la cadena.
   \return Devuelve 1 ssi la cadena contiene solo letras, 0 en caso contrario.
*/
int getStringLetras(char mensaje[], char input[]) {
  char aux[256];
  getString(mensaje, aux);
  if (esAlfabetico(aux)) {
    strcpy(input,aux);
    return 1;
  }
  return 0;
}

/*!
   \brief Solicita una cadena numerica y la retorna
   \param mensaje[] Es el mensaje de solicitud de la cadena.
   \param input[] Array donde se cargara la cadena.
   \return Devuelve 1 ssi la cadena contiene solo numeros, 0 en caso contrario.
*/
int getStringNumeros(char mensaje[], char input[]) {
  char aux[256];
  getString(mensaje, aux);
  if (esNumerico(aux)) {
    strcpy(input, aux);
    return 1;
  }
  return 0;
}

/*!
   \brief Solicita una cadena numerica y la retorna (acepta flotantes).
   \param mensaje[] Es el mensaje de solicitud de la cadena.
   \param input[] Array donde se cargara la cadena.
   \return Devuelve 1 ssi la cadena contiene solo numeros, 0 en caso contrario.
*/
int getStringNumerosFlotantes(char mensaje[], char input[]) {
  char aux[256];
  getString(mensaje, aux);
  if (esNumericoFlotante(aux)) {
    strcpy(input,aux);
    return 1;
  }
  return 0;
}

/*!
   \brief Solicita un entero y lo valida.
   \param requestMessage[] Mensaje para ser mostrado al solicitar el dato.
   \param errorMessage[] El mensaje a ser mostrado en caso de error.
   \param lowLimit Limite inferior valido.
   \param hiLimit Limite superior valido.
   \return El numero validado.
*/
int getValidInt(char requestMessage[], char errorMessage[], int lowLimit, int hiLimit) {
  char auxStr[256];
  int auxInt;
  while (1) {
    if (!getStringNumeros(requestMessage, auxStr)) {
      printf ("%s\n", errorMessage);
      continue;
    }
    auxInt = atoi(auxStr);
    if (auxInt < lowLimit || auxInt > hiLimit) {
      printf("El numero del debe ser mayor a %d y menor a %d\n", lowLimit, hiLimit);
      continue;
    }
    return auxInt;
    }
}

int esNombreArch(char str[]) {
  int i = 0;
  while (str[i] != '\0') {
    if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] == '_') && (str[i] == '-') && (str[i] == '.')) {
      return 0;
    }
    i++;
  }
  return 1;
}

int getStringArch(char mensaje[], char input[]) {
  char aux[256];
  getString(mensaje, aux);
  if (esNombreArch(aux)) {
    strcpy(input,aux);
    return 1;
  }
  return 0;
}

void getValidArch(char requestMessage[], char errorMessage[], char input[]) {
  while (1) {
    if (!getStringArch(requestMessage, input)) {
      printf ("%s\n", errorMessage);
      continue;
    }
    fflush(stdin);
    break;
    }
}

/*!
   \brief Solicita una cadena y la valida.
   \param requestMessage[] Mensaje para ser mostrado al solicitar el dato.
   \param errorMessage[] El mensaje a ser mostrado en caso de error.
   \param input[] Array donde se cargara el texto validado.
*/
void getValidString(char requestMessage[], char errorMessage[], char input[]) {
  while (1) {
    if (!getStringLetras(requestMessage, input)) {
      printf ("%s\n", errorMessage);
      continue;
    }
    fflush(stdin);
    break;
    }
}

void getValidTarjeta(char requestMessage[], char errorMessage[], char input[]) {
  while (1) {
    if (!getStringTarjeta(requestMessage, input)) {
      printf ("%s\n", errorMessage);
      continue;
    }
    fflush(stdin);
    break;
    }
}

int getStringTarjeta(char mensaje[], char input[]) {
  char aux[256];
  getString(mensaje, aux);
  if (esTarjeta(aux)) {
    strcpy(input,aux);
    return 1;
  }
  return 0;
}
