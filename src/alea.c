#include "laby.h"

coord_t copycoord(coord_t source)
{
    coord_t ret;

    ret = init_coord(source.x, source.y);
    return (ret);
}

coord_t trouve(laby_t *lab, coord_t c)
{
    if (coordcmp(lab->cases[c.y][c.x].pere, c))
        lab->cases[c.y][c.x].pere = trouve(lab, lab->cases[c.y][c.x].pere);
    return (copycoord(lab->cases[c.y][c.x].pere));
}

void    fusion(laby_t *lab, coord_t c1, coord_t c2)
{
    coord_t pere_c1;
    coord_t pere_c2;
    int     i;
    int     j;
    int     diff;
 
    pere_c1 = trouve(lab, c1);
    pere_c2 = trouve(lab, c2);
    if (!(diff = coordcmp(pere_c1, pere_c2)))
        return ;
    if (diff < 0)
    {
        lab->cases[pere_c1.y][pere_c1.x].rang += lab->cases[pere_c2.y][pere_c2.x].rang;
        lab->cases[c2.y][c2.x].pere = copycoord(pere_c1);
        for (i = 0; i < lab->taille.y; i++)
            for (j = 0; j < lab->taille.x; j++)
                if (!coordcmp(lab->cases[i][j].pere, pere_c2))
                    lab->cases[i][j].pere = copycoord(pere_c1);
    }
    else
    {
        lab->cases[pere_c2.y][pere_c2.x].rang += lab->cases[pere_c1.y][pere_c1.x].rang;
        lab->cases[c1.y][c1.x].pere = copycoord(pere_c2);
        for (i = 0; i < lab->taille.y; i++)
            for (j = 0; j < lab->taille.x; j++)
                if (!coordcmp(lab->cases[i][j].pere, pere_c1))
                    lab->cases[i][j].pere = copycoord(pere_c2);
    }
}



void    alea_mur(lst_case_t *dispos, int *size, laby_t *lab, int opt)
{
    int         pos;
    int         i;
    int         d_b;
    int         x;
    int         y;
    lst_case_t  tmp;
    lst_case_t  tmp2;

    pos = rand() % *size;
    tmp = *dispos;
    if (pos == 0)
    {
        if ((*dispos)->dispo->mur_est % 2 == 0) 
        {
            (*dispos)->dispo->mur_sud = 0;
            d_b = 0;
        }
        else if ((*dispos)->dispo->mur_sud % 2 == 0)
        {
            (*dispos)->dispo->mur_est = 0;
            d_b = 1;
        }
        else
        {
            if (rand() % 2)
            {
                (*dispos)->dispo->mur_est = 0;
                d_b = 1;
            }
            else
            {
                (*dispos)->dispo->mur_sud = 0;
                d_b = 0;
            }
        }
        x = (*dispos)->lui.x + ((d_b) ? 1 : 0);
        y = (*dispos)->lui.y + ((d_b) ? 0 : 1);
        fusion(lab, (*dispos)->lui, init_coord(x, y));
        if (((*dispos)->dispo->mur_est % 2 == 0 &&
            (*dispos)->dispo->mur_sud % 2 == 0)) 
        {
            *dispos = (*dispos)->next;
            free(tmp);
            (*size)--;
        }
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
            (*dispos) = (*dispos)->next;
        if ((*dispos)->next->dispo->mur_est % 2 == 0)
        {
            (*dispos)->next->dispo->mur_sud = 0;
            d_b = 0;
        }
        else if ((*dispos)->next->dispo->mur_sud % 2 == 0)
        {
            (*dispos)->next->dispo->mur_est = 0;
            d_b = 1;
        }
        else
        {
            if (rand() % 2)
            {
                (*dispos)->next->dispo->mur_est = 0;
                d_b = 1;
            }
            else
            {
                (*dispos)->next->dispo->mur_sud = 0;
                d_b = 0;
            }
        }
        x = (*dispos)->next->lui.x + ((d_b) ? 1 : 0);
        y = (*dispos)->next->lui.y + ((d_b) ? 0 : 1);
        fusion(lab, (*dispos)->next->lui, init_coord(x, y));
        if (((*dispos)->next->dispo->mur_est % 2 == 0 &&
            (*dispos)->next->dispo->mur_sud % 2 == 0))
        {
            tmp2 = (*dispos)->next;
            (*dispos)->next = tmp2->next;
            free(tmp2);
            (*size)--;
        }
        *dispos = tmp;
    }
}
