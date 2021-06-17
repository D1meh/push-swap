#include "../push_swap.h"

static void	atoi_check(char *nb)
{
	int	i;

	i = 0;
	while (nb[i])
	{
		if ((nb[i] > '9' || nb[i] < '0') && (nb[i] != '-'
				|| i != 0 || nb[i + 1] == '\0'))
			if (nb[i] != ' ' && (nb[i] == '-' && !ft_isdigit(nb[i + 1])))
				error_return();
		i++;
	}
}

void	error_return(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_args(int ac, char **av)
{
	int	i;

	if (ac == 1)
		exit(0);
	i = 1;
	while (av[i])
	{
		atoi_check(av[i]);
		i++;
	}
}

void	check_int(long int *tab, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		if (tab[i] > 2147483647 || tab[i] < -2147483648)
		{
			free(tab);
			error_return();
		}
		j = i + 1;
		while (j < ac - 1)
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				error_return();
			}
			j++;
		}
		i++;
	}
}
