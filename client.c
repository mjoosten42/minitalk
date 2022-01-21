/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:44:39 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/21 14:55:49 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_signal(int signum);
int		ft_atoi(char *str);
int		ft_isdigit(int c);

int	main(int argc, char *argv[])
{
	char	c;
	int		i;

	if (argc != 3)
		return (1);
	signal(SIGUSR1, ft_signal);
	while (1)
	{
		i = 0;
		c = *argv[2];
		while (i < 8)
		{
			if (c < 0)
				kill(ft_atoi(argv[1]), SIGUSR2);
			else
				kill(ft_atoi(argv[1]), SIGUSR1);
			c = c << 1;
			i++;
			usleep(42);
		}
		if (*argv[2] == 0)
			while (1)
				;
		argv[2]++;
	}
}

void	ft_signal(int signum)
{
	(void)signum;
	exit(EXIT_SUCCESS);
}

int	ft_atoi(char *str)
{
	long	result;

	result = 0;
	while (ft_isdigit(*str))
		result = 10 * result + *str++ - '0';
	return (result);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
