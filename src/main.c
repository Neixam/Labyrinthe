#include "laby.h"

int     main(int ac, char **av)
{
    lab_t   data;

    init_data(&data);
    if (parseur(ac, av, &data))
        return (affiche_err(data));
    if (data.opt & 16)
        return (affiche_help());
    init_lab(&data.lab, &data.dispo, &data.len, data.size.x, data.size.y);
    srand(data.seed);
	if (data.opt & 1)
		MLV_create_window("Labyrinthe", "Lab", WIDTH + 1, HEIGHT + 1);
    if (genere_laby(&data))
        return (affiche_err(data));
    if (affiche_laby(data, 1))
		return (affiche_err(data));
	if (data.opt & 1)
		MLV_free_window();
    return (0);
}
