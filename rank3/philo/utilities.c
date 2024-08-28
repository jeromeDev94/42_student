/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:28:50 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/28 11:44:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_perror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

long long	ft_get_time_ms(void)
{
	t_timeval	tv;
	long long	time;
	int			succes;

	succes = gettimeofday(&tv, NULL);
	if (succes == -1)
	{
		ft_perror("Error, time not found.\n");
		return (-1);
	}
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

static long long ft_get_elapsed_time_us(t_timeval start, t_timeval end)
{
	return (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
}

void	ft_precise_usleep(long long usec, t_philo *philo)
{
	t_timeval	start;
	t_timeval	current;
	long long	elapsed;
	long long	rem;

	gettimeofday(&start, NULL);
	elapsed = 0;

	while (elapsed < usec)
	{
		if (mtx_get_bool(philo->mtdata->death_mutex, philo->mtdata->someone_died) == true)
			break;
		if (mtx_get_int(philo->mtdata->end_mutex, philo->mtdata->end) == philo->rdonly->num_philo)
			break;
		gettimeofday(&current, NULL);
		elapsed = ft_get_elapsed_time_us(start, current);
		rem = usec - elapsed;
		if (rem > 1000)
			usleep(rem / 2);
		else if (rem > 0)
			usleep(rem);
	}
}

void	ft_free_philos(t_simu *simu)
{
	int	i;

	if (simu->philos)
	{
		i = 0;
		while (i < simu->rdonly.num_philo)
		{
			if (simu->philos[i].thread)
				pthread_join(simu->philos[i].thread, NULL);
			i++;
		}
	}
	if (simu->forks)
	{
		i = 0;
		while (i < simu->rdonly.num_philo)
		{
			pthread_mutex_destroy(&simu->forks[i]);
			i++;
		}
	}
	if (simu->philos)
		free(simu->philos);
	if (simu->forks)
		free(simu->forks);
	pthread_mutex_destroy(&simu->mtdata.print_mutex);
	pthread_mutex_destroy(&simu->mtdata.death_mutex);
	pthread_mutex_destroy(&simu->mtdata.meal_mutex);
	pthread_mutex_destroy(&simu->mtdata.init_mutex);
	pthread_mutex_destroy(&simu->mtdata.end_mutex);
	pthread_mutex_destroy(&simu->mtdata.start_mutex);
}
