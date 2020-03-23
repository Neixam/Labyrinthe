#include "laby.h"
#include <unistd.h>

lst_case_t  alloue_cel(case_t *addr_case, int x, int y)
{
    lst_case_t  ret;

    if (!(ret = (lst_case_t)malloc(sizeof(cel_case_t))))
        return (NULL);
    ret->dispo = addr_case;
    ret->lui = init_coord(x, y);
    ret->next = NULL;
    return (ret);
}

int         ajout_en_tete(lst_case_t *lst, case_t *addr_case, int x, int y)
{
    lst_case_t  tmp;

    tmp = *lst;
    if (!(*lst = alloue_cel(addr_case, x, y)))
        return (1);
    (*lst)->next = tmp;
    return (0);
}

int        coordcmp(coord_t c1, coord_t c2)
{
    if (c1.x == c2.x && c1.y == c2.y)
        return (0);
    if (c1.y == c2.y)
        return (c1.x - c2.x);
    return (c1.y - c2.y);
}

coord_t     init_coord(int x, int y)
{
    coord_t ret;

    ret.x = x;
    ret.y = y;
    return (ret);
}
int         genere_laby(lab_t *data)
{
    coord_t     origin;

    origin = init_coord(0, 0);
    while (coordcmp(trouve(&data->lab, data->lab.cases[data->lab.taille.y - 1][data->lab.taille.x - 1].pere), origin) ||
           (data->opt & 4 && data->lab.cases[0][0].rang < data->lab.taille.x * data->lab.taille.y))
    {
        if (data->opt & 64 && data->wait)
        {
            (void)affiche_laby(*data, 0);
            if (data->opt & 32)
                printf("\n");
            usleep(data->wait);
        }
        alea_mur(&(data->dispo), &(data->len), &(data->lab), data->opt);
    }
    return (0);
}
