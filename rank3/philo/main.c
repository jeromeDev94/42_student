/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:35:24 by jeportie          #+#    #+#             */
/*   Updated: 2024/08/28 13:59:07 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

/*
 * TODO
 * Implementer monitor pour voir quand philo meurt
 * Regler pb de freeze qui arrive avant que la simu commemce
 * Trouver moyen de laisser lock printf apres que someonedied (peut etre en coupant la simu puis en printant)
 */ 

int	main(int ac, char **av)
{
	t_simu		simu;

	if (!ft_init_simu(&simu))
		return (1);
	printf(GREEN "[0ms]\t Simulation Starts.\n" RESET);
	if (!ft_init_params(&simu, ac, av) || !ft_init_forks(&simu)
		|| !ft_init_philos(&simu) || !ft_init_threads(&simu))
	{
		ft_free_philos(&simu);
		return (1);
	}

	while (mtx_get_int(simu.mtdata.init_mutex, simu.mtdata.init_philos) != simu.rdonly.num_philo)
		usleep(10);
	simu.rdonly.start_time = ft_get_time_ms();
	mtx_set_bool(simu.mtdata.start_mutex, &simu.mtdata.start, true);

	while (mtx_get_int(simu.mtdata.end_mutex, simu.mtdata.end) != simu.rdonly.num_philo)
		usleep(10);

	pthread_mutex_lock(&simu.mtdata.print_mutex);
	printf(GREEN "[%lldms]\t Simulation Ended.\n\n" RESET,
		ft_get_time_ms() - simu.rdonly.start_time);
	pthread_mutex_unlock(&simu.mtdata.print_mutex);
	ft_free_philos(&simu);
	return (0);
}
