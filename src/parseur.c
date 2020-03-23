#include "laby.h"
#include <string.h>
#include "parseur.h"

char    *ft_tabstrstr(char tab[][25], char *str)
{
    int     i;

    for (i = 0; tab[i][0]; i++)
        if (!strncmp(tab[i], str, strlen(tab[i])))
            return (tab[i]);
    return (NULL);
}

int     traite_arg(char *arg, char *option, lab_t *data)
{
    if (!strcmp(option, "unique"))
        data->opt = data->opt | 2;
    else if (!strcmp(option, "acces"))
        data->opt = data->opt | 4;
    else if (!strcmp(option, "victor"))
        data->opt = data->opt | 8;
    else if (!strcmp(option, "help"))
        data->opt = data->opt | 16;
    else if (!strcmp(option, "mode="))
    {
        if (!strcmp(arg, "texte"))
        {
            if (data->opt & 1)
                data->opt = data->opt - 1;
            data->opt = data->opt | 32;
        }
        else if (!strcmp(arg, "graphique"))
        {
            if (data->opt & 32)
                data->opt -= 32;
            data->opt = data->opt | 1;
        }
        else
            return (4);
    }
    else if (!strcmp(option, "graine="))
        data->seed = atoi(arg);
    else if (!strcmp(option, "attente="))
    {
        if ((data->wait = atoi(arg)) < 0)
            return (3);
        data->opt = data->opt | 64;
    }
    else if (!strcmp(option, "taille="))
    {
        if ((data->size.y = atoi(arg)) <= 0)
            return (5);
        for (; *arg && *arg != 'x'; arg++);
        if (!*arg)
            return (6);
        arg++;
        if ((data->size.x = atoi(arg)) <= 0)
            return (5);
    }
    else
        return (1);
    return (0);
}

void    init_opt(char opt[][25])
{
    strcpy(opt[0], "mode=");
    strcpy(opt[1], "graine=");
    strcpy(opt[2], "attente=");
    strcpy(opt[3], "taille=");
    strcpy(opt[4], "unique");
    strcpy(opt[5], "acces");
    strcpy(opt[6], "victor");
    strcpy(opt[7], "help");
    strcpy(opt[8], "");
}

int     parseur(int ac, char **av, lab_t *data)
{
    int     i;
    char    *choix;
    char    option[OPT + 1][CNT];

    init_opt(option);
    for (i = 1; i < ac; i++)
    {
        if (strncmp(av[i], "--", 2))
        {
            data->error_val = 1;
            return (1);
        }
        if (!(choix = ft_tabstrstr(option, &av[i][2])))
        {
            data->error_val = 1;
            return (1);
        }
        if ((data->error_val = traite_arg(&av[i][strlen(choix) + 2], choix, data)))
            return (1);
        if (data->opt & 16)
            return (0);
    }
    return (0);
}
