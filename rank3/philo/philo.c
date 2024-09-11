/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:36:57 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/11 10:36:57 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	ft_simulation_loop(t_philo *philo)
{
	bool	dead_flag;

	while (1)
	{
		pthread_mutex_lock(&philo->mtdata->stop_mutex);
		dead_flag = philo->mtdata->stop_flag;
		pthread_mutex_unlock(&philo->mtdata->stop_mutex);
		if (dead_flag == true)
			break ;
		ft_print_state(philo, THINK);
		ft_eat(philo);
		if (philo->meals_eaten == philo->rdonly->num_meals)
			break ;
		ft_sleep(philo);
	}
}

bool	ft_pick_up_forks(t_philo *philo)
{
	bool	dead_flag;

	pthread_mutex_lock(&philo->mtdata->stop_mutex);
	dead_flag = philo->mtdata->stop_flag;
	pthread_mutex_unlock(&philo->mtdata->stop_mutex);
	if (dead_flag)
		return (false);
	if (philo->id % 2 == 0)
		ft_fork_pick(philo, EVEN);
	else
		ft_fork_pick(philo, ODD);
	return (true);
}

void	ft_eat(t_philo *philo)
{
	t_mtx	*meal_mtx;

	meal_mtx = &philo->mtdata->meal_mutex;
	ft_pick_up_forks(philo);
	ft_update_meal_time(philo);
	ft_print_state(philo, EAT);
	philo->meals_eaten++;
	ft_precise_usleep(philo->rdonly->time_to_eat * 1000);
	if (philo->meals_eaten == philo->rdonly->num_meals)
	{
		pthread_mutex_lock(&philo->finish_mutex);
		philo->finish_flag = true;
		pthread_mutex_unlock(&philo->finish_mutex);
		mtx_increment_int(meal_mtx, &philo->mtdata->philos_full);
	}
	ft_release_forks(philo);
}

void	ft_release_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_release(philo, EVEN);
	else
		ft_release(philo, ODD);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_state(philo, SLEEP);
	ft_precise_usleep(philo->rdonly->time_to_sleep * 1000);
}