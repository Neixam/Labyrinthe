#include "laby.h"

int     main(int ac, char **av)
{
    lab_t   data;

    init_data(&data);
    if (parseur(ac, av, &data))
        return (affiche_err(data));
    if (data.opt & 16)
        return (affiche_help());
    init_lab(&data.lab, data.size.x, data.size.y);
    srand(data.seed);
    if (genere_laby(&data))
        return (affiche_err(data));
    if (affiche_laby(data))
        return (affiche_err(data));
    return (0);
}
