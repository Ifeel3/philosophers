#include "../philo.h"

static int	checkargs(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	convert(const char *string)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (string[i])
	{
		result = result * 10 + (string[i] - 48);
		i++;
	}
	return (result);
}

static void	parseargs(char **argv, t_data *data)
{
	data->philos = convert(argv[1]);
	data->timedie = convert(argv[2]);
	data->timeeat = convert(argv[3]);
	data->timesleep = convert(argv[4]);
	if (argv[5])
		data->musteat = convert(argv[5]);
	else
		data->musteat = 0;
}

void	parser(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		error(1);
	if (checkargs(argv))
		error(2);
	parseargs(argv, data);
}
