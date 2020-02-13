#include "laby.h"

int     main(int ac, char **av)
{
    lab     data;

    init_data(&data);
    if (parseur_entrer(ac, av, &data))
        return (affiche_err(data));
    if (genere_laby(&data))
        return (affiche_err(data));
    if (affiche_laby(data))
        return (affiche_err(data));
    return (0);
}
