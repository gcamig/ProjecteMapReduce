#ifndef D8E5564E_A998_46E6_9A70_0B73488F1AF3
#define D8E5564E_A998_46E6_9A70_0B73488F1AF3
// incloure les llibreries que es necessiten

#define rutaFitxer "./fitxers/lorem1.txt"

typedef struct
{
    int lletres[26];
    int qttLletres[26];
}LLETRES;

typedef enum {
    CONTARLLETRES = 1,
    CONTARPARAULES,
    SORTIR
} MENU;

void contarLletres();
#endif /* D8E5564E_A998_46E6_9A70_0B73488F1AF3 */