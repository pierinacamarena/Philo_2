/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:38 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:55:17 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	error_arg(void)
{
	ft_putstr_fd("Wrong number of Arguments\n./philosophers ", 1);
	ft_putstr_fd("[number_of_philosophers] [time_to_die] [time_to_eat] ", 1);
	ft_putstr_fd("[time_to_sleep] \
    [number_of_times_each_philosophers_must_eat]\n", 1);
}


void 	error_parsing(void)
{
	ft_putstr_fd("Wrong value of arguments\n./philosophers ", 1);
	ft_putstr_fd("[number_of_philosophers > 1] [time_to_die > 1]\
	 [time_to_eat > 1] ", 1);
	ft_putstr_fd("[time_to_sleep] > 1\
    [number_of_times_each_philosophers_must_eat] > 1\n", 1);
}
