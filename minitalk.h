/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:45:27 by mjoosten          #+#    #+#             */
/*   Updated: 2022/01/20 17:15:50 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# define BITS 8

typedef struct s_char
{
	char	c;
	char	i;
}	t_char;

#endif