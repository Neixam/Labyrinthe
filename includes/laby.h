#ifndef __LABY__
# define __LABY__
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

typedef struct  coord_s
{
    int     x;
    int     y;
}               coord_t;

typedef struct  case_s
{
    int             mur_est;
    int             mur_sud;
    coord_t         pere;
    unsigned int    rang;
}               case_t;

typedef struct  laby_s
{
    coord_t taille;
    case_t  **cases;
}               laby_t;

typedef struct  lst_s
{
    case_t          *dispo;
    coord_t         lui;
    struct lst_s    *next;
}               cel_case_t,
                *lst_case_t;

typedef struct  lab_s
{
    int             opt;
    int             error_val;
    unsigned long   seed;
    coord_t         size;
    unsigned int    wait;
    laby_t          lab;
}               lab_t;

int             affiche_err(lab_t data);
int             parseur(int ac, char **av, lab_t *data);
void            alea_mur(lst_case_t *dispo, int *size, laby_t *lab);
int             genere_laby(lab_t *data);
int             affiche_laby(lab_t data);
int             init_data(lab_t *data);
case_t          init_case(int mur_est, int mur_sud, int x, int y);
coord_t         init_coord(int x, int y);
int             coordcmp(coord_t c1, coord_t c2);
int             affiche_help(void);
int             init_lab(laby_t *lab, int x, int y);

#endif
