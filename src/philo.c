/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void *func(void *philo_void)
{
	t_philo *philo;
	t_param	*param;

	philo = (t_philo *)philo_void;
	param = philo->params;
	if (philo->id % 2)
		usleep(15000);
	// while (param->died != 1)
	// {

	// }
	while (param->died != 1 || philo->full != 1)
	{
		if (philo->full > 0 || eat(philo) == 1)
			break;
		if (philo->meal_count == philo->total_eat)
			philo->full = 2;
		if (param->died || philo->full > 0 || philo_sleep(philo) == 1)
			break;
		if (param->died != 1)
    		locked_print(philo, 4);
	}
	return (NULL);
}

void    philos_setup(t_param *param)
{
    int i;

    i = 0;
    param->philo = malloc(sizeof(t_philo) * param->num_philo);
	if (!param->philo)
		return;
    while (i < param->num_philo)
    {
        param->philo[i].id = i + 1;
        param->philo[i].time_init = current_time();
        param->philo[i].l_meal = current_time();
        param->philo[i].full = 0;
        param->philo[i].meal_count = 0;
        param->philo[i].total_eat = param->num_eat;
        param->philo[i].left_f = &param->forks[i];
        if (i < param->num_philo - 1)
            param->philo[i].right_f = &param->forks[i + 1];
        else
            param->philo[i].right_f = &param->forks[0];
        param->philo[i].params = param;
        i++;
    }
}

void	philo_thread(t_param *param, pthread_t *philos)
{
	int	i;

	i = 0;
	while (i < param->num_philo)
	{
		pthread_create(&philos[i], NULL, func, &(param->philo[i]));
		i = i + 2;
	}
	i = 1;	
	while (i < param->num_philo)
	{
		pthread_create(&philos[i], NULL, func, &(param->philo[i]));
		i = i + 2;
	}
}

int	init_philo(t_param *param)
{
	int i;
	pthread_t	*philos;

	philos = malloc(sizeof(pthread_t) * param->num_philo);
	if (!philos)
		return (-1);
	philos_setup(param);
	philo_thread(param, philos);
    check_dead_full(param);
	i = 0;
    while (i < param->num_philo)
    {
        pthread_join(philos[i], NULL);
		i++;
    }
	return (0);
}
