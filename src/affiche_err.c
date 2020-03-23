#include "laby.h"

int     affiche_help(void)
{
    int     c;
    FILE    *man;

    if (!(man = fopen(".man.txt", "r")))
        return (1);
    for (c = fgetc(man); c != EOF; c = fgetc(man))
        fputc(c, stdout);
    fclose(man);
    return (0);
}

int     affiche_err(lab_t data)
{
    if (data.error_val == 1)
        fprintf(stderr, "Mausaise utilisation :\n./labyrinthe --help\n");
    if (data.error_val == 2)
        fprintf(stderr, "Erreur allocation mémoire\n");
    if (data.error_val == 3)
        fprintf(stderr, "Erreur --attente=X X doit être un nombre supérieur ou égale à 0\n");
    if (data.error_val == 4)
        fprintf(stderr, "Erreur --mode=MODE MODE : graphique/texte\n");
    if (data.error_val == 5)
        fprintf(stderr, "Erreur --taille=hxl h et l doivent être strictement positif\n");
    if (data.error_val == 6)
        fprintf(stderr, "Erreur --taille=hxl l doit être indiqué\n");
    return (1);
}
