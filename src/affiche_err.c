#include "laby.h"

int     affiche_err(Laby data)
{
    if (data.error_val == 1)
        fprintf(stderr, "Mausaise utilisation :\n./labyrinthe --help\n");
    return (1);
}
