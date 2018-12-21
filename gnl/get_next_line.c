/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrandon <gbrandon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:45:41 by gbrandon          #+#    #+#             */
/*   Updated: 2018/12/20 15:47:21 by gbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "libft.h"
#include "get_next_line.h"

static t_list				*get_fd(t_list **head, int fd)
{
	t_info		*new;
	t_list		*new_head;

	new_head = *head;
	while (new_head)
	{
		if (((t_info*)new_head->content)->fd == fd)
			return (new_head);
		new_head = new_head->next;
	}
	if (!(new = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	new->fd = fd;
	new->buf = NULL;
	new->inter_buf = NULL;
	new->buf_size = 0;
	new->i_buf_size = 0;
	new->buf_cur_pos = 0;
	if (!(new_head = ft_lstnew((const void*)new, 0)))
		return (NULL);
	if (!(new_head->content = new))
	{
		free(new_head);
 		return (NULL);
 	}
 	new_head->next = NULL;
	ft_lstadd(head, new_head);
	return (*head);
}

static int					assembly_line(char **hli, t_info *cbuf, char **line)
{
	char		*temp;

	CHECK_ERR(temp = ft_strsub(*hli, 0, cbuf->inter_buf - *hli));
	if (*line)
	{
		CHECK_ERR(*line = ft_strjoin(*line, temp));
	}
	else
		*line = temp;
	if ((cbuf->i_buf_size = cbuf->i_buf_size - (cbuf->inter_buf - *hli)) > 1)
	{
		CHECK_ERR(cbuf->inter_buf = ft_strsub(cbuf->inter_buf, 1, cbuf->i_buf_size));
		cbuf->i_buf_size = cbuf->i_buf_size - 1;
	}
	else
		cbuf->i_buf_size = 0;
	return (1);
}

static int					create_line(t_info *cur_buf, char **line)
{
	char	*head_line;

	head_line = cur_buf->inter_buf;
	//cur_buf->i_buf_size = ft_strlen(head_line); //?
	while (*cur_buf->inter_buf)
	{
		if (*(cur_buf->inter_buf) == '\n')
		{
			CHECK_ERR(assembly_line(&head_line, cur_buf, line));
			return (1);
		}
		(cur_buf->inter_buf)++;
	}
	if (*line)
	{
		CHECK_ERR(*line = ft_strjoin(*line, head_line));
	}
	else
		CHECK_ERR(*line = ft_strdup(head_line));
	cur_buf->i_buf_size = 0;
	cur_buf->inter_buf = head_line;
	return (0);
}

static int					proc(t_info *cur_buf, char **line)
{
	int				err_code;

	err_code = 0;
	while (cur_buf->buf_size > 0 || cur_buf->i_buf_size > 0)
	{
		while (cur_buf->buf_size > 0 && cur_buf->i_buf_size < INTERMEDIATE_SIZE)
		{
			cur_buf->inter_buf[cur_buf->i_buf_size++] = cur_buf->buf[cur_buf->buf_cur_pos++];
			cur_buf->buf_size--;
		}
		if (cur_buf->i_buf_size < INTERMEDIATE_SIZE && cur_buf->buf_size > 0)
		{
			cur_buf->buf_cur_pos = 0;
			break;
		}
		cur_buf->inter_buf[cur_buf->i_buf_size] = '\0';
		CHECK_CMP_ERR((err_code = create_line(cur_buf, line)) < 0);
		IF_BREAK(err_code == 1);
	}
	return (err_code);
}

int							get_next_line(const int fd, char **line)
{
	static t_list	*list_head = NULL;
	t_info			*cur_buf;
	int				rbytes;
	char			*inter_buf_head;

	CHECK_CMP_ERR(fd < 0);
	CHECK_ERR(line);
	*line = NULL;
	rbytes = 0;
	CHECK_ERR(cur_buf = get_fd(&list_head, fd)->content);
	if (cur_buf->i_buf_size > 0 || cur_buf->buf_size > 0)
	{
		ERR_PROC(proc(cur_buf, line));
	}
	if (!cur_buf->inter_buf && !cur_buf->buf)
	{
		CHECK_ERR(cur_buf->inter_buf = (char*)malloc(sizeof(char) * (INTERMEDIATE_SIZE + 1))); ///
		CHECK_ERR(cur_buf->buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1)));
	}
	inter_buf_head = cur_buf->inter_buf;
	while (((rbytes = read(fd, cur_buf->buf, BUFF_SIZE)) > 0) ||
	(rbytes == 0 && (cur_buf->buf_size > 0 || cur_buf->i_buf_size > 0))) ///?
	{
		cur_buf->buf_cur_pos = 0;
		cur_buf->buf[rbytes] = '\0';
		cur_buf->buf_size = rbytes;
		rbytes = proc(cur_buf, line);
		if (cur_buf->i_buf_size == 0)
			cur_buf->inter_buf = inter_buf_head;
		ERR_PROC(rbytes);
	}
	cur_buf->inter_buf = inter_buf_head;
	CHECK_CMP_ERR(rbytes < 0);
	FREE_X(cur_buf->buf);
	FREE_X(cur_buf->inter_buf);
	/// free list
	IF_RET_ONE(*line);
	return (0);
}
