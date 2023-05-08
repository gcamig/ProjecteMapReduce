#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void acabament(void)
{
    printf("\nPrem una tecla per finalitzar");
    getch();
}

int demanaNumeroEntreDosValors(int minim, int maxim)
{
    int x;
    scanf("%d", &x);
    while (x < minim || x > maxim)
    {
        printf("Introduiex un valor valid [%d-%d]: ", minim, maxim);
        scanf("%d", &x);
    }
    return x;
}

int generarNumeroEntreDosValors(int minim, int maxim)
{
    return (rand() % (maxim - minim + 1) + minim);
}

int demanaNumeroAPartirUnValor(int minim)
{
    int x;
    scanf("%d", &x);
    while (x < minim)
    {
        printf("Insereix un n√∫mero v√†lid >= %d: ", minim);
        scanf("%d", &x);
    }

    return x;
}

char demanaCaracter(void)
{
    char car;
    fflush(stdin);
    scanf("%c", &car);
    return car;
}

bool esTraspas(int any)
{
    bool traspas = true;
    if (any % 4 == 0 && any % 100 != 0)
    {
        traspas = true;
    }
    else if (any % 4 == 0 && any % 100 == 0)
    {
        if ((any / 100) % 4 == 0)
        {
            traspas = true;
        }
    }
    return traspas;
}

int demanaNumero(void)
{
    int num;
    scanf("%d", &num);
    return num;
}

void intercanviVariables(int *num1, int *num2)
{
    int copia = (*num1);
    (*num1) = (*num2);
    (*num2) = copia;
}

float calculaMitja(int v[], int qttE, bool *ok)
{
    (*ok) = true;
    int suma = 0;
    float mitja = -1;

    if (qttE > 0)
    {
        for (int i = 0; i < qttE; i++)
        {
            suma = suma + v[i];
        }
        mitja = (float)suma / qttE;
    }
    else
    {
        (*ok) = false;
    }
    return mitja;
}

void mostraContingut(int v[], int qttE)
{
    if (qttE == 0)
        printf("\nVector buit");
    else
    {
        for (int i = 0; i < qttE; i++)
        {
            printf("\nv[%02d]:%02d", i, v[i]);
        }
    }
}

bool cerca(int v[], int qttE, int numCerca)
{
    bool trobat = false;
    int i = 0;

    while (i < qttE && trobat == false)
    {
        if (v[i] == numCerca)
            trobat = true;
        else
            i++;
    }
    return trobat;
}

bool cercaSentilla(int v[], int qttE)
{
    // juga amb tenir en v[qttE] el valor que estem buscant
    bool trobat = true;
    int i = 0;
    while (v[i] != v[qttE])
        i++;
    if (i == qttE)
        trobat = false;

    return trobat;
}

int posicio(int v[], int qttE, int numCerca)
{
    int i = 0;
    int pos = -1;
    // retorna -1 si el valor no esta
    // retorna la pos si el valor esta

    while (i < qttE && pos == -1)
    {
        if (v[i] == numCerca)
            pos = i;
        else
            i++;
    }
    return pos;
}

void seleccioMin(int v[], int qttE)
{
    int min;
    int posMin;

    for (int i = 0; i <= qttE - 2; i++)
    {
        min = v[i];
        posMin = i;

        for (int j = i + 1; j < qttE; j++)
        {
            if (v[j] < min)
            {
                min = v[j];
                posMin = j;
            }
        }
        if (i != posMin)
        {
            intercanviVariables(&v[i], &v[posMin]);
        }
    }
}

void seleccioMax(int v[], int qttE)
{
    int max;
    int posMax;

    for (int i = 0; i <= qttE - 2; i++)
    {
        max = v[i];
        posMax = i;

        for (int j = i + 1; j < qttE; j++)
        {
            if (v[j] > max)
            {
                max = v[j];
                posMax = j;
            }
        }
        if (i != posMax)
        {
            intercanviVariables(&v[i], &v[posMax]);
        }
    }
}

void bombolla(int v[], int qttE)
{
    for (int pasada = 0; pasada <= qttE - 2; pasada++)
    {
        for (int i = 0; i <= qttE - 2 - pasada; i++)
        {
            if (v[i] > v[i + 1])
            {
                intercanviVariables(&v[i], &v[i + 1]);
            }
        }
    }
}

