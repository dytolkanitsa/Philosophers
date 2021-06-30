#include "philo.h"

void	my_usleep(int time)
{
	time_t	start;
	time_t	end;

	start = get_time(0);
	end = get_time(0) + time;
	while (start < end)
	{
		usleep(10);
		start = get_time(0);
	}
}

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	check_argv(int	argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of parametrs\n");
		return (0);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	if_if(char *str)
{
	int	i;

	i = 0;
	return (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r');
}

int	ft_atoi(char *str)
{
	int	sign;
	int	nbr;
	int	num;

	sign = 1;
	nbr = 0;
	num = 19;
	while (if_if(str))
		str++;
	if (*str == '-')
		sign = -sign;
	else if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (!num--)
			return ((1 + sign) / (-2));
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}
