#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = (struct s_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	pthread_mutex_init(&philo->print, NULL);
	if (check_argv(argc, argv))
	{
		philo->data.start_progr = get_time(0);
		parser(philo, argv, argc);
		philosophers_treads(philo);
	}
	return (0);
}
