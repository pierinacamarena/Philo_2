/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 18:14:57 by pcamaren          #+#    #+#             */
/*   Updated: 2021/09/09 18:15:00 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct  s_fork
{
    pthread_mutex_t	fork;
    int             id_dirty;
}               t_fork;

typedef struct  s_philo
{
    int             id;
    long long       time_init;
    long long       l_meal;
    int             total_eat;
    int             full;
    int             meal_count;
    t_fork          *left_f;
    t_fork          *right_f;
    struct s_param  *params;
}               t_philo;

typedef struct     s_param
{
    int     num_philo;
    int     t_die;
    int     t_eat;
    int     t_sleep;
    int     num_eat;
    int     all_ate;
    int     died;
    t_fork  *forks;
    t_philo *philo;
    pthread_mutex_t	printer;
    pthread_mutex_t meal_check;
    pthread_mutex_t meal_update;
    pthread_mutex_t meal_count;
    pthread_mutex_t id_check;
    pthread_mutex_t dead_check;
    pthread_mutex_t sleep_check;
}               t_param;

/*error*/
void 	error_parsing(void);
void	error_arg(void);

/*parsing*/
int arg_parsing(t_param *param, char **av, int ac);

/*utils*/
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	locked_print(t_philo *philo, int action);

/*philo*/
int	init_philo(t_param *param);
void    philos_setup(t_param *param);

/*time*/
long long	current_time(void);
long long   time_differ(long long past, long long current);
void    my_sleep(t_philo *philo, int time_sleep);
void		ft_usleep(unsigned int n, t_philo *th);

/*activites*/
int    eat(t_philo *philo);
int    philo_sleep(t_philo *philo);

/*checker*/
void    check_dead_full(t_param *param);
#endif