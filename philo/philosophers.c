/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:44:21 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/04 16:11:27 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->next_meal < ft_get_time())
		{
			philo->data->is_dead = 1;
			pthread_mutex_lock(philo->eat);
			ft_print_message(5, philo);
			pthread_mutex_unlock(philo->data->stop);
			break ;
		}
	}
	return (NULL);
}

int	ft_check_eat(t_philo *philo)
{
	if ((philo->data->eat_counter != -1)
		&& (philo->data->current_eat >= philo->data->max_eat))
	{
		philo->data->is_dead = 1;
		pthread_mutex_lock(philo->eat);
		pthread_mutex_unlock(philo->data->stop);
		return (0);
	}
	return (1);
}

void	*ft_routine(void *arg)
{
	t_philo		*philo;
	pthread_t	death;

	philo = arg;
	philo->next_meal = ft_get_time() + (unsigned int)philo->data->time_to_die;
	pthread_create(&death, NULL, ft_check_death, philo);
	pthread_detach(death);
	while (1)
	{
		if (philo->data->is_dead)
			break ;
		ft_take_fork(philo);
		ft_eat(philo);
		if (!ft_check_eat(philo))
			break ;
		ft_sleep(philo);
		ft_print_message(4, philo);
	}
	return (NULL);
}

int	ft_error_put(t_args *args, char *message, int ret)
{
	(void)(args);
	printf("%s\n", message);
	return (ret);
}

int	main(int ac, char **av)
{
	int			i;
	t_args		args;
	t_philo		*philo;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		if (ft_parsing(av, &args))
			return (1);
		philo = ft_philo_init(&args);
		args.start = ft_get_time();
		ft_create_mutex(&args);
		pthread_mutex_lock(args.stop);
		while (i < args.philo_numbers)
		{
			pthread_create(args.threads + i, NULL, ft_routine, philo + i);
			pthread_detach(args.threads[i++]);
			usleep(100);
		}
		pthread_mutex_lock(args.stop);
		ft_destroy_all(&args, philo);
	}
	else
		write(2, "Error: Too many arguments\n", 26);
	return (0);
}
