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

int         creation_lst(lst_case_t *lst, laby_t *lab)
{
    int     i;
    int     j;
    int     size;

    size = 0;
    for (i = 0; i < lab->taille.y; i++)
    {
        for (j = 0; j < lab->taille.x; j++)
        {
            if (lab->cases[i][j].mur_est == 1 || lab->cases[i][j].mur_sud == 1)
            {
                if (ajout_en_tete(lst, &(lab->cases[i][j]), j, i))
                    return (0);
                size++;
            }
        }
    }
    return (size);
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
    lst_case_t  case_dispo;
    coord_t     origin;
    int         size;

    case_dispo = NULL;
    if (!(size = creation_lst(&case_dispo, &(data->lab))))
    {
        data->error_val = 2;
        return (1);
    }
    origin = init_coord(0, 0);
    if (data->opt & 64 && data->wait)
    {
        (void)affiche_laby(*data);
        printf("\n");
        usleep(data->wait);
    }
    while (coordcmp(data->lab.cases[data->lab.taille.y - 1][data->lab.taille.x - 1].pere, origin))
    {
        alea_mur(&case_dispo, &size, &(data->lab));
        if (data->opt & 64 && data->wait)
        {
            (void)affiche_laby(*data);
            printf("\n");
            usleep(data->wait);
        }
    }
    return (0);
}
