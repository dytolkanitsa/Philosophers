#include "philo.h"

void	fork_eat(t_one_p *philo)
{
	pthread_mutex_lock(philo->left_f);
	print(get_time(philo->data.start_progr), "has taken a (left) fork", \
													 philo, "\x1b[33m");
	pthread_mutex_lock(philo->right_f);
	print(get_time(philo->data.start_progr), "has taken a (right) fork", \
													 philo, "\x1b[33m");
	print(get_time(philo->data.start_progr), "is eating", philo, "\x1b[35m");
	philo->lst_time_eat = get_time(philo->data.start_progr);
	my_usleep(philo->data.time_to_eat);
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
}

void	*philo_life(t_one_p *philo)
{
	while (1)
	{
		fork_eat(philo);
		philo->count_eat++;
		if (philo->data.nbr_time_eat != 0 && \
						philo->count_eat == philo->data.nbr_time_eat)
			return (NULL);
		print(get_time(philo->data.start_progr), \
									"is sleeping", philo, "\x1b[36m");
		my_usleep(philo->data.time_to_sleep);
		print(get_time(philo->data.start_progr), "is thinking", \
													 philo, "\x1b[37m");
	}
	return (NULL);
}

void	for_check_death(t_philo *philo, int i)
{
	if (philo->data.nbr_time_eat != 0 && \
		philo->one_p[i].count_eat >= philo->data.nbr_time_eat)
	{
		philo->philo_fed++;
		philo->one_p[i].stop_progr = 1;
	}
}

void	*check_death(t_philo *philo)
{
	int	i;

	while (1)
	{
		philo->philo_fed = 0;
		i = 0;
		while (i < philo->data.nbr_p)
		{
			for_check_death(philo, i);
			if ((time_comp(get_time(philo->data.start_progr), \
					philo->one_p[i].lst_time_eat)) > philo->data.time_to_die \
									&& philo->one_p[i].stop_progr != 1)
			{
				print(get_time(philo->data.start_progr), \
							 "died", &philo->one_p[i], "\x1b[36m");
				return (NULL);
			}
			i++;
		}
		if (philo->philo_fed == philo->data.nbr_p)
			return (NULL);
	}
	return (NULL);
}

void	philosophers_treads(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_create(&philo->waiter, NULL, (void *)&check_death, philo);
	while (i < philo->data.nbr_p)
	{
		pthread_create(&philo->one_p->thread, NULL, (void *)&philo_life, \
															 philo->one_p + i);
		usleep(100);
		i++;
	}
	pthread_join(philo->waiter, NULL);
	free_everything(philo);
}
