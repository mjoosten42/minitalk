/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:44:39 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/20 17:36:44 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
		exit(EXIT_FAILURE);
	while (*argv[2])
	{
		i = 0;
		while (i < BITS)
		{
			if (*argv[2] < 0)
				kill(ft_atoi(argv[1]), SIGUSR2);
			else
				kill(ft_atoi(argv[1]), SIGUSR1);
			*argv[2] = *argv[2] << 1;
			i++;
			pause();
		}
		argv[2]++;
	}
}
