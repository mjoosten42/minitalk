/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:44:39 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/24 12:43:42 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

char	*g_str;

void	ft_setsigaction(void);
void	ft_sendbit(pid_t client);
void	ft_signal(int signum, siginfo_t *info, void *ucontext);
int		ft_atoi(char *str);

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (1);
	g_str = argv[2];
	ft_setsigaction();
	ft_sendbit(ft_atoi(argv[1]));
	while (1)
		;
}

void	ft_sendbit(pid_t client)
{
	static char			c;
	static int			i;

	if (i == 8)
	{
		g_str++;
		i = 0;
		if (!*g_str)
			exit(EXIT_SUCCESS);
	}
	c = *g_str;
	*g_str = *g_str << 1;
	i++;
	if (c < 0)
		kill(client, SIGUSR2);
	else
		kill(client, SIGUSR1);
}

void	ft_signal(int signum, siginfo_t *info, void *ucontext)
{
	ft_setsigaction();
	ft_sendbit(info->si_pid);
	(void)signum;
	(void)ucontext;
}

int	ft_atoi(char *str)
{
	long	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
		result = 10 * result + *str++ - '0';
	if (*str)
		exit(EXIT_FAILURE);
	return (result);
}

void	ft_setsigaction(void)
{
	struct sigaction	usr;

	usr.sa_sigaction = ft_signal;
	usr.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &usr, 0);
}
