/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:02:32 by pcamaren          #+#    #+#             */
/*   Updated: 2022/06/14 17:02:38 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long	current_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000LL) + (t.tv_usec / 1000));
}

long long   time_differ(long long past, long long current)
{
    return (current - past);
}
void    my_sleep(t_philo *philo, int time_sleep)
{
    long long   start;
    int         philo_exist;

    philo_exist = 0;
    if (philo)
        philo_exist = 1;
    start = current_time();
    while (1)
    {
        if (philo->params->died && philo_exist)
            break ;
        if (time_differ(start, current_time()) >= time_sleep)
            break;
        usleep(50);
    }
}

void		ft_usleep(unsigned int n, t_philo *th)
{
	struct timeval	start;
	struct timeval	step;
	int				no_null;

	no_null = 0;
	if (th)
		no_null = 1;
	gettimeofday(&start, NULL);
	while (1)
	{
		if (no_null && th->params->died)
			break ;
		usleep(100);
		gettimeofday(&step, NULL);
		if ((size_t)(((size_t)(step.tv_sec - start.tv_sec)) * 1000000 +
					((size_t)(step.tv_usec - start.tv_usec))) > n)
			break ;
	}
}