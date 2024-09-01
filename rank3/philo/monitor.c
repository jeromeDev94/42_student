/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:00:00 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/01 19:55:31 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * TODO
 * PROBLEME : LA SIMU S'ARRETE PAS APRES END = num_philos 
 */

#include "include/philo.h"

bool	ft_check_if_dead(t_philo *philo)
{
	long long	time;

	if (mtx_get_bool(philo->mtdata->death_mutex, philo->mtdata->stop))
		return (true);
	time = ft_get_time_ms() - mtx_get_longlong(philo->mtdata->init_mutex, philo->last_meal_time);
	if (time >= philo->rdonly->time_to_die)
	{
		mtx_set_bool(philo->mtdata->death_mutex, &philo->mtdata->stop, true);
		ft_print_state(philo, DEAD);
		return (true);
	}
	return (false);
}

void	*ft_monitor_routine(void *arg)
{
	t_monitor	*mon;
	int			i;

	mon = (t_monitor *)arg;
	if (!mon)
		return (NULL);
	mtx_increment_int(&mon->mtdata->init_mutex, &mon->mtdata->init_philos);

	ft_wait_for_start(&mon->mtdata->start_mutex, &mon->mtdata->start);

	while (!mtx_get_bool(mon->mtdata->death_mutex, mon->mtdata->stop))
	{
		i = 0;

		while (i < mon->rdonly->num_philo)
		{
			if (ft_check_if_dead(&mon->simu->philos[i]))
				break;
			i++;
		}
		if (mtx_get_int(mon->mtdata->end_mutex, mon->mtdata->end_philos) == mon->rdonly->num_philo)
		{
			mtx_set_bool(mon->mtdata->death_mutex, &mon->mtdata->stop, true);
//			printf("break ok\n");
			break;
		}
		ft_precise_usleep(100, mon->simu);
	}

	// Stop all threads after a death has been detected
	ft_stop_threads(mon->simu);
//	printf("monitor stop threads ok\n");
	return (NULL);
}

