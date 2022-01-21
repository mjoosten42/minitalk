/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:18:41 by mjoosten          #+#    #+#             */
/*   Updated: 2021/12/06 17:57:53 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*make_line(int fd, int len);

char	*ft_get_next_line(int fd)
{
	char	c;
	off_t	len;
	int		bytesread;

	bytesread = read(fd, &c, 1);
	len = 0;
	while (bytesread > 0)
	{
		len++;
		if (c == '\n')
			break ;
		bytesread = read(fd, &c, 1);
		if (bytesread < 0)
			return (0);
	}
	return (make_line(fd, len));
}

static	char	*make_line(int fd, int len)
{
	char	*str;

	if (!len)
		return (0);
	str = malloc(len + 1);
	if (!str)
		return (0);
	if (lseek(fd, -len, SEEK_CUR) < 0 || read(fd, str, len) < 0)
	{
		free(str);
		return (0);
	}
	str[len] = 0;
	return (str);
}
