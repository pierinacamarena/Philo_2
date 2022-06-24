/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 23:02:53 by pcamaren          #+#    #+#             */
/*   Updated: 2019/11/18 23:14:55 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int		ft_atoi(const char *str)
{
	int nb;
	int sign;

	nb = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		nb = (nb * 10) + ((*str++) - '0');
	return (nb * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			write(fd, s++, 1);
	}
}

void	locked_print(t_philo *philo, int action)
{
	pthread_mutex_lock(&(philo->params->meal_check));
	pthread_mutex_lock(&(philo->params->printer));
	if (philo->params->died != 1)
	{
	if (action == 1)
	    printf("%lld %d has taken a fork\n", current_time() - philo->time_init, philo->id);
	else if (action == 2)
	    printf("%lld %d is eating\n", current_time() - philo->time_init, philo->id);
	else if (action == 3)
	    printf("%lld %d is sleeping\n", current_time() - philo->time_init, philo->id);
	else if (action == 4)
	    printf("%lld %d is thinking\n", current_time() - philo->time_init, philo->id);
	}
	pthread_mutex_unlock(&(philo->params->printer));
	pthread_mutex_unlock(&(philo->params->meal_check));
}