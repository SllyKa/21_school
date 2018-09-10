/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 18:43:24 by gbrandon          #+#    #+#             */
/*   Updated: 2018/09/10 19:25:13 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUFF_SIZE 8192

int				find_n(char *str)
{
	int		pos;

	pos = 0;
	while (*str)
	{
		if (*str == '\n')
		{
			return (pos);
		}
		pos++;
	}
	return (-1);
}

char			**read_map(int fd)
{
	char				buf[8192 + 1];
	unsigned int		size;
	unsigned int		pos;

	while((size = read(fd, buf, BUFF_SIZE)))
	{
		buf[size] = '\0';
		if ((pos = find_n) > 0)
		{
			if (buf[pos + 1] != '\0')
			{
				
			}
		}
	}
}
