#ifndef __LLIBRERIA_PROPIA_H__
#define __LLIBRERIA_PROPIA_H__
// incloure les llibreries que es necessiten
#include <stdbool.h>
#define FICADENA '\0'
#define SALTLINIA '\n'
#define ESPAI ' '
#define MAXVECTOR 5
#define MAXCADENA 100

void acabament(void);
int demanaNumeroEntreDosValors(int, int);
int generarNumeroEntreDosValors(int, int);
int demanaNumeroAPartirUnValor(int);
char demanaCaracter(void);
bool esTraspas(int);
int demanaNumero(void);
void intercanviVariables(int *, int *);
float calculaMitja(int[], int, bool *);
void mostraContingut(int[], int);
bool cerca(int[], int, int);
bool cercaSentilla(int[], int);
int posicio(int[], int, int);
void seleccioMin(int[], int);
void seleccioMax(int[], int);
void bombolla(int[], int);
bool esLletra(char);
bool esVocal(char);
void pintaCadena(char[], int);
int calculLongitud(char[], int);
void entrarCadena(char[], int);
bool cercaCaracterCadena(char[], int, char);
void pintaMenu();
bool esNumOLletra(char);
void generaFitxer(FILE *);
bool existeixFitxer(char[]);
bool fitxerBuit(char[]);
void llegir(char[]);
void eliminarSaltLinia(char[]);
void concatenar(char[], char[], char[]);
#endif