/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:44:19 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/21 14:23:22 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>			//	sigaction 
							//	getpid()
#include "libft/libft.h"	//	ft_putnbr()
							//	write()

void	ft_setsigaction(void);
void	ft_addbit(int bit, pid_t client);
void	ft_sigusr1(int signum, siginfo_t *info, void *ucontext);
void	ft_sigusr2(int signum, siginfo_t *info, void *ucontext);

int	main(void)
{
	ft_setsigaction();
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		;
}

void	ft_setsigaction(void)
{
	struct sigaction	usr1;
	struct sigaction	usr2;

	usr1.sa_sigaction = ft_sigusr1;
	usr1.sa_flags = SIGINFO;
	usr2.sa_sigaction = ft_sigusr2;
	usr2.sa_flags = SIGINFO;
	sigaction(SIGUSR1, &usr1, 0);
	sigaction(SIGUSR2, &usr2, 0);
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
		if (c)
			write(1, &c, 1);
		else
		{
			write(1, "\n", 1);
			kill(client, SIGUSR1);
		}
		c = 0;
		i = 0;
	}
	ft_setsigaction();
}

void	ft_sigusr1(int signum, siginfo_t *info, void *ucontext)
{
	ft_addbit(0, info->si_pid);
	(void)signum;
	(void)ucontext;
}

void	ft_sigusr2(int signum, siginfo_t *info, void *ucontext)
{
	ft_addbit(1, info->si_pid);
	(void)signum;
	(void)ucontext;
}
