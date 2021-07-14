#include "philo.h"

static void	error(void)
{
	printf("Error: not valid argument...\n");
	exit(0);
}

static void	checknum(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= 48 && argv[i][j] <= 57))
				error();
			j++;
		}
		i++;
	}
}

static void	checkargs(int argc, char **argv)
{
	if (argc < 5)
	{
		printf("Error: too few arguments...\n");
		exit(0);
	}
	if (argc > 6)
	{
		printf("Error: too many arguments...\n");
		exit(0);
	}
	checknum(argv);
}

static int	*parseargs(int argc, char **argv)
{
	int	i;
	int	*args;

	args = (int *)malloc(sizeof(int) * 5);
	i = 1;
	if (argc == 5)
	{
		while (i < 5)
		{
			args[i - 1] = (int)strtol(argv[i], NULL, 10);
			i++;
		}
		args[i - 1] = 0;
	}
	else if (argc == 6)
	{
		while (i < 6)
		{
			args[i - 1] = (int)strtol(argv[i], NULL, 10);
			i++;
		}
	}
	return (args);
}

int	*parser(int argc, char **argv)
{
	checkargs(argc, argv);
	return (parseargs(argc, argv));
}
