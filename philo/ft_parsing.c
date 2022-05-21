/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:43:58 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/04 16:07:07 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_check_last(t_args *args, int num, int i)
{
	if (i == 5)
	{
		if (num == 0)
		{
			args->eat_counter = -1;
			args->current_eat = -1;
			args->max_eat = -1;
		}
		else
		{
			args->eat_counter = num;
			args->current_eat = 0;
			args->max_eat = num * args->philo_numbers;
		}
	}
	return (0);
}

static int	ft_set_rest(t_args *args, int num, int i)
{
	if (i == 3)
		args->time_to_eat = num;
	else if (i == 4)
		args->time_to_sleep = num;
	else
		ft_check_last(args, num, i);
	return (0);
}

static int	ft_get_args(t_args *args, int num, int i)
{
	if (i == 1)
	{
		if (num == 0)
			return (ft_error_put(NULL,
					"Error! No philosophers!", 1));
		args->philo_numbers = num;
		args->threads = malloc(sizeof(pthread_t) * num);
		args->forks = malloc(sizeof(pthread_mutex_t) * num);
	}
	else if (i == 2)
	{
		args->time_to_die = num;
	}
	else
		ft_set_rest(args, num, i);
	return (0);
}

static int	ft_atoi(char *arg)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			num = num * 10 + (arg[i] - '0');
		else
			return (ft_error_put(NULL, "Error: Number Only", -1));
		i++;
	}
	return (num);
}

int	ft_parsing(char **av, t_args *args)
{
	int				num;
	int				i;

	i = 1;
	while (av[i])
	{
		num = ft_atoi(av[i]);
		if (num == -1)
			return (1);
		if (ft_get_args(args, num, i))
			return (1);
		i++;
	}
	if (i == 5)
	{
		args->eat_counter = -1;
		args->current_eat = -1;
		args->max_eat = -1;
	}
	args->is_dead = 0;
	return (0);
}
