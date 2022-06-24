/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static  t_fork  *create_fork(int n)
{
    t_fork *tmp;
    int     i;

    i = 0;
    tmp = malloc(sizeof(t_fork) * n);
    if (!tmp)
        return (NULL);
    while (i < n)
    {
        pthread_mutex_init(&tmp[i].fork, NULL);
        tmp[i].id_dirty = -35;
        i++;
    }
    return (tmp);       
}

static int init_mutexes(t_param *param)
{
    if (pthread_mutex_init(&(param->printer), NULL))
		return (1);
    if (pthread_mutex_init(&(param->meal_check), NULL))
        return (1);
    if (pthread_mutex_init(&(param->meal_update), NULL))
        return (1);
    if (pthread_mutex_init(&(param->meal_count), NULL))
        return (1);
    if (pthread_mutex_init(&(param->id_check), NULL))
        return (1);
    if (pthread_mutex_init(&(param->dead_check), NULL))
        return (1);
    if (pthread_mutex_init(&(param->sleep_check), NULL))
        return (1);
    return (0);
}

int arg_parsing(t_param *param, char **av, int ac)
{
    param->forks = create_fork(param->num_philo);
    if (!param->forks)
        return (1);
    param->num_philo = ft_atoi(av[1]);
    if (param->num_philo < 1)
        return (1);
    param->t_die = ft_atoi(av[2]);
    if (param->t_die < 0 || param->t_die > 1000000)
        return (1);
    param->t_sleep = ft_atoi(av[3]);
    if (param->t_sleep < 0 || param->t_sleep > 1000000)
        return (1);
    param->all_ate = 0;
    param->died = 0;
    if (ac == 6)
    {
        param->num_eat = ft_atoi(av[5]);
        if (param->num_eat < 1)
            return (1);
    }
    else if (ac == 5)
        param->num_eat = 0;
    if (init_mutexes(param))
        return (1);
    return (0);
}