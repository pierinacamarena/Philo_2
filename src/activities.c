/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// void    eat(t_philo *philo)
// {
//     t_param *param;

//     param = philo->params;
//     if (philo->id % 2 == 0)
//         pthread_mutex_lock(&(philo->left_f));
//     else
//         pthread_mutex_lock(&(philo->right_f));
//     if (philo->id % 2 == 0)
//         pthread_mutex_lock(&(philo->right_f));
//     else
//         pthread_mutex_lock(&(philo->left_f));
//     if (!param->died)
//     {
//         locked_print(philo, 1);
//         locked_print(philo, 1);

//     }
// }

static void    greedy_philo_check(int *id_dirty, int id, pthread_mutex_t *fork, t_param *param)
{
    // pthread_mutex_lock(&(param->meal_update));
    if (*id_dirty == id)
        usleep(10);
    // pthread_mutex_unlock(&(param->meal_update));
    pthread_mutex_lock(fork);
    pthread_mutex_lock(&(param->meal_check));
    *id_dirty = id;
    pthread_mutex_unlock(&(param->meal_check));
}

int    eat(t_philo *philo)
{
    if (philo->id % 2 == 0)
        greedy_philo_check(&philo->left_f->id_dirty, philo->id, &(philo->left_f->fork), philo->params);
    else
        greedy_philo_check(&philo->right_f->id_dirty, philo->id, &(philo->right_f->fork), philo->params);
    if (philo->id % 2 == 0)
        greedy_philo_check(&philo->right_f->id_dirty, philo->id, &(philo->right_f->fork), philo->params);
    else if (philo->id % 2 != 0 && philo->params->num_philo > 1)
        greedy_philo_check(&philo->left_f->id_dirty, philo->id, &(philo->left_f->fork), philo->params);
    if (philo->params->died != 1 && philo->params->num_philo > 1)
    {
        locked_print(philo, 1);
        locked_print(philo, 1);
        locked_print(philo, 2);
        pthread_mutex_lock(&(philo->params->meal_count));
        philo->meal_count++;
        pthread_mutex_unlock(&(philo->params->meal_count));
        my_sleep(philo, philo->params->t_eat);
        pthread_mutex_lock(&(philo->params->meal_update));
        philo->l_meal = current_time();
        pthread_mutex_unlock(&(philo->params->meal_update));
    }
    pthread_mutex_unlock(&(philo->left_f->fork));
    pthread_mutex_unlock(&(philo->right_f->fork));
    return (0);
}

int    philo_sleep(t_philo *philo)
{
    if (philo->params->died == 0)
    {
        locked_print(philo, 3);
        my_sleep(philo, philo->params->t_sleep);
    }
    return (0);
}