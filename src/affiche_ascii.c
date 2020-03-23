#include "laby.h"
#include "structures.h"

void    affiche_case(case_t c_a, case_t c_p_b, case_t c_p_d)
{
    printf("%s%s", intersections[0][0][c_a.mur_sud > 0][c_a.mur_sud > 0],
           intersections[c_p_b.mur_est > 0][c_a.mur_est > 0][c_a.mur_sud > 0][c_p_d.mur_sud > 0]);
}

int     affiche_ascii(laby_t lab)
{
    int     i;
    int     j;
    case_t  fin[3];

    fin[0] = init_case(1, 0, -1, -1);
    fin[1] = init_case(0, 1, -1, -1);
    fin[2] = init_case(0, 0, -1, -1);
    printf("%s", intersections[0][0][0][1]);
    for (j = 0; j < lab.taille.x; j++)
        printf("%s%s", intersections[0][0][1][1], 
               intersections[(j != lab.taille.x) ? lab.cases[0][j].mur_est > 0 : 1][0][1][j + 1 != lab.taille.x]);
    printf("\n");
    for (i = 0; i < lab.taille.y; i++)
    {
        printf("%s", intersections[i + 1 != lab.taille.y][i != 0][0][lab.cases[i][0].mur_sud > 0]);
        for (j = 0; j < lab.taille.x; j++)
        {   
            affiche_case(lab.cases[i][j], 
                         (i != lab.taille.y - 1) ? lab.cases[i + 1][j] : (j != lab.taille.x - 1) ? fin[1] : fin[2],
                         (j != lab.taille.x - 1) ? lab.cases[i][j + 1] : (i != lab.taille.y - 1) ? fin[0] : fin[2]);
        }
        printf("\n");
    }
    return (0);
}

int     affiche_laby(lab_t data)
{
    if (data.opt & 1)
        return (0);
        /*return (affiche_graph(data));*/
    if (data.opt & 32)
        return (affiche_ascii(data.lab));
    return (0);
}
