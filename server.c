/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:44:19 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/20 17:37:33 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_char	g_char;

void	ft_sigusr2(int signum)
{
	g_char.c = g_char.c << 1;
	g_char.c++;
	g_char.i++;
	if (g_char.i == 8)
	{
		write(1, &g_char.c, 1);
		g_char.c = 0;
		g_char.i = 0;
	}
	(void)signum;
}

void	ft_sigusr1(int signum)
{
	g_char.c = g_char.c << 1;
	g_char.i++;
	if (g_char.i == 8)
	{
		write(1, &g_char.c, 1);
		g_char.c = 0;
		g_char.i = 0;
	}
	(void)signum;
}

int	main(void)
{
	g_char.c = 0;
	g_char.i = 0;
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_sigusr1);
	signal(SIGUSR2, ft_sigusr2);
	while (1)
		;
}

//TODO: use sigaction to send kill to client.