bool esLletra(char car)
{
    bool esLletra = false;
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ¿¡»…Õœ“”⁄‹—«abcdefghijklmnopqrstuvwxyz‡·ËÈÌÔÚÛ˙¸ÒÁ";
    int i = 0;
    int longitud = strlen(lletres);
    while (lletres[i] != FICADENA && i < longitud && esLletra == false)
    {
        if (lletres[i] == car)
        {
            esLletra = true;
        }
        else
        {
            i++;
        }
    }
    return esLletra;
}

bool esNumOLletra(char car)
{
    bool esLletra = false;
    char lletres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ¿¡»…Õœ“”⁄‹—«abcdefghijklmnopqrstuvwxyz‡·ËÈÌÔÚÛ˙¸ÒÁ0123456789";
    int i = 0;
    int longitud = strlen(lletres);
    while (lletres[i] != FICADENA && i < longitud && esLletra == false)
    {
        if (lletres[i] == car)
        {
            esLletra = true;
        }
        else
        {
            i++;
        }
    }
    return esLletra;
}

bool esVocal(char car)
{
    bool esVocal = false;
    char vocals[] = "AEIOU¿¡»…Õœ“”⁄‹aeiou‡·ËÈÌÔÚÛ˙¸";
    int i = 0;
    int longitud = strlen(vocals);
    while (vocals[i] != FICADENA && i < longitud && esVocal == false)
    {
        if (vocals[i] == car)
        {
            esVocal = true;
        }
        else
        {
            i++;
        }
    }
    return esVocal;
}

void pintaCadena(char frase[], int longitud)
{
    int i = 0;

    while (i < longitud && frase[i] != FICADENA)
    {
        printf("%c", frase[i]);
        i++;
    }
}

int calculLongitud(char frase[], int longitud)
{
    int i = 0;
    while (i < longitud && frase[i] != FICADENA)
    {
        i++;
    }
    return i;
}

void entrarCadena(char frase[], int longitud)
{
    fflush(stdin);
    // llegeix longitud -1 caracters per deixar l'espai per a el FICADENA
    fgets(frase, longitud, stdin); // stdin: teclat
    fflush(stdin);
    if (frase[strlen(frase) - 1] == SALTLINIA)
    {
        frase[strlen(frase) - 1] = FICADENA;
    }
}

bool cercaCaracterCadena(char paraula[], int longitud, char carCerca)
{
    bool trobat = false;
    int i = 0;
    while (i < longitud && paraula[i] != FICADENA && !trobat)
    {
        if (paraula[i] == carCerca)
            trobat = true;
        else
            i++;
    }
    return trobat;
}

void pintaMenu()
{
    char opcions[SORTIR][MAXCADENA] = {"Contar lletres", "Contar paraules", "Sortir"};

    for (int i = 0; i < SORTIR; i++)
    {
        printf("\n%d:-%s", i + 1, opcions[i]);
    }
}

void generaFitxer(FILE *f)
{
    f = fopen("./fitxers/dades.txt", "wt");
    if (f != NULL)
    {
        for (int i = 1; i < 100; i++)
        {
            if (i > 1)
                fputc('\n', f);
            fprintf(f, "Fitxer%d.txt", i);
        }
    }
    fclose(f);
}

bool existeixFitxer(char ubicacioNom[])
{
    bool existeix = false;
    FILE *f;
    f = fopen(ubicacioNom, "rt");
    if (f != NULL)
    {
        existeix = true;
        fclose(f);
    }
    else
    {
        printf("El fitxer no existeix.");
    }
    return existeix;
}

bool fitxerBuit(char nomFile[])
{
    bool buit = true;
    FILE *f;
    f = fopen(nomFile, "rt");
    if (f != NULL)
    {
        fseek(f, 0, SEEK_END);
        if (ftell(f) > 0)
            buit = false;
        fclose(f);
    }
    return buit;
}

void llegir(char nomFitxer[])
{
    FILE *f;
    char frase[MAXCADENA];

    if (existeixFitxer(nomFitxer) && !fitxerBuit(nomFitxer))
    {
        f = fopen(nomFitxer, "rt");
        printf("\nContingut del fitxer:\n");
        while (feof(f) == 0)
        {
            fgets(frase, sizeof(frase), f);
            printf("%s", frase);
        }
        fclose(f);
    }
}

void eliminarSaltLinia(char frase[])
{
    if (strlen(frase) > 0 && frase[strlen(frase) - 1] == SALTLINIA)
    {
        frase[strlen(frase) - 1] = FICADENA;
    }
}

void concatenar(char nomFinal[], char ruta[], char nomFitxer[])
{
    strcpy(nomFinal, ruta);      //./fitxers/
    strcat(nomFinal, nomFitxer); //./fitxers/a.txt
}