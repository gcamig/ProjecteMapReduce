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
    FILE *f;
    char c;
    f = fopen(rutaFitxer, "rt");
    c = fgetc(f);
    while (feof(f) == 0)
    {
        if (c != ESPAI)
        {
            printf("%c", c);
        }
        c = fgetc(f);
    }
    fclose(f);
}