#include "philo.h"

static void	init_data(t_philo *philo, char **argv, char argc)
{
	philo->data.nbr_p = ft_atoi(argv[1]);
	philo->data.time_to_die = ft_atoi(argv[2]);
	philo->data.time_to_eat = ft_atoi(argv[3]);
	philo->data.time_to_sleep = ft_atoi(argv[4]);
	philo->data.nbr_time_eat = 0;
	if (argc == 6)
		philo->data.nbr_time_eat = ft_atoi(argv[5]);
	philo->philo_fed = 0;
}

static void	init_philo(t_philo *philo)
{
	int	i;

	i = 0;
	philo->one_p = (struct s_one_p *)malloc(sizeof(t_one_p) \
											* philo->data.nbr_p);
	if (!philo->one_p)
		return ;
	while (i <= philo->data.nbr_p)
	{
		philo->one_p[i].one_philo_dead = 0;
		philo->one_p[i].lst_time_eat = 0;
		philo->one_p[i].count_eat = 0;
		philo->one_p[i].index = i + 1;
		philo->one_p[i].stop_progr = 0;
		philo->one_p[i].main = philo;
		philo->one_p[i].data = philo->data;
		i++;
	}
}

static void	init_forks(t_philo *philo)
{
	int	i;

	i = 0;
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
													* philo->data.nbr_p);
	if (!philo->forks)
		return ;
	while (i < philo->data.nbr_p)
	{
		pthread_mutex_init(&philo->forks[i], NULL);
		i++;
	}
}

static void	philos_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data.nbr_p)
	{
		if (i != philo->data.nbr_p - 1)
		{
			philo->one_p[i].left_f = &philo->forks[i];
			philo->one_p[i].right_f = &philo->forks[i + 1];
		}
		else
		{
			philo->one_p[i].left_f = &philo->forks[i];
			philo->one_p[i].right_f = &philo->forks[0];
		}
		i++;
	}
}

void	parser(t_philo *philo, char **argv, int	argc)
{
	init_data(philo, argv, argc);
	init_philo(philo);
	init_forks(philo);
	philos_forks(philo);
}
