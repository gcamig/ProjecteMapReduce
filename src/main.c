#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main()
{
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
    srand(time(NULL));

    MENU opcio;

    do
    {
        pintaMenu();
        printf("\nIntrodueix quina opció vols: [1...%d]: ", SORTIR);
        opcio = demanaNumeroEntreDosValors(1, SORTIR);

        switch (opcio)
        {
        case SORTIR:
            printf("Adeu");
            break;
        case CONTARLLETRES:
            contarLletres();
            break;
        case CONTARPARAULES:

            break;
        }
    } while (opcio != SORTIR);

    acabament();
    return 0;
}
