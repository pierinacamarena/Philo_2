/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int  check_helper(t_param *param, int *i)
{
    int ret;

    ret = 0;
    if (param->num_eat && (param->philo[*i].full == 2))
    {
        // pthread_mutex_lock(&(param->meal_check));
	    param->all_ate++;
        // pthread_mutex_unlock(&(param->meal_check));
        // pthread_mutex_lock(&(param->meal_check));
	    param->philo[*i].full = 1;
        // pthread_mutex_unlock(&(param->meal_check));
    }
    // pthread_mutex_lock(&param->meal_check);
	// if (current_time() - param->philo[*i].l_meal > param->t_die)
    // {
	// 	param->died = 1;
    //     printf("%lld %d died\n", current_time() - param->philo[*i].time_init,
	// 	param->philo[*i].id);
    //     ret = 1;
    // }
    // pthread_mutex_unlock(&param->meal_check);
    return (ret);
}

void    check_dead_full(t_param *param)
{
    int i;
    while (1)
    {
        ft_usleep(20, NULL);
        i = -1;
        while (++i < param->num_philo)
        {
            if (check_helper(param, &i))
                return;
            if (param->all_ate == param->num_philo)
            {
                printf("%lld all philo are full\n", current_time() - param->philo->time_init);
                return;
            }
		}
    }
}