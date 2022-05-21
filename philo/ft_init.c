/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:44:11 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/04 16:11:54 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_create_mutex(t_args *args)
{
	int	i;

	i = 0;
	pthread_mutex_init(args->message, NULL);
	pthread_mutex_init(args->death, NULL);
	pthread_mutex_init(args->stop, NULL);
	while (i < args->philo_numbers)
		pthread_mutex_init(args->forks + i++, NULL);
}

void	ft_destroy_all(t_args *args, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(args->death);
	pthread_mutex_destroy(args->message);
	pthread_mutex_destroy(args->stop);
	while (i < args->philo_numbers)
	{
		pthread_mutex_destroy(args->forks + i);
		pthread_mutex_destroy(philo[i].eat);
		free(philo[i].eat);
		i++;
	}
	free(philo);
}

t_philo	*ft_philo_init(t_args *args)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(t_philo) * args->philo_numbers);
	args->stop = malloc(sizeof(pthread_mutex_t));
	args->death = malloc(sizeof(pthread_mutex_t));
	args->message = malloc(sizeof(pthread_mutex_t));
	while (++i < args->philo_numbers)
		ft_for_each_philo(args, philo, i);
	return (philo);
}

void	ft_for_each_philo(t_args *args, t_philo *philo, int i)
{
	philo[i].index = i;
	philo[i].left_hand = i;
	philo[i].right_hand = (i + 1) % args->philo_numbers;
	philo[i].is_dead = 0;
	philo[i].data = args;
	philo[i].eat = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo[i].eat, NULL);
	if (args->eat_counter == -1)
		philo[i].eat_counter = -1;
	else
		philo[i].eat_counter = args->eat_counter;
}

void	ft_print_message(int id, t_philo *philo)
{
	unsigned int	time;

	pthread_mutex_lock(philo->data->message);
	time = ft_get_time() - philo->data->start;
	if (id == 1)
		printf("%u\t%d has taken a fork\n", time, philo->index + 1);
	if (id == 2)
		printf("%u\t%d is eating\n", time, philo->index + 1);
	if (id == 3)
		printf("%u\t%d is sleeping\n", time, philo->index + 1);
	if (id == 4)
		printf("%u\t%d is thinking\n", time, philo->index + 1);
	if (id == 5)
		printf("%u\t%d died\n", time, philo->index + 1);
	if (id != 5)
		pthread_mutex_unlock(philo->data->message);
}
