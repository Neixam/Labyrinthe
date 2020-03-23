#ifndef __LABY__
# define __LABY__
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include <MLV/MLV_all.h>
# define WIDTH 600.0
# define HEIGHT 600.0

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
    lst_case_t      dispo;
    int             len;
    unsigned int    wait;
    laby_t          lab;
}               lab_t;

coord_t         trouve(laby_t *lab, coord_t c);
int             affiche_err(lab_t data);
int             parseur(int ac, char **av, lab_t *data);
void            alea_mur(lst_case_t *dispo, int *size, laby_t *lab, int opt);
int             genere_laby(lab_t *data);
int             ajout_en_tete(lst_case_t *lst, case_t *addr_case, int x, int y);
int             affiche_laby(lab_t data, int fini);
int             init_data(lab_t *data);
case_t          init_case(int mur_est, int mur_sud, int x, int y);
coord_t         init_coord(int x, int y);
int             coordcmp(coord_t c1, coord_t c2);
int             affiche_help(void);
int             init_lab(laby_t *lab, lst_case_t *lst, int *size,int x, int y);

#endif
