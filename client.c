/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:44:39 by mjoosten          #+#    #+#             */
/*   Updated: 2022/02/08 17:12:46 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_sendbit(pid_t client, char *str);
void	ft_signal(int signum, siginfo_t *info, void *ucontext);
int		ft_atoi(char *str);

int	main(int argc, char *argv[])
{
	struct sigaction	usr;

	if (argc != 3 || !*argv[2])
		return (1);
	usr.sa_sigaction = ft_signal;
	usr.sa_flags = SA_SIGINFO | SA_NODEFER;
	sigaction(SIGUSR1, &usr, 0);
	ft_sendbit(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
}

void	ft_sendbit(pid_t client, char *arg)
{
	static char	*str;
	static int	i;
	char		c;

	if (!str)
		str = arg;
	if (i == 8)
	{
		str++;
		i = 0;
		if (!*str)
			exit(EXIT_SUCCESS);
	}
	c = *str;
	*str = *str << 1;
	i++;
	if (c < 0)
		kill(client, SIGUSR2);
	else
		kill(client, SIGUSR1);
}

void	ft_signal(int signum, siginfo_t *info, void *ucontext)
{
	ft_sendbit(info->si_pid, 0);
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
