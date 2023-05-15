#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

void contarLletres()
{
    LLETRES lletres = inicialitzarEstructura();
    FILE *f = fopen(rutaFitxer, "rt");
    char c;
    int pos;
    c = fgetc(f);
    while (feof(f) == 0)
    {
        pos = posCar(c);
        if (pos != -1)
        {
            lletres.qttLletres[pos]++;
        }
        c = fgetc(f);
    }
    fclose(f);
    guardaEnFitxer(lletres);
}

int posCar(char carCerca)
{
    char lletres[] = "abcdefghijklmnopqrstuvwxyz";
    carCerca = tolower(carCerca);
    int i = 0;
    int pos = -1;
    // retorna -1 si el valor no esta
    // retorna la pos si el valor esta

    while (i < sizeof(lletres) && pos == -1)
    {
        if (lletres[i] == carCerca)
            pos = i;
        else
            i++;
    }
    return pos;
}

LLETRES inicialitzarEstructura()
{
    LLETRES l;
    char lletres[] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0, qttE = sizeof(l.qttLletres) / sizeof(int);
    while (i < qttE)
    {
        l.lletres[i] = lletres[i];
        l.qttLletres[i] = 0;
        i++;
    }
    return l;
}

void guardaEnFitxer(LLETRES l)
{
    int i = 0, qttE = sizeof(l.lletres);
    while (i < qttE)
    {
        pintaUnaLLetra(l, i);
        i++;
    }
}

void pintaUnaLLetra(LLETRES l, int index)
{
    FILE *f = fopen(rutaLletres, "at");
    fprintf(f, "%c: %d", l.lletres[index], l.qttLletres[index]);
    if (index != 25)
    {
        fputc('\n', f);
    }
    fclose(f);
}

void contarParaules()
{
    PARAULES p[1000];
    FILE *f = fopen(rutaFitxer, "rt");
    int i = 0;
    while (feof(f) == 0)
    {
    }
}