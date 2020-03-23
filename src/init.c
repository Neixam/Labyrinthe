#include "laby.h"

case_t  init_case(int mur_est, int mur_sud, int x, int y)
{
    case_t  ret;

    ret.pere.y = y;
    ret.pere.x = x;
    ret.rang = 1;
    ret.mur_est = mur_est;
    ret.mur_sud = mur_sud;
    return (ret);
}

int     init_lab(laby_t *lab, lst_case_t *lst, int *size, int x, int y)
{
    int     i;
    int     j;

    lab->taille.x = x;
    lab->taille.y = y;
    *size = 0;
    if (!(lab->cases = (case_t**)malloc(sizeof(case_t*) * (y))))
        return (1);
    for (i = 0; i < lab->taille.y; i++)
    {
        if (!(lab->cases[i] = (case_t*)malloc(sizeof(case_t) * (x))))
            return (1);
        for (j = 0; j < lab->taille.x; j++)
        {
            if (i + 1 == y && j + 1 == x)
                lab->cases[i][j] = init_case(-2, 2, j, i);
            else if (j + 1 == x)
                lab->cases[i][j] = init_case(2, 1, j, i);
            else if (i + 1 == y)
                lab->cases[i][j] = init_case(1, 2, j, i);
            else
                lab->cases[i][j] = init_case(1, 1, j, i);
            if (lab->cases[i][j].mur_est == 1 ||
                lab->cases[i][j].mur_sud == 1)
            {
                if (ajout_en_tete(lst, &(lab->cases[i][j]), j, i))
                    return (1);
                (*size)++;
            }
        }
    }
    return (0);
}

int     init_data(lab_t *data)
{
    data->opt = 1;
    data->error_val = 0;
    data->seed = time(NULL);
    data->size.x = 8;
    data->size.y = 6;
    data->wait = 0;
/*    if (!(init_lab(&(data->lab), 8, 6)))
        return (1);*/
    return (0);
}
