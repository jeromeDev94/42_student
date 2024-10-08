/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:23:49 by jeportie          #+#    #+#             */
/*   Updated: 2024/09/03 14:11:43 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h> 
# include <string.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>

# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define RESET   "\033[0m"

# define DEAD 0
# define THINK 1
# define LEFT 2
# define RIGHT 3
# define EAT 4
# define SLEEP 5
# define STOP 6

typedef struct timeval	t_timeval;
typedef struct s_simu	t_simu;
typedef struct s_rdonly	t_rdonly;
typedef struct s_shared	t_shared;
typedef pthread_mutex_t	t_mtx;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	long long		last_meal_time;
	int				meals_eaten;
	t_mtx			*right_fork;
	t_mtx			*left_fork;
	t_rdonly		*rdonly;
	t_shared		*mtdata;
	t_simu			*simu;
}					t_philo;

typedef struct s_monitor
{
	pthread_t		thread;
	t_rdonly		*rdonly;
	t_shared		*mtdata;
	t_simu			*simu;
}					t_monitor;

typedef struct s_rdonly
{
	int			num_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			num_meals;
	long long	start_time;
}				t_rdonly;

typedef struct s_shared
{
	t_mtx		print_mutex;
	int			philos_full;
	t_mtx		meal_mutex;

//	int			init_philos;
//	t_mtx		init_mutex;
//	bool		start;
//	t_mtx		start_mutex;
	
//	bool		stop;
//	t_mtx		death_mutex;
//	int			end_philos;
//	t_mtx		end_mutex;

	bool		action_flag;
	int			wait_flag;
	t_mtx		action_mutex;
	t_mtx		wait_mutex;
}				t_shared;

typedef struct s_simu
{
	t_philo		*philos;
	t_mtx		*forks;
	t_rdonly	rdonly;
	t_shared	mtdata;
	t_monitor	monitor;
}				t_simu;

/*Parsing*/
bool		ft_is_int(char *nptr);
bool		ft_check_args(int ac, char **av);

/*Init*/
bool		ft_init_mtdata(t_simu *simu);
bool		ft_init_rdonly(t_simu *simu, int ac, char **av);
bool		ft_init_philos(t_simu *simu);
bool		ft_init_monitor(t_simu *simu);
bool		ft_init_forks(t_simu *simu);
bool		ft_init_threads(t_simu *simu);

/*Philosopher Threads*/
void		*ft_routine(void *arg);
void		ft_think(t_philo *philo);
void		ft_pick_up_forks(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_sleep(t_philo *philo);
void		ft_release_forks(t_philo *philo);

/*Monitoring thread*/
bool		ft_check_if_dead(t_philo *philo);
void		*ft_monitor(void *arg);
void		ft_wait_for_start(t_mtx *mutex, bool *start);

/*Simulation*/
void		ft_stop_threads(t_simu *simu);
void		ft_start_simulation(t_simu *simu);

/*Getters/Setters*/
bool		mtx_get_bool(t_mtx mutex, bool value);
void		mtx_set_bool(t_mtx mutex, bool *dest, bool value);
int			mtx_get_int(t_mtx mutex, int value);
void		mtx_set_int(t_mtx mutex, int *dest, int value);
void		mtx_increment_int(t_mtx *mutex, int *dest);
long long	mtx_get_llong(t_mtx mutex, long long value);
void		mtx_set_llong(t_mtx mutex, long long *dest, long long value);

/*Utilities*/
void		ft_perror(char *str);
long long	ft_get_time_ms(void);
void		ft_precise_usleep(long long usec);
void		ft_free_philos(t_simu *simu);

/*42_ft*/
int			ft_isspace(int c);
int			ft_isdigit(int c);
int			ft_issign(int c, int *sign);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *nptr);

/*Printing*/
void		ft_print_state(t_philo *philo, int state);
void		ft_print_intro(void);
void		ft_print_params(t_rdonly params);
void		ft_print_philos(t_simu simu);
void		ft_print_parsing(t_simu simu);
void		ft_print_start_stop(t_simu *simu, bool choice);

#endif /*PHILO_H*/
