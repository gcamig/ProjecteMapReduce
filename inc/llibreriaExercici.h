#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
// incloure les llibreries que es necessiten

#define rutaFitxer "./fitxers/lorem1.txt"
#define rutaLletres "./fitxers/lletres.txt"
#define rutaParaules "./fitxers/paraules.txt"

typedef struct
{
    char lletres[26];
    int qttLletres[26];
} LLETRES;

typedef struct
{
    char paraula[MAXCADENA];
    int qttParaula;
} PARAULES;

typedef enum
{
    CONTARLLETRES = 1,
    CONTARPARAULES,
    SORTIR
} MENU;

void contarLletres();
int posCar(char);
LLETRES inicialitzarEstructura();
void guardaEnFitxer(LLETRES);
void pintaUnaLLetra(LLETRES, int);
#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */