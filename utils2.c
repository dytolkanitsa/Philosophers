#include "philo.h"

void	print(long time, char *str, t_one_p *philo, char *colour)
{
	pthread_mutex_lock(&philo->main->print);
	printf("%s%ld Philo %d %s\n", colour, time, philo->index, str);
	if (!philo->one_philo_dead)
		pthread_mutex_unlock(&philo->main->print);
}

long	time_comp(long start, long end)
{
	return (start - end);
}

long	get_time(long	start)
{
	struct timeval	tv;
	long			time;

	gettimeofday(&tv, NULL);
	time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	return (time - start);
}

void	free_everything(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data.nbr_p)
	{
		pthread_detach(philo->one_p[i].thread);
		i++;
	}
	i = 0;
	while (i < philo->data.nbr_p)
	{
		pthread_mutex_destroy(&philo->forks[i]);
		i++;
	}
	pthread_detach(philo->waiter);
	pthread_mutex_destroy(&philo->print);
}
