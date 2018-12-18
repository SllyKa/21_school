/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:45:41 by gbrandon          #+#    #+#             */
/*   Updated: 2018/12/07 15:29:18 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "libft.h"
#include "get_next_line.h"

static int		assembly_line(char **hli, char **buf, char **line, size_t len)
{
	char		*temp;
	size_t		rest_len;

	CHECK_ERR(temp = ft_strsub(*hli, 0, *buf - *hli));
	if (*line)
	{
		CHECK_ERR(*line = ft_strjoin(*line, temp));
	}
	else
		*line = temp;
	if ((rest_len = len - (*buf - *hli)) > 1)
	{
		CHECK_ERR(*buf = ft_strsub(*buf, 1, len - (*buf - *hli)));
	}
	else
		*buf = NULL;
	free(*hli);
	*hli = NULL;
	return (1);
}

static int		create_line(char **buf, char **line)
{
	char	*head_line;
	size_t	line_length;

	head_line = *buf;
	line_length = ft_strlen(*buf);
	while (**buf)
	{
		if (**buf == '\n')
		{
			CHECK_ERR(assembly_line(&head_line, buf, line, line_length));
			return (1);
		}
		(*buf)++;
	}
	if (*line)
	{
		CHECK_ERR(*line = ft_strjoin(*line, head_line));
	}
	else
		CHECK_ERR(*line = ft_strdup(head_line));
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char *buf = NULL;
	int			rbytes;
	char		*head_buf;

	size_t		inter_buf_size; ///
	char		*inter_buf; ///

	CHECK_CMP_ERR(fd < 0);
	CHECK_ERR(line);
	*line = NULL;
	rbytes = 0;
	inter_buf_size = BUFF_SIZE; ///
	CHECK_ERR(inter_buf = (char*)malloc(sizeof(char) * (INTERMEDIATE_SIZE + 1))); ///
	if (buf)
		CHECK_CMP_ERR((rbytes = create_line(&buf, line)) < 0);
	IF_RET_ONE(rbytes == 1);
	CHECK_ERR(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1)));
	head_buf = buf;
	while ((rbytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (inter_buf_size < INTERMEDIATE_SIZE)
		{
			*inter_buf = *buf;
			inter_buf_size += BUFF_SIZE;
			inter_buf++;
			continue;
		}
		buf[rbytes] = '\0';
		CHECK_CMP_ERR((rbytes = create_line(&buf, line)) < 0);
		IF_RET_ONE(rbytes == 1);
		buf = head_buf;
	}
	CHECK_CMP_ERR(rbytes < 0);
	FREE_X(buf);
	IF_RET_ONE(*line);
	return (0);
}
