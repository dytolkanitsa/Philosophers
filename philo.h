#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int					nbr_p;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					nbr_time_eat;
	long				start_progr;
}	t_data;

typedef struct s_one_p
{
	pthread_mutex_t		*left_f;
	pthread_mutex_t		*right_f;
	int					one_philo_dead;
	long				lst_time_eat;
	int					count_eat;
	int					index;
	int					stop_progr;
	t_philo				*main;
	t_data				data;
	pthread_t			thread;
}	t_one_p;

typedef struct s_philo
{
	int					philo_fed;
	t_one_p				*one_p;
	t_data				data;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	pthread_t			waiter;
}	t_philo;

void		philosophers_treads(t_philo *philo);
void		parser(t_philo *philo, char **argv, int	argc);

long		get_time(long start);
long		time_comp(long start, long end);
int			check_argv(int	argc, char **argv);
int			ft_isdigit(char c);
int			ft_atoi(char *str);
void		print(long time, char *str, t_one_p *philo, char *colour);
void		my_usleep(int in);
void		free_everything(t_philo *philo);
#endif