/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:44:33 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/04 16:07:17 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_args
{
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*message;
	pthread_mutex_t		*death;
	pthread_mutex_t		*stop;
	unsigned int		start;
	int					philo_numbers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					eat_counter;
	int					max_eat;
	int					is_dead;
	int					current_eat;
}				t_args;

typedef struct s_philo
{
	pthread_mutex_t	*eat;
	t_args			*data;
	unsigned int	eating_time;
	unsigned int	next_meal;
	int				index;
	int				right_hand;
	int				left_hand;
	int				is_dead;
	int				eat_counter;
}				t_philo;

unsigned int	ft_get_time(void);
void			*ft_routine(void *arg);
void			ft_eat(t_philo *philo);
void			ft_sleep(t_philo *philo);
void			*ft_check_death(void *arg);
void			ft_take_fork(t_philo *philo);
void			ft_print_message(int id, t_philo *philo);
t_philo			*ft_philo_init(t_args *args);
void			ft_create_mutex(t_args *args);
int				ft_parsing(char **av, t_args *args);
void			ft_destroy_all(t_args *args, t_philo *philo);
void			ft_for_each_philo(t_args *args, t_philo *philo,
					int i);
int				ft_error_put(t_args *args, char *message, int ret);

#endif
