#include "laby.h"
#include "structures.h"

void    affiche_case(case_t c_a, case_t c_p_b, case_t c_p_d)
{
    printf("%s%s", intersections[0][0][c_a.mur_sud > 0][c_a.mur_sud > 0],
           intersections[c_p_b.mur_est > 0][c_a.mur_est > 0][c_a.mur_sud > 0][c_p_d.mur_sud > 0]);
}

void    affiche_ascii(laby_t lab)
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
}

void    affiche_case_graph(int x, int y, case_t c_a, case_t c_p_h, case_t c_p_g, float len_x, float len_y)
{
    if (c_a.mur_est > 0)
        MLV_draw_line(x + len_x, y, x + len_x, y + len_y, MLV_COLOR_WHITE);
    if (c_a.mur_sud > 0)
        MLV_draw_line(x, y + len_y, x + len_x, y + len_y, MLV_COLOR_WHITE);
    if (c_p_h.mur_sud > 0)
        MLV_draw_line(x, y, x + len_x, y, MLV_COLOR_WHITE);
    if (c_p_g.mur_est > 0)
        MLV_draw_line(x, y, x, y + len_y, MLV_COLOR_WHITE);
}

void    affiche_graph(laby_t lab)
{
    int     i;
    int     j;
    float   len_x;
    float   len_y;
    case_t  fin[2];

    MLV_clear_window(MLV_COLOR_BLACK);
    fin[0] = init_case(1, 0, -1, -1);
    fin[1] = init_case(0, 1, -1, -1);
    len_x = WIDTH / lab.taille.x;
    len_y = HEIGHT / lab.taille.y;
    for (i = 0; i < lab.taille.y; i++)
    {
        for (j = 0; j < lab.taille.x; j++)
        {   
            affiche_case_graph(j * len_x, i * len_y, lab.cases[i][j], 
                         (i != 0) ? lab.cases[i - 1][j] : (j != 0) ? fin[1] : fin[1],
                         (j != 0) ? lab.cases[i][j - 1] : (i != 0) ? fin[0] : fin[1],
                         len_x, len_y);
        }
    }
    MLV_actualise_window();
}

int     affiche_laby(lab_t data, int fini)
{
    if (data.opt & 1)
    {
        affiche_graph(data.lab);
        while (fini);
    }
    else if (data.opt & 32)
        affiche_ascii(data.lab);
    return (0);
}
