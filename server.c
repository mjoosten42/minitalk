/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:44:19 by mjoosten          #+#    #+#             */
/*   Updated: 2022/02/08 17:12:27 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_addbit(int bit, pid_t client);
void	ft_signal(int signum, siginfo_t *info, void *ucontext);
void	ft_putnbr(int n);

int	main(void)
{
	struct sigaction	usr;

	usr.sa_sigaction = ft_signal;
	usr.sa_flags = SA_SIGINFO | SA_NODEFER;
	sigaction(SIGUSR1, &usr, 0);
	sigaction(SIGUSR2, &usr, 0);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}

void	ft_addbit(int bit, pid_t client)
{
	static char	c;
	static char	i;

	c = c << 1;
	if (bit)
		c++;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	kill(client, SIGUSR1);
}

void	ft_signal(int signum, siginfo_t *info, void *ucontext)
{
	if (signum == SIGUSR1)
		ft_addbit(0, info->si_pid);
	if (signum == SIGUSR2)
		ft_addbit(1, info->si_pid);
	(void)ucontext;
}

void	ft_putnbr(int n)
{
	char	c;

	if (n / 10)
		ft_putnbr(n / 10);
	c = '0' + n % 10;
	write(1, &c, 1);
}